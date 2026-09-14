#include "overlay40_box_transition_tail_private.h"

u32 ov40_0223480C(void *p) {
    void *work = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        SetBgPriority(0, 1);
        SetBgPriority(1, 3);
        SetBgPriority(2, 2);
        SetBgPriority(3, 1);
        SetBgPriority(4, 1);
        SetBgPriority(5, 3);
        SetBgPriority(6, 2);
        SetBgPriority(7, 1);
        Heap_Free(PTR(work, 0x238));
        sub_020314BC(PTR(work, 0x250));
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        ov40_02236130(p);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((u8 *)work + 8, 1);
        if (ov40_0222DA00(work, (u8 *)work + 4, 1, 0) != 0) {
            ov40_02230964(p, 1);
            ov40_02235B10(p);
            ov40_02230964(p, 0);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xc, (u8)WORD(work, 8), (u16)WORD(p, 0x58));
        break;
    case 2:
        ov40_0222DAA8((u8 *)work + 8);
        ov40_02230964(p, 1);
        ov40_0222D88C(p);
        ov40_02230964(p, 0);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
        ov40_0222FB90(p, 1);
        WORD(p, 8)
        ++;
        break;
    default:
        if (ov40_0222FBB4(p) != 0) {
            if (ov40_0222DA84((u8 *)work + 8, 0) != 0) {
                ov40_02230964(p, 1);
                if (PTR(work, 0x228) != NULL) {
                    ov41_0224B57C(PTR(work, 0x228));
                    ov40_0222BC54(p);
                    SetBgPriority(2, 0);
                    ov40_02235994();
                }
                ov40_02230964(p, 0);
                ov40_0222DD08(p);
                ov40_0222DAA8((u8 *)work + 8);
                PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xc, 0x10, (u16)WORD(p, 0x58));
                ov40_0222BF64(p, 1, 1, PTR(p, 0x10));
                ov40_0222BF80(p, 5);
                Heap_Free(work);
                UnloadOverlayByID(FS_OVERLAY_ID(OVY_41));
                Main_SetVBlankIntrCB(ov40_0222BD04, p);
            } else {
                PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)WORD(work, 8), (u16)WORD(p, 0x58));
                PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xc, (u8)WORD(work, 8), (u16)WORD(p, 0x58));
            }
        }
        break;
    }
    return 0;
}
