#include "overlay72_event_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

int ov72_0223A014(void *p) {
    sub_0203A914(p);
    sub_0203946C();
    BeginNormalPaletteFade(0, 0, 0, 0, 8, 1, 0x43);
    U32(p, 0x1C) = 0;
    return 4;
}

int ov72_0223A044(void *p) {
    int r = ov72_02238668(PTR(p, 0x1308));
    if (r != 0) {
        if (r == 2) {
            U32(p, 0x1C) = 0;
        } else {
            U32(p, 0x1C) = 0x29;
        }
    }
    return 3;
}

int ov72_0223A06C(void *p) {
    int msg = 0;
    switch (S32(p, 0xF5C)) {
    case -6:
    case -2:
        msg = 0x0F;
        break;
    case 1:
        msg = 0x0D;
        break;
    case -1:
    case 2:
        msg = 0x0E;
        break;
    case -7:
    case -4:
        msg = 0x10;
        break;
    case -3:
        msg = 0x11;
        break;
    }
    ov72_0223A444(p);
    ov72_0223A350(p, PTR(p, 0xBD4), msg, 1, 0xF0F);
    ov72_02238680(p, 0x2F, 0x36);
    return 3;
}
