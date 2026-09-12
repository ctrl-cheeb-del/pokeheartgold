#include "overlay96_course_results_r62_private.h"

int ov96_021F7740(void *course, Ov96CycleWork *state) {
    int slot;
    int result = 4;

    if (state->disabled == 4) {
        return 0;
    }
    state->tick++;
    for (slot = state->firstSlot; slot < 4; slot++) {
        *(u32 *)ov96_021E8A20(state->data + 0x50 + slot * 0x28) = 0;
    }
    if (state->tick >= state->tickLimit) {
        state->active = 1;
        state->tick = 0;
    }
    if (state->active != 0) {
        slot = state->firstSlot + state->itemIndex;
        if (slot < state->firstSlot) {
            GF_AssertFail();
        }
        if (slot < state->firstSlot) {
            return 4;
        }
        ov96_021F77EC(course, state, (u8)slot);
        result = (u8)slot;
        state->itemIndex++;
        if (state->itemIndex >= state->itemCount) {
            state->itemIndex = 0;
            state->active = 0;
        }
    }
    return result;
}

void ov96_021F77EC(void *course, Ov96CycleWork *state, u8 slot) {
    int value;
    u8 roll;
    u8 i;
    u32 *status = ov96_021E8A20(state->data + 0x50 + slot * 0x28);

    if (state->counts[slot] == 0) {
        value = 0;
    } else {
        value = state->base[slot] + state->counts[slot] * 2 + LCRandom() % 101;
    }
    if (value >= 100) {
        *status = 1;
        roll = LCRandom() % state->counts[slot];
        for (i = 0; i < 3; i++) {
            if (roll < state->thresholds[slot * 3 + i]) {
                ov96_021E8228(course, slot, i, 3, 1);
                break;
            }
        }
        if (i >= 3) {
            GF_AssertFail();
        }
    }
}

void ov96_021F7878(void *bgConfig, void *window, int heapId) {
    if (window == NULL) {
        GF_AssertFail();
    }
    AddWindow(window, bgConfig, ov96_0221C2A0);
    BG_FillCharDataRange(window, 1, 0, 1, 0);
    LoadFontPal0(0, 0x1e0, heapId);
    LoadFontPal0(6, 0x4000, heapId);
}

void ov96_021F78C4(void *window, int heapId) {
    void *msgData;
    void *format;
    void *string;

    FillWindowPixelBuffer(window, 0);
    msgData = NewMsgDataFromNarc(1, 0x1b, 0x135, heapId);
    format = MessageFormat_New(heapId);
    string = ReadMsgData_ExpandPlaceholders(format, msgData, 0x12f, heapId);
    AddTextPrinterParameterizedWithColor(window, 0, string, 0, 0, 0xff, 0x10200, NULL);
    String_Delete(string);
    MessageFormat_Delete(format);
    DestroyMsgData(msgData);
    CopyWindowToVram(window);
}
