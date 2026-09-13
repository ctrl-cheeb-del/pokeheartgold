#ifndef OV113_R40_PRIVATE_H
#define OV113_R40_PRIVATE_H
#include "global.h"
typedef struct State {
    u8 raw[0x200];
} State;
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
void ov113_021E5F94(State *, int *);
void ov113_021E5F48(State *);
void FillWindowPixelBuffer(void *, int);
void ov113_021E5FC0(State *);
void ov113_021E6084(State *, u8);
void ov113_021E613C(State *, u8);
void BufferIntegerAsString(void *, int, int, int, int, int);
void StringExpandPlaceholders(void *, void *, void *);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
void ScheduleWindowCopyToVram(void *);
void ov113_021E6B1C(State *);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_ResetAnimCtrlState(void *);
u32 FontID_String_GetWidth(int, void *, int);
extern const u16 ov113_021E6BD0[][2];
void ov113_021E5D60(State *);
u8 ov113_021E5D80(State *);
void ov113_021E5DA4(State *);
void ov113_021E5E64(State *, int);
#endif
