#include "constants/battle.h"

#include "battle/battle_022378C0.h"
#include "battle/battle_022378C0_tail_private.h"
#include "battle/battle_controller_player.h"
#include "battle/battle_system.h"
#include "battle/overlay_12_0224E4FC.h"

#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "palette.h"
#include "render_window.h"
#include "unk_0200FA24.h"

void ov12_02237D00(BattleSystem *battleSystem);
void ov12_02237ED0(BattleSystem *battleSystem, int a1);
BOOL ov12_02238358(OverlayManager *man);

void ov12_022387AC(BattleSystem *battleSystem, BgConfig *bgConfig) {
    BattleBgTemplateSet templates;
    GraphicsBanks banks;
    GraphicsModes modes;
    u32 frame;

    GfGfx_DisableEngineAPlanes();

    banks = ov12_0226C0A8;
    GfGfx_SetBanks(&banks);

    MI_CpuClear32((void *)0x06000000, 0x80000);
    MI_CpuClear32((void *)0x06200000, 0x20000);
    MI_CpuClear32((void *)0x06400000, 0x40000);
    MI_CpuClear32((void *)0x06600000, 0x20000);

    SetMasterBrightnessNeutral(0);
    SetMasterBrightnessNeutral(1);

    modes = ov12_0226BFE8;
    SetBothScreensModesAndDisable(&modes);

    battleSystem->unk240F_0 = 1;

    templates = ov12_0226C174;

    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &templates.templates[0], 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &templates.templates[1], 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &templates.templates[2], 0);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_3);

    G2_SetBG0Priority(1);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);

    BgConfig_InitBattleMenuBackgrounds(bgConfig);

    frame = BattleSystem_GetFrame(battleSystem);
    sub_0200EB80(bgConfig, GF_BG_LYR_MAIN_1, 1, 10, frame, HEAP_ID_BATTLE);

    GfGfxLoader_LoadCharData(NARC_a_0_0_7, battleSystem->backgroundId + 3, bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_BATTLE);
    PaletteData_LoadNarc(battleSystem->palette, NARC_a_0_0_7, battleSystem->backgroundId * 3 + 0xB0 + ov12_0223B52C(battleSystem), HEAP_ID_BATTLE, (PaletteBufferId)0, 0, 0);
    PaletteData_LoadNarc(battleSystem->palette, NARC_a_0_3_8, sub_0200E640(frame), HEAP_ID_BATTLE, (PaletteBufferId)0, 0x20, 0xA0);
    PaletteData_LoadNarc(battleSystem->palette, NARC_graphic_font, 8, HEAP_ID_BATTLE, (PaletteBufferId)0, 0x20, 0xB0);
    GfGfxLoader_LoadScrnData(NARC_a_0_0_7, 2, bgConfig, GF_BG_LYR_MAIN_3, 0, 0, TRUE, HEAP_ID_BATTLE);

    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_NONE, FALSE);
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_NONE, FALSE);

    GfGfx_BothDispOn();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);

    Main_SetVBlankIntrCB(ov12_02239730, battleSystem);
}

void ov12_022389B8(BattleSystem *battleSystem) {
    BattleContext *ctx;
    int i;
    Terrain terrain = BattleSystem_GetTerrainId(battleSystem);

    ov12_02265FD4(&battleSystem->unk17C[0], battleSystem, 0, terrain);
    ov12_02265FD4(&battleSystem->unk17C[1], battleSystem, 1, terrain);

    ctx = BattleSystem_GetBattleContext(battleSystem);

    for (i = 0; i < battleSystem->maxBattlers; i++) {
        int battlerId = ov12_022581D4(battleSystem, ctx, 2, i);
        ov12_02258DB0(battleSystem, battleSystem->opponentData[i], BattleSystem_GetMonBall(battleSystem, BattleSystem_GetPartyMon(battleSystem, i, battlerId)), battlerId);
    }

    ov12_0223A7A0();
}
