#include "to42_overlay_45_thumb_residual_35_private.h"
void ov45_02230008(int, const u32 *);
void ov45_02230050(void *);
void ov45_02230064(int, void *, void *);
BOOL ov45_02230090(int);
void ov45_02230008(int key, const u32 *record) {
    int result;
    if (ov45_0222FB24(_022577C0, key, 0) == -1) {
        return;
    }
    result = ov45_022301E0(_022577C0, record[0], key);
    if (*(u16 *)(_022577C0 + 0x69c) == record[0] && result == 1) {
        _022577C0[0x69f] = 1;
    }
}
void ov45_02230050(void *arg) {
    Ov45Callback1 callback = *(Ov45Callback1 *)(_022577C0 + 0x18);
    callback(arg, *(void **)(_022577C0 + 0x20));
}
void ov45_02230064(int result, void *arg0, void *arg1) {
    if (result != 0) {
        _022577C0[0x133] = 1;
    } else {
        Ov45Callback2 callback = *(Ov45Callback2 *)(_022577C0 + 0x1c);
        callback(arg0, arg1, *(void **)(_022577C0 + 0x20));
    }
}
BOOL ov45_02230090(int result) {
    if (result == 0) {
        return TRUE;
    }
    _022577C0[0x132] = 1;
    return FALSE;
}
