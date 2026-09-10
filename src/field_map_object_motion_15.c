#include "field_map_object_motion_internal.h"

void ov01_021F8BA8(void *u, void *o, const s8 *s, int i) {
    LocalMotion(o, s, i, 0, ov01_02208A28);
}

void ov01_021F8BE0(void *obj) {
    VecFx32 v = { 0, 0, 0 };
    v.z += 2 << 10;
    MapObject_SetFacingVector(obj, &v);
}

void ov01_021F8C00(void *obj, int divisor) {
    s32 value = sub_02023F70(obj) / FX32_ONE;
    sub_02023F40(obj, (value - value % divisor) * FX32_ONE);
    sub_02023F04(obj, 0);
}

void ov01_021F8C30(void *obj) {
    ov01_021F8C00(obj, 8);
}

void ov01_021F8C3C(void *obj, u32 value, int divisor) {
    fx32 old;
    ov01_021F8C00(obj, divisor);
    old = sub_02023F70(obj);
    sub_02023EE0(obj, value);
    sub_02023F40(obj, old);
}

void ov01_021F8C64(void *obj, u32 value) {
    fx32 old;
    ov01_021F8C30(obj);
    old = sub_02023F70(obj);
    sub_02023EE0(obj, value);
    sub_02023F40(obj, old);
}

void ov01_021F8C88(void *obj, void *state) {
    int enabled = TRUE;
    if (MapObject_TestFlagsBits(obj, 1 << 9) == TRUE) {
        enabled = FALSE;
    }
    if (MapObject_TestFlagsBits(obj, 1 << 12) == TRUE && MapObject_TestFlagsBits(obj, 2 << 12) == FALSE) {
        enabled = FALSE;
    }
    sub_02023EA4(state, enabled);
}

void ov01_021F8CC8(u32 id, LocalConfig *out) {
    const u32 *p = ov01_022073D8;
    while (p[0] != 0xffff) {
        if (p[0] == id) {
            *out = *(const LocalConfig *)(p + 1);
            return;
        }
        p += 4;
    }
    GF_AssertFail();
}

void ov01_021F8CFC(void *obj) {
    void **slot = sub_0205F3E8(obj, 4);
    LocalConfig c;
    ov01_021F8CC8(MapObject_GetSpriteID(obj), &c);
    *slot = ov01_021FD2EC(obj, &c);
}

void ov01_021F8D24(void) {
}

void ov01_021F8D28(void *obj) {
    void **slot = sub_0205F40C(obj);
    if (*slot != NULL) {
        ov01_021F1640(*slot);
        *slot = NULL;
    }
}

void ov01_021F8D40(void *obj) {
    void **slot = sub_0205F40C(obj);
    if (*slot != NULL) {
        ov01_021F1640(*slot);
        *slot = NULL;
    }
}

void ov01_021F8D58(void *obj) {
    void **slot = sub_0205F40C(obj);
    LocalConfig c;
    ov01_021F8CC8(MapObject_GetSpriteID(obj), &c);
    *slot = ov01_021FD2EC(obj, &c);
}
