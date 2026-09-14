#include "to45_ov40_r31_r6_private.h"

u32 ov40_02238838(void *p) {
    Ov40R31R6Work *w = PTR_AT(p, 0x860);
    switch (U32_AT(p, 8)) {
    case 0:
        ov40_0222D980(&w->fadeA, &w->fadeB, 8, 0x12, 8, 0x12, 1);
        ov40_02237564(p);
        ov40_02237410(p);
        ov40_022371A0(p);
        BgClearTilemapBufferAndCommit(PTR_AT(p, 0x24), 2);
        ov40_02237008(p);
        ov40_02237C54(p);
        U32_AT(p, 8)
        ++;
        /* fall through */
    case 1:
        w->flag = 0;
        U32_AT(p, 8)
        ++;
        /* fall through */
    case 2:
        if (!ov40_0222DA00(&w->fadeA, &w->fadeB, 1, 0)) {
            break;
        }
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR_AT(p, 0x14), 0x3E, PTR_AT(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(p, 0x14), 3, PTR_AT(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(p, 0x14), 0x4E, PTR_AT(p, 0x24), 7, 0, 0, 0, 0x6D);
        GfGfx_EngineBTogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        U32_AT(p, 8)
        ++;
        break;
    default:
        if (!ov40_0222DA00(&w->fadeA, &w->fadeB, 0, 0)) {
            break;
        }
        ov40_02230964(p, 1);
        sub_020879E0(PTR_AT(p, 0x6F0), 1);
        ov40_02237C9C(p);
        ov40_02237AC0(p);
        ov40_0222F9E0((u8 *)p + 0x47C, p, 2);
        ov40_0222EED0((u8 *)p + 0x49C, p, w->pad02EAC, w->strings);
        ov40_0222FA5C((u8 *)p + 0x47C, (u8 *)p + 0x49C);
        ov40_0222F740((u8 *)p + 0x49C, p, 1);
        ov40_0222F858((u8 *)p + 0x49C, 0x38, 0xB0);
        ov40_0223077C(p, PTR_AT(p, 0x6F0), 0x10, (s16)(U32_AT(p, 0x4D8) * 24 + 0x44));
        sub_020879E0(PTR_AT(p, 0x6F0), 1);
        sub_02087A08(PTR_AT(p, 0x6F0), 0xC, 0xC);
        if (w->flag == 0) {
            ov40_0222FA88((u8 *)p + 0x47C);
            ov40_0222F5EC((u8 *)p + 0x49C, S16_AT(p, 0x48C));
            ov40_0222EFD8((u8 *)p + 0x49C, p, w->strings);
            sub_020878EC(PTR_AT(p, 0x6F0), 0x10, (s16)(U32_AT(p, 0x4D8) * 24 + 0x44));
        }
        ov40_02230964(p, 0);
        GfGfx_EngineATogglePlanes(4, 1);
        GfGfx_EngineBTogglePlanes(4, 1);
        ov40_0222BF80(p, 5);
        break;
    }
    return 0;
}

u32 ov40_02238A50(void *p) {
    Ov40R31R6Work *w = PTR_AT(p, 0x860);
    switch (U32_AT(p, 8)) {
    case 0:
        sub_020879E0(PTR_AT(p, 0x6F0), 0);
        if (w->flag == 0) {
            ov40_02237D6C(p);
        }
        ov40_0222FA24((u8 *)p + 0x47C);
        ov40_0222F720((u8 *)p + 0x49C);
        ov40_0222F920((u8 *)p + 0x49C, p);
        w->flag = 1;
        BgClearTilemapBufferAndCommit(PTR_AT(p, 0x24), 2);
        ov40_0222D980(&w->fadeA, &w->fadeB, 8, 0x12, 8, 0x12, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        U32_AT(p, 8)
        ++;
        /* fall through */
    case 1:
        if (!ov40_0222DA00(&w->fadeA, &w->fadeB, 1, 1)) {
            break;
        }
        ov40_02236184(p, PTR_AT(p, 0x4D4));
        ov40_02230964(p, 1);
        ov40_0222E79C(w->panel, p);
        ov40_0222E7DC((u8 *)w + 0x2ED8, 0);
        ov40_02230964(p, 0);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR_AT(p, 0x14), 0x3E, PTR_AT(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(p, 0x14), 0x50, PTR_AT(p, 0x24), 3, 0, 0, 0, 0x6D);
        U32_AT(p, 8)
        ++;
        break;
    case 2:
        if (!ov40_0222DA00(&w->fadeA, &w->fadeB, 0, 1)) {
            break;
        }
        ov40_0222E7DC(w->panel, 1);
        ov40_02237B7C(p, w->flag + 0x79);
        GfGfx_EngineBTogglePlanes(4, 1);
        GfGfx_EngineATogglePlanes(4, 1);
        ov40_0222BF80(p, 5);
        break;
    }
    return 0;
}

u32 ov40_02238BB0(void *p) {
    Ov40R31R6Work *w = PTR_AT(p, 0x860);
    switch (U32_AT(p, 8)) {
    case 0:
        w->flag = 0;
        U32_AT(p, 8)
        ++;
        break;
    case 1:
        ov40_02230964(p, 1);
        ov40_0222E7B8(w->panel, p);
        ov40_022361B0(p);
        ov40_02230964(p, 0);
        U32_AT(p, 8)
        ++;
        /* fall through */
    case 2:
        if (!ov40_0222DA00(&w->fadeA, &w->fadeB, 1, 1)) {
            break;
        }
        BgClearTilemapBufferAndCommit(PTR_AT(p, 0x24), 2);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR_AT(p, 0x14), 0x3E, PTR_AT(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(p, 0x14), 3, PTR_AT(p, 0x24), 3, 0, 0, 0, 0x6D);
        U32_AT(p, 8)
        ++;
        break;
    default:
        if (!ov40_0222DA00(&w->fadeA, &w->fadeB, 0, 1)) {
            break;
        }
        ov40_02230964(p, 1);
        ov40_02237B7C(p, w->flag + 0x79);
        ov40_02237C9C(p);
        ov40_0222F9E0((u8 *)p + 0x47C, p, 2);
        ov40_0222EED0((u8 *)p + 0x49C, p, w->pad02EAC, w->strings);
        ov40_0222FA5C((u8 *)p + 0x47C, (u8 *)p + 0x49C);
        ov40_0222F740((u8 *)p + 0x49C, p, 1);
        ov40_0222F858((u8 *)p + 0x49C, 0x38, 0xB0);
        if (w->flag == 0) {
            ov40_0222FA88((u8 *)p + 0x47C);
            ov40_0222F5EC((u8 *)p + 0x49C, S16_AT(p, 0x48C));
            ov40_0222EFD8((u8 *)p + 0x49C, p, w->strings);
            sub_020878EC(PTR_AT(p, 0x6F0), 0x10, (s16)(U32_AT(p, 0x4D8) * 24 + 0x44));
        }
        sub_020879E0(PTR_AT(p, 0x6F0), 1);
        GfGfx_EngineATogglePlanes(4, 1);
        ov40_02230964(p, 0);
        ov40_0222BF80(p, 5);
        break;
    }
    return 0;
}
