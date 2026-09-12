#include "overlay45_state_accessors_r5_private.h"

int ov45_0222A2CC(void *p) {
    GF_ASSERT(p != NULL);
    return ov45_0222ECDC(4);
}

u32 ov45_0222A2E0(Overlay45State *p) {
    GF_ASSERT(p != NULL);
    return p->low;
}

u32 ov45_0222A2F8(Overlay45State *p) {
    GF_ASSERT(p != NULL);
    return p->high;
}

void ov45_0222A310(Overlay45State *p) {
    p->high = 1;
}

u32 ov45_0222A324(Overlay45State *p) {
    return p->flag0;
}
u32 ov45_0222A330(Overlay45State *p) {
    return p->flag7;
}

BOOL ov45_0222A33C(Overlay45State *p) {
    if (p->flag1 == 1 && p->value_200 <= 0) {
        return TRUE;
    }
    return FALSE;
}

u32 ov45_0222A35C(Overlay45State *p) {
    if (p->value_204 <= 0) {
        return p->mode2;
    }
    return 0;
}

BOOL ov45_0222A374(Overlay45State *p) {
    if (p->flag4 == 1 && p->value_206 <= 0) {
        return TRUE;
    }
    return FALSE;
}

u32 ov45_0222A394(Overlay45State *p) {
    return p->mode5;
}

BOOL ov45_0222A3A0(Overlay45State *p) {
    if (p->unk_008 == 1 && p->value_202 <= 0) {
        return TRUE;
    }
    return FALSE;
}

u32 ov45_0222A3BC(Overlay45State *p) {
    if (p->value_202 <= 0) {
        return p->value_1fd;
    }
    return 1;
}

u32 ov45_0222A3D4(Overlay45State *p) {
    if (p->value_202 <= 0) {
        return p->value_1fe;
    }
    return 7;
}

u32 ov45_0222A3EC(Overlay45State *p) {
    if (p->value_202 <= 0) {
        return p->value_1ff;
    }
    return 11;
}
