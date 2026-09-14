#ifndef TO45_OV40_R27_U12_PRIVATE_H
#define TO45_OV40_R27_U12_PRIVATE_H

#include "global.h"

typedef struct ManagedSprite ManagedSprite;
typedef struct SpriteManager SpriteManager;
typedef struct SaveVarsFlags SaveVarsFlags;

typedef struct Ov40SpriteGroup {
    u8 pad00[4];
    float scale[5];
    s32 radius[5];
    s32 angle[5];
    ManagedSprite *group1[5];
    ManagedSprite *group2[5];
    ManagedSprite *group3[5];
    ManagedSprite *group4[5];
    u8 pad90[0x44];
    s32 transitionA;
    s32 transitionB;
} Ov40SpriteGroup;

typedef struct Ov40Work {
    u8 pad00[0x1C];
    SpriteManager *spriteManager;
    u8 pad20[0x840];
    Ov40SpriteGroup *sprites;
} Ov40Work;

typedef struct Ov40FiveWords {
    u32 values[5];
} Ov40FiveWords;

BOOL SpriteManager_UnloadCharObjById(SpriteManager *, u32);
BOOL SpriteManager_UnloadPlttObjById(SpriteManager *, u32);
BOOL SpriteManager_UnloadCellObjById(SpriteManager *, u32);
BOOL SpriteManager_UnloadAnimObjById(SpriteManager *, u32);
void Sprite_DeleteAndFreeResources(ManagedSprite *);
void ManagedSprite_SetAffineOverwriteMode(ManagedSprite *, u8);
void ManagedSprite_SetDrawFlag(ManagedSprite *, int);
void ManagedSprite_SetPositonFxXY(ManagedSprite *, fx32, fx32);
void ManagedSprite_GetPositionXY(ManagedSprite *, s16 *, s16 *);
void ManagedSprite_SetPositionXY(ManagedSprite *, s16, s16);
void ManagedSprite_SetAffineScale(ManagedSprite *, float, float);
fx32 GF_SinDeg(u16);
fx32 GF_CosDeg(u16);
BOOL ov40_0222DA00(s32 *, s32 *, int, int);
SaveVarsFlags *Save_VarsFlags_Get(void *saveData);
u16 Save_VarsFlags_GetBattleTowerPrintProgress(SaveVarsFlags *);
u16 Save_VarsFlags_GetBattleFactoryPrintProgress(SaveVarsFlags *);
u16 Save_VarsFlags_GetBattleArcadePrintProgress(SaveVarsFlags *);
u16 Save_VarsFlags_GetBattleCastlePrintProgress(SaveVarsFlags *);
u16 Save_VarsFlags_GetBattleHallPrintProgress(SaveVarsFlags *);
void *PaletteData_GetFadedBuf(void *, u32);
void PaletteData_SetAutoTransparent(void *, BOOL);
void ov40_022334F8(void *, u16, int);
extern const Ov40FiveWords ov40_02245174;
void ov40_02233550(void *work);
void ov40_022338D0(Ov40Work *work);
BOOL ov40_022339CC(Ov40Work *work);
BOOL ov40_02233AEC(Ov40Work *work);

#endif
