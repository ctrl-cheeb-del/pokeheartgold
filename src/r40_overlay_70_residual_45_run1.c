#include "r40_overlay_70_residual_45_private.h"

void ov70_0224512C(Ov70State *state, int msgNo) {
    void *tmp = String_New(0x100, 0x3D);
    ReadMsgDataIntoString(PTR(state, 0xBAC), msgNo, tmp);
    StringExpandPlaceholders(PTR(state, 0xB9C), PTR(state, 0xBEC), tmp);
    FillWindowPixelBuffer(state->raw + 0xF48, 0xF);
    DrawFrameAndWindow1(state->raw + 0xF48, 1, 0x1F, 0xB);
    U32(state, 0xBF0) = AddTextPrinterParameterized(state->raw + 0xF48, 1, PTR(state, 0xBEC), 0, 0, 0, NULL);
    String_Delete(tmp);
}

void ov70_022451A8(Ov70State *state, int msgNo, int value) {
    if (msgNo == -1) {
        msgNo = 0xB;
    }
    BufferIntegerAsString(PTR(state, 0xB9C), 0, value, 5, 2, 1);
    ClearFrameAndWindow2(state->raw + 0xF18, 1);
    ov70_0224512C(state, msgNo);
}
