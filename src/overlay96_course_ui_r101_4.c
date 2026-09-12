#include "overlay96_course_ui_r101_private.h"

void ov96_0220EFD0(u8 *state, void *bgConfig, u32 heapId) {
    if (state == NULL) {
        GF_AssertFail();
    }
    if (bgConfig == NULL) {
        GF_AssertFail();
    }

    state[0]++;
    if (state[0] >= 4) {
        GfGfxLoader_LoadScrnData(0xed, state[1] + 5, bgConfig, 0, 0, 0, 1, heapId);
        GfGfxLoader_LoadScrnData(0xed, state[1] + 5, bgConfig, 4, 0, 0, 1, heapId);
        state[1] = (u8)((state[1] + 1) % 6);
        state[0] = 0;
    }
}
