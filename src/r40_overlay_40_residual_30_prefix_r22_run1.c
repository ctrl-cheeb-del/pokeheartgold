#include "r40_overlay_40_residual_30_prefix_r22_private.h"

void ov40_022371E4(void *p, int index) {
    u16 name[0x100];
    void *ctx = PTR(p, 0x860);
    void *window = (u8 *)ctx + 0x1B4;
    void *entry;
    u16 species;
    void *str;
    int x;
    FillWindowPixelBuffer(window, 0);
    entry = (u8 *)ctx + index * 2;
    species = U16(entry, 0x2C);
    if (species == 0) {
        ScheduleWindowCopyToVram(window);
        return;
    }
    str = String_New(0xFF, 0x6D);
    if (ov40_022371D4(PTR(ctx, 0x158), 1 << U32(ctx, 0x1B0)) == 1) {
        species = 0x1EE;
    }
    GetSpeciesNameIntoArray(species, 0x6D, name);
    CopyU16ArrayToString(str, name);
    x = ov40_022306C0(window, str);
    AddTextPrinterParameterizedWithColor(window, 0, str, x, 6, 0xFF, 0xF0D00, 0);
    ScheduleWindowCopyToVram(window);
    String_Delete(str);
}
