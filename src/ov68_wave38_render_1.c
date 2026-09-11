#include "global.h"
typedef struct Ctx{void*camera;void*picman;}Ctx;
extern void Thunk_G3X_Reset(void);extern void Camera_PushLookAtToNNSGlb(void);extern void NNS_G3dGlbFlushP(void);extern void NNS_G2dSetupSoftwareSpriteCamera(void);extern void PokepicManager_DrawAll(void*);
void ov68_021E734C(Ctx*);
extern int GetMoveAttr(int,int);extern int sub_02077830(int);extern int sub_02077800(int);extern int sub_02077818(int);extern void SpriteSystem_ReplaceCharResObj(void*,void*,int,int,int,int);extern void ManagedSprite_SetPaletteOverride(void*,int);
void ov68_021E7124(void*,int);
extern void ov68_021E6DDC(void*);extern void ov68_021E6EB8(void*,void*);extern void*SpriteSystem_NewSprite(void*,void*,const void*);extern void ManagedSprite_SetAnimateFlag(void*,int);extern const u8 ov68_021E7E74[];
void ov68_021E7178(void*,void*);
extern void ManagedSprite_SetPositionXY(void*,int,int);extern void ManagedSprite_SetDrawFlag(void*,int);extern void ov68_021E7028(void*,u16,u16);
void ov68_021E70BC(void*);
extern void*PokepicManager_Create(int);extern void GetPokemonSpriteCharAndPlttNarcIds(void*,void*,int);extern void*PokepicManager_CreatePokepic(void*,void*,int,int,int,int,int,int);extern int GetMonData(void*,int,void*);extern int GetMonBaseStat_HandleAlternateForm(int,int,int);extern void Pokepic_SetAttr(void*,int,int);
void ov68_021E7224(Ctx*,void*,int);

void ov68_021E7124(void*w,int move){int attr=GetMoveAttr(move,1);int a=sub_02077830(attr);int b=sub_02077800(attr);SpriteSystem_ReplaceCharResObj(*(void**)((u8*)w+0x11c),*(void**)((u8*)w+0x120),a,b,1,0xb8aa);ManagedSprite_SetPaletteOverride(*(void**)((u8*)w+0x130),sub_02077818(attr)+4);}
