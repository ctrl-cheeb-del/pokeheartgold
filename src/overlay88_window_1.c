#include "overlay88_window_internal.h"

int ov88_022590D8(Ov88Small *p, void *arg) {
    int ret = 0;
    switch (ov45_0222DD38(arg)) {
    case 0:
        break;
    case 1:
        ret = 1;
        p->state = ret;
        break;
    case 2:
        p->state = 3;
        ret = 1;
        break;
    default:
        break;
    }
    return ret;
}

void ov88_02259104(Ov88Small *p, void *a, void *b, void *c, void *d) {
    switch (p->state) {
    case 1:
        p->state = 2;
        p->frame = 0;
        return;
    case 2:
        ov88_02259244(a, b, c, d, p->frame);
        p->frame++;
        if (p->frame >= 32) {
            p->state = 0;
            return;
        }
        break;
    case 3:
        p->state = 4;
        p->frame = 0;
        return;
    case 4:
        ov88_02259264(a, b, c, d, p->frame);
        p->frame++;
        if (p->frame >= 32) {
            p->state = 0;
        }
        break;
    }
}
