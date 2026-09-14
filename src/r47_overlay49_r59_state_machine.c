#include "r47_overlay49_r59_state_machine_private.h"

BOOL ov49_022607C4(void *controller, void *work, u32 arg) {
    void *state = ov49_0225EF84(controller);
    void *owner = ov49_0225A010(work);
    void *object = ov49_02259FF0(work);
    void *entry = ov49_02258DAC(object);
    void *anim = ov49_02259FE8(work);
    int value;
    int choice;

    switch (ov49_0225EF88(controller)) {
    case 0: {
        u8 *selection = ov49_0225EF40(controller, 4);
        ov49_02258EEC(object, entry, 0);
        ov49_0225EF90(controller);
        selection[0] = 0;
        switch (ov49_0225A040(work)) {
        case 0x1e:
            selection[1] = 0;
            selection[2] = 0;
            selection[3] = 2;
            break;
        case 0x1f:
            selection[1] = 1;
            selection[2] = 1;
            selection[3] = 3;
            break;
        case 0x20:
            selection[1] = 2;
            selection[2] = 2;
            selection[3] = 4;
            break;
        default:
            GF_AssertFail();
            break;
        }
        ov45_0222A5E8(ov49_02259FE8(work), 12);
        ov49_0225EFC4(owner, arg, ov49_02269B88, selection);
        break;
    }
    case 1:
        if (*(u8 *)state == 8) {
            ov49_0225EF8C(controller, 2);
        } else {
            ov49_0225EF8C(controller, 3);
        }
        break;
    case 2: {
        Ov49ResultR59 *result;
        Ov49Pair16 position;
        Ov49Pair16 current;
        u32 packed;
        u32 converted;
        switch (ov49_0225A040(work)) {
        case 0x1e:
            value = 3;
            choice = 0;
            break;
        case 0x1f:
            value = 4;
            choice = 1;
            break;
        case 0x20:
            value = 5;
            choice = 2;
            break;
        }
        ov49_0225A034(work, 1);
        ov49_0225A038(work, (u8)value);
        IncrementGameStat119(anim);
        ov45_0222B118(anim, choice);
        converted = ov42_022282A4(ov49_02258E60(entry, 6));
        result = ov49_02259FEC(work);
        packed = ov49_02258E34(entry);
        current.x = packed;
        current.y = packed >> 16;
        position = current;
        result->kind = 2;
        result->x = position.x / 16;
        result->y = position.y / 16;
        result->value = converted;
        result->state = *((u8 *)state + 2);
        ov45_0222A4C8(ov49_02259FE8(work), 1);
        ov49_0225EF68(controller);
        return TRUE;
    }
    case 3:
        ov49_02258EAC(object, entry, 2, ov42_022282A4(ov49_02258E60(entry, 6)));
        ov49_0225EF90(controller);
        break;
    case 4:
        if (ov49_02258E60(entry, 5) == 0) {
            ov49_0225EF90(controller);
        }
        break;
    case 5: {
        BOOL valid = TRUE;
        switch (*(u8 *)state) {
        case 0:
            ov49_0225A37C(work, *((u8 *)state + 2), 0);
            value = 4;
            break;
        case 1:
            value = 5;
            break;
        case 2:
            ov49_0225A37C(work, *((u8 *)state + 2), 0);
            value = 6;
            break;
        case 3:
            value = 0x13;
            break;
        case 4:
            value = 0x11;
            break;
        case 6:
            value = 0x1d;
            break;
        case 7:
            value = 7;
            break;
        default:
            valid = FALSE;
            break;
        }
        if (valid) {
            ov49_0225A08C(work, ov49_0225A30C(work, 0, value));
            ov49_0225EF90(controller);
        } else {
            ov49_0225EF8C(controller, 7);
        }
        break;
    }
    case 6:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225A0EC(work);
            ov49_0225EF90(controller);
        }
        break;
    case 7:
        ov49_0225EF68(controller);
        ov45_0222A5E8(ov49_02259FE8(work), 1);
        ov49_02258EEC(object, entry, 1);
        ov49_0225EF98(ov49_0225A010(work), arg, ov49_02269B38, 0);
        break;
    }
    return FALSE;
}
