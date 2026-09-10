#ifndef POKEHEARTGOLD_FIELD_EFFECT_MAP_MARKER_INTERNAL_H
#define POKEHEARTGOLD_FIELD_EFFECT_MAP_MARKER_INTERNAL_H

#include "global.h"

#include "map_object.h"
#include "overlay_01_021F1348.h"
#include "unk_02023694.h"
#include "unk_020689C8.h"

// The 0x24-byte argument block handed to ov01_021F1620 as a4 and recovered
// inside the renderer via sub_02068D98.
typedef struct {
    int unk00;               // 0x00
    int unk04;               // 0x04
    int unk08;               // 0x08
    void *unk0C;             // 0x0c
    FieldSystem *unk10;      // 0x10
    UnkOv01_021FFECC *unk14; // 0x14
    LocalMapObject *unk18;   // 0x18
    s16 unk1C;               // 0x1c
    s16 unk1E;               // 0x1e
    s8 unk20;                // 0x20
} UnkOv01_02209218_Args;     // sizeof == 0x24

// The 0x40-byte per-instance work block (template unk0 == 0x40).
typedef struct {
    int unk00;                   // 0x00 state
    u32 unk04;                   // 0x04 sprite id
    u32 unk08;                   // 0x08 local map object id
    u32 unk0C;                   // 0x0c map id
    u32 unk10;                   // 0x10
    BOOL unk14;                  // 0x14
    UnkOv01_02209218_Args unk18; // 0x18 .. 0x3c
    Sprite *unk3C;               // 0x3c
} UnkOv01_02209218_Work;         // sizeof == 0x40

void ov01_021F18D4(void *a0, int a1, int a2);
void ov01_021F1908(void *a0, int a1, int a2);
void ov01_021F1930(void *a0, int a1, int a2, int a3);
void ov01_021F1758(void *a0, int a1, int a2, int a3, int a4, int a5, const void *a6);
void ov01_021F18FC(void *a0, int a1);
void ov01_021F1924(void *a0, int a1);
void ov01_021F1970(void *a0, int a1);
void ov01_021F18C8(void *a0, int a1);
Sprite *ov01_021F1740(FieldSystem *a0, int a1, VecFx32 *a2);

// sub_02068D98 comes from the tracked include/unk_020689C8.h (returns UnkOv01_021FFFCC *)
void *sub_02068D90(void *a0);
void *sub_02023DA4(Sprite *a0);
void sub_02023F1C(Sprite *a0, fx32 a1);
fx32 sub_02023F70(Sprite *a0);
void sub_02023E50(Sprite *a0, VecFx32 *a1);
void sub_02023F04(Sprite *a0, fx32 a1);
void sub_02068DA8(void *a0, VecFx32 *a1);
BOOL sub_0206121C(void *a0, VecFx32 *a1);

#endif // POKEHEARTGOLD_FIELD_EFFECT_MAP_MARKER_INTERNAL_H
