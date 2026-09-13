#include "to41_ov40_r33_a05_private.h"

int ov40_0223B5B0(void *p) {
    void *w = Heap_Alloc(0x6D, 0x217C);
    memset(w, 0, 0x217C);
    PTR(p, 0x860) = w;
    if (WORD(p, 0x86C) == 0x12C) {
        WORD(w, 0xC) = 0;
    } else if (WORD(p, 0x86C) == 0x12D) {
        WORD(w, 0xC) = 1;
    } else if (WORD(p, 0x86C) == 0xC8) {
        WORD(w, 0xC) = 2;
    }
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
    ov40_0222D9E8(w, (u8 *)w + 4, 0);
    ov40_0222BF80(p, 1);
    return 0;
}

int ov40_0223B62C(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((u8 *)w + 8, 1)) {
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 2, 0xC);
        BLEND(p, w, 3, 0xC);
        BLEND(p, w, 1, 2);
        break;
    case 1:
        SetBgPriority(0, 1);
        SetBgPriority(1, 3);
        SetBgPriority(2, 0);
        SetBgPriority(3, 1);
        SetBgPriority(4, 1);
        SetBgPriority(5, 3);
        SetBgPriority(6, 0);
        SetBgPriority(7, 2);
        ov40_0222FB90(p, 0);
        sub_020879E0(PTR(p, 0x6F0), 0);
        WORD(p, 8)
        ++;
        break;
    case 2:
        if (ov40_0222FBB4(p)) {
            ov40_02230964(p, 1);
            ov40_0222D874(p);
            ov40_02230964(p, 0);
            ov40_02230964(p, 1);
            ov40_0223A430(p);
            ov40_02230964(p, 0);
            WORD(p, 8)
            ++;
        }
        break;
    default:
        if (ov40_0222C4DC() == 1) {
            ov40_0222BF80(p, 0x13);
        } else {
            ov40_0222BF80(p, 2);
        }
        break;
    }
    return 0;
}
