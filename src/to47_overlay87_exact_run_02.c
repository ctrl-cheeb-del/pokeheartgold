#include "to47_overlay87_private.h"

int ov87_021E65FC(u8 *p) {
    switch (p[8]) {
    case 0:
        p[13] = 10;
        p[8]++;
        break;
    case 1:
        p[13]--;
        if (p[13] == 0) {
            ClearFrameAndWindow2(p + 0x5c, 0);
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x7a);
            p[8]++;
        }
        break;
    case 2:
        if (IsPaletteFadeFinished() == 1) {
            return 1;
        }
        break;
    }
    return 0;
}
