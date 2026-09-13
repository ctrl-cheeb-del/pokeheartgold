#include "to41_overlay_40_residual_29_unmatched_2_private.h"

#define BLEND(p, w) PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 0x1AC), (u16)WORD(p, 0x58))

void ov40_022371A0(void *p) {
    void *win;
    const u32 *fills = ov40_02245290;
    int i;
    for (i = 0, win = (u8 *)PTR(p, 0x860) + 0x1B4; i < 2; i++) {
        FillWindowPixelBuffer(win, (u8)*fills);
        ScheduleWindowCopyToVram(win);
        win = (u8 *)win + 0x10;
        fills++;
    }
}
