#ifndef LOCAL_OV90_R16_H
#define LOCAL_OV90_R16_H
#include "global.h"
extern void Sprite_Delete(void *);
extern BOOL WindowIsInUse(void *);
extern void RemoveWindow(void *);
extern void ov90_02258CF0(void *, int, int, int, int);
extern void ov90_02259FC8(void *, int);
extern int ov90_02258D4C(void *, int);
extern void PlaySE(u16);
extern void Main_SetHBlankIntrCB(void *, void *);
extern void sub_02014A38(void *);
void ov90_02259EE0(void *, int, u16);
void ov90_02259EAC(void *);
void ov90_02259F44(void *, u16);
int ov90_02259F7C(void *);
void ov90_0225A108(void *);
#endif
