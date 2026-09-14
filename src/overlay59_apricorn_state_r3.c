#include "overlay59_apricorn_state_r3_internal.h"

u32 ov59_02238124(Ov59Work *work) {
    int result;

    switch (U16_(work, 0x3C)) {
    case 0:
        ov59_02238FF4(work, 2);
        ov59_02238AB0(work, 1);
        ov59_02238C40(work, 11);
        U16_(work, 0x3C)
        ++;
        break;
    case 1:
        result = ov59_0223A05C(work);
        if (result == 6) {
            break;
        }
        U8_(work, 0x48) = result;
        U8_(work, 0x51) = 4;
        U16_(work, 0x3C)
        ++;
        break;
    case 2:
        if (U8_(work, 0x51)-- != 0) {
            break;
        }
        if (U8_(work, 0x48) == 1) {
            ov59_02238FF4(work, 0);
            ov59_02238AB0(work, 0);
            ov59_02238C40(work, 10);
            U16_(work, 0x3C) = 0;
            return 5;
        }
        ov59_02238C40(work, 12);
        ov59_02238AB0(work, 0);
        ov59_02238F58(work);
        U16_(work, 0x3C)
        ++;
        break;
    case 3:
        result = ov59_02238FB4(work);
        if (result < 0) {
            break;
        }
        U16_(work, 0x3C) = 0;
        if (result != 0) {
            ApricornBox_SetKurtApricorn(PTR_(work, 0x10), U8_(work, 0x4D), U8_(work, 0x4E));
            return 1;
        }
        ov59_02238FF4(work, 0);
        ov59_02238C40(work, 10);
        // fallthrough
    default:
        U16_(work, 0x3C) = 0;
        return 5;
    }
    return 6;
}

u32 ov59_02238218(Ov59Work *work) {
    switch (U16_(work, 0x3C)) {
    case 0:
        ov59_02238FF4(work, 2);
        U16_(work, 0x3C)
        ++;
        break;
    case 1:
        if (!ov59_022390A8(work, 1)) {
            break;
        }
        ov59_0223919C(work, 0, 0);
        ov59_0223919C(work, 1, 0);
        U16_(work, 0x3C)
        ++;
        break;
    case 2:
        if (U8_(work, 0x50) != 0) {
            break;
        }
        PlaySE(0x8E6);
        Sprite_SetAnimCtrlSeq(PTR_(work, 0x27C), 0x15);
        U16_(work, 0x3C)
        ++;
        // fallthrough
    case 3:
        if (U32_(gSystem, 0x48) & 1) {
            U16_(work, 0x3C) = 0;
            PlaySE(0x5EA);
            return 10;
        }
        if (U32_(gSystem, 0x48) & 2) {
            U16_(work, 0x3C) = 0;
            PlaySE(0x682);
            return 9;
        }
        if (System_GetTouchNew()) {
            U16_(work, 0x3C) = 0;
            PlaySE(0x682);
            if (U32_(work, 0x40) != 1) {
                U32_(work, 0x40) = 0;
            }
            return 9;
        }
        break;
    default:
        U16_(work, 0x3C) = 0;
        return 4;
    }
    return 7;
}

u32 ov59_022382F4(Ov59Work *work) {
    int result;

    switch (U16_(work, 0x3C)) {
    case 0:
        ov59_02238FF4(work, 2);
        U16_(work, 0x3C)
        ++;
        break;
    case 1:
        if (ov59_022390A8(work, 1)) {
            U16_(work, 0x3C)
            ++;
        }
        break;
    case 2:
        result = ov59_02239F38(work);
        switch (result) {
        case 0:
            U16_(work, 0x3C) = 0;
            return 9;
        case 1:
            U16_(work, 0x3C) = 0;
            return 10;
        default:
            break;
        }
        break;
    }
    return 8;
}

u32 ov59_0223834C(Ov59Work *work) {
    switch (U16_(work, 0x3C)) {
    case 0:
        ov59_0223919C(work, 0, 1);
        ov59_0223919C(work, 1, 1);
        Sprite_SetAnimCtrlSeq(PTR_(work, 0x27C), 0x14);
        U16_(work, 0x3C)
        ++;
        break;
    case 1:
        if (U8_(work, 0x50) == 0) {
            U16_(work, 0x3C)
            ++;
        }
        break;
    case 2:
        if (!ov59_022390A8(work, 0)) {
            break;
        }
        // fallthrough
    default:
        ov59_02238FF4(work, 0);
        U16_(work, 0x3C) = 0;
        return 4;
    }
    return 9;
}

u32 ov59_022383B4(Ov59Work *work) {
    switch (U16_(work, 0x3C)) {
    case 0:
        if (U8_(work, 0x18) >= 5) {
            ov59_02238C40(work, 7);
            ov59_02238CFC(work, 0x1A, 0xFF);
            U16_(work, 0x3C) = 1;
        } else {
            U8_(work, 0x49) = 2;
            U8_(work, 0x4A) = 0;
            U16_(work, 0x3C) = 2;
        }
        break;
    case 1:
        if (ov59_022385AC(work)) {
            ov59_02238D74(work);
            U16_(work, 0x3C) = 0;
            return 9;
        }
        break;
    case 2:
        if (!ov59_022390A8(work, 0)) {
            break;
        }
        {
            Ov59Work *entry = work + (U8_(work, 0x4D) + 2) * 4;
            Sprite_SetDrawFlag(PTR_(entry, 0x254), 0);
        }
        Sprite_SetAnimCtrlSeq(PTR_(work, 0x27C), 0x16);
        Sprite_ResetAnimCtrlState(PTR_(work, 0x27C));
        U16_(work, 0x3C)
        ++;
        break;
    case 3:
        if (Sprite_IsAnimated(PTR_(work, 0x27C))) {
            break;
        }
        PlaySE(0x8E6);
        Sprite_SetAnimCtrlSeq(PTR_(work, 0x27C), 0x14);
        sub_02031C30(PTR_(work, 0x10), U8_(work, 0x4D), PTR_(work, 0x38));
        ov59_02238768(work);
        ov59_0223919C(work, 1, 0);
        U16_(work, 0x3C)
        ++;
        break;
    case 4:
        if (U8_(work, 0x50) != 0) {
            break;
        }
        if (U8_(work, 0x18) >= 5) {
            ov59_02238C40(work, 7);
        } else {
            ov59_02238C40(work, 6);
        }
        ov59_0223892C(work, U8_(work, 0x4D));
        ov59_02238FF4(work, 0);
        U16_(work, 0x3C) = 0;
        return 4;
    }
    return 10;
}

u32 ov59_022384E4(Ov59Work *work) {
    int result;

    switch (U16_(work, 0x3C)) {
    case 0:
        ov59_02238E98(work);
        ov59_02238C40(work, 8);
        ov59_02238FF4(work, 1);
        U16_(work, 0x3C)
        ++;
        break;
    case 1:
        result = ov59_02238F24(work);
        if (result == -1) {
            break;
        }
        U16_(work, 0x3C) = 0;
        if ((u32)result >= 2 || result == -2) {
            ov59_02238C24(work);
            return 4;
        }
        if (result == 1) {
            ov59_02238C40(work, 9);
            ov59_02238D90(work);
            ov59_02238FF4(work, 1);
            return 15;
        }
        U8_(PTR_(work, 4), 0x18) = 3;
        U8_(PTR_(work, 4), 0x1C) = 0;
        U8_(PTR_(work, 4), 0x1A) = U8_(work, 0x4B);
        U8_(PTR_(work, 4), 0x1B) = U8_(work, 0x4C);
        return 1;
    }
    return 11;
}
