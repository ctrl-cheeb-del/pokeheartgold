#include "overlay106_render_helpers_private.h"




typedef struct { u32 v[9]; } Ov106Matrix;
typedef struct { u32 v[3]; } Ov106Vec;

void ov106_021E5A44(const s16 *data) {
    u32 i = 0;
    const s16 *vec = data;
    const u16 *color = (const u16 *)data;
    while (i < 4) {
        NNS_G3dGlbLightVector((GXLightId)i, vec[0], vec[1], vec[2]);
        NNS_G3dGlbLightColor((GXLightId)i, color[12]);
        i++;
        vec += 3;
        color += 1;
    }
}

void ov106_021E5A74(const u16 *table) {
    if (table == NULL) {
        *(volatile u16 *)0x04000060 &= 0xCFDF;
    } else {
        *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x20;
        G3X_SetEdgeColorTable(table);
    }
}
