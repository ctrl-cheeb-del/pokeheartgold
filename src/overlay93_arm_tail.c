#include "overlay93_arm_tail_internal.h"

typedef struct Ov93Node {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
} Ov93Node;

typedef struct Ov93WorkScratch {
    u8 pad000[0xc];
    Ov93Node nodes[8];
    Ov93Node nodes2[8];
    s32 f20c;
    s32 f210;
    u8 pad214[0x218 - 0x214];
    s32 f218;
    u8 pad21c[0x224 - 0x21c];
    s32 f224;
    s32 f228;
    s32 f22c;
    s32 f230;
    u8 pad234[0x238 - 0x234];
    s32 f238;
    s32 f23c;
    s32 f240;
    u8 pad244[0x248 - 0x244];
    s32 f248;
    u8 pad24c[0x270 - 0x24c];
    u32 f270;
    u8 f274;
} Ov93WorkScratch;

extern const u8 ov93_02262C05[];
extern const u8 ov93_02262C06[];
extern const u8 ov93_02262C07[];
extern const u8 ov93_02262C08[];
extern s32 ov93_0225F9AC(Ov93WorkScratch *work);
int ov93_0225F370(Ov93WorkScratch *work);
extern BOOL IsSEPlaying(u16 seqNo);
extern void PlaySE(u16 seqNo);
extern s32 ov93_0225F548(Ov93WorkScratch *work, s32 mode, s32 amount);
extern s32 ov93_0225F8AC(Ov93WorkScratch *work, s32 mode);
extern BOOL ov93_0225F8E4(Ov93WorkScratch *work, s32 amount, s32 a, s32 b, s32 *hi, s32 *lo);
extern u16 FX_Atan2Idx(fx32 y, fx32 x);
extern void ov93_0225EB38(Ov93WorkScratch *work);
int ov93_0225F44C(Ov93WorkScratch *work);

int ov93_0225F370(Ov93WorkScratch *work) {
    s32 idx;
    s32 y;
    s32 mid;

    if (work->f238 == 1 || work->f218 == 0) {
        return 0;
    }
    idx = work->f270;
    y = ov93_02262C07[idx * 4] + (work->f230 >> 12);
    if (work->f20c < ov93_02262C05[idx * 4] || work->f20c > ov93_02262C06[idx * 4] || work->f210 < y || work->f210 > ov93_02262C08[idx * 4]) {
        return 0;
    }
    work->f238 = 1;
    work->f224 = work->f20c;
    work->f228 = work->f210;
    work->f22c = work->f210 - y;
    mid = work->nodes[0].f14 + (work->nodes[0].f04 - work->nodes[0].f14) / 2;
    work->f230 = -mid;
    work->f240 = ov93_0225F9AC(work);
    return 1;
}

int ov93_0225F44C(Ov93WorkScratch *work) {
    s32 mode = 0;
    s32 amount;
    s32 result;

    if (work->f238 == 1) {
        s32 previous = work->f23c;
        s32 current = work->f210;

        if (current < previous) {
            work->f274 = 0;
            return 0;
        }
        if (current == previous) {
            work->f274 = 0;
            return 1;
        }
        if (previous != -1 && current > previous && !IsSEPlaying(0x58f)) {
            PlaySE(0x58f);
            work->f274 = 1;
        }
        amount = ((work->f210 - work->f22c) << 12) - (work->f230 + (ov93_02262C07[work->f270 * 4] << 12));
        work->f23c = work->f210;
    } else {
        mode = 1;
        amount = -work->f248;
    }
    result = ov93_0225F548(work, mode, amount);
    if (result != 0) {
        if (result != 1 && result != 2) {
            result = result;
        } else {
            ov93_0225EB38(work);
        }
    }
    work->f230 = -(work->nodes[0].f14 + (work->nodes[0].f04 - work->nodes[0].f14) / 2);
    return 1;
}

s32 ov93_0225F548(Ov93WorkScratch *work, s32 mode, fx32 amount) {
    s32 hi;
    s32 lo;
    BOOL flag;
    s32 a;
    s32 b;
    s32 mid;
    s32 newMid;
    s32 i;
    s32 deltaMid;
    s32 angleA;
    s32 angleB;

    a = -work->nodes[0].f04;
    b = -work->nodes[0].f14;
    mid = b + (a - b) / 2;
    flag = FALSE;

    switch (ov93_0225F8AC(work, mode)) {
    case 0:
        hi = a + amount;
        lo = b + amount;
        break;
    case 1:
        flag = ov93_0225F8E4(work, amount, a, b, &hi, &lo);
        break;
    case 2:
        flag = ov93_0225F8E4(work, amount, b, a, &lo, &hi);
        break;
    }

    newMid = lo + (hi - lo) / 2;
    if (mid == newMid && a == hi && b == lo) {
        return 0;
    }
    if (newMid < 0) {
        newMid = 0;
    }
    if (hi < 0) {
        hi = 0;
    }
    if (lo < 0) {
        lo = 0;
    }
    if (newMid > FX32_CONST(100)) {
        newMid = FX32_CONST(100);
        flag = TRUE;
    }
    if (hi > FX32_CONST(100)) {
        hi = FX32_CONST(100);
        flag = TRUE;
    }
    if (lo > FX32_CONST(100)) {
        lo = FX32_CONST(100);
        flag = TRUE;
    }

    switch (ov93_0225F8AC(work, mode)) {
    default:
    case 0:
        angleB = FX_Atan2Idx(lo - newMid, FX32_CONST(64));
        angleA = (u16)(angleB + 0x8000);
        break;
    case 2:
        angleB = FX_Atan2Idx(lo - newMid, FX32_CONST(64));
        angleA = (u16)(angleB + 0x8000);
        break;
    case 1:
        angleA = FX_Atan2Idx(hi - newMid, -FX32_CONST(64));
        angleB = (u16)(angleA + 0x8000);
        break;
    }

    work->nodes[0].f00 = (FX_CosIdx(angleA) << 6) + FX32_CONST(64);
    work->nodes[0].f04 = -(newMid + (FX_SinIdx(angleA) << 6));
    work->nodes[0].f10 = (FX_CosIdx(angleB) << 6) + FX32_CONST(64);
    work->nodes[0].f14 = -(newMid + (FX_SinIdx(angleB) << 6));
    deltaMid = (FX32_CONST(112) - newMid) / 7;
    if ((u32)angleB > 0x8000) {
        a = -(0x10000 - angleB) / 7;
    } else {
        a = angleB / 7;
    }
    b = a;
    mid = deltaMid;
    for (i = 1; i < 7; i++) {
        work->nodes[i].f00 = (FX_CosIdx(angleA - b) << 6) + FX32_CONST(64);
        work->nodes[i].f04 = -(newMid + (FX_SinIdx(angleA - b) << 6) + mid);
        work->nodes[i].f10 = (FX_CosIdx(angleB - b) << 6) + FX32_CONST(64);
        work->nodes[i].f14 = -(newMid + (FX_SinIdx(angleB - b) << 6) + mid);
        work->nodes[i - 1].f08 = work->nodes[i].f00;
        work->nodes[i - 1].f0c = work->nodes[i].f04;
        work->nodes[i - 1].f18 = work->nodes[i].f10;
        work->nodes[i - 1].f1c = work->nodes[i].f14;
        b += a;
        mid += deltaMid;
    }
    return flag == TRUE ? 2 : 0;
}
