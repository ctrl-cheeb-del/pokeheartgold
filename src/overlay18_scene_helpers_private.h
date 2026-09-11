#ifndef R17_OVERLAY18_PRIVATE_H
#define R17_OVERLAY18_PRIVATE_H
#include "global.h"

#define R17_U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define R17_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define R17_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define R17_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Position18 {
    s16 y;
    s16 x;
} Position18;

typedef struct Work18BA4 {
    u8 pad[0x188c];
    u32 value188c;
} Work18BA4;

typedef struct Work18CA8 {
    void *root;
    u8 pad004[0x18a2 - 4];
    u16 species;
    u8 forms[1];
} Work18CA8;

void ov18_021F11C0(void *, u32, u32);
void ov18_021F2AC0(void *, u32);
void ov18_021F118C(void *, u32, u32);
void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
void ManagedSprite_SetPositionXY(void *, s16, s16);
void ManagedSprite_SetPaletteOverride(void *, u32);
u32 Pokedex_SpeciesGetLastSeenGender(void *, u32, u32);
void ov18_021F2648(void *);
void *SpriteSystem_NewSprite(void *, void *, const void *);
extern const u8 ov18_021FA554[];

void ov18_021F3AD8(void *);
void ov18_021F3B2C(void *, s32);
void ov18_021F3B60(void *, u32);
void ov18_021F3BA4(void *);
void ov18_021F3BD4(void *, s32);
void ov18_021F3C30(void *);
void ov18_021F3C54(void *, s32);
void ov18_021F3C88(void *);
void ov18_021F3CA8(void *, u32, u8 *, u8 *);
void ov18_021F3D34(void *);

#endif
