#ifndef OV39_PRIVATE_H
#define OV39_PRIVATE_H

#include "global.h"

typedef struct Ov39Work {
    u8 pad000[0x17C];
    u32 unk17C;
    u8 pad180[0x190 - 0x180];
    u32 unk190;
    u8 pad194[0x3AC - 0x194];
    union {
        u32 w;
        u16 h;
        u8 b;
    } unk3AC;
    u32 unk3B0;
    u8 pad3B4[0x3BC - 0x3B4];
    u32 unk3BC;
    u8 pad3C0[0x3C4 - 0x3C0];
    u32 unk3C4;
    u32 unk3C8;
    u8 pad3CC[0x3E0 - 0x3CC];
    u32 unk3E0;
    u32 unk3E4;
    u32 unk3E8;
    u32 unk3EC;
    u32 unk3F0;
} Ov39Work;

typedef struct Ov39App {
    u8 pad00[0x8];
    u32 unk08;
    u32 unk0C;
    u8 pad10[0x18 - 0x10];
    int unk18;
    int unk1C;
    u8 pad20[0x40 - 0x20];
    u32 unk40;
    u8 pad44[0x88 - 0x44];
    void *unk88;
} Ov39App;

typedef struct Ov39Cb {
    u8 pad00[4];
    void (*fn)(void *, int);
    void *arg;
} Ov39Cb;

typedef struct Ov39Cb2 {
    u8 pad00[8];
    void (*fn)(void *);
    void *arg;
} Ov39Cb2;

typedef struct Ov39Ev {
    u8 pad00[2];
    u16 kind;
} Ov39Ev;

typedef struct Ov39Crc5C {
    u8 pad00[0x5C];
    u16 crc;
} Ov39Crc5C;

typedef struct Ov39Crc198 {
    u8 pad000[0x177];
    u8 unk177;
    u8 pad178[0x198 - 0x178];
    u16 crc;
} Ov39Crc198;

typedef struct Ov39Blk {
    u32 f0;
    u32 f4;
    u32 f8;
} Ov39Blk;

struct Ov39System {
    u8 pad00[0x48];
    u32 heldKeys;
};
extern struct Ov39System gSystem;

/* external references (prototype only; never defined here) */
void ov39_02229224(void *a0, void *a1, void *a2);
Ov39Blk *ov39_0222A2B4(void *a0);
void ov39_0222A130(Ov39Work *work);
void ov39_0222915C(void *a0, void *a1);
void ov39_02227D5C(Ov39Work *work, int a1, int a2);
u32 ov39_02227DE4(Ov39Work *work);
void ov39_02228A34(Ov39App *app, int a1, int a2);
void ov39_022289D0(void *app, int a1);

void ov00_021EC210(void);
void ov00_021EC8D8(void);
void ov00_021ECD04(void *app);
int ov00_021E6A70(int a0, int a1);
void sub_0203946C(void);
void sub_0200F450(void *p);

u16 SaveArray_CalcCRC16(void *saveData, const void *data, u32 size);
void FreeBgTilemapBuffer(void *bgConfig, u32 layer);
void RemoveWindow(void *window);
BOOL TextPrinterCheckActive(u8 printerId);
void *WaitingIcon_New(void *window, u32 a1);

/* functions defined in candidate.c */
void ov39_02227060(void *a0, void *a1, Ov39Crc5C *a2);
void ov39_02227080(void *a0, void *a1, void *a2);
BOOL ov39_02227364(Ov39Work *work);
BOOL ov39_022273F8(Ov39Work *work, u16 a1);
BOOL ov39_0222748C(Ov39Work *work, u8 a1);
BOOL ov39_022276A4(Ov39Work *work);
BOOL ov39_022276E0(Ov39Work *work);
BOOL ov39_02227720(Ov39Work *work, u32 a1, u32 a2);
BOOL ov39_0222774C(Ov39Work *work, u32 a1, u32 a2);
BOOL ov39_02227DB8(Ov39Work *work);
BOOL ov39_02228B74(int a0, int a1);
u32 ov39_02228EA4(Ov39App *app);
void ov39_02227188(void *a0, Ov39Crc198 *a1, u8 a2);
void ov39_022271A4(void *a0, const void *a1, void *a2);
void ov39_022271C0(const void *src, void *dst);
BOOL ov39_02227334(Ov39Work *work);
BOOL ov39_02227348(Ov39Work *work);
BOOL ov39_0222738C(Ov39Cb *cb);
BOOL ov39_022274B4(Ov39Work *work);
BOOL ov39_02227B1C(void);
BOOL ov39_02227B20(void);
BOOL ov39_02227B50(void);
BOOL ov39_02227B54(void);
BOOL ov39_02227B58(void);
u32 ov39_02227D44(Ov39Work *work, u32 **out);
void ov39_02227D50(Ov39Cb *cb, int a1);
void ov39_02227E3C(void);
BOOL ov39_02227E48(void *a0, Ov39Ev *ev);
BOOL ov39_02227E6C(void *a0, Ov39Ev *ev);
BOOL ov39_02227ECC(void *a0, Ov39Ev *ev);
BOOL ov39_02227EF4(void *a0, Ov39Ev *ev);
BOOL ov39_02227F60(void *a0, Ov39Ev *ev);
void ov39_02227F74(void *a0, void **out);
BOOL ov39_02227F84(void *a0, Ov39Ev *ev);
void ov39_02227FA8(void *a0, void **out1, void **out2);
BOOL ov39_02227FC4(void *a0, Ov39Ev *ev);
BOOL ov39_02227FFC(void *a0, Ov39Ev *ev);
BOOL ov39_022280B4(void *a0, Ov39Ev *ev);
BOOL ov39_02228120(void *a0, Ov39Ev *ev);
void ov39_022285A8(void *bgConfig);
void ov39_02228948(Ov39App *app);
BOOL ov39_02228A70(u32 printerId);
void ov39_02228A8C(Ov39App *app);
void ov39_02228AA8(Ov39App *app);
void ov39_02228B6C(Ov39Cb2 *cb, void (*fn)(void *), void *arg);
u32 ov39_02228D90(Ov39App *app);
u32 ov39_0222908C(Ov39App *app);

#endif
