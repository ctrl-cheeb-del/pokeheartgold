#include "to47_overlay65_resources_r4_4_private.h"

void ov65_0221D280(void *work, void *narc) {
    void *bgConfig = PTR_AT(work, 0x180);

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, 4, 0, 0x120, 0x1A);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, 0, 0, 0x120, 0x1A);
    BG_SetMaskColor(0, 0);
    BG_SetMaskColor(4, 0);
    LoadFontPal1(0, 0x1A0, 0x1A);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, bgConfig, 2, 0, 0x2400, 1, 0x1A);
    ov65_0221D204(narc, 3, bgConfig, 2, 0, 0x600, 1, 0x1A);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 4, bgConfig, 3, 0, 0x600, 1, 0x1A);
    LoadFontPal1(0, 0x40, 0x1A);
    LoadFontPal0(0, 0x60, 0x1A);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, 5, 0, 0x800, 1, 0x1A);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 5, bgConfig, 5, 0, 0x600, 1, 0x1A);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 6, bgConfig, 6, 0, 0x600, 1, 0x1A);
    LoadFontPal1(4, 0x40, 0x1A);
    LoadFontPal0(4, 0x60, 0x1A);
    BgClearTilemapBufferAndCommit(bgConfig, 4);
}

void ov65_0221D3B8(void) {
    Ov65CharTransferConfigR4 config = ov65_0221FD48;

    ObjCharTransfer_Init(&config);
    ObjPlttTransfer_Init(0x14, 0x1A);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}

void ov65_0221D3E8(void *work, void *narc) {
    typedef struct {
        u8 pad[0x2CC];
        void *managers[4];
    } ManagerState;
    u8 *state = work;
    int i;
    ManagerState *managerState = work;

    NNS_G2dInitOamManagerModule();
    OamManager_Create(0, 0x64, 0, 0x20, 0, 0x64, 0, 0x20, 0x1A);
    PTR_AT(state, 0x1A0) = G2dRenderer_Init(0x2D, state + 0x1A4, 0x1A);
    for (i = 0; i < 4; i++) {
        managerState->managers[i] = Create2DGfxResObjMan(2, i, 0x1A);
    }
    PTR_AT(state, 0x2DC) = AddCharResObjFromOpenNarc(PTR_AT(state, 0x2CC), narc, 7, 1, 0, 1, 0x1A);
    PTR_AT(state, 0x2E0) = AddPlttResObjFromOpenNarc(PTR_AT(state, 0x2D0), narc, 0, 0, 0, 1, 9, 0x1A);
    PTR_AT(state, 0x2E4) = AddCellOrAnimResObjFromOpenNarc(PTR_AT(state, 0x2D4), narc, 8, 1, 0, 2, 0x1A);
    PTR_AT(state, 0x2E8) = AddCellOrAnimResObjFromOpenNarc(PTR_AT(state, 0x2D8), narc, 9, 1, 0, 3, 0x1A);
    PTR_AT(state, 0x2EC) = AddCharResObjFromOpenNarc(PTR_AT(state, 0x2CC), narc, 0xA, 1, 1, 2, 0x1A);
    PTR_AT(state, 0x2F0) = AddPlttResObjFromOpenNarc(PTR_AT(state, 0x2D0), narc, 0, 0, 1, 2, 0xA, 0x1A);
    PTR_AT(state, 0x2F4) = AddCellOrAnimResObjFromOpenNarc(PTR_AT(state, 0x2D4), narc, 0xB, 1, 1, 2, 0x1A);
    PTR_AT(state, 0x2F8) = AddCellOrAnimResObjFromOpenNarc(PTR_AT(state, 0x2D8), narc, 0xC, 1, 1, 3, 0x1A);
    SpriteTransfer_CreateCharTransferTask(PTR_AT(state, 0x2DC));
    SpriteTransfer_CreateCharTransferTask(PTR_AT(state, 0x2EC));
    SpriteTransfer_CreateExtPlttTransferTask(PTR_AT(state, 0x2E0));
    SpriteTransfer_CreateExtPlttTransferTask(PTR_AT(state, 0x2F0));
    GfGfxLoader_GXLoadPal(0x14, sub_02074490(), 1, 0x140, 0x80, 0x1A);
}

u32 ov65_0221D57C(u32 side, void *mon, void *dest, u16 *ids) {
    u32 personality;
    u32 species;

    GetPokemonSpriteCharAndPlttNarcIds(ids, mon, 2);
    personality = GetMonData(mon, 0, 0);
    species = GetMonData(mon, 5, 0);
    if (GetMonData(mon, 0x4C, 0) == 1 && species == 0x147) {
        species = 0x1EE;
    }
    sub_02014494(ids[0], ids[1], 0x1A, 0, 0, 10, 10, dest, personality, 0, 2, species);
    DC_FlushRange(dest, 0xC80);
    return side + 1;
}

void ov65_0221D5FC(void *window, void *party, u32 index, u32 value, u32 a4) {
    void *string = String_New(0x14, 0x1A);
    void *mon = Party_GetMonByIndex(party, index);

    GetMonData(mon, 0x77, string);
    FillWindowPixelBuffer(window, 0);
    ov65_0221FB4C(window, string, value, 0, a4, 1);
    String_Delete(string);
}
