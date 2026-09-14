#include "global.h"

#include "overlay45_lobby_object_lifecycle_r26_private.h"
typedef struct Obj {
    u8 pad[0x39];
    u8 b39;
    u16 h3a;
    void *p3c;
    u32 v40;
    u32 v44;
} Obj;
int ov45_0222CCE4(u16 v) {
    int i;
    for (i = 0; i < 16; i++) {
        if (v == ov45_02254A84[i][0]) {
            return i;
        }
    }
    return 16;
}
u16 ov45_0222CD04(u32 i) {
    if (i < 16) {
        return ov45_02254A84[i][0];
    }
    return 0xffff;
}
Obj *ov45_0222CD1C(int a, u32 b, u32 c, void *d, u32 heap) {
    Obj *p = Heap_Alloc(heap, 0x48);
    int i;
    memset(p, 0, 0x48);
    p->p3c = d;
    p->v40 = b;
    p->v44 = c;
    p->b39 = a;
    p->h3a = heap;
    for (i = 0; i < 13; i++) {
        ov45_0222CDE4(p, i, heap);
    }
    return p;
}
void ov45_0222CD68(void *p) {
    int i;
    for (i = 0; i < 13; i++) {
        ov45_0222CE0C(p, i);
    }
    Heap_Free(p);
}
int ov45_0222CD84(void *p) {
    return ov45_0222CE2C(p, 5);
}
int ov45_0222CD90(void *v) {
    Obj *p = v;
    int ret = 0;
    if (*(void **)p && OverlayManager_Run(*(void **)p)) {
        OverlayManager_Delete(*(void **)p);
        *(void **)p = 0;
        ret = ov45_0222CE54(p, p->pad[0x38]);
    }
    return ret;
}
