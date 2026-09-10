#include "overlay39_helpers_internal.h"

BOOL ov39_022280B4(void *a0, Ov39Ev *ev) {
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
