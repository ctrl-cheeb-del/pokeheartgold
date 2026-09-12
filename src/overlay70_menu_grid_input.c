#include "overlay70_menu_helpers_private.h"

int ov70_022429B8(Ov70R36 *work, const u8 *enabled) {
    int oldCursor = work->cursor;
    int input;

    if (oldCursor < 9) {
        work->savedCursor = oldCursor;
    }
    if (gSystem.newAndRepeatedKeys & 0x40) {
        work->cursor = ov70_02245EFC[work->cursor * 4];
    } else if (gSystem.newAndRepeatedKeys & 0x80) {
        work->cursor = ov70_02245EFD[work->cursor * 4];
    } else if (gSystem.newAndRepeatedKeys & 0x20) {
        work->cursor = ov70_02245EFE[work->cursor * 4];
    } else if (gSystem.newAndRepeatedKeys & 0x10) {
        work->cursor = ov70_02245EFF[work->cursor * 4];
    }

    if (oldCursor >= 9 && work->cursor < 9) {
        if (gSystem.newAndRepeatedKeys & 0x40) {
            work->cursor = work->savedCursor;
            if (work->cursor + 4 < 9) {
                do {
                    work->cursor += 4;
                } while (work->cursor + 4 < 9);
            }
        } else if (gSystem.newAndRepeatedKeys & 0x80) {
            work->cursor = work->savedCursor;
            if (work->cursor - 4 >= 0) {
                do {
                    work->cursor -= 4;
                } while (work->cursor - 4 >= 0);
            }
        }
    }

    if (oldCursor != work->cursor) {
        int cursor;
        PlaySE(0x5dc);
        cursor = work->cursor;
        ov70_02238F9C(work->cursorSprite, (ov70_02245DF8[cursor * 2] + 0x10) << 3, ov70_02245DF9[cursor * 2] << 3);
        switch (work->cursor) {
        case 9:
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x30);
            break;
        case 10:
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x31);
            break;
        default:
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x3d);
            break;
        }
    }

    input = ov70_02242164(work, 6);
    if (input != -1) {
        input = ov70_022429A0(work, input);
        if (input == -2 || input == 11 || enabled == NULL || enabled[input] != 0) {
            PlaySE(0x5dc);
            return input;
        }
    } else if (gSystem.newKeys & 1) {
        input = ov70_022429A0(work, work->cursor);
        if (input == -2 || input == 11 || enabled == NULL || enabled[input] != 0) {
            PlaySE(0x5dc);
            return input;
        }
    } else if (gSystem.newKeys & 2) {
        PlaySE(0x5dc);
        return -2;
    }
    return -1;
}
