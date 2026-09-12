#include "overlay40_pc_box_summary_29_private.h"

void ov40_02236230(u32 a, int b, void *p) {
    void *w = PTR(p, 0x860);
    switch (a) {
    case 0:
        if (b == 2) {
            ov40_02230944(p);
            if (WORD(w, 0x1A0) > 0) {
                WORD(w, 0x1A0) = WORD(w, 0x1A0) - 1;
            } else {
                WORD(w, 0x1A0) = 0x11;
            }
            ov40_0222BF80(p, 4);
        }
        break;
    case 1:
        if (b == 2) {
            ov40_02230944(p);
            WORD(w, 0x1A0)
            ++;
            WORD(w, 0x1A0) = WORD(w, 0x1A0) % 0x12;
            ov40_0222BF80(p, 4);
        }
        break;
    case 2:
        if (b == 0) {
            ov40_02230944(p);
            ov40_0222BF80(p, 9);
        }
        break;
    case 3:
        if (b == 0) {
            ov40_02230944(p);
            if (ov40_022361C8((u8 *)w + 4) != 0) {
                ov40_0222BF80(p, 5);
            } else {
                ov40_02237030(p, 0x10F);
            }
        }
        break;
    }
}

void ov40_022362E4(u32 a, int b, void *p) {
    void *w = PTR(p, 0x860);
    if (b == 0) {
        if (a != 6) {
            ov40_02230944(p);
            WORD(w, 0x380) = a;
            ov40_0222BF80(p, 8);
        } else {
            ov40_02230944(p);
            ov40_0222BF80(p, 7);
        }
    }
}

void ov40_02236320(u32 a, int b, void *p) {
    void *w = PTR(p, 0x860);
    if (b == 0) {
        if (a != 6) {
            ov40_02230944(p);
            WORD(w, 0x380) = a;
            ov40_0222BF80(p, 4);
        } else {
            ov40_02230944(p);
            ov40_0222BF80(p, 0xC);
        }
    }
}

void ov40_0223635C(u32 a, int b, void *p) {
    void *w = PTR(p, 0x860);
    if (b == 0) {
        switch (a) {
        case 0:
        default:
            ov40_02230944(p);
            if (WORD(w, 0x2F64) == 0) {
                ov40_0222BF80(p, 7);
            } else {
                ov40_0222BF80(p, 8);
            }
            break;
        case 1:
            ov40_02230944(p);
            ov40_0222BF80(p, 9);
            break;
        case 2:
            ov40_02230944(p);
            ov40_0222BF80(p, 6);
            break;
        }
    }
}

void ov40_022363BC(u32 a, int b, void *p) {
    void *w = PTR(p, 0x860);
    if (b == 0) {
        switch (a) {
        case 0: {
            int idx;
            ov40_02230944(p);
            WORD(w, 0x1B0)
            ++;
            WORD(w, 0x1B0) = WORD(w, 0x1B0) % 0x1E;
            ov40_022361E0(w);
            WORD(w, 0x2F68) = WORD(w, 0x1B0) % 6;
            WORD(w, 0x2F6C) = WORD(w, 0x1B0) / 6;
            sub_020878B8(PTR(p, 0x6F0), (s16)(WORD(w, 0x2F68) * 0x18 + 0x6E), (s16)(WORD(w, 0x2F6C) * 0x16 + 0x34));
            ov40_02230964(p, 1);
            ov40_02237564(p);
            ov40_02237474(p);
            ov40_02230964(p, 0);
            ov40_022371E4(p, WORD(w, 0x1B0));
            idx = WORD(w, 0x1B0);
            if (HALF((u8 *)w + idx * 2, 0x2C) != 0) {
                if (ov40_022371D4(PTR(w, 0x158), 1 << idx) != 1) {
                    PlayCry(HALF((u8 *)w + WORD(w, 0x1B0) * 2, 0x2C), BYTE(w, 0x15C + WORD(w, 0x1B0)));
                }
            }
            break;
        }
        case 1:
            ov40_02230944(p);
            sub_020879E0(PTR(p, 0x6F0), 0);
            sub_02087A08(PTR(p, 0x6F0), 0, 0);
            ov40_0222BF80(p, 0xB);
            break;
        }
    }
}

void ov40_022364D0(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222D73C(p, 2);
    ov40_02230970(p, (u8 *)w + 0x348, 2, 3, 0x20, 0xE8, 0x24, -8, 0, 1);
    ov40_02230970(p, (u8 *)w + 0x364, 2, 0x35, 0x80, 0xE8, 0x24, -8, 1, 1);
}

void ov40_02236534(void *p) {
    void *w = PTR(p, 0x860);
    ov40_022309CC((u8 *)w + 0x348);
    ov40_022309CC((u8 *)w + 0x364);
    ov40_0222D7DC(p);
}

void ov40_0223655C(void *w) {
    int i;
    u16 *q;
    for (i = 0, q = (u16 *)w; i < 0x1E; i++, q++) {
        if (q[0x16] != 0) {
            WORD(w, 0x1B0) = i;
            return;
        }
    }
}

void ov40_02236578(void *a, void *b, u32 c, void *d) {
    memset(d, 0, 0x19C);
    ov39_02227088(a, b, c, d, 0x6D);
}

int ov40_022365A0(void *p) {
    void *w = Heap_Alloc(0x6D, 0x2F70);
    memset(w, 0, 0x2F70);
    PTR(p, 0x860) = w;
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
    PTR(w, 0) = SaveArray_PCStorage_Get(PTR(p, 0x830));
    ov40_02236578(PTR(p, 0x830), PTR(w, 0), UWORD(w, 0x1A0), (u8 *)w + 4);
    ov40_0223655C(w);
    ov40_0222D9E8((int *)((u8 *)w + 0x1A4), (int *)((u8 *)w + 0x1A8), 0);
    PTR(w, 0x330) = TouchHitboxController_Create(ov40_022452CC, 4, ov40_02236230, p, 0x6D);
    PTR(w, 0x334) = TouchHitboxController_Create(ov40_022452F4, 7, ov40_022362E4, p, 0x6D);
    PTR(w, 0x338) = TouchHitboxController_Create(ov40_022452F4, 7, ov40_02236320, p, 0x6D);
    PTR(w, 0x33C) = TouchHitboxController_Create(ov40_02245284, 3, ov40_0223635C, p, 0x6D);
    PTR(w, 0x340) = TouchHitboxController_Create(ov40_0224526C, 2, ov40_022363BC, p, 0x6D);
    PTR(w, 0x384) = sub_020314A4(0x6D);
    sub_020314C4(PTR(w, 0x384), PTR(p, 0x830));
    ov40_0222BF80(p, 1);
    return 0;
}
