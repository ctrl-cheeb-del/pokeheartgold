#ifndef OV70_WAVE38_MENU_PRIVATE_H
#define OV70_WAVE38_MENU_PRIVATE_H
#include "global.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
typedef struct Pair38 {
    s32 a, b;
} Pair38;
extern const Pair38 ov70_02245F5C[], ov70_02245F58[];
extern const s32 ov70_02245E84[], ov70_02245FA0[];
extern const u8 ov70_02245E26[], ov70_02245E27[];
void ov70_02242D44(void *, int, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetDrawFlag(void *, int);
void ov70_02238F9C(void *, int, int);
void sub_020198FC(void *, int, int, int, int);
int ov70_022421D0(void *, void *);
void ov70_02241DB4(void *, int);
void GF_AssertFail(void);
void sub_02019688(void *, int, int, int, int);
void sub_02019B08(void *, int);
void ov70_0224190C(void *, int);
void *NewString_ReadMsgData(void *, int);
void String_Delete(void *);
int ov70_02243F7C(void *, int);
void ov70_02242FC4(void *, void *, void *, int, int);
void ov70_02243EB8(void *, void *, void *, int);
void sub_020196E8(void *, int, int, int);
void sub_020197F4(void *, int);
int ov70_02243F54(void *, int);
void ov70_02243E8C(void *, void *, void *, int, int, int);
int ov70_02242390(void *, void *);
int ov70_0224308C(void *);
int ov70_022430CC(void *);
int ov70_02243120(void *);
int ov70_0224316C(void *);
int ov70_02243254(void *);
int ov70_022433A8(void *);
#endif
