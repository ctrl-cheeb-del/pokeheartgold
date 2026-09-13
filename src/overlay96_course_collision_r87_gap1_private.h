#ifndef OVERLAY96_R87_GAP1_PRIVATE_H
#define OVERLAY96_R87_GAP1_PRIVATE_H

#include "global.h"

extern void ov96_021EB588();
extern void ov96_021EB52C();
extern void ov96_021EB564();
extern void ov96_021EAB38();
extern int ov96_02208448();
extern int ov96_02208608();
extern u8 *ov96_021E60D8();
extern void ov96_022076C0();

typedef struct Ov96Vec3 {
    int x;
    int y;
    int z;
} Ov96Vec3;

void ov96_02206A24(u8 *, int, int);
void ov96_02206AC0(u8 *, int, int);
void ov96_02206B80(u8 *, u8 *, int, int);
void ov96_02206C90(void *, u8 *, int, int, u8 *, int, int);
void ov96_02206D58(u8 *, int, int, u8 *, int);
void ov96_02206DEC(void *, u8 *, void *, int, u8, u8 *, int, int, int);
void ov96_02206E88(void *, u8 *, int, int, u8 *);

#endif
