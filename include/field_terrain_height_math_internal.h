#ifndef PRIVATE_OVERLAY_01_021FAD1C_H
#define PRIVATE_OVERLAY_01_021FAD1C_H

#include "global.h"

// 8-byte triangle record. Offsets confirmed by ov01_021FAD6C (u16 @0, @2),
// ov01_021FAD9C (u16 @4) and ov01_021FADBC (u16 @6); stride 8 from `lsl rN, idx, #3`.
typedef struct Ov01Tri {
    u16 vtxA;
    u16 vtxB;
    u16 normal;
    u16 plane;
} Ov01Tri;

// 8-byte 2D point (x,z). Stride 8 from ov01_021FAD6C `lsl r4, r1, #3`.
typedef struct Ov01Vec2 {
    fx32 x;
    fx32 z;
} Ov01Vec2;

// 8-byte sorted bucket: key @0 (signed compare in ov01_021FADEC), count @4, offset @6.
typedef struct Ov01Bucket {
    fx32 key;
    u16 count;
    u16 offset;
} Ov01Bucket;

// 12-byte hit record; ov01_021FADD4 writes {0,-1,-1} over 10 of them.
typedef struct Ov01Hit {
    fx32 y;
    s32 unk4;
    s32 unk8;
} Ov01Hit;

typedef struct Ov01Thm {
    Ov01Tri *tris;       // 0x00
    fx32 *dists;         // 0x04
    Ov01Bucket *buckets; // 0x08
    u16 *indices;        // 0x0c
    Ov01Vec2 *verts;     // 0x10
    VecFx32 *normals;    // 0x14
    u32 unk18;           // 0x18
    u32 numBuckets;      // 0x1c (ldr + lsl#16/lsr#16 => u32 field, (u16) cast at use)
} Ov01Thm;

fx32 sub_02020B8C(fx32 a, fx32 b); // min
fx32 sub_02020B94(fx32 a, fx32 b); // max

#endif
