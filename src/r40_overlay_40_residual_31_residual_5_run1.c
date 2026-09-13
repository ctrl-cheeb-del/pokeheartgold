#include "r40_overlay_40_residual_31_residual_5_private.h"

u32 ov40_022383C8(void *p) {
    Ov40R31Work *w = PTR_AT(p, 0x860);
    switch (U32_AT(p, 8)) {
    case 0:
        ov40_02238304(p);
        ov40_02237C74(p);
        if (w->flag == 0) {
            ov40_02237D6C(p);
            ov40_02230964(p, 1);
            ov40_0222FA24((u8 *)p + 0x47c);
            ov40_0222F720((u8 *)p + 0x49c);
            ov40_0222F920((u8 *)p + 0x49c, p);
            ov40_02230964(p, 0);
        } else {
            ov40_02230964(p, 1);
            ov40_0222E7B8((u8 *)w + 0x2ed8, p);
            ov40_022361B0(p);
            ov40_02230964(p, 0);
        }
        w->flag = 0;
        ov40_02230964(p, 1);
        ov40_02236EB4(p);
        ov40_0223707C(p, 0xff);
        sub_020879E0(PTR_AT(p, 0x6f4), 0);
        sub_020878B0(PTR_AT(p, 0x6f0), 0);
        sub_020879E0(PTR_AT(p, 0x6f0), 0);
        sub_02087A08(PTR_AT(p, 0x6f0), 0, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        BgClearTilemapBufferAndCommit(PTR_AT(p, 0x24), 3);
        ov40_02230964(p, 0);
        U32_AT(p, 8)
        ++;
        /* fall through */
    case 1:
        if (!ov40_0222DA00((u8 *)w + 0x1a4, (u8 *)w + 0x1a8, 1, 0)) {
            break;
        }
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(p, 0x14), 0x4f, PTR_AT(p, 0x24), 7, 0, 0, 0, 0x6d);
        U32_AT(p, 8)
        ++;
        break;
    case 2:
        if (!ov40_0222DA00((u8 *)w + 0x1a4, (u8 *)w + 0x1a8, 0, 2)) {
            break;
        }
        ov40_0222C710(p, 2);
        GfGfx_EngineATogglePlanes(4, 1);
        GfGfx_EngineBTogglePlanes(4, 1);
        ov40_02237030(p, 0x113);
        ov40_02236F38(p);
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}
