#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

void ov40_0223707C(void *p) {
    void *w = PTR(p, 0x860);
    void *tmpl = NewString_ReadMsgData(PTR(p, 0x48), WORD(w, 0x380) + 0x1C);
    void *name = String_New(0xFF, 0x6D);
    void *expanded = String_New(0xFF, 0x6D);
    void *fmt = ov40_0222DAB0(0x6D);
    void *win = (u8 *)w + 0x1D4;
    CopyU16ArrayToString(name, (u16 *)PTR((u8 *)w + WORD(p, 0x4D4) * 4, 0x38C));
    ov40_02230DCC(p, name);
    BufferString(fmt, 0, name, 0, 1, 2);
    StringExpandPlaceholders(fmt, expanded, tmpl);
    FillWindowPixelBuffer(win, 0xCC);
    AddTextPrinterParameterizedWithColor(win, 0, expanded, 0, 0, 0xFF, 0xF0D00, NULL);
    ScheduleWindowCopyToVram(win);
    String_Delete(tmpl);
    String_Delete(name);
    String_Delete(expanded);
    MessageFormat_Delete(fmt);
}
