#include "r40_overlay_49_residual_59_unmatched_1_private.h"

BOOL ov49_0225FA14(void *controller, void *work, u32 arg) {
    void *object;
    void *selection;
    u16 *data;
    void *entry;

    selection = ov49_02259FE8(work);
    data = ov49_02259FEC(work);
    object = ov49_02259FF0(work);
    entry = ov49_02258DAC(object);

    switch (ov49_0225EF88(controller)) {
    case 0:
        ov49_0225F334(work, arg, data[0], data[1], 1);
        if (ov45_0222D844() == 0) {
            ov45_0222EB94();
        }
        ov45_0222A520(selection, 0);
        ov49_0225EF90(controller);
        break;
    case 1:
        if (ov45_0222D844() != 0 || ov45_0222EBC4() != 0) {
            data = ov49_02259FEC(work);
            if (ov49_0225A030(work) == 0) {
                ov49_0225EF90(controller);
                ov49_02258EAC(object, entry, 2, data[2]);
            }
        }
        break;
    case 2:
        if (ov49_02258E60(entry, 5) == 0) {
            ov49_0225A018(work, 1);
            if (ov45_0222A4B8(selection) == 1) {
                ov49_0225EF90(controller);
            } else {
                ov49_0225EF8C(controller, 5);
            }
        }
        break;
    case 3:
        ov49_0225A37C(work, data[4], 0);
        ov49_0225A08C(work, ov49_0225A30C(work, 0, 0x15));
        ov49_0225EF90(controller);
        break;
    case 4:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225A0EC(work);
            ov49_0225EF90(controller);
        }
        break;
    case 5:
        ov49_02258EEC(object, entry, 1);
        controller = ov49_0225A010(work);
        ov49_0225EF98(controller, ov49_0225A02C(work), ov49_02269B38, 0);
        break;
    }

    return FALSE;
}

BOOL ov49_0225FB5C(void *controller, void *work, u32 arg) {
    void *selection;
    void *object;
    void *message;
    u16 *data;
    void *entry;

    message = ov49_0225A010(work);
    object = ov49_02259FF0(work);
    entry = ov49_02258DAC(object);
    selection = ov49_02259FE8(work);
    data = ov49_02259FEC(work);

    switch (ov49_0225EF88(controller)) {
    case 0:
        ov49_0225F334(work, arg, data[0], data[1], 1);
        ov49_0225EF90(controller);
        ov49_0225EFC4(message, arg, ov49_02269B68, 0);
        ov45_0222A4C8(selection, 0);
        ov45_0222A4D0(selection);
        break;
    case 1:
        data = ov49_02259FEC(work);
        if (ov49_0225A030(work) == 0) {
            ov49_0225EF90(controller);
            ov49_02258EAC(object, entry, 2, data[2]);
        }
        break;
    case 2:
        if (ov49_02258E60(entry, 5) == 0) {
            ov49_0225A018(work, 1);
            if (ov45_0222A424(selection) == 1) {
                ov49_0225EF8C(controller, 3);
            } else {
                ov49_0225EF8C(controller, 5);
            }
        }
        break;
    case 3:
        ov49_0225A37C(work, data[4], 0);
        ov49_0225A08C(work, ov49_0225A30C(work, 0, 8));
        ov49_0225EF90(controller);
        break;
    case 4:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225A0EC(work);
            ov49_0225EF90(controller);
        }
        break;
    case 5:
        ov49_02258EEC(object, entry, 1);
        controller = ov49_0225A010(work);
        ov49_0225EF98(controller, ov49_0225A02C(work), ov49_02269B38, 0);
        break;
    }

    return FALSE;
}

BOOL ov49_0225FCA8(void *controller, void *work, u32 arg) {
    void *selection = ov49_02259FE8(work);
    u16 *data = ov49_02259FEC(work);
    void *object = ov49_02259FF0(work);
    void *entry = ov49_02258DAC(object);

    switch (ov49_0225EF88(controller)) {
    case 0:
        ov49_0225F334(work, arg, data[0], data[1], 1);
        ov45_0222A520(selection, 0);
        ov49_0225EF90(controller);
        break;
    case 1:
        data = ov49_02259FEC(work);
        if (ov49_0225A030(work) == 0) {
            ov49_0225EF90(controller);
            ov49_02258EAC(object, entry, 2, data[2]);
        }
        break;
    case 2:
        if (ov49_02258E60(entry, 5) == 0) {
            ov49_0225A018(work, 1);
            if (ov45_0222A4B8(selection) == 1) {
                ov49_0225EF90(controller);
            } else {
                ov49_0225EF8C(controller, 5);
            }
        }
        break;
    case 3:
        ov49_0225A08C(work, ov49_0225A30C(work, 1, 0x5B));
        ov49_0225EF90(controller);
        break;
    case 4:
        if (ov49_0225A0AC(work) == 1) {
            ov49_0225A0EC(work);
            ov49_0225EF90(controller);
        }
        break;
    case 5:
        ov49_02258EEC(object, entry, 1);
        controller = ov49_0225A010(work);
        ov49_0225EF98(controller, ov49_0225A02C(work), ov49_02269B38, 0);
        break;
    }

    return FALSE;
}
