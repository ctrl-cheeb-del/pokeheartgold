#ifndef TO45_OV40_R27_U19_PRIVATE_H
#define TO45_OV40_R27_U19_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

void *ov40_0222DAB0(u32 heapId);
void *ov40_0222DD68(u32 heapId, u32 unused, u32 *count);
void ov40_02230DCC(void *scene, void *string);

int WindowIsInUse(const void *window);
void InitWindow(void *window);
void AddWindowParameterized(void *bgConfig, void *window, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteNum, u16 baseTile);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void ScheduleWindowCopyToVram(void *window);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void *NewString_ReadMsgData(void *msgData, u32 msgId);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
u32 String_CountLines(void *str);
void String_GetLineN(void *dst, void *src, u32 line);
u32 FontID_String_GetWidth(u32 fontId, void *str, u32 letterSpacing);
void BufferString(void *fmt, u32 idx, void *str, u32 a, u32 b, u32 c);
void BufferECWord(void *fmt, u32 idx, void *word);
void StringExpandPlaceholders(void *fmt, void *dst, void *src);
void MessageFormat_Delete(void *fmt);
void sub_0202BE60(void *src, void *dst);
void *sub_0202BE98(void *src);

void *Save_Pokedex_Get(void *save);
BOOL Pokedex_CheckMonSeenFlag(void *pokedex, u32 species);
void Heap_Free(void *ptr);
void *Heap_Alloc(u32 heapId, u32 size);
void MI_CpuFill8(void *dst, u8 value, u32 size);
void *NewMsgDataFromNarc(u32 type, u32 narc, u32 file, u32 heapId);

extern u16 ov40_02245CD4[];

typedef struct Ov40SceneU19 {
    u8 pad000[0x830];
    void *save;
} Ov40SceneU19;

void ov40_02235B4C(void *scene);
void ov40_02235C7C(void *scene);
BOOL ov40_02235DAC(Ov40SceneU19 *scene, u32 selection);
void ov40_02235E34(void *scene, u32 selection);

#endif
