#ifndef POKEHEARTGOLD_FIELD_HONEY_SWEET_SCENT_OVERLAY_01_021FC05C_H
#define POKEHEARTGOLD_FIELD_HONEY_SWEET_SCENT_OVERLAY_01_021FC05C_H

// Thumb comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include "global.h"

#include "field/encounter_check.h"
#include "field/field_3d_object_task.h"

#include "assert.h"
#include "bg_window.h"
#include "field_system.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "map_header.h"
#include "overlay_01.h"
#include "script_manager.h"
#include "task.h"
#include "unk_02005D10.h"

// Declared in include/summary_screen_helpers_internal.h (not includable here).
extern void G2x_SetBlendAlpha_(u32 reg, int plane1, int plane2, int eva, int evb);

// Still assembly-only (asm/overlay_01_021EB31C region); no tracked prototype exists.
extern u32 ov01_021EB31C(void *weatherManager);

// PlayerAvatar accessors live in *_internal.h headers only.
extern u32 PlayerAvatar_GetXCoord(PlayerAvatar *playerAvatar);
extern u32 PlayerAvatar_GetZCoord(PlayerAvatar *playerAvatar);
extern u8 GetMetatileBehavior(FieldSystem *fieldSystem, u32 x, u32 z);

// 0x18 bytes: the Field3dObjectTask data block for both templates.
typedef struct HoneySweetScentAnim {
    int cur;     // 0x00
    int start;   // 0x04
    int delta;   // 0x08
    int counter; // 0x0c
    int max;     // 0x10
    int done;    // 0x14
} HoneySweetScentAnim;

// 0xc bytes: GetHoneySweetScentWorkSize() returns sizeof(this).
typedef struct HoneySweetScentEnv {
    Field3dObjectTask *task; // 0x00
    int useSweetScentFx;     // 0x04
    u16 state;               // 0x08
    s16 timer;               // 0x0a
} HoneySweetScentEnv;

#endif // POKEHEARTGOLD_FIELD_HONEY_SWEET_SCENT_OVERLAY_01_021FC05C_H
