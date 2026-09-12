#include "overlay99_record_screen_resources_r11_private.h"
void ov99_021E8C50(void *p) {
    u32 draw;
    if (U32(p, 0xb0) != 0) {
        draw = 0;
    } else if (P((u8 *)p + S8(p, 0xac) * 4, 0xbc) == NULL) {
        draw = 1;
    } else {
        draw = 0;
    }
    ov99_021E8F50(p);
    ManagedSprite_SetDrawFlag(P(p, 0x1c), draw);
}
void ov99_021E8C88(void *p) {
    void *a = ov98_0221E5C0(P(p, 0x14));
    void *b = ov98_0221E5D0(P(p, 0x14));
    SpriteSystem_LoadCharResObjFromOpenNarc(a, b, P(p, 8), 1, 1, 1, 0);
    SpriteSystem_LoadPlttResObjFromOpenNarc(a, b, P(p, 8), 0, 0, 1, 1, 0);
    SpriteSystem_LoadCellResObjFromOpenNarc(a, b, P(p, 8), 2, 1, 0);
    SpriteSystem_LoadAnimResObjFromOpenNarc(a, b, P(p, 8), 3, 1, 0);
    SpriteSystem_LoadPlttResObjFromOpenNarc(a, b, P(p, 8), 0xc, 0, 1, 2, 1);
    SpriteSystem_LoadCharResObjFromOpenNarc(a, b, P(p, 8), 0xd, 1, 2, 1);
    SpriteSystem_LoadCellResObjFromOpenNarc(a, b, P(p, 8), 0xe, 1, 1);
    SpriteSystem_LoadAnimResObjFromOpenNarc(a, b, P(p, 8), 0xf, 1, 1);
    ov98_0221E8A8(P(p, 0x14), ov99_021EA364, 0xf, 0, 1);
}
