#ifndef TO46_OVERLAY83_PRIVATE_H
#define TO46_OVERLAY83_PRIVATE_H

#include "global.h"

#include "frontier/overlay_80_022340E8.h"

#include "bg_window.h"
#include "heap.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "poke_overlay.h"
#include "unk_02030A98.h"
#include "unk_020379A0.h"
#include "unk_02096910.h"
#include "vram_transfer_manager.h"

FS_EXTERN_OVERLAY(OVY_80);

void Main_SetVBlankIntrCB(void (*cb)(void *), void *arg);
void ov83_0223F058(void *work);
BOOL ov83_0223DFBC(OverlayManager *manager);
void ov83_0223F1C8(void);
void ov83_0223F200(void *work);
void ov83_022477E4(u32 *p);
BOOL ov83_0223DD60(OverlayManager *manager, int *state);
BOOL ov83_0223E008(void *work);
BOOL ov83_02241368(void *work, int a, int b);
void ov83_0223E10C(void *work);
void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, enum HeapID);
BOOL IsPaletteFadeFinished(void);

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct To46Ov83Work {
    u8 pad_000[0x7FF];
    u8 flags[3];
} To46Ov83Work;

#endif
