#include "overlay39_helpers_internal.h"

BOOL ov39_02227F60(void *a0, Ov39Ev *ev) {
    BOOL ret = FALSE;
    switch (ev->kind) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
        break;
    }
    return ret;
}

void ov39_02227F74(void *a0, void **out) {
    Ov39Blk *blk = ov39_0222A2B4(a0);
    *out = &blk->f4;
}

BOOL ov39_02227F84(void *a0, Ov39Ev *ev) {
    BOOL ret = FALSE;
    switch (ev->kind) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    }
    return ret;
}

void ov39_02227FA8(void *a0, void **out1, void **out2) {
    u8 *p = (u8 *)&ov39_0222A2B4(a0)->f4;
    *out1 = p;
    *out2 = p + 0x558;
}

BOOL ov39_02227FC4(void *a0, Ov39Ev *ev) {
    BOOL ret = FALSE;
    switch (ev->kind) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
    return ret;
}
