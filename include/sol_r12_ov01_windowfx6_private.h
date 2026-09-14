#ifndef TO45_R12_OV01_EFFECT_PRIVATE_H
#define TO45_R12_OV01_EFFECT_PRIVATE_H

#include <string.h>

#include "global.h"

typedef struct SysTask SysTask;
typedef struct Ov01WindowEffect {
    s32 value;
    u8 pad04[0x14];
    u32 divisor;
    u32 state;
    u8 pad20[4];
    void *hblankTask;
    SysTask *task;
    u32 *done;
    u8 pad30[0x18];
} Ov01WindowEffect;

void *Heap_Alloc(u32, u32);
void SysTask_Destroy(SysTask *);
BOOL ov01_021EFF28(Ov01WindowEffect *);
void ov01_021FB554(void *);
void ov01_021F010C(SysTask *, Ov01WindowEffect *);
void ov01_021F0174(Ov01WindowEffect *);
void ov01_021F01D0(SysTask *, Ov01WindowEffect *);
Ov01WindowEffect *ov01_021F0250(void);

#endif
