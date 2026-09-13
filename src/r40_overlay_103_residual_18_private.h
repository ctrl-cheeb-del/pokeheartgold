#ifndef R40_OV103_R18_PRIVATE_H
#define R40_OV103_R18_PRIVATE_H
#include "global.h"

#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "mail.h"
#include "sprite_system.h"
typedef struct R40Ov103Work18 {
    u8 pad00[0xC];
    u8 *ctx;
    u8 pad10[0xF];
    u8 mailIndex;
    u8 pad20[0x230];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    u8 pad258[0x1C];
    NARC *narc;
} R40Ov103Work18;
#define P18(a, o, T) (*(T **)((u8 *)(a) + (o)))
#define U818(a, o)   (*(u8 *)((u8 *)(a) + (o)))
extern u32 GetMonIconNaixEx(u32, u32, u32);
extern u32 sub_02074490(void);
extern u32 sub_02074494(void);
extern u32 sub_02074498(void);
extern void ov103_021EE0CC(void *, u32, u32);
void ov103_021EE160(R40Ov103Work18 *);
void ov103_021EE210(R40Ov103Work18 *);
void ov103_021EE2E0(R40Ov103Work18 *);
#endif
