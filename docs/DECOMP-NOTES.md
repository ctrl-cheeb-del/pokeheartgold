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
listed in README.md after this batch. The new C file and changed header also
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

## Fourth batch: fades, queries, and sound cleanup

Six routines in `0x02005F10` through `0x0200602B` (284 bytes including
alignment) move into `src/sound_bgm.c`: `GF_SndStartFadeInBGM`,
`GF_SndStartFadeOutBGM`, `GF_SndGetFadeTimer`, `sub_02005F94`, `Sound_Stop`,
and `sub_02005FD8`.

Fade-out preserves an already active fade timer. The fade timer query
returns the low 16 bits of the timer; its public return type is now `u32`
rather than `BOOL`, since it returns the remaining count rather than a
normalized boolean. The sequence count query also preserves its full
32-bit return value. Existing uses of both queries retain their behavior.
The cleanup routines preserve the original four SE-handle loop and the
conditional wave-output stops for handles 14 and 15.

Validation completed: both full ROMs passed their retail SHA-1 comparisons.
HeartGold C-only coverage increased by 282 mapped bytes to 922,992. This
brings the four batches to 25 functions and 998 additional mapped C bytes
(1,020 original bytes including alignment). Formatting checks passed.

## Fifth batch: sound-effect playback, stopping, and queries

`src/sound_se.c` replaces 13 routines in the contiguous range
`0x0200602C` through `0x020061B3` (392 bytes including alignment). These
cover SE playback with optional player/bank selection, pan/volume/pitch
wrappers, stopping individual sequences or all four SE handles, and
playback-count queries.

The select/confirm suppression check in `sub_020060BC` uses unsigned
subtraction to preserve the original range check for all 32-bit sequence
inputs. Narrowing to 16 bits is retained only where the original does it.
The playback wrappers expose the success results returned by the assembly;
existing callers discard them. `GF_IsAnySEPlaying` intentionally checks
for exactly one active sequence on a player, preserving the original
comparison rather than replacing it with a broader nonzero check.

Validation completed: both HeartGold and SoulSilver passed the full retail
ROM hash checks. HeartGold C-only coverage rose by 388 mapped bytes to
923,380. Across five batches, 38 functions now replace 1,412 original bytes
including alignment, adding 1,386 mapped C bytes. Formatting checks passed.

## Sixth batch: pan controls and cry playback

Three pan-control routines (`sub_020061B4`, `sub_020061D0`, and
`sub_020061EC`) move into `src/sound_se.c`, and `PlayCry` moves into the new
`src/sound_cry.c`. The contiguous original range is `0x020061B4` through
`0x020062DF` (300 bytes).

Cry playback preserves the alternate Shaymin cry-bank selection, invalid
bank fallback, Chatot recording playback, and primary/chorus handle paths.
The return prototype now exposes the playback success result already
returned by the original assembly. All existing callers discard that result.

Validation completed: both full ROMs passed their retail SHA-1 comparisons
locally. HeartGold C-only coverage increased by 300 mapped bytes to 923,680.
Across six batches, 42 functions add 1,686 mapped C bytes. Formatting checks
passed. GitHub build CI remains disabled; this batch was validated locally.

## Seventh batch: cry control helpers

`sub_020062E0`, `sub_02006300`, and `IsCryFinished` move into
`src/sound_cry.c`, replacing `0x020062E0` through `0x020063A3` (196 bytes
including alignment). The wrapper queues a cry and returns TRUE. The stop
routine stops both cry handles, performs conditional wave-output cleanup,
and resets the Chatot and queued-cry state.

`IsCryFinished` retains its original activity/count return value despite its
misleading name. Apparently unused sound-attribute lookups remain in place.

Validation completed: HeartGold and SoulSilver both passed their full retail
SHA-1 comparisons locally. This batch adds 194 mapped C bytes (the other two
bytes are alignment), bringing HeartGold C-only coverage to 923,874 bytes.
The seven batches total 45 functions and 1,880 additional mapped C bytes.
Formatting checks passed; no GitHub CI run was started.

## Eighth batch: extended cry playback

`PlayCryEx` moves into `src/sound_cry.c`, replacing the 1,148-byte range
`0x020063A4` through `0x0200681F`. The C reconstruction retains all 15
playback modes, the Chatot-specific path, wave-output setup, pitch changes,
chorus settings, and timer setup. Its prototype exposes the TRUE return
value already present in the original assembly.

The scratch object has the same size and identical bytes outside call
relocations. Matching required declaring the pan/volume temporaries before
the attribute pointers and retaining an explicit Chatot species argument
inside the Chatot branch. No inline assembly or register pinning is used.

Before this batch, HeartGold C-only mapped-byte coverage was 22.615679%
(923,874 of 4,085,104 mapped code bytes).

Validation completed: both full ROMs passed their retail SHA-1 comparisons
locally. Coverage increased from 22.615679% to 22.643781% (+0.028102
percentage points), with 925,022 C-only bytes out of 4,085,104 mapped bytes.
This adds 1,148 C bytes and brings the total to 46 converted functions and
3,028 additional mapped C bytes. Formatting checks passed. No GitHub CI was
started.

## Ninth batch: cry timer tasks

Four routines in `0x02006820` through `0x0200691F` (256 bytes) move into
`src/sound_cry.c`: initial volume setup, creation of the cry-stop task, its
per-frame callback, and task destruction. The reconstructed eight-byte
task state contains a countdown and task pointer. Allocation failure,
initialization, ten-frame fade timing, early playback completion, and
cleanup order are preserved.

Before this batch, HeartGold C-only coverage was 22.643781% (925,022 of
4,085,104 mapped code bytes).

Validation completed: both full ROM hashes match retail locally. Coverage
increased from 22.643781% to 22.650048% (+0.006267 percentage points), with
925,278 C-only bytes out of 4,085,104 mapped bytes. This adds 256 C bytes,
bringing the total to 50 converted functions and 3,284 additional mapped C
bytes. Formatting passed; GitHub CI was not used.

## Tenth batch: queued cries and alternate cry selection

`sub_02006920`, `sub_02006A0C`, and `sub_02006A30` move into
`src/sound_cry.c`, replacing `0x02006920` through `0x02006ABF` (416 bytes
including alignment). They select one of two cry queues, dispatch immediately
when delay is zero, recognize Shaymin's alternate cry bank, and clear both
queues in the original access order.

Before this batch, HeartGold C-only coverage was 22.650048% (925,278 of
4,085,104 mapped bytes).

Validation completed: both ROMs pass their full retail SHA-1 comparisons
locally. Coverage increased from 22.650048% to 22.660193% (+0.010145
percentage points), with 925,692 C-only bytes out of 4,085,102 mapped bytes.
This adds 414 C bytes; two alignment bytes leave the mapped total. The total
is now 53 converted functions and 3,698 additional mapped C bytes. Formatting
passed; no GitHub CI was started.

## Eleventh batch: chorus, fanfares, and shared sequence startup

The remaining eight functions in `asm/unk_02005D10.s` move to C. Chorus
helpers finish `src/sound_cry.c`; fanfare routines live in
`src/sound_fanfare.c`; shared sequence startup lives in `src/sound_seq.c`.
The range is `0x02006AC0` through `0x02006C8B` (460 bytes including alignment).
The now-empty assembly unit and its private include are removed from the
build and repository.

The reconstruction preserves BGM/radio pause and resume behavior, the
15-frame fanfare wait, sound-state restoration, GB Sounds bank substitution,
and channel allocation updates. The player-number helper is declared as
returning `u8`, consistent with its byte load and 255 sentinel. Fanfare
callers retain that width. Playback return values are preserved.

Before this batch, HeartGold C-only coverage was 22.660193% (925,692 of
4,085,102 mapped bytes).

Validation completed: both full ROM hashes match retail locally. Coverage
increased from 22.660193% to 22.671264% (+0.011071 percentage points), with
926,142 C-only bytes out of 4,085,092 mapped bytes. This adds 450 C bytes;
ten alignment bytes leave the mapped total. All 50 functions from the
original assembly unit now have exactly one C definition. Together with the
sound-state batch, 61 functions add 4,148 mapped C bytes relative to the
initial baseline. Formatting passed; no GitHub CI was started.

## Twelfth batch: scene sound resource loader

`sub_02004B24` moves from `asm/unk_02004A44.s` into the new
`src/sound_scene.c`. The function covers `0x02004B24` through `0x02004EB3`
(912 bytes), dispatching sound group, bank, wave archive, and sequence loads
by scene ID. The C switch preserves load order, the selected return value
when a scene loads multiple resources, and the assertion for unsupported
IDs. Its declaration now exposes the existing Boolean return value.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.671264% to 22.693589% (+0.022325 percentage points), from
926,142 to 927,054 C bytes out of 4,085,092 mapped bytes. This adds 912 C
bytes, bringing the total to 62 converted functions and 5,060 additional
mapped C bytes relative to the initial baseline. The HeartGold treemap was
refreshed and formatting checks passed. GitHub build CI remains disabled;
validation used local builds only.

## Thirteenth batch: sound scene switching

`sub_02004EB4`, `Sound_SetSceneAndPlayBGM`, and `sub_02005060` move into
`src/sound_scene.c`, replacing `0x02004EB4` through `0x0200508B` (472 bytes).
The C preserves the separate primary and secondary scene checks, scene-specific
BGM dispatch, fanfare timer reset, and sound heap state restoration/save order.
The public scene-switch declaration now exposes its existing Boolean return
value, and names the forwarded third argument `mode` instead of `unused`.
The remaining assembly declares the moved state-loading helper as external.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.693589% to 22.705143% (+0.011554 percentage points), from
927,054 to 927,526 C bytes out of 4,085,092 mapped bytes. This adds 472 C
bytes, bringing the total to 65 converted functions and 5,532 additional
mapped C bytes relative to the initial baseline. The HeartGold treemap was
refreshed and formatting checks passed. GitHub CI was not used.

## Fourteenth batch: field BGM reload and fade setup

`sub_0200508C`, `sub_02005150`, and `sub_020051A4` move into
`src/sound_scene.c`, replacing `0x0200508C` through `0x02005227` (412 bytes
including alignment). The reconstruction preserves GB Sounds sequence
conversion, bicycle handling, sound state reloads, bank-dependent sequence
loads, assertion paths, and fade-in setup. Existing sound-state storage
remains in assembly and is exported for the C references.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.705143% to 22.715191% (+0.010048 percentage points), from
927,526 to 927,936 C bytes out of 4,085,090 mapped bytes. This adds 410 C
bytes; two alignment bytes leave the mapped total. There are now 68 converted
functions and 5,942 additional mapped C bytes relative to the initial
baseline. The HeartGold treemap was refreshed, formatting passed, and no
GitHub CI was used.

## Fifteenth batch: scene-specific BGM helpers

Eight routines from `0x02005228` through `0x02005327` (256 bytes including
alignment) move into `src/sound_scene.c`: six scene dispatch helpers,
`BGM_SaveStateAndPlayNew`, and sound-state restoration helper `sub_02005318`.
Their original load, stop, pause-clear, save, and playback order is preserved.
The sequence argument of `BGM_SaveStateAndPlayNew` and the return type of
`FieldBGM_GetEyesMeetForTrainer` are declared `u16`, matching the sequence
value and preserving the caller's original instructions without narrowing.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.715191% to 22.721231% (+0.006040 percentage points), from
927,936 to 928,180 C bytes out of 4,085,078 mapped bytes. This adds 244 C
bytes; twelve alignment bytes leave the mapped total. There are now 76
converted functions and 6,186 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Sixteenth batch: sound state, pause, and volume controls

Five routines from `0x02005328` through `0x02005447` (288 bytes including
alignment) move into the new `src/sound_control.c`: sound heap state lookup,
BGM pause control, pause-flag reset, volume movement, and initial volume
clamping. The C retains the original state lookup assertion and valid-state
switch, pause bookkeeping, GB Sounds volume update, and 0–127 volume limits.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.721231% to 22.728205% (+0.006974 percentage points), from
928,180 to 928,464 C bytes out of 4,085,074 mapped bytes. This adds 284 C
bytes; four alignment bytes leave the mapped total. There are now 81
converted functions and 6,470 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Seventeenth batch: sound sequence metadata

Ten routines from `0x02005448` through `0x0200551F` (216 bytes including
alignment) move into `src/sound_seq_info.c`. These cover volume selection,
player counts and sequence lookup, bank lookup, and the microphone-counter
query wrapper. The original missing-parameter sentinel values and reduced
volume behavior are preserved. The declaration of `sub_02005448` remains
unprototyped to retain the original caller that leaves its sequence in r0.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.728205% to 22.733304% (+0.005099 percentage points), from
928,464 to 928,670 C bytes out of 4,085,064 mapped bytes. This adds 206 C
bytes; ten alignment bytes leave the mapped total. There are now 91
converted functions and 6,676 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Eighteenth batch: microphone and wave-output controls

Thirteen routines from `0x02005520` through `0x020057AB` (652 bytes including
alignment) move into `src/sound_mic.c` and `src/sound_wave.c`. Microphone
start/stop and lid handling preserve the saved sampling parameters and
counter reset. Wave-output helpers preserve allocation flags, failure and
assertion paths, channel release, playback, pan clamping, speed, and volume.
The allocation helper's declarations expose its existing Boolean result.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.733304% to 22.749037% (+0.015733 percentage points), from
928,670 to 929,310 C bytes out of 4,085,052 mapped bytes. This adds 640 C
bytes; twelve alignment bytes leave the mapped total. There are now 104
converted functions and 7,316 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Nineteenth batch: wave-file loading and cleanup

Three routines from `0x020057AC` through `0x020058F3` (328 bytes including
alignment) move into `src/sound_wave.c`. They preserve wave archive lookup,
24-bit file IDs, heap allocation, file reads, byte reversal, playback setup,
and buffer cleanup, including the original failure and assertion paths.
The cry caller's declaration now exposes the existing Boolean return value.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.749037% to 22.757029% (+0.007992 percentage points), from
929,310 to 929,636 C bytes out of 4,085,050 mapped bytes. This adds 326 C
bytes; two alignment bytes leave the mapped total. There are now 107
converted functions and 7,642 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twentieth batch: capture, track controls, and fade-delay state

Fifteen routines from `0x020058F4` through `0x020059EF` (252 bytes including
alignment) move into `src/sound_track.c`. They preserve capture queries and
reverb stop, pitch/pan/tempo dispatch, mono state, fade timer writes and
countdown, master volume, scratch-buffer access, and the sequence reload
flag. The remaining assembly imports its three moved helper dependencies.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.757029% to 22.763046% (+0.006017 percentage points), from
929,636 to 929,880 C bytes out of 4,085,042 mapped bytes. This adds 244 C
bytes; eight alignment bytes leave the mapped total. There are now 122
converted functions and 7,886 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-first batch: music transitions and channel allocation

Eight routines from `0x020059F0` through `0x02005B4F` (352 bytes including
alignment) move into `src/sound_transition.c`. They preserve immediate and
faded music transitions, queued sequence/bank state, fade timings, channel
allocation masks, reverb handling, and the pause-or-stop decision.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.763046% to 22.771550% (+0.008504 percentage points), from
929,880 to 930,226 C bytes out of 4,085,036 mapped bytes. This adds 346 C
bytes; six alignment bytes leave the mapped total. There are now 130
converted functions and 8,232 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-second batch: GB Sounds controls and sequence tables

Fourteen routines from `0x02005B58` through `0x02005D0F` (440 bytes including
alignment) move into `src/sound_gb.c`. They preserve sequence variable reads,
volume/pitch presets, GB Sounds toggling, bidirectional sequence lookup,
channel masks, and sound-state flags. Existing constant tables remain in
assembly and are exported for C access. The eight-byte player-volume wrapper
is the only remaining code in `asm/unk_02004A44.s`.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.771550% to 22.782132% (+0.010582 percentage points), from
930,226 to 930,656 C bytes out of 4,085,026 mapped bytes. This adds 430 C
bytes; ten alignment bytes leave the mapped total. There are now 144
converted functions and 8,662 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-third batch: font-sprite allocation and text objects

Five routines from `0x02013534` through `0x020136B3` (384 bytes including
alignment) move into `src/font_sprite.c`. These cover font-system allocation
and destruction, text-object creation and deletion, and VRAM sizing. The
reconstructed system has twelve cell files and cell banks plus an object
pool; temporary glyph lists preserve the original sentinel links and calls.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.782132% to 22.791418% (+0.009286 percentage points), from
930,656 to 931,034 C bytes out of 4,085,020 mapped bytes. This adds 378 C
bytes; six alignment bytes leave the mapped total. There are now 149
converted functions and 9,040 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-fourth batch: font-sprite positioning and display settings

Nine routines from `0x020136B4` through `0x020138DF` (556 bytes including
alignment) move into `src/font_sprite.c`. They preserve absolute and
parent-relative positioning, coordinate queries, sprite visibility,
priority, draw priority, and palette controls. Each text object retains
its per-sprite offsets and the original iteration and assertion behavior.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.791418% to 22.804689% (+0.013271 percentage points), from
931,034 to 931,572 C bytes out of 4,085,002 mapped bytes. This adds 538 C
bytes; eighteen alignment bytes leave the mapped total. There are now 158
converted functions and 9,578 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-fifth batch: reusable font layouts and window copies

Seven routines from `0x020138E0` through `0x02013A4F` (368 bytes including
alignment) move into `src/font_sprite.c`. They cover palette offsets,
reusable glyph-layout allocation and cleanup, layout sizing, text-object
creation/destruction, and copying a window to main or sub OBJ VRAM. Layout
sentinels, allocation sizes, cache flushing, and original call order are
preserved. Palette setter arguments retain full-width values until their
byte-sized storage field; correcting those declarations preserves the
original battle caller without adding narrowing instructions.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.804689% to 22.813584% (+0.008895 percentage points), from
931,572 to 931,934 C bytes out of 4,084,996 mapped bytes. This adds 362 C
bytes; six alignment bytes leave the mapped total. There are now 165
converted functions and 9,940 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-sixth batch: tile copies and font object pool

Four routines from `0x02013A50` through `0x02013B23` (212 bytes including
alignment) move into `src/font_sprite.c`. They preserve checked row copies
from a window, object reset, the first-free-object scan, and glyph-size
selection. Targeted volatile reads retain the original row-width and pool
metadata accesses, with the source offset calculation kept in its original
order for matching.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.813584% to 22.818698% (+0.005114 percentage points), from
931,934 to 932,142 C bytes out of 4,084,992 mapped bytes. This adds 208 C
bytes; four alignment bytes leave the mapped total. There are now 169
converted functions and 10,148 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Twenty-seventh batch: glyph rectangle splitting and layout

Two routines from `0x02013B24` through `0x02013C5B` (312 bytes) move into
`src/font_sprite.c`. They select glyph sizes, insert layout nodes, split
remaining rectangles, and build successive rows. The reconstructed rectangle
and pending-remainder state preserve the original order and assertions.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.818698% to 22.826336% (+0.007638 percentage points), from
932,142 to 932,454 C bytes out of 4,084,992 mapped bytes. This adds 312 C
bytes. There are now 171 converted functions and 10,460 additional mapped C
bytes relative to the initial baseline. The HeartGold treemap was refreshed,
formatting passed, and GitHub CI was not used.

## Twenty-eighth batch: glyph VRAM uploads and sizing

Five routines from `0x02013C5C` through `0x02013E77` (540 bytes) move into
`src/font_sprite.c`. They allocate and copy glyph tiles, upload them to
main or sub OBJ VRAM, initialize image proxies, and calculate aligned
storage requirements. Image proxies now use the SDK structure; a targeted
volatile offset preserves the original stack reloads.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.826336% to 22.839555% (+0.013219 percentage points), from
932,454 to 932,994 C bytes out of 4,084,992 mapped bytes. This adds 540 C
bytes. There are now 176 converted functions and 11,000 additional mapped C
bytes relative to the initial baseline. The HeartGold treemap was refreshed,
formatting passed, and GitHub CI was not used.

## Twenty-ninth batch: finish font sprite code

Eight routines from `0x02013E78` through `0x02013FDB` (356 bytes including
alignment) move into `src/font_sprite.c`. They construct sprite resources
and positions, delete sprites, allocate and release glyph nodes, link nodes,
and update the parent sprite. The original font assembly unit now contains
only its glyph dimension table; all its executable code is in C.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.839555% to 22.848081% (+0.008526 percentage points), from
932,994 to 933,340 C bytes out of 4,084,982 mapped bytes. This adds 346 C
bytes; ten alignment bytes leave the mapped total. There are now 184
converted functions and 11,346 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Thirtieth batch: battle-record lifecycle and save state

Twelve routines from `0x0202FBCC` through `0x0202FF07` (828 bytes including
alignment) move into `src/battle_record.c`. They initialize and manage the
record buffer, load and validate saved records, drive asynchronous writes,
prepare checksums and encryption, and select participant/party counts.
The save structure exposes its initialized first word while retaining the
original total size and remaining layout.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.848081% to 22.868313% (+0.020232 percentage points), from
933,340 to 934,166 C bytes out of 4,084,980 mapped bytes. This adds 826 C
bytes; two alignment bytes leave the mapped total. There are now 196
converted functions and 12,172 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Thirty-first batch: battle-record summaries and validation

Seven routines from `0x0202FF08` through `0x020302A3` (924 bytes) move into
`src/battle_record.c`. They build Pokémon summaries and copy rulesets,
validate save markers, checksums and Pokémon values, wrap record encryption
and decryption, and access recorded command bytes. Reconstructed fields use
the existing Pokémon bitfields and link ruleset structure. The original
participant-order tables retain their addresses in assembly.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.868313% to 22.890932% (+0.022619 percentage points), from
934,166 to 935,090 C bytes out of 4,084,980 mapped bytes. This adds 924 C
bytes. There are now 203 converted functions and 13,096 additional mapped C
bytes relative to the initial baseline. The HeartGold treemap was refreshed,
formatting passed, and GitHub CI was not used.

## Thirty-second batch: battle capture, restoration and parties

Six routines from `0x020302A4` through `0x0203077B` (1,240 bytes including
alignment) move into `src/battle_record.c`. They capture and restore battle
configuration, trainer and player data, handle AI flags, and convert parties
to and from recorded Pokémon. The record data layout now includes proper
party headers and profiles. BattleSetup exposes its four AI words and four
recorded bytes at their original offsets.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.890932% to 22.921212% (+0.030280 percentage points), from
935,090 to 936,326 C bytes out of 4,084,976 mapped bytes. This adds 1,236 C
bytes; four alignment bytes leave the mapped total. There are now 209
converted functions and 14,332 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Thirty-third batch: finish battle-record accessors

Fourteen routines from `0x0203077C` through `0x02030A97` (796 bytes including
alignment) move into `src/battle_record.c`. They copy and import record
sections, expose bounded summary values, allocate and clear summaries, and
read and write Frontier record fields. The original battle-record assembly
unit now retains only its tables and global buffer pointer.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.921212% to 22.940585% (+0.019373 percentage points), from
936,326 to 937,116 C bytes out of 4,084,970 mapped bytes. This adds 790 C
bytes; six alignment bytes leave the mapped total. There are now 223
converted functions and 15,122 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used.

## Thirty-fourth batch: Frontier state and field accessors

Thirty-seven routines from `0x02030A98` through `0x02030FFF` (1,384 bytes
including alignment) move into `src/frontier_state.c`. They initialize
facility state, read and write flags, packed nibbles and indexed fields,
and return the original save substructures. Two formerly void declarations
now expose their actual pointer returns. Targeted volatile parameter loads
preserve the original unconditional stack argument reads.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.940585% to 22.974012% (+0.033427 percentage points), from
937,116 to 938,476 C bytes out of 4,084,946 mapped bytes. This adds 1,360 C
bytes; twenty-four alignment bytes leave the mapped total. There are now
260 converted functions and 16,482 additional mapped C bytes relative to
the initial baseline. The HeartGold treemap was refreshed, formatting
passed, and GitHub CI was not used.

## Thirty-fifth batch: Frontier saves and statistics; 23% reached

Twenty-one routines from `0x02031000` through `0x020314A3` (1,188 bytes
including alignment) move into `src/frontier_save.c`. They initialize and
commit Frontier saves, manage stat rows and packed flags, update bounded
statistics, and synchronize extra save records. Recovered layouts expose
32 rows of statistics and the three extra-record stat arrays without
changing either save size. An existing caller now explicitly passes the
Frontier pointer to the stat reset function.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 22.974012% to 23.002906% (+0.028894 percentage points), from
938,476 to 939,654 C bytes out of 4,084,936 mapped bytes. This adds 1,178 C
bytes; ten alignment bytes leave the mapped total. There are now 281
converted functions and 17,660 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed, formatting passed,
and GitHub CI was not used. The requested 23% C-only coverage target has
been reached with both retail ROMs verified.

## Thirty-sixth batch: Frontier cards (Sol parallel experiment, task 1)

Ten routines from `0x020314A4` through `0x0203164B` move into
`src/frontier_card.c`. They allocate and populate Frontier cards and read
validated profile, favorite Pokémon, and location fields. The recovered
card retains its 128-byte layout and CRC span.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 23.002906% to 23.013097% (+0.010191 percentage points), from
939,654 to 940,068 C bytes out of 4,084,926 mapped bytes. This adds 414 C
bytes; ten alignment bytes leave the mapped total. There are now 291
converted functions and 18,074 additional mapped C bytes relative to the
initial baseline. The HeartGold treemap was refreshed and formatting passed.
GitHub CI remained disabled.

The Sol worker took 5 minutes 23 seconds (22:12:28–22:17:51 UTC) to produce
this candidate. Integration and serial verification of both ROMs are timed
separately in the overall five-task experiment.

## Thirty-seventh batch: fashion save records (Sol task 2)

Ten routines from `0x0202B614` through `0x0202B847` move into
`src/fashion_save.c`. They validate record markers, copy Pokémon identity
and text fields, restore Pokémon, and manage packed accessory values.
The record exposes separate nickname and secondary text arrays.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 23.013097% to 23.026754% (+0.013656 percentage points), from
940,068 to 940,624 C bytes out of 4,084,918 mapped bytes. This adds 556 C
bytes; eight alignment bytes leave the mapped total. There are now 301
converted functions and 18,630 additional mapped C bytes relative to the
initial baseline. The treemap was refreshed, formatting passed, and GitHub
CI remained disabled. The Sol worker took 6 minutes 49 seconds
(22:12:38–22:19:27 UTC), excluding integration and ROM verification.

## Thirty-eighth batch: Apricorn save helpers (Sol task 3)

Fifteen routines from `0x02031B0C` through `0x02031C07` move into
`src/apricorn_save.c`. They initialize the 128-byte save, manage Apricorn
quantities and Kurt's selection, and access packed state. The original ball
table remains in assembly. The Give function now declares its actual return;
its byte-sized quantity parameter is retained and widened internally so
existing callers also remain byte-identical.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 23.026754% to 23.032847% (+0.006094 percentage points), from
940,624 to 940,872 C bytes out of 4,084,914 mapped bytes. This adds 248 C
bytes; four alignment bytes leave the mapped total. There are now 316
converted functions and 18,878 additional mapped C bytes relative to the
initial baseline. The treemap was refreshed, formatting passed, and GitHub
CI remained disabled.

The Sol worker took 14 minutes 45 seconds (22:12:51–22:27:36 UTC).
Integration caught a script-caller mismatch caused by initially widening
the public quantity parameter. Preserving that parameter and using a local
int fixed the caller while retaining the matching helper implementation;
both complete ROM checks passed after the correction.

## Thirty-ninth batch: billboard list lifecycle (Sol task 4)

Five routines from `0x02023694` through `0x020237EB` move into
`src/billboard.c`. They initialize billboard records and embedded objects,
allocate and free lists, and dispatch drawing and state transitions.
The recovered layouts preserve the original 0xE0-byte billboard and
0xC4-byte object sizes. The global list manager remains in assembly BSS.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 23.032847% to 23.041193% (+0.008346 percentage points), from
940,872 to 941,212 C bytes out of 4,084,910 mapped bytes. This adds 340 C
bytes; four alignment bytes leave the mapped total. There are now 321
converted functions and 19,218 additional mapped C bytes relative to the
initial baseline. The treemap was refreshed, formatting passed, and GitHub
CI remained disabled. The reused Sol worker took 3 minutes 59 seconds
(22:18:58–22:22:57 UTC), excluding integration and ROM verification.

## Fortieth batch: particle contexts (Sol task 5)

Four routines from `0x02014DA0` through `0x02014FA3` move into
`src/particle_context.c`. They initialize context slots, allocate particle
heaps and optional cameras, and release VRAM keys, cameras and contexts.
The private 0xDC-byte context layout preserves the existing public API.
Original vectors, callback tables and global slots remain in assembly.

Both full ROM hashes match retail locally. HeartGold C-only mapped coverage
increased from 23.041193% to 23.053825% (+0.012632 percentage points), from
941,212 to 941,728 C bytes out of 4,084,910 mapped bytes. This adds 516 C
bytes without changing the mapped total. There are now 325 converted
functions and 19,734 additional mapped C bytes relative to the initial
baseline. The treemap was refreshed, formatting passed, and GitHub CI
remained disabled. The reused Sol worker took 3 minutes 30 seconds
(22:21:35–22:25:05 UTC), excluding integration and ROM verification.

### Five-task Sol experiment results

The experiment began at 22:09:48 UTC on 2026-09-09. All candidates were
ready by 22:27:36 UTC (17 minutes 48 seconds including setup); final local
ROM verification completed by 22:49:02 UTC (39 minutes 14 seconds).
The session allowed only three Sol worker threads, including completed
threads in that limit, so two workers were reused for the fourth and fifth
independent tasks. Five simultaneous subagents were not available.

| Task | Functions | New mapped C bytes | Worker time |
| --- | ---: | ---: | ---: |
| Frontier cards | 10 | 414 | 5m 23s |
| Fashion saves | 10 | 556 | 6m 49s |
| Apricorn saves | 15 | 248 | 14m 45s |
| Billboard lists | 5 | 340 | 3m 59s |
| Particle contexts | 4 | 516 | 3m 30s |
| Total | 44 | 2,074 | 34m 26s summed worker time |

Coverage increased from 23.002906% to 23.053825%, or 0.050919 percentage
points. Every contribution was integrated separately and both complete
retail ROM hashes checked before its commit. The Apricorn caller mismatch
was corrected before committing. All verification was local; build CI
remained disabled and commit messages included `[skip ci]`.

This small-batch experiment achieved about 53 new mapped C bytes per minute
through final verification. The previous solo stretch added 11,190 bytes
in 2h 1m 25s, about 92 bytes per minute. This is not a controlled model
comparison: the functions and batch sizes differ. Parallel candidate work
overlapped, but repeated serial ROM builds and integration dominated this
run, so it did not improve overall throughput. A useful next experiment
would assign larger independent blocks while retaining the ROM checks.
