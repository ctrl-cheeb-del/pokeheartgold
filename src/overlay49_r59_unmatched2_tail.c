#include "overlay49_r59_unmatched2_tail_private.h"

BOOL ov49_02260A68(void *controller, void *work, u32 arg) {
    void *state = ov49_0225EF84(controller);
    void *object;
    void *entry;
    void *anim;
    Ov49Result *result;
    int value;
    u32 packed;
    UnkStruct_ov44_02232914 position;
    UnkStruct_ov44_02232914 current;

    ov49_0225A010(work);
    object = ov49_02259FF0(work);
    entry = ov49_02258DAC(object);
    anim = ov49_02259FE8(work);

    switch (ov49_0225EF88(controller)) {
    case 0: {
        u16 *selection = ov49_0225EF40(controller, 12);
        ov45_0222A5E8(ov49_02259FE8(work), 13);
        if (ov45_0222A330(anim) == 1) {
            selection[0] = 0x7a;
            ov49_0225EF8C(controller, 2);
        } else if (ov45_0222A3A0(anim) == 1) {
            selection[1] = 10;
            goto set_state_one;
        } else if (ov45_0222A2E0(anim) == 1) {
            selection[0] = 0x62;
            ov49_0225EF8C(controller, 2);
        } else {
            selection[1] = 9;
set_state_one:
            ov49_0225EF8C(controller, 1);
        }
        break;
    }
    case 1:
        if (((u16 *)state)[1] == 9) {
            value = 9;
        } else {
            value = 10;
            ov45_0222A310(anim);
        }
        ov49_0225A034(work, 1);
        ov49_0225A038(work, (u8)value);
        ov45_0222A704(anim, 23, -1);
        value = ov42_022282A4(ov49_02258E60(entry, 6));
        result = ov49_02259FEC(work);
        packed = ov49_02258E34(entry);
        current.unk0 = packed;
        current.unk2 = packed >> 16;
        position = current;
        result->kind = 3;
        result->x = position.unk0 / 16;
        result->y = position.unk2 / 16;
        result->value = value;
        result->zero = 0;
        ov49_0225EF68(controller);
        return TRUE;
    case 2:
        ov49_02258EAC(object, entry, 2, ov42_022282A4(ov49_02258E60(entry, 6)));
        ov49_0225EF90(controller);
        break;
    case 3:
        if (ov49_02258E60(entry, 5) == 0) {
            ov49_0225EF90(controller);
        }
        break;
    case 4:
        ov49_0225A08C(work, ov49_0225A30C(work, 1, ((u16 *)state)[0]));
        ov49_0225EF90(controller);
        break;
    case 5:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225A0EC(work);
            ov49_0225EF90(controller);
        }
        break;
    case 6:
        ov49_0225EF68(controller);
        ov45_0222A5E8(ov49_02259FE8(work), 1);
        ov49_02258EEC(object, entry, 1);
        ov49_0225EF98(ov49_0225A010(work), arg, ov49_02269B38, 0);
        break;
    default:
        GF_AssertFail();
        break;
    }
    return FALSE;
}
