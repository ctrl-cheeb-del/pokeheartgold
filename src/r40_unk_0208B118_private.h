#ifndef SOL_R40_UNK_0208B118_PRIVATE_H
#define SOL_R40_UNK_0208B118_PRIVATE_H

#include "global.h"

typedef struct SummaryWorkB118 {
    void *bgConfig;
    u8 pad004[0x7CC];
    void *anim7D0;
} SummaryWorkB118;

int sub_0208A2E0(void *work, int direction);
void sub_020196E8(void *anim, int sequence, int x, int y);
void FillBgTilemapRect(void *bgConfig, int bgId, u32 fill, u8 x, u8 y, u8 width, u8 height, u8 palette);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, u8 bgId);
void sub_0208B118(SummaryWorkB118 *work);

#endif
