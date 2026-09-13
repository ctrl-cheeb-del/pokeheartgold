#ifndef SOL_R40_OV73_RESIDUAL_9_4_PRIVATE_H
#define SOL_R40_OV73_RESIDUAL_9_4_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov73_021E761C(void *);
void ov73_021E6830(void *);
int ov73_021E75FC(u32);
void RemoveTextPrinter(u8);
void ov73_021E71E4(void *, int, int);
void ScheduleBgTilemapBufferTransfer(void *, int);
void ov73_021E756C(void *, int, int);
void *sub_02034818(int);
void BufferPlayersName(void *, int, void *);
int sub_0203769C(void);
void ov73_021E781C(void *, int);
u32 sub_02037454(void);
void sub_02037030(int, void *, int);
void GF_AssertFail(void);
extern const u8 _021EA51C[];
void CopyToBgTilemapRect(void *, int, int, int, int, int, void *, int, int, int, int);
void *NewString_ReadMsgData(void *, int);
int FontID_String_GetWidth(int, void *, int);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
void String_Delete(void *);
int GF_SinDeg(int);
#endif
