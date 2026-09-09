# Decompilation work log

## Earlier local research located

The following work was found on this machine during the first decompilation
session. It remains in its original locations; private saves, ROMs, and
research datasets have not been copied into this repository.

| Location | What was found |
| --- | --- |
| `~/pokemon-research-private/` | Research notes, save decoders, source-derived models, and ARM/Thumb experiments using Unicorn. |
| `~/pokemon-research-private/NATIVE-RESEARCH.md` | Headbutt, roamer, and battle-AI investigations, with references to native execution harnesses. |
| `~/pokemon-research-private/headbutt_reference_test.c` | A standalone source-derived Headbutt classifier for research, rather than a replacement object integrated into a matching build. |
| `~/pokemon-research-private/mood_ref/pret/` | A clean full checkout at upstream `0985e8718`. |
| `~/pokemon-research-private/reference/pokeheartgold/` | Selected reference files; the C, header, and assembly files with counterparts in this checkout matched byte-for-byte. |
| `~/Documents/projects/pokeheartgold/` | A clean main checkout at upstream `0985e8718`; this fork task runs in its separate worktree. |

Spotlight and the usual project/worktree directories were also checked for
other HeartGold copies. No uncommitted matching-decomp changes were found in
the full checkouts inspected. The research is useful evidence for future
work, but its reported behavioral tests have not been rerun in this session.
Some studied routines, including the Headbutt classifier, are already C in
upstream and should not be counted as new decompilation progress.

## First batch: sound state

`src/sound_state.c` replaces the contiguous assembly functions from
`0x02004A44` through `0x02004B23` (224 bytes, including alignment):

- `GF_SND_BGM_DisableSet`
- `GF_SND_BGM_DisableCheck`
- `sub_02004A60`
- `GF_GetCurrentPlayingBGM`
- `GF_SetCurrentPlayingBGM`
- `sub_02004AAC`
- `sub_02004AB8`
- `Sound_SetFieldBGM`
- `Sound_SetScene`
- `sub_02004AFC`
- `sub_02004B10`

The C object is inserted immediately before the remaining assembly object
in `main.lsf`. Original data stays in the assembly file. Existing function
names are preserved, including the misleading `GF_SetCurrentPlayingBGM`
name: its attribute 11 points at the queued sequence, whereas attribute 10
is the current sequence.

The unsigned comparison in `Sound_SetScene` preserves the original branch
behavior for all 32-bit inputs. The apparently unused attribute lookup in
`sub_02004AFC` is also retained. No assembly fallback is used in the new C
file.

Use the full matching builds to validate the change:

```sh
./scripts/build.sh progress
./scripts/build.sh GAME_VERSION=SOULSILVER progress
python3 tools/progress/progress.py --game heartgold.us --output docs/progress
```

The mapped-byte metric can change slightly when assembler function sizes
include alignment bytes that C symbol sizes exclude. Compare the actual
ROM hashes as well as the chart; a source-language percentage is not a
substitute for binary verification.

Validation completed: both full ROMs passed the retail SHA-1 comparisons
listed in FORK.md after this batch. The new C file and changed header also
pass the repository's clang-format rules. HeartGold C-only coverage rose
from 921,994 to 922,208 mapped bytes (+214); the remaining 10 bytes of the
224-byte replaced range are alignment no longer included in C symbol sizes.

## Second batch: starting background music

`src/sound_bgm.c` replaces four functions in the contiguous range
`0x02005D10` through `0x02005DF3` (228 bytes including alignment):
`sub_02005D10`, `PlayBGM`, `sub_02005DA0`, and `sub_02005DC4`.

This reconstructs the player/handle selection, two supported BGM player
paths, failure bookkeeping, sound-state updates, and sequence-load setup.
The `PlayBGM` declaration now returns `BOOL`, matching the success result
already returned by the original assembly. Existing callers ignore that
result. The assembly file retains the remaining routines, with the two
helpers called from C explicitly exported.

The compiler assigned different registers to the handle and success result
in `sub_02005D10` until their declaration order matched its allocation
behavior. No inline assembly or register pinning was needed.

Validation completed: both full ROMs passed their retail SHA-1 comparisons.
HeartGold C-only coverage increased by 226 mapped bytes to 922,434. The
two-byte difference from the replaced range is function alignment.

## Third batch: field playback and stopping BGM

Four more routines move into `src/sound_bgm.c`: `sub_02005DF4`,
`sub_02005E44`, `StopBGM`, and `sub_02005EEC`. Their original contiguous
range is `0x02005DF4` through `0x02005F0F` (284 bytes including alignment).

The field playback path reuses the active sequence's bank and stops the
radio. `GF_NNS_SndPlayerGetSeqNo` can return -1; the bank lookup takes an
`int` so this sentinel reaches it unchanged, just as in the original code.
`sub_02005E44` returns the actual playback success result, reflected in its
public prototype. `StopBGM` stops both the normal and GB Sounds sequences
when they differ, releases the selected handle, and resets the BGM state.

Validation completed: HeartGold and SoulSilver both passed the full retail
ROM hash checks. This batch adds 276 HeartGold mapped C bytes, bringing
C-only coverage to 922,710 bytes. The 8-byte difference is alignment.
