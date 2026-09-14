#ifndef OV70_R40_PRIVATE_H
#define OV70_R40_PRIVATE_H

#include "global.h"

#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const s32 ov70_02245E84[];
extern const u8 ov70_02245D8A[];
extern const u8 ov70_02245D8B[];

void sub_02019688(void *, int, int, int, int);
void sub_02019B08(void *, int);
void sub_020196E8(void *, int, int, int);
void sub_020198FC(void *, int, int, int, int);
void ov70_0224190C(void *, int);
int ov70_0223F904(void **, void *, int);
void ov70_0224352C(void *, int, int);
int ov70_02242508(int, int);
void ov70_02243F00(void *, void *, void *, int, int);
void ov70_02243EB8(void *, void *, void *, int);
void ov70_02238F9C(void *, int, int);
void Sprite_SetDrawFlag(void *, int);
int ov70_02242C64(void *);

int ov70_02243B2C(void *);
int ov70_02243C08(void *);

#endif
