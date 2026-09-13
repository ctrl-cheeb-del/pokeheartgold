#include "overlay96_course_collision_r87_gap1_private.h"

void ov96_02206E88(void *a0, u8 *a1, int a2, int a3, u8 *a4);

void ov96_02206A24(u8 *p, int x, int y) {
    u8 i;

    for (i = 0; i < 20; i++) {
        int dx;
        int dy;
        u8 *q = p + i * 12;
        Ov96Vec3 vec;
        if (*(void **)(q + 0x37C) == NULL) {
            break;
        }
        dx = *(u16 *)(q + 0x384) - x + 0x80;
        dy = *(u16 *)(q + 0x386) - y + 0x60;
        vec.z = 0;
        vec.x = dx * FX32_ONE;
        vec.y = dy * FX32_ONE;
        ov96_021EB588(*(void **)(q + 0x380), &vec);
        if (dx >= -32 && dx <= 288 && dy >= -32 && dy <= 224) {
            ov96_021EB52C(*(void **)(q + 0x380), 1, 1);
        } else {
            ov96_021EB52C(*(void **)(q + 0x380), 1, 0);
        }
    }
}

void ov96_02206AC0(u8 *p, int x, int y) {
    u8 i;

    for (i = 0; i < 10; i++) {
        int dx;
        int dy;
        u8 *q = p + i * 16;
        Ov96Vec3 vec;
        if (*(void **)(q + 0x46C) == NULL) {
            break;
        }
        dx = *(u16 *)(q + 0x478) - x + 0x80;
        dy = *(u16 *)(q + 0x47A) - y + 0x60;
        vec.z = 0;
        vec.x = dx * FX32_ONE;
        vec.y = dy * FX32_ONE;
        ov96_021EB588(*(void **)(q + 0x470), &vec);
        ov96_021EB588(*(void **)(q + 0x474), &vec);
        if (dx >= -32 && dx <= 288 && dy >= -32 && dy <= 224) {
            ov96_021EB52C(*(void **)(q + 0x470), 1, 1);
            ov96_021EB52C(*(void **)(q + 0x474), 1, 1);
        } else {
            ov96_021EB52C(*(void **)(q + 0x470), 1, 0);
            ov96_021EB52C(*(void **)(q + 0x474), 1, 0);
        }
    }
}

void ov96_02206B80(u8 *work, u8 *v, int x, int y) {
    u8 i;
    u8 *base;

    for (i = 0, base = work + 0x564; i < 5; i++) {
        int idx;
        int dx;
        int dy;
        Ov96Vec3 vec;
        idx = *(u16 *)(v + i * 2 + 0x18) & 0x1F;
        dx = *(u16 *)(work + idx * 4 + 0x5C8) - x + 0x80;
        dy = *(u16 *)(work + idx * 4 + 0x5CA) - y + 0x60;
        vec.z = 0;
        vec.x = dx * FX32_ONE;
        vec.y = dy * FX32_ONE;
        ov96_021EB588(*(void **)(work + i * 20 + 0x568), &vec);
        ov96_021EB588(*(void **)(work + i * 20 + 0x56C), &vec);
        if (dx >= -32 && dx <= 288 && dy >= -32 && dy <= 224) {
            ov96_021EB52C(*(void **)(work + i * 20 + 0x568), 1, 1);
            ov96_021EB52C(*(void **)(work + i * 20 + 0x56C), 1, 1);
        } else {
            ov96_021EB52C(*(void **)(work + i * 20 + 0x568), 1, 0);
            ov96_021EB52C(*(void **)(work + i * 20 + 0x56C), 1, 0);
        }
        if (idx != work[i + 0x513]) {
            ov96_021EB564(*(void **)(work + i * 20 + 0x56C), 4);
            work[i + 0x513] = idx;
        }
        ov96_022076C0(base + i * 20, dy);
    }
}

void ov96_02206C90(void *a0, u8 *work, int a2, int a3, u8 *out, int f5, int f6) {
    switch (work[0x9F]) {
    case 0:
        work[0xA0] = 0;
        work[0x9F]++;
        break;
    case 1:
        *(s16 *)(work + 0x70) = *(s16 *)(work + 0x70) + 8;
        work[0xA0]++;
        if (work[0xA0] >= 0x20) {
            ov96_021EAB38(*(void **)(work + a3 * 4), 0);
            work[0x9F]++;
        }
        break;
    case 2:
        if (f6) {
            if (ov96_02208448(a0, a3)) {
                out[8] = 1;
                work[0x9F]++;
            }
        } else if (f5) {
            if (ov96_02208608(a0, a2)) {
                out[8] = 1;
                work[0x9F]++;
            }
        } else {
            work[0x9F]++;
        }
        break;
    case 3:
        break;
    }
}

void ov96_02206D58(u8 *work, int a1, int a2, u8 *out, int f4) {
    switch (work[0x9F]) {
    case 0:
        work[0xA0] = 0;
        ov96_021EAB38(*(void **)(work + a2 * 4), 1);
        work[0x9F]++;
        break;
    case 1:
        *(s16 *)(work + 0x70) = *(s16 *)(work + 0x70) - 8;
        work[0xA0]++;
        if (work[0xA0] >= 0x20) {
            *(u16 *)(work + 0x70) = 0;
            work[0x9F]++;
        }
        break;
    case 2:
        if (f4) {
            out[8] = 2;
        }
        work[0x9F]++;
        break;
    case 3:
        break;
    }
}

void ov96_02206DEC(void *a0, u8 *work, void *src, int a3, u8 a4, u8 *a5, int a6, int a7, int a8) {
    u8 tmp = *(u32 *)((u8 *)src + 0x10) >> 23;
    u8 v = (tmp >> (a3 * 2)) & 3;

    if (work[0x9E] != v) {
        work[0x9E] = v;
        work[0x9F] = 0;
    }
    switch (work[0x9E]) {
    case 0:
        break;
    case 1:
        ov96_02206C90(a0, work, a3, a4, a5, (a6 && a8) ? 1 : 0, a7);
        break;
    case 2:
        ov96_02206D58(work, a3, a4, a5, a7 | ((a6 && a8) ? 1 : 0));
        break;
    }
}
