#ifndef R40_OV43_R8_H
#define R40_OV43_R8_H
#include "global.h"
void Sprite_Delete(void *);
void Sprite_SetDrawFlag(void *, int);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_ResetAnimCtrlState(void *);
void ov43_0222ACDC(u8 *);
void ov43_0222AD00(u8 *, int);
void ov43_0222AD20(u8 *, int);
void ov43_0222AD40(u8 *, u8, int);
#endif
