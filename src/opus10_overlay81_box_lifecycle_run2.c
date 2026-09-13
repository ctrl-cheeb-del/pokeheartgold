#include "opus10_overlay81_box_lifecycle_private.h"

BOOL ov81_0223DD60(void *man, u32 *state);
BOOL ov81_0223DEA8(void *man, u32 *state);
BOOL ov81_0223E234(void *man, u32 *state);
BOOL ov81_0223E318(u8 *p);
void ov81_0223E5B4(u8 *p);
void ov81_0223E87C(u8 *p);

BOOL ov81_0223E520(u8 *p) {
    switch (p[8]) {
    case 0:
        if (ov81_02240F08(p, 0) == 1) {
            ov81_0223E5B4(p);
        } else {
            ov81_0223E8BC(p);
        }
        if (ov80_02237254(p[9]) == 1) {
            ov81_0224093C(p, p + 0x60, 0, 0, 0);
            GfGfx_EngineATogglePlanes(4, 1);
        }
        if (BIT(p[0x13], 4) == 1) {
            BeginNormalPaletteFade(0, 1, 1, 0, 6, 3, 0x64);
        }
        p[0x13] |= 0x10;
        p[8]++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == 1) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}
