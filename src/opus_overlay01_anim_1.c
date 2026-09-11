#include "overlay_01_021F944C_internal.h"

FieldObjAnimData *ov01_021F9704(FieldObjSys *sys, u32 id) {
    u32 i;
    u32 count;
    FieldObjAnimEntry *entries;
    FieldObjAnimEntry *scan;

    entries = sys->entries;
    count = sys->count;
    scan = entries;
    i = count;

    do {
        if (scan->id == id) {
            return scan->data;
        }
        scan++;
    } while (--i != 0);

    do {
        if (entries->id == 0xFFFF) {
            entries->id = id;
            ov01_021FA370(sys, id, entries->data);
            return entries->data;
        }
        entries++;
    } while (--count != 0);
    return NULL;
}

BOOL ov01_021F9744(void *obj, u32 id, FieldObjAnimData *dst) {
    u32 count;
    FieldObjAnimEntry *entries;
    FieldObjSys *sys;

    sys = sub_0205F1A0(obj);
    entries = sys->entries;
    count = sys->count;

    do {
        if (entries->id == id) {
            *dst = *entries->data;
            return TRUE;
        }
        entries++;
    } while (--count != 0);
    return FALSE;
}

void ov01_021F9778(FieldObjSys *sys, u32 id) {
    u32 count;
    FieldObjAnimEntry *entries;

    entries = sys->entries;
    count = sys->count;

    do {
        if (entries->id == id) {
            entries->id = 0xFFFF;
            return;
        }
        entries++;
    } while (--count != 0);
}

void ov01_021F9798(FieldObjSys *sys) {
    u32 count;
    FieldObjAnimEntry *entries;

    entries = sys->entries;
    count = sys->count;

    do {
        if (entries->id != 0xFFFF) {
            entries->id = 0xFFFF;
        }
        entries++;
    } while (--count != 0);
}

BOOL ov01_021F97BC(void *mgr, void *self, u32 spriteId) {
    void *cur;
    u32 count = MapObjectManager_GetObjectCount(mgr);

    cur = MapObjectManager_GetObjects2(mgr);
    do {
        if (cur != self) {
            if (MapObject_CheckActive(cur) == TRUE) {
                u32 id = MapObject_GetSpriteID(cur);
                if (id != 0xFFFF) {
                    if (id == spriteId) {
                        return TRUE;
                    }
                }
            }
        }
        MapObjectArray_NextObject(&cur);
    } while (--count != 0);
    return FALSE;
}

void ov01_021F9808(FieldObjSys *sys, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    sys->unkF8 = ov01_021FC4C4(4, 0x3F, a1 << 12, a1);
    ov01_021F9B00(sys);
    ov01_021FA208(sys, a2);
    ov01_021FA210(sys, a1 - a2);
    sys->unkFC = ov01_021FC4C4(4, 0x40, a3 << 7, a3);
    ov01_021F9C24(sys);
    ov01_021FA218(sys, a4);
    ov01_021FA220(sys, a3 - a4);
    ov01_021FA1EC(sys, GF3dGfxRawResMan_Create(a5, 4));
    ov01_021F9D48(sys);
    ov01_021FA228(sys, a6);
    ov01_021FA230(sys, a5 - a6);
}
