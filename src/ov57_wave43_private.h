#ifndef SOL_R29_PRIVATE_H
#define SOL_R29_PRIVATE_H
#include "global.h"
typedef struct ManagedSprite ManagedSprite;
typedef struct Ov57SpriteSlot {
    u32 active;
    u8 x;
    u8 y;
    u8 z;
    u8 padding;
    ManagedSprite *sprite;
    void *effect;
} Ov57SpriteSlot;
typedef struct Ov57Work {
    u8 padding00[0xD4];
    u32 selected;
    u8 paddingD8[8];
    void *spriteManager;
    u8 paddingE4[0x1A4];
    u32 needsPrioritySort;
    u8 padding28C[0xC0];
    Ov57SpriteSlot slots[8];
} Ov57Work;
typedef struct Ov57SpriteTemplate {
    s16 x, y, z;
    u16 animation;
    s32 drawPriority;
    s32 palette;
    s32 vram;
    s32 resources[6];
    s32 bgPriority;
    s32 vramTransfer;
} Ov57SpriteTemplate;
typedef struct Ov57Coordinates {
    u8 values[24];
} Ov57Coordinates;
u32 ManagedSprite_GetDrawPriority(ManagedSprite *);
void ManagedSprite_SetDrawPriority(ManagedSprite *, u32);
void ManagedSprite_SetDrawFlag(ManagedSprite *, BOOL);
void ManagedSprite_GetPositionXY(ManagedSprite *, s16 *, s16 *);
void ManagedSprite_SetOamMode(ManagedSprite *, GXOamMode);
void ov57_02238044(u8 *, s32);
void ov57_0223809C(u8 *, void *, s32);
BOOL ov57_022382F8(Ov57Work *, u32, s32);
BOOL ov57_02238260(Ov57Work *, s32);
void ov57_02238134(Ov57Work *);
BOOL ov57_022383F8(u8 *, s32);
void ov57_02238438(u8 *, s32);
void ov57_0223848C(u8 *, s32);
void ov57_02238508(u8 *, s32);
void ov57_022383AC(u8 *);
void ov57_022383D0(u8 *, BOOL);
BOOL ov57_022384C0(u8 *);
void SealCase_SetCapsuleI(void *, const u8 *, u32);
void ov57_0223853C(u8 *);
void ov57_0223857C(u8 *, u8 *);
void ov57_022385A4(u8 *, ManagedSprite *, s32, s32);
void ov57_022385DC(u8 *);
s32 ov07_022344E4(s32, s32, s32, s32);
void ov57_02239814(void *, void *, s32, s32, s32, s32, s32, s32);
u32 sub_02091054(u32);
void SpriteManager_UnloadCharObjById(void *, u32);
void Sprite_DeleteAndFreeResources(ManagedSprite *);
void ov57_02237E90(void *, s32, s32);
void ov57_02237EB8(void *, ManagedSprite *, BOOL);
u8 SpriteSystem_LoadPaletteBuffer(void *, s32, void *, void *, s32, s32, BOOL, s32, s32, s32);
BOOL SpriteSystem_LoadCharResObj(void *, void *, s32, s32, BOOL, s32, s32);
BOOL SpriteSystem_LoadCellResObj(void *, void *, s32, s32, BOOL, s32);
BOOL SpriteSystem_LoadAnimResObj(void *, void *, s32, s32, BOOL, s32);
ManagedSprite *SpriteSystem_NewSprite(void *, void *, const Ov57SpriteTemplate *);
void ManagedSprite_TickFrame(ManagedSprite *);
#endif
