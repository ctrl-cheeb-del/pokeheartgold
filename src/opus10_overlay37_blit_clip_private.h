#ifndef OVERLAY_37_RESIDUAL_7_PRIVATE_H
#define OVERLAY_37_RESIDUAL_7_PRIVATE_H

#include "global.h"

typedef struct Ov37Window {
    u8 dummy[0x10];
} Ov37Window;

typedef struct Ov37SpriteHolder {
    u8 unk_00[0x20];
    void *unk_20;
} Ov37SpriteHolder;

typedef struct Ov37Pair {
    u32 cur;
    u32 prev;
} Ov37Pair;

typedef struct Ov37Entry {
    u8 xs[4];        /* 0x00 */
    u8 ys[4];        /* 0x04 */
    u8 unk_08_0 : 3; /* 0x08 bits 0-2 */
    u8 count : 3;    /* 0x08 bits 3-5 */
    u8 unk_08_6 : 2; /* 0x08 bits 6-7 */
    u8 unk_09;       /* 0x09 */
} Ov37Entry;

typedef struct Ov37Point {
    u8 x;      /* 0x00 */
    u8 y;      /* 0x01 */
    u16 count; /* 0x02 */
} Ov37Point;

typedef struct Ov37Tile {
    u8 data[0x18];
} Ov37Tile;

typedef struct Ov37Work {
    void *bgConfig; /* 0x0000 */
    u8 unk_0004[0x000C - 0x0004];
    void *msgFormat; /* 0x000C */
    u8 unk_0010[0x0014 - 0x0010];
    void *strbuf[5]; /* 0x0014 */
    void *unk_0028;  /* 0x0028 */
    void *unk_002C;  /* 0x002C */
    u32 printerId;   /* 0x0030 */
    u8 unk_0034[0x01D8 - 0x0034];
    void *sprites[5]; /* 0x01D8 */
    u8 unk_01EC[0x0248 - 0x01EC];
    Ov37SpriteHolder holder; /* 0x0248 */
    u8 unk_026C[0x0278 - 0x026C];
    Ov37Window windows[5]; /* 0x0278 */
    Ov37Window winB2;      /* 0x02C8 */
    Ov37Window winB6;      /* 0x02D8 */
    Ov37Window winBA;      /* 0x02E8 */
    u8 unk_02F8[0x0304 - 0x02F8];
    u32 prevState; /* 0x0304 */
    u32 state;     /* 0x0308 */
    u8 unk_030C[0x0310 - 0x030C];
    u32 counter; /* 0x0310 */
    u8 unk_0314[0x0320 - 0x0314];
    u32 unk_0320; /* 0x0320 */
    u8 unk_0324[0x0334 - 0x0324];
    Ov37Pair pair[5]; /* 0x0334 */
    u8 unk_035C[0x4380 - 0x035C];
    u8 flags;                     /* 0x4380 */
    u8 unk_4381;                  /* 0x4381 */
    Ov37Entry entries[5];         /* 0x4382 */
    u8 unk_43B4[0x43C8 - 0x43B4]; /* 0x43B4 */
    void *unk_43C8;               /* 0x43C8 */
    u8 unk_43CC[0x93B0 - 0x43CC];
    u32 unk_93B0; /* 0x93B0 */
    u32 unk_93B4; /* 0x93B4 */
    u8 unk_93B8[0x93BA - 0x93B8];
    u16 unk_93BA; /* 0x93BA */
    u8 unk_93BC;  /* 0x93BC */
    u8 unk_93BD[0x93F0 - 0x93BD];
    void *yesNoPrompt; /* 0x93F0 */
    u32 unk_93F4;      /* 0x93F4 */
    u32 yesNoActive;   /* 0x93F8 */
    u8 unk_93FC[0x9404 - 0x93FC];
    u32 unk_9404; /* 0x9404 */
    u8 unk_9408[0x940C - 0x9408];
} Ov37Work;

/* module-local rodata blob, left in the assembly */
extern const Ov37Tile ov37_021E7AC8[][8];

/* external game functions */
void CopyWindowToVram(Ov37Window *window);
void BlitBitmapRectToWindow(Ov37Window *window, const void *src, u16 srcX, u16 srcY, u16 srcWidth, u16 srcHeight, u16 destX, u16 destY, u16 destWidth, u16 destHeight);
void Sprite_SetDrawFlag(void *sprite, u32 flag);
u32 sub_02034818(u32 index);
u32 sub_0203769C(void);
u32 sub_02037454(void);
void BufferPlayersName(void *msgFormat, u32 idx, u32 arg2);
s32 GF_SinDeg(u16 deg);
void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);

/* module functions */
void ov37_021E657C(void *sprite, u32 x, u32 y);
void ov37_021E6848(Ov37SpriteHolder *holder, u32 arg1);
void ov37_021E68AC(Ov37Work *work);
void ov37_021E76C0(Ov37Work *work);
void ov37_021E76D0(Ov37Work *work, u32 arg1);
void ov37_021E7844(Ov37Work *work, u32 state);
void ov37_021E78A4(Ov37Work *work);

u32 ov37_021E6F5C(Ov37Work *work, u32 arg1);
void ov37_021E6FC8(Ov37Work *work, int arg1, u32 arg2);
void ov37_021E70BC(Ov37Window *window, const void *src, s32 srcX, s32 srcY, s32 srcWidth, s32 srcHeight, s32 destX, s32 destY, s32 destWidth, s32 destHeight);
void ov37_021E713C(Ov37Window *window, const void *src, s32 x1, s32 y1, s32 *px, s32 *py, s32 arg6, s32 arg7);
void ov37_021E72B4(const Ov37Entry *entries, Ov37Point *points);
void ov37_021E72E8(Ov37Window *window, Ov37Entry *entries, Ov37Point *points, u32 arg3);
void ov37_021E73B4(Ov37Work *work);
void ov37_021E741C(u16 *deg);

#endif
