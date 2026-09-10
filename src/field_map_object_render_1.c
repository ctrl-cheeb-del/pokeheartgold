#include "field_map_object_render_internal.h"

void ov01_021F944C(void *p, void *manager, u32 count, u32 unused, u32 a5, u32 a6, const u32 *ids, u32 a8) {
    *(void **)((u8 *)p + 0x104) = manager;
    ov01_021FA2EC(p, (void *)count);
    ov01_021FA854(p, count, a8);
    ov01_021F9808(p, 8, 4, 8, 4, a5, a6);
    ov01_021F9698(p, count);
    ov01_021F9A8C(p, (void *)ids, (void *)ov01_02207260, (void *)ov01_02206CF0);
}

void ov01_021F94A0(void *p) {
    ov01_021FA8F8(p);
    ov01_021F96E4(p);
    ov01_021FA314(ov01_021FA1D0(p));
    ov01_021F9890(p);
}

int ov01_021F94C0(void *obj, void *out, u32 id) {
    void *manager;
    int result;
    *(void **)out = NULL;
    manager = ov01_021FA3DC(obj);
    result = ov01_021F9DA4(manager, id);
    if (result == 0) {
        ov01_021F9654(obj, out, id);
        return result;
    }
    if (result == 3 || result == 4) {
        ov01_021FA75C(manager, obj, out, id);
        return result;
    }
    *(void **)out = ov01_021F9528(obj, id);
    return result;
}

void ov01_021F9510(void *obj, void *arg) {
    ov01_021F94C0(obj, arg, MapObject_GetSpriteID(obj));
}

void *ov01_021F9528(void *obj, u32 id) {
    int position[3];
    void *manager = ov01_021FA3DC(obj);
    void *resman = ov01_021FA1D0(manager);
    void *resource;
    void *result;
    ov01_021F9F84(manager, (void *)id);
    resource = ov01_021F9704(manager, id);
    if (resource == NULL) {
        GF_AssertFail();
    }
    ov01_021F93AC(obj, position);
    result = ov01_021FA31C(resman, resource, position);
    if (result == NULL) {
        GF_AssertFail();
    }
    return result;
}

void ov01_021F9574(void *obj, void *out, u32 id) {
    void *manager;
    sub_02023DA4(*(void **)out);
    *(void **)out = NULL;
    manager = MapObject_GetManager(obj);
    if (!ov01_021F97BC(manager, obj, id)) {
        ov01_021F9778(ov01_021FA3DC(obj), id);
    }
}

void ov01_021F95A8(void *obj, void *arg) {
    ov01_021F9688(obj);
    if (*(void **)arg != NULL) {
        ov01_021F9574(obj, arg, MapObject_GetSpriteID(obj));
    }
}

void ov01_021F95CC(void *obj, void *out, u32 id) {
    ov01_021F9688(obj);
    if (*(void **)out != NULL) {
        sub_02023DA4(*(void **)out);
        *(void **)out = NULL;
    }
    if (id != 0xffff && !ov01_021F97BC(MapObject_GetManager(obj), obj, id)) {
        ov01_021F9778(ov01_021FA3DC(obj), id);
    }
}

void ov01_021F9610(void *src, ObjRecord *dst) {
    dst->id = sub_02023EB8(src);
    dst->unk6 = sub_02023EF4(src);
    dst->unk8 = sub_02023F30(src);
}

void ov01_021F9630(void *dst, ObjRecord *src) {
    sub_02023EA4(dst, (u8)src->id);
    sub_02023EE0(dst, src->unk6);
    sub_02023F1C(dst, src->unk8);
}

void ov01_021F9654(void *obj, void *out, u32 id) {
    void *manager = ov01_021FA3DC(obj);
    if (!ov01_021F9974(manager, id)) {
        *(void **)out = ov01_021F9528(obj, id);
    } else {
        ov01_021FA75C(manager, obj, out, id);
    }
}

void ov01_021F9688(void *obj) {
    ov01_021FA798(ov01_021FA3DC(obj), obj);
}

void ov01_021F9698(void *p, u32 count) {
    u8 *records = Heap_Alloc(4, 0x28 * count);
    u32 *index;
    *(void **)((u8 *)p + 0xe4) = records;
    if (records == NULL) {
        GF_AssertFail();
    }
    index = Heap_Alloc(4, count * 8);
    *(void **)((u8 *)p + 0xf4) = index;
    if (index == NULL) {
        GF_AssertFail();
    }
    do {
        index[0] = 0xffff;
        index[1] = (u32)records;
        index += 2;
        records += 0x28;
    } while (--count != 0);
}

void ov01_021F96E4(void *p) {
    ov01_021F9798(p);
    Heap_FreeExplicit(4, *(void **)((u8 *)p + 0xe4));
    Heap_FreeExplicit(4, *(void **)((u8 *)p + 0xf4));
}
