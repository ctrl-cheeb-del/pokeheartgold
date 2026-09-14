#ifndef SOL_R9_OV96_R08_PRIVATE_H
#define SOL_R9_OV96_R08_PRIVATE_H

#include "global.h"

typedef struct SolR9Ov96R08Graphics {
    u32 heapId;
    void *bgConfig;
} SolR9Ov96R08Graphics;

typedef struct SolR9Ov96R08Animation {
    void *owner;
    u8 pad004[8];
    void *spriteC;
    void *sprite10;
} SolR9Ov96R08Animation;

u32 GfGfxLoader_LoadCharData(u32 narcId, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 size, BOOL compressed, u32 heapId);
void GfGfxLoader_LoadScrnData(u32 narcId, s32 memberNo, void *bgConfig, u32 layer, u32 tileStart, u32 size, BOOL compressed, u32 heapId);
void GfGfxLoader_GXLoadPal(u32 narcId, s32 memberNo, u32 location, u32 offset, u32 size, u32 heapId);
void LoadFontPal0(u32 location, u32 offset, u32 heapId);
void ov96_021EAB38(void *owner, int value);
void ManagedSprite_SetPositionXYWithSubscreenOffset(void *sprite, s16 x, s16 y, fx32 offset);
void ManagedSprite_ResetSpriteAnimCtrlState(void *sprite);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ov96_022193CC(u32 value, void *course);
void ov96_0221663C(SolR9Ov96R08Graphics *work);
void ov96_02216A54(SolR9Ov96R08Animation *work, const s16 *position, u32 *flags, BOOL clear, void *course);

#endif
