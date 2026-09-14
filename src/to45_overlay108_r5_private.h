#ifndef TO45_OV108_R5_PRIVATE_H
#define TO45_OV108_R5_PRIVATE_H

#include "global.h"

typedef struct SafariAreaCustomizer {
    u8 pad00000[0xC];
    u32 unk0C;
    u8 pad00010[0x1C - 0x10];
    u8 areas[6][0x7A];
    u8 pad002F8[0x340 - 0x2F8];
    void *bgConfig;
    u8 pad00344[0x354 - 0x344];
    void *sprites[18];
    u8 pad0039C[0x4C4 - 0x39C];
    void (*cb4C4)(struct SafariAreaCustomizer *);
    void (*cb4C8)(struct SafariAreaCustomizer *);
    u8 pad004CC[0x184DE - 0x4CC];
    u8 unk184DE;
    u8 unk184DF;
    u8 unk184E0;
    u8 unk184E1;
    u8 unk184E2;
    u8 unk184E3;
    s16 unk184E4;
    s16 unk184E6;
    u32 unk184E8;
} SafariAreaCustomizer;

typedef struct Ov108System {
    u8 pad00[0x48];
    u32 buttons;
    u8 pad4C[0x60 - 0x4C];
    u16 touchX;
    u16 touchY;
} Ov108System;

extern Ov108System gSystem;
extern const u8 ov108_021EA760[];
extern const u8 ov108_021EA7D0[];

extern void PlaySE(u32 seqNo);
extern s32 TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);
extern BOOL DoesPixelAtScreenXYMatchPtrVal(void *bgConfig, u32 bgId, u32 x, u32 y, u16 *value);
extern void SafariZone_InitAreaInSet(void *areaSet, u32 areaNo, u32 areaId);
extern void ov108_021E6A58(SafariAreaCustomizer *s);
extern void ov108_021E6B00(SafariAreaCustomizer *s);
extern void ov108_021E78F4(SafariAreaCustomizer *s, u32 index, u32 anim);
extern void ov108_021E79A8(SafariAreaCustomizer *s, u32 a, u32 b, u32 c);
extern void ov108_021E7BB4(SafariAreaCustomizer *s, u32 index, u32 value);
extern void ov108_021E7CD8(SafariAreaCustomizer *s, u32 value);
extern void ov108_021E7EB0(SafariAreaCustomizer *s);
extern void ov108_021E78C0(SafariAreaCustomizer *s, u32 index, u32 anim, u32 draw);
extern void Sprite_SetAnimActiveFlag(void *sprite, BOOL active);
extern void Sprite_ResetAnimCtrlState(void *sprite);

u32 ov108_021E63B8(SafariAreaCustomizer *s);
u32 ov108_021E6450(SafariAreaCustomizer *s);
u32 ov108_021E62B4(SafariAreaCustomizer *s);
u32 ov108_021E66AC(SafariAreaCustomizer *s);
u32 ov108_021E64C0(SafariAreaCustomizer *s);

#endif
