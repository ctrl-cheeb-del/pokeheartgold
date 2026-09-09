# Working on this fork

This is an independently maintained fork of pret/pokeheartgold. The fork's
build and progress tooling was created with AI assistance. Upstream's
contribution policy in CONTRIBUTING.md applies to submissions to upstream;
do not represent these changes as eligible upstream contributions.

## Matching builds on macOS

With Homebrew and (on Apple Silicon) Rosetta 2 installed:

```sh
./scripts/setup-macos.sh
./scripts/build.sh progress
./scripts/build.sh GAME_VERSION=SOULSILVER progress
```

The setup helper installs native dependencies through Homebrew, obtains the
compiler and SDK tools from the same assets used by upstream CI, and verifies
download SHA256 hashes. It installs Wine 11.16 inside `.local-tools/`; its Wine
prefix also stays in this ignored directory. It does not modify system Wine
settings. Downloaded tools, compiler licenses, ROMs, and build intermediates
are ignored by Git.

The original INSTALL.md remains the reference for other operating systems.
On Linux with the toolchain installed, `make progress` works directly.

`progress` refreshes the selected ROM with `COMPARE=1`, checks the original
SHA1, and generates `build/progress/treemap.svg` and `progress.json`. The
standalone SVG opens in a browser and shows file details on hover. The JSON
contains every object, module, CPU, byte count, source path, and category.
The HeartGold and SoulSilver reports use the same output path by default;
choose separate output directories when retaining both:

```sh
python3 tools/progress/progress.py --game heartgold.us --output build/progress/heartgold
python3 tools/progress/progress.py --game soulsilver.us --output build/progress/soulsilver
```

To refresh the checked-in README snapshot after a matching HeartGold build:

```sh
python3 tools/progress/progress.py --output docs/progress
```

CI builds both versions and uploads a `decompilation-progress` artifact with
both reports. It does not upload ROMs or proprietary toolchain files in that
artifact. The README snapshot is a deliberate checked-in update, not an
automatically committed change on every CI run.

## What the chart measures

This is **source-language coverage by mapped code-section bytes**, not an
official upstream progress metric or a per-function matching score.

- Green: an object attributed to a C file without detected assembly syntax.
- Amber: a C object whose source contains assembly, including conditional
  nonmatching fallbacks. The entire object is excluded from the green total.
- Slate: an object attributed to assembly source.
- Purple: the source mapping is unresolved or ambiguous.

Rectangles are grouped by CPU and linker module, then sized by object bytes.
ARM7, ARM9, libraries, and all mapped overlays are included. Modules that load
at the same address remain separate. Aliases and enclosing section symbols
are merged by interval so their bytes are not counted twice. Sections `.text`,
`.init`, `.itcm`, `.sinit`, and `.wram` count as code; literal pools inside
these sections count too. Assets, other data sections, BSS, and padding with
no mapped symbol coverage are excluded.

The source mapping uses the linker specification to disambiguate C/assembly
files with the same basename. Generated protection objects and archive
members can remain unresolved. Source classification is conservative and
lexical; it is not a C preprocessor or proof of portable behavior. Assembly
needed for hardware or runtime operations is not necessarily work that
should be converted to C.

The generator verifies the ROM hash but cannot by itself establish that an
old build corresponds to newly edited source. Use `build.sh progress` to
refresh the build first. The report records the Git commit, tracked working
tree state, and map hashes for provenance. A passing ROM checksum establishes
retail binary equivalence, not complete decompilation or portability.

## Validation

Baseline verified locally on Apple Silicon macOS with Wine 11.16, against
game source commit `0985e8718df4f25e64d6507d89c0c97c0d288981`:

| US version | Verified ROM SHA-1 |
| --- | --- |
| HeartGold | `4fcded0e2713dc03929845de631d0932ea2b5a37` |
| SoulSilver | `f8dc38ea20c17541a43b58c5e6d18c1732c7e582` |

HeartGold baseline: 4,085,132 mapped code bytes across 830 object/module
entries. Of these, 921,994 bytes (22.57%) are attributed to C-only sources,
18,270 to mixed C/assembly, 3,136,076 to assembly, and 8,792 are unresolved.
No game-source changes were required for either initial matching build.
The checked-in chart is refreshed as decompilation advances; see
[the work log](DECOMP-NOTES.md) for subsequent batches.

```sh
python3 -m unittest discover -s tools/progress -v
./scripts/build.sh progress
./scripts/build.sh GAME_VERSION=SOULSILVER progress
```

Start decompilation work only after the unchanged build passes. Keep the
matching checks enabled while replacing assembly with C.
