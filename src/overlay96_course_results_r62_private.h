#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_RESULTS_R62_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_RESULTS_R62_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern void *ov96_021E8A20(void *);
extern void ov96_021EB5BC(void *);
extern void SpriteSystem_DrawSprites(void *);
extern void ov96_021F87D0(void *);
extern void AddWindow(void *, void *, const void *);
extern void BG_FillCharDataRange(void *, int, int, int, int);
extern void LoadFontPal0(int, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *MessageFormat_New(int);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, int, int);
extern int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void CopyWindowToVram(void *);
extern void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
extern void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
extern void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
extern u8 ov96_0221C2A0[];
extern u8 gSystem[];
extern u8 ov96_0221C290[];
extern const struct Ov96Banks {
    u32 word[10];
} ov96_0221C310;
extern const struct Ov96ScreenMode {
    u32 word[4];
} ov96_0221C2B4;
extern const struct Ov96BgTemplates {
    u32 word[42];
} ov96_0221C338;
extern u8 ov96_0221C298[];
extern void Main_SetVBlankIntrCB(void *, void *);
extern void Main_SetHBlankIntrCB(void *, void *);
extern void FontID_Release(int);
extern void ov96_021EE5E0(void *);
extern void RemoveWindow(void *);
extern void ov96_021EE808(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void ov96_021F8F0C(void *);
extern void ov96_021F8728(void *);
extern void ov96_021EB21C(void *);
extern void ov96_021F84E4(void *);
extern void Heap_Free(void *);
extern void PokeathlonCourse_FreePtr4HeapAlloc(void *);
extern void GfGfx_SwapDisplay(void);
extern void Heap_Destroy(int);
extern void sub_0203A914(void);
extern void GfGfx_SetBanks(const void *);
extern void SetBothScreensModesAndDisable(const void *);
extern void InitBgFromTemplate(void *, int, const void *, int);
extern void BgClearTilemapBufferAndCommit(void *, int);
extern void BG_ClearCharDataRange(int, int, int, int);
extern int LCRandom(void);
extern void ov96_021E8228(void *, int, int, int, int);

typedef struct Ov96CycleWork {
    u32 active;
    u8 *data;
    u8 counts[4];
    u8 base[4];
    u8 thresholds[12];
    u8 itemCount;
    u8 itemIndex;
    u8 tick;
    u8 tickLimit;
    u8 firstSlot;
    u8 disabled;
} Ov96CycleWork;

void ov96_021F7878(void *, void *, int);
void ov96_021F78C4(void *, int);
int ov96_021F7740(void *, Ov96CycleWork *);
void ov96_021F77EC(void *, Ov96CycleWork *, u8);
int ov96_021F7C4C(void *);
int ov96_021F7C70(void *);
void ov96_021F7D10(void);
void ov96_021F7D30(void *, int);
void ov96_021F7DA8(void *);
int ov96_021F7E64(void *);

#endif
