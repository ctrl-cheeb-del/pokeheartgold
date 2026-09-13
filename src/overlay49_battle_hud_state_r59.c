#include "overlay49_battle_hud_state_r59_private.h"

BOOL ov49_02260254(void *controller, void *work, u32 arg) {
    void *object;
    void *entry;
    int flag;

    switch (ov49_0225EF88(controller)) {
    case 0:
        object = ov49_02259FF0(work);
        entry = ov49_02258DAC(object);
        ov49_02258EEC(object, entry, 0);
        ov45_0222A5E8(ov49_02259FE8(work), 0xB);
        PlaySE(0x5DD);
        ov49_0225A08C(work, ov49_0225A30C(work, 1, 0x41));
        ov49_0225EF90(controller);
        break;
    case 1:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225EF90(controller);
        }
        break;
    case 2:
        ov49_0225A08C(work, ov49_0225A30C(work, 2, 0x19));
        ov49_0225EF90(controller);
        break;
    case 3:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225EF90(controller);
        }
        break;
    case 4:
        ov49_0225A294(work);
        ov49_0225EF90(controller);
        break;
    case 5:
        flag = 0;
        switch (ov49_0225A2C4(work)) {
        case 0:
            ov49_0225EF8C(controller, 6);
            flag = 1;
            break;
        case 1:
            ov49_0225EF8C(controller, 8);
            flag = 1;
            break;
        case 2:
            break;
        }
        if (flag == 1) {
            ov49_0225A2F8(work);
            ov49_0225A0EC(work);
        }
        break;
    case 6:
        ov49_0225A018(work, 0);
        object = ov49_02259FF0(work);
        entry = ov49_02258DAC(object);
        ov49_0225CC44(ov49_0225A008(work));
        ov49_02258EEC(object, entry, 3);
        ov49_0225EF8C(controller, 7);
        break;
    case 7:
        if (ov49_02258F38(ov49_02258DAC(ov49_02259FF0(work))) == 1) {
            ov49_0225A034(work, 1);
            ov49_0225A038(work, 0);
            ov45_0222A5E8(ov49_02259FE8(work), 0xB);
            return TRUE;
        }
        break;
    case 8:
        object = ov49_02259FF0(work);
        entry = ov49_02258DAC(object);
        ov49_02258EAC(object, entry, 2, 0);
        ov49_0225EF90(controller);
        break;
    case 9:
        ov45_0222A5E8(ov49_02259FE8(work), 1);
        object = ov49_02259FF0(work);
        controller = ov49_0225A010(work);
        entry = ov49_02258DAC(object);
        if (ov49_02258E60(entry, 5) == 0) {
            ov49_02258EEC(object, entry, 1);
            ov49_0225EF98(controller, arg, ov49_02269B38, 0);
        }
        break;
    }
    return FALSE;
}
