#include "field_map_object_render_internal.h"

void ov01_021F99A4(void *p, u32 id) {
    ov01_021FA1DC(p);
    ov01_021F98CC(p, *(void **)((u8 *)p + 0xf8), id, 0xff, ov01_02207294);
    ov01_021F9B10(p, id);
}

void ov01_021F99D0(void *p, u32 id) {
    ov01_021FA1DC(p);
    ov01_021F98CC(p, *(void **)((u8 *)p + 0xf8), id, 0xff, ov01_02207294);
    ov01_021F9B54(p, id);
}

void ov01_021F99FC(void *p, const u32 *ids) {
    while (*ids != 0xff) {
        ov01_021F99A4(p, *ids);
        ids++;
    }
}

void ov01_021F9A18(void *p, u32 id) {
    ov01_021FA1E4(p);
    ov01_021F98CC(p, *(void **)((u8 *)p + 0xfc), id, 0xff, ov01_022072CC);
    ov01_021F9C34(p, id);
}

void ov01_021F9A44(void *p, u32 id) {
    ov01_021FA1E4(p);
    ov01_021F98CC(p, *(void **)((u8 *)p + 0xfc), id, 0xff, ov01_022072CC);
    ov01_021F9C78(p, id);
}

void ov01_021F9A70(void *p, const u32 *ids) {
    while (*ids != 0xff) {
        ov01_021F9A18(p, *ids);
        ids++;
    }
}

void ov01_021F9A8C(void *p, void *a, void *b, void *c) {
    ov01_021F9980(p, a);
    ov01_021F99FC(p, b);
    ov01_021F9A70(p, c);
}

void ov01_021F9AAC(u32 *p, u32 value, u32 count) {
    do {
        *p++ = value;
    } while (--count != 0);
}

BOOL ov01_021F9AB4(u32 *p, u32 value, u32 old, u32 count) {
    do {
        if (*p == old) {
            *p = value;
            return TRUE;
        }
        p++;
    } while (--count != 0);
    return FALSE;
}

BOOL ov01_021F9AD0(u32 *p, u32 value, u32 count) {
    do {
        if (*p == value) {
            return TRUE;
        }
        p++;
    } while (--count != 0);
    return FALSE;
}

BOOL ov01_021F9AE4(u32 *p, u32 old, u32 value, u32 count) {
    do {
        if (*p == old) {
            *p = value;
            return TRUE;
        }
        p++;
    } while (--count != 0);
    return FALSE;
}

void ov01_021F9B00(void *p) {
    ov01_021F9AAC(ov01_021FA200(p), 0xff, 8);
}

void ov01_021F9B10(void *p, u32 value) {
    u32 count = (u32)ov01_021FA20C(p);
    u32 *a = ov01_021FA200(p);
    if (!ov01_021F9AB4(a, value, 0xff, count)) {
        GF_AssertFail();
    }
}

BOOL ov01_021F9B38(void *p, u32 value) {
    u32 count = (u32)ov01_021FA20C(p);
    u32 *a = ov01_021FA200(p);
    return ov01_021F9AD0(a, value, count);
}
