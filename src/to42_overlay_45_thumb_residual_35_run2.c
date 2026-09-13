#include "to42_overlay_45_thumb_residual_35_private.h"
void ov45_0222FF40(int, void *);
void ov45_0222FF40(int key, void *record) {
    if (ov45_0222FB24(_022577C0, key, 0) != -1) {
        Ov45Callback2 callback;
        ov45_0222F88C(_022577C0, key, record);
        callback = *(Ov45Callback2 *)(_022577C0 + 0x14);
        callback((void *)key, record, *(void **)(_022577C0 + 0x20));
    }
}
