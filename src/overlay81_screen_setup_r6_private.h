#ifndef POKEHEARTGOLD_OVERLAY81_SCREEN_SETUP_R6_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY81_SCREEN_SETUP_R6_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov81_022405F0(void *work);
void ov81_02240628(void *work, int layer, u8 x, u8 y, u8 width);
void ov81_02240658(void *work, int kind);
void ov81_02240698(void *work, int layer);
void ov81_022406E0(void *work, int layer);
void ov81_02240728(void *work, int layer);
void ov81_02240770(void);
void ov81_022407A8(void *work, int layer);
void ov81_022408B8(void *work, void *boxMon);
void ov81_022408C4(void *save, void *window, int x, int y, u8 font);
void ov81_0224093C(void *unused, void *window, int x, int y, u8 font);
void ov81_02240CD4(void *work);
void ov81_02240D2C(void);
void ov81_02240E78(void *work);

void BgSetPosTextAndCommit(void *, int, int, int, ...);
int Bg_GetXpos(void *, int);
void BgTilemapRectChangePalette(void *, u8, int, int, int, int, int);
void ScheduleBgTilemapBufferTransfer(void *, u8);
int ov81_02241340(void *, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
void *GfGfxLoader_GetPlttData(int, int, void **, int);
void Heap_Free(void *);
void FillWindowPixelBuffer(void *, int);
int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
void ScheduleWindowCopyToVram(void *);
void BufferBoxMonSpeciesName(void *, void *);
void *Save_PlayerData_GetProfile(void *);
void *String_New(int, int);
void *PlayerProfile_GetNamePtr(void *);
void CopyU16ArrayToString(void *, const u16 *);
int PlayerProfile_GetTrainerGender(void *);
void String_Delete(void *);
int sub_0203769C(void);
void *sub_02034818(int);
void PlayerName_FlatToString(void *, void *);
void Main_SetVBlankIntrCB(void *, void *);
void Main_SetHBlankIntrCB(void *, void *);
void GfGfx_DisableEngineAPlanes(void);
void GfGfx_DisableEngineBPlanes(void);
void *GF_3DVramMan_Create(int, int, int, int, int, void *);
void *BgConfig_Alloc(int);
void ov81_02242FDC(void *, void *);
void ov81_022430E8(void *);
void ov81_02242BC8(void);
void *Heap_Alloc(int, int);
int SaveArray_IsNatDexEnabled(void *);
void sub_02089D40(void *, void *);
void sub_0208AD34(void *, void *);
void ov81_02240D64(void *work);
extern u8 _02243458[];

#endif
