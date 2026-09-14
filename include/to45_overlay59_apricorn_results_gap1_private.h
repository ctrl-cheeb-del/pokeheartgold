#ifndef TO45_OVERLAY59_GAP1_PRIVATE_H
#define TO45_OVERLAY59_GAP1_PRIVATE_H

#include "global.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define S8_AT(p, n)  (*(s8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

typedef struct To45Nibble {
    u16 value : 4;
} To45Nibble;

extern const u32 ov59_0223C94C[];

extern void ReadMsgDataIntoString(void *, int, void *);
extern int AddTextPrinterParameterizedWithColor(void *, int, void *, u32, u32, u32, u32, void *);
extern void ScheduleWindowCopyToVram(void *);
extern void FillWindowPixelBuffer(void *, int);
extern void BufferIntegerAsString(void *, int, int, int, int, int);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void ov59_0223C3AC(void *);
extern void ov59_0223C380(void *, void *);
extern void ov59_0223BE18(void *, void *);
extern void Sprite_SetDrawFlag(void *, BOOL);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void ov59_0223BE44(void *, int, u8, BOOL);

void ov59_0223BBD4(void *, int);
void ov59_0223BC88(void *, int);
void ov59_0223BD4C(u8 *, u8 *, u8);

#endif
