#ifndef TO42_OV15_RESIDUAL7_PRIVATE_H
#define TO42_OV15_RESIDUAL7_PRIVATE_H

#include "global.h"

#include "sys_vars.h"
#include "system.h"

typedef struct BagPocketEntryRaw {
    void *items;
    u16 unk_04;
    s16 cursor;
    u8 count;
    u8 unk_09;
    s16 scroll;
} BagPocketEntryRaw;

typedef struct BagItemSlotRaw {
    u16 item;
    u16 quantity;
} BagItemSlotRaw;

typedef struct BagContextRaw {
    u8 pad_000[4];
    BagPocketEntryRaw pockets[8];
    u8 pocket;
    u8 state;
    u16 item;
    u16 quantity;
} BagContextRaw;

typedef struct BagWorkRaw {
    u8 raw[0x900];
} BagWorkRaw;

#define PTR(type, p, o) (*(type **)((u8 *)(p) + (o)))
#define S32(p, o)       (*(s32 *)((u8 *)(p) + (o)))
#define S16(p, o)       (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o)       (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)        (*(u8 *)((u8 *)(p) + (o)))

extern const u8 ov15_02200640[];
extern const u8 ov15_02200641[];
extern const u8 ov15_02200642[];
extern const u8 ov15_02200643[];
extern const u8 ov15_022008B0[];
extern s32 _02201300;
extern s32 _02201480;

void PlaySE(u16);
BOOL System_GetTouchHeld(void);
void ov15_021FECA0(BagWorkRaw *, void *, u32);
void ov15_021FECC4(BagWorkRaw *, void *);
void ov15_021FECD8(BagWorkRaw *, void *, u32);
void ov15_021FD574(BagWorkRaw *, s32, s32, s32);
void ov15_021FF4EC(BagWorkRaw *, s32, s32);
void ov15_022002B4(BagWorkRaw *, s32);
void ov15_021FB14C(BagWorkRaw *);
void ov15_021FAD80(BagWorkRaw *, BagPocketEntryRaw *);
void ov15_021FFF34(BagWorkRaw *, void *);
s32 ov15_021FA074(BagWorkRaw *);
void ov15_021FF364(BagWorkRaw *, s32, s32, s32);
void ov15_021FF6BC(BagWorkRaw *, s32, s32, s32);
void ov15_02200140(BagWorkRaw *, BagPocketEntryRaw *, s32, s32);
s32 ov15_021FA12C(BagWorkRaw *);
void ov15_021FA170(BagWorkRaw *);
s32 ov15_021FA68C(BagWorkRaw *, s32);
s32 ov15_021FA6C0(BagWorkRaw *, s32, s32);
void ov15_021FA6F4(BagWorkRaw *, BagPocketEntryRaw *);
void ov15_021FA620(BagWorkRaw *);
s32 ov15_021FA650(BagWorkRaw *);
s32 ov15_021FA4F8(BagWorkRaw *);
s32 ov15_021FA578(BagWorkRaw *, s32);

#endif
