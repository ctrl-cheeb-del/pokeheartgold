#include "overlay40_trainer_card_resources_r19_private.h"

void ov40_0222FCCC(void *p) {
    int i;
    int result;
    u8 *q;

    q = p;
    for (i = 0; i < 4; i++, q += 4) {
        sub_0202FC90(PTR(p, 0x830), 0x6D, &result, NULL, i);
        switch (result) {
        case 0:
            PTR(q, 0x87C) = NULL;
            PTR(q, 0x88C) = NULL;
            if (i == 0) {
                PTR(q, 0x88C) = sub_020314A4(0x6D);
                sub_020314C4(PTR(q, 0x88C), PTR(p, 0x830));
            }
            break;
        case 2:
            PTR(q, 0x87C) = NULL;
            PTR(q, 0x88C) = NULL;
            if (i == 0) {
                PTR(q, 0x88C) = sub_020314A4(0x6D);
                sub_020314C4(PTR(q, 0x88C), PTR(p, 0x830));
            }
            break;
        case 3:
            PTR(q, 0x87C) = NULL;
            PTR(q, 0x88C) = NULL;
            if (i == 0) {
                PTR(q, 0x88C) = sub_020314A4(0x6D);
                sub_020314C4(PTR(q, 0x88C), PTR(p, 0x830));
            }
            break;
        case 1:
            PTR(q, 0x87C) = sub_0203077C(0x6D);
            if (i == 0) {
                PTR(q, 0x88C) = sub_020314A4(0x6D);
                sub_020314C4(PTR(q, 0x88C), PTR(p, 0x830));
            } else {
                PTR(q, 0x88C) = sub_020307AC(0x6D);
            }
            break;
        }
        if (sub_0202FC48() == 1) {
            sub_0202FC24();
        }
    }
}

void ov40_0222FDC4(void *p) {
    int i;
    u8 *q = p;
    void *zero1 = NULL;
    void *zero2 = NULL;

    for (i = 0; i < 4; i++, q += 4) {
        if (PTR(q, 0x87C) != NULL) {
            Heap_Free(PTR(q, 0x87C));
            PTR(q, 0x87C) = zero1;
        }
        if (PTR(q, 0x88C) != NULL) {
            Heap_Free(PTR(q, 0x88C));
            PTR(q, 0x88C) = zero2;
        }
    }
}

void ov40_0222FE00(void *p) {
    SpriteSystem *system = PTR(p, 0x18);
    SpriteManager *manager = PTR(p, 0x1C);
    PaletteData *palette = PTR(p, 0x28);

    SpriteSystem_LoadPaletteBuffer(palette, (PaletteBufferId)2, system, manager, (NarcId)0x14, sub_02074490(), FALSE, 3, 1, 0x186A0);
    SpriteSystem_LoadCellResObj(system, manager, (NarcId)0x14, sub_0207449C(), FALSE, 0x186A0);
    SpriteSystem_LoadAnimResObj(system, manager, (NarcId)0x14, sub_020744A8(), FALSE, 0x186A0);
}

void ov40_0222FE68(void *p) {
    SpriteManager_UnloadPlttObjById(PTR(p, 0x1C), 0x186A0);
    SpriteManager_UnloadCellObjById(PTR(p, 0x1C), 0x186A0);
    SpriteManager_UnloadAnimObjById(PTR(p, 0x1C), 0x186A0);
}
