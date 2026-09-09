# Pokémon HeartGold and SoulSilver

This is an independently maintained fork of the work-in-progress matching
decompilation of Pokémon HeartGold and SoulSilver. It builds from a mixture of
reconstructed C and assembly. For this fork's macOS setup and progress tooling,
see [Working on this fork](docs/FORK.md). The original build instructions are in
[INSTALL.md](INSTALL.md).

[![Decompilation source-language treemap](docs/progress/treemap.svg)](docs/progress/treemap.svg)

The chart measures mapped code bytes across ARM9, ARM7, and overlays. Green is
C-only source; amber contains assembly; slate is assembly; purple is unresolved.
It is not a per-function matching score. [Metric details](docs/FORK.md#what-the-chart-measures)
and [snapshot data](docs/progress/progress.json).

```sh
./scripts/setup-macos.sh      # first-time macOS toolchain setup
./scripts/build.sh progress  # matching HeartGold build + SVG/JSON report
```

This repository builds the following ROMs:

* [**pokeheartgold.us.nds**](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=4787) `sha1: 4fcded0e2713dc03929845de631d0932ea2b5a37`
* [**pokesoulsilver.us.nds**](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=4788) `sha1: f8dc38ea20c17541a43b58c5e6d18c1732c7e582`

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
