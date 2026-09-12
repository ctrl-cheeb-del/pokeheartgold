#include "overlay83_summary_display_r20_private.h"

void ov83_02241FF0(u8 *work) {
    FillWindowPixelBuffer(work + 0x190, 0);
    FillWindowPixelBuffer(work + 0x1B0, 0);
    FillWindowPixelBuffer(work + 0x1D0, 0);
    FillWindowPixelBuffer(work + 0x1F0, 0);
    FillWindowPixelBuffer(work + 0x210, 0);
    FillWindowPixelBuffer(work + 0x230, 0);
    FillWindowPixelBuffer(work + 0x250, 0);
    FillWindowPixelBuffer(work + 0x270, 0);
    FillWindowPixelBuffer(work + 0x290, 0);
    FillWindowPixelBuffer(work + 0x2B0, 0);
    ov83_022479E4(work + 0x190, *(void **)(work + 0x20), 0x58, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x1B0, *(void **)(work + 0x20), 0x4A, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x1D0, *(void **)(work + 0x20), 0x48, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x1F0, *(void **)(work + 0x20), 0x46, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x210, *(void **)(work + 0x20), 0x59, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x230, *(void **)(work + 0x20), 0x4C, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x250, *(void **)(work + 0x20), 0x50, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x270, *(void **)(work + 0x20), 0x4E, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x290, *(void **)(work + 0x20), 0x52, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x2B0, *(void **)(work + 0x20), 0x54, 0, 0, 0, 0x10200, 0);
    CopyWindowPixelsToVram_TextMode(work + 0x190);
    CopyWindowPixelsToVram_TextMode(work + 0x1B0);
    CopyWindowPixelsToVram_TextMode(work + 0x1D0);
    CopyWindowPixelsToVram_TextMode(work + 0x1F0);
    CopyWindowPixelsToVram_TextMode(work + 0x210);
    CopyWindowPixelsToVram_TextMode(work + 0x230);
    CopyWindowPixelsToVram_TextMode(work + 0x250);
    CopyWindowPixelsToVram_TextMode(work + 0x270);
    CopyWindowPixelsToVram_TextMode(work + 0x290);
    CopyWindowPixelsToVram_TextMode(work + 0x2B0);
}
