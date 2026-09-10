#include "field_map_object_render_internal.h"

int ov01_021F9EC4(void *p, u32 v) {
    if (ov01_021F9D88(p, v) == 1) {
        return 0;
    }
    if (ov01_021F9E9C(p, v) == 1) {
        return 1;
    }
    return 2;
}

int ov01_021F9EEC(void *p, u32 v) {
    if (ov01_021F9B38(p, v) == 1) {
        return 0;
    }
    if (ov01_021F9B84(p, v) == 1) {
        return 1;
    }
    return 2;
}

int ov01_021F9F14(void *p, u32 v) {
    if (ov01_021F9C5C(p, v) == 1) {
        return 0;
    }
    if (ov01_021F9CA8(p, v) == 1) {
        return 1;
    }
    return 2;
}

void ov01_021F9F3C(void *p, void *arg) {
    if (ov01_021F9DA4(p, (u32)arg) == 0) {
        ov01_021F9974(p, (u32)arg);
    }
}

void ov01_021F9F54(void *p, void *arg) {
    if (ov01_021F9EEC(p, (u32)arg) == 2) {
        ov01_021F99D0(p, (u32)arg);
    }
}

void ov01_021F9F6C(void *p, void *arg) {
    if (ov01_021F9F14(p, (u32)arg) == 2) {
        ov01_021F9A44(p, (u32)arg);
    }
}

void ov01_021F9F84(void *p, void *obj) {
    ov01_021F9F54(p, (void *)(u32)ov01_021FA28C((u32)obj));
    ov01_021F9F6C(p, (void *)(u32)ov01_021FA2A0((u32)obj));
    ov01_021F9F3C(p, obj);
}

void ov01_021F9FB0(void *p, void *arg) {
    ov01_021F9BD4(p, arg);
    ov01_021F9CF8(p, arg);
    ov01_021F9E30(p, arg);
}
