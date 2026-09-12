#ifndef OVERLAY96_COURSE_COLLISION_R87_PRIVATE_H
#define OVERLAY96_COURSE_COLLISION_R87_PRIVATE_H

#include "global.h"

extern void ov96_021EB588();
extern void ov96_021EB52C();
extern fx32 VEC_Mag();
extern fx32 VEC_DotProduct();
extern void VEC_Subtract();
extern fx32 FX_Sqrt();
extern fx32 FX_Div();
extern void ov96_021EAB38();
extern int ov96_02208448();
extern int ov96_02208608();
extern u8 *ov96_021E60D8();

typedef struct Ov96Vec2 {
    int x;
    int y;
} Ov96Vec2;

typedef struct Ov96Vec3 {
    int x;
    int y;
    int z;
} Ov96Vec3;

void ov96_02206A24(u8 *, int, int);
void ov96_02206AC0(u8 *, int, int);
void ov96_02206F1C(u8 *, fx32, fx32, void **, u8 *);
void ov96_02206FA4(int, const u16 *, int *);
void ov96_02206C90(void *, u8 *, int, int, u8 *, int, int);
void ov96_02206D58(u8 *, int, int, u8 *, int);
void ov96_02206E88(void *, u8 *, int, int, u8 *);
fx32 ov96_02207390(const Ov96Vec3 *, const Ov96Vec3 *, const Ov96Vec3 *, fx32);
float ov96_022073F0(u8 *, int);

#endif // OVERLAY96_COURSE_COLLISION_R87_PRIVATE_H
