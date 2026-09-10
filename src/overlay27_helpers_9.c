#include "overlay_27_helpers_internal.h"

void ov27_0225BB38(Ov27Window *window, String *str, s32 a2) {
    u32 color = ov27_0225CEC4[a2];
    FillWindowPixelBuffer(window, color);
    AddTextPrinterParameterizedWithColor(window, 0, str, 3, 0, 0, color, 0);
}
