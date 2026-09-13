#ifndef OVERLAY96_POKEATHLON_COURSE_MOTION_R79_PRIVATE_H
#define OVERLAY96_POKEATHLON_COURSE_MOTION_R79_PRIVATE_H

#include "global.h"

extern void ov96_021EAB38(void *sprite, int value);
extern void ov96_021EB52C(void *sprite, int a, int b);
extern void ov96_021EB564(void *sprite, int value);
extern void ov96_021EB588(void *sprite, const void *position);
extern void *ov96_021EB594(void *sprite);
extern void ov96_021FFE38(int position, int sound, int enabled);
extern BOOL ov96_022006BC(void *course, int participant);
extern BOOL ov96_02200900(void *course, u32 mode);

void ov96_021FEAEC(u8 *work, int value);
void ov96_021FEBF0(void *course, u8 *work, VecFx32 *position, int mode, u8 participant, u8 *result, BOOL checkA, BOOL checkB);
void ov96_021FED3C(u8 *work, VecFx32 *position, int unused, u8 participant, u8 *result, BOOL flag, BOOL sound);

#endif
