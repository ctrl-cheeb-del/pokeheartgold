#ifndef OV92_RESIDUAL14_PRIVATE_H
#define OV92_RESIDUAL14_PRIVATE_H
#include "global.h"

#include "heap.h"
#include "sys_task_api.h"
#include "system.h"
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTRTac(p, o) ((void *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct Ov92Work14 {
    u8 pad0000[0x2ae4];
    s32 progress;
    u32 mode;
    u32 index;
    u32 accumulator;
    u8 pad2af4[0x2afe - 0x2af4];
    s16 count;
    u8 pad2b00[0x2b18 - 0x2b00];
    s32 value;
} Ov92Work14;
extern const u16 ov92_02263C34[];
void ov92_0225F254(SysTask *, void *);
void ov92_0225F338(SysTask *, void *);
void ov92_0225F530(SysTask *, void *);
void ov92_0225EF4C(SysTask *, void *);
void ov92_0225DD48(void *, int);
void sub_02018198(void *, int);
int ov92_0225F968(Ov92Work14 *, int, u32 *);
void ov92_0225FAB8(void *);
void ov92_0225F9C4(void *);
int ov92_0225F8EC(Ov92Work14 *);
void ov92_0225EE60(void *, int);
void ov92_0225F8B0(Ov92Work14 *);
void ov92_0225FEE4(void *);
void PlaySE(u32);

void ov92_0225EDB4(void *, int);
void ov92_0225EE04(void *, int);
void ov92_0225EEBC(void *);
void ov92_0225F878(Ov92Work14 *);
void ov92_0225FC2C(Ov92Work14 *);
#endif
