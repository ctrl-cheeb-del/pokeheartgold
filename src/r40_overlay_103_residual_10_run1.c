#include "global.h"

#include "r40_overlay_103_residual_10_private.h"

u32 ov103_021ED5B4(R40Ov103Work *work) {
    u32 input;
    switch (ov103_021EEA24(work)) {
    case 0:
        if (work->row != 0) {
            work->row--;
            PlaySE(0x5DC);
            return ov103_021EDB18(work, 0, 11);
        } else {
            return 9;
        }
    case 1:
        if (work->row != *(u16 *)(work->ctx + 0x2E2)) {
            work->row++;
            PlaySE(0x5DC);
            return ov103_021EDB18(work, 1, 11);
        } else {
            return 9;
        }
    }
    input = GridInputHandler_HandleInput_NoHold(*(void **)(work->ctx + 0x278));
    switch (input) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        if (work->ctx[input + work->row * 10 + 0x2CC] != 0xFF) {
            work->col = input;
            work->value = work->ctx[input + work->row * 10 + 0x2CC];
            PlaySE(0x5DD);
            return ov103_021EDA98(work, input, 12);
        }
        break;
    case 10:
    case -2:
        PlaySE(0x5DD);
        return ov103_021EDB18(work, 3, 10);
    case -1:
        input = GridInputHandler_GetNextInput(*(void **)(work->ctx + 0x278));
        if ((gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) && (input == 1 || input == 3 || input == 5 || input == 7 || input == 9) && work->row != *(u16 *)(work->ctx + 0x2E2)) {
            work->row++;
            PlaySE(0x5DC);
            return ov103_021EDB18(work, 1, 11);
        }
        if ((gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) && (input == 0 || input == 2 || input == 4 || input == 6 || input == 8) && work->row != 0) {
            work->row--;
            PlaySE(0x5DC);
            return ov103_021EDB18(work, 0, 11);
        }
        break;
    case -3:
        PlaySE(0x5DC);
        break;
    case -4:
        break;
    }
    return 9;
}
