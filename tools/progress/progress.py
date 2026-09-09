#!/usr/bin/env python3
"""Build a source-language treemap from a matching ROM and its linker maps.

Only Python's standard library is required. This measures mapped code-section
bytes by source language, not a function-by-function matching percentage.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import html
import json
from pathlib import Path
import re
import subprocess

CODE = {'.text', '.init', '.itcm', '.sinit', '.wram'}
ROW = re.compile(r'\s+([0-9A-Fa-f]{8}) ([0-9A-Fa-f]{8}) (\.\S+)\s+(.+?)\s+\(([^)]+)\)')
COLORS = {'c': '#35b85a', 'mixed': '#e4ad42', 'asm': '#455268', 'unknown': '#b875ae'}
LABELS = {'c': 'C-only source', 'mixed': 'C with assembly', 'asm': 'Assembly', 'unknown': 'Unresolved source'}


def union_size(ranges):
    end, total = -1, 0
    for start, stop in sorted(ranges):
        total += max(0, stop - max(start, end))
        end = max(end, stop)
    return total


def source_index(root, arm7=False):
    base = root / 'sub' if arm7 else root
    candidates = defaultdict(set)
    for folder in ('src', 'asm', 'lib'):
        for p in (base / folder).rglob('*'):
            if p.suffix in ('.c', '.s'):
                candidates[p.stem + '.o'].add(p.relative_to(root).as_posix())
    # The linker spec resolves duplicate C/ASM basenames left in the tree.
    spec = base / ('ichneumon_sub.lsf' if arm7 else 'main.lsf')
    linked = defaultdict(set)
    for obj in re.findall(r'^\s*Object\s+(\S+\.o)', spec.read_text(), re.M):
        for ext in ('.c', '.s'):
            p = (base / obj).with_suffix(ext)
            if p.is_file():
                linked[Path(obj).name].add(p.relative_to(root).as_posix())
    candidates.update(linked)
    return candidates


def classify(root, paths):
    if len(paths) != 1:
        return 'unknown', None
    path = next(iter(paths))
    if path.endswith('.s'):
        return 'asm', path
    text = (root / path).read_text()
    text = re.sub(r'/\*.*?\*/|//[^\n]*', '', text, flags=re.S)
    # Conservatively mark the entire object mixed, including conditional ASM.
    mixed = re.search(r'\b(?:asm|__asm|__asm__|GLOBAL_ASM)\b', text)
    return ('mixed' if mixed else 'c'), path


def parse_map(path, root, cpu):
    sources = source_index(root, cpu == 'ARM7')
    ranges = defaultdict(list)
    module = None
    for line in path.read_text().splitlines():
        if line.startswith('# .'):
            module = line[3:]
        match = ROW.fullmatch(line)
        if not match or module is None:
            continue
        address, size, section, symbol, obj = match.groups()
        size = int(size, 16)
        if size and section in CODE:
            start = int(address, 16)
            ranges[module, obj.strip(), section].append((start, start + size))
    objects = Counter()
    for (module, obj, section), intervals in ranges.items():
        objects[module, obj] += union_size(intervals)
    result = []
    for (module, obj), size in sorted(objects.items()):
        status, source = classify(root, sources.get(obj, set()))
        result.append(dict(cpu=cpu, module=module, object=obj, bytes=size,
                           status=status, source=source))
    if not result:
        raise ValueError(f'No code symbols found in {path}')
    return result


def layout(items, x, y, width, height):
    """Deterministic balanced binary treemap; rectangle area tracks bytes."""
    if not items:
        return
    if len(items) == 1:
        yield items[0], x, y, width, height
        return
    total = sum(item['bytes'] for item in items)
    acc, split = 0, 1
    best = float('inf')
    for i, item in enumerate(items[:-1], 1):
        acc += item['bytes']
        if abs(total / 2 - acc) < best:
            best, split = abs(total / 2 - acc), i
    fraction = sum(item['bytes'] for item in items[:split]) / total
    if width >= height:
        cut = width * fraction
        yield from layout(items[:split], x, y, cut, height)
        yield from layout(items[split:], x + cut, y, width - cut, height)
    else:
        cut = height * fraction
        yield from layout(items[:split], x, y, width, cut)
        yield from layout(items[split:], x, y + cut, width, height - cut)


def svg(report):
    total = sum(report['totals'].values())
    pct = 100 * report['totals'].get('c', 0) / total
    game_title = 'HeartGold' if report['game'] == 'heartgold.us' else 'SoulSilver'
    esc = html.escape
    out = ['<svg xmlns="http://www.w3.org/2000/svg" width="1200" height="780" viewBox="0 0 1200 780" role="img">',
           f'<title>{game_title} decompilation source-language treemap</title>',
           '<desc>Rectangle area represents mapped code bytes. Green is C-only source, amber is mixed C and assembly, slate is assembly, purple is unresolved. Hover for file details.</desc>',
           '<rect width="1200" height="780" rx="16" fill="#101722"/>',
           '<g font-family="system-ui, sans-serif" fill="#edf2fa">',
           f'<text x="28" y="42" font-size="25" font-weight="700">{game_title} · decompilation</text>',
           f'<text x="1172" y="42" text-anchor="end" font-size="22">{pct:.2f}% C-only source</text>',
           f'<text x="28" y="71" font-size="14" fill="#b9c7da">Matching US ROM verified · {esc(report["commit"][:9])} · ARM9 + ARM7 · {total:,} mapped code bytes</text>']
    x = 28
    for status, color in COLORS.items():
        percent = report['totals'].get(status, 0) / total * 100
        out += [f'<rect x="{x}" y="91" width="12" height="12" rx="2" fill="{color}"/>',
                f'<text x="{x+19}" y="102" font-size="14">{LABELS[status]} {percent:.1f}%</text>']
        x += 288
    groups = defaultdict(list)
    for item in report['objects']:
        groups[item['cpu'], item['module']].append(item)
    modules = [dict(name=f'{cpu} / {module}', bytes=sum(o['bytes'] for o in items), children=items)
               for (cpu, module), items in sorted(groups.items())]
    modules.sort(key=lambda m: (-m['bytes'], m['name']))
    for module, x, y, w, h in layout(modules, 28, 125, 1144, 592):
        for item, ox, oy, ow, oh in layout(sorted(module['children'], key=lambda o: (-o['bytes'], o['object'])), x, y, w, h):
            title = f"{module['name']} / {item['object']}\n{item['bytes']:,} bytes · {LABELS[item['status']]}\n{item['source'] or 'Source mapping unresolved'}"
            out += [f'<rect x="{ox:.3f}" y="{oy:.3f}" width="{ow:.3f}" height="{oh:.3f}" fill="{COLORS[item["status"]]}" stroke="#101722" stroke-width="0.6"><title>{esc(title)}</title></rect>']
        out += [f'<rect x="{x:.3f}" y="{y:.3f}" width="{w:.3f}" height="{h:.3f}" fill="none" stroke="#101722" stroke-width="2"/>']
        if w > 140 and h > 40:
            label = module['name']
            out += [f'<rect x="{x+3:.3f}" y="{y+3:.3f}" width="{min(w-6, len(label)*7+14):.3f}" height="22" rx="3" fill="#101722" opacity="0.88"/>',
                    f'<text x="{x+9:.3f}" y="{y+19:.3f}" font-size="12">{esc(label)}</text>']
    out += ['<text x="28" y="744" font-size="14" fill="#b9c7da">Area = code-section bytes · Hover for files · Mixed objects are not counted as C-only</text>',
            '<text x="28" y="765" font-size="12" fill="#b9c7da">Source-language coverage, not a per-function matching score. Assets and unmapped padding are excluded; code literal pools are included.</text>',
            '</g></svg>']
    return '\n'.join(out) + '\n'


def generate(root, game):
    rom = root / 'build' / game / f'poke{game}.nds'
    expected = (root / game / 'rom.sha1').read_text().split()[0]
    actual = hashlib.sha1(rom.read_bytes()).hexdigest()
    if actual != expected:
        raise ValueError(f'ROM mismatch: expected {expected}, got {actual}')
    maps = {'ARM9': root / 'build' / game / 'main.elf.xMAP',
            'ARM7': root / 'sub/build/ichneumon_sub.elf.xMAP'}
    objects = []
    for cpu, path in maps.items():
        objects += parse_map(path, root, cpu)
    totals = Counter()
    for item in objects:
        totals[item['status']] += item['bytes']
    return dict(schema_version=1, game=game, commit=subprocess.check_output(
        ['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(), rom_sha1=actual,
        tracked_worktree_dirty=bool(subprocess.check_output(
            ['git', 'status', '--porcelain', '--untracked-files=no'], cwd=root, text=True)),
        map_sha256={cpu: hashlib.sha256(path.read_bytes()).hexdigest() for cpu, path in maps.items()},
        metric='Mapped code-section bytes classified by source language; mixed objects excluded from C-only.',
        totals=dict(totals), objects=objects)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument('--game', choices=['heartgold.us', 'soulsilver.us'], default='heartgold.us')
    parser.add_argument('--output', type=Path, default=Path('build/progress'))
    args = parser.parse_args()
    try:
        report = generate(args.root.resolve(), args.game)
    except (OSError, ValueError, subprocess.SubprocessError) as error:
        parser.exit(1, f'progress: {error}\nRun the matching build before generating progress.\n')
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / 'progress.json').write_text(json.dumps(report, indent=2) + '\n')
    (args.output / 'treemap.svg').write_text(svg(report))
    print(json.dumps({k: report[k] for k in ('game', 'rom_sha1', 'totals')}, indent=2))
    print(f'Treemap: {args.output / "treemap.svg"}')


if __name__ == '__main__':
    main()
