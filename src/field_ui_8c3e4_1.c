#include "field_ui_8c3e4_internal.h"

void sub_0208C4E0(SummaryState *state) {
    u32 i;
    switch (S8(state, 0x7bc)) {
    case 0:
    case 1:
        for (i = 0; i < U32(state, 0x228); i++) {
            ClearWindowTilemapAndCopyToVram(&PTR(state, 0x224, Window)[i]);
        }
        break;
    case 2:
        ClearWindowTilemapAndCopyToVram(PTR(state, 0x224, Window));
        break;
    case 3:
        if (U8((SummaryState *)PTR(state, 0x22c, void), 0x12) != 3 && U8((SummaryState *)PTR(state, 0x22c, void), 0x12) != 4) {
            return;
        }
        break;
    default:
        return;
    }
    WindowArray_Delete(PTR(state, 0x224, Window), U32(state, 0x228));
}

void sub_0208C560(SummaryState *state) {
    u32 i;
    Window *window;
    sub_0208C4E0(state);
    for (i = 0, window = (Window *)&state->raw[4]; i < 34; i++, window++) {
        RemoveWindow(window);
    }
}
