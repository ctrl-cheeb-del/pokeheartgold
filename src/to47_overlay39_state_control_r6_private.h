#ifndef OV39_RESIDUAL_6_PRIVATE_H
#define OV39_RESIDUAL_6_PRIVATE_H

#include "global.h"

typedef struct Ov39Work Ov39Work;

typedef void (*Ov39DoneFn)(void *a0, void *a1);
typedef BOOL (*Ov39CompleteFn)(Ov39Work *work, Ov39DoneFn *out);
typedef int (*Ov39StateFn)(Ov39Work *work, void *arg);

typedef struct Ov39Blk {
    u32 f0;
    u32 f4;
    u32 f8;
} Ov39Blk;

struct Ov39Work {
    u8 pad000[0x148];
    u32 unk148;
    u32 unk14C;
    void *unk150;
    u8 pad154[0x17C - 0x154];
    u32 unk17C;
    u32 unk180;
    u32 unk184;
    u32 unk188;
    u8 pad18C[0x190 - 0x18C];
    u32 unk190;
    u8 pad194[0x3AC - 0x194];
    union {
        u32 w;
        u16 h;
        u8 b;
    } unk3AC;
    u32 unk3B0;
    u32 unk3B4;
    u8 pad3B8[0x3BC - 0x3B8];
    u32 unk3BC;
    u32 unk3C0;
    u32 unk3C4;
    u8 pad3C8[0x3CC - 0x3C8];
    Ov39Blk unk3CC;
    u8 pad3D8[0x3E8 - 0x3D8];
    int unk3E8;
    int unk3EC;
    u32 unk3F0;
    u8 pad3F4[0x400 - 0x3F4];
    Ov39DoneFn unk400;
    u8 pad404[0x40C - 0x404];
    Ov39CompleteFn unk40C;
    u8 pad410[0x411 - 0x410];
    u8 unk411;
    u8 pad412[0x420 - 0x412];
};

extern Ov39StateFn *const ov39_0222A8B4[];

void GF_AssertFail(void);

u32 ov39_0222A13C(void);
u32 ov39_0222A158(void);
BOOL ov39_0222A164(void *a0, u32 a1);
BOOL ov39_0222A1C0(u16 a0, u32 a1);
BOOL ov39_0222A200(u8 a0, void *a1, u32 a2);
BOOL ov39_0222A268(u8 a0, u32 a1);
BOOL ov39_0222A2CC(u32 a0);
BOOL ov39_0222A2EC(void *a0, u32 a1);
BOOL ov39_0222A33C(u32 a0, u32 a1);
BOOL ov39_0222A394(void *a0, u32 a1);
BOOL ov39_0222A3DC(void *a0, u32 a1);
BOOL ov39_0222A434(void *a0, u32 a1);
BOOL ov39_0222A48C(u32 a0, u32 a1, u32 a2, u32 a3);
BOOL ov39_0222A4C0(u32 a0, u32 a1, u32 a2);

BOOL ov39_02227B1C(Ov39Work *work, Ov39DoneFn *out);
BOOL ov39_02227B58(Ov39Work *work, Ov39DoneFn *out);
void ov39_02227B5C(Ov39Work *work);

BOOL ov39_02227778(Ov39Work *work);
BOOL ov39_022278D4(Ov39Work *work);
BOOL ov39_02227A5C(Ov39Work *work);

#endif
