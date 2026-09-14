#include "overlay40_pc_box_wallpaper_private.h"

void ov40_02243B48(u8 *w) {
    int i = 0;
    u8 *p;
    if ((int)WORD(w, 0x204) > 0) {
        p = w;
        do {
            if (PTR(p, 0xC) != NULL) {
                ManagedSprite_SetDrawFlag(PTR(p, 0xC), TRUE);
            }
            i++;
            p += 0x1C;
        } while (i < (int)WORD(w, 0x204));
    }
    for (i = 0; i < 2; i++, w += 0x1C) {
        if (PTR(w, 0x15C) != NULL) {
            ManagedSprite_SetDrawFlag(PTR(w, 0x15C), TRUE);
        }
    }
}

void ov40_02243B94(u8 *w) {
    int i = 0;
    u8 *p;
    if ((int)WORD(w, 0x204) > 0) {
        p = w;
        do {
            Sprite_DeleteAndFreeResources(PTR(p, 0xC));
            i++;
            p += 0x1C;
        } while (i < (int)WORD(w, 0x204));
    }
    {
        u8 *q;
        int j = 0;
        q = w;
        for (; j < 2; j++, q += 0x1C) {
            Sprite_DeleteAndFreeResources(PTR(q, 0x15C));
        }
    }
    {
        u8 *q;
        int j = 0;
        q = w;
        for (; j < 3; j++, q += 0x1C) {
            Sprite_DeleteAndFreeResources(PTR(q, 0x194));
        }
    }
    SpriteManager_UnloadCharObjById(PTR(w, 0x228), 0x3E8);
    SpriteManager_UnloadPlttObjById(PTR(w, 0x228), 0x3E8);
    SpriteManager_UnloadCellObjById(PTR(w, 0x228), 0x3E8);
    SpriteManager_UnloadAnimObjById(PTR(w, 0x228), 0x3E8);
    SpriteManager_UnloadCharObjById(PTR(w, 0x228), 0x3E9);
    SpriteManager_UnloadPlttObjById(PTR(w, 0x228), 0x3E9);
    SpriteManager_UnloadCellObjById(PTR(w, 0x228), 0x3E9);
    SpriteManager_UnloadAnimObjById(PTR(w, 0x228), 0x3E9);
}
