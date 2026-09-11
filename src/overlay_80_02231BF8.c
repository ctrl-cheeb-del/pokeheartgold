#include "overlay_80_02231BF8_internal.h"

void ov80_02231E4C(AppArgsPrivate *out, FrontierDataPrivate *data) {
    u8 *src = (u8 *)data;
    int i;

    out->type = data->type;
    out->data18 = *(u32 *)(src + 0x28);
    out->data1c = *(u32 *)(src + 0x2C);
    out->frontierData = data;
    out->field28 = *(u16 *)(src + 0xA1C);
    for (i = 0; i < 4; i++) {
        out->a[i] = src[0x370 + i];
        out->b[i] = src[0x374 + i];
        out->c[i] = src[0x378 + i];
        out->d[i] = src[0x37C + i];
    }
}
