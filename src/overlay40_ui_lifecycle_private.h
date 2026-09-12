#ifndef POKEHEARTGOLD_OVERLAY40_UI_LIFECYCLE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_UI_LIFECYCLE_PRIVATE_H

#include "global.h"

#include "system.h"

typedef struct BattleAppWorkRaw {
    u8 raw[0x4170];
} BattleAppWorkRaw;
typedef struct Ov40SpriteSystemTemplate {
    u32 raw[8];
} Ov40SpriteSystemTemplate;
typedef struct Ov40SpriteResourceCapacities {
    u32 raw[5];
} Ov40SpriteResourceCapacities;
typedef struct Ov40SpriteManagerTemplate {
    u32 raw[6];
} Ov40SpriteManagerTemplate;

extern void GfGfx_EngineATogglePlanes(u8, u8);
extern void GfGfx_EngineBTogglePlanes(u8, u8);
extern void GfGfx_SwapDisplay(void);
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Free(void *);
extern void PaletteData_FreeBuffers(void *, int);
extern void PaletteData_Free(void *);
extern void *Save_Misc_Get(void *);
extern void sub_0202AC1C(void *, int);
extern void NARC_Delete(void *);
extern void SysTask_Destroy(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void sub_0203A914(void);
extern void sub_02021238(void);
extern void TouchHitboxController_Destroy(void *);
extern void TextFlags_SetCanTouchSpeedUpPrint(BOOL);
extern void sub_020135AC(void *);
extern void DestroyMsgData(void *);
extern void GF_3DVramMan_Delete(void *);
extern void PokepicManager_Delete(void *);
extern void ov40_0223D600(void *);
extern void GF_DestroyVramTransferManager(void);
extern void InitBgFromTemplate(void *, int, const void *, int);
extern const u8 ov40_02244D00[];
extern const Ov40SpriteSystemTemplate ov40_02244C80;
extern const Ov40SpriteResourceCapacities ov40_02244C54;
extern const Ov40SpriteManagerTemplate ov40_02244C68;
extern void *SpriteSystem_Alloc(int);
extern void SpriteSystem_Init(void *, const Ov40SpriteSystemTemplate *, const Ov40SpriteResourceCapacities *, int);
extern void *SpriteManager_New(void *);
extern BOOL SpriteSystem_InitSprites(void *, void *, int);
extern BOOL SpriteSystem_InitManagerWithCapacities(void *, void *, const Ov40SpriteManagerTemplate *);
extern void GF_AssertFail(void);
extern void *SpriteSystem_GetRenderer(void *);
extern void G2dRenderer_SetSubSurfaceCoords(void *, int, int);

#define OV40_PTR(w, o) (*(void **)((w)->raw + (o)))
#define OV40_U8(w, o)  (*(u8 *)((w)->raw + (o)))

void ov40_0222B934(BattleAppWorkRaw *work);
void ov40_0222BC44(int screen);
void ov40_0222BC54(BattleAppWorkRaw *work);
void ov40_0222BC68(BattleAppWorkRaw *work);

#endif
