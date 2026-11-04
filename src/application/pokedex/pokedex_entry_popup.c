#include "global.h"

#include "application/pokedex/pokedex_text_util.h"
#include "battle/battle.h"
#include "graphic/zukan_gra.naix"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0802.h"

#include "bg_window.h"
#include "dex_mon_measures.h"
#include "filesystem.h"
#include "filesystem_files_def.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "message_format.h"
#include "obj_char_transfer.h"
#include "overlay_18.h"
#include "palette.h"
#include "pokedex_util.h"
#include "pokemon.h"
#include "pokepic.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "sprite_resource.h"
#include "sprite_resource_header.h"
#include "sprite_transfer.h"
#include "sys_task_api.h"
#include "text.h"

// Sprites of the popup: 0 banner, 1 and 2 the type icons, 3 the footprint
typedef struct PokedexEntryPopupSprite {
    Sprite *sprite;
    SpriteResource *resources[4]; // char, palette, cell, anim
} PokedexEntryPopupSprite;

// "Registered in the Pokedex" popup after a capture (msg_0802). Starts with a copy of PokedexEntryPopupArgs; created
// by PokedexEntryPopup_Create, run by PokedexEntryPopup_Task.
typedef struct PokedexEntryPopup {
    BgConfig *bgConfig;
    PaletteData *paletteData;
    PokepicManager *pokepicManager;
    Pokemon *mon;
    BOOL natDexEnabled;
    enum HeapID heapId;
    SysTask *task;
    NARC *gfxNarc;
    Pokepic *pokepic;
    Window windows[9];
    SpriteList *spriteList;
    G2dRenderer renderer;
    GF_2DGfxResMan *resourceManagers[4];
    PokedexEntryPopupSprite sprites[4];
    u16 state;
    u16 bannerFlashTimer;
    u32 species;
    u32 form;
    u32 type1;
    u32 type2;
    u32 done;
} PokedexEntryPopup;

enum PokedexEntryPopupState {
    POKEDEX_ENTRY_POPUP_STATE_INIT,
    POKEDEX_ENTRY_POPUP_STATE_WAIT_FADE_IN,
    POKEDEX_ENTRY_POPUP_STATE_PLAY_CRY,
    POKEDEX_ENTRY_POPUP_STATE_WAIT_CRY,
    POKEDEX_ENTRY_POPUP_STATE_DONE,
};

static void PokedexEntryPopup_Task(SysTask *task, void *data);
static void PokedexEntryPopup_ReadMonData(PokedexEntryPopup *popup);
static void PokedexEntryPopup_InitBgs(PokedexEntryPopup *popup);
static void PokedexEntryPopup_FreeBgs(PokedexEntryPopup *popup);
static void PokedexEntryPopup_StartFadeIn(PokedexEntryPopup *popup);
static BOOL PokedexEntryPopup_IsFadeDone(PokedexEntryPopup *popup);
static void PokedexEntryPopup_FlashBanner(PokedexEntryPopup *popup);
static void PokedexEntryPopup_DrawWindows(PokedexEntryPopup *popup);
static void PokedexEntryPopup_RemoveWindows(PokedexEntryPopup *popup);
static void PokedexEntryPopup_InitObjCharTransfer(PokedexEntryPopup *popup);
static void PokedexEntryPopup_DestroyObjCharTransfer(void);
static void PokedexEntryPopup_CreateResourceManagers(PokedexEntryPopup *popup);
static void PokedexEntryPopup_DestroyResourceManagers(PokedexEntryPopup *popup);
static void PokedexEntryPopup_InitSprites(PokedexEntryPopup *popup);
static void PokedexEntryPopup_LoadBannerResources(PokedexEntryPopup *popup);
static void PokedexEntryPopup_FreeBannerResources(PokedexEntryPopup *popup);
static void PokedexEntryPopup_LoadTypeIconResources(PokedexEntryPopup *popup);
static void PokedexEntryPopup_UnloadTypeIconResources(PokedexEntryPopup *popup);
static void PokedexEntryPopup_LoadFootprintResources(PokedexEntryPopup *popup);
static void PokedexEntryPopup_UnloadFootprintResources(PokedexEntryPopup *popup);
static void PokedexEntryPopup_FreeSprites(PokedexEntryPopup *popup);
static void PokedexEntryPopup_LoadSpriteResources(SpriteResource **resources, GF_2DGfxResMan **managers, enum HeapID heapId, NARC *narc, int charFileId, int plttFileId, int cellFileId, int animFileId, int plttNum, int charId, int plttId, int cellId, int animId);
static SpriteResource *PokedexEntryPopup_LoadPaletteResource(GF_2DGfxResMan *manager, enum HeapID heapId, NARC *narc, int fileId, int plttNum, int id);
static void PokedexEntryPopup_FreeSpriteResources(SpriteResource **resources, GF_2DGfxResMan **managers);
static void PokedexEntryPopup_MakeResourcesHeader(SpriteResource **resources, GF_2DGfxResMan **managers, SpriteResourcesHeader *header, int priority);
static void PokedexEntryPopup_CreateTypeIconSprites(PokedexEntryPopup *popup);
static void PokedexEntryPopup_DeleteTypeIconSprites(PokedexEntryPopup *popup);
static void PokedexEntryPopup_CreateBannerSprite(PokedexEntryPopup *popup);
static void PokedexEntryPopup_DeleteBannerSprite(PokedexEntryPopup *popup);
static void PokedexEntryPopup_CreateFootprintSprite(PokedexEntryPopup *popup);
static void PokedexEntryPopup_DeleteFootprintSprite(PokedexEntryPopup *popup);
static void PokedexEntryPopup_CreatePokepic(PokedexEntryPopup *popup);

static const ObjCharTransferTemplate sEntryPopupObjCharTransferTemplate = {
    .maxTasks = 32,
    .sizeMain = 0x10000,
    .sizeSub = 0x4000,
    .heapID = HEAP_ID_DEFAULT,
};

static const BgTemplate sEntryPopupBg1Template = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf800,
    .charBase = GX_BG_CHARBASE_0x00000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 1,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sEntryPopupBg2Template = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xf000,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 2,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const BgTemplate sEntryPopupBg3Template = {
    .x = 0,
    .y = 0,
    .bufferSize = 0x800,
    .baseTile = 0,
    .size = GF_BG_SCR_SIZE_256x256,
    .colorMode = GX_BG_COLORMODE_16,
    .screenBase = GX_BG_SCRBASE_0xe800,
    .charBase = GX_BG_CHARBASE_0x10000,
    .bgExtPltt = GX_BG_EXTPLTT_01,
    .priority = 3,
    .areaOver = GX_BG_AREAOVER_XLU,
    .mosaic = FALSE,
};

static const WindowTemplate sEntryPopupWindowTemplates[9] = {
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 2,
     .top = 0,
     .width = 28,
     .height = 2,
     .palette = 2,
     .baseTile = 0x3C8,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 15,
     .top = 3,
     .width = 4,
     .height = 2,
     .palette = 0,
     .baseTile = 0x3C0,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 19,
     .top = 3,
     .width = 9,
     .height = 2,
     .palette = 0,
     .baseTile = 0x3AE,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 13,
     .top = 5,
     .width = 18,
     .height = 2,
     .palette = 0,
     .baseTile = 0x38A,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 2,
     .top = 17,
     .width = 28,
     .height = 6,
     .palette = 1,
     .baseTile = 0x2E2,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 18,
     .top = 11,
     .width = 5,
     .height = 2,
     .palette = 1,
     .baseTile = 0x2D8,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 23,
     .top = 11,
     .width = 8,
     .height = 2,
     .palette = 1,
     .baseTile = 0x2C8,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 18,
     .top = 13,
     .width = 5,
     .height = 2,
     .palette = 1,
     .baseTile = 0x2BE,
     },
    {
     .bgId = GF_BG_LYR_MAIN_1,
     .left = 23,
     .top = 13,
     .width = 8,
     .height = 2,
     .palette = 1,
     .baseTile = 0x2AE,
     },
};

PokedexEntryPopup *PokedexEntryPopup_Create(PokedexEntryPopupArgs *args) {
    PokedexEntryPopup *popup = Heap_Alloc(args->heapID, sizeof(PokedexEntryPopup));
    memset(popup, 0, sizeof(PokedexEntryPopup));
    memcpy(popup, args, sizeof(PokedexEntryPopupArgs));
    popup->gfxNarc = NARC_New(NARC_graphic_zukan_gra, popup->heapId);
    popup->state = POKEDEX_ENTRY_POPUP_STATE_INIT;
    popup->done = 0;
    popup->task = SysTask_CreateOnMainQueue(PokedexEntryPopup_Task, popup, 0);
    return popup;
}

s32 PokedexEntryPopup_IsDone(PokedexEntryPopup *popup) {
    return popup->done;
}

void PokedexEntryPopup_Delete(PokedexEntryPopup *popup) {
    PokedexEntryPopup_FreeSprites(popup);
    PokedexEntryPopup_RemoveWindows(popup);
    PokedexEntryPopup_FreeBgs(popup);
    NARC_Delete(popup->gfxNarc);
    SysTask_Destroy(popup->task);
    Heap_Free(popup);
}

// Fades in the screen, plays the cry, then flags done; the caller deletes the popup.
static void PokedexEntryPopup_Task(SysTask *task, void *data) {
    PokedexEntryPopup *popup = data;

    switch (popup->state) {
    case POKEDEX_ENTRY_POPUP_STATE_INIT:
        *(vu16 *)REG_BLDCNT_ADDR = 0;
        PokedexEntryPopup_ReadMonData(popup);
        PokedexEntryPopup_InitBgs(popup);
        PokedexEntryPopup_DrawWindows(popup);
        PokedexEntryPopup_InitSprites(popup);
        PokedexEntryPopup_CreatePokepic(popup);
        PokedexEntryPopup_StartFadeIn(popup);
        popup->state = POKEDEX_ENTRY_POPUP_STATE_WAIT_FADE_IN;
        break;
    case POKEDEX_ENTRY_POPUP_STATE_WAIT_FADE_IN:
        if (PokedexEntryPopup_IsFadeDone(popup) == TRUE) {
            popup->state = POKEDEX_ENTRY_POPUP_STATE_PLAY_CRY;
        }
        break;
    case POKEDEX_ENTRY_POPUP_STATE_PLAY_CRY:
        PlayCryEx(14, popup->species, 0x1FF, 0x1FF, 0x1FF, 0);
        popup->state = POKEDEX_ENTRY_POPUP_STATE_WAIT_CRY;
        break;
    case POKEDEX_ENTRY_POPUP_STATE_WAIT_CRY:
        if (!IsCryPlaying()) {
            popup->done = 1;
            popup->state = POKEDEX_ENTRY_POPUP_STATE_DONE;
        }
        break;
    case POKEDEX_ENTRY_POPUP_STATE_DONE:
        break;
    }
    SpriteList_RenderAndAnimateSprites(popup->spriteList);
    PokedexEntryPopup_FlashBanner(popup);
}

static void PokedexEntryPopup_ReadMonData(PokedexEntryPopup *popup) {
    BOOL lock = AcquireMonLock(popup->mon);
    popup->species = GetMonData(popup->mon, MON_DATA_SPECIES, NULL);
    popup->form = GetMonData(popup->mon, MON_DATA_FORM, NULL);
    popup->type1 = GetMonData(popup->mon, MON_DATA_TYPE_1, NULL);
    popup->type2 = GetMonData(popup->mon, MON_DATA_TYPE_2, NULL);
    ReleaseMonLock(popup->mon, lock);
}

static void PokedexEntryPopup_InitBgs(PokedexEntryPopup *popup) {
    SetBgPriority(GF_BG_LYR_MAIN_0, 0);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
    {
        BgTemplate bg1 = sEntryPopupBg1Template;
        InitBgFromTemplate(popup->bgConfig, GF_BG_LYR_MAIN_1, &bg1, GF_BG_TYPE_TEXT);
        BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 0x20, 0, popup->heapId);
        BgTemplate bg2 = sEntryPopupBg2Template;
        InitBgFromTemplate(popup->bgConfig, GF_BG_LYR_MAIN_2, &bg2, GF_BG_TYPE_TEXT);
        BgTemplate bg3 = sEntryPopupBg3Template;
        InitBgFromTemplate(popup->bgConfig, GF_BG_LYR_MAIN_3, &bg3, GF_BG_TYPE_TEXT);
    }
    GfGfxLoader_LoadCharDataFromOpenNarc(popup->gfxNarc, NARC_zukan_gra_zukan_gra_00000019_NCGR_lz, popup->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, popup->heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(popup->gfxNarc, NARC_zukan_gra_zukan_gra_00000020_NSCR_lz, popup->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, TRUE, popup->heapId);
    PaletteData_LoadOpenNarc(popup->paletteData, popup->gfxNarc, NARC_zukan_gra_zukan_gra_00000018_NCLR, popup->heapId, PLTTBUF_MAIN_BG, 0, 0);
}

static void PokedexEntryPopup_FreeBgs(PokedexEntryPopup *popup) {
    FreeBgTilemapBuffer(popup->bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(popup->bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(popup->bgConfig, GF_BG_LYR_MAIN_1);
}

static void PokedexEntryPopup_StartFadeIn(PokedexEntryPopup *popup) {
    PaletteData_BeginPaletteFade(popup->paletteData, PLTTBUF_MAIN_BG_F | PLTTBUF_MAIN_OBJ_F, 0xFFFF, 1, 16, 0, RGB_BLACK);
    Pokepic_StartPaletteFade(popup->pokepic, 16, 0, 0, RGB_BLACK);
    PaletteData_SetAutoTransparent(popup->paletteData, FALSE);
}

static BOOL PokedexEntryPopup_IsFadeDone(PokedexEntryPopup *popup) {
    if (PaletteData_GetSelectedBuffersBitmask(popup->paletteData) == 0 && !Pokepic_ResumePaletteFade(popup->pokepic)) {
        return TRUE;
    }
    return FALSE;
}

// The banner (BG 2 rows 0-1) alternates between palettes 7 and 0 every 16 frames.
static void PokedexEntryPopup_FlashBanner(PokedexEntryPopup *popup) {
    popup->bannerFlashTimer++;
    if (popup->bannerFlashTimer == 16) {
        BgTilemapRectChangePalette(popup->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 32, 2, 7);
        ScheduleBgTilemapBufferTransfer(popup->bgConfig, GF_BG_LYR_MAIN_2);
    } else if (popup->bannerFlashTimer == 32) {
        BgTilemapRectChangePalette(popup->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 32, 2, 0);
        ScheduleBgTilemapBufferTransfer(popup->bgConfig, GF_BG_LYR_MAIN_2);
        popup->bannerFlashTimer = 0;
    }
}

static void PokedexEntryPopup_DrawWindows(PokedexEntryPopup *popup) {
    MsgData *msgData;
    MessageFormat *msgFormat;
    String *strbuf;
    String *string;
    u32 i;
    int x;

    for (i = 0; i < NELEMS(popup->windows); i++) {
        AddWindow(popup->bgConfig, &popup->windows[i], &sEntryPopupWindowTemplates[i]);
        FillWindowPixelBuffer(&popup->windows[i], 0);
    }
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0802_bin, popup->heapId);
    msgFormat = MessageFormat_New(popup->heapId);
    strbuf = String_New(0x400, popup->heapId);
    PokedexApp_PrintMessage(&popup->windows[0], msgData, msg_0802_00144, 112, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    BufferIntegerAsString(msgFormat, 0, Pokedex_ConvertToCurrentDexNo(popup->natDexEnabled, popup->species), 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
    string = NewString_ReadMsgData(msgData, msg_0802_00009);
    StringExpandPlaceholders(msgFormat, strbuf, string);
    PokedexApp_PrintString(&popup->windows[1], strbuf, 1, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    String_Delete(string);
    string = PokedexApp_GetSpeciesNameString(popup->species, 2, popup->heapId);
    PokedexApp_PrintString(&popup->windows[2], string, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    String_Delete(string);
    string = PokedexApp_GetCategoryString(popup->species, 2, popup->heapId);
    x = GetWindowWidth(&popup->windows[3]) * 8 - 4;
    PokedexApp_PrintString(&popup->windows[3], string, x, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_RIGHT);
    String_Delete(string);
    string = PokedexApp_GetFlavorTextString(popup->species, 2, 0, popup->heapId);
    x = (GetWindowWidth(&popup->windows[4]) * 8 - FontID_String_GetWidthMultiline(0, string, 0)) / 2;
    PokedexApp_PrintString(&popup->windows[4], string, x, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    String_Delete(string);
    PokedexApp_PrintMessage(&popup->windows[5], msgData, msg_0802_00010, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&popup->windows[7], msgData, msg_0802_00011, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    MessageFormat_Delete(msgFormat);
    DestroyMsgData(msgData);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, GetDexHeightMsgBank(), popup->heapId);
    PokedexApp_PrintMessage(&popup->windows[6], msgData, popup->species, 4, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    DestroyMsgData(msgData);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, GetDexWeightMsgBank(), popup->heapId);
    PokedexApp_PrintMessage(&popup->windows[8], msgData, popup->species, 4, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    DestroyMsgData(msgData);
    String_Delete(strbuf);
    for (i = 0; i < NELEMS(popup->windows); i++) {
        ScheduleWindowCopyToVram(&popup->windows[i]);
    }
}

static void PokedexEntryPopup_RemoveWindows(PokedexEntryPopup *popup) {
    u32 i;

    for (i = 0; i < NELEMS(popup->windows); i++) {
        RemoveWindow(&popup->windows[i]);
    }
}

static void PokedexEntryPopup_InitObjCharTransfer(PokedexEntryPopup *popup) {
    ObjCharTransferTemplate template = sEntryPopupObjCharTransferTemplate;
    template.heapID = popup->heapId;
    ObjCharTransfer_InitEx(&template, GX_OBJVRAMMODE_CHAR_1D_64K, GX_OBJVRAMMODE_CHAR_1D_32K);
}

static void PokedexEntryPopup_DestroyObjCharTransfer(void) {
    ObjCharTransfer_Destroy();
}

static void PokedexEntryPopup_CreateResourceManagers(PokedexEntryPopup *popup) {
    int i;

    for (i = 0; i < 4; i++) {
        popup->resourceManagers[i] = Create2DGfxResObjMan(8, (GfGfxResType)i, popup->heapId);
    }
}

static void PokedexEntryPopup_DestroyResourceManagers(PokedexEntryPopup *popup) {
    int i;

    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(popup->resourceManagers[i]);
    }
}

static void PokedexEntryPopup_InitSprites(PokedexEntryPopup *popup) {
    popup->spriteList = G2dRenderer_Init(32, &popup->renderer, popup->heapId);
    ClearMainOAM(popup->heapId);
    PokedexEntryPopup_InitObjCharTransfer(popup);
    PokedexEntryPopup_CreateResourceManagers(popup);
    PokedexEntryPopup_LoadBannerResources(popup);
    PokedexEntryPopup_LoadTypeIconResources(popup);
    PokedexEntryPopup_LoadFootprintResources(popup);
    PokedexEntryPopup_CreateBannerSprite(popup);
    PokedexEntryPopup_CreateTypeIconSprites(popup);
    PokedexEntryPopup_CreateFootprintSprite(popup);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

static void PokedexEntryPopup_LoadBannerResources(PokedexEntryPopup *popup) {
    PokedexEntryPopup_LoadSpriteResources(popup->sprites[0].resources, popup->resourceManagers, popup->heapId, popup->gfxNarc, NARC_zukan_gra_zukan_gra_00000029_NCGR_lz, NARC_zukan_gra_zukan_gra_00000032_NCLR, NARC_zukan_gra_zukan_gra_00000030_NCER_lz, NARC_zukan_gra_zukan_gra_00000031_NANR_lz, 2, 0xC618, 0xC618, 0xC618, 0xC618);
    PaletteData_LoadPaletteSlotFromHardware(popup->paletteData, PLTTBUF_MAIN_OBJ, SpriteTransfer_GetPlttOffset(popup->sprites[0].resources[1], NNS_G2D_VRAM_TYPE_2DMAIN) << 4, 0x40);
}

static void PokedexEntryPopup_FreeBannerResources(PokedexEntryPopup *popup) {
    PokedexEntryPopup_FreeSpriteResources(popup->sprites[0].resources, popup->resourceManagers);
}

// Both type icons share the first icon's palettes, cell and animation.
static void PokedexEntryPopup_LoadTypeIconResources(PokedexEntryPopup *popup) {
    PokedexEntryPopup_LoadSpriteResources(popup->sprites[1].resources, popup->resourceManagers, popup->heapId, popup->gfxNarc, PokedexApp_GetTypeIconCharFile(popup->type1), NARC_zukan_gra_zukan_gra_00000035_NCLR, NARC_zukan_gra_zukan_gra_00000033_NCER_lz, NARC_zukan_gra_zukan_gra_00000034_NANR_lz, 4, 0xC619, 0xC619, 0xC619, 0xC619);
    PokedexEntryPopup_LoadSpriteResources(popup->sprites[2].resources, popup->resourceManagers, popup->heapId, popup->gfxNarc, PokedexApp_GetTypeIconCharFile(popup->type2), -1, NARC_zukan_gra_zukan_gra_00000033_NCER_lz, NARC_zukan_gra_zukan_gra_00000034_NANR_lz, 4, 0xC61A, 0xC61A, 0xC61A, 0xC61A);
    PaletteData_LoadPaletteSlotFromHardware(popup->paletteData, PLTTBUF_MAIN_OBJ, SpriteTransfer_GetPlttOffset(popup->sprites[1].resources[1], NNS_G2D_VRAM_TYPE_2DMAIN) << 4, 0x80);
}

static void PokedexEntryPopup_UnloadTypeIconResources(PokedexEntryPopup *popup) {
    PokedexEntryPopup_FreeSpriteResources(popup->sprites[1].resources, popup->resourceManagers);
    SpriteTransfer_DeleteCharTransferTask(popup->sprites[2].resources[0]);
    DestroySingle2DGfxResObj(popup->resourceManagers[0], popup->sprites[2].resources[0]);
    DestroySingle2DGfxResObj(popup->resourceManagers[2], popup->sprites[2].resources[2]);
    DestroySingle2DGfxResObj(popup->resourceManagers[3], popup->sprites[2].resources[3]);
}

static void PokedexEntryPopup_LoadFootprintResources(PokedexEntryPopup *popup) {
    NARC *narc = NARC_New(Pokefoot_GetNarcId(), popup->heapId);
    PokedexEntryPopup_LoadSpriteResources(popup->sprites[3].resources, popup->resourceManagers, popup->heapId, popup->gfxNarc, NARC_zukan_gra_zukan_gra_00000077_NCGR_lz, -1, NARC_zukan_gra_zukan_gra_00000078_NCER_lz, NARC_zukan_gra_zukan_gra_00000079_NANR_lz, 1, 0xC61B, 0xC61B, 0xC61B, 0xC61B);
    popup->sprites[3].resources[1] = PokedexEntryPopup_LoadPaletteResource(popup->resourceManagers[1], popup->heapId, narc, Pokefoot_GetPlttFileId(), 1, 0xC61B);
    PaletteData_LoadPaletteSlotFromHardware(popup->paletteData, PLTTBUF_MAIN_OBJ, SpriteTransfer_GetPlttOffset(popup->sprites[3].resources[1], NNS_G2D_VRAM_TYPE_2DMAIN) << 4, 0x20);
    NARC_Delete(narc);
}

static void PokedexEntryPopup_UnloadFootprintResources(PokedexEntryPopup *popup) {
    PokedexEntryPopup_FreeSpriteResources(popup->sprites[3].resources, popup->resourceManagers);
}

static void PokedexEntryPopup_FreeSprites(PokedexEntryPopup *popup) {
    PokedexEntryPopup_DeleteFootprintSprite(popup);
    PokedexEntryPopup_DeleteTypeIconSprites(popup);
    PokedexEntryPopup_DeleteBannerSprite(popup);
    PokedexEntryPopup_UnloadFootprintResources(popup);
    PokedexEntryPopup_UnloadTypeIconResources(popup);
    PokedexEntryPopup_FreeBannerResources(popup);
    PokedexEntryPopup_DestroyResourceManagers(popup);
    PokedexEntryPopup_DestroyObjCharTransfer();
    SpriteList_Delete(popup->spriteList);
}

// plttFileId -1: no palette (the caller shares or loads one itself)
static void PokedexEntryPopup_LoadSpriteResources(SpriteResource **resources, GF_2DGfxResMan **managers, enum HeapID heapId, NARC *narc, int charFileId, int plttFileId, int cellFileId, int animFileId, int plttNum, int charId, int plttId, int cellId, int animId) {
    resources[0] = AddCharResObjFromOpenNarc(managers[0], narc, charFileId, TRUE, charId, NNS_G2D_VRAM_TYPE_2DMAIN, heapId);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(resources[0]);
    GF2DGfxResObj_FreeData(resources[0]);
    if (plttFileId != -1) {
        resources[1] = PokedexEntryPopup_LoadPaletteResource(managers[1], heapId, narc, plttFileId, plttNum, plttId);
    }
    resources[2] = AddCellOrAnimResObjFromOpenNarc(managers[2], narc, cellFileId, TRUE, cellId, GF_GFX_RES_TYPE_CELL, heapId);
    resources[3] = AddCellOrAnimResObjFromOpenNarc(managers[3], narc, animFileId, TRUE, animId, GF_GFX_RES_TYPE_ANIM, heapId);
}

static SpriteResource *PokedexEntryPopup_LoadPaletteResource(GF_2DGfxResMan *manager, enum HeapID heapId, NARC *narc, int fileId, int plttNum, int id) {
    SpriteResource *resource = AddPlttResObjFromOpenNarc(manager, narc, fileId, FALSE, id, NNS_G2D_VRAM_TYPE_2DMAIN, plttNum, heapId);
    SpriteTransfer_CreatePlttTransferTask(resource);
    GF2DGfxResObj_FreeData(resource);
    return resource;
}

static void PokedexEntryPopup_FreeSpriteResources(SpriteResource **resources, GF_2DGfxResMan **managers) {
    SpriteTransfer_DeleteCharTransferTask(resources[0]);
    SpriteTransfer_DeletePlttTransferTask(resources[1]);
    DestroySingle2DGfxResObj(managers[0], resources[0]);
    DestroySingle2DGfxResObj(managers[1], resources[1]);
    DestroySingle2DGfxResObj(managers[2], resources[2]);
    DestroySingle2DGfxResObj(managers[3], resources[3]);
}

static void PokedexEntryPopup_MakeResourcesHeader(SpriteResource **resources, GF_2DGfxResMan **managers, SpriteResourcesHeader *header, int priority) {
    int charId = GF2DGfxResObj_GetResID(resources[0]);
    int plttId = GF2DGfxResObj_GetResID(resources[1]);
    int cellId = GF2DGfxResObj_GetResID(resources[2]);
    int animId = GF2DGfxResObj_GetResID(resources[3]);
    CreateSpriteResourcesHeader(header, charId, plttId, cellId, animId, -1, -1, 0, priority, managers[0], managers[1], managers[2], managers[3], NULL, NULL);
}

// The second icon uses the first one's palette and is hidden for single-type species.
static void PokedexEntryPopup_CreateTypeIconSprites(PokedexEntryPopup *popup) {
    SimpleSpriteTemplate template;
    SpriteResourcesHeader header;
    int charId;
    int plttId;
    int cellId;
    int animId;

    PokedexEntryPopup_MakeResourcesHeader(popup->sprites[1].resources, popup->resourceManagers, &header, 1);
    template.spriteList = popup->spriteList;
    template.header = &header;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.priority = 0;
    template.heapID = popup->heapId;
    template.position.x = 168 * FX32_ONE;
    template.position.y = 72 * FX32_ONE;
    popup->sprites[1].sprite = Sprite_Create(&template);
    Sprite_SetPalIndexRespectVramOffset(popup->sprites[1].sprite, PokedexApp_GetTypeIconPalette(popup->type1));
    charId = GF2DGfxResObj_GetResID(popup->sprites[2].resources[0]);
    plttId = GF2DGfxResObj_GetResID(popup->sprites[1].resources[1]);
    cellId = GF2DGfxResObj_GetResID(popup->sprites[2].resources[2]);
    animId = GF2DGfxResObj_GetResID(popup->sprites[2].resources[3]);
    CreateSpriteResourcesHeader(&header, charId, plttId, cellId, animId, -1, -1, 0, 1, popup->resourceManagers[0], popup->resourceManagers[1], popup->resourceManagers[2], popup->resourceManagers[3], NULL, NULL);
    template.spriteList = popup->spriteList;
    template.header = &header;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.priority = 0;
    template.heapID = popup->heapId;
    template.position.x = 217 * FX32_ONE;
    template.position.y = 72 * FX32_ONE;
    popup->sprites[2].sprite = Sprite_Create(&template);
    if (popup->type2 == 0 || popup->type1 == popup->type2) {
        Sprite_SetDrawFlag(popup->sprites[2].sprite, FALSE);
    } else {
        Sprite_SetPalIndexRespectVramOffset(popup->sprites[2].sprite, PokedexApp_GetTypeIconPalette(popup->type2));
    }
}

static void PokedexEntryPopup_DeleteTypeIconSprites(PokedexEntryPopup *popup) {
    Sprite_Delete(popup->sprites[1].sprite);
    Sprite_Delete(popup->sprites[2].sprite);
}

static void PokedexEntryPopup_CreateBannerSprite(PokedexEntryPopup *popup) {
    SimpleSpriteTemplate template;
    SpriteResourcesHeader header;

    PokedexEntryPopup_MakeResourcesHeader(popup->sprites[0].resources, popup->resourceManagers, &header, 1);
    template.spriteList = popup->spriteList;
    template.header = &header;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.priority = 0;
    template.heapID = popup->heapId;
    template.position.x = 112 * FX32_ONE;
    template.position.y = 32 * FX32_ONE;
    popup->sprites[0].sprite = Sprite_Create(&template);
}

static void PokedexEntryPopup_DeleteBannerSprite(PokedexEntryPopup *popup) {
    Sprite_Delete(popup->sprites[0].sprite);
}

// The footprint is copied straight into the sprite's VRAM.
static void PokedexEntryPopup_CreateFootprintSprite(PokedexEntryPopup *popup) {
    SimpleSpriteTemplate template;
    SpriteResourcesHeader header;
    void *footprint;
    u32 location;

    PokedexEntryPopup_MakeResourcesHeader(popup->sprites[3].resources, popup->resourceManagers, &header, 1);
    template.spriteList = popup->spriteList;
    template.header = &header;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.priority = 0;
    template.heapID = popup->heapId;
    template.position.x = 120 * FX32_ONE;
    template.position.y = 80 * FX32_ONE;
    popup->sprites[3].sprite = Sprite_Create(&template);
    footprint = PokedexApp_LoadFootprintGraphics(popup->species, popup->heapId);
    location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(popup->sprites[3].sprite), NNS_G2D_VRAM_TYPE_2DMAIN);
    DC_FlushRange(footprint, 0x80);
    GX_LoadOBJ(footprint, location, 0x80);
    Heap_Free(footprint);
}

static void PokedexEntryPopup_DeleteFootprintSprite(PokedexEntryPopup *popup) {
    Sprite_Delete(popup->sprites[3].sprite);
}

void PokedexEntryPopup_HideSprites(PokedexEntryPopup *popup) {
    u32 i;
    BOOL draw = FALSE;

    for (i = 0; i < 4; i++) {
        Sprite_SetDrawFlag(popup->sprites[i].sprite, draw);
    }
}

static void PokedexEntryPopup_CreatePokepic(PokedexEntryPopup *popup) {
    PokepicTemplate template;
    GetPokemonSpriteCharAndPlttNarcIds(&template, popup->mon, 2);
    popup->pokepic = PokepicManager_CreatePokepic(popup->pokepicManager, &template, 48, 72, 0, 0, NULL, NULL);
}

Pokepic *PokedexEntryPopup_GetPokepic(PokedexEntryPopup *popup) {
    return popup->pokepic;
}
