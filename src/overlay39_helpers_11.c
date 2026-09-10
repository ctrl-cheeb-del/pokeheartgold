#include "overlay39_helpers_internal.h"

void ov39_02227E3C(void) {
    OS_ClearAlloc((OSArenaId)0);
}

BOOL ov39_02227E48(void *a0, Ov39Ev *ev) {
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

BOOL ov39_02227E6C(void *a0, Ov39Ev *ev) {
    BOOL ret = FALSE;
    switch (ev->kind) {
    case 0:
        ret = TRUE;
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    return ret;
}
