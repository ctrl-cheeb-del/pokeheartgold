#ifndef TO47_OV102_R7_PRIVATE_H
#define TO47_OV102_R7_PRIVATE_H

#include "global.h"

typedef struct Ov102R7Work {
    u8 pad00[0x14];
    void *ui;
    u8 pad18[0x0c];
    void *handler;
    u8 pad28[8];
    u16 keys;
    u8 pad32[2];
    u16 repeatKeys;
    u8 pad36[2];
    u32 mode;
    u8 pad3c[0x14];
    u16 cursor50;
    u8 pad52[2];
    u16 page54;
    u8 pad56[2];
    u16 count58;
    u8 pad5a[6];
    u16 flag60;
    u16 selected62;
    u8 pad64[7];
    u8 side6b;
} Ov102R7Work;

typedef struct Ov102R7Cursor {
    u16 page;
    u16 maxPage;
    u16 count;
    u8 column;
    u8 row;
    s32 delta;
    u16 edge;
} Ov102R7Cursor;

typedef struct Ov102R7Hitbox {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} Ov102R7Hitbox;

extern u8 gSystem[];
extern const Ov102R7Hitbox ov102_021EC5F4[];
int System_GetTouchNew(void);
int TouchscreenHitbox_FindRectAtTouchNew(const void *);
int TouchscreenHitbox_PointIsIn(const void *, int, int);
void PlaySE(int);
int ov102_021E839C(void *);
int ov102_021E8B18(void *, void *);
int ov102_021E8B40(void *, u16);
int ov102_021E8C3C(void *);
int ov102_021E8C64(void *);
void ov102_021E8CA4(void *);
int ov102_021E9464(void *);
int ov102_021E947C(void *, int);
void ov102_021E940C(void *, int);
void ov102_021E7A4C(void *, void *);
void ov102_021E7AA4(void);
void ov102_021E8240(void);
int ov102_021E87B4(Ov102R7Work *, u32 *);
void ov102_021E8820(Ov102R7Work *, u32 *);
int ov102_021E896C(Ov102R7Work *);
void ov102_021E8A34(Ov102R7Work *, u32 *);

#endif
