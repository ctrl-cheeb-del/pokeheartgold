#include "to41_overlay_96_residual_93_private.h"

void ov96_02209F14(u8 *p) {
    ov96_02209F40((u8 *)p + 0x218, PTR(p, 0x25c), U32(p, 0x258), 0x12d, U32(p, 0));
    ov96_02209E70(p);
}

void ov96_02209F40(void *w, void *a, u32 b, u32 c, u32 d) {
    void *s;
    FillWindowPixelBuffer(w, 0);
    s = ReadMsgData_ExpandPlaceholders(a, b, c, d);
    AddTextPrinterParameterizedWithColor(w, 0, s, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(s);
    CopyWindowToVram(w);
}
