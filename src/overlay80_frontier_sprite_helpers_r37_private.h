#ifndef OVERLAY80_FRONTIER_SPRITE_HELPERS_R37_PRIVATE_H
#define OVERLAY80_FRONTIER_SPRITE_HELPERS_R37_PRIVATE_H

#include "global.h"

typedef struct Ov80R37ManagedSprite {
    void *sprite;
} Ov80R37ManagedSprite;
typedef struct Ov80R37ManagedSpriteTemplate {
    s16 x;
    s16 y;
    s16 z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} Ov80R37ManagedSpriteTemplate;
typedef struct Ov80R37FrontierMap {
    void *bgConfig;
    void *plttData;
    u8 padding08[0x34 - 0x08];
    void *spriteSystem;
    void *spriteManager;
    u8 padding3C[0x80 - 0x3C];
    Ov80R37ManagedSprite *sprites[4];
} Ov80R37FrontierMap;

extern const Ov80R37ManagedSpriteTemplate ov80_0223BD80;
void GF_AssertFail(void);
void Sprite_DeleteAndFreeResources(Ov80R37ManagedSprite *);
BOOL SpriteManager_UnloadCharObjById(void *, u32);
BOOL SpriteManager_UnloadPlttObjById(void *, u32);
BOOL SpriteManager_UnloadCellObjById(void *, u32);
BOOL SpriteManager_UnloadAnimObjById(void *, u32);
u32 sub_02074490(void);
u32 sub_02074498(void);
u32 sub_020744A4(void);
u8 SpriteSystem_LoadPaletteBuffer(void *, int, void *, void *, int, int, BOOL, int, int, int);
BOOL SpriteSystem_LoadCellResObj(void *, void *, int, int, BOOL, int);
BOOL SpriteSystem_LoadAnimResObj(void *, void *, int, int, BOOL, int);
BOOL SpriteSystem_LoadCharResObjAtEndWithHardwareMappingType(void *, void *, int, int, BOOL, int, int);
Ov80R37ManagedSprite *SpriteSystem_NewSprite(void *, void *, const Ov80R37ManagedSpriteTemplate *);
u32 Pokemon_GetIconNaix(void *);
u32 Pokemon_GetIconPalette(void *);
void Sprite_SetPalOffsetRespectVramOffset(void *, int);
void ManagedSprite_TickFrame(Ov80R37ManagedSprite *);
void ov80_0222F1D0(Ov80R37FrontierMap *, u32);
void ov80_0222F210(Ov80R37FrontierMap *);
void ov80_0222F278(Ov80R37FrontierMap *);
Ov80R37ManagedSprite *ov80_0222F29C(Ov80R37FrontierMap *, void *, s32, s32, s32);

#define PLTTBUF_MAIN_OBJ                2
#define NARC_poketool_icongra_poke_icon 0x14
#define NNS_G2D_VRAM_TYPE_2DMAIN        1
#define GF_GFX_RES_TYPE_CHAR            0
#endif
