#include "overlay70_menu_helpers_private.h"

int ov70_02242B5C(Ov70R36 *work, int input) {
    int index;
    switch (input) {
    case 5:
        PlaySE(0x5dc);
        return -2;
    case 6:
        ov70_02242BBC(work, -1);
        return -1;
    case 7:
        ov70_02242BBC(work, 1);
        return -1;
    }
    index = input + work->page * 5;
    if (index < work->count) {
        PlaySE(0x5dc);
        return work->items[index].value;
    }
    return -1;
}

void ov70_02242BBC(Ov70R36 *work, int direction) {
    int last = ov70_02242508(work->count, 5) - 1;
    int total;
    if (last == 0) {
        return;
    }
    if (direction < 0) {
        PlaySE(0x5e0);
        Sprite_SetAnimActiveFlag(work->leftSprite, 1);
        Sprite_SetAnimCtrlSeq(work->leftSprite, 0x27);
        if (work->page != 0) {
            work->page--;
        } else {
            work->page = last;
        }
    } else {
        PlaySE(0x5e0);
        Sprite_SetAnimActiveFlag(work->rightSprite, 1);
        Sprite_SetAnimCtrlSeq(work->rightSprite, 0x26);
        if (work->page < last) {
            work->page++;
        } else {
            work->page = 0;
        }
    }
    ov70_0224352C(work, work->page, work->count);
    total = ov70_02242508(work->count, 5);
    ov70_02243F00(work->listMenu, PTR(work, 0x38), work->windows + 0x50, work->page, total);
}

int ov70_02242C64(Ov70R36 *work) {
    int oldCursor = work->cursor;
    int input;

    if (gSystem.newAndRepeatedKeys & 0x40) {
        PlaySE(0x5dc);
        if (work->cursor != 0) {
            work->cursor--;
        } else {
            work->cursor = 5;
        }
    } else if (gSystem.newAndRepeatedKeys & 0x80) {
        PlaySE(0x5dc);
        if (work->cursor != 5) {
            work->cursor++;
        } else {
            work->cursor = 0;
        }
    } else if (gSystem.newAndRepeatedKeys & 0x20) {
        ov70_02242BBC(work, -1);
    } else if (gSystem.newAndRepeatedKeys & 0x10) {
        ov70_02242BBC(work, 1);
    }

    if (oldCursor != work->cursor) {
        int cursor = work->cursor;
        ov70_02238F9C(work->cursorSprite, ov70_02245D8A[cursor * 2], ov70_02245D8B[cursor * 2]);
        if (work->cursor == 5) {
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x30);
        } else {
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x32);
        }
    }

    input = ov70_02242164(work, 3);
    if (input != -1) {
        return ov70_02242B5C(work, input);
    }
    if (gSystem.newKeys & 1) {
        return ov70_02242B5C(work, work->cursor);
    }
    if (gSystem.newKeys & 2) {
        PlaySE(0x5dc);
        return -2;
    }
    return -1;
}
