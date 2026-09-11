#ifndef SOL40_R29_PRIVATE_H
#define SOL40_R29_PRIVATE_H
#include "global.h"
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define S8(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define U16(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define S16(p,o) (*(s16 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
void ov70_02241DB4(void *,int); void ListMenuItems_Delete(void *); void GF_AssertFail(void);
void Sprite_SetDrawFlag(void *,int); void Sprite_SetAnimCtrlSeq(void *,int); void ov70_02242E58(void *); void ov70_02242EE4(void *); void ov70_02238F9C(void *,int,int);
int ov70_02242C64(void *); int ov70_022426F4(void *); int ov70_022428C0(void *); void sub_020198FC(void *,int,int,int,int);
void *NewString_ReadMsgData(void *,int); void String_Delete(void *); void ov70_02242FC4(void *,void *,void *,int,int); void CopyWindowPixelsToVram_TextMode(void *); void sub_02019A60(void *,int,void *);
void AddTextPrinterParameterizedWithColor(void *,int,void *,int,int,int,int,int); void PrintUIntOnWindow(void *,int,int,int,void *,int,int); void sub_0200CDAC(void *,int,void *,int,int); void *ov70_0223F658(int,int,u32 *); int ov70_0224342C(void *,void *,u32,void *); void Heap_Free(void *);
int ov70_0223F8D0(u32,u32 *);
extern const u8 ov70_02245D66[],ov70_02245D67[],ov70_02245D80[],ov70_02245D81[];
typedef struct Ov70Pair29 { s32 a,b; } Ov70Pair29; extern const s32 ov70_02245E84[]; extern const Ov70Pair29 ov70_02245F5C[]; extern void (*ov70_02246780[])(void *); extern const Ov70Pair29 ov70_02245F58[]; typedef struct Far29 { u8 pad[0x12d0]; void *task; u32 value; } Far29;

int ov70_02243C08(void *); int ov70_02243C8C(void *); int ov70_02243CC8(void *); int ov70_02243CEC(void *); int ov70_02243D28(void *); int ov70_02243D90(void *); int ov70_02243DA0(void *); int ov70_02243DDC(void *); int ov70_02243E74(void *); void ov70_02243E8C(void *,void *,void *,int,int,int); void ov70_02243EB8(void *,void *,void *,int); void ov70_02243F00(void *,void *,void *,int,int); int ov70_02243F54(void *,int); int ov70_02243F7C(void *,int); int ov70_02243FD4(void *,u32); void ov70_02238E44(void *); void sub_0203A930(void); void ov70_02244124(void *); void SysTask_Destroy(void *); void ov70_022446A8(void *); void ov70_02244644(void *); void ov70_02244290(void *); void ov70_02238E58(void *); int ov70_02244154(void *); int ov70_02243FE0(void *,int);
#endif
