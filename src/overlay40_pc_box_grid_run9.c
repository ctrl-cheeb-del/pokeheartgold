#include "overlay40_pc_box_grid_private.h"

void ov40_022330B8(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222D6D0((u8 *)w + 0x158);
    Sprite_DeleteAndFreeResources(PTR(w, 0x15C));
    ov40_0222D7DC(p);
}

void ov40_022330E0(void *p, int a) {
    void *w = PTR(p, 0x860);
    if (a == 0) {
        ManagedSprite_SetPositionXY(PTR(w, 0xBC), 0x80, 0xE8);
    } else {
        ManagedSprite_SetPositionXY(PTR(w, 0xBC), 0x50, 0xE8);
    }
    sub_020136B4(PTR(w, 0xC0), 0x24, -8);
}

void ov40_0223311C(void *p, u32 vram) {
    void *narc = PTR(p, 0x14);
    void *sys = PTR(p, 0x18);
    void *mgr = PTR(p, 0x1C);
    SpriteSystem_LoadCharResObjFromOpenNarc(sys, mgr, narc, 0x32, 0, vram, 0x2E94);
    SpriteSystem_LoadCellResObjFromOpenNarc(sys, mgr, narc, 0x1C, 0, 0x2E94);
    SpriteSystem_LoadAnimResObjFromOpenNarc(sys, mgr, narc, 0x1D, 0, 0x2E94);
}
