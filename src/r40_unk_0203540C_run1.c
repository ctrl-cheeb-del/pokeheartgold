#include "r40_unk_0203540C_private.h"
#define W       _021D4134.work
#define U8O(n)  (*(u8 *)(W + (n)))
#define U16O(n) (*(u16 *)(W + (n)))

void sub_0203540C(int value, u8 *unused) {
    int mode = sub_02033298(value);
    int connected = sub_020347CC();
    sub_020353B8();
    if (sub_020338F4() == 0 && sub_0203567C() == 0 && (((u32)U8O(0xD95) << 29) >> 31)) {
        U8O(0xD95) = (U8O(0xD95) & ~1) | 1;
    }
    if (U16O(0xD8E) == 0xFFFF) {
        U16O(0xD8E) = value;
    }
    if (((u32)U8O(0xD95) << 30) >> 31) {
        if (U16O(0xD8E) > (u32)value) {
            U8O(0xD95) = (U8O(0xD95) & ~1) | 1;
        }
        if (connected != 0) {
            U8O(0xD95) = (U8O(0xD95) & ~1) | 1;
        }
    }
    if (sub_020332AC() == 0x19) {
        sub_020399DC(0);
    }
    switch (mode) {
    case 0:
        if (U8O(0xD92) == 1) {
            sub_020350D4();
            return;
        }
        if (U8O(0xD92) == 2) {
            U8O(0xD92) = 3;
            return;
        }
        break;
    case 1:
        if (U8O(0xD92) == 1) {
            if (sub_020338D0() != 0) {
                break;
            }
        }
        if (U8O(0xD92) == 2) {
            if (sub_020338D0() == 0) {
                return;
            }
            return;
        }
        break;
    case 8:
    case 9:
        if (W != NULL) {
            U8O(0xD95) = (U8O(0xD95) & ~1) | 1;
            return;
        }
        break;
    case 7: {
        u16 id = sub_02033468();
        u16 saved;
        int a3;
        u32 a4;
        if (U8O(0xD91) == 0) {
            U16O(0xD8C) = id;
            U8O(0xD91) = 5;
        } else {
            U8O(0xD91)
            --;
        }
        saved = U16O(0xD8C);
        if (((u32)U8O(0xD95) << 28) >> 31) {
            _021D4134.localId = WM_GetNextTgid();
        }
        sub_020352D8();
        a3 = sub_02033FC4((u16)sub_0203993C());
        a4 = sub_02035724((u16)sub_0203993C());
        sub_02033668(0, _021D4134.localId, saved, a3, a4, ((u32)U8O(0xD95) << 26) >> 31);
        U8O(0xD90) = saved;
        break;
    }
    }
    return;
}
