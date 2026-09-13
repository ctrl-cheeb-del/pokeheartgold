#include "r40_overlay_40_residual_31_residual_6_private.h"

int ov40_02238D5C(void *p) {
    void *ctx = PTR(p, 0x860);
    switch (U32(p, 8)) {
    case 0:
        ov40_02230964(p, 1);
        ov40_02237008(p);
        ov40_02236534(p);
        sub_020878B0(PTR(p, 0x6F4), 0);
        sub_020879E0(PTR(p, 0x6F4), 0);
        sub_020878B0(PTR(p, 0x6F0), 1);
        sub_020879E0(PTR(p, 0x6F0), 0);
        ov40_02230964(p, 0);
        ov40_0222FB90(p, 1);
        U32(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222FBB4() != 0) {
            int i;
            for (i = 0; i < 5; i++) {
                TouchHitboxController_Destroy(((SolCtx40 *)ctx)->hitbox[i]);
            }
            ov40_0222DAA8((u8 *)ctx + 0x1AC);
            ov40_0222D88C(p);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
            U32(p, 8)
            ++;
        }
        break;
    default:
        if (ov40_0222DA84((u8 *)ctx + 0x1AC, 0) != 0) {
            ov40_0222DD08(p);
            ov40_0222DAA8((u8 *)ctx + 0x1AC);
            PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, (u16)U32(p, 0x58));
            ov40_0222BF64(p, 1, 1, PTR(p, 0x10));
            ov40_0222BF80(p, 5);
            sub_020314BC(PTR(ctx, 0x384));
            Heap_Free(ctx);
        } else {
            PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)U32(ctx, 0x1AC), (u16)U32(p, 0x58));
            PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)U32(ctx, 0x1AC), (u16)U32(p, 0x58));
        }
        break;
    }
    return 0;
}
