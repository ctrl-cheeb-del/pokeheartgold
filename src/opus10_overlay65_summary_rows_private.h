#ifndef TO40_R10_OVERLAY65_RESIDUAL_9_H
#define TO40_R10_OVERLAY65_RESIDUAL_9_H

#include "global.h"

#include "message_format.h"
#include "msgdata.h"
#include "touchscreen_list_menu.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
typedef struct Ov65Row {
    u8 dummy[0x10];
} Ov65Row;

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const TouchscreenListMenuTemplate ov65_0221FD3C;
extern s32 ov65_0221FF4C[];
extern s32 ov65_0221FF50[];

extern int sub_02037454(void);
extern void sub_02037AC0(u32);
extern void *Save_Bag_Get(void *);
extern BOOL Bag_HasItem(void *, u16, u16, int);
extern void *sub_02034818(u32);
extern void *sub_0202C6F4(void *);
extern BOOL sub_0202C2DC(void *, int);
extern void sub_0203A280(void *, u32, int, int, int);
extern BOOL sub_0203A1C4(void *, void *, int);
extern void MI_CpuFill8(void *, u8, u32);
extern void *Party_GetMonByIndex(void *, u32);
extern void *Mon_GetBoxMon(void *);
extern void Sprite_SetDrawFlag(void *, u32);

extern void ov65_0221FB90(void *, u32, u32, u32, void *);
extern void ov65_0221E330(void *, u32);
extern void ov65_0221DE24(void *, u32, u32);
extern void ov65_0221F4B0(void *);
extern void ov65_0221F890(void);
extern void ov65_0221ED80(void *, s32, s32, s32, s32);
extern int ov65_0221E72C(void);
extern int ov65_0221E684(void *);
extern int ov65_0221E270(void *);
extern int ov65_0221E050(void *);
extern int ov65_0221EE18(void *);

int ov65_0221E740(void *);
int ov65_0221E858(void *);
int ov65_0221E8EC(void *);
void *ov65_0221E928(void *, u32, u32);
int ov65_0221E9A8(void *);
int ov65_0221EA74(void *);
int ov65_0221EB9C(void *);
int ov65_0221EBF8(void *);
void ov65_0221EC34(void *);

#endif
