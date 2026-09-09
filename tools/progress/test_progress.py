import tempfile
from pathlib import Path
import unittest
import xml.etree.ElementTree as ET

from progress import classify, generate, layout, parse_map, svg, union_size


class ProgressTests(unittest.TestCase):
    def test_mismatched_rom_is_rejected_before_reporting(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / 'build/heartgold.us').mkdir(parents=True)
            (root / 'heartgold.us').mkdir()
            (root / 'build/heartgold.us/pokeheartgold.us.nds').write_bytes(b'wrong ROM')
            (root / 'heartgold.us/rom.sha1').write_text('0' * 40 + '  rom.nds')
            with self.assertRaisesRegex(ValueError, 'ROM mismatch'):
                generate(root, 'heartgold.us')

    def test_aliases_and_section_symbols_are_not_double_counted(self):
        self.assertEqual(union_size([(0, 100), (0, 20), (20, 60), (95, 110)]), 110)

    def test_overlay_addresses_stay_separate_and_spec_resolves_sources(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            (root / 'src').mkdir()
            (root / 'asm').mkdir()
            (root / 'src/unit.c').write_text('void f(void) {}')
            (root / 'asm/unit.s').write_text('')
            (root / 'main.lsf').write_text('Object src/unit.o\n')
            path = root / 'test.xMAP'
            path.write_text('# .OVY_1\n'
                            '  02000000 00000020 .text .text (unit.o)\n'
                            '  02000000 00000010 .text f (unit.o)\n'
                            '  02000000 00000000 .text $t (unit.o)\n'
                            '  02000020 00000080 .data x (unit.o)\n'
                            '# .OVY_2\n'
                            '  02000000 00000020 .text f (unit.o)\n')
            result = parse_map(path, root, 'ARM9')
            self.assertEqual(sum(o['bytes'] for o in result), 64)
            self.assertEqual([o['status'] for o in result], ['c', 'c'])
            self.assertEqual(result[0]['source'], 'src/unit.c')

    def test_inline_and_conditional_assembly_are_not_c_only(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            path = root / 'unit.c'
            path.write_text('// asm comment\nvoid f(void) {}')
            self.assertEqual(classify(root, {'unit.c'})[0], 'c')
            path.write_text('#ifdef NONMATCHING\nvoid f(void) {}\n#else\nasm void f(void) {}\n#endif')
            self.assertEqual(classify(root, {'unit.c'})[0], 'mixed')
            self.assertEqual(classify(root, {'unit.c', 'other.c'})[0], 'unknown')

    def test_treemap_area_proportional_and_svg_escapes_names(self):
        items = [dict(bytes=n) for n in [10, 25, 1, 64]]
        rects = list(layout(items, 0, 0, 100, 50))
        for item, x, y, w, h in rects:
            self.assertAlmostEqual(w*h, item['bytes']*50)
            self.assertGreaterEqual(x, 0)
            self.assertLessEqual(x+w, 100)
            self.assertLessEqual(y+h, 50)
        report = dict(game='heartgold.us', commit='abc123', totals={'c': 10}, objects=[
            dict(cpu='ARM9', module='a&b', object='x.o', bytes=10, status='c', source='src/a&b.c')])
        ET.fromstring(svg(report))


if __name__ == '__main__':
    unittest.main()
