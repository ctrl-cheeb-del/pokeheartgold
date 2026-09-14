#include "overlay49_r62_state_machine_internal.h"

typedef struct Ov49R62MenuWork {
    u32 nextState;
    u8 menu[0x24];
} Ov49R62MenuWork;

#define SHOW_MESSAGE(ctx, work, message, next)                    \
    do {                                                          \
        ov49_0225A08C((ctx), ov49_0225A30C((ctx), 1, (message))); \
        (work)->nextState = (next);                               \
    } while (0)

BOOL ov49_022644E8(void *state, void *ctx) {
    Ov49R62MenuWork *work = ov49_0225EF84(state);
    void *object = ov49_02259FE8(ctx);
    u32 selected;
    u32 choice;

    switch (ov49_0225EF88(state)) {
    case 0:
        ov49_0225EF40(state, 0x28);
        PlaySE(0x5DC);
        if (ov45_0222A330(object) == 1) {
            ov49_0225EF8C(state, 2);
        } else if (ov45_0222A374(object) == 1) {
            ov49_0225EF8C(state, 1);
        } else {
            ov49_0225EF8C(state, 3);
        }
        break;
    case 1:
        SHOW_MESSAGE(ctx, work, 0x4E, 0x18);
        ov49_0225EF8C(state, 0x17);
        break;
    case 2:
        SHOW_MESSAGE(ctx, work, 3, 0x18);
        ov49_0225EF8C(state, 0x17);
        break;
    case 3:
        SHOW_MESSAGE(ctx, work, 0xF, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 4:
        SHOW_MESSAGE(ctx, work, 0x10, 5);
        ov49_0225EF8C(state, 0x17);
        break;
    case 5:
        ov49_02265110(work->menu, ctx);
        ov49_0225A1A4(ctx, work->menu, 0, 0, 0x10, 1, 0xF);
        ov49_0225EF8C(state, 6);
        break;
    case 6:
        selected = FALSE;
        choice = ov49_0225A1D4(ctx);
        switch (choice) {
        default:
            if (choice == (u32)-2) {
                goto cancel_menu1;
            }
            break;
        case 0:
            ov49_0225EF8C(state, 7);
            selected = TRUE;
            break;
        case 1:
            ov49_0225EF8C(state, 8);
            selected = TRUE;
            break;
        case 2:
            ov49_0225EF8C(state, 0xD);
            selected = TRUE;
            break;
        case 3:
            ov49_0225EF8C(state, 0xE);
            selected = TRUE;
            break;
        case 4:
            ov49_0225EF8C(state, 0xF);
            selected = TRUE;
            break;
        case 5:
            ov49_0225EF8C(state, 0x15);
            selected = TRUE;
            break;
        case 6:
            ov49_0225EF8C(state, 0x10);
            selected = TRUE;
            break;
cancel_menu1:
            PlaySE(0x5DC);
        case 7:
            ov49_0225EF8C(state, 0x16);
            selected = TRUE;
            break;
        }
        if (selected == TRUE) {
            ov49_0225A1E4(ctx, 0, 0);
            ov49_02265260(work->menu, ctx);
        }
        break;
    case 7:
        SHOW_MESSAGE(ctx, work, 0x17, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 8:
        ov49_022651E8(work->menu, ctx);
        ov49_0225A174(ctx, work->menu, 0, 0);
        ov49_0225EF8C(state, 9);
        break;
    case 9:
        selected = FALSE;
        choice = ov49_0225A1D4(ctx);
        switch (choice) {
        default:
            if (choice == (u32)-2) {
                goto cancel_menu2;
            }
            break;
        case 0:
            ov49_0225EF8C(state, 0xA);
            selected = TRUE;
            break;
        case 1:
            ov49_0225EF8C(state, 0xB);
            selected = TRUE;
            break;
        case 2:
            ov49_0225EF8C(state, 0xC);
            selected = TRUE;
            break;
cancel_menu2:
            PlaySE(0x5DC);
        case 3:
            ov49_0225EF8C(state, 4);
            selected = TRUE;
            break;
        }
        if (selected == TRUE) {
            ov49_0225A1E4(ctx, 0, 0);
            ov49_02265260(work->menu, ctx);
        }
        break;
    case 10:
        ov49_0225A37C(ctx, 0, 0);
        SHOW_MESSAGE(ctx, work, 0x18, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 11:
        ov49_0225A37C(ctx, 1, 0);
        SHOW_MESSAGE(ctx, work, 0x19, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 12:
        ov49_0225A37C(ctx, 2, 0);
        SHOW_MESSAGE(ctx, work, 0x1A, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 13:
        SHOW_MESSAGE(ctx, work, 0x12, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 14:
        SHOW_MESSAGE(ctx, work, 0x13, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 15:
        SHOW_MESSAGE(ctx, work, 0x14, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 16:
        ov49_02265170(work->menu, ctx);
        ov49_0225A174(ctx, work->menu, 0, 0);
        ov49_0225EF8C(state, 0x11);
        break;
    case 17:
        selected = FALSE;
        choice = ov49_0225A1D4(ctx);
        switch (choice) {
        default:
            if (choice == (u32)-2) {
                goto cancel_menu3;
            }
            break;
        case 0:
            ov49_0225EF8C(state, 0x12);
            selected = TRUE;
            break;
        case 1:
            ov49_0225EF8C(state, 0x13);
            selected = TRUE;
            break;
        case 2:
            ov49_0225EF8C(state, 0x14);
            selected = TRUE;
            break;
cancel_menu3:
            PlaySE(0x5DC);
        case 3:
            ov49_0225EF8C(state, 4);
            selected = TRUE;
            break;
        }
        if (selected == TRUE) {
            ov49_0225A1E4(ctx, 0, 0);
            ov49_02265260(work->menu, ctx);
        }
        break;
    case 18:
        SHOW_MESSAGE(ctx, work, 0x1B, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 19:
        SHOW_MESSAGE(ctx, work, 0x1C, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 20:
        SHOW_MESSAGE(ctx, work, 0x1D, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 21:
        SHOW_MESSAGE(ctx, work, 0x1E, 4);
        ov49_0225EF8C(state, 0x17);
        break;
    case 22:
        SHOW_MESSAGE(ctx, work, 0x16, 0x18);
        ov49_0225EF8C(state, 0x17);
        break;
    case 23:
        if (ov49_0225A0AC(ctx)) {
            ov49_0225EF8C(state, work->nextState);
        }
        break;
    case 24:
        ov49_0225EF68(state);
        ov49_0225A0EC(ctx);
        ctx = ov49_02259FF0(ctx);
        ov49_02258EEC(ctx, ov49_02258DAC(ctx), 1);
        return TRUE;
    }
    return FALSE;
}
