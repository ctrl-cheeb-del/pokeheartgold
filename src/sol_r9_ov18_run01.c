#include "sol_r9_ov18_private.h"

void ov18_021EE35C(Work18 *work, const void *templates, u32 count) {
    u32 i;
    const u8 *template = templates;
    for (i = 0; i < count; i++) {
        AddWindow(work->bgConfig, &work->windows[i], template);
        template += 8;
    }
}
