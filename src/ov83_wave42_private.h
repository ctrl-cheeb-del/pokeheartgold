#ifndef SOL40_R36_PRIVATE_H
#define SOL40_R36_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void Heap_Free(void *);
void *GfGfxLoader_GetPlttData(int, int, void *, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
void ov83_02246E08(void *, void *, u8);
typedef struct {
    u32 v[10];
} SolBanks;
extern SolBanks ov83_02247E88;
void GfGfx_SetBanks(void *);
int ov83_0223FC48(void *, void *, int, int, int, int, u8, u8, u8, u8);
int ov83_0223FCB4(void *, void *, int, int, int, int, u8, u8, u8, u8);
void ScheduleWindowCopyToVram(void *);
#endif
void ov83_0223F804(void *);
void *PaletteData_Init(int);
void PaletteData_AllocBuffers(void *, int, u32, int);
void PaletteData_PushTransparentBuffers(void *);
void DoScheduledBgGpuUpdates(void *);
void ov83_0224780C(void *);
void GF_RunVramTransferTasks(void);
void OamManager_ApplyAndResetBuffers(void);
void ov83_022477EC(int, int, void *);
void FillWindowPixelBuffer(void *, u8);
void ReadMsgDataIntoString(void *, int, void *);
void StringExpandPlaceholders(void *, void *, void *);
u8 AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void ov83_0223FFD8(void *, void *, int, int, int, void *, int, int, int);
u32 GetMonData(void *, int, void *);
void BufferMoveName(void *, int, u32);
void ov83_02240C48(void *, int, int, int, int);
void BufferItemName(void *, int, u32);
int GetMonNature(void *);
void BufferNatureName(void *, int, int);
void BufferAbilityName(void *, int, u32);
typedef struct SolModes {
    u32 v[4];
} SolModes;
typedef struct SolBgTemplate {
    u32 v[7];
} SolBgTemplate;
extern SolModes ov83_02247D38;
extern SolBgTemplate ov83_02247DA0, ov83_02247DBC, ov83_02247DF4, ov83_02247E10, ov83_02247E2C, ov83_02247E48, ov83_02247D84, ov83_02247DD8;
void SetBothScreensModesAndDisable(void *);
void InitBgFromTemplate(void *, int, void *, int);
void BG_ClearCharDataRange(int, int, int, int);
void BgClearTilemapBufferAndCommit(void *, int);
void *NARC_New(int, int);
void FontID_Alloc(int, int);
void *NewMsgDataFromNarc(int, int, int, int);
void *MessageFormat_New(int);
void *String_New(int, int);
void LoadFontPal0(int, int, int);
void LoadFontPal1(int, int, int);
void *MessagePrinter_New(int, int, int, int);
void ov83_022478D4(void *, void *);
void ov83_02240F7C(void *, s16 *, s16 *, s16 *, s16 *);
void *ov83_02247454(void *, int, int, int, int, int, int, int, int);
void *ov83_022474C4(void *, int, int, int, int, int, int, int, int);
void ov83_0224755C(void *, int);
int ov80_02237B24(u8, int);
void *Party_GetMonByIndex(void *, int);
int CalculateHpBarColor(u16, u16, int);
int ov83_022411B0(void *, int);
int ov83_022411DC(void *, int);
void ov83_022475EC(void *, void *);
void ov83_02242894(int, s16 *, s16 *);
void ov83_02240E70(void *, s16 *, s16 *, int);
void ov83_02241E18(void *);
void ov83_02241FF0(void *);
void ov83_022421E0(void *, int);
void ov83_02247668(void *, void *, u16, void *);
void *ov83_02247A24(void *, int, u8);
void *ov83_02247CB8(void *, void *);
void ov83_02247844(void *);
int sub_02037474(void);
void G2dRenderer_SetObjCharTransferReservedRegion(int, int);
void G2dRenderer_SetPlttTransferReservedRegion(int);
void sub_0203A880(void);
void G2x_SetBlendAlpha_(u32, int, int, int, int);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void ov83_0223F690(void *);
void ov83_0223F70C(void *);
void ov83_0223F7A0(void *);
