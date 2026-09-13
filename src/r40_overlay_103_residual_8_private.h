#ifndef R40_OV103_R8_PRIVATE_H
#define R40_OV103_R8_PRIVATE_H
#include "global.h"
typedef struct R40PalAnim {
    u8 isBg : 1;
    u8 target : 7;
    u8 pal0 : 4;
    u8 pal1 : 4;
    u8 state;
    u8 timer;
    u8 x, y, w, h;
} R40PalAnim;
typedef struct R40Ov103Work8 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work8;
extern void ManagedSprite_SetPaletteOverride(void *, u32);
extern void BgTilemapRectChangePalette(void *, u32, u32, u32, u32, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
BOOL ov103_021ED144(R40Ov103Work8 *);
#endif
