#ifndef OV96_R40_RESIDUAL80_PRIVATE_H
#define OV96_R40_RESIDUAL80_PRIVATE_H

#include "global.h"

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern const u32 ov96_0221C728[];
extern const u8 ov96_0221C760[];
extern const u8 ov96_0221C768[];

void FillWindowPixelBuffer(void *, int);
void BufferString(void *, u32, void *, s32, s32, s32);
void *ReadMsgData_ExpandPlaceholders(void *, void *, u32, u32);
void *NewString_ReadMsgData(void *, u32);
void AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
void String_Delete(void *);
void CopyWindowToVram(void *);
void AddWindow(void *, void *, const void *);
void BG_FillCharDataRange(void *, u32, u32, u32, u32);
void LoadFontPal0(u32, u32, u32);
void *Heap_Alloc(u32, u32);
void MI_CpuFill8(void *, u8, u32);

void ov96_021EB408(void *, u32, u32, u32, u32);
void *ov96_021EB4F4(void *, u32, u32);
void *ov96_021EB5B8(void *);
void ov96_021EB52C(void *, u32, u32);
void ov96_021EB564(void *, u32);
void ov96_021EB588(void *, const VecFx32 *);
void **ov96_021EB5EC(void *, u32, u32);
void Sprite_SetMatrix(void *, const VecFx32 *);
void *SpriteTransfer_GetCharProxy(void *);
void *SpriteTransfer_GetPaletteProxy(void *, void *);
void ov96_02200BD8(void *, s32);
void ov96_02200C40(void *);
void ov96_02200C8C(void *, void *);
void ov96_02200D7C(void *, void *);
void ov96_02200DF8(void *);
void *ov96_02200E3C(u32, u8);

#endif
