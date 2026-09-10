#include "field_map_object_render_internal.h"

void ov01_021FA8F8(void *p) {
    u8 *state = *(u8 **)((u8 *)p + 0x100);
    *(u16 *)(state + 6) = 1;
    SysTask_Destroy(*(void **)(state + 0x18));
    SysTask_Destroy(*(void **)(state + 0x1c));
    SysTask_Destroy(*(void **)(state + 0x20));
    SysTask_Destroy(*(void **)(state + 0x24));
    Heap_Free(state);
    *(void **)((u8 *)p + 0x100) = NULL;
}

void ov01_021FA930(void *obj, void *arg) {
    if (ov01_021FA2D4(obj) == TRUE || ov01_021F72DC(obj) == FALSE) {
        u32 id = MapObject_GetSpriteID(obj);
        void *manager = MapObject_GetManager(obj);
        sub_0205E420(obj);
        ov01_021FA108(manager, id, obj);
        sub_0205E38C(obj, arg);
    } else {
        ov01_021FA97C(obj, arg);
    }
}
