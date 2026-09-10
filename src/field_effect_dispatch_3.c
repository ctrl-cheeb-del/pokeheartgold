#include "field_effect_dispatch_internal.h"

void ov01_02205808(BOOL select, void *obj, void *model) {
    u8 info[0x28];
    void *manager = MapObject_GetManager(obj);
    s32 sprite = MapObject_GetSpriteID(obj);
    ov01_021F9744(manager, sprite, info);
    {
        u32 id = MapObject_GetID(obj);
        if (id != 0xfd && id != 0xfa && id != 0xfb) {
            return;
        }
        ov01_02205870(select, obj, model, info);
        sub_02023EC8(model, info);
        sub_02023EE0(model, ov01_021FA44C(MapObject_GetFacingDirection(obj)));
        sub_02023F40(model, 0);
    }
}

void ov01_02205870(BOOL select, void *obj, void *unused, void *data) {
    void *fs = sub_0205F1A0(MapObject_GetManager(obj));
    void *entry = ov01_021FC5A4(*(void **)((u8 *)fs + 0xfc), select ? 0x16 : 0x15);
    sub_02026E18(entry, (u8 *)data + 0xc);
}
