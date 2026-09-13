#include "ov96_r109_r3_private.h"

void ov96_02213E60(u8 *work, PickOut *out) {
    u8 candidates[16];
    u8 count = 0;
    s32 i;
    for (i = 0; i < 15; i++) {
        if (work[0x66e] != i && work[0x6ba] != i) {
            candidates[count++] = i;
        }
    }
    {
        u8 selected = candidates[(u8)(LCRandom() % count)];
        out->x = ov96_0221D438[selected * 2] << 12;
        out->y = ov96_0221D43A[selected * 2] << 12;
        out->index = selected;
    }
}

u8 ov96_02213EC4(u8 *obj) {
    s32 value;
    s32 result;
    if (obj[0x39] == 3) {
        if (*(s32 *)(obj + 0xc) == 0x58000) {
            result = obj[0x43] + 0xc0;
        } else if (*(s32 *)(obj + 0xc) == 0x68000) {
            result = obj[0x43] + 0xc8;
        } else if (*(s32 *)(obj + 0xc) == 0x78000) {
            result = obj[0x43] + 0xd0;
        } else {
            GF_AssertFail();
            value = *(s32 *)(obj + 0xc);
            result = (value + (s32)((u32)(value >> 11) >> 20)) >> 12;
        }
    } else if (obj[0x39] == 1) {
        if (obj[0x3b] == 0xc) {
            value = *(s32 *)(obj + 0xc);
            result = (value + (s32)((u32)(value >> 11) >> 20)) >> 12;
        } else {
            u32 direction = ov96_022143DC(obj);
            result = ov96_02214394(direction, (u8)_s32_div_f(obj[0x3b], 3));
        }
    } else {
        value = *(s32 *)(obj + 0xc);
        result = (value + (s32)((u32)(value >> 11) >> 20)) >> 12;
    }
    return result;
}

s32 ov96_02213F5C(s32 value) {
    u8 i;
    s32 result;
    if (value < 0xc0) {
        return value << 12;
    }
    if (value < 0xd8) {
        value -= 0xc0;
        i = value % 8;
        if (value < 8) {
            result = ov96_0221DC80[i] + 0x58;
        } else if (value < 0x10) {
            result = ov96_0221DC80[i] + 0x68;
        } else {
            result = ov96_0221DC80[i] + 0x78;
        }
        return result << 12;
    }
    if (value < 0xe8) {
        return value << 12;
    }
    GF_AssertFail();
    return value << 12;
}

void ov96_02213FB4(StateObj *obj) {
    switch (obj->state) {
    case 1:
        obj->state = 4;
        break;
    case 4:
        obj->state = 2;
        break;
    case 2:
        obj->state = 3;
        break;
    case 3:
        obj->state = 1;
        break;
    }
}

void ov96_02213FF4(u8 *w, u32 i, BOOL special, s32 value) {
    if (value < 0xc0) {
        w[0x7b4 + i] = 0;
        return;
    }
    if (value < 0xd8) {
        if (w[0x7b4 + i] == 0) {
            w[0x7b4 + i] = 1;
            if (i == 0 && special != 0) {
                PlaySE(0x8ca);
                return;
            }
            PlaySE(0x8c9);
        }
        return;
    }
    w[0x7b4 + i] = 0;
}
