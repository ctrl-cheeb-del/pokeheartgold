#include "overlay_27_helpers_internal.h"

BOOL ov27_0225CA68(Ov27Timer *p, s32 a1, const s8 *a2) {
    s32 cur = p->unk00;
    s32 idx = a1 - 2;
    s32 off = ov27_0225D480[idx] + cur * 4;
    s8 next = a2[off];
    if (next == -1 || cur == next) {
        return FALSE;
    }
    p->unk00 = next;
    return TRUE;
}
