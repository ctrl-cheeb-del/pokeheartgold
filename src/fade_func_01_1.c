#include "fade_func_01_internal.h"

BOOL FadeFunc_01(FadeWork *work) {
    if (work->state == 0) {
        work->topScreen = 0;
        work->bottomScreen = 1;
        sub_02010B14(work, 0, 1);
        return FALSE;
    }
    return sub_02010BB4(work);
}
