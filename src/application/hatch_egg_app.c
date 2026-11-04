#include "hatch_egg_app.h"

#include "global.h"

#include "constants/sndseq.h"
#include "constants/species.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0187.h"

#include "bg_window.h"
#include "field_environment_sound.h"
#include "filesystem.h"
#include "font.h"
#include "gf_3d_vramman.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "hatch_egg_app_internal.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "obj_pltt_transfer.h"
#include "options.h"
#include "palette.h"
#include "pm_string.h"
#include "pokemon.h"
#include "pokepic.h"
#include "pokepic_anim_internal.h"
#include "render_text.h"
#include "screen_fade.h"
#include "sound_chatot.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "sprite_system.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"
#include "vram_transfer_manager.h"

enum HatchEggSceneType {
    HATCH_EGG_SCENE_TYPE_EGG,
    HATCH_EGG_SCENE_TYPE_MANAPHY,
};

enum HatchEggSceneState {
    HATCH_EGG_SCENE_SETUP,
    HATCH_EGG_SCENE_FADE_IN,
    HATCH_EGG_SCENE_WAIT_FADE_IN,
    HATCH_EGG_SCENE_WAIT_BEFORE_SHAKE,
    HATCH_EGG_SCENE_SHAKE_ONCE,
    HATCH_EGG_SCENE_SHAKE_TWICE,
    HATCH_EGG_SCENE_SHAKE_CRACK,
    HATCH_EGG_SCENE_HATCH,
    HATCH_EGG_SCENE_WAIT_CRY,
    HATCH_EGG_SCENE_WAIT_FANFARE,
    HATCH_EGG_SCENE_PRINT_NICKNAME_PROMPT,
    HATCH_EGG_SCENE_SHOW_YES_NO,
    HATCH_EGG_SCENE_HANDLE_YES_NO,
    HATCH_EGG_SCENE_FADE_OUT = 15,
    HATCH_EGG_SCENE_WAIT_FADE_OUT,
    HATCH_EGG_SCENE_FREE,
};

enum HatchEggYesNo {
    HATCH_EGG_YES_NO_NONE,
    HATCH_EGG_YES_NO_YES,
    HATCH_EGG_YES_NO_NO,
};

enum HatchEggYesNoMenuState {
    HATCH_EGG_YES_NO_MENU_INPUT,
    HATCH_EGG_YES_NO_MENU_WAIT_PRESS,
};

enum HatchEggAppState {
    HATCH_EGG_APP_STATE_INIT,
    HATCH_EGG_APP_STATE_RUN_SCENE,
    HATCH_EGG_APP_STATE_WAIT_FADE,
};

typedef BOOL (*HatchEggSceneFunc)(HatchEggApp *app);

static BOOL HatchEggApp_RunScene(HatchEggApp *app);
static BOOL HatchEggApp_RunEggScene(HatchEggApp *app);
static BOOL HatchEggApp_RunManaphyEggScene(HatchEggApp *app);
static BOOL HatchEggApp_WaitBeforeShake(HatchEggApp *app);
static BOOL HatchEggApp_ShakeEggOnce(HatchEggApp *app);
static BOOL HatchEggApp_ShakeEggTwice(HatchEggApp *app);
static BOOL HatchEggApp_ShakeEggCrack(HatchEggApp *app);
static BOOL HatchEggApp_HatchEgg(HatchEggApp *app);
static BOOL HatchEggApp_HatchManaphyEgg(HatchEggApp *app);
static void HatchEggYesNoMenu_InitBgs(BgConfig *bgConfig);
static HatchEggYesNoMenu *HatchEggYesNoMenu_New(BgConfig *bgConfig, SpriteSystem *spriteSystem, SpriteManager *spriteManager, enum HeapID heapId);
static void HatchEggYesNoMenu_Free(HatchEggYesNoMenu *menu);
static void HatchEggYesNoMenu_LoadGfx(HatchEggYesNoMenu *menu, PaletteData *paletteData, int charResId, int plttResId, int cellResId, int animResId);
static void HatchEggYesNoMenu_Show(HatchEggYesNoMenu *menu, u32 yesMsgId, u32 noMsgId);
static int HatchEggYesNoMenu_Run(HatchEggYesNoMenu *menu);
static void HatchEggYesNoMenu_AddWindows(HatchEggYesNoMenu *menu);
static void HatchEggYesNoMenu_RemoveWindows(HatchEggYesNoMenu *menu);
static void HatchEggYesNoMenu_PrintButton(HatchEggYesNoMenu *menu, Window *window, u32 msgId);
static void HatchEggYesNoMenu_CreateCursor(HatchEggYesNoMenu *menu, int charResId, int plttResId, int cellResId, int animResId);
static void HatchEggYesNoMenu_DeleteCursor(HatchEggYesNoMenu *menu);
static void HatchEggYesNoMenu_UpdateCursor(HatchEggYesNoMenu *menu);
static BOOL HatchEggYesNoMenu_HandleInput(HatchEggYesNoMenu *menu);
static BOOL HatchEggYesNoMenu_IsPressAnimFinished(HatchEggYesNoMenu *menu);

static const HatchEggSceneFunc sHatchEggSceneFuncs[] = {
    [HATCH_EGG_SCENE_TYPE_EGG] = HatchEggApp_RunEggScene,
    [HATCH_EGG_SCENE_TYPE_MANAPHY] = HatchEggApp_RunManaphyEggScene,
};

static const s16 sHatchEggYesNoCursorPositions[][2] = {
    { 128, 72  },
    { 128, 120 },
};

static const TouchscreenHitbox sHatchEggYesNoHitboxes[] = {
    { .rect = { 50, 92, 3, 251 } },
    { .rect = { 99, 140, 3, 251 } },
    { .rect = { TOUCHSCREEN_RECTLIST_END } },
};

static const ManagedSpriteTemplate sHatchEggYesNoCursorTemplate = {
    .x = 0,
    .y = 0,
    .z = 0,
    .animation = 0,
    .drawPriority = 0,
    .pal = 0xFFFF,
    .vram = NNS_G2D_VRAM_TYPE_2DSUB,
    .resIdList = { 0, 0, 0, 0, 0, 0 },
    .bgPriority = 0,
    .vramTransfer = 0,
};

static const HatchEggBgTemplates sHatchEggYesNoBgTemplates = {
    .templates = {
                  {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x7000,
            .charBase = GX_BG_CHARBASE_0x04000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 2,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = FALSE,
        },
                  {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x6800,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 1,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = FALSE,
        },
                  {
            .x = 0,
            .y = 0,
            .bufferSize = GF_BG_BUF_SIZE_256x256_4BPP,
            .baseTile = 0,
            .size = GF_BG_SCR_SIZE_256x256,
            .colorMode = GX_BG_COLORMODE_16,
            .screenBase = GX_BG_SCRBASE_0x6000,
            .charBase = GX_BG_CHARBASE_0x00000,
            .bgExtPltt = GX_BG_EXTPLTT_01,
            .priority = 0,
            .areaOver = GX_BG_AREAOVER_XLU,
            .dummy = 0,
            .mosaic = FALSE,
        },
                  },
};

static BOOL HatchEggApp_RunScene(HatchEggApp *app) {
    return sHatchEggSceneFuncs[app->sceneType](app);
}

static BOOL HatchEggApp_RunEggScene(HatchEggApp *app) {
    BOOL ret = TRUE;
    switch (app->state) {
    case HATCH_EGG_SCENE_SETUP: {
        HatchEggParticlesParam param;
        HatchEggApp_LoadBackground(app->gfx.bgConfig, app->gfx.paletteData);
        HatchEggApp_LoadWindowGfx(app->gfx.bgConfig, app->gfx.paletteData, app->gfx.frame);
        HatchEggApp_CreateMessageWindow(app->gfx.bgConfig, &app->gfx.window, GF_BG_LYR_MAIN_1, 2, 19, 27, 4, 59, 14);
        HatchEggApp_LoadSpriteResources(app);
        HatchEggApp_CreateSprites(app);
        HatchEggYesNoMenu_LoadGfx(app->yesNoMenu, app->gfx.paletteData, 21000, 21001, 21002, 21003);
        HatchEggApp_CreatePokepic(app);
        HatchEggApp_SetPokepicVanished(app, TRUE);
        param.heapId = HEAP_ID_70;
        param.fileId = 0;
        app->gfx.particles = HatchEggParticles_New(&param);
        app->state++;
        break;
    }
    case HATCH_EGG_SCENE_FADE_IN:
        HatchEggApp_FadeIn();
        app->state++;
    case HATCH_EGG_SCENE_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            Sound_Stop();
            Sound_SetSceneAndPlayBGM(13, SEQ_GS_SHINKA, 1);
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_WAIT_BEFORE_SHAKE:
        if (!HatchEggApp_WaitBeforeShake(app)) {
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_SHAKE_ONCE:
        if (!HatchEggApp_ShakeEggOnce(app)) {
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_SHAKE_TWICE:
        if (!HatchEggApp_ShakeEggTwice(app)) {
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_SHAKE_CRACK:
        if (!HatchEggApp_ShakeEggCrack(app)) {
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_HATCH:
        if (!HatchEggApp_HatchEgg(app)) {
            HatchEggApp_StartPokepicAnim(app);
            PlayCry(GetMonData(app->args->args.mon, MON_DATA_SPECIES, NULL), GetMonData(app->args->args.mon, MON_DATA_FORM, NULL));
            app->gfx.printerId = HatchEggApp_PrintMessage(&app->gfx.window, msg_0187_00000, app->args->args.mon, app->gfx.textSpeed);
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_WAIT_CRY:
        if (IsCryPlaying()) {
            break;
        }
        PlayFanfare(SEQ_ME_SHINKAOME);
        app->state++;
    case HATCH_EGG_SCENE_WAIT_FANFARE:
        if (IsFanfarePlaying()) {
            break;
        }
        app->state++;
    case HATCH_EGG_SCENE_PRINT_NICKNAME_PROMPT:
        if (TextPrinterCheckActive(app->gfx.printerId)) {
            break;
        }
        app->gfx.printerId = HatchEggApp_PrintMessage(&app->gfx.window, msg_0187_00001, app->args->args.mon, app->gfx.textSpeed);
        app->state++;
    case HATCH_EGG_SCENE_SHOW_YES_NO:
        if (TextPrinterCheckActive(app->gfx.printerId)) {
            break;
        }
        if (PokepicAnimManager_GetAnimState(app->picManager, 0) != TRUE) {
            break;
        }
        if (Pokepic_IsAnimFinished(app->pokepic)) {
            break;
        }
        HatchEggYesNoMenu_Show(app->yesNoMenu, 2, 3);
        app->state++;
        break;
    case HATCH_EGG_SCENE_HANDLE_YES_NO:
        switch (HatchEggYesNoMenu_Run(app->yesNoMenu)) {
        case HATCH_EGG_YES_NO_YES:
            app->args->wantToNameNewMon = TRUE;
            app->state++;
            break;
        case HATCH_EGG_YES_NO_NO:
            app->args->wantToNameNewMon = FALSE;
            app->state++;
            break;
        }
        break;
    case 13:
        app->state++;
        break;
    case 14:
        app->state++;
        break;
    case HATCH_EGG_SCENE_FADE_OUT:
        HatchEggApp_FadeOut();
        app->state++;
    case HATCH_EGG_SCENE_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_FREE:
    default:
        HatchEggApp_DeletePokepic(app);
        HatchEggApp_DeleteSprites(app);
        HatchEggApp_RemoveMessageWindow(&app->gfx.window);
        HatchEggApp_DestroyParticleSystem(app->gfx.particles->particleSystem);
        HatchEggParticles_Free(app->gfx.particles);
        ret = FALSE;
        break;
    }
    SpriteSystem_DrawSprites(app->gfx.spriteManager);
    return ret;
}

static BOOL HatchEggApp_RunManaphyEggScene(HatchEggApp *app) {
    BOOL ret = TRUE;
    switch (app->state) {
    case HATCH_EGG_SCENE_SETUP: {
        HatchEggParticlesParam param;
        HatchEggApp_LoadBackground(app->gfx.bgConfig, app->gfx.paletteData);
        HatchEggApp_LoadWindowGfx(app->gfx.bgConfig, app->gfx.paletteData, app->gfx.frame);
        HatchEggApp_CreateMessageWindow(app->gfx.bgConfig, &app->gfx.window, GF_BG_LYR_MAIN_1, 2, 19, 27, 4, 59, 14);
        HatchEggApp_LoadSpriteResources(app);
        HatchEggApp_CreateSprites(app);
        ManagedSprite_SetDrawFlag(app->eggSprite, FALSE);
        HatchEggYesNoMenu_LoadGfx(app->yesNoMenu, app->gfx.paletteData, 21000, 21001, 21002, 21003);
        HatchEggApp_CreatePokepic(app);
        HatchEggApp_SetPokepicVanished(app, TRUE);
        param.heapId = HEAP_ID_70;
        param.fileId = 1;
        app->gfx.particles = HatchEggParticles_New(&param);
        app->state++;
        break;
    }
    case HATCH_EGG_SCENE_FADE_IN:
        HatchEggApp_FadeIn();
        app->state++;
    case HATCH_EGG_SCENE_WAIT_FADE_IN:
        if (IsPaletteFadeFinished() == TRUE) {
            Sound_SetSceneAndPlayBGM(13, SEQ_GS_SHINKA, 1);
            app->state++;
        }
        break;
    case 3:
        if (!HatchEggApp_HatchManaphyEgg(app)) {
            HatchEggApp_StartPokepicAnim(app);
            PlayCry(GetMonData(app->args->args.mon, MON_DATA_SPECIES, NULL), GetMonData(app->args->args.mon, MON_DATA_FORM, NULL));
            app->gfx.printerId = HatchEggApp_PrintMessage(&app->gfx.window, msg_0187_00000, app->args->args.mon, app->gfx.textSpeed);
            app->state = HATCH_EGG_SCENE_WAIT_CRY;
        }
        break;
    case HATCH_EGG_SCENE_SHAKE_ONCE:
    case HATCH_EGG_SCENE_SHAKE_TWICE:
    case HATCH_EGG_SCENE_SHAKE_CRACK:
    case HATCH_EGG_SCENE_HATCH:
        GF_ASSERT(FALSE);
        break;
    case HATCH_EGG_SCENE_WAIT_CRY:
        if (IsCryPlaying()) {
            break;
        }
        PlayFanfare(SEQ_ME_SHINKAOME);
        app->state++;
    case HATCH_EGG_SCENE_WAIT_FANFARE:
        if (IsFanfarePlaying()) {
            break;
        }
        app->state++;
    case HATCH_EGG_SCENE_PRINT_NICKNAME_PROMPT:
        if (TextPrinterCheckActive(app->gfx.printerId)) {
            break;
        }
        app->gfx.printerId = HatchEggApp_PrintMessage(&app->gfx.window, msg_0187_00001, app->args->args.mon, app->gfx.textSpeed);
        app->state++;
    case HATCH_EGG_SCENE_SHOW_YES_NO:
        if (TextPrinterCheckActive(app->gfx.printerId)) {
            break;
        }
        if (PokepicAnimManager_GetAnimState(app->picManager, 0) != TRUE) {
            break;
        }
        if (Pokepic_IsAnimFinished(app->pokepic)) {
            break;
        }
        HatchEggYesNoMenu_Show(app->yesNoMenu, 2, 3);
        app->state++;
        break;
    case HATCH_EGG_SCENE_HANDLE_YES_NO:
        switch (HatchEggYesNoMenu_Run(app->yesNoMenu)) {
        case HATCH_EGG_YES_NO_YES:
            app->args->wantToNameNewMon = TRUE;
            app->state++;
            break;
        case HATCH_EGG_YES_NO_NO:
            app->args->wantToNameNewMon = FALSE;
            app->state++;
            break;
        }
        break;
    case 13:
        app->state++;
        break;
    case 14:
        app->state++;
        break;
    case HATCH_EGG_SCENE_FADE_OUT:
        HatchEggApp_FadeOut();
        app->state++;
    case HATCH_EGG_SCENE_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished() == TRUE) {
            app->state++;
        }
        break;
    case HATCH_EGG_SCENE_FREE:
    default:
        HatchEggApp_DeletePokepic(app);
        HatchEggApp_DeleteSprites(app);
        HatchEggApp_RemoveMessageWindow(&app->gfx.window);
        HatchEggApp_DestroyParticleSystem(app->gfx.particles->particleSystem);
        HatchEggParticles_Free(app->gfx.particles);
        ret = FALSE;
        break;
    }
    SpriteSystem_DrawSprites(app->gfx.spriteManager);
    return ret;
}

static BOOL HatchEggApp_WaitBeforeShake(HatchEggApp *app) {
    switch (app->subState) {
    case 0:
        ManagedSprite_SetAnimationFrame(app->eggSprite, 0);
        app->subState++;
        break;
    case 1:
        app->timer++;
        if (app->timer >= 25) {
            PlaySE(SEQ_SE_DP_EGG01);
            app->subState++;
        }
        break;
    default:
        app->subState = 0;
        app->timer = 0;
        return FALSE;
    }
    return TRUE;
}

static BOOL HatchEggApp_ShakeEggOnce(HatchEggApp *app) {
    switch (app->subState) {
    case 0:
        if (HatchEggParticles_IsRunning(app->gfx.particles) != TRUE) {
            ManagedSprite_SetAnimationFrame(app->eggSprite, 1);
            app->subState++;
        }
        break;
    case 1:
        if (HatchEggApp_UpdateEggShake(app, 0) == HATCH_EGG_SHAKE_ENDED) {
            PlaySE(SEQ_SE_DP_EGG01);
            ManagedSprite_SetAnimationFrame(app->eggSprite, 2);
            app->subState++;
            app->timer = 0;
        }
        break;
    default:
        if (HatchEggApp_UpdateEggShake(app, 0) == HATCH_EGG_SHAKE_ENDED) {
            ManagedSprite_SetAnimationFrame(app->eggSprite, 2);
            app->subState = 0;
            app->timer = 0;
            return FALSE;
        }
        break;
    }
    return TRUE;
}

static BOOL HatchEggApp_ShakeEggTwice(HatchEggApp *app) {
    switch (app->subState) {
    case 0:
        app->subState++;
        break;
    case 1: {
        enum HatchEggShakeResult status = HatchEggApp_UpdateEggShake(app, 1);
        if (status == HATCH_EGG_SHAKE_HIT) {
            PlaySE(SEQ_SE_DP_EGG01);
            ManagedSprite_SetAnimationFrame(app->eggSprite, 3);
            HatchEggParticles_Emit(app->gfx.particles, 0);
        }
        if (status == HATCH_EGG_SHAKE_ENDED) {
            app->timer = 0;
            app->subState++;
        }
        break;
    }
    default:
        app->subState = 0;
        app->timer = 0;
        return FALSE;
    }
    return TRUE;
}

static BOOL HatchEggApp_ShakeEggCrack(HatchEggApp *app) {
    switch (app->subState) {
    case 0:
        if (HatchEggParticles_IsRunning(app->gfx.particles) != TRUE) {
            app->subState++;
        }
        break;
    case 1: {
        enum HatchEggShakeResult status = HatchEggApp_UpdateEggShake(app, 2);
        if (status == HATCH_EGG_SHAKE_HIT) {
            PlaySE(SEQ_SE_DP_EGG01);
            ManagedSprite_SetAnimationFrame(app->eggSprite, 4);
            HatchEggParticles_Emit(app->gfx.particles, 1);
        }
        if (status == HATCH_EGG_SHAKE_ENDED) {
            app->timer = 0;
            app->subState++;
        }
        break;
    }
    default:
        app->subState = 0;
        app->timer = 0;
        return FALSE;
    }
    return TRUE;
}

// The egg bursts, the screen flashes white and the bars slide off-screen to reveal the Pokemon.
static BOOL HatchEggApp_HatchEgg(HatchEggApp *app) {
    struct {
        s16 y;
        s16 x;
    } pos;
    int done;
    enum HatchEggShakeResult status;
    u32 plttOffset;
    switch (app->subState) {
    case 0:
        if (HatchEggParticles_IsRunning(app->gfx.particles) == TRUE) {
            break;
        }
        ManagedSprite_SetAnimationFrame(app->eggSprite, 4);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
        app->subState++;
        break;
    case 1:
        status = HatchEggApp_UpdateEggShake(app, 3);
        if (status == HATCH_EGG_SHAKE_HIT) {
            ManagedSprite_SetAnimationFrame(app->eggSprite, 5);
            PlaySE(SEQ_SE_DP_BOWA3);
            HatchEggParticles_Emit(app->gfx.particles, 2);
            HatchEggParticles_Emit(app->gfx.particles, 3);
        }
        if (status == HATCH_EGG_SHAKE_ENDED) {
            ManagedSprite_SetDrawFlag(app->eggSprite, FALSE);
            app->timer = 0;
            app->subState++;
        }
        break;
    case 2:
        app->timer++;
        if (app->timer < 10) {
            break;
        }
        app->timer = 0;
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 1, 0xffff, 0, 0, 16, 0xffff);
        plttOffset = ObjPlttTransfer_GetPaletteVramOffset(Sprite_GetPaletteProxy(app->topBar->sprite), NNS_G2D_VRAM_TYPE_2DMAIN);
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 4, (u16)(0xffff ^ (1 << plttOffset)), 0, 0, 16, 0xffff);
        Pokepic_StartPaletteFade(app->pokepic, 0, 16, 0, 0xffff);
        app->subState++;
        break;
    case 3:
        done = 0;
        ManagedSprite_GetPositionXY(app->topBar, &pos.x, &pos.y);
        if (pos.y > -48) {
            ManagedSprite_OffsetPositionXY(app->topBar, 0, -4);
        } else {
            done++;
        }
        ManagedSprite_GetPositionXY(app->bottomBar, &pos.x, &pos.y);
        if (pos.y < 192) {
            ManagedSprite_OffsetPositionXY(app->bottomBar, 0, 4);
        } else {
            done++;
        }
        if (PaletteData_GetSelectedBuffersBitmask(app->gfx.paletteData) != 0 || done != 2 || Pokepic_ResumePaletteFade(app->pokepic)) {
            break;
        }
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
        HatchEggApp_SetPokepicVanished(app, FALSE);
        ManagedSprite_SetDrawFlag(app->eggSprite, FALSE);
        ManagedSprite_SetDrawFlag(app->topBar, FALSE);
        ManagedSprite_SetDrawFlag(app->bottomBar, FALSE);
        app->subState++;
        break;
    case 4:
        app->timer++;
        if (app->timer < 25) {
            break;
        }
        app->timer = 0;
        Pokepic_StartPaletteFade(app->pokepic, 16, 0, 0, 0xffff);
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 1, 0xffff, 0, 16, 0, 0xffff);
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 4, 0xffff, 0, 16, 0, 0xffff);
        app->subState++;
        break;
    case 5:
        if (PaletteData_GetSelectedBuffersBitmask(app->gfx.paletteData) != 0 || Pokepic_ResumePaletteFade(app->pokepic)) {
            break;
        }
        app->subState++;
        break;
    default:
        if (HatchEggParticles_IsRunning(app->gfx.particles) == TRUE) {
            break;
        }
        app->subState = 0;
        app->timer = 0;
        return FALSE;
    }
    return TRUE;
}

static BOOL HatchEggApp_HatchManaphyEgg(HatchEggApp *app) {
    struct {
        s16 y;
        s16 x;
    } pos;
    int done;
    u32 plttOffset;
    switch (app->subState) {
    case 0:
        HatchEggParticles_Emit(app->gfx.particles, 0);
        HatchEggParticles_Emit(app->gfx.particles, 1);
        HatchEggParticles_Emit(app->gfx.particles, 2);
        HatchEggParticles_Emit(app->gfx.particles, 3);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
        app->subState++;
        break;
    case 1:
        switch ((u32)app->timer) {
        case 25:
            PlaySE(SEQ_SE_DP_W278);
            break;
        case 80:
            PlaySE(SEQ_SE_DP_W080C);
            break;
        case 142:
            PlaySE(SEQ_SE_DP_W361);
            break;
        }
        app->timer++;
        if (app->timer < 160) {
            break;
        }
        app->timer = 0;
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 1, 0xffff, 0, 0, 16, 0xffff);
        plttOffset = ObjPlttTransfer_GetPaletteVramOffset(Sprite_GetPaletteProxy(app->topBar->sprite), NNS_G2D_VRAM_TYPE_2DMAIN);
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 4, (u16)(0xffff ^ (1 << plttOffset)), 0, 0, 16, 0xffff);
        Pokepic_StartPaletteFade(app->pokepic, 0, 16, 0, 0xffff);
        app->subState++;
        break;
    case 2:
        done = 0;
        ManagedSprite_GetPositionXY(app->topBar, &pos.x, &pos.y);
        if (pos.y > -48) {
            ManagedSprite_OffsetPositionXY(app->topBar, 0, -4);
        } else {
            done++;
        }
        ManagedSprite_GetPositionXY(app->bottomBar, &pos.x, &pos.y);
        if (pos.y < 192) {
            ManagedSprite_OffsetPositionXY(app->bottomBar, 0, 4);
        } else {
            done++;
        }
        if (PaletteData_GetSelectedBuffersBitmask(app->gfx.paletteData) != 0 || done != 2 || Pokepic_ResumePaletteFade(app->pokepic)) {
            break;
        }
        HatchEggApp_SetPokepicVanished(app, FALSE);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_ON);
        ManagedSprite_SetDrawFlag(app->eggSprite, FALSE);
        ManagedSprite_SetDrawFlag(app->topBar, FALSE);
        ManagedSprite_SetDrawFlag(app->bottomBar, FALSE);
        app->subState++;
        break;
    case 3:
        app->timer++;
        if (app->timer < 25) {
            break;
        }
        app->timer = 0;
        Pokepic_StartPaletteFade(app->pokepic, 16, 0, 0, 0xffff);
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 1, 0xffff, 0, 16, 0, 0xffff);
        PaletteData_BeginPaletteFade(app->gfx.paletteData, 4, 0xffff, 0, 16, 0, 0xffff);
        app->subState++;
        break;
    case 4:
        if (PaletteData_GetSelectedBuffersBitmask(app->gfx.paletteData) != 0 || Pokepic_ResumePaletteFade(app->pokepic)) {
            break;
        }
        app->subState++;
        break;
    default:
        app->subState = 0;
        app->timer = 0;
        return FALSE;
    }
    return TRUE;
}

BOOL HatchEggApp_Init(OverlayManager *man, int *state) {
    HatchEggApp *app;
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    Heap_Create(HEAP_ID_3, HEAP_ID_70, 0x40000);
    app = OverlayManager_CreateAndGetData(man, sizeof(HatchEggApp), HEAP_ID_70);
    memset(app, 0, sizeof(HatchEggApp));
    app->args = OverlayManager_GetArgs(man);
    app->gfx.textSpeed = Options_GetTextFrameDelay(app->args->args.options);
    app->gfx.frame = Options_GetFrame(app->args->args.options);
    app->gfx.vramMan = HatchEggApp_Create3DVramMan();
    app->gfx.pokepicManager = PokepicManager_Create(HEAP_ID_70);
    app->gfx.narc = NARC_New(NARC_a_1_8_0, HEAP_ID_70);
    app->gfx.bgConfig = BgConfig_Alloc(HEAP_ID_70);
    GF_CreateVramTransferManager(64, HEAP_ID_70);
    app->picManager = PokepicAnimManager_New(HEAP_ID_70, 1, FALSE);
    PaletteData_SetAutoTransparent(app->gfx.paletteData = PaletteData_Init(HEAP_ID_70), TRUE);
    PaletteData_AllocBuffers(app->gfx.paletteData, PLTTBUF_MAIN_BG, 0x200, HEAP_ID_70);
    PaletteData_AllocBuffers(app->gfx.paletteData, PLTTBUF_MAIN_OBJ, 0x200, HEAP_ID_70);
    PaletteData_AllocBuffers(app->gfx.paletteData, PLTTBUF_SUB_BG, 0x200, HEAP_ID_70);
    PaletteData_LoadNarc(app->gfx.paletteData, NARC_graphic_font, 9, HEAP_ID_70, PLTTBUF_SUB_BG, 0x20, 0xF0);
    HatchEggApp_HideLayers();
    HatchEggApp_InitBlend();
    HatchEggApp_InitParticleVram();
    HatchEggApp_InitBgs(app->gfx.bgConfig);
    HatchEggYesNoMenu_InitBgs(app->gfx.bgConfig);
    HatchEggApp_InitSpriteSystem(&app->gfx);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    app->yesNoMenu = HatchEggYesNoMenu_New(app->gfx.bgConfig, app->gfx.spriteSystem, app->gfx.spriteManager, HEAP_ID_70);
    Sound_Stop();
    Main_SetVBlankIntrCB(HatchEggApp_VBlankCB, app);
    return TRUE;
}

BOOL HatchEggApp_Main(OverlayManager *man, int *state) {
    HatchEggApp *app = OverlayManager_GetData(man);
    switch (*state) {
    case HATCH_EGG_APP_STATE_INIT: {
        u32 species;
        if (IsPaletteFadeFinished() == TRUE) {
            (*state)++;
        }
        species = GetMonData(app->args->args.mon, MON_DATA_SPECIES, NULL);
        NARC_ReadPokepicCryDelay(app->gfx.narc, app->animParams, species, 1);
        if (species == SPECIES_MANAPHY) {
            app->sceneType = HATCH_EGG_SCENE_TYPE_MANAPHY;
        } else {
            app->sceneType = HATCH_EGG_SCENE_TYPE_EGG;
        }
        break;
    }
    case HATCH_EGG_APP_STATE_RUN_SCENE:
        if (!HatchEggApp_RunScene(app)) {
            (*state)++;
        } else {
            PokepicManager_DrawAll(app->gfx.pokepicManager);
            HatchEggApp_Draw3D();
        }
        break;
    default:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL HatchEggApp_Exit(OverlayManager *man, int *state) {
    HatchEggApp *app = OverlayManager_GetData(man);
    HatchEggYesNoMenu_Free(app->yesNoMenu);
    GF_3DVramMan_Delete(app->gfx.vramMan);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
    PaletteData_FreeBuffers(app->gfx.paletteData, PLTTBUF_MAIN_BG);
    PaletteData_FreeBuffers(app->gfx.paletteData, PLTTBUF_MAIN_OBJ);
    PaletteData_FreeBuffers(app->gfx.paletteData, PLTTBUF_SUB_BG);
    PaletteData_Free(app->gfx.paletteData);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    FreeBgTilemapBuffer(app->gfx.bgConfig, GF_BG_LYR_MAIN_1);
    FreeBgTilemapBuffer(app->gfx.bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(app->gfx.bgConfig, GF_BG_LYR_MAIN_3);
    Heap_Free(app->gfx.bgConfig);
    GF_DestroyVramTransferManager();
    PokepicManager_Delete(app->gfx.pokepicManager);
    PokepicAnimManager_Delete(app->picManager);
    NARC_Delete(app->gfx.narc);
    HatchEggApp_FreeSpriteSystem(&app->gfx);
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_70);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    Field_ForceEnvironmentSoundRecheck();
    return TRUE;
}

static void HatchEggYesNoMenu_InitBgs(BgConfig *bgConfig) {
    HatchEggBgTemplates templates = sHatchEggYesNoBgTemplates;
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &templates.templates[0], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &templates.templates[1], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &templates.templates[2], GF_BG_TYPE_TEXT);
    BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_2);
}

static HatchEggYesNoMenu *HatchEggYesNoMenu_New(BgConfig *bgConfig, SpriteSystem *spriteSystem, SpriteManager *spriteManager, enum HeapID heapId) {
    HatchEggYesNoMenu *menu;
    GF_ASSERT(bgConfig);
    GF_ASSERT(spriteSystem);
    GF_ASSERT(spriteManager);
    menu = Heap_Alloc(heapId, sizeof(HatchEggYesNoMenu));
    MI_CpuFill8(menu, 0, sizeof(HatchEggYesNoMenu));
    menu->heapId = heapId;
    menu->bgConfig = bgConfig;
    menu->spriteSystem = spriteSystem;
    menu->spriteManager = spriteManager;
    menu->msgFormat = MessageFormat_New(heapId);
    FontID_Alloc(4, menu->heapId);
    HatchEggYesNoMenu_AddWindows(menu);
    return menu;
}

static void HatchEggYesNoMenu_Free(HatchEggYesNoMenu *menu) {
    GF_ASSERT(menu);
    HatchEggYesNoMenu_RemoveWindows(menu);
    HatchEggYesNoMenu_DeleteCursor(menu);
    FontID_Release(4);
    MessageFormat_Delete(menu->msgFormat);
    FreeBgTilemapBuffer(menu->bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(menu->bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(menu->bgConfig, GF_BG_LYR_SUB_2);
    Heap_Free(menu);
}

static void HatchEggYesNoMenu_LoadGfx(HatchEggYesNoMenu *menu, PaletteData *paletteData, int charResId, int plttResId, int cellResId, int animResId) {
    SpriteSystem *spriteSystem = menu->spriteSystem;
    SpriteManager *spriteManager = menu->spriteManager;
    NARC *narc;
    GF_ASSERT(menu);
    GF_ASSERT(spriteSystem);
    GF_ASSERT(spriteManager);
    narc = NARC_New(NARC_a_2_3_7, menu->heapId);
    SpriteSystem_LoadPlttResObjFromOpenNarc(spriteSystem, spriteManager, narc, 11, FALSE, 1, NNS_G2D_VRAM_TYPE_2DSUB, plttResId);
    SpriteSystem_LoadCharResObjFromOpenNarc(spriteSystem, spriteManager, narc, 12, FALSE, NNS_G2D_VRAM_TYPE_2DSUB, charResId);
    SpriteSystem_LoadCellResObjFromOpenNarc(spriteSystem, spriteManager, narc, 13, FALSE, cellResId);
    SpriteSystem_LoadAnimResObjFromOpenNarc(spriteSystem, spriteManager, narc, 14, FALSE, animResId);
    HatchEggYesNoMenu_CreateCursor(menu, charResId, plttResId, cellResId, animResId);
    PaletteData_LoadNarc(paletteData, NARC_a_2_3_7, 0, HEAP_ID_70, PLTTBUF_SUB_BG, 0xA0, 0);
    PaletteData_LoadNarc(paletteData, NARC_graphic_font, 9, HEAP_ID_70, PLTTBUF_SUB_BG, 0x20, 0xF0);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, menu->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, HEAP_ID_70);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 9, menu->bgConfig, GF_BG_LYR_SUB_0, 0, 0, FALSE, HEAP_ID_70);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, menu->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_70);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, menu->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_70);
    ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_OFF);
    ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    NARC_Delete(narc);
}

static void HatchEggYesNoMenu_Show(HatchEggYesNoMenu *menu, u32 yesMsgId, u32 noMsgId) {
    HatchEggYesNoMenu_PrintButton(menu, &menu->buttons[0], yesMsgId);
    HatchEggYesNoMenu_PrintButton(menu, &menu->buttons[1], noMsgId);
    menu->state = HATCH_EGG_YES_NO_MENU_INPUT;
    menu->selection = HATCH_EGG_YES_NO_YES;
    HatchEggYesNoMenu_UpdateCursor(menu);
    ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_ON);
    ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    ManagedSprite_SetDrawFlag(menu->cursor, TRUE);
}

// Returns the selection (1 = yes, 2 = no) once a button was pressed and its animation has ended, else 0.
static int HatchEggYesNoMenu_Run(HatchEggYesNoMenu *menu) {
    switch (menu->state) {
    case HATCH_EGG_YES_NO_MENU_INPUT:
        if (HatchEggYesNoMenu_HandleInput(menu)) {
            menu->state++;
        }
        break;
    case HATCH_EGG_YES_NO_MENU_WAIT_PRESS:
        if (HatchEggYesNoMenu_IsPressAnimFinished(menu)) {
            GF_ASSERT(menu->selection);
            ToggleBgLayer(GF_BG_LYR_SUB_1, GF_PLANE_TOGGLE_OFF);
            ToggleBgLayer(GF_BG_LYR_SUB_2, GF_PLANE_TOGGLE_OFF);
            ManagedSprite_SetDrawFlag(menu->cursor, FALSE);
            GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_OFF);
            return menu->selection;
        }
        break;
    default:
        GF_ASSERT(0);
        break;
    }
    return HATCH_EGG_YES_NO_NONE;
}

static void HatchEggYesNoMenu_AddWindows(HatchEggYesNoMenu *menu) {
    AddWindowParameterized(menu->bgConfig, &menu->buttons[0], GF_BG_LYR_SUB_2, 4, 8, 24, 2, 15, 0x50);
    AddWindowParameterized(menu->bgConfig, &menu->buttons[1], GF_BG_LYR_SUB_2, 4, 14, 24, 2, 15, 0x80);
}

static void HatchEggYesNoMenu_RemoveWindows(HatchEggYesNoMenu *menu) {
    int i;
    Window *window;
    GF_ASSERT(menu != NULL);
    i = 0;
    window = menu->buttons;
    for (; i < 2; i++) {
        RemoveWindow(window);
        window++;
    }
}

static void HatchEggYesNoMenu_PrintButton(HatchEggYesNoMenu *menu, Window *window, u32 msgId) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0187_bin, menu->heapId);
    String *string = ReadMsgData_ExpandPlaceholders(menu->msgFormat, msgData, msgId, menu->heapId);
    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 4, string, 0, 0, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(1, 2, 0), NULL);
    CopyWindowToVram(window);
    DestroyMsgData(msgData);
    String_Delete(string);
}

static void HatchEggYesNoMenu_CreateCursor(HatchEggYesNoMenu *menu, int charResId, int plttResId, int cellResId, int animResId) {
    ManagedSpriteTemplate template = sHatchEggYesNoCursorTemplate;
    ManagedSprite *sprite;
    SpriteSystem *spriteSystem = menu->spriteSystem;
    SpriteManager *spriteManager = menu->spriteManager;
    GF_ASSERT(menu != NULL);
    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    template.x = 128;
    template.y = 72;
    template.animation = 1;
    template.resIdList[GF_GFX_RES_TYPE_CHAR] = charResId;
    template.resIdList[GF_GFX_RES_TYPE_PLTT] = plttResId;
    template.resIdList[GF_GFX_RES_TYPE_CELL] = cellResId;
    template.resIdList[GF_GFX_RES_TYPE_ANIM] = animResId;
    sprite = SpriteSystem_NewSprite(spriteSystem, spriteManager, &template);
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    ManagedSprite_SetDrawFlag(sprite, FALSE);
    menu->cursor = sprite;
}

static void HatchEggYesNoMenu_DeleteCursor(HatchEggYesNoMenu *menu) {
    Sprite_DeleteAndFreeResources(menu->cursor);
}

static void HatchEggYesNoMenu_UpdateCursor(HatchEggYesNoMenu *menu) {
    int index;
    GF_ASSERT(menu->cursor);
    switch (menu->selection) {
    case HATCH_EGG_YES_NO_YES:
        index = 0;
        break;
    case HATCH_EGG_YES_NO_NO:
        index = 1;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    ManagedSprite_SetPositionXY(menu->cursor, sHatchEggYesNoCursorPositions[index][0], sHatchEggYesNoCursorPositions[index][1]);
}

static BOOL HatchEggYesNoMenu_HandleInput(HatchEggYesNoMenu *menu) {
    BOOL pressed = FALSE;
    int hit = TouchscreenHitbox_FindRectAtTouchNew(sHatchEggYesNoHitboxes);
    if (hit != TOUCH_MENU_NO_INPUT) {
        PlaySE(SEQ_SE_DP_SELECT);
        switch (hit) {
        case 0:
            menu->selection = HATCH_EGG_YES_NO_YES;
            pressed = TRUE;
            break;
        case 1:
            menu->selection = HATCH_EGG_YES_NO_NO;
            pressed = TRUE;
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
    } else {
        u32 keys = gSystem.newKeys;
        if (keys & PAD_KEY_UP) {
            if (menu->selection != HATCH_EGG_YES_NO_YES) {
                menu->selection = HATCH_EGG_YES_NO_YES;
                HatchEggYesNoMenu_UpdateCursor(menu);
                PlaySE(SEQ_SE_DP_SELECT);
            }
        } else if (keys & PAD_KEY_DOWN) {
            if (menu->selection != HATCH_EGG_YES_NO_NO) {
                menu->selection = HATCH_EGG_YES_NO_NO;
                HatchEggYesNoMenu_UpdateCursor(menu);
                PlaySE(SEQ_SE_DP_SELECT);
            }
        } else if (keys & PAD_BUTTON_A) {
            if (menu->selection == HATCH_EGG_YES_NO_NONE) {
                GF_ASSERT(FALSE);
                menu->selection = HATCH_EGG_YES_NO_NO;
            }
            pressed = TRUE;
        } else if (keys & PAD_BUTTON_B) {
            menu->selection = HATCH_EGG_YES_NO_NO;
            pressed = TRUE;
        }
    }
    if (pressed) {
        HatchEggYesNoMenu_UpdateCursor(menu);
        ManagedSprite_SetAnim(menu->cursor, 3);
        PlaySE(SEQ_SE_DP_SELECT);
    }
    return pressed;
}

static BOOL HatchEggYesNoMenu_IsPressAnimFinished(HatchEggYesNoMenu *menu) {
    GF_ASSERT(ManagedSprite_GetActiveAnim(menu->cursor) == 3);
    return !ManagedSprite_IsAnimated(menu->cursor);
}
