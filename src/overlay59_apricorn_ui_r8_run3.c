#include "overlay59_apricorn_ui_r8_private.h"

#define U8(w, off)  (*(u8 *)((u8 *)(w) + (off)))
#define U16(w, off) (*(u16 *)((u8 *)(w) + (off)))
#define U32(w, off) (*(u32 *)((u8 *)(w) + (off)))
#define PTR(w, off) (*(void **)((u8 *)(w) + (off)))

int ov59_0223A03C(Ov59R8Work *work) {
    int hit = 0;
    int result = ov59_0223A418(work, &hit);
    if (hit == 0) {
        result = ov59_0223A3B0(work);
    }
    return result;
}

int ov59_0223A05C(Ov59R8Work *work) {
    int hit = 0;
    int result = ov59_0223A614(work, &hit);
    if (hit == 0) {
        result = ov59_0223A58C(work);
    }
    return result;
}

int ov59_0223A07C(Ov59R8Work *work, u32 input) {
    if (input <= 6) {
        PlaySE(0x5DC);
        ov59_022388C4(work);
        U8(work, 0x4D) = input;
        return 3;
    }
    if (input == 8) {
        PlaySE(0x5DC);
        ov59_022387D0(work, 1);
        return 1;
    }
    return 3;
}

int ov59_0223A0B8(Ov59R8Work *work) {
    u32 keys = gSystem.newKeys;
    if (keys & 0xCF3) {
        U32(work, 0x40) = 0;
    }
    keys = gSystem.newKeys;
    if (keys & 2) {
        return ov59_0223A07C(work, 8);
    }
    if (keys & 1) {
        return ov59_0223A07C(work, ov59_02239EA8(work));
    }
    if (ov59_0223A678(work)) {
        PlaySE(0x5DC);
        ov59_022388C4(work);
        return 3;
    }
    return 3;
}

int ov59_0223A120(Ov59R8Work *work, int *hit) {
    int input = TouchscreenHitbox_FindHitboxAtTouchNew((const TouchscreenHitbox *)ov59_0223C924);
    if (input == -1 || input == 7) {
        return 3;
    }
    *hit = 1;
    U32(work, 0x40) = 1;
    U8(work, 0x4C) = 0;
    U8(work, 0x4B) = U8(work, 0x4C);
    U8(work, 0x4A) = 0;
    if (input == 8) {
        U8(work, 0x49) = 2;
    } else {
        U8(work, 0x49) = input % 2;
        U8(work, 0x4A) = input / 2;
    }
    return ov59_0223A07C(work, input);
}

int ov59_0223A194(Ov59R8Work *work, u32 input) {
    if (input <= 6) {
        ov59_022388C4(work);
        if (U8(work, 0x1A + input) == 0) {
            return 4;
        }
        PlaySE(0x5EB);
        U8(work, 0x4D) = input;
        return U32(work, 0x40) == 0 ? 7 : 8;
    }
    if (input == 8) {
        PlaySE(0x5DC);
        ov59_022387D0(work, 1);
        return 1;
    }
    if (input == 7) {
        PlaySE(0x5DC);
        ov59_022388C4(work);
        U8(work, 0x4D) = input;
        if (U8(work, 0x14) == 0 && U8(work, 0x18) == 0) {
            ov59_02238CFC(work, 0x19, 0xFF);
            ov59_02238FF4(work, 1);
            return 15;
        }
        if (U8(work, 0x14) == 0 && U8(work, 0x18) != 0) {
            ov59_02238CFC(work, 0x1B, 0xFF);
            ov59_02238FF4(work, 1);
            return 15;
        }
        if (U8(work, 0x14) != 0 && U8(work, 0x18) != 0) {
            ov59_02238CFC(work, 0x1C, 0xFF);
            ov59_02238FF4(work, 1);
            return 15;
        }
        return 11;
    }
    return 4;
}

int ov59_0223A268(Ov59R8Work *work) {
    u32 keys = gSystem.newKeys;
    if (keys & 0xCF3) {
        U32(work, 0x40) = 0;
    }
    keys = gSystem.newKeys;
    if (keys & 2) {
        return ov59_0223A194(work, 8);
    }
    if (keys & 1) {
        return ov59_0223A194(work, ov59_02239EA8(work));
    }
    if (ov59_0223A678(work)) {
        PlaySE(0x5DC);
        ov59_022388C4(work);
        return 4;
    }
    return 4;
}
