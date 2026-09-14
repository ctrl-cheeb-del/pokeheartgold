#include "global.h"

#include "overlay45_resource_flags_r39_private.h"

extern Overlay45ResourceConfig ov45_02254C48[];

void ov45_02230978(u8 *data, int value) {
    ((Overlay45PackedFlags *)data)->value = value;
    ov45_02230E28(data);
}

int ov45_02230994(u8 *data) {
    return ((u32)*data << 24) >> 30;
}

Overlay45ResourceConfig *ov45_0223099C(u16 id) {
    int i;

    for (i = 0; i < 20; i++) {
        if (id == ov45_02254C48[i].lookupKey) {
            return &ov45_02254C48[i];
        }
    }

    GF_ASSERT(FALSE);
    return NULL;
}
