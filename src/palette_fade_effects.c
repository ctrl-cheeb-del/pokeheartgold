#include "palette_fade_effects_internal.h"

BOOL FadeFunc_00(FadeWork *work) {
    if (work->state == 0) {
        work->topScreen = 1;
        work->bottomScreen = 1;
        sub_02010B14(work);
        return 0;
    }
    return sub_02010BB4(work);
}
