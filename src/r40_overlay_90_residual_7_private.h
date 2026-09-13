#ifndef OVERLAY_90_RESIDUAL_7_PRIVATE_H
#define OVERLAY_90_RESIDUAL_7_PRIVATE_H

#include "global.h"

typedef struct Ov90StatusData {
    u8 padding00[0x1C];
    u32 ready;
} Ov90StatusData;

typedef struct Ov90Status {
    u8 padding00[8];
    u8 value;
    u8 padding09[3];
    Ov90StatusData *data;
} Ov90Status;

typedef struct Ov90Resource {
    u8 padding00[8];
    void *owner;
    void *narc;
    u8 manager[0x18];
    void *resource;
    void *task;
    void *sprite;
    u8 auxiliary[1];
} Ov90Resource;

BOOL ov90_02258B54(Ov90Status *status);
BOOL ov90_02258B98(Ov90Status *status);
Ov90Resource *ov90_02258BD4(void *owner, u32 heapId);
void ov90_02258C38(Ov90Resource *resource);

extern u8 sub_02037454(Ov90StatusData *data);
extern int sub_02039264(void);
extern int sub_020390C4(void);
extern void GF_AssertFail(void);
extern int sub_02034420(void);
extern void sub_020343E4(void);
extern void sub_0203986C(void);
extern int sub_020392A0(void);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void *NARC_New(u32 narcId, u32 heapId);
extern void ov90_02258DD0(void *manager, u32 value, u32 heapId);
extern void *ov90_02258E54(void *manager, void *narc, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 heapId);
extern void SysTask_Destroy(void *task);
extern void Sprite_Delete(void *sprite);
extern void ov90_0225BD08(void *auxiliary);
extern void ov90_02258E10(void *manager);
extern void NARC_Delete(void *narc);
extern void Heap_Free(void *ptr);

#endif
