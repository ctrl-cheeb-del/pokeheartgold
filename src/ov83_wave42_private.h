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
