#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_UI_R90_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_UI_R90_PRIVATE_H

#include "global.h"

#define OV96_R90_BYTE(p, n) (*(u8 *)((u8 *)(p) + (n)))
#define OV96_R90_WORD(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define OV96_R90_PTR(p, n)  (*(void **)((u8 *)(p) + (n)))

void GF_AssertFail(void);
void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void MI_CpuFill8(void *dest, u8 value, u32 size);
void ov96_021EB52C(void *sprite, int value, int arg);
void ov96_021EB564(void *sprite, int value);
BOOL sub_0200606C(u16 seqNo, int playerNo);
void DC_FlushRange(const void *ptr, u32 size);
void GXS_LoadOBJ(const void *src, u32 offset, u32 size);
void GXS_LoadOBJPltt(const void *src, u32 offset, u32 size);
void GX_LoadBG0Char(const void *src, u32 offset, u32 size);
void String_Delete(void *str);
void MessageFormat_Delete(void *fmt);
void DestroyMsgData(void *msgData);
void RemoveWindow(void *window);
void AddWindow(void *bgConfig, void *window, const void *template);
void BG_FillCharDataRange(void *bgConfig, int bgId, int value, int count, int heapId);
void LoadFontPal0(int bgId, int offset, int heapId);
void GetMonSpriteCharAndPlttNarcIdsEx(u16 *ids, u16 species, u8 value7, int two, u8 value6, u8 value2, u32 valueC);
void *sub_0201457C(u16 charNarc, u16 charFile, u32 heapId, u32 valueC, int zero, int two, u16 species);
void *sub_02014450(u16 plttNarc, u16 plttFile, u32 heapId);
extern const u8 ov96_0221CBEC[];

void ov96_02207BE4(void *work);
void ov96_02207C38(int x, int y, int seq, BOOL player);
void ov96_02207D64(void *work);
void ov96_02208250(void *work, const void *records);
void ov96_022082BC(void *work, u32 bank, u32 index);
void ov96_02208840(void *work, int index, u32 value);
void ov96_02208864(void *work, int index);
void ov96_02208A4C(void *work);
void ov96_02208A80(void **sprites, int value);
void *ov96_02208AA8(u32 heapId, int value);

#endif
