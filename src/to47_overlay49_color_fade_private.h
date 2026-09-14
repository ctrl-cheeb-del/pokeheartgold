#ifndef TO47_OVERLAY49_COLOR_FADE_PRIVATE_H
#define TO47_OVERLAY49_COLOR_FADE_PRIVATE_H

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

#pragma require_prototypes off

typedef struct Ov49Fade {
    u8 a[2][4];
    u8 b[4][4];
    u8 aFrom[2][4];
    u8 bFrom[4][4];
    u8 aTo[2][4];
    u8 bTo[4][4];
    s32 aTimer[2];
    s32 bTimer[4];
} Ov49Fade;

typedef struct Ov49FadeEntry {
    u16 c[5];
} Ov49FadeEntry;

extern const u16 ov49_0226A7D8[];
extern const Ov49FadeEntry ov49_0226A7E0[];

void ov49_02268640(void *, const u16 *);
void ov49_02268664(void *, void *, void *, int, int);
void ov49_022686F0(void *);

void ov49_022684FC(Ov49Fade *);
void ov49_02268588(Ov49Fade *, int);
void ov49_022685F8(void *, int);

#endif
