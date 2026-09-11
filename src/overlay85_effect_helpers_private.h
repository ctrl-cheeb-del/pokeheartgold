#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
void sub_020699D0(void *,void *,void *,void *);
void sub_020699BC(void *,void *);
void sub_02069784(void *);void sub_02069818(void *);void sub_020698E8(void *,s32,int);
void sub_02069998(void *,void *,void *);
void sub_02069978(void *,void *);void ov85_021E7A54(void *,void *);
void ov85_021E7A20(void *,void *);void ov85_021E7AC8(void *,void *);void ov85_021E8530(void *,void *);
void *Heap_AllocAtEnd(u32,u32);
void *SysTask_CreateOnMainQueue(void (*)(void *,void *),void *,u32);
void Heap_Free(void *);void SysTask_Destroy(void *);void PlaySE(int);void ov85_021E776C(void *,void *);void ov85_021E73D4(void *,void *,void *);void ov85_021E7E88(void *,s32);void ov85_021E7FC0(void *,void *);
extern int (*ov85_021EA51C[])(void *);
void ov85_021E7734(void *);void ov85_021E776C(void *,void *);void ov85_021E78A4(void *,void *);void ov85_021E7B8C(void *,void *);int ov85_021E7BC0(void *);int ov85_021E7BEC(void *);int ov85_021E7C2C(void *);void ov85_021E7C70(void *,void *);
void ov85_021E7A20(void *,void *);
void ov85_021E7AC8(void *,void *);
void ov85_021E7A54(void *,void *);
void ov85_021E7B04(void *,void *);
void *memset(void *,int,u32);
void ov85_021E7B40(void *,s32,s32,s32,s32,s32,void *);
void ov85_021E782C(void *);
#endif
