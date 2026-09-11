#ifndef R14_OVERLAY70_PRIVATE_H
#define R14_OVERLAY70_PRIVATE_H

#include "global.h"

typedef struct Ov70Work {
    u8 pad00[0x2c];
    u32 state2c;
    u8 pad30[6];
    u16 value36;
    u8 pad38[4];
    s32 value3c;
    u8 pad40[0xba0 - 0x40];
    void *ptrBA0;
    u8 padBA4[0x1604 - 0xba4];
    u32 timer1604;
} Ov70Work;

void ov70_02238E50(Ov70Work *, int, int);
void ov70_022380EC(Ov70Work *);
int ov70_02237F38(void);
int ov70_02237F58(void);
void ov70_022404D4(Ov70Work *);
void sub_02039AD8(int);
void sub_020399EC(void);
void ov70_02244FA4(Ov70Work *, void *, int, int, int);
void ov70_02238D84(Ov70Work *, int, int);
void ov70_02238F80(Ov70Work *);
void ov70_02241234(Ov70Work *);
int ov70_02240640(Ov70Work *);
int ov70_02240658(Ov70Work *);
int ov70_02240670(Ov70Work *);
int ov70_02240684(Ov70Work *);
int ov70_0224069C(Ov70Work *);
int ov70_022406B8(Ov70Work *);
int ov70_02240748(Ov70Work *);
void ov70_0224078C(Ov70Work *);
int ov70_022407E4(Ov70Work *);
int ov70_0224080C(Ov70Work *);

#endif
