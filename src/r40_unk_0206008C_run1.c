#include "global.h"

#include "r40_unk_0206008C_private.h"

void sub_0206008C(LocalMapObject *object) {
    u8 value = sub_0205F514(object);
    sub_0205F51C(object, value);
    sub_02061108(object);
    if (sub_0205F73C(object) == TRUE) {
        u8 a = sub_0205F504(object);
        u8 b = sub_0205F514(object);
        int effect = ov01_021F9318(object);
        sub_020601A4(object, a, b, effect);
        sub_0206073C(object, a, b, effect);
        sub_020607A4(object, a, b, effect);
        sub_0206039C(object, a, b, effect);
        sub_020609D4(object, a, b, effect);
        sub_02060530(object, a, b, effect);
    }
}

void sub_02060114(LocalMapObject *object) {
    sub_02061108(object);
    if (sub_0205F73C(object) == TRUE) {
        u8 a = sub_0205F504(object);
        u8 b = sub_0205F514(object);
        int effect = ov01_021F9318(object);
        sub_020601A4(object, a, b, effect);
        sub_0206073C(object, a, b, effect);
        sub_020607A4(object, a, b, effect);
        sub_0206039C(object, a, b, effect);
        sub_020609D4(object, a, b, effect);
        sub_02060530(object, a, b, effect);
        sub_02060274(object, a, b, effect);
        sub_0206064C(object, a, b, effect);
    }
}
