#ifndef OVERLAY89_R23_OBJECT_POOL_H
#define OVERLAY89_R23_OBJECT_POOL_H
#include "global.h"

typedef struct Ov89Rect {
    s32 left;
    s32 right;
    s32 bottom;
    s32 top;
} Ov89Rect;

typedef union Ov89Packed {
    u32 raw;
    struct {
        u32 low : 4;
        u32 mid : 4;
        u32 pad08 : 16;
        u32 high : 8;
    } bits;
} Ov89Packed;

typedef struct Ov89Arg {
    u8 pad00[0x18];
    void *object;
    u8 pad1C[0x224];
    Ov89Packed packed;
} Ov89Arg;

typedef struct Ov89Work {
    u8 pad00[0xB0];
    u8 clear[4];
    u8 padB4[0x488];
    u8 entries[128][4];
    u8 active;
    u8 value;
    u8 pad73E;
    u8 level;
} Ov89Work;

typedef struct Ov89Input {
    u16 unk00;
    u16 id;
    u8 pad04[4];
    u8 kind;
} Ov89Input;

extern void ov89_0225A988(u8 *work, void *arg);
extern void ov89_0225AF7C(u8 *work, int id);
extern void ov89_0225AC10(u8 *arg);
extern int ov89_0225C8BC(u16 id, u8 kind);
extern void sub_020182B0(void *ctx, s32 *x, s32 *z, s32 *y);
extern void sub_020182CC(void *ctx, s32 *x, s32 *z, s32 *y);
extern const s32 ov89_0225CD3C[];
extern const s32 ov89_0225CD40[];
extern const s32 ov89_0225CD44[];
extern const s32 ov89_0225CD48[];
extern const s32 ov89_0225CD6C[];
extern const s32 ov89_0225CCE4[];
extern const s16 ov89_0225CCD0[];

void ov89_0225AC24(u8 *, Ov89Arg *, int);
void ov89_0225AC68(void *, int, int, s32 *, s32 *);
int ov89_0225AD00(u8 *);
void ov89_0225AD64(u8 *, int);
BOOL ov89_0225AEA8(const Ov89Rect *, const Ov89Rect *);
void ov89_0225AED0(u8 *, u8 *);
void ov89_0225AF7C(u8 *, int);
#endif
