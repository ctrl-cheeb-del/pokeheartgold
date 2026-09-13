/*
 * overlay96_course_particle_r107_gap2.c
 *
 * asm/overlay_96_residual_107_gap_2.s, functions 0x0221090C .. 0x02210C48.
 * ov96_02210C98 (0x9B8 bytes, 6-case state machine) remains in assembly.
 */
#include "global.h"

#include "assert.h"
#include "math_util.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define BIT(x, n) ((u32)(x) << (31 - (n)) >> 31)
#define ABS(a)    ((a) < 0 ? -(a) : (a))

typedef struct Ov96ParticleUpdateR107 {
    void *owner;
    s16 unk04;
    s16 x;
    s16 y;
    u16 padding_0A;
    u32 active : 1;
    u32 target : 2;
    u32 group : 2;
    u32 lane : 2;
    u32 state : 4;
    u32 delay : 8;
    u32 unused : 13;
    u8 timer;
    u8 padding_11[3];
} Ov96ParticleUpdateR107;

extern const u8 ov96_0221D1B0[];
extern const u8 ov96_0221D1B1[];
extern const int ov96_0221D1B8[];
extern const s16 ov96_0221D1C4[][3][2];

extern void *PokeathlonCourse_GetHeapAllocPtr4(void *course);

s16 ov96_0220E6DC(s16 a0, int a1);
u32 ov96_0220E70C(void *w, u8 i, u8 j);
void *ov96_0220E74C(void *w, u8 i);
void ov96_0220E770(void *w, u8 i, u8 j, s16 *out, void **out2);
u8 ov96_0220E7BC(void *course, u8 idx);
void ov96_0220E818(void *w, s16 *a1, u8 i, u8 j);
u32 ov96_0220E834(void *w, u8 i, u8 j);

void ov96_0221090C(Ov96ParticleUpdateR107 *p);
void ov96_02210980(Ov96ParticleUpdateR107 *p, void *owner, u8 index);
void ov96_022109D8(Ov96ParticleUpdateR107 *p);
void ov96_02210AE0(Ov96ParticleUpdateR107 *p, u16 average, u16 value);
BOOL ov96_02210BD0(Ov96ParticleUpdateR107 *p, int idx, int radius);
BOOL ov96_02210C48(s16 x0, s16 y0, int r0, s16 x1, s16 y1, int r1);

void ov96_0221090C(Ov96ParticleUpdateR107 *p) {
    int i = p->lane * 2;

    p->x = ov96_0221D1B0[i] + MTRandom() % ov96_0221D1B1[i];
    p->x = p->x * 8;
    p->y = ov96_0221D1C4[p->group][p->lane][0];
    p->y = p->y + (MTRandom() % 5 - 2) * 8;
    p->active = 0;
    p->state = 0;
}

void ov96_02210980(Ov96ParticleUpdateR107 *p, void *owner, u8 index) {
    u8 a = index / 3;
    u8 b = index % 3;

    p->owner = owner;
    p->group = a;
    p->lane = b;
    p->delay = a * 2 + b * 8;
    p->timer = a * 2 + b * 8;
    ov96_0221090C(p);
}

void ov96_022109D8(Ov96ParticleUpdateR107 *p) {
    void *w = PokeathlonCourse_GetHeapAllocPtr4(p->owner);
    void *e;
    int i;

    ov96_0220E7BC(p->owner, p->group);
    switch (p->state) {
    case 0:
        GF_ASSERT(p->active == 0);
        p->unk04 = p->y;
        for (i = 0; i < 2; i++) {
            if (BIT(U32(ov96_0220E74C(w, i), 4), 5)) {
                if (ov96_02210BD0(p, i, 0x38)) {
                    p->target = i;
                    p->active = 1;
                    p->state = 1;
                }
            }
        }
        break;
    case 1:
        GF_ASSERT(p->active == 1);
        if (p->active) {
            e = ov96_0220E74C(w, p->target);
            if (BIT(U32(e, 4), 5)) {
                p->unk04 = ov96_0220E6DC(p->x + 0x120, U8(e, 9));
            } else {
                p->active = 0;
                p->state = 0;
            }
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    ov96_0220E818(w, &p->unk04, p->group, p->lane);
}

void ov96_02210AE0(Ov96ParticleUpdateR107 *p, u16 average, u16 value) {
    s16 pos[2];
    void *val;
    void *w = PokeathlonCourse_GetHeapAllocPtr4(p->owner);
    int rnd;
    int threshold;

    if (ov96_0220E70C(w, p->group, p->lane) == 0) {
        return;
    }
    p->timer--;
    if (p->timer == 0) {
        ov96_0221090C(p);
        p->timer = 90;
    }
    p->delay--;
    if (p->delay == 0) {
        ov96_022109D8(p);
        p->delay = 20;
    }
    if (p->active == 0) {
        return;
    }
    if (!ov96_02210BD0(p, p->target, 0x10)) {
        return;
    }
    rnd = MTRandom() % 100;
    ov96_0220E770(w, p->group, p->lane, pos, &val);
    if (average + 20 < value) {
        threshold = 0;
    } else {
        threshold = ov96_0221D1B8[p->lane];
    }
    if (rnd < threshold) {
        ov96_0220E834(w, p->group, p->lane);
    }
}

BOOL ov96_02210BD0(Ov96ParticleUpdateR107 *p, int idx, int radius) {
    s16 pos[2];
    void *val;
    void *w = PokeathlonCourse_GetHeapAllocPtr4(p->owner);
    void *e = ov96_0220E74C(w, idx);

    if (S16(e, 2) < 0x120) {
        return FALSE;
    }
    ov96_0220E770(w, p->group, p->lane, pos, &val);
    return ov96_02210C48(pos[0], pos[1], (int)val, S16(e, 0), S16(e, 2) - 0x120, radius);
}

BOOL ov96_02210C48(s16 x0, s16 y0, int r0, s16 x1, s16 y1, int r1) {
    if ((r0 + r1) * (r0 + r1) >= ABS(x0 - x1) * ABS(x0 - x1) + ABS(y0 - y1) * ABS(y0 - y1)) {
        return TRUE;
    }
    return FALSE;
}
