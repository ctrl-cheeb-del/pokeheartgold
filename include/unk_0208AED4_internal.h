#ifndef TO40_UNK_0208AED4_PRIVATE_H
#define TO40_UNK_0208AED4_PRIVATE_H
#include "global.h"

typedef struct SummaryInner8AED4 {
    u8 pad00[0x12];
    u8 mode;
    u8 pad13[5];
    u16 unk18;
} SummaryInner8AED4;

typedef struct SummaryInputConfig8AED4 {
    u8 pad[0x7C8];
    u8 a2;
    u8 a3;
    u8 a4;
    u8 a5;
    u8 a6 : 4;
    u8 a7 : 4;
    u8 a1;
    u8 zero;
    u8 a8;
} SummaryInputConfig8AED4;

typedef struct SummaryWork8AED4 {
    void *bgConfig; // 0x000
    u8 pad004[0x228];
    SummaryInner8AED4 *inner; // 0x22c
    u8 pad230[0x1f8];
    void *sprite428; // 0x428
    void *sprite42c; // 0x42c
    u8 pad430[0x18];
    void *sprite448; // 0x448
    u8 pad44c[0x384];
    void *anim7d0; // 0x7d0
} SummaryWork8AED4;

void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetDrawFlag(void *, BOOL);
void sub_0208BCB4(void *);
void sub_020196E8(void *, int, int, int);
void sub_0208DC68(void *, int);
void sub_0208DD20(void *, int);
void FillBgTilemapRect(void *, int, u16, int, int, int, int, int);
void ScheduleBgTilemapBufferTransfer(void *, int);

int sub_0208AED4(SummaryWork8AED4 *);
void sub_0208AF08(SummaryWork8AED4 *, int);
void sub_0208AF70(SummaryWork8AED4 *);
void sub_0208AFA0(SummaryWork8AED4 *, int);
void sub_0208AFE8(void *, u8, u8, u8, u8, u8, u8, u8, u8);
#endif
