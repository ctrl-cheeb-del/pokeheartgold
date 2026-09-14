#include "global.h"

typedef struct Ov70R36 {
    u8 pad00[4];
    u8 *windows;
    u8 pad08[4];
    void *cursorSprite;
    void *rightSprite;
    void *leftSprite;
    u8 pad18[4];
    void *listMenu;
    u8 pad20[4];
    void *msgData;
    u8 pad28[0x34 - 0x28];
    struct Ov70Item *items;
    u8 pad38[0x48 - 0x38];
    s32 cursor;
    s32 state;
    s32 nextState;
    u8 pad54[0x5a - 0x54];
    s16 page;
    s32 count;
    s32 mode;
    u8 enabled[0x1a];
    u8 savedCursor;
} Ov70R36;

typedef struct Ov70SystemR36 {
    u8 pad00[0x48];
    u32 newKeys;
    u32 newAndRepeatedKeys;
} Ov70SystemR36;

extern Ov70SystemR36 gSystem;
extern const u8 ov70_02245D66[];
extern const u8 ov70_02245D67[];
extern const u8 ov70_02245D76[];
extern const u8 ov70_02245D77[];
extern const s32 ov70_02245DB0[];

void PlaySE(u16);
void Sprite_SetAnimCtrlSeq(void *, int);
void ov70_02238F9C(void *, int, int);
int ov70_02242164(Ov70R36 *, int);
int ov70_0224251C(Ov70R36 *, int);
void ov70_02242574(Ov70R36 *, int);

int ov70_0224261C(Ov70R36 *);
int ov70_022426F4(Ov70R36 *);

int ov70_0224261C(Ov70R36 *work) {
    int oldCursor = work->cursor;
    int input;

    if (gSystem.newAndRepeatedKeys & 0x40) {
        if (work->cursor != 0) {
            work->cursor--;
        } else {
            work->cursor = 4;
        }
    } else if (gSystem.newAndRepeatedKeys & 0x80) {
        if (work->cursor != 4) {
            work->cursor++;
        } else {
            work->cursor = 0;
        }
    } else if (gSystem.newAndRepeatedKeys & 0x20) {
        ov70_02242574(work, -1);
    } else if (gSystem.newAndRepeatedKeys & 0x10) {
        ov70_02242574(work, 1);
    }

    if (oldCursor != work->cursor) {
        int cursor;
        PlaySE(0x5dc);
        cursor = work->cursor;
        ov70_02238F9C(work->cursorSprite, ov70_02245D76[cursor * 2], ov70_02245D77[cursor * 2]);
        if (work->cursor == 4) {
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x30);
        } else {
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x31);
        }
    }

    input = ov70_02242164(work, 0);
    if (input != -1) {
        return ov70_0224251C(work, input);
    }
    if (gSystem.newKeys & 1) {
        return ov70_0224251C(work, work->cursor);
    }
    if (gSystem.newKeys & 2) {
        PlaySE(0x5dc);
        return -2;
    }
    return -1;
}

int ov70_022426F4(Ov70R36 *work) {
    int oldCursor = work->cursor;
    int input;

    if (gSystem.newAndRepeatedKeys & 0x40) {
        PlaySE(0x5dc);
        if (work->cursor != 0) {
            work->cursor--;
        } else {
            work->cursor = 3;
        }
    } else if (gSystem.newAndRepeatedKeys & 0x80) {
        PlaySE(0x5dc);
        if (work->cursor != 3) {
            work->cursor++;
        } else {
            work->cursor = 0;
        }
    }

    if (oldCursor != work->cursor) {
        int cursor = work->cursor;
        ov70_02238F9C(work->cursorSprite, ov70_02245D66[cursor * 2], ov70_02245D67[cursor * 2]);
        if (work->cursor == 3) {
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x30);
        } else {
            Sprite_SetAnimCtrlSeq(work->cursorSprite, 0x31);
        }
    }

    input = ov70_02242164(work, 1);
    if (input != -1) {
        PlaySE(0x5dc);
        return ov70_02245DB0[input];
    }
    if (gSystem.newKeys & 1) {
        PlaySE(0x5dc);
        return ov70_02245DB0[work->cursor];
    }
    if (gSystem.newKeys & 2) {
        PlaySE(0x5dc);
        return -2;
    }
    return -1;
}
