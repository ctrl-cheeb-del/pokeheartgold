#ifndef OV96_R43_PRIVATE_H
#define OV96_R43_PRIVATE_H
#include "global.h"
#include "constants/heap.h"
extern void GF_AssertFail(void);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern void *ov96_021E8A20(void *);
extern void *Heap_Alloc(enum HeapID, u32);
extern void *NARC_New(int, enum HeapID);
extern const u8 ov96_0221B19A[];
extern void AddWindow(void *, void *, const void *);
extern void FillWindowPixelBuffer(void *, int);
extern void ClearWindowTilemap(void *);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void NARC_Delete(void *);
extern void Heap_Free(void *);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void String_Delete(void *);
extern void RemoveTextPrinter(u8);
extern void ClearFrameAndWindow2(void *, int);
extern void *WaitingIcon_New(void *, int);
extern void sub_0200F450(void *);
extern void LoadFontPal0(int, int, enum HeapID);
extern void LoadUserFrameGfx2(void *, int, int, int, int, enum HeapID);
int ov96_021EE264(const u32 *, u32);
void *ov96_021EE740(enum HeapID);
void ov96_021EE944(u8 *);
void ov96_021EE60C(u8 *, void *);
BOOL ov96_021EE54C(void *);
BOOL ov96_021EE580(void *);
void *ov96_021EE5B4(void *, enum HeapID);
void ov96_021EE5E0(u8 *);
void ov96_021EE808(u8 *);
void *ov96_021EE97C(u8 *);
void ov96_021EE994(u8 *);
void ov96_021EE9BC(u8 *);
void ov96_021EE9D8(void *, int, enum HeapID);
#endif
