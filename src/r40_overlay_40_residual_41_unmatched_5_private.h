#ifndef CANDIDATE_PRIVATE_H
#define CANDIDATE_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
void ov40_0222D88C(void *);
void BgClearTilemapBufferAndCommit(void *, int);
void ov40_0222FB90(void *, int);
void *ov40_0222FBB4(void *);
int ov40_0222DA84(void *, int);
void ov40_0222DD08(void *);
void ov40_0222DAA8(void *);
void PaletteData_BlendPalettes(void *, int, int, int, u16);
void ov40_0222BF64(void *, int, int, void *);
void ov40_0222BF80(void *, int);
void Heap_Free(void *);
void SetBgPriority(int, int);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void ov40_02230964(void *, int);
void ov40_0222D874(void *);
void sub_0202FEB8(int, int *, int *);
void *String_New(int, int);
void *Heap_Alloc(int, int);
void ov40_02244A84(void *, int);
void CopyStringToU16Array(void *, u16 *, int);
void String_SetEmpty(void *);
void CopyU16ArrayToString(void *, u16 *);
int FontID_String_AllCharsValid(int, void *, void *);
int Party_GetCount(void *);
void *Party_GetMonByIndex(void *, int);
u32 GetMonData(void *, int, void *);
void SetMonData(void *, int, void *);
void String_Delete(void *);
#endif
