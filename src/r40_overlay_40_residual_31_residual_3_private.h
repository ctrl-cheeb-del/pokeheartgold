#ifndef OVERLAY_40_RESIDUAL_31_RESIDUAL_3_R40_PRIVATE_H
#define OVERLAY_40_RESIDUAL_31_RESIDUAL_3_R40_PRIVATE_H
#include "global.h"
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov40WindowTemplateR3 {
    u8 x, y, width, height;
} Ov40WindowTemplateR3;
extern const u32 ov40_02245268[];
extern const Ov40WindowTemplateR3 ov40_02245274[];
void InitWindow(void *);
void AddWindowParameterized(void *, void *, u32, u32, u32, u32, u32, u32, u32);
void FillWindowPixelBuffer(void *, u32);
void *NewString_ReadMsgData(void *, u32);
u32 ov40_022306C0(void *, void *);
u8 AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
void ScheduleWindowCopyToVram(void *);
void String_Delete(void *);
u32 FontID_String_GetWidthMultiline(u32, void *, u32);
void ov40_02237AC0(void *);
void ov40_02237B7C(void *, u32);
void ov40_02237BD4(void *);
#endif
