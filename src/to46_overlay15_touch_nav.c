#include "global.h"

#include "system.h"
#include "touchscreen.h"

typedef struct BagWorkRaw {
    u8 raw[0x900];
} BagWorkRaw;
typedef struct TouchState {
    u8 pocket;
    u8 direction;
    u8 stage;
    u8 frame;
    u8 unk4;
    u8 pad5[2];
    u8 flags;
} TouchState;

extern s32 ov15_021FAC40(BagWorkRaw *);
extern BOOL ov15_021FAA18(BagWorkRaw *);
extern BOOL ov15_021FAB34(BagWorkRaw *);
extern void ov15_021FF950(BagWorkRaw *);
extern void ov15_021FF964(BagWorkRaw *);
extern void ov15_021FDAF4(void *, s32, s32);
extern void ov15_021F9F08(BagWorkRaw *);
extern s32 ov15_021FA074(BagWorkRaw *);
extern void ov15_021FF364(BagWorkRaw *, s32, s32, s32);
extern void ov15_021FD574(BagWorkRaw *, s32, s32, s32);
extern void ov15_02200030(BagWorkRaw *, s32);
extern void ov15_021FD404(BagWorkRaw *, s32, s32);
extern void ov15_021FA044(s16 *, u16 *, u8);
extern void ov15_021FA070(s16 *, u16 *, u8, s32);
extern void PlaySE(u16);
s32 ov15_021FA93C(BagWorkRaw *);
BOOL ov15_021FAA18(BagWorkRaw *);
BOOL ov15_021FAB34(BagWorkRaw *);

s32 ov15_021FA93C(BagWorkRaw *work) {
    TouchState *state = (TouchState *)&work->raw[0x619];
    s32 pocket;

    if (!System_GetTouchHeld()) {
        state->flags = (state->flags & ~0x70) | 0x10;
    }
    pocket = ov15_021FAC40(work);
    if (pocket == -1 || pocket != state->pocket) {
        state->flags = (state->flags & ~0xF) | 1;
    }
    if (!ov15_021FAA18(work) && (((u32)state->flags << 25) >> 29) == 1 && pocket != -1) {
        u8 current;
        (*(u8 **)&work->raw[0x234])[0x64] = state->pocket;
        current = state->pocket;
        if (current > (u8)pocket) {
            state->direction = 0;
            state->stage = 0;
        } else if (current < (u8)pocket) {
            state->direction = 1;
            state->stage = 0;
        } else {
            state->direction = 2;
        }
        state->pocket = pocket;
        state->flags &= ~0xF;
        state->flags &= ~0x70;
        state->unk4 = 0;
        work->raw[0x670] = pocket;
        ov15_021FF950(work);
        ov15_021FDAF4(&work->raw[0x808], work->raw[0x670] + 1, 7);
    }
    ov15_021FAB34(work);
    ov15_021FF964(work);
    return 0;
}

BOOL ov15_021FAA18(BagWorkRaw *work) {
    TouchState *state = (TouchState *)&work->raw[0x619];

    if (gSystem.newKeys & PAD_KEY_LEFT) {
        if (work->raw[0x614] == 1) {
            return TRUE;
        }
        PlaySE(0x5DC);
        (*(u8 **)&work->raw[0x234])[0x64] = state->pocket;
        if (state->pocket != 0) {
            state->pocket--;
            work->raw[0x670]--;
        } else {
            state->pocket = work->raw[0x614] - 1;
            work->raw[0x670] = work->raw[0x614] - 1;
        }
        state->stage = 0;
        state->direction = 0;
        state->flags = (state->flags & ~0x70) | 0x10;
        state->flags = (state->flags & ~0xF) | 1;
        state->flags &= ~0x80;
        if (state->unk4 != 3) {
            state->unk4 = 4;
        }
        ov15_021FF950(work);
        return TRUE;
    }
    if (gSystem.newKeys & PAD_KEY_RIGHT) {
        if (work->raw[0x614] == 1) {
            return TRUE;
        }
        PlaySE(0x5DC);
        (*(u8 **)&work->raw[0x234])[0x64] = state->pocket;
        if (state->pocket + 1 < work->raw[0x614]) {
            state->pocket++;
            work->raw[0x670]++;
        } else {
            state->pocket = 0;
            work->raw[0x670] = 0;
        }
        state->stage = 0;
        state->direction = 1;
        state->flags = (state->flags & ~0x70) | 0x10;
        state->flags = (state->flags & ~0xF) | 1;
        state->flags &= ~0x80;
        if (state->unk4 != 3) {
            state->unk4 = 4;
        }
        ov15_021FF950(work);
        return TRUE;
    }
    return FALSE;
}
