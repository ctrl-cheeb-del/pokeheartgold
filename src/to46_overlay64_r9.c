#include "to46_overlay64_r9_private.h"

int ov64_021E6B84(Ov64ShowcaseWork *work) {
    if (work->paletteTimer == 0) {
        ManagedSprite_SetPaletteOverride(work->sprites[work->selected], 1);
    } else if (work->paletteTimer == 4) {
        ManagedSprite_SetPaletteOverride(work->sprites[work->selected], 0);
    } else if (work->paletteTimer == 6) {
        work->paletteTimer = 0;
        return 0;
    }

    work->paletteTimer++;
    return 1;
}
