#include "unk_02063A14_internal.h"

void sub_02063A14(LocalMapObject *object) {
    sub_02063A40(object);
}

BOOL sub_02063A1C(LocalMapObject *object) {
    if (!sub_02063A5C(object)) {
        return FALSE;
    }
    if (sub_02063A78(object)) {
        return TRUE;
    }
    return FALSE;
}

void sub_02063A40(LocalMapObject *object) {
    _020FE104[MapObject_GetType(object)](object);
}

BOOL sub_02063A5C(LocalMapObject *object) {
    return _020FE134[MapObject_GetType(object)](object);
}

BOOL sub_02063A78(LocalMapObject *object) {
    return _020FE164[MapObject_GetType(object)](object);
}
