#include "to45_overlay89_r11_private.h"

void ov89_0225BB28(void *unused, u8 *work) {
    int i;
    u8 *p;

    p = work + 0x94;
    if (p[0xF6] != 0xFF) {
        NNS_G3dGlbPolygonAttr(0, (GXPolygonMode)0, (GXCull)0, p[0xF6], *(u16 *)(p + 0xF4) >> 8, 0);
        NNSi_G3dModifyPolygonAttrMask(*(void **)(work + 0x14), 0, 0x3F << 24);
        NNSi_G3dModifyPolygonAttrMask(*(void **)(work + 0x14), 0, 0x1F << 16);
    }
    i = 0;
    do {
        sub_020181EC(p);
        i++;
        p += 0x78;
    } while (i < 2);
    sub_020181EC(work + 0x1C);
}
