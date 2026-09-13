#include "to41_overlay_40_residual_36_private.h"

typedef struct Ov40CardEntries {
    u8 pad_0000[0x2608];
    void *entryPtrs[30];
    u8 entries[30][0xe4];
    s32 count;
} Ov40CardEntries;

int ov40_0223FD8C(void *p) {
    void *w = PTR(p, 0x860);
    void *result;

    if (!ov40_0223D5CC(p)) {
        return 0;
    }
    switch (WORD(p, 8)) {
    case 0:
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        if (WORD(w, 0x1cc) == 0) {
            ov40_022306A0((u8 *)w + 0x10c, 0);
        } else {
            ov40_0222E7DC((u8 *)w + 0x80, 0);
        }
        WORD(p, 8)
        ++;
    case 1:
        ov40_0222DA84((int *)((u8 *)w + 8), 1);
        if (ov40_0222DA00(w, (int *)((u8 *)w + 4), 1, 0)) {
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xc);
        break;
    case 2:
        ov40_0222DED0(p, 0x75);
        ov40_0223077C(p, PTR(p, 0x6f0), 0x80, 0x60);
        sub_020879E0(PTR(p, 0x6f0), 1);
        sub_02087A08(PTR(p, 0x6f0), 0x18, 0x18);
        WORD(w, 0x4b8) = 0;
        PlaySE(0x57d);
        WORD(p, 8)
        ++;
        break;
    case 3: {
        void *session = ov40_0223D540(p);
        if (ov39_02227720(session,
                PTR(PTR(p, 0x2608 + WORD(p, 0x4d4) * 4), 0xd8),
                PTR(PTR(p, 0x2608 + WORD(p, 0x4d4) * 4), 0xdc))
            == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    }
    case 4:
        if (ov39_02227D44(ov40_0223D540(p), &result) == 1) {
            StopSE(0x57d, 0);
            ov40_0222DFB0(p);
            ov40_02230CDC(p, 8, PTR(result, 0xc), PTR(result, 4));
            WORD(p, 8)
            ++;
            WORD(w, 0x4b8) = 0;
        } else {
            StopSE(0x57d, 0);
            WORD(p, 8) = 0xff;
            WORD(w, 0x4b8) = 1;
            PTR(p, 0x878) = (u8 *)p + 0x413c + WORD(p, 0x4d4);
            PTR(w, 0x4bc) = PTR(p, 0x8b4);
            MI_CpuCopy8(PTR(w, 0x4bc), (u8 *)p + 0x8b8, 0x1d4c);
        }
        sub_020879E0(PTR(p, 0x6f0), 0);
        sub_02087A08(PTR(p, 0x6f0), 0, 0);
        break;
    default:
        if (WORD(w, 0x4b8) != 0) {
            PlaySE(0x577);
            ov40_0222DFB0(p);
            ov40_0222BF80(p, WORD(w, 0xc));
            ov40_0222FC40(p, 1);
        } else {
            ov40_0222DFB0(p);
            ov40_0222BF80(p, 0x1f);
        }
        break;
    }
    return 0;
}

int ov40_0223FF8C(void *p) {
    void *w = PTR(p, 0x860);
    Ov40CardEntries *card = p;
    int i;

    switch (WORD(p, 8)) {
    case 0:
        ov40_02230738(p);
        ov40_0222D9E8(w, (u8 *)w + 4, 0);
        for (i = 0; i < card->count; i++) {
            card->entryPtrs[i] = card->entries[i];
        }
        BYTE(w, 0x79c) = BYTE(p, 0x413c + WORD(p, 0x4d4));
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3e, PTR(p, 0x24), 3, 0, 0, 0, 0x6d);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3e, PTR(p, 0x24), 7, 0, 0, 0, 0x6d);
        ov40_022307DC(p, 6, 7);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        ov40_02242110(p);
        ov40_022420B4(p, 0);
        ov40_0222D66C((u8 *)w + 0x10, (u8 *)p + 0x14, 3);
        ov40_0222D66C((u8 *)w + 0x2c, (u8 *)p + 0x14, 0x5e);
        ManagedSprite_SetAnim(PTR(w, 0x14), 0);
        ManagedSprite_SetAnim(PTR(w, 0x30), 3);
        HALF(w, 0x4c0) = 0xffff;
        BYTE(w, 0x4c2) = 0xff;
        BYTE(w, 0x4c3) = 0xff;
        BYTE(w, 0x4c4) = 0xff;
        WORD(w, 0x514) = 0x1f4;
        WORD(w, 0x510) = (s16)HALF(p, 0x4a4);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_022408AC(p);
        PTR(w, 0x608) = TouchHitboxController_Create(ov40_022456B4, 4, ov40_02241E40, p, 0x6d);
        PTR(w, 0x60c) = TouchHitboxController_Create(ov40_02245674, 4, ov40_02241ED4, p, 0x6d);
        PTR(w, 0x610) = TouchHitboxController_Create(ov40_02245654, 2, ov40_02241F3C, p, 0x6d);
        WORD(p, 8)
        ++;
        break;
    case 2:
        ov40_02230964(p, (void *)1);
        ov40_02230638((u8 *)w + 0x10c, p);
        ov40_022307DC(p, ov40_02230410((u8 *)w + 0x10c), 3);
        ov40_022306A0((u8 *)w + 0x10c, 0);
        ov40_02230964(p, NULL);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222DA84((int *)((u8 *)w + 8), 0);
        if (ov40_0222DA00(w, (int *)((u8 *)w + 4), 0, 0)) {
            ov40_022306A0((u8 *)w + 0x10c, 1);
            ov40_02241AB0(p);
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xc);
        break;
    case 4:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x6d);
        WORD(p, 8)
        ++;
        break;
    case 5:
        if (IsPaletteFadeFinished() == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    default:
        WORD(p, 0x6d8)
        ++;
        ov40_0222C4B8(p);
        ov40_0222BF80(p, 0x12);
        break;
    }
    return 0;
}

int ov40_02240238(void *p) {
    void *w = Heap_Alloc(0x6d, 0x7a0);

    memset(w, 0, 0x7a0);
    PTR(p, 0x860) = w;
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
    BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
    ov40_0222D9E8(w, (u8 *)w + 4, 0);
    ov40_0222BF80(p, 1);
    return 0;
}

int ov40_02240290(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        if (ov40_0222DA84((int *)((u8 *)w + 8), 1)) {
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 2, 0xc);
        BLEND(p, w, 3, 0xc);
        BLEND(p, w, 1, 2);
        break;
    case 1:
        ov40_02230964(p, (void *)1);
        ov40_0222D874(p);
        ov40_02230964(p, NULL);
        SetBgPriority(0, 0);
        SetBgPriority(1, 3);
        SetBgPriority(2, 0);
        SetBgPriority(3, 2);
        SetBgPriority(4, 0);
        SetBgPriority(5, 3);
        SetBgPriority(6, 1);
        SetBgPriority(7, 2);
        WORD(p, 8)
        ++;
        break;
    default:
        switch (WORD(p, 0x86c)) {
        case 0xc8:
            ov40_0222FB90(p, 0);
            sub_020879E0(PTR(p, 0x6f0), 0);
            if (ov40_0222C4DC(p) == 1) {
                ov40_0222BF80(p, 6);
            } else {
                ov40_0222BF80(p, 2);
            }
            break;
        case 0xd2:
            ov40_0222FB90(p, 0);
            sub_020879E0(PTR(p, 0x6f0), 0);
            if (ov40_0222C4DC(p) == 1) {
                ov40_0222BF80(p, 0x1e);
            } else {
                ov40_0222BF80(p, 2);
            }
            break;
        case 0xdc:
            if (ov40_0222C4DC(p) == 1) {
                ov40_0222BF80(p, 0x13);
            } else {
                ov40_0222BF80(p, 2);
            }
            sub_020879E0(PTR(p, 0x6f0), 0);
            break;
        default:
            ov40_0222FB90(p, 0);
            sub_020879E0(PTR(p, 0x6f0), 0);
            ov40_0222BF80(p, 2);
            break;
        }
        break;
    }
    return 0;
}

int ov40_02240418(void *p) {
    void *w = PTR(p, 0x860);
    void *obj = (u8 *)w + 0x1d4;
    int values[3];

    switch (WORD(p, 8)) {
    case 0:
        values[0] = 2;
        values[1] = 5;
        values[2] = 5;
        PTR(w, 0x4ac) = ov40_02242FAC(0x6d, 0xc, values, Save_PlayerData_GetOptionsAddr(PTR(p, 0x830)));
        PTR(obj, 0x220) = PTR(p, 0x14);
        PTR(obj, 0x224) = PTR(p, 0x18);
        PTR(obj, 0x228) = PTR(p, 0x1c);
        PTR(obj, 0x22c) = PTR(p, 0x24);
        PTR(obj, 0x230) = PTR(p, 0x28);
        *(Ov40Block32 *)((u8 *)obj + 0x2a8) = *(Ov40Block32 *)PTR(w, 0x4ac);
        PTR(obj, 0x2d4) = p;
        ov40_02241FD0(p);
        WORD(p, 8)
        ++;
    case 1:
        ov40_0222D910(w, (u8 *)w + 4, 8, 0x12, 8, 0x12, 0);
        GfGfx_EngineATogglePlanes(8, 1);
        WORD(p, 8)
        ++;
        break;
    case 2:
        ov40_0222DA84((int *)((u8 *)w + 8), 0);
        if (ov40_0222DA00(w, (int *)((u8 *)w + 4), 0, 0)) {
            ov40_0222DD9C(p, 0x70);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 2, 0xc);
        break;
    default:
        ov40_0222BF80(p, 3);
        break;
    }
    return 0;
}

int ov40_02240520(void *p) {
    void *w = PTR(p, 0x860);

    if (ov40_02243538((u8 *)w + 0x1d4) == 1) {
        ov40_0222BF80(p, 4);
    }
    return 0;
}

int ov40_02240544(void *p) {
    void *w = PTR(p, 0x860);
    void *obj = (u8 *)w + 0x1d4;

    switch (WORD(p, 8)) {
    case 0:
        ov40_0222DE40(p);
        ov40_0222D980(w, (u8 *)w + 4, 8, 0x12, 8, 0x12, 0);
        ov40_02242FF8(PTR(w, 0x4ac));
        WORD(p, 8)
        ++;
    case 1:
        ov40_0222DA84((int *)((u8 *)w + 8), 1);
        if (ov40_0222DA00(w, (int *)((u8 *)w + 4), 1, 0)) {
            GfGfx_EngineATogglePlanes(8, 0);
            ov40_02242084(p);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 2, 0xc);
        break;
    default:
        if (PTR(obj, 0x2c8) != NULL) {
            ov40_0222BF80(p, 6);
        } else {
            ov40_0222BF80(p, 5);
        }
        break;
    }
    return 0;
}

int ov40_022405F0(void *p) {
    void *w = PTR(p, 0x860);

    if (WORD(p, 8) == 0) {
        ov40_0222DAA8((u8 *)w + 8);
        ov40_02230964(p, (void *)1);
        ov40_0222D88C(p);
        ov40_02230964(p, NULL);
        WORD(p, 8)
        ++;
    } else if (ov40_0222DA84((int *)((u8 *)w + 8), 0)) {
        ov40_0222DD08(p);
        ov40_0222DAA8((u8 *)w + 8);
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xc, 0x10, (u16)WORD(p, 0x58));
        ov40_0222BF64(p, 1, TRUE, (u32 *)PTR(p, 0x10));
        ov40_0222BF80(p, 5);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
        Heap_Free(w);
    } else {
        BLEND(p, w, 3, 0xc);
        BLEND(p, w, 1, 2);
    }
    return 0;
}

int ov40_022406C8(void *p) {
    void *w = PTR(p, 0x860);
    void *obj = (u8 *)w + 0x1d4;
    void *result;

    switch (WORD(p, 8)) {
    case 0:
        ov40_0222DD9C(p, 0x75);
        ov40_0223077C(p, PTR(p, 0x6f4), 0x80, 0x60);
        sub_020879E0(PTR(p, 0x6f4), 1);
        sub_02087A08(PTR(p, 0x6f4), 0x18, 0x18);
        WORD(w, 0x4b8) = 0;
        PlaySE(0x57d);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (!ov40_0223D5CC(p)) {
            return 0;
        }
        if (ov39_02227720(ov40_0223D540(p), PTR(obj, 0x2cc), PTR(obj, 0x2d0)) == 1) {
            WORD(p, 8)
            ++;
        }
        break;
    case 2:
        if (!ov40_0223D5CC(p)) {
            return 0;
        }
        ov40_0222DE40(p);
        if (ov39_02227D44(ov40_0223D540(p), &result) == 1) {
            StopSE(0x57d, 0);
            *(vu16 *)0x04000050 = 0;
            ov40_02230CDC(p, 8, PTR(result, 0xc), PTR(result, 4));
            ov40_0222FB90(p, 0);
            WORD(p, 8)
            ++;
            WORD(w, 0x4b8) = 0;
        } else {
            StopSE(0x57d, 0);
            WORD(p, 8) = 0xff;
            WORD(w, 0x4b8) = 1;
            PlaySE(0x577);
            PTR(p, 0x878) = (u8 *)p + 0x2604;
            PTR(w, 0x4bc) = PTR(p, 0x8b4);
            MI_CpuCopy8(PTR(w, 0x4bc), (u8 *)p + 0x8b8, 0x1d4c);
        }
        sub_020879E0(PTR(p, 0x6f4), 0);
        sub_02087A08(PTR(p, 0x6f4), 0, 0);
        break;
    case 3:
        ov40_0222FB90(p, 1);
        WORD(p, 8)
        ++;
        break;
    case 4:
        WORD(p, 8)
        ++;
        break;
    default:
        if (WORD(w, 0x4b8) != 0) {
            ov40_0222BF80(p, 7);
        } else {
            ov40_0222BF80(p, 5);
        }
        break;
    }
    return 0;
}

void ov40_0224085C(void *p) {
    void *w = PTR(p, 0x860);

    PTR(w, 0x80) = sub_020314A4(0x6d);
    ov39_022271C0(PTR(w, 0x4bc), PTR(w, 0x80));
    PTR(w, 0x10c) = PTR(w, 0x80);
    PTR(w, 0x110) = sub_02030920(0x6d);
    MI_CpuCopy8((u8 *)PTR(w, 0x4bc) + 0x80, PTR(w, 0x110), 0x64);
}

void ov40_022408AC(void *p) {
    void *w = PTR(p, 0x860);

    PTR(w, 0x80) = sub_020314A4(0x6d);
    ov39_022271C0(PTR(p, 0x2608 + WORD(p, 0x4d4) * 4), PTR(w, 0x80));
    PTR(w, 0x10c) = PTR(w, 0x80);
    PTR(w, 0x110) = sub_02030920(0x6d);
    MI_CpuCopy8((u8 *)PTR(p, 0x2608 + WORD(p, 0x4d4) * 4) + 0x80, PTR(w, 0x110), 0x64);
}

void ov40_02240910(void *p) {
    void *w = PTR(p, 0x860);

    sub_02030938(PTR(w, 0x110));
    sub_020314BC(PTR(w, 0x80));
}

int ov40_0224092C(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        ov40_0222FB90(p, 0);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222FBB4(p) != NULL) {
            ov40_0222D980(w, (u8 *)w + 4, 8, 0x12, 8, 0x12, 0);
            GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3e, PTR(p, 0x24), 3, 0, 0, 0, 0x6d);
            GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3e, PTR(p, 0x24), 7, 0, 0, 0, 0x6d);
            ov40_022307DC(p, 6, 7);
            SetBgPriority(0, 1);
            SetBgPriority(1, 3);
            SetBgPriority(2, 0);
            SetBgPriority(3, 1);
            SetBgPriority(4, 1);
            SetBgPriority(5, 3);
            SetBgPriority(6, 0);
            SetBgPriority(7, 2);
            ov40_0224085C(p);
            ov40_02242110(p);
            PTR(w, 0x608) = TouchHitboxController_Create(ov40_022456B4, 4, ov40_02241C10, p, 0x6d);
            PTR(w, 0x60c) = TouchHitboxController_Create(ov40_02245674, 4, ov40_02241C70, p, 0x6d);
            PTR(w, 0x610) = TouchHitboxController_Create(ov40_02245654, 2, ov40_02241CD8, p, 0x6d);
            WORD(p, 8)
            ++;
        }
        break;
    case 2:
        ov40_02230964(p, (void *)1);
        WORD(w, 0x1cc) = 0;
        ov40_02230638((u8 *)w + 0x10c, p);
        ov40_022307DC(p, ov40_02230410((u8 *)w + 0x10c), 3);
        ov40_022306A0((u8 *)w + 0x10c, 0);
        ov40_02230964(p, NULL);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        GfGfx_EngineATogglePlanes(4, 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222DA84((int *)((u8 *)w + 8), 0);
        if (ov40_0222DA00(w, (int *)((u8 *)w + 4), 0, 0)) {
            ov40_022306A0((u8 *)w + 0x10c, 1);
            ov40_02241AB0(p);
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            WORD(p, 8)
            ++;
        }
        BLEND(p, w, 3, 0xc);
        break;
    default:
        ov40_0222BF80(p, 8);
        break;
    }
    return 0;
}
