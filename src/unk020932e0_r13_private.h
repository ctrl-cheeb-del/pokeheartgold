#ifndef TO45_UNK_020932E0_RESIDUAL_13_PRIVATE_H
#define TO45_UNK_020932E0_RESIDUAL_13_PRIVATE_H

#include "global.h"

#include "sprite.h"

typedef struct Residual13Work {
    u8 filler_0000[0x0F];
    u8 selection;
    u8 selectionCount;
    u8 filler_0011[2];
    u8 enabled;
    u8 filler_0014[0x8B4 - 0x14];
    Sprite *sprite8B4;
    Sprite *sprite8B8;
    Sprite *sprite8BC;
    Sprite *sprite8C0;
    u8 filler_08C4[0x46B8 - 0x8C4];
    void *cursor;
} Residual13Work;

int sub_02095DD8(void *cursor);
int sub_02095DE8(void *cursor);
void sub_02095D40(void *cursor, int mode, int value);
void sub_020943EC(Residual13Work *work);
void sub_02094A90(Residual13Work *work, int value);
void sub_0209569C(Residual13Work *work);
void PlaySE(u32 seq);
int sub_020954CC(Residual13Work *work);
void sub_02095540(Residual13Work *work);
void sub_020955EC(Residual13Work *work);

#endif
