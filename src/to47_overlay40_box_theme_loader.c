#include "to47_overlay40_box_theme_loader_private.h"

static inline void LoadBoxTheme(void *work, void *inner) {
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR_AT(work, 0x14), BYTE_AT(inner, 0x17A) * 3 + 0x8A, PTR_AT(work, 0x24), 3, 0, 0, 0, 0x6D);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(work, 0x14), BYTE_AT(inner, 0x17A) * 3 + 0x8C, PTR_AT(work, 0x24), 3, 0, 0, 0, 0x6D);
    PaletteData_LoadFromNarc(PTR_AT(work, 0x28), 0xBF, BYTE_AT(inner, 0x17A) * 3 + 0x8B, 0x6D, 0, 0x40, 0xC0, 0xC0);
    ov40_02237474(work);
    ov40_02237284(work);
}

void ov40_0223757C(void *work) {
    void *inner = PTR_AT(work, 0x860);

    SaveArray_PCStorage_Get(PTR_AT(work, 0x830));
    if (BYTE_AT(inner, 0x17A) >= 0x10 && BYTE_AT(inner, 0x17A) < 0x18) {
        BYTE_AT(inner, 0x17A) = 0;
    }
    if (BYTE_AT(inner, 0x17A) >= 0x28) {
        BYTE_AT(inner, 0x17A) = 0;
    }

    LoadBoxTheme(work, inner);
    ov40_022371E4(work, WORD_AT(inner, 0x1B0));
    ov40_02237144(work);
    ov40_02237030(work, 0x10E);
}

void ov40_02237644(void *work) {
    void *inner = PTR_AT(work, 0x860);
    void *pcStorage = SaveArray_PCStorage_Get(PTR_AT(work, 0x830));

    if (BYTE_AT(inner, 0x17A) >= 0x10 && BYTE_AT(inner, 0x17A) < 0x18) {
        BYTE_AT(inner, 0x17A) = 0;
    }
    if (BYTE_AT(inner, 0x17A) >= 0x18 && BYTE_AT(inner, 0x17A) < 0x20 && !PCStorage_IsBonusWallpaperUnlocked(pcStorage, BYTE_AT(inner, 0x17A) - 0x18)) {
        BYTE_AT(inner, 0x17A) = 0;
    }

    LoadBoxTheme(work, inner);
}

int ov40_022376FC(void *work) {
    void *inner = PTR_AT(work, 0x860);

    switch (WORD_AT(work, 8)) {
    case 0:
        ov40_0222C710(work, 2);
        ov40_02230964(work, 1);
        ov40_02236EB4(work);
        ov40_0223757C(work);
        ov40_02237548(work, 1);
        ov40_022373E4(work, 0);
        ov40_02230964(work, 0);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR_AT(work, 0x14), 0x3E, PTR_AT(work, 0x24), 7, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR_AT(work, 0x14), 0x4D, PTR_AT(work, 0x24), 7, 0, 0, 0, 0x6D);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        WORD_AT(work, 8)
        ++;
        break;
    case 1:
        if (ov40_0222DA00((u8 *)inner + 0x1A4, (u8 *)inner + 0x1A8, 0, 0)) {
            ov40_02237548(work, 0);
            ov40_022373E4(work, 1);
            GfGfx_EngineATogglePlanes(1, 1);
            GfGfx_EngineATogglePlanes(4, 1);
            *(u16 *)0x04000050 = 0;
            WORD_AT(work, 8)
            ++;
        }
        break;
    case 2:
        if (ov40_0222DA84((u8 *)inner + 0x1AC, 0)) {
            WORD_AT(inner, 0x344) = WORD_AT(inner, 0x330);
            ov40_0222BF80(work, 3);
        }
        PaletteData_BlendPalettes(PTR_AT(work, 0x28), 3, 0xC, (u8)WORD_AT(inner, 0x1AC), (u16)WORD_AT(work, 0x58));
        break;
    }
    return 0;
}
