#include "overlay40_trainer_card_panels_private.h"

int ov40_02240B40(void *p) {
    TouchHitboxController_IsTriggered(PTR(PTR(p, 0x860), 0x608));
    return 0;
}

int ov40_02240B58(void *p) {
    if (ov40_0224222C(p)) {
        ov40_0222BF80(p, 8);
    }
    return 0;
}

int ov40_02240B70(void *p) {
    void *w = PTR(p, 0x860);
    if (ov40_02242CFC(p)) {
        Heap_Free(w);
        return 1;
    }
    return 0;
}

int ov40_02240B90(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        TouchHitboxController_Destroy(PTR(w, 0x608));
        TouchHitboxController_Destroy(PTR(w, 0x60C));
        TouchHitboxController_Destroy(PTR(w, 0x610));
        GfGfx_EngineBTogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        ov40_02240910(p);
        ov40_02230964(p, (void *)1);
        if (WORD(w, 0x1CC) == 0) {
            ov40_0223064C((u8 *)w + 0x10C, p);
        } else {
            ov40_0222E7B8((u8 *)w + 0x80, p);
        }
        ov40_02230964(p, NULL);
        ov40_02241A34(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((int *)w + 2, 1);
        if (ov40_0222DA00((int *)w, (int *)w + 1, 1, 0)) {
            ov40_022421FC(p);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xC);
        break;
    case 2:
        ov40_0222DAA8((int *)w + 2);
        ov40_02230964(p, (void *)1);
        ov40_0222D88C(p);
        ov40_02230964(p, NULL);
        ov40_0222FB90(p, 1);
        WORD(p, 8)
        ++;
        break;
    case 3:
        if (ov40_0222FBB4(p) != NULL) {
            if (ov40_0222DA84((int *)w + 2, 0)) {
                ov40_0222DD08(p);
                ov40_0222DAA8((int *)w + 2);
                PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, (u16)WORD(p, 0x58));
                ov40_0222BF64(p, 1, TRUE, (u32 *)PTR(p, 0x10));
                ov40_0222BF80(p, 5);
                Heap_Free(w);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
                if (sub_0202FC48() == 1) {
                    sub_0202FC24();
                }
            } else {
                BLEND(p, w, 1, 2);
                BLEND(p, w, 3, 0xC);
            }
        }
        break;
    }
    return 0;
}
