#ifndef SOL_R40_OV108_R4_PRIVATE_H
#define SOL_R40_OV108_R4_PRIVATE_H
#include "global.h"
typedef struct Ov108Sub Ov108Sub;
typedef struct SafariAreaCustomizer4 {
    u32 heapId;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    void *unk14;
    void *unk18;
    u8 areaData[0x340 - 0x1C];
    u8 pad340[8];
    Ov108Sub *sub;
    void *spriteSystem;
    void *spriteManager;
    void *sprites[6];
    void *areaSprites[12];
    u8 pad39C[0x184DF - 0x39C];
    u8 unk184DF;
    u8 unk184E0;
    u8 unk184E1;
    u8 flag0 : 1;
    u8 bit1 : 1;
    u8 flagB : 1;
    u8 mode : 5;
    u8 unk184E3;
    s16 unk184E4;
    s16 unk184E6;
    u32 unk184E8;
} SafariAreaCustomizer4;
void ManagedSprite_SetPriority(void *, int);
void GfGfx_EngineBTogglePlanes(int, int);
BOOL ov108_021E82E0(SafariAreaCustomizer4 *, int);
void SafariZone_SwapAreasInSet(void *, u8, u8);
void ov108_021E84F8(Ov108Sub *, u8, u8);
void ov108_021E7BB4(SafariAreaCustomizer4 *, u32, int);
void ov108_021E6850(SafariAreaCustomizer4 *);
u32 ov108_021E6090(SafariAreaCustomizer4 *);
#endif
