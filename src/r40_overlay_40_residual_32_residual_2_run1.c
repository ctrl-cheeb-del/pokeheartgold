#include "r40_overlay_40_residual_32_residual_2_private.h"

typedef struct Ov40PartialState {
    u32 unk0;
    u32 unk4;
    s32 state;
} Ov40PartialState;

int ov40_02239EFC(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 0x21, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 0x22, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        ov40_02239418(p);
        ov40_02239574(p);
        ov40_02230964(p, 1);
        ov40_0222F9E0((u8 *)p + 0x47C, p, 2);
        ov40_02238F00(p);
        ov40_02230964(p, 0);
        ov40_02239340(p);
        GfGfx_EngineATogglePlanes(8, 1);
        GfGfx_EngineBTogglePlanes(8, 1);
        {
            Ov40PartialState *state = p;
            s32 nextState = state->state;
            nextState++;
            state->state = nextState;
        }
        break;
    case 1:
        ov40_0222DA84((u8 *)w + 8, 0);
        if (ov40_0222DA00(w, (u8 *)w + 4, 0, 0)) {
            GfGfx_EngineATogglePlanes(4, 1);
            GfGfx_EngineBTogglePlanes(4, 1);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, WORD(w, 8), WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 6);
        break;
    }
    return 0;
}
