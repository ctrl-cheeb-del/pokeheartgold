#include "r40_overlay_73_residual_3_private.h"

void ov73_021E629C(void *p) {
    AddWindowParameterized(PTR(p, 0), (u8 *)p + 0x2A8, 0, 2, 1, 0x1B, 4, 0xC, 0x5B);
    FillWindowPixelBuffer((u8 *)p + 0x2A8, 0xF);
    AddWindowParameterized(PTR(p, 0), (u8 *)p + 0x2B8, 0, 0x10, 0x15, 8, 2, 9, 0xC7);
    FillWindowPixelBuffer((u8 *)p + 0x2B8, 0);
    AddWindowParameterized(PTR(p, 0), (u8 *)p + 0x2C8, 0, 0x18, 0x15, 8, 2, 9, 0x133);
    FillWindowPixelBuffer((u8 *)p + 0x2C8, 0);
    AddWindowParameterized(PTR(p, 0), (u8 *)p + 0x2D8, 4, 3, 1, 0x1A, 2, 9, 1);
    ov73_021E63BC((u8 *)p + 0x2D8, PTR(p, 0x48), 0);
    AddWindowParameterized(PTR(p, 0), (u8 *)p + 0x298, 4, 8, 7, 0x10, 0xB, 9, 0x35);
    FillWindowPixelBuffer((u8 *)p + 0x298, 0);
    ov73_021E735C((u8 *)p + 0x298, 0, 0x10300, p);
    PTR(p, 0x2E8) = YesNoPrompt_Create(0x32);
}
