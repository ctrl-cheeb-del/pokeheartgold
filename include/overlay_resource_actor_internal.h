#ifndef POKEHEARTGOLD_OVERLAY_RESOURCE_ACTOR_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY_RESOURCE_ACTOR_INTERNAL_H
#include "global.h"
typedef struct SpriteCreate {
    u16 x, y;
    u8 unk4, unk5;
    u16 unk6;
    u32 rest[11];
} SpriteCreate;
typedef struct PokemonSpriteIds {
    u32 value[4];
} PokemonSpriteIds;
typedef struct Config32 {
    u32 value[8];
} Config32;
typedef struct Config20 {
    u32 value[5];
} Config20;
typedef struct Config24 {
    u32 value[6];
} Config24;

typedef struct Work {
    void *bg;         /* 00 */
    void *windows;    /* 04 */
    void *msgData;    /* 08 */
    void *msgFmt;     /* 0c */
    void *string;     /* 10 */
    void *palette;    /* 14 */
    void *pokepicMgr; /* 18 */
    void *pokepic1;   /* 1c */
    void *pokepic2;   /* 20 */
    void *party;      /* 24 */
    void *pokemon;    /* 28 */
    void *options;    /* 2c */
    u8 pad30[4];
    void *vramMan;     /* 34 */
    void *overlayMan;  /* 38 */
    void *summaryArgs; /* 3c */
    u8 pad40[4];
    void *unk44;   /* 44 */
    void *pokedex; /* 48 */
    void *bag;     /* 4c */
    void *stats;   /* 50 */
    u8 pad54[4];
    void *unk58; /* 58 */
    u32 heapId;  /* 5c */
    u8 pad60[2];
    u8 flag62; /* 62 */
    u8 pad63[4];
    u8 done; /* 67 */
    u8 pad68[4];
    u16 move; /* 6c */
    u8 pad6e[0xa];
    u32 action; /* 78 */
    u8 pad7c[0xe];
    u8 state;            /* 8a */
    u8 result;           /* 8b */
    u8 window1[0x10];    /* 8c */
    u8 window2[0x10];    /* 9c */
    void *spriteSystem;  /* ac */
    void *spriteManager; /* b0 */
    void *sprite;        /* b4 */
    void *spritesReady;  /* b8 */
} Work;

extern void GF_AssertFail(void);
extern void Sprite_DeleteAndFreeResources(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern int ManagedSprite_GetActiveAnim(void *);
extern int ManagedSprite_IsAnimated(void *);
extern void ManagedSprite_SetPositionXY(void *, int, int);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, int, u32);
extern void FillWindowPixelBuffer(void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
extern void CopyWindowToVram(void *);
extern void String_Delete(void *);
extern void BufferMoveName(void *, int, u16);
extern void ToggleBgLayer(int, int);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void FreeBgTilemapBuffer(void *, int);
extern void *OverlayManager_New(void *, void *, u32);
extern const u8 gOverlayTemplate_PokemonSummary[];
extern const short _020FFEC4[];
extern const short _020FFEC6[];
extern const SpriteCreate _020FFF5C;
extern void *SpriteSystem_NewSprite(void *, void *, const SpriteCreate *);
extern void ManagedSprite_SetAnimateFlag(void *, int);
void *sub_020755E8(void *, void *, u16, u16, u8);
extern int sub_020758D0(Work *);
extern int sub_020759CC(Work *);
extern void sub_02075804(Work *, void *, void *, int);
void sub_02075770(Work *);
void sub_020757AC(Work *);
void sub_0207584C(Work *, int);
int sub_02075A04(Work *);
BOOL sub_02075D3C(Work *);
void sub_020771A0(void *);
void sub_02077394(Work *);
extern void PokepicManager_DrawAll(void *);
extern void sub_020774E0(void);
extern void RequestSwap3DBuffers(int, int);
extern void SysTask_Destroy(void *);
extern void sub_02075E14(Work *);
void sub_02075D08(void *, Work *);
extern void sub_0200FBF4(int, int);
extern void Main_SetVBlankIntrCB(void *, int);
extern void FontID_Release(int);
extern void WindowArray_Delete(void *, int);
extern void RemoveWindow(void *);
extern void PaletteData_FreeBuffers(void *, int);
extern void PaletteData_Free(void *);
extern void PokepicManager_Delete(void *);
extern void sub_02016F2C(void *);
extern void GF_3DVramMan_Delete(void *);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void Heap_Free(void *);
extern void sub_020164C4(void *);
extern void NARC_Delete(void *);
extern void TextFlags_SetCanABSpeedUpPrint(int);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
extern void GfGfx_SwapDisplay(void);
extern u8 gSystem[];
void sub_02075D4C(Work *);
extern void *NewString_ReadMsgData(void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern int Options_GetTextFrameDelay(void *);
extern void AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
void sub_020772F8(Work *);
int sub_02077340(void *, int);
extern int GF_IsAnySEPlaying(void);
extern int IsFanfarePlaying(void);
extern void PlayFanfare(int);
extern void PlaySE(int);
extern void GetPokemonSpriteCharAndPlttNarcIds(PokemonSpriteIds *, void *, int);
extern void *PokepicManager_CreatePokepic(void *, PokemonSpriteIds *, int, int, int, int, int, int);
extern void *AllocMonZeroed(u32);
extern void CopyPokemonToPokemon(void *, void *);
extern void SetMonData(void *, int, void *);
extern void CalcMonLevelAndStats(void *);
extern void Pokepic_SetAttr(void *, int, int);
void sub_020771E8(Work *);
extern const u8 _020FFECC[];
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern void ManagedSprite_SetAnim(void *, int);
extern void PokepicManager_HandleLoadImgAndOrPltt(void *);
extern void SpriteSystem_DrawSprites(void *);
extern void SpriteSystem_TransferOam(void);
extern void GF_RunVramTransferTasks(void);
extern void PaletteData_PushTransparentBuffers(void *);
extern void DoScheduledBgGpuUpdates(void *);
void sub_02077270(Work *);
extern const Config32 _020FFF14;
extern const Config20 _020FFEE8;
extern const Config24 _020FFEFC;
extern void *SpriteSystem_Alloc(u32);
extern void *SpriteManager_New(void *);
extern void SpriteSystem_Init(void *, Config32 *, Config20 *, int);
extern void SpriteSystem_InitSprites(void *, void *, int);
extern void SpriteSystem_InitManagerWithCapacities(void *, void *, Config24 *);
extern void *NARC_New(int, u32);
extern void SpriteSystem_LoadPlttResObjFromOpenNarc(void *, void *, void *, int, int, int, int, int);
extern void SpriteSystem_LoadCharResObjFromOpenNarc(void *, void *, void *, int, int, int, int);
extern void SpriteSystem_LoadCellResObjFromOpenNarc(void *, void *, void *, int, int, int);
extern void SpriteSystem_LoadAnimResObjFromOpenNarc(void *, void *, void *, int, int, int);
void sub_02075630(Work *);
extern int Bag_GetQuantity(void *, int, u32);
extern int Party_GetCount(void *);
extern int Party_GetMaxCount(void *);
extern void *Mail_New(u32);
extern void UpdateMonAbility(void *);
extern void Party_AddMon(void *, void *);
extern void Pokedex_SetMonCaughtFlag(void *, void *);
extern void GameStats_Inc(void *, int);
extern void GameStats_AddScore(void *, int);
extern void Bag_TakeItem(void *, int, int, u32);
void sub_02076C90(Work *);

#endif
