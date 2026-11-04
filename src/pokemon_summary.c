#include "pokemon_summary.h"

#include "global.h"

#include "constants/balls.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/sndseq.h"
#include "constants/species.h"

#include "data/resdat.naix"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0302.h"

#include "bg_cell_manager.h"
#include "bg_window.h"
#include "filesystem.h"
#include "filesystem_files_def.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "item.h"
#include "menu_input_state.h"
#include "message_format.h"
#include "message_printer.h"
#include "move.h"
#include "msgdata.h"
#include "options.h"
#include "overlay_manager.h"
#include "party.h"
#include "party_menu.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokemon.h"
#include "pokemon_icon_idx.h"
#include "pokemon_summary_internal.h"
#include "pokepic_anim_internal.h"
#include "render_window.h"
#include "ribbon.h"
#include "save_vars_flags.h"
#include "screen_fade.h"
#include "sound_chatot.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "sprite_system.h"
#include "sys_flags.h"
#include "system.h"
#include "touchpad.h"
#include "touchscreen.h"
#include "type_icon_resources.h"
#include "ui_util.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"

#define FillBgTilemapRect_U32(bgConfig, bgId, fillValue, x, y, width, height, mode) ((void (*)(BgConfig *, u8, u32, u8, u8, u8, u8, u8))FillBgTilemapRect)(bgConfig, bgId, fillValue, x, y, width, height, mode)

#define Sprite_SetFlipMode_Int(sprite, flip) ((void (*)(Sprite *, int))Sprite_SetFlipMode)(sprite, flip)
#define GetRibbonAttr_Int(ribbon, attr)      ((u32(*)(int, RibbonAttr))GetRibbonAttr)(ribbon, attr)

static void PokemonSummary_VBlank(void *data);
static void PokemonSummary_SetGraphicsBanks(void);
static void PokemonSummary_InitBgs(BgConfig *bgConfig);
static void PokemonSummary_FreeBgs(BgConfig *bgConfig);
static void PokemonSummary_LoadBgGraphics(PokemonSummary *summary, NARC *unused, NARC *narc);
static void PokemonSummary_SetBlend(void);
static void PokemonSummary_InitText(PokemonSummary *summary);
static void PokemonSummary_FreeText(PokemonSummary *summary);
static void PokemonSummary_InitBgCells(PokemonSummary *summary, NARC *narc);
static void PokemonSummary_FreeBgCells(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_WaitFadeIn(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_HandleInput(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_WaitSlideInMoveInfo(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_WaitSlideOutMoveInfo(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_HandleMoveSelectInput(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_StartMoveSwap(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_HandleMoveSwapInput(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_HandleForgetMoveInput(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_HandleForgetMoveConfirmInput(PokemonSummary *arg);
static enum PokemonSummaryState PokemonSummary_OpenRibbonList(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_CloseRibbonList(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_HandleRibbonInput(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_WaitRibbonPageUp(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_WaitRibbonPageDown(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_UpdateCondition(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_ShowConditionChanges(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_WaitConditionExit(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_StartFadeOut(PokemonSummary *summary);
static int PokemonSummary_WaitFadeOut(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_ChangeMonByButton(PokemonSummary *summary);
static void PokemonSummary_ReadShownMon(PokemonSummary *summary);
static void PokemonSummary_ReadBoxMon(PokemonSummary *summary, BoxPokemon *boxMon, PokemonSummaryMon *out);
static void PokemonSummary_PlayCry(PokemonSummary *summary);
static void PokemonSummary_ShowFirstPage(PokemonSummary *summary);
static void PokemonSummary_SetPage(PokemonSummary *summary, int page);
static void PokemonSummary_ChangePage(PokemonSummary *summary, int page);
static void PokemonSummary_ScrollPage(PokemonSummary *summary, int direction);
static BOOL PokemonSummary_HasPage(PokemonSummary *summary, int page);
static enum PokemonSummaryState PokemonSummary_HandleTouchInput(PokemonSummary *arg);
static void PokemonSummary_LoadBgScreen(PokemonSummary *summary, BgConfig *bgConfig, int member, int bgId);
static void PokemonSummary_LoadPageBgs(PokemonSummary *summary);
static void PokemonSummary_DrawHpBar(PokemonSummary *summary);
static void PokemonSummary_DrawExpBar(PokemonSummary *summary);
static void PokemonSummary_ShowMon(PokemonSummary *summary, u8 slot);
static void PokemonSummary_ChangeMon(PokemonSummary *summary, int direction);
static int PokemonSummary_FindNextMon(PokemonSummary *summary, int direction);
static BOOL PokemonSummary_CanShowMonAt(PokemonSummary *summary, int slot);
static BOOL PokemonSummary_CanShowEgg(PokemonSummary *summary);
static int PokemonSummary_FindNextMonInArray(PokemonSummary *summary, int direction);
static int PokemonSummary_FindNextPartyMon(PokemonSummary *summary, int direction);
static int PokemonSummary_FindNextBoxMon(PokemonSummary *summary, int direction);
static BOOL PokemonSummary_SlideInMoveInfo(PokemonSummary *summary);
static BOOL PokemonSummary_SlideOutMoveInfo(PokemonSummary *summary);
static BOOL PokemonSummary_MoveMoveCursor(PokemonSummary *summary, int direction);
static void PokemonSummary_ShowSelectedMoveInfo(PokemonSummary *summary);
static void PokemonSummary_ShowMoveInfo(PokemonSummary *summary, int move);
static void PokemonSummary_SwapMoves(PokemonSummary *summary);
static void PokemonSummary_InitForgetMove(PokemonSummary *summary);
static void PokemonSummary_UpdateForgetMovePage(PokemonSummary *summary);
static BOOL PokemonSummary_SlideInRibbonList(PokemonSummary *summary);
static BOOL PokemonSummary_SlideOutRibbonList(PokemonSummary *summary);
static void PokemonSummary_MoveRibbonCursor(PokemonSummary *summary, int direction);
static u8 PokemonSummary_GetRibbonAt(PokemonSummary *summary, u8 cell);
static void PokemonSummary_SetMenuInputState(PokemonSummary *summary, int state);
static int PokemonSummary_GetTouchedMove(PokemonSummary *summary);
static int PokemonSummary_GetMoveSwapTouch(PokemonSummary *summary);
static int PokemonSummary_GetMoveSelectTouch(PokemonSummary *summary);
static int PokemonSummary_GetForgetMoveTouch(PokemonSummary *summary);
static int PokemonSummary_GetForgetConfirmTouch(PokemonSummary *summary);
static int PokemonSummary_GetMonButtonTouch(PokemonSummary *summary);
static int PokemonSummary_GetRibbonTouch(PokemonSummary *summary);
static enum PokemonSummaryState PokemonSummary_ShowForgetConfirm(PokemonSummary *summary);
static void PokemonSummary_DrawForgetConfirm(PokemonSummary *summary, BOOL show);
static void PokemonSummary_ClearForgetButton(PokemonSummary *summary);
static void PokemonSummary_DrawSwitchButton(PokemonSummary *summary, BOOL show);
static enum PokemonSummaryState PokemonSummary_StartButtonFlash(PokemonSummary *summary, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 palette, u8 restorePalette, u8 nextState);
static enum PokemonSummaryState PokemonSummary_FlashCancelButton(PokemonSummary *summary, u8 nextState);
static enum PokemonSummaryState PokemonSummary_FlashConfirmButton(PokemonSummary *summary, u8 nextState);
static enum PokemonSummaryState PokemonSummary_FlashSwapButton(PokemonSummary *summary, u8 nextState);
static enum PokemonSummaryState PokemonSummary_FlashMonButton(PokemonSummary *summary, int which, u8 nextState);
static enum PokemonSummaryState PokemonSummary_FlashRibbonCancelButton(PokemonSummary *summary, u8 nextState);
static void PokemonSummary_DrawMonButtons(PokemonSummary *summary);
static void PokemonSummary_InitSpriteSystem(PokemonSummary *summary);
static void PokemonSummary_FreeSpriteSystem(PokemonSummary *summary);
static void PokemonSummary_UpdateSpriteAnims(PokemonSummary *summary);
static void PokemonSummary_CreateSprites(PokemonSummary *summary);
static void PokemonSummary_UpdatePartySlotSprite(PokemonSummary *summary);
static void PokemonSummary_HideSprites0To7And21And22(PokemonSummary *summary);
static void PokemonSummary_LoadBallSprite(PokemonSummary *summary);
static void PokemonSummary_UpdateStatusSprite(PokemonSummary *summary);
static void PokemonSummary_LoadTypeAndIconSprites(PokemonSummary *summary);
static void PokemonSummary_UpdateTypeSprites(PokemonSummary *summary);
static void PokemonSummary_HidePokeathlonStars(PokemonSummary *summary);
static void PokemonSummary_InitShinyLeafSprites(PokemonSummary *summary);
static void PokemonSummary_SetPokeathlonStatStars(Sprite **sprites, int firstStar, int maxStars, int baseStars, int color, int modifier, int modifierSprite);
static void PokemonSummary_UpdatePokeathlonStars(PokemonSummary *summary);
static void PokemonSummary_UpdateShinyLeafSprites(PokemonSummary *summary);
static void PokemonSummary_SetMonTypeSprites(PokemonSummary *summary);
static void PokemonSummary_SetTypeSprite(PokemonSummary *summary, u8 sprite, u8 resId, u8 type);
static void PokemonSummary_FindMoveTypeSprite(PokemonSummary *summary, u8 *slot, s16 *x, s16 *y);
static void PokemonSummary_SwapMoveTypeSprites(PokemonSummary *summary, u8 slotA, u8 slotB);
static void PokemonSummary_SetMoveCategorySprite(PokemonSummary *summary, u16 move);
static void PokemonSummary_UpdateMoveCursorSprite(PokemonSummary *summary);
static void PokemonSummary_ShowSwapCursorSprite(PokemonSummary *summary);
static void PokemonSummary_ResetSwapCursorSprite(PokemonSummary *summary);
static void PokemonSummary_InitSheenSparkles(PokemonSummary *summary);
static void PokemonSummary_UpdateMarkingSprites(PokemonSummary *summary);
static void PokemonSummary_ShowConditionChangeSprites(PokemonSummary *summary);
static void PokemonSummary_LoadMonIcon(PokemonSummary *summary, void *mon, int sprite);
static void PokemonSummary_LoadShownMonIcon(PokemonSummary *summary);
static void PokemonSummary_LoadPartyIcons(PokemonSummary *summary);
static void PokemonSummary_SetBoxMonIconPos(PokemonSummary *summary);
static void PokemonSummary_AlternateBoxMonIcon(PokemonSummary *summary);
static void PokemonSummary_ShowMonIconSprite(PokemonSummary *summary);
static s16 PokemonSummary_GetConditionPoint(int stat, s16 tip, s16 center);
static void PokemonSummary_ShowConditionSprites(PokemonSummary *summary);
static void PokemonSummary_HideConditionSprites(PokemonSummary *summary);
static void PokemonSummary_SetRibbonSprite(PokemonSummary *summary, int ribbon, int index);
static void PokemonSummary_ShowRibbonSprites(PokemonSummary *summary);
static void PokemonSummary_UpdateRibbonSprites(PokemonSummary *summary);
static void PokemonSummary_UpdateRibbonCursorSprite(PokemonSummary *summary);
static void PokemonSummary_AnimateRibbonSprite66(PokemonSummary *summary);

static u8 sPokemonSummaryPartySlotPositions[][2] = {
    { 183, 55  },
    { 223, 63  },
    { 183, 87  },
    { 223, 95  },
    { 183, 119 },
    { 223, 127 },
};

static const ResdatIdList sPokemonSummarySpriteResdatIds = {
    .charRes = NARC_resdat_resdat_00000054_bin,
    .plttRes = NARC_resdat_resdat_00000055_bin,
    .cellRes = NARC_resdat_resdat_00000053_bin,
    .animRes = NARC_resdat_resdat_00000052_bin,
    .mcelRes = 0xFFFF,
    .manmRes = 0xFFFF,
    .headerId = NARC_resdat_resdat_00000085_bin,
};

static const OamCharTransferParam sPokemonSummaryOamTransferParam = {
    .maxTasks = 115,
    .sizeMain = 0x400,
    .sizeSub = 0x400,
    .charModeMain = GX_OBJVRAMMODE_CHAR_1D_32K,
    .charModeSub = GX_OBJVRAMMODE_CHAR_1D_32K,
};

static const OamManagerParam sPokemonSummaryOamManagerParam = {
    .fromOBJmain = 0,
    .numOBJmain = 128,
    .fromAffineMain = 0,
    .numAffineMain = 32,
    .fromOBJsub = 0,
    .numOBJsub = 128,
    .fromAffineSub = 0,
    .numAffineSub = 32,
};

static const UnmanagedSpriteTemplate sPokemonSummarySpriteTemplates[POKEMON_SUMMARY_SPRITE_COUNT] = {
    { 1,  128, 24,  0, 0, 1, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  144, 24,  0, 1, 1, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  160, 24,  0, 2, 1, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  176, 24,  0, 3, 1, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  192, 24,  0, 4, 1, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  208, 24,  0, 5, 1, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  224, 24,  0, 6, 1, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 1,  240, 24,  0, 7, 1, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 0,  168, 39,  0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 2,  68,  24,  0, 0, 1, 2,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 2,  68,  24,  0, 1, 0, 2,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 3,  0,   0,   0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 4,  0,   0,   0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 5,  0,   0,   0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 6,  0,   0,   0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 7,  0,   0,   0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 8,  0,   0,   0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 9,  0,   0,   0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 10, 0,   0,   0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 11, 160, 16,  0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 12, 232, 58,  0, 0, 0, 3,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 14, 0,   24,  0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 14, 0,   24,  0, 1, 0, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 17, 200, 150, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 18, 208, 150, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 19, 216, 150, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 20, 224, 150, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 21, 232, 150, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 22, 240, 150, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 152, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 160, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 168, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 176, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 184, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 192, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 200, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 208, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 216, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 224, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 232, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 13, 240, 168, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 15, 208, 48,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 15, 224, 88,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 15, 216, 120, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 15, 144, 120, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 15, 136, 88,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 16, 0,   0,   0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 24, 0,   0,   0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 24, 0,   0,   0, 1, 0, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 24, 0,   0,   0, 3, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 24, 0,   0,   0, 2, 0, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 24, 0,   0,   0, 4, 0, 0,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 23, 252, 72,  0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 23, 252, 132, 0, 1, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 25, 32,  24,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 26, 64,  24,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 27, 96,  24,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 28, 32,  64,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 29, 64,  64,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 30, 96,  64,  0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 31, 32,  104, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 32, 64,  104, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 33, 96,  104, 0, 0, 0, 0,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 34, 32,  24,  0, 0, 0, 15, NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 34, 128, 32,  0, 4, 0, 15, NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 34, 128, 96,  0, 5, 0, 15, NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 35, 164, 148, 0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 36, 32,  24,  0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 36, 32,  24,  0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 36, 32,  24,  0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 36, 32,  24,  0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 36, 32,  24,  0, 0, 0, 2,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 37, 228, 54,  0, 0, 0, 1,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 38, 184, 50,  0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 39, 224, 58,  0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 40, 184, 82,  0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 41, 224, 90,  0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 42, 184, 114, 0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 43, 224, 122, 0, 0, 0, 4,  NNS_G2D_VRAM_TYPE_2DSUB,  0, 0, 0, 0 },
    { 44, 64,  48,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  48,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 96,  48,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 112, 48,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 128, 48,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 64,  80,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  80,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 96,  80,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 112, 80,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 128, 80,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 64,  112, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  112, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 96,  112, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 112, 112, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 128, 112, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 64,  144, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  144, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 96,  144, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 112, 144, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 128, 144, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 64,  176, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  176, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 96,  176, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 112, 176, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 128, 176, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  32,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  64,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  96,  0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  128, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 80,  160, 0, 0, 0, 5,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 91,  182, 0, 6, 0, 6,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 101, 182, 0, 6, 0, 6,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 111, 182, 0, 6, 0, 6,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 121, 182, 0, 6, 0, 6,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 131, 182, 0, 6, 0, 6,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
    { 44, 111, 182, 0, 7, 0, 6,  NNS_G2D_VRAM_TYPE_2DMAIN, 0, 0, 0, 0 },
};

static const u8 sPokemonSummaryBallPalettes[] = { 2, 0, 2, 2, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 2, 0, 4, 5, 6, 7, 8, 9, 10, 11, 0, 0, 0 };

u32 PokemonSummary_GetDefaultUnk2C(SaveData *saveData) {
    return 1;
}

BOOL PokemonSummary_IsPokeathlonUnlocked(SaveData *saveData) {
    return CheckFlag982(Save_VarsFlags_Get(saveData));
}

BOOL PokemonSummary_Init(OverlayManager *manager, int *state) {
    NARC *ribbonNarc;
    NARC *graphicsNarc;
    PokemonSummary *summary;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    reg_GX_DISPCNT &= 0xFFFF1FFF;
    reg_GXS_DB_DISPCNT &= 0xFFFF1FFF;
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    SetKeyRepeatTimers(4, 8);
    Heap_Create(HEAP_ID_3, HEAP_ID_19, 0x45000);
    ribbonNarc = NARC_New(NARC_a_0_3_9, HEAP_ID_19);
    graphicsNarc = NARC_New(NARC_a_1_6_2, HEAP_ID_19);
    summary = OverlayManager_CreateAndGetData(manager, sizeof(PokemonSummary), HEAP_ID_19);
    memset(summary, 0, sizeof(PokemonSummary));
    summary->args = OverlayManager_GetArgs(manager);
    summary->bgConfig = BgConfig_Alloc(HEAP_ID_19);
    *(u32 *)summary->args->monModified = 0;
    summary->pokepicAnimManager = PokepicAnimManager_New(HEAP_ID_19, 1, TRUE);
    summary->pokepicAnimNarc = NARC_New(NARC_a_1_8_0, HEAP_ID_19);
    FontID_SetAccessDirect(0, HEAP_ID_19);
    GF_TouchpadResetSampling();
    GF_TouchpadStartSampling(4);
    PokemonSummary_SetGraphicsBanks();
    PokemonSummary_InitBgs(summary->bgConfig);
    PokemonSummary_LoadBgGraphics(summary, ribbonNarc, graphicsNarc);
    PokemonSummary_SetBlend();
    PokemonSummary_Init3D(summary);
    FontID_Alloc(4, HEAP_ID_19);
    PokemonSummary_InitText(summary);
    PokemonSummary_InitBgCells(summary, graphicsNarc);
    PokemonSummary_ReadShownMon(summary);
    PokemonSummary_InitSpriteSystem(summary);
    PokemonSummary_CreateSprites(summary);
    PokemonSummary_CreatePokepic(summary);
    PokemonSummary_LoadBallSprite(summary);
    PokemonSummary_UpdateStatusSprite(summary);
    PokemonSummary_LoadPartyIcons(summary);
    PokemonSummary_AddWindows(summary);
    PokemonSummary_ShowFirstPage(summary);
    PokemonSummary_CreateCamera(summary);
    Main_SetVBlankIntrCB(PokemonSummary_VBlank, summary);
    reg_GX_POWCNT |= 0x8000;
    GfGfx_BothDispOn();
    Sound_SetSceneAndPlayBGM(61, SEQ_NONE, 0);
    WirelessStatusIcon_CreateIfConnected();
    NARC_Delete(graphicsNarc);
    NARC_Delete(ribbonNarc);
    return TRUE;
}

BOOL PokemonSummary_Main(OverlayManager *manager, int *state) {
    PokemonSummary *summary = OverlayManager_GetData(manager);

    switch (*state) {
    case POKEMON_SUMMARY_STATE_START_FADE_IN:
        BeginAppScreenFade(0, HEAP_ID_19);
        Pokepic_SetAttr(summary->pokepic, POKEPIC_VANISHED, 0);
        *state = POKEMON_SUMMARY_STATE_WAIT_FADE_IN;
        break;
    case POKEMON_SUMMARY_STATE_WAIT_FADE_IN:
        *state = PokemonSummary_WaitFadeIn(summary);
        break;
    case POKEMON_SUMMARY_STATE_INPUT:
        *state = PokemonSummary_HandleInput(summary);
        break;
    case POKEMON_SUMMARY_STATE_SLIDE_IN_MOVE_INFO:
        *state = PokemonSummary_WaitSlideInMoveInfo(summary);
        break;
    case POKEMON_SUMMARY_STATE_SLIDE_OUT_MOVE_INFO:
        *state = PokemonSummary_WaitSlideOutMoveInfo(summary);
        break;
    case POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT:
        *state = PokemonSummary_HandleMoveSelectInput(summary);
        break;
    case POKEMON_SUMMARY_STATE_START_MOVE_SWAP:
        *state = PokemonSummary_StartMoveSwap(summary);
        break;
    case POKEMON_SUMMARY_STATE_MOVE_SWAP_INPUT:
        *state = PokemonSummary_HandleMoveSwapInput(summary);
        break;
    case POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT:
        *state = PokemonSummary_HandleForgetMoveInput(summary);
        break;
    case POKEMON_SUMMARY_STATE_FORGET_MOVE_CONFIRM_INPUT:
        *state = PokemonSummary_HandleForgetMoveConfirmInput(summary);
        break;
    case POKEMON_SUMMARY_STATE_OPEN_RIBBON_LIST:
        *state = PokemonSummary_OpenRibbonList(summary);
        break;
    case POKEMON_SUMMARY_STATE_CLOSE_RIBBON_LIST:
        *state = PokemonSummary_CloseRibbonList(summary);
        break;
    case POKEMON_SUMMARY_STATE_RIBBON_INPUT:
        *state = PokemonSummary_HandleRibbonInput(summary);
        break;
    case POKEMON_SUMMARY_STATE_RIBBON_PAGE_UP:
        *state = PokemonSummary_WaitRibbonPageUp(summary);
        break;
    case POKEMON_SUMMARY_STATE_RIBBON_PAGE_DOWN:
        *state = PokemonSummary_WaitRibbonPageDown(summary);
        break;
    case POKEMON_SUMMARY_STATE_FLASH_BUTTON:
        *state = PokemonSummary_FlashButton(summary);
        break;
    case POKEMON_SUMMARY_STATE_UPDATE_CONDITION:
        *state = PokemonSummary_UpdateCondition(summary);
        break;
    case POKEMON_SUMMARY_STATE_SHOW_CONDITION_CHANGES:
        *state = PokemonSummary_ShowConditionChanges(summary);
        break;
    case POKEMON_SUMMARY_STATE_WAIT_CONDITION_EXIT:
        *state = PokemonSummary_WaitConditionExit(summary);
        break;
    case POKEMON_SUMMARY_STATE_START_FADE_OUT:
        *state = PokemonSummary_StartFadeOut(summary);
        break;
    case POKEMON_SUMMARY_STATE_WAIT_FADE_OUT:
        if (PokemonSummary_WaitFadeOut(summary) == 1) {
            return TRUE;
        }
        break;
    case POKEMON_SUMMARY_STATE_SHOW_POKEPIC:
        Pokepic_SetAttr(summary->pokepic, POKEPIC_VANISHED, 0);
        *state = POKEMON_SUMMARY_STATE_INPUT;
        break;
    case POKEMON_SUMMARY_STATE_CHANGE_MON_BY_BUTTON:
        *state = PokemonSummary_ChangeMonByButton(summary);
        break;
    }
    PokemonSummary_UpdateSpriteAnims(summary);
    PokemonSummary_AnimateRibbonSprite66(summary);
    SpriteSystem_DrawSprites(summary->spriteManager);
    PokemonSummary_DrawPokepic(summary);
    return FALSE;
}

BOOL PokemonSummary_Exit(OverlayManager *manager, int *state) {
    PokemonSummary *summary = OverlayManager_GetData(manager);

    Main_SetVBlankIntrCB(NULL, NULL);
    PokemonSummary_FreePokepicAndCamera(summary);
    PokemonSummary_FreeSpriteSystem(summary);
    PokemonSummary_RemoveWindows(summary);
    PokemonSummary_FreeBgs(summary->bgConfig);
    GF_TouchpadStopSampling();
    GF_DestroyVramTransferManager();
    PokemonSummary_FreeBgCells(summary);
    PokemonSummary_FreeText(summary);
    FontID_Release(4);
    NARC_Delete(summary->pokepicAnimNarc);
    FontID_SetAccessLazy(0);
    reg_G2_BLDCNT = 0;
    OverlayManager_FreeData(manager);
    Heap_Destroy(HEAP_ID_19);
    return TRUE;
}

static void PokemonSummary_VBlank(void *data) {
    PokemonSummary *summary = data;
    DoScheduledBgGpuUpdates(summary->bgConfig);
    PokepicManager_HandleLoadImgAndOrPltt(summary->pokepicManager);
    GF_RunVramTransferTasks();
    SpriteSystem_TransferOam();
    OS_SetIrqCheckFlag(OS_IE_VBLANK);
}

static void PokemonSummary_SetGraphicsBanks(void) {
    GraphicsBanks banks = gPokemonSummaryGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static void PokemonSummary_InitBgs(BgConfig *bgConfig) {
    {
        GraphicsModes modes = gPokemonSummaryGraphicsModes;
        SetBothScreensModesAndDisable(&modes);
    }
    {
        BgTemplate template = gPokemonSummaryBgTemplate1;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_1, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_1);
    }
    {
        BgTemplate template = gPokemonSummaryBgTemplate2;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_2, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_MAIN_2);
        ScheduleSetBgPosText(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
    }
    {
        BgTemplate template = gPokemonSummaryBgTemplate3;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_MAIN_3, &template, GF_BG_TYPE_TEXT);
    }
    {
        BgTemplate template = gPokemonSummaryBgTemplate4;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_0, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_0);
    }
    {
        BgTemplate template = gPokemonSummaryBgTemplate5;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_1, &template, GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, GF_BG_LYR_SUB_1);
    }
    {
        BgTemplate template = gPokemonSummaryBgTemplate6;
        InitBgFromTemplate(bgConfig, GF_BG_LYR_SUB_2, &template, GF_BG_TYPE_TEXT);
    }
    BG_ClearCharDataRange(GF_BG_LYR_MAIN_1, 0x20, 0, HEAP_ID_19);
    BG_ClearCharDataRange(GF_BG_LYR_SUB_0, 0x20, 0, HEAP_ID_19);
}

static void PokemonSummary_FreeBgs(BgConfig *bgConfig) {
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_1);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_SUB_0);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_3);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_2);
    FreeBgTilemapBuffer(bgConfig, GF_BG_LYR_MAIN_1);
    Heap_FreeExplicit(HEAP_ID_19, bgConfig);
}

static void PokemonSummary_LoadBgGraphics(PokemonSummary *summary, NARC *unused, NARC *narc) {
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x200, HEAP_ID_19);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, summary->bgConfig, GF_BG_LYR_MAIN_3, 0, 0x4400, FALSE, HEAP_ID_19);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 13, summary->bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, HEAP_ID_19);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x200, HEAP_ID_19);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 1, summary->bgConfig, GF_BG_LYR_SUB_2, 0, 0x4400, FALSE, HEAP_ID_19);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 20, summary->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_19);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 21, summary->bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, HEAP_ID_19);
}

static void PokemonSummary_SetBlend(void) {
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG0, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 23, 8);
}

static void PokemonSummary_InitText(PokemonSummary *summary) {
    summary->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0302_bin, HEAP_ID_19);
    summary->ribbonMsgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0424_bin, HEAP_ID_19);
    summary->numberPrinter = MessagePrinter_New(1, 2, 0, HEAP_ID_19);
    summary->msgFormat = MessageFormat_New(HEAP_ID_19);
    summary->mon.speciesName = String_New(12, HEAP_ID_19);
    summary->mon.nickname = String_New(12, HEAP_ID_19);
    summary->mon.otName = String_New(8, HEAP_ID_19);
    summary->buffer = String_New(128, HEAP_ID_19);
    summary->moveNames = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0750_bin, HEAP_ID_19);
    summary->playerName = String_New(8, HEAP_ID_19);
    if (summary->args->playerName != NULL) {
        CopyU16ArrayToString(summary->playerName, summary->args->playerName);
    }
}

static void PokemonSummary_FreeText(PokemonSummary *summary) {
    DestroyMsgData(summary->moveNames);
    DestroyMsgData(summary->ribbonMsgData);
    DestroyMsgData(summary->msgData);
    MessagePrinter_Delete(summary->numberPrinter);
    MessageFormat_Delete(summary->msgFormat);
    String_Delete(summary->mon.speciesName);
    String_Delete(summary->mon.nickname);
    String_Delete(summary->mon.otName);
    String_Delete(summary->buffer);
    String_Delete(summary->playerName);
}

static void PokemonSummary_InitBgCells(PokemonSummary *summary, NARC *narc) {
    summary->cellManager = BgCellManager_New(summary->bgConfig, 2, 7, HEAP_ID_19);
    BgCellManager_InitCell(summary->cellManager, 0, 6, 17, 6);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 0, narc, 69, FALSE);
    BgCellManager_InitCell(summary->cellManager, 1, 6, 17, 6);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 1, narc, 70, FALSE);
    BgCellManager_InitCell(summary->cellManager, 2, 6, 10, 4);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 2, narc, 71, FALSE);
    BgCellManager_InitCell(summary->cellManager, 3, 6, 10, 4);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 3, narc, 72, FALSE);
    BgCellManager_InitCell(summary->cellManager, 4, 6, 11, 14);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 4, narc, 73, FALSE);
    BgCellManager_InitCell(summary->cellManager, 5, 6, 6, 3);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 5, narc, 74, FALSE);
    BgCellManager_InitCell(summary->cellManager, 6, 6, 6, 3);
    BgCellManager_LoadCellTilemapFromOpenNarc(summary->cellManager, 6, narc, 75, FALSE);
}

static void PokemonSummary_FreeBgCells(PokemonSummary *summary) {
    BgCellManager_Delete(summary->cellManager);
}

// State 1: wait for the fade-in, then go to the screen's starting state.
static enum PokemonSummaryState PokemonSummary_WaitFadeIn(PokemonSummary *summary) {
    u8 mode;

    if (IsPaletteFadeFinished() == TRUE) {
        PokemonSummary_StartPokepicAnim(summary);
        PokemonSummary_PlayCry(summary);
        mode = summary->args->mode;
        if (mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
            return POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT;
        }
        if (mode == POKEMON_SUMMARY_MODE_UPDATE_CONDITION) {
            return POKEMON_SUMMARY_STATE_UPDATE_CONDITION;
        }
        return POKEMON_SUMMARY_STATE_INPUT;
    }
    return POKEMON_SUMMARY_STATE_WAIT_FADE_IN;
}

// State 2: the page input.
static enum PokemonSummaryState PokemonSummary_HandleInput(PokemonSummary *summary) {
    int selection;

    if (summary->exitRequested == 1) {
        summary->args->exitedWithB = 1;
        return POKEMON_SUMMARY_STATE_START_FADE_OUT;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) {
        PokemonSummary_ScrollPage(summary, -1);
        return POKEMON_SUMMARY_STATE_INPUT;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) {
        PokemonSummary_ScrollPage(summary, 1);
        return POKEMON_SUMMARY_STATE_INPUT;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        PokemonSummary_ChangeMon(summary, -1);
        return POKEMON_SUMMARY_STATE_SHOW_POKEPIC;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        PokemonSummary_ChangeMon(summary, 1);
        return POKEMON_SUMMARY_STATE_SHOW_POKEPIC;
    }
    if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        summary->args->exitedWithB = 1;
        PokemonSummary_SetMenuInputState(summary, 0);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_START_FADE_OUT);
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        switch (summary->page) {
        case POKEMON_SUMMARY_PAGE_STATS:
            PlaySE(SEQ_SE_DP_SYU01);
            summary->moveSlot = 0;
            return POKEMON_SUMMARY_STATE_SLIDE_IN_MOVE_INFO;
        case POKEMON_SUMMARY_PAGE_RIBBONS:
            if (summary->ribbonCount != 0) {
                PlaySE(SEQ_SE_DP_DECIDE);
                summary->ribbonCursor = 0;
                return POKEMON_SUMMARY_STATE_OPEN_RIBBON_LIST;
            }
            break;
        }
    }
    if (summary->page == POKEMON_SUMMARY_PAGE_STATS) {
        selection = PokemonSummary_GetTouchedMove(summary);
        if (selection != -1 && summary->mon.moves[selection] != MOVE_NONE) {
            PlaySE(SEQ_SE_DP_SYU01);
            summary->moveSlot = selection;
            return POKEMON_SUMMARY_STATE_SLIDE_IN_MOVE_INFO;
        }
    }
    if (summary->page == POKEMON_SUMMARY_PAGE_RIBBONS) {
        selection = PokemonSummary_GetRibbonTouch(summary);
        if (selection != -1 && selection < POKEMON_SUMMARY_RIBBONS_PER_PAGE && selection < summary->ribbonCount) {
            PlaySE(SEQ_SE_DP_DECIDE);
            summary->ribbonCursor = selection;
            return POKEMON_SUMMARY_STATE_OPEN_RIBBON_LIST;
        }
    }
    if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
        selection = PokemonSummary_GetMonButtonTouch(summary);
        if (selection == 0) {
            if (PokemonSummary_FindNextMon(summary, -1) != -1) {
                PlaySE(SEQ_SE_DP_DECIDE);
                return PokemonSummary_FlashMonButton(summary, 0, POKEMON_SUMMARY_STATE_CHANGE_MON_BY_BUTTON);
            }
            return POKEMON_SUMMARY_STATE_INPUT;
        }
        if (selection == 1) {
            if (PokemonSummary_FindNextMon(summary, 1) != -1) {
                PlaySE(SEQ_SE_DP_DECIDE);
                return PokemonSummary_FlashMonButton(summary, 1, POKEMON_SUMMARY_STATE_CHANGE_MON_BY_BUTTON);
            }
            return POKEMON_SUMMARY_STATE_INPUT;
        }
    }
    return PokemonSummary_HandleTouchInput(summary);
}

static enum PokemonSummaryState PokemonSummary_WaitSlideInMoveInfo(PokemonSummary *summary) {
    if (PokemonSummary_SlideInMoveInfo(summary) == TRUE) {
        PokemonSummary_DrawSwitchButton(summary, TRUE);
        return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
    }
    return POKEMON_SUMMARY_STATE_SLIDE_IN_MOVE_INFO;
}

static enum PokemonSummaryState PokemonSummary_WaitSlideOutMoveInfo(PokemonSummary *summary) {
    if (PokemonSummary_SlideOutMoveInfo(summary) == TRUE) {
        return POKEMON_SUMMARY_STATE_INPUT;
    }
    return POKEMON_SUMMARY_STATE_SLIDE_OUT_MOVE_INFO;
}

// State 5: pick a move to move (A) or leave the move list (B).
static enum PokemonSummaryState PokemonSummary_HandleMoveSelectInput(PokemonSummary *summary) {
    u32 keys;
    int index;

    keys = gSystem.newKeys;

    if (keys & PAD_KEY_UP) {
        if (PokemonSummary_MoveMoveCursor(summary, -1) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
    }
    if (keys & PAD_KEY_DOWN) {
        if (PokemonSummary_MoveMoveCursor(summary, 1) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
    }
    if ((keys & PAD_BUTTON_A) && summary->args->mode != POKEMON_SUMMARY_MODE_NO_MOVE_SWAP) {
        PlaySE(SEQ_SE_DP_DECIDE);
        return PokemonSummary_FlashSwapButton(summary, POKEMON_SUMMARY_STATE_START_MOVE_SWAP);
    }
    if (keys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        PokemonSummary_DrawSwitchButton(summary, FALSE);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_SLIDE_OUT_MOVE_INFO);
    }
    index = PokemonSummary_GetMoveSelectTouch(summary);
    if (index == 4) {
        if (summary->args->mode != POKEMON_SUMMARY_MODE_NO_MOVE_SWAP) {
            PlaySE(SEQ_SE_DP_DECIDE);
            return PokemonSummary_FlashSwapButton(summary, POKEMON_SUMMARY_STATE_START_MOVE_SWAP);
        }
    } else if (index == 5) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        PokemonSummary_DrawSwitchButton(summary, FALSE);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_SLIDE_OUT_MOVE_INFO);
    } else if (index != -1 && summary->mon.moves[index] != MOVE_NONE) {
        summary->moveSlot = index;
        PlaySE(SEQ_SE_DP_SELECT);
        PokemonSummary_ShowSelectedMoveInfo(summary);
        return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
    }
    return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
}

// State 7: show the swap cursor on the picked move.
static enum PokemonSummaryState PokemonSummary_StartMoveSwap(PokemonSummary *summary) {
    PokemonSummary_DrawSwitchButton(summary, FALSE);
    PokemonSummary_ShowSwapCursorSprite(summary);
    summary->swapMoveSlot = summary->moveSlot;
    return POKEMON_SUMMARY_STATE_MOVE_SWAP_INPUT;
}

// State 6: pick the move to swap with.
static enum PokemonSummaryState PokemonSummary_HandleMoveSwapInput(PokemonSummary *summary) {
    int index;

    if (gSystem.newKeys & PAD_KEY_UP) {
        if (PokemonSummary_MoveMoveCursor(summary, -1) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        return POKEMON_SUMMARY_STATE_MOVE_SWAP_INPUT;
    }
    if (gSystem.newKeys & PAD_KEY_DOWN) {
        if (PokemonSummary_MoveMoveCursor(summary, 1) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        return POKEMON_SUMMARY_STATE_MOVE_SWAP_INPUT;
    }
    if (gSystem.newKeys & PAD_BUTTON_A) {
        PokemonSummary_DrawSwitchButton(summary, TRUE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
        if (summary->moveSlot != summary->swapMoveSlot) {
            PlaySE(SEQ_SE_DP_DECIDE);
            PokemonSummary_SwapMoves(summary);
            PokemonSummary_SwapMoveTypeSprites(summary, summary->moveSlot, summary->swapMoveSlot);
            PokemonSummary_PrintSwappedMoves(summary);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        } else {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
    }
    if (gSystem.newKeys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        PokemonSummary_DrawSwitchButton(summary, TRUE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT);
    }
    index = PokemonSummary_GetMoveSwapTouch(summary);
    if (index == 4) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        PokemonSummary_DrawSwitchButton(summary, TRUE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT);
    }
    if (index != -1 && summary->mon.moves[index] != MOVE_NONE) {
        PokemonSummary_DrawSwitchButton(summary, TRUE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
        if (index != summary->swapMoveSlot) {
            summary->moveSlot = index;
            PlaySE(SEQ_SE_DP_DECIDE);
            PokemonSummary_SwapMoves(summary);
            PokemonSummary_SwapMoveTypeSprites(summary, summary->moveSlot, summary->swapMoveSlot);
            PokemonSummary_PrintSwappedMoves(summary);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        } else {
            PlaySE(SEQ_SE_DP_SELECT);
        }
        return POKEMON_SUMMARY_STATE_MOVE_SELECT_INPUT;
    }
    return POKEMON_SUMMARY_STATE_MOVE_SWAP_INPUT;
}

// State 8 (learning a move): pick the move to forget; the slot after the four moves is the move to learn.
static enum PokemonSummaryState PokemonSummary_HandleForgetMoveInput(PokemonSummary *summary) {
    u32 keys;
    int index;

    keys = gSystem.newKeys;

    if (keys & PAD_KEY_UP) {
        if (PokemonSummary_MoveMoveCursor(summary, -1) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        return POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT;
    }
    if (keys & PAD_KEY_DOWN) {
        if (PokemonSummary_MoveMoveCursor(summary, 1) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        return POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT;
    }
    if (keys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_DECIDE);
        index = summary->moveSlot;
        if (index == POKEMON_SUMMARY_MOVE_SLOT_NEW) {
            summary->args->selectedMoveSlot = POKEMON_SUMMARY_MOVE_SLOT_NEW;
            summary->args->exitedWithB = 0;
            return POKEMON_SUMMARY_STATE_START_FADE_OUT;
        }
        if (MoveIsHM(summary->mon.moves[index]) == TRUE && summary->args->moveToLearn != MOVE_NONE) {
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], FALSE);
            PokemonSummary_PrintCantForgetHMMessage(summary);
            return POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT;
        }
        return PokemonSummary_ShowForgetConfirm(summary);
    }
    if (keys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        summary->args->selectedMoveSlot = POKEMON_SUMMARY_MOVE_SLOT_NEW;
        summary->args->exitedWithB = 1;
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_START_FADE_OUT);
    }

    index = PokemonSummary_GetForgetMoveTouch(summary);
    switch (index) {
    case -1:
        break;
    case POKEMON_SUMMARY_MOVE_SLOT_NEW:
        if (summary->args->moveToLearn != MOVE_NONE) {
            PlaySE(SEQ_SE_DP_DECIDE);
            summary->moveSlot = POKEMON_SUMMARY_MOVE_SLOT_NEW;
            PokemonSummary_ShowSelectedMoveInfo(summary);
        }
        break;
    case POKEMON_SUMMARY_MOVE_SLOT_CANCEL:
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        summary->moveSlot = POKEMON_SUMMARY_MOVE_SLOT_CANCEL;
        summary->args->selectedMoveSlot = POKEMON_SUMMARY_MOVE_SLOT_NEW;
        summary->args->exitedWithB = 0;
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_START_FADE_OUT);
    default:
        if (MoveIsHM(summary->mon.moves[index]) == TRUE && summary->args->moveToLearn != MOVE_NONE) {
            PlaySE(SEQ_SE_DP_DECIDE);
            summary->moveSlot = index;
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], FALSE);
            PokemonSummary_UpdateMoveCursorSprite(summary);
            PokemonSummary_PrintCantForgetHMMessage(summary);
            return POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT;
        }
        if (summary->mon.moves[index] != MOVE_NONE) {
            PlaySE(SEQ_SE_DP_DECIDE);
            summary->moveSlot = index;
            PokemonSummary_ShowSelectedMoveInfo(summary);
            return PokemonSummary_ShowForgetConfirm(summary);
        }
        break;
    }
    return POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT;
}

// State 9: confirm forgetting the picked move.
static enum PokemonSummaryState PokemonSummary_HandleForgetMoveConfirmInput(PokemonSummary *arg) {
    struct System *system = &gSystem;
    PokemonSummary *summary = arg;
    u32 keys;
    int input;

    keys = system->newKeys;

    if (keys & PAD_BUTTON_A) {
        PlaySE(SEQ_SE_DP_DECIDE);
        summary->args->selectedMoveSlot = summary->moveSlot;
        summary->args->exitedWithB = 0;
        return PokemonSummary_FlashConfirmButton(summary, POKEMON_SUMMARY_STATE_START_FADE_OUT);
    }
    if (keys & PAD_BUTTON_B) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
        PokemonSummary_DrawForgetConfirm(summary, FALSE);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT);
    }
    input = PokemonSummary_GetForgetConfirmTouch(summary);
    if (input != -1) {
        switch (input) {
        case 0:
            PlaySE(SEQ_SE_DP_DECIDE);
            summary->args->selectedMoveSlot = summary->moveSlot;
            summary->args->exitedWithB = 0;
            return PokemonSummary_FlashConfirmButton(summary, POKEMON_SUMMARY_STATE_START_FADE_OUT);
        case 1:
            PlaySE(SEQ_SE_GS_GEARCANCEL);
            Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
            PokemonSummary_DrawForgetConfirm(summary, FALSE);
            return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_FORGET_MOVE_INPUT);
        default:
            break;
        }
    }
    return POKEMON_SUMMARY_STATE_FORGET_MOVE_CONFIRM_INPUT;
}

// State 10: open the ribbon list.
static enum PokemonSummaryState PokemonSummary_OpenRibbonList(PokemonSummary *summary) {
    if (PokemonSummary_SlideInRibbonList(summary) == 1) {
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    return POKEMON_SUMMARY_STATE_OPEN_RIBBON_LIST;
}

// State 11: close the ribbon list.
static enum PokemonSummaryState PokemonSummary_CloseRibbonList(PokemonSummary *summary) {
    if (PokemonSummary_SlideOutRibbonList(summary) == 1) {
        return POKEMON_SUMMARY_STATE_INPUT;
    }
    return POKEMON_SUMMARY_STATE_CLOSE_RIBBON_LIST;
}

// State 12: move the ribbon cursor; the arrows scroll by a page.
static enum PokemonSummaryState PokemonSummary_HandleRibbonInput(PokemonSummary *summary) {
    int selection;

    if (gSystem.newAndRepeatedKeys & PAD_KEY_LEFT) {
        PokemonSummary_MoveRibbonCursor(summary, -1);
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_RIGHT) {
        PokemonSummary_MoveRibbonCursor(summary, 1);
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_UP) {
        PokemonSummary_MoveRibbonCursor(summary, -POKEMON_SUMMARY_RIBBON_COLUMNS);
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    if (gSystem.newAndRepeatedKeys & PAD_KEY_DOWN) {
        PokemonSummary_MoveRibbonCursor(summary, POKEMON_SUMMARY_RIBBON_COLUMNS);
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        return PokemonSummary_FlashRibbonCancelButton(summary, POKEMON_SUMMARY_STATE_CLOSE_RIBBON_LIST);
    }
    selection = PokemonSummary_GetRibbonTouch(summary);
    switch (selection) {
    case -1:
        break;
    case 9:
        if (Sprite_GetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_UP]) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_UP], 2);
            return POKEMON_SUMMARY_STATE_RIBBON_PAGE_UP;
        }
        break;
    case 10:
        if (Sprite_GetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_DOWN]) == TRUE) {
            PlaySE(SEQ_SE_DP_SELECT);
            Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_DOWN], 3);
            return POKEMON_SUMMARY_STATE_RIBBON_PAGE_DOWN;
        }
        break;
    case 11:
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        return PokemonSummary_FlashRibbonCancelButton(summary, POKEMON_SUMMARY_STATE_CLOSE_RIBBON_LIST);
    default:
        if (summary->ribbonCursor != selection) {
            summary->ribbonCursor = selection;
            PlaySE(SEQ_SE_DP_SELECT);
            PokemonSummary_MoveRibbonCursor(summary, 0);
        }
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
}

// State 13: the up arrow was touched; scroll up a page once its animation ends.
static enum PokemonSummaryState PokemonSummary_WaitRibbonPageUp(PokemonSummary *summary) {
    if (!Sprite_IsAnimated(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_UP])) {
        PokemonSummary_MoveRibbonCursor(summary, -POKEMON_SUMMARY_RIBBONS_PER_PAGE);
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    return POKEMON_SUMMARY_STATE_RIBBON_PAGE_UP;
}

// State 14: the same for the down arrow.
static enum PokemonSummaryState PokemonSummary_WaitRibbonPageDown(PokemonSummary *summary) {
    if (!Sprite_IsAnimated(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_DOWN])) {
        PokemonSummary_MoveRibbonCursor(summary, POKEMON_SUMMARY_RIBBONS_PER_PAGE);
        return POKEMON_SUMMARY_STATE_RIBBON_INPUT;
    }
    return POKEMON_SUMMARY_STATE_RIBBON_PAGE_DOWN;
}

// State 16: on A or B, read the condition again; unk7BE gets one bit per stat (cool..tough) that changed.
static enum PokemonSummaryState PokemonSummary_UpdateCondition(PokemonSummary *summary) {
    Pokemon *mon;
    u8 old;

    if ((gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) != 0) {
        if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
            BoxPokemon *boxMon = PokemonSummary_GetShownMon(summary);
            mon = AllocMonZeroed(HEAP_ID_19);
            CopyBoxPokemonToPokemon(boxMon, mon);
        } else {
            mon = PokemonSummary_GetShownMon(summary);
        }
        summary->unk7BE = 0;
        old = summary->mon.contestStats[0];
        summary->mon.contestStats[0] = GetMonData(mon, MON_DATA_COOL, NULL);
        if (old != summary->mon.contestStats[0]) {
            summary->unk7BE |= 1;
        }
        old = summary->mon.contestStats[1];
        summary->mon.contestStats[1] = GetMonData(mon, MON_DATA_BEAUTY, NULL);
        if (old != summary->mon.contestStats[1]) {
            summary->unk7BE |= 2;
        }
        old = summary->mon.contestStats[2];
        summary->mon.contestStats[2] = GetMonData(mon, MON_DATA_CUTE, NULL);
        if (old != summary->mon.contestStats[2]) {
            summary->unk7BE |= 4;
        }
        old = summary->mon.contestStats[3];
        summary->mon.contestStats[3] = GetMonData(mon, MON_DATA_SMART, NULL);
        if (old != summary->mon.contestStats[3]) {
            summary->unk7BE |= 8;
        }
        old = summary->mon.contestStats[4];
        summary->mon.contestStats[4] = GetMonData(mon, MON_DATA_TOUGH, NULL);
        if (old != summary->mon.contestStats[4]) {
            summary->unk7BE |= 0x10;
        }
        summary->mon.contestStats[5] = GetMonData(mon, MON_DATA_SHEEN, NULL);
        if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
            Heap_Free(mon);
        }
        LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_14_OFFSET, HEAP_ID_19);
        LoadUserFrameGfx2(summary->bgConfig, GF_BG_LYR_MAIN_1, 0x3E2, 13, Options_GetFrame(summary->args->options), HEAP_ID_19);
        if (summary->unk7BE == 0) {
            PokemonSummary_PrintConditionChangeMessage(summary, 0xFE);
            return POKEMON_SUMMARY_STATE_WAIT_CONDITION_EXIT;
        }
        PokemonSummary_InitConditionChart(summary);
        PokemonSummary_InitSheenSparkles(summary);
        PokemonSummary_ShowConditionChangeSprites(summary);
        return POKEMON_SUMMARY_STATE_SHOW_CONDITION_CHANGES;
    }
    return POKEMON_SUMMARY_STATE_UPDATE_CONDITION;
}

// State 17: on A or B, show the next changed condition stat.
static enum PokemonSummaryState PokemonSummary_ShowConditionChanges(PokemonSummary *summary) {
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        u8 changes = summary->unk7BE;
        u8 i;
        for (i = 0; i < 5; i++) {
            u32 mask = 1 << i;
            if (changes & mask) {
                PokemonSummary_PrintConditionChangeMessage(summary, i);
                summary->unk7BE ^= mask;
                if (summary->unk7BE == 0) {
                    return POKEMON_SUMMARY_STATE_WAIT_CONDITION_EXIT;
                }
                break;
            }
        }
    }
    return POKEMON_SUMMARY_STATE_SHOW_CONDITION_CHANGES;
}

// State 18: leave on A or B.
static enum PokemonSummaryState PokemonSummary_WaitConditionExit(PokemonSummary *summary) {
    if (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) {
        return POKEMON_SUMMARY_STATE_START_FADE_OUT;
    }
    return POKEMON_SUMMARY_STATE_WAIT_CONDITION_EXIT;
}

static enum PokemonSummaryState PokemonSummary_StartFadeOut(PokemonSummary *summary) {
    BeginAppScreenFade(1, HEAP_ID_19);
    return POKEMON_SUMMARY_STATE_WAIT_FADE_OUT;
}

static int PokemonSummary_WaitFadeOut(PokemonSummary *summary) {
    return (u8)(IsPaletteFadeFinished() == TRUE);
}

// State 15: flash a touched button (see PokemonSummary_StartButtonFlash), then go to flashNextState.
int PokemonSummary_FlashButton(PokemonSummary *summary) {
    switch (summary->unk7BE) {
    case 0:
        BgTilemapRectChangePalette(summary->bgConfig, summary->flashBgId, summary->flashX, summary->flashY, summary->flashWidth, summary->flashHeight, summary->flashPalette);
        ScheduleBgTilemapBufferTransfer(summary->bgConfig, summary->flashBgId);
        summary->unk7BE++;
        break;
    case 1:
        summary->flashTimer++;
        if (summary->flashTimer == 4) {
            BgTilemapRectChangePalette(summary->bgConfig, summary->flashBgId, summary->flashX, summary->flashY, summary->flashWidth, summary->flashHeight, summary->restorePalette);
            ScheduleBgTilemapBufferTransfer(summary->bgConfig, summary->flashBgId);
            summary->flashTimer = 0;
            summary->unk7BE++;
        }
        break;
    case 2:
        summary->flashTimer++;
        if (summary->flashTimer == 2) {
            summary->unk7BE = 0;
            return summary->flashNextState;
        }
        break;
    }
    return POKEMON_SUMMARY_STATE_FLASH_BUTTON;
}

// State 20: one of the previous/next Pokemon buttons was touched.
static enum PokemonSummaryState PokemonSummary_ChangeMonByButton(PokemonSummary *summary) {
    if (summary->flashY == 5) {
        PokemonSummary_ChangeMon(summary, -1);
    } else {
        PokemonSummary_ChangeMon(summary, 1);
    }
    PokemonSummary_DrawMonButtons(summary);
    return POKEMON_SUMMARY_STATE_SHOW_POKEPIC;
}

static void PokemonSummary_ReadShownMon(PokemonSummary *summary) {
    void *mon = PokemonSummary_GetShownMon(summary);
    if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
        PokemonSummary_ReadBoxMon(summary, mon, &summary->mon);
    } else {
        PokemonSummary_ReadMon(summary, mon, &summary->mon);
    }
}

static void PokemonSummary_ReadBoxMon(PokemonSummary *summary, BoxPokemon *boxMon, PokemonSummaryMon *out) {
    Pokemon *mon = AllocMonZeroed(HEAP_ID_19);
    CopyBoxPokemonToPokemon(boxMon, mon);
    PokemonSummary_ReadMon(summary, mon, out);
    Heap_Free(mon);
}

void PokemonSummary_ReadMon(PokemonSummary *summary, Pokemon *mon, PokemonSummaryMon *out) {
    BOOL decrypted;
    BoxPokemon *boxMon;
    u16 i;

    decrypted = AcquireMonLock(mon);
    out->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    boxMon = Mon_GetBoxMon(mon);

    ReadMsgDataIntoString(summary->msgData, msg_0302_00011, summary->buffer);
    BufferBoxMonSpeciesName(summary->msgFormat, 0, boxMon);
    StringExpandPlaceholders(summary->msgFormat, summary->mon.speciesName, summary->buffer);

    ReadMsgDataIntoString(summary->msgData, msg_0302_00000, summary->buffer);
    BufferBoxMonNickname(summary->msgFormat, 0, boxMon);
    StringExpandPlaceholders(summary->msgFormat, summary->mon.nickname, summary->buffer);

    ReadMsgDataIntoString(summary->msgData, msg_0302_00014, summary->buffer);
    BufferBoxMonOTName(summary->msgFormat, 0, boxMon);
    StringExpandPlaceholders(summary->msgFormat, summary->mon.otName, summary->buffer);

    out->heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    out->level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    out->isEgg = GetMonData(mon, MON_DATA_IS_EGG, NULL);

    if (GetMonData(mon, MON_DATA_NO_PRINT_GENDER, NULL) == TRUE && !out->isEgg) {
        out->noPrintGender = 0;
    } else {
        out->noPrintGender = 1;
    }

    out->gender = GetMonGender(mon);
    out->pokeball = GetMonData(mon, MON_DATA_POKEBALL, NULL);
    out->type1 = GetMonData(mon, MON_DATA_TYPE_1, NULL);
    out->type2 = GetMonData(mon, MON_DATA_TYPE_2, NULL);
    out->otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    out->exp = GetMonData(mon, MON_DATA_EXPERIENCE, NULL);
    out->otGender = GetMonData(mon, MON_DATA_OT_GENDER, NULL);

    out->curLevelExp = GetMonExpBySpeciesAndLevel(out->species, out->level);
    if (out->level == MAX_LEVEL) {
        out->nextLevelExp = out->curLevelExp;
    } else {
        out->nextLevelExp = GetMonExpBySpeciesAndLevel(out->species, out->level + 1);
    }

    out->hp = GetMonData(mon, MON_DATA_HP, NULL);
    out->maxHp = GetMonData(mon, MON_DATA_MAX_HP, NULL);
    out->attack = GetMonData(mon, MON_DATA_ATK, NULL);
    out->defense = GetMonData(mon, MON_DATA_DEF, NULL);
    out->spAttack = GetMonData(mon, MON_DATA_SP_ATK, NULL);
    out->spDefense = GetMonData(mon, MON_DATA_SP_DEF, NULL);
    out->speed = GetMonData(mon, MON_DATA_SPEED, NULL);
    out->ability = GetMonData(mon, MON_DATA_ABILITY, NULL);
    out->nature = GetMonNature(mon);

    for (i = 0; i < MAX_MON_MOVES; i++) {
        u8 ppUps;
        out->moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);
        out->pp[i] = GetMonData(mon, MON_DATA_MOVE1_PP + i, NULL);
        ppUps = GetMonData(mon, MON_DATA_MOVE1_PP_UPS + i, NULL);
        out->maxPP[i] = GetMoveMaxPP(out->moves[i], ppUps);
    }

    out->contestStats[0] = GetMonData(mon, MON_DATA_COOL, NULL);
    out->contestStats[1] = GetMonData(mon, MON_DATA_BEAUTY, NULL);
    out->contestStats[2] = GetMonData(mon, MON_DATA_CUTE, NULL);
    out->contestStats[3] = GetMonData(mon, MON_DATA_SMART, NULL);
    out->contestStats[4] = GetMonData(mon, MON_DATA_TOUGH, NULL);
    out->contestStats[5] = GetMonData(mon, MON_DATA_SHEEN, NULL);
    out->favoriteFlavor = FLAVOR_MAX;
    for (i = 0; i < FLAVOR_MAX; i++) {
        if (MonGetFlavorPreference(mon, i) == 1) {
            out->favoriteFlavor = i;
            break;
        }
    }

    out->markings = GetMonData(mon, MON_DATA_MARKINGS, NULL);
    out->form = GetMonData(mon, MON_DATA_FORM, NULL);
    out->status = Pokemon_GetStatusIconId(mon);
    if (Pokemon_IsImmuneToPokerus(mon) == TRUE) {
        out->pokerus = POKEMON_SUMMARY_POKERUS_CURED;
    } else if (Pokemon_HasPokerus(mon) == TRUE) {
        out->pokerus = POKEMON_SUMMARY_POKERUS_INFECTED;
        if (out->status == PARTY_MON_STATUS_ICON_OK) {
            out->status = PARTY_MON_STATUS_ICON_UNSET;
        }
    } else {
        out->pokerus = POKEMON_SUMMARY_POKERUS_NONE;
    }

    if (MonIsShiny(mon) == TRUE) {
        out->shiny = 1;
    } else {
        out->shiny = 0;
    }

    out->ribbons[0] = 0;
    out->ribbons[1] = 0;
    out->ribbons[2] = 0;
    out->ribbons[3] = 0;
    summary->ribbonCount = 0;
    for (i = 0; i < RIBBON_MAX; i++) {
        if (GetMonData(mon, GetRibbonAttr(i, RIBBONDAT_MONDATNO), NULL) != 0) {
            out->ribbons[i / 32] |= 1 << (i & 31);
            summary->ribbonCount++;
        }
    }

    for (i = 0; i < NELEMS(summary->mon.shinyLeaves); i++) {
        summary->mon.shinyLeaves[i] = GetMonData(mon, MON_DATA_SHINY_LEAF_A + i, NULL);
    }
    ReleaseMonLock(mon, decrypted);
}

static void PokemonSummary_PlayCry(PokemonSummary *summary) {
    u8 delay;
    if (!summary->mon.isEgg) {
        NARC_ReadPokepicCryDelay(summary->pokepicAnimNarc, &delay, summary->mon.species, 1);
        if (summary->mon.species == SPECIES_CHATOT) {
            Chatot_PlayCryWithDelayedFallback((SOUND_CHATOT *)summary->args->chatot, 0, 100, 0, delay);
        } else {
            PlayCryDelayed(summary->mon.species, delay, summary->mon.form);
        }
    }
}

// Shows the first page: the move page when picking a move to forget, else the info page.
static void PokemonSummary_ShowFirstPage(PokemonSummary *summary) {
    switch (summary->args->mode) {
    case POKEMON_SUMMARY_MODE_NORMAL:
    case POKEMON_SUMMARY_MODE_NO_MOVE_SWAP:
        summary->page = POKEMON_SUMMARY_PAGE_INFO;
        break;
    case POKEMON_SUMMARY_MODE_FORGET_MOVE:
        summary->page = POKEMON_SUMMARY_PAGE_STATS;
        break;
    }
    PokemonSummary_HideSprites0To7And21And22(summary);
    PokemonSummary_UpdateTypeSprites(summary);
    PokemonSummary_ShowRibbonSprites(summary);
    PokemonSummary_UpdateMarkingSprites(summary);
    PokemonSummary_InitSheenSparkles(summary);
    PokemonSummary_AddPageWindows(summary);
    PokemonSummary_PrintPage(summary);
    PokemonSummary_LoadPageBgs(summary);
    PokemonSummary_UpdateShinyLeafSprites(summary);
    if (summary->args->mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
        PokemonSummary_InitForgetMove(summary);
        return;
    }
    PokemonSummary_UpdatePartySlotSprite(summary);
    PokemonSummary_SetBoxMonIconPos(summary);
    PokemonSummary_AlternateBoxMonIcon(summary);
}

// Which pages can be shown (args->pageFlags, one bit per page): pages lists them, ended by POKEMON_SUMMARY_PAGE_COUNT.
void PokemonSummary_SetPages(PokemonSummaryArgs *args, const u8 *pages) {
    u8 i;
    args->pageFlags = 0;
    for (i = 0; i < POKEMON_SUMMARY_PAGE_COUNT; i++) {
        u8 page = pages[i];
        if (page == POKEMON_SUMMARY_PAGE_COUNT) {
            break;
        }
        args->pageFlags |= 1 << page;
    }
}

static void PokemonSummary_SetPage(PokemonSummary *summary, int page) {
    if (summary->page == page) {
        return;
    }
    PokemonSummary_RemovePageWindows(summary);
    summary->page = page;
    PokemonSummary_HideSprites0To7And21And22(summary);
    PokemonSummary_UpdateTypeSprites(summary);
    PokemonSummary_UpdatePokeathlonStars(summary);
    PokemonSummary_UpdateShinyLeafSprites(summary);
    PokemonSummary_ShowRibbonSprites(summary);
    PokemonSummary_InitSheenSparkles(summary);
    PokemonSummary_AddPageWindows(summary);
    FillBgTilemapRect(summary->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, 3, 18, 20, 0);
    BgCommitTilemapBufferToVram(summary->bgConfig, GF_BG_LYR_MAIN_1);
    FillBgTilemapRect(summary->bgConfig, GF_BG_LYR_SUB_0, 0, 0, 3, 18, 20, 0);
    BgCommitTilemapBufferToVram(summary->bgConfig, GF_BG_LYR_SUB_0);
    PokemonSummary_PrintPage(summary);
    PokemonSummary_LoadPageBgs(summary);
    if (summary->args->mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
        PokemonSummary_UpdateForgetMovePage(summary);
    }
}

static void PokemonSummary_ChangePage(PokemonSummary *summary, int page) {
    PlaySE(SEQ_SE_DP_SELECT5);
    PokemonSummary_SetPage(summary, (u8)page);
}

// Left/right: the next shown page in that direction (eggs have only the first page).
static void PokemonSummary_ScrollPage(PokemonSummary *summary, int direction) {
    s8 page = summary->page;
    if (summary->mon.isEgg) {
        return;
    }
    u8 pages = summary->args->pageFlags;
    do {
        page += direction;
        if (page < 0) {
            page = POKEMON_SUMMARY_PAGE_RIBBONS;
        } else if (page > POKEMON_SUMMARY_PAGE_RIBBONS) {
            page = POKEMON_SUMMARY_PAGE_INFO;
        }
    } while ((pages & (1 << page)) == 0);
    if (page != summary->page) {
        PokemonSummary_ChangePage(summary, page);
    }
}

static BOOL PokemonSummary_HasPage(PokemonSummary *summary, int page) {
    return (summary->args->pageFlags & (1 << page)) != 0;
}

// State 2's touch input: the page tabs (0-2), the cancel button (3) and the party icons (4-9).
static enum PokemonSummaryState PokemonSummary_HandleTouchInput(PokemonSummary *arg) {
    PokemonSummary *summary = arg;
    u8 button = PokemonSummary_CheckTouchedButton(summary);
    if (button == 0xFF) {
        return POKEMON_SUMMARY_STATE_INPUT;
    }
    switch (button) {
    case 0:
        if (PokemonSummary_HasPage(summary, button)) {
            PokemonSummary_ChangePage(summary, (s8)button);
        }
        break;
    case 1:
    case 2:
        if (!summary->mon.isEgg && PokemonSummary_HasPage(summary, button)) {
            PokemonSummary_ChangePage(summary, (s8)button);
        }
        break;
    case 3:
        PokemonSummary_SetMenuInputState(summary, 1);
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        return PokemonSummary_FlashCancelButton(summary, POKEMON_SUMMARY_STATE_START_FADE_OUT);
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9: {
        int slot = button - 4;
        if (summary->args->partySlot != slot && PokemonSummary_CanShowMonAt(summary, slot)) {
            PokemonSummary_ShowMon(summary, slot);
            return POKEMON_SUMMARY_STATE_SHOW_POKEPIC;
        }
    } break;
    }
    return POKEMON_SUMMARY_STATE_INPUT;
}

static void PokemonSummary_LoadBgScreen(PokemonSummary *summary, BgConfig *bgConfig, int member, int bgId) {
    NNSG2dScreenData *screen;
    void *file = AllocAndReadWholeNarcMemberByIdPair(NARC_a_1_6_2, member, HEAP_ID_19);
    NNS_G2dGetUnpackedScreenData(file, &screen);
    LoadRectToBgTilemapRect(summary->bgConfig, bgId, screen->rawData, 0, 0, 32, 32);
    ScheduleBgTilemapBufferTransfer(bgConfig, bgId);
    Heap_Free(file);
}

// The current page's backgrounds (gPokemonSummaryPageScreens[page]: main, sub, sub when picking a move to forget
// or for an egg), the previous/next Pokemon buttons and the HP or EXP bar.
static void PokemonSummary_LoadPageBgs(PokemonSummary *summary) {
    if (!summary->args->isFlag982Set && summary->page == POKEMON_SUMMARY_PAGE_RIBBONS) {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, 11, GF_BG_LYR_MAIN_3);
    } else {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, gPokemonSummaryPageScreens[summary->page][0], GF_BG_LYR_MAIN_3);
    }
    if (summary->args->mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, gPokemonSummaryPageScreens[summary->page][2], GF_BG_LYR_SUB_2);
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 128);
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 0);
        if (summary->args->moveToLearn == MOVE_NONE) {
            PokemonSummary_ClearForgetButton(summary);
        }
    } else if (summary->mon.isEgg) {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, gPokemonSummaryPageScreens[summary->page][2], GF_BG_LYR_SUB_2);
    } else if (PokemonSummary_HasPage(summary, 2)) {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, gPokemonSummaryPageScreens[summary->page][1], GF_BG_LYR_SUB_2);
    } else if (summary->page == POKEMON_SUMMARY_PAGE_INFO) {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, 77, GF_BG_LYR_SUB_2);
    } else {
        PokemonSummary_LoadBgScreen(summary, summary->bgConfig, 78, GF_BG_LYR_SUB_2);
    }
    if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
        BgCellManager_DrawCellAt(summary->cellManager, 4, 20, 4);
        PokemonSummary_DrawMonButtons(summary);
    }
    if (!summary->mon.isEgg) {
        if (summary->page == POKEMON_SUMMARY_PAGE_INFO) {
            PokemonSummary_DrawExpBar(summary);
        } else if (summary->page == POKEMON_SUMMARY_PAGE_STATS) {
            PokemonSummary_DrawHpBar(summary);
        }
    }
}

static void PokemonSummary_DrawHpBar(PokemonSummary *summary) {
    u16 tileBase;
    u32 pixels;
    u8 i;
    u16 fullTile;

    switch (CalculateHpBarColor(summary->mon.hp, summary->mon.maxHp, 48)) {
    case 0:
    case 3:
    case 4:
        tileBase = 0xF097;
        break;
    case 2:
        tileBase = 0xF0B7;
        break;
    case 1:
        tileBase = 0xF0D7;
        break;
    }
    pixels = CalculateHpBarPixelsLength(summary->mon.hp, summary->mon.maxHp, 48);
    i = 0;
    fullTile = tileBase + 8;
    do {
        u16 tile = pixels >= 8 ? fullTile : (u16)(tileBase + pixels);
        FillBgTilemapRect(summary->bgConfig, GF_BG_LYR_MAIN_3, tile, i + 10, 5, 1, 1, TILEMAP_FILL_OVWT_PAL);
        if (pixels < 8) {
            pixels = 0;
        } else {
            pixels = (u8)(pixels - 8);
        }
        i++;
    } while (i < 6);
    ScheduleBgTilemapBufferTransfer(summary->bgConfig, GF_BG_LYR_MAIN_3);
}

static void PokemonSummary_DrawExpBar(PokemonSummary *summary) {
    u32 exp;
    u32 levelExp;
    u32 pixels;
    u8 i;

    if (summary->mon.level < MAX_LEVEL) {
        u32 start = summary->mon.curLevelExp;
        levelExp = summary->mon.nextLevelExp - start;
        exp = summary->mon.exp - start;
    } else {
        levelExp = 0;
        exp = 0;
    }
    pixels = CalculateHpBarPixelsLength(exp, levelExp, 56);
    for (i = 0; i < 7; i++) {
        u32 tile = pixels >= 8 ? 0xE03F : (u16)(0xE037 + pixels);
        FillBgTilemapRect_U32(summary->bgConfig, GF_BG_LYR_SUB_2, tile, i + 9, 19, 1, 1, 17);
        if (pixels < 8) {
            pixels = 0;
        } else {
            pixels = (u8)(pixels - 8);
        }
    }
    ScheduleBgTilemapBufferTransfer(summary->bgConfig, GF_BG_LYR_SUB_2);
}

static void PokemonSummary_ShowMon(PokemonSummary *summary, u8 slot) {
    summary->args->partySlot = slot;
    PokemonSummary_ReadShownMon(summary);
    PokemonSummary_PlayCry(summary);
    PokemonSummary_PrintNickname(summary);
    PokemonSummary_PrintLevel(summary);
    PokemonSummary_PrintHeldItem(summary);
    PokemonSummary_LoadPageBgs(summary);
    PokemonSummary_ReloadPokepic(summary);
    PokemonSummary_HideSprites0To7And21And22(summary);
    PokemonSummary_SetMonTypeSprites(summary);
    PokemonSummary_UpdateTypeSprites(summary);
    PokemonSummary_UpdatePokeathlonStars(summary);
    PokemonSummary_UpdateShinyLeafSprites(summary);
    PokemonSummary_ShowRibbonSprites(summary);
    PokemonSummary_LoadShownMonIcon(summary);
    PokemonSummary_LoadBallSprite(summary);
    PokemonSummary_UpdateStatusSprite(summary);
    PokemonSummary_InitSheenSparkles(summary);
    PokemonSummary_UpdateMarkingSprites(summary);
    PokemonSummary_PrintPage(summary);
    PokemonSummary_UpdatePartySlotSprite(summary);
    PokemonSummary_AlternateBoxMonIcon(summary);
}

static void PokemonSummary_ChangeMon(PokemonSummary *summary, int direction) {
    int slot = PokemonSummary_FindNextMon(summary, direction);
    if (slot != -1) {
        PokemonSummary_ShowMon(summary, slot);
    }
}

// The next Pokemon to show in that direction, or -1.
static int PokemonSummary_FindNextMon(PokemonSummary *summary, int direction) {
    switch (summary->args->monDataType) {
    case POKEMON_SUMMARY_MON_ARRAY:
        return PokemonSummary_FindNextMonInArray(summary, direction);
    case POKEMON_SUMMARY_PARTY:
        return PokemonSummary_FindNextPartyMon(summary, direction);
    case POKEMON_SUMMARY_BOX_MON_ARRAY:
        return PokemonSummary_FindNextBoxMon(summary, direction);
    default:
        return -1;
    }
}

static BOOL PokemonSummary_CanShowMonAt(PokemonSummary *summary, int slot) {
    int size;
    int offset;
    u8 *mons;
    Pokemon *mon;

    switch (summary->args->monDataType) {
    case POKEMON_SUMMARY_MON_ARRAY:
        size = Pokemon_sizeof();
        mons = (u8 *)summary->args->party;
        offset = slot * size;
        if (GetMonData((Pokemon *)(mons + offset), MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (GetMonData((Pokemon *)(mons + offset), MON_DATA_IS_EGG, NULL)) {
                return TRUE;
            }
        }
        break;
    case POKEMON_SUMMARY_PARTY:
        if (slot < summary->args->partyCount) {
            mon = Party_GetMonByIndex(summary->args->party, slot);
            if (GetMonData(mon, MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
                if (GetMonData(mon, MON_DATA_IS_EGG, NULL)) {
                    if (PokemonSummary_CanShowEgg(summary) != TRUE) {
                        break;
                    }
                    return TRUE;
                }
                return TRUE;
            }
        }
        break;
    case POKEMON_SUMMARY_BOX_MON_ARRAY:
        size = BoxPokemon_sizeof();
        mons = (u8 *)summary->args->party;
        offset = slot * size;
        if (GetBoxMonData((BoxPokemon *)(mons + offset), MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (GetBoxMonData((BoxPokemon *)(mons + offset), MON_DATA_IS_EGG, NULL)) {
                return TRUE;
            }
        }
        break;
    }
    return FALSE;
}

static BOOL PokemonSummary_CanShowEgg(PokemonSummary *summary) {
    s8 page;
    if (summary->args->mode == POKEMON_SUMMARY_MODE_CONDITION) {
        return FALSE;
    }
    page = summary->page;
    if (page != POKEMON_SUMMARY_PAGE_INFO && page != POKEMON_SUMMARY_PAGE_CONDITION) {
        return FALSE;
    }
    return TRUE;
}

static int PokemonSummary_FindNextMonInArray(PokemonSummary *summary, int direction) {
    s8 slot = summary->args->partySlot;
    int size;
    u8 *mons;
    while (TRUE) {
        slot += direction;
        if (slot < 0 || slot >= summary->args->partyCount) {
            return -1;
        }
        size = Pokemon_sizeof();
        mons = (u8 *)summary->args->party;
        if (GetMonData((Pokemon *)(mons + slot * size), MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (!GetMonData((Pokemon *)(mons + slot * size), MON_DATA_IS_EGG, NULL) || PokemonSummary_CanShowEgg(summary) == TRUE) {
                return slot;
            }
        }
    }
}

static int PokemonSummary_FindNextPartyMon(PokemonSummary *summary, int direction) {
    s8 slot = summary->args->partySlot;
    Pokemon *mon;
    while (TRUE) {
        slot += direction;
        if (slot < 0 || slot >= summary->args->partyCount) {
            return -1;
        }
        mon = Party_GetMonByIndex(summary->args->party, slot);
        if (GetMonData(mon, MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (!GetMonData(mon, MON_DATA_IS_EGG, NULL) || PokemonSummary_CanShowEgg(summary) == TRUE) {
                return slot;
            }
        }
    }
}

static int PokemonSummary_FindNextBoxMon(PokemonSummary *summary, int direction) {
    s8 slot = summary->args->partySlot;
    int size;
    u8 *mons;
    while (TRUE) {
        slot += direction;
        if (slot < 0 || slot >= summary->args->partyCount) {
            return -1;
        }
        size = BoxPokemon_sizeof();
        mons = (u8 *)summary->args->party;
        if (GetBoxMonData((BoxPokemon *)(mons + slot * size), MON_DATA_SPECIES, NULL) != SPECIES_NONE) {
            if (!GetBoxMonData((BoxPokemon *)(mons + slot * size), MON_DATA_IS_EGG, NULL) || PokemonSummary_CanShowEgg(summary) == TRUE) {
                return slot;
            }
        }
    }
}

void *PokemonSummary_GetShownMon(PokemonSummary *summary) {
    PokemonSummaryArgs *args = summary->args;
    switch (args->monDataType) {
    case POKEMON_SUMMARY_MON_ARRAY:
        return (u8 *)args->party + args->partySlot * Pokemon_sizeof();
    case POKEMON_SUMMARY_PARTY:
        return Party_GetMonByIndex(args->party, args->partySlot);
    case POKEMON_SUMMARY_BOX_MON_ARRAY:
        return (u8 *)args->party + args->partySlot * BoxPokemon_sizeof();
    default:
        return NULL;
    }
}

// Slides the move info panel (sub BG 1) in; TRUE when done.
static BOOL PokemonSummary_SlideInMoveInfo(PokemonSummary *summary) {
    switch (summary->unk7BE) {
    case 0:
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], FALSE);
        Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 0);
        ClearWindowTilemapAndScheduleTransfer(&summary->windows[4]);
        summary->unk7BE = 1;
        break;
    case 1:
        if (Bg_GetXpos(summary->bgConfig, GF_BG_LYR_SUB_1) >= 128) {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 128);
            summary->unk7BE = 2;
        } else {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_ADD_X, 64);
        }
        break;
    case 2:
        PokemonSummary_PrintMoveToLearn(summary);
        PokemonSummary_ShowSelectedMoveInfo(summary);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], TRUE);
        PokemonSummary_ShowMonIconSprite(summary);
        if (summary->mon.type1 != summary->mon.type2) {
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], TRUE);
        }
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], TRUE);
        summary->unk7BE = 0;
        return TRUE;
    }
    return FALSE;
}

// Slides it out again; TRUE when done.
static BOOL PokemonSummary_SlideOutMoveInfo(PokemonSummary *summary) {
    switch (summary->unk7BE) {
    case 0:
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], FALSE);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], FALSE);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], FALSE);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MON_ICON], FALSE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], FALSE);
        PokemonSummary_ScheduleMainBg1Transfer(summary);
        PokemonSummary_ClearMoveInfo(summary);
        summary->unk7BE = 1;
        break;
    case 1:
        if (Bg_GetXpos(summary->bgConfig, GF_BG_LYR_SUB_1) <= 128) {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 0);
            summary->unk7BE = 2;
        } else {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SUB_X, 64);
        }
        break;
    case 2:
        ScheduleWindowCopyToVram(&summary->windows[32]);
        ScheduleWindowCopyToVram(&summary->windows[6]);
        ScheduleWindowCopyToVram(&summary->windows[31]);
        ScheduleWindowCopyToVram(&summary->windows[4]);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], TRUE);
        PokemonSummary_UpdatePartySlotSprite(summary);
        summary->unk7BE = 0;
        return TRUE;
    }
    return FALSE;
}

// Moves the move cursor up or down, skipping empty slots; the move to learn only when picking a move to
// forget. TRUE if it moved.
static BOOL PokemonSummary_MoveMoveCursor(PokemonSummary *summary, int direction) {
    u8 old = summary->moveSlot;
    s8 slot = old;
    s8 max;
    if (summary->args->mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
        if (summary->args->moveToLearn) {
            max = POKEMON_SUMMARY_MOVE_SLOT_NEW;
        } else {
            max = MAX_MON_MOVES - 1;
        }
    } else {
        max = MAX_MON_MOVES - 1;
    }
    do {
        slot += direction;
        if (slot < 0) {
            slot = max;
        } else if (slot > max) {
            slot = 0;
        }
        if (slot == POKEMON_SUMMARY_MOVE_SLOT_NEW) {
            break;
        }
        if (summary->mon.moves[slot] != MOVE_NONE) {
            break;
        }
    } while (slot != old);
    if (slot != old) {
        summary->moveSlot = slot;
        return TRUE;
    }
    return FALSE;
}

static void PokemonSummary_ShowSelectedMoveInfo(PokemonSummary *summary) {
    u32 slot;
    PokemonSummary_UpdateMoveCursorSprite(summary);
    slot = summary->moveSlot;
    if (slot == POKEMON_SUMMARY_MOVE_SLOT_NEW) {
        u16 move = summary->args->moveToLearn;
        if (move != MOVE_NONE) {
            PokemonSummary_ShowMoveInfo(summary, move);
        } else {
            PokemonSummary_ShowMoveInfo(summary, -1);
        }
    } else if (slot == POKEMON_SUMMARY_MOVE_SLOT_CANCEL) {
        PokemonSummary_ShowMoveInfo(summary, -1);
    } else {
        PokemonSummary_ShowMoveInfo(summary, summary->mon.moves[slot]);
    }
}

#define PokemonSummary_PrintMoveInfo_Int(summary, move)         ((void (*)(PokemonSummary *, int))PokemonSummary_PrintMoveInfo)(summary, move)
#define PokemonSummary_SetMoveCategorySprite_Int(summary, move) ((void (*)(PokemonSummary *, int))PokemonSummary_SetMoveCategorySprite)(summary, move)

// -1: clear it.
static void PokemonSummary_ShowMoveInfo(PokemonSummary *summary, int move) {
    if (move == -1) {
        PokemonSummary_ClearMoveInfo(summary);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], FALSE);
        return;
    }
    PokemonSummary_PrintMoveInfo_Int(summary, move);
    PokemonSummary_SetMoveCategorySprite_Int(summary, move);
    thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], TRUE);
}

static void PokemonSummary_SwapMoves(PokemonSummary *summary) {
    void *mon = PokemonSummary_GetShownMon(summary);
    u16 move;
    u8 value;
    if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
        BoxMonSwapMoves(mon, summary->moveSlot, summary->swapMoveSlot);
    } else {
        MonSwapMoves(mon, summary->moveSlot, summary->swapMoveSlot);
    }
    move = summary->mon.moves[summary->moveSlot];
    summary->mon.moves[summary->moveSlot] = summary->mon.moves[summary->swapMoveSlot];
    summary->mon.moves[summary->swapMoveSlot] = move;
    value = summary->mon.pp[summary->moveSlot];
    summary->mon.pp[summary->moveSlot] = summary->mon.pp[summary->swapMoveSlot];
    summary->mon.pp[summary->swapMoveSlot] = value;
    value = summary->mon.maxPP[summary->moveSlot];
    summary->mon.maxPP[summary->moveSlot] = summary->mon.maxPP[summary->swapMoveSlot];
    summary->mon.maxPP[summary->swapMoveSlot] = value;
    *(u32 *)summary->args->monModified = 1;
}

// Picking a move to forget: the move page with the move to learn.
static void PokemonSummary_InitForgetMove(PokemonSummary *summary) {
    ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_X, 0);
    PokemonSummary_PrintMoveToLearn(summary);
    PokemonSummary_ShowSelectedMoveInfo(summary);
    thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], TRUE);
    PokemonSummary_ShowMonIconSprite(summary);
    if (summary->mon.type1 != summary->mon.type2) {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], TRUE);
    }
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], TRUE);
}

static void PokemonSummary_UpdateForgetMovePage(PokemonSummary *summary) {
    PokemonSummary_PrintMoveToLearn(summary);
    PokemonSummary_ShowSelectedMoveInfo(summary);
    PokemonSummary_ShowMonIconSprite(summary);
    if (summary->page == POKEMON_SUMMARY_PAGE_STATS) {
        PokemonSummary_HideConditionSprites(summary);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], TRUE);
        if (summary->mon.type1 != summary->mon.type2) {
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], TRUE);
        }
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 0);
    } else {
        PokemonSummary_ShowConditionSprites(summary);
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_MAIN_2, BG_POS_OP_SET_Y, 256);
    }
}

// Slides the ribbon list (sub BG 1) in; TRUE when done.
static BOOL PokemonSummary_SlideInRibbonList(PokemonSummary *summary) {
    switch (summary->unk7BE) {
    case 0:
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_X, 0);
        ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 0);
        Sprite_SetPriority(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 3);
        thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
        ClearWindowTilemapAndScheduleTransfer(&summary->windows[29]);
        ClearWindowTilemapAndScheduleTransfer(&summary->windows[23]);
        ClearWindowTilemapAndScheduleTransfer(summary->pageWindows);
        summary->ribbonRow = 0;
        summary->unk7BE = 1;
        break;
    case 1:
        if (Bg_GetYpos(summary->bgConfig, GF_BG_LYR_SUB_1) >= 72) {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 72);
            summary->unk7BE = 2;
        } else {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_ADD_Y, 36);
        }
        break;
    case 2:
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_CURSOR], TRUE);
        Sprite_SetDrawFlag(summary->sprites[66], TRUE);
        PokemonSummary_MoveRibbonCursor(summary, 0);
        summary->unk7BE = 0;
        return TRUE;
    }
    return FALSE;
}

// Slides it out again; TRUE when done.
static BOOL PokemonSummary_SlideOutRibbonList(PokemonSummary *summary) {
    switch (summary->unk7BE) {
    case 0:
        summary->ribbonCursor = 0;
        summary->ribbonRow = 0;
        ClearWindowTilemapAndScheduleTransfer(&summary->pageWindows[1]);
        ClearWindowTilemapAndScheduleTransfer(&summary->pageWindows[2]);
        PokemonSummary_ShowRibbonSprites(summary);
        summary->unk7BE = 1;
        break;
    case 1:
        if (Bg_GetYpos(summary->bgConfig, GF_BG_LYR_SUB_1) <= 0) {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SET_Y, 0);
            summary->unk7BE = 2;
        } else {
            ScheduleSetBgPosText(summary->bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_SUB_Y, 36);
        }
        break;
    case 2:
        ScheduleWindowCopyToVram(&summary->windows[29]);
        ScheduleWindowCopyToVram(&summary->windows[23]);
        ScheduleWindowCopyToVram(summary->pageWindows);
        Sprite_SetPriority(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
        thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 2);
        summary->unk7BE = 0;
        return TRUE;
    }
    return FALSE;
}

// Moves the ribbon cursor in the grid: +-1 left/right, +-a row up/down (turning the page at the edges), +-a page.
static void PokemonSummary_MoveRibbonCursor(PokemonSummary *summary, int direction) {
    u8 cursor = summary->ribbonCursor, row = summary->ribbonRow;
    if (direction == 1) {
        if (cursor % POKEMON_SUMMARY_RIBBON_COLUMNS == POKEMON_SUMMARY_RIBBON_COLUMNS - 1) {
            return;
        }
        summary->ribbonCursor++;
    } else if (direction == -1) {
        if (cursor % POKEMON_SUMMARY_RIBBON_COLUMNS == 0) {
            return;
        }
        summary->ribbonCursor--;
    } else if (direction == POKEMON_SUMMARY_RIBBON_COLUMNS) {
        if (cursor >= POKEMON_SUMMARY_RIBBONS_PER_PAGE - POKEMON_SUMMARY_RIBBON_COLUMNS) {
            if ((row + 1) * POKEMON_SUMMARY_RIBBONS_PER_PAGE < summary->ribbonCount) {
                summary->ribbonRow++;
                summary->ribbonCursor = summary->ribbonCursor % POKEMON_SUMMARY_RIBBON_COLUMNS;
            }
        } else {
            summary->ribbonCursor = cursor + POKEMON_SUMMARY_RIBBON_COLUMNS;
        }
    } else if (direction == -POKEMON_SUMMARY_RIBBON_COLUMNS) {
        if (cursor <= POKEMON_SUMMARY_RIBBON_COLUMNS - 1) {
            if (row != 0) {
                summary->ribbonRow--;
                summary->ribbonCursor = summary->ribbonCursor % POKEMON_SUMMARY_RIBBON_COLUMNS + POKEMON_SUMMARY_RIBBONS_PER_PAGE - POKEMON_SUMMARY_RIBBON_COLUMNS;
            }
        } else {
            summary->ribbonCursor = cursor - POKEMON_SUMMARY_RIBBON_COLUMNS;
        }
    } else if (direction == POKEMON_SUMMARY_RIBBONS_PER_PAGE) {
        if ((row + 1) * POKEMON_SUMMARY_RIBBONS_PER_PAGE < summary->ribbonCount) {
            summary->ribbonRow++;
        }
    } else if (direction == -POKEMON_SUMMARY_RIBBONS_PER_PAGE) {
        if (row != 0) {
            summary->ribbonRow--;
        }
    }
    if ((cursor != summary->ribbonCursor || row != summary->ribbonRow) && direction != POKEMON_SUMMARY_RIBBONS_PER_PAGE && direction != -POKEMON_SUMMARY_RIBBONS_PER_PAGE) {
        PlaySE(SEQ_SE_DP_SELECT);
    }
    summary->ribbonId = PokemonSummary_GetRibbonAt(summary, summary->ribbonCursor);
    PokemonSummary_UpdateRibbonCursorSprite(summary);
    if (row != summary->ribbonRow) {
        PokemonSummary_UpdateRibbonSprites(summary);
    }
    PokemonSummary_PrintRibbonInfo(summary);
    if (summary->ribbonRow != 0) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_UP], TRUE);
    } else {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_UP], FALSE);
    }
    if ((summary->ribbonRow + 1) * POKEMON_SUMMARY_RIBBONS_PER_PAGE < summary->ribbonCount) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_DOWN], TRUE);
    } else {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_DOWN], FALSE);
    }
}

// The ribbon in that grid cell of the current page: the cell-th ribbon the Pokemon has, counted from the page start.
static u8 PokemonSummary_GetRibbonAt(PokemonSummary *summary, u8 cell) {
    u16 i;
    u8 target;
    u8 found;
    found = 0;
    i = found;
    target = summary->ribbonRow * POKEMON_SUMMARY_RIBBONS_PER_PAGE + cell;
    for (; i < RIBBON_MAX; i++) {
        if ((summary->mon.ribbons[(u32)i >> 5] & (1 << (i & 31))) != 0) {
            if (target == found) {
                return i;
            }
            found++;
        }
    }
    return 0;
}

void PokemonSummaryArgs_SetPlayer(PokemonSummaryArgs *args, PlayerProfile *profile) {
    args->playerName = PlayerProfile_GetNamePtr(profile);
    args->playerId = PlayerProfile_GetTrainerID(profile);
    args->playerGender = PlayerProfile_GetTrainerGender(profile);
}

int StatusIcon_GetCharNaix(void) {
    return 64;
}

int StatusIcon_GetPlttNaix(void) {
    return 65;
}

int StatusIcon_GetCellNaix(void) {
    return 63;
}

int StatusIcon_GetAnimNaix(void) {
    return 62;
}

PartyMonStatusIconId Pokemon_GetStatusIconId(Pokemon *mon) {
    u32 status = GetMonData(mon, MON_DATA_STATUS, NULL);
    if (GetMonData(mon, MON_DATA_HP, NULL) == 0) {
        return PARTY_MON_STATUS_ICON_FNT;
    }
    if (status & (MON_STATUS_PSN_MASK | MON_STATUS_TOX_MASK)) {
        return PARTY_MON_STATUS_ICON_PSN;
    }
    if (status & MON_STATUS_SLP_MASK) {
        return PARTY_MON_STATUS_ICON_SLP;
    }
    if (status & MON_STATUS_BRN_MASK) {
        return PARTY_MON_STATUS_ICON_BRN;
    }
    if (status & MON_STATUS_FRZ_MASK) {
        return PARTY_MON_STATUS_ICON_FRZ;
    }
    if (status & MON_STATUS_PRZ_MASK) {
        return PARTY_MON_STATUS_ICON_PRZ;
    }
    return PARTY_MON_STATUS_ICON_OK;
}

static void PokemonSummary_SetMenuInputState(PokemonSummary *summary, int state) {
    PokemonSummaryArgs *args = summary->args;
    MenuInputStateMgr *mgr = args->menuInputStatePtr;
    if (mgr != NULL) {
        MenuInputStateMgr_SetState(mgr, (MenuInputState)state);
    }
}

// The touched move (0-3) or -1.
static int PokemonSummary_GetTouchedMove(PokemonSummary *summary) {
    return TouchscreenHitbox_FindRectAtTouchNew(gPokemonSummaryMoveHitboxes);
}

// Picking the move to swap with: a move (0-3), cancel (4) or -1.
static int PokemonSummary_GetMoveSwapTouch(PokemonSummary *summary) {
    int ret = TouchscreenHitbox_FindRectAtTouchNew(gPokemonSummaryMoveHitboxes);
    if (ret != -1) {
        return ret;
    }
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummaryCancelButtonHitbox) == TRUE) {
        return 4;
    }
    return -1;
}

// The move list: a move (0-3), swap (4), cancel (5) or -1.
static int PokemonSummary_GetMoveSelectTouch(PokemonSummary *summary) {
    int ret = TouchscreenHitbox_FindRectAtTouchNew(gPokemonSummaryMoveHitboxes);
    if (ret != -1) {
        return ret;
    }
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummarySwapButtonHitbox) == TRUE) {
        return 4;
    }
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummaryCancelButtonHitbox) == TRUE) {
        return 5;
    }
    return -1;
}

// Picking a move to forget: a move (0-3), the move to learn, cancel or -1.
static int PokemonSummary_GetForgetMoveTouch(PokemonSummary *summary) {
    int ret = TouchscreenHitbox_FindRectAtTouchNew(gPokemonSummaryMoveHitboxes);
    if (ret != -1) {
        return ret;
    }
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummaryConfirmButtonHitbox) == TRUE) {
        return POKEMON_SUMMARY_MOVE_SLOT_NEW;
    }
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummaryCancelButtonHitbox) == TRUE) {
        return POKEMON_SUMMARY_MOVE_SLOT_CANCEL;
    }
    return -1;
}

// Confirming the move to forget: yes (0), cancel (1) or -1.
static int PokemonSummary_GetForgetConfirmTouch(PokemonSummary *summary) {
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummaryConfirmButtonHitbox) == TRUE) {
        return 0;
    }
    if (TouchscreenHitbox_TouchNewIsIn(gPokemonSummaryCancelButtonHitbox) == TRUE) {
        return 1;
    }
    return -1;
}

// The previous (0) or next (1) Pokemon button, or -1.
static int PokemonSummary_GetMonButtonTouch(PokemonSummary *summary) {
    return TouchscreenHitbox_FindRectAtTouchNew(gPokemonSummaryMonButtonHitboxes);
}

// The ribbon list: a ribbon cell (0-8), page up (9), page down (10), cancel (11) or -1.
static int PokemonSummary_GetRibbonTouch(PokemonSummary *summary) {
    return TouchscreenHitbox_FindRectAtTouchNew(gPokemonSummaryRibbonHitboxes);
}

// State 8: the move to forget was picked; ask to confirm.
static enum PokemonSummaryState PokemonSummary_ShowForgetConfirm(PokemonSummary *summary) {
    Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 1);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], TRUE);
    PokemonSummary_ResetSwapCursorSprite(summary);
    PokemonSummary_DrawForgetConfirm(summary, TRUE);
    return POKEMON_SUMMARY_STATE_FORGET_MOVE_CONFIRM_INPUT;
}

static void PokemonSummary_DrawForgetConfirm(PokemonSummary *summary, BOOL show) {
    if (show == TRUE) {
        BgCellManager_DrawCellAt(summary->cellManager, 0, 0, 18);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TO_LEARN_TYPE], FALSE);
        PokemonSummary_ShowForgetLabel(summary, TRUE);
        return;
    }
    if (summary->args->moveToLearn != MOVE_NONE) {
        BgCellManager_DrawCellAt(summary->cellManager, 1, 0, 18);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TO_LEARN_TYPE], TRUE);
    } else {
        PokemonSummary_ClearForgetButton(summary);
    }
    PokemonSummary_ShowForgetLabel(summary, FALSE);
}

static void PokemonSummary_ClearForgetButton(PokemonSummary *summary) {
    FillBgTilemapRect(summary->bgConfig, GF_BG_LYR_SUB_2, 0x3006, 0, 18, 17, 6, TILEMAP_FILL_OVWT_PAL);
    ScheduleBgTilemapBufferTransfer(summary->bgConfig, GF_BG_LYR_SUB_2);
}

static void PokemonSummary_DrawSwitchButton(PokemonSummary *summary, BOOL show) {
    if (summary->args->mode == POKEMON_SUMMARY_MODE_NO_MOVE_SWAP) {
        return;
    }
    if (show == TRUE) {
        BgCellManager_DrawCellAt(summary->cellManager, 2, 1, 16);
        PokemonSummary_ShowSwitchLabel(summary, TRUE);
        return;
    }
    BgCellManager_DrawCellAt(summary->cellManager, 3, 1, 16);
    PokemonSummary_ShowSwitchLabel(summary, FALSE);
}

// Starts flashing a touched button (a tilemap rect of bgId, palette then restorePalette) for PokemonSummary_FlashButton,
// which then goes to nextState. Returns that state (15).
static enum PokemonSummaryState PokemonSummary_StartButtonFlash(PokemonSummary *summary, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 palette, u8 restorePalette, u8 nextState) {
    summary->flashX = x;
    summary->flashY = y;
    summary->flashWidth = width;
    summary->flashHeight = height;
    summary->flashPalette = palette;
    summary->restorePalette = restorePalette;
    summary->flashBgId = bgId;
    summary->flashTimer = 0;
    summary->flashNextState = nextState;
    return POKEMON_SUMMARY_STATE_FLASH_BUTTON;
}

static enum PokemonSummaryState PokemonSummary_FlashCancelButton(PokemonSummary *summary, u8 nextState) {
    return PokemonSummary_StartButtonFlash(summary, GF_BG_LYR_SUB_2, 23, 20, 9, 4, 1, 0, nextState);
}

static enum PokemonSummaryState PokemonSummary_FlashConfirmButton(PokemonSummary *summary, u8 nextState) {
    return PokemonSummary_StartButtonFlash(summary, GF_BG_LYR_SUB_2, 1, 19, 15, 4, 1, 0, nextState);
}

static enum PokemonSummaryState PokemonSummary_FlashSwapButton(PokemonSummary *summary, u8 nextState) {
    return PokemonSummary_StartButtonFlash(summary, GF_BG_LYR_SUB_2, 1, 17, 10, 2, 1, 0, nextState);
}

// 0: the previous Pokemon button, else the next one.
static enum PokemonSummaryState PokemonSummary_FlashMonButton(PokemonSummary *summary, int which, u8 nextState) {
    if (which == 0) {
        return PokemonSummary_StartButtonFlash(summary, GF_BG_LYR_SUB_2, 24, 5, 6, 3, 1, 0, nextState);
    } else {
        return PokemonSummary_StartButtonFlash(summary, GF_BG_LYR_SUB_2, 24, 13, 6, 3, 1, 0, nextState);
    }
}

static enum PokemonSummaryState PokemonSummary_FlashRibbonCancelButton(PokemonSummary *summary, u8 nextState) {
    return PokemonSummary_StartButtonFlash(summary, GF_BG_LYR_SUB_1, 26, 29, 6, 4, 1, 0, nextState);
}

// The previous/next Pokemon buttons, blanked when there is no Pokemon that way.
static void PokemonSummary_DrawMonButtons(PokemonSummary *summary) {
    if (PokemonSummary_FindNextMon(summary, -1) != -1) {
        BgCellManager_DrawCellAt(summary->cellManager, 5, 24, 5);
    } else {
        FillBgTilemapRect(summary->bgConfig, GF_BG_LYR_SUB_2, 1, 24, 5, 6, 3, TILEMAP_FILL_KEEP_PAL);
        ScheduleBgTilemapBufferTransfer(summary->bgConfig, GF_BG_LYR_SUB_2);
    }

    if (PokemonSummary_FindNextMon(summary, 1) != -1) {
        BgCellManager_DrawCellAt(summary->cellManager, 6, 24, 13);
    } else {
        FillBgTilemapRect(summary->bgConfig, GF_BG_LYR_SUB_2, 1, 24, 13, 6, 3, TILEMAP_FILL_KEEP_PAL);
        ScheduleBgTilemapBufferTransfer(summary->bgConfig, GF_BG_LYR_SUB_2);
    }
}

static void PokemonSummary_InitSpriteSystem(PokemonSummary *summary) {
    OamManagerParam oamManagerParam;
    OamCharTransferParam oamTransferParam;
    ResdatIdList resdatIds;

    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GF_CreateVramTransferManager(32, HEAP_ID_19);
    summary->spriteSystem = SpriteSystem_Alloc(HEAP_ID_19);
    summary->spriteManager = SpriteManager_New(summary->spriteSystem);
    oamManagerParam = sPokemonSummaryOamManagerParam;
    oamTransferParam = sPokemonSummaryOamTransferParam;
    SpriteSystem_Init(summary->spriteSystem, &oamManagerParam, &oamTransferParam, 32);
    SpriteSystem_InitSprites(summary->spriteSystem, summary->spriteManager, POKEMON_SUMMARY_SPRITE_COUNT);
    resdatIds = sPokemonSummarySpriteResdatIds;
    SpriteSystem_LoadResourceDataFromFileIdList(summary->spriteSystem, summary->spriteManager, &resdatIds);
}

static void PokemonSummary_FreeSpriteSystem(PokemonSummary *summary) {
    SpriteSystem_DestroySpriteManager(summary->spriteSystem, summary->spriteManager);
    SpriteSystem_Free(summary->spriteSystem);
}

static void PokemonSummary_UpdateSpriteAnims(PokemonSummary *summary) {
    Sprite_UpdateAnim(summary->sprites[21], FX32_ONE);
    Sprite_UpdateAnim(summary->sprites[22], FX32_ONE);
    Sprite_UpdateAnim(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_UP], FX32_ONE);
    Sprite_UpdateAnim(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_PAGE_DOWN], FX32_ONE);
}

static void PokemonSummary_CreateSprites(PokemonSummary *summary) {
    for (u16 i = 0; i < POKEMON_SUMMARY_SPRITE_COUNT; i++) {
        summary->sprites[i] = SpriteSystem_CreateSpriteFromResourceHeader(summary->spriteSystem, summary->spriteManager, &sPokemonSummarySpriteTemplates[i]);
    }
    PokemonSummary_LoadTypeAndIconSprites(summary);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CHANGES], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CHANGES + 1], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CHANGES + 2], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CHANGES + 3], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CHANGES + 4], FALSE);
    Sprite_SetDrawFlag(summary->sprites[46], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_COOL], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_BEAUTY], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CUTE], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_SMART], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_TOUGH], FALSE);
    Sprite_SetDrawFlag(summary->sprites[67], FALSE);
    Sprite_SetDrawFlag(summary->sprites[68], FALSE);
    Sprite_SetDrawFlag(summary->sprites[69], FALSE);
    Sprite_SetDrawFlag(summary->sprites[70], FALSE);
    Sprite_SetDrawFlag(summary->sprites[71], FALSE);
    PokemonSummary_HidePokeathlonStars(summary);
    PokemonSummary_InitShinyLeafSprites(summary);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKERUS], FALSE);
}

// The cursor marks the shown Pokemon's party slot (not for a box Pokemon).
static void PokemonSummary_UpdatePartySlotSprite(PokemonSummary *summary) {
    if (summary->args->monDataType != POKEMON_SUMMARY_BOX_MON_ARRAY) {
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], sPokemonSummaryPartySlotPositions[summary->args->partySlot][0], sPokemonSummaryPartySlotPositions[summary->args->partySlot][1]);
        Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 2);
    } else {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], FALSE);
    }
}

static void PokemonSummary_HideSprites0To7And21And22(PokemonSummary *summary) {
    Sprite **sprites = summary->sprites;
    u8 i;
    for (i = 0; i < 8; i++) {
        Sprite_SetDrawFlag(sprites[i], FALSE);
    }
    Sprite_SetDrawFlag(summary->sprites[21], FALSE);
    Sprite_SetDrawFlag(summary->sprites[22], FALSE);
}

static void PokemonSummary_LoadBallSprite(PokemonSummary *summary) {
    int pokeball = summary->mon.pokeball;
    int charFile = pokeball == BALL_NONE ? 25 : pokeball + 24;
    SpriteSystem_ReplaceCharResObj(summary->spriteSystem, summary->spriteManager, NARC_a_1_6_2, charFile, FALSE, 0);
    SpriteSystem_ReplacePlttResObj(summary->spriteSystem, summary->spriteManager, NARC_a_1_6_2, sPokemonSummaryBallPalettes[summary->mon.pokeball] + 49, FALSE, 6);
}

static void PokemonSummary_UpdateStatusSprite(PokemonSummary *summary) {
    if (summary->mon.status == PARTY_MON_STATUS_ICON_OK) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_STATUS], FALSE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKERUS], FALSE);
        return;
    }
    if (summary->mon.status != PARTY_MON_STATUS_ICON_UNSET) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKERUS], FALSE);
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_STATUS], TRUE);
        Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_STATUS], summary->mon.status);
        return;
    }
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKERUS], TRUE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_STATUS], FALSE);
}

static void PokemonSummary_LoadTypeAndIconSprites(PokemonSummary *summary) {
    u16 i;
    PokemonSummary_SetMonTypeSprites(summary);
    for (i = 0; i < MAX_MON_MOVES; i++) {
        u16 move = summary->mon.moves[i];
        if (move != MOVE_NONE) {
            PokemonSummary_SetTypeSprite(summary, i + POKEMON_SUMMARY_SPRITE_MOVE_TYPES, i + 5, GetMoveAttr(move, MOVEATTR_TYPE));
        }
    }
    PokemonSummary_LoadShownMonIcon(summary);
}

// Shows the type sprites (and the move category sprite) of the current page.
static void PokemonSummary_UpdateTypeSprites(PokemonSummary *summary) {
    for (u16 i = POKEMON_SUMMARY_SPRITE_TYPE_1; i <= POKEMON_SUMMARY_SPRITE_MON_ICON; i++) {
        thunk_Sprite_SetDrawFlag(summary->sprites[i], FALSE);
    }
    if (summary->mon.isEgg) {
        return;
    }
    switch (summary->page) {
    case POKEMON_SUMMARY_PAGE_INFO:
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], TRUE);
        if (summary->mon.type1 == summary->mon.type2) {
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], 108, 48);
        } else {
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], 91, 48);
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], TRUE);
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], 125, 48);
        }
        break;
    case POKEMON_SUMMARY_PAGE_STATS:
        for (u16 i = 0; i < MAX_MON_MOVES; i++) {
            if (summary->mon.moves[i]) {
                u32 type = GetMoveAttr(summary->mon.moves[i], MOVEATTR_TYPE);
                PokemonSummary_SetTypeSprite(summary, i + POKEMON_SUMMARY_SPRITE_MOVE_TYPES, i + 5, type);
                thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TYPES + i], TRUE);
                Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TYPES + i], 24, 32 * i + 16);
            }
        }
        if (summary->args->moveToLearn) {
            u32 type = GetMoveAttr(summary->args->moveToLearn, MOVEATTR_TYPE);
            PokemonSummary_SetTypeSprite(summary, POKEMON_SUMMARY_SPRITE_MOVE_TO_LEARN_TYPE, 9, type);
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TO_LEARN_TYPE], TRUE);
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TO_LEARN_TYPE], 24, 160);
        } else {
            thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TO_LEARN_TYPE], FALSE);
        }
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_1], 200, 24);
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_TYPE_2], 234, 24);
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], 232, 40);
        break;
    }
}

static void PokemonSummary_HidePokeathlonStars(PokemonSummary *summary) {
    int i;
    for (i = 0; i < 25; i++) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKEATHLON_STARS + i], FALSE);
    }
    for (i = 0; i < 5; i++) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKEATHLON_MODIFIERS + i], FALSE);
    }
}

static void PokemonSummary_InitShinyLeafSprites(PokemonSummary *summary) {
    int i;
    for (i = 0; i < 6; i++) {
        Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], FALSE);
        Sprite_SetAnimActiveFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], TRUE);
        Sprite_SetDrawPriority(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], 6 - i);
    }
}

static void PokemonSummary_SetPokeathlonStatStars(Sprite **sprites, int firstStar, int maxStars, int baseStars, int color, int modifier, int modifierSprite) {
    u8 states[5];
    int i;
    int result = PokemonSummary_GetPokeathlonStarStates(states, maxStars, baseStars, color, modifier);

    for (i = 0; i < 5; i++) {
        if (states[i] == 0) {
            Sprite_SetDrawFlag(sprites[firstStar + i], FALSE);
        } else if (states[i] == 1) {
            Sprite_SetDrawFlag(sprites[firstStar + i], TRUE);
            Sprite_SetAnimCtrlSeq(sprites[firstStar + i], 3);
        } else if (states[i] == 2) {
            Sprite_SetDrawFlag(sprites[firstStar + i], TRUE);
            Sprite_SetAnimCtrlSeq(sprites[firstStar + i], 0);
        } else if (states[i] == 3) {
            Sprite_SetDrawFlag(sprites[firstStar + i], TRUE);
            Sprite_SetAnimCtrlSeq(sprites[firstStar + i], 1);
        } else if (states[i] == 4) {
            Sprite_SetDrawFlag(sprites[firstStar + i], TRUE);
            Sprite_SetAnimCtrlSeq(sprites[firstStar + i], 2);
        }
    }
    if (result == 0) {
        Sprite_SetDrawFlag(sprites[modifierSprite], FALSE);
    } else if (result > 0) {
        Sprite_SetDrawFlag(sprites[modifierSprite], TRUE);
        Sprite_SetAnimCtrlSeq(sprites[modifierSprite], 4);
    } else if (result < 0) {
        Sprite_SetDrawFlag(sprites[modifierSprite], TRUE);
        Sprite_SetAnimCtrlSeq(sprites[modifierSprite], 5);
    }
}

// Each star: 0 hidden, 1 empty (above the base), else 2 + color. Returns the sign of the Aprijuice modifier.
int PokemonSummary_GetPokeathlonStarStates(u8 *states, int maxStars, int baseStars, int color, int modifier) {
    int i;
    color += 2;
    for (i = 0; i < 5; i++) {
        if (i > maxStars) {
            states[i] = 0;
        } else if (i > baseStars) {
            states[i] = 1;
        } else {
            states[i] = color;
        }
    }
    if (modifier > 0) {
        return 1;
    }
    if (modifier < 0) {
        return -1;
    }
    return 0;
}

static void PokemonSummary_UpdatePokeathlonStars(PokemonSummary *summary) {
    struct {
        struct PokeathlonPerformanceStars stars;
        PartyExtraSub aprijuice;
        u8 pad;
        struct PokeathlonTodayPerformance performance;
    } data;

    BoxPokemon *mon;

    if (summary->page == POKEMON_SUMMARY_PAGE_RIBBONS && summary->args->isFlag982Set) {
        mon = PokemonSummary_GetShownMon(summary);
        MI_CpuFill8(&data.aprijuice, 0, sizeof(PartyExtraSub));
        CalcBoxMonPokeathlonPerformance(mon, &data.performance);
        if (summary->args->monDataType == POKEMON_SUMMARY_PARTY) {
            Party_GetMonAprijuiceModifiers(summary->args->party, &data.aprijuice, summary->args->partySlot);
        }
        CalcBoxmonPokeathlonStars(&data.stars, mon, (s8 *)&data.aprijuice, HEAP_ID_19);
        PokemonSummary_SetPokeathlonStatStars(summary->sprites, POKEMON_SUMMARY_SPRITE_POKEATHLON_STARS, data.performance.stats[4].hi, data.stars.stamina, data.stars.color[4], (s8)data.aprijuice.stats[4], POKEMON_SUMMARY_SPRITE_POKEATHLON_MODIFIERS);
        PokemonSummary_SetPokeathlonStatStars(summary->sprites, POKEMON_SUMMARY_SPRITE_POKEATHLON_STARS + 5, data.performance.stats[0].hi, data.stars.power, data.stars.color[0], (s8)data.aprijuice.stats[0], POKEMON_SUMMARY_SPRITE_POKEATHLON_MODIFIERS + 1);
        PokemonSummary_SetPokeathlonStatStars(summary->sprites, POKEMON_SUMMARY_SPRITE_POKEATHLON_STARS + 10, data.performance.stats[2].hi, data.stars.speed, data.stars.color[2], (s8)data.aprijuice.stats[2], POKEMON_SUMMARY_SPRITE_POKEATHLON_MODIFIERS + 2);
        PokemonSummary_SetPokeathlonStatStars(summary->sprites, POKEMON_SUMMARY_SPRITE_POKEATHLON_STARS + 15, data.performance.stats[1].hi, data.stars.skill, data.stars.color[1], (s8)data.aprijuice.stats[1], POKEMON_SUMMARY_SPRITE_POKEATHLON_MODIFIERS + 3);
        PokemonSummary_SetPokeathlonStatStars(summary->sprites, POKEMON_SUMMARY_SPRITE_POKEATHLON_STARS + 20, data.performance.stats[3].hi, data.stars.jump, data.stars.color[3], (s8)data.aprijuice.stats[3], POKEMON_SUMMARY_SPRITE_POKEATHLON_MODIFIERS + 4);
    } else {
        PokemonSummary_HidePokeathlonStars(summary);
    }
}

static void PokemonSummary_UpdateShinyLeafSprites(PokemonSummary *summary) {
    int i;
    if (summary->page == POKEMON_SUMMARY_PAGE_INFO) {
        if (summary->mon.shinyLeaves[5]) {
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAF_CROWN], TRUE);
            for (i = 0; i < 5; i++) {
                Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], FALSE);
            }
        } else {
            for (i = 0; i < 5; i++) {
                if (summary->mon.shinyLeaves[i]) {
                    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], TRUE);
                } else {
                    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], FALSE);
                }
            }
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAF_CROWN], FALSE);
        }
    } else {
        for (i = 0; i < 6; i++) {
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY_LEAVES + i], FALSE);
        }
    }
}

static void PokemonSummary_SetMonTypeSprites(PokemonSummary *summary) {
    PokemonSummary_SetTypeSprite(summary, POKEMON_SUMMARY_SPRITE_TYPE_1, 3, summary->mon.type1);
    PokemonSummary_SetTypeSprite(summary, POKEMON_SUMMARY_SPRITE_TYPE_2, 4, summary->mon.type2);
}

static void PokemonSummary_SetTypeSprite(PokemonSummary *summary, u8 sprite, u8 resId, u8 type) {
    NarcId narc = TypeIcon_GetNarc();
    int charFile = TypeIcon_GetCharFile(type);
    SpriteSystem_ReplaceCharResObj(summary->spriteSystem, summary->spriteManager, narc, charFile, TRUE, resId);
    thunk_Sprite_SetPaletteOverride(summary->sprites[sprite], TypeIcon_GetPalette(type) + 3);
}

// Finds the move type sprite shown in the given move slot row; *slot becomes its index.
static void PokemonSummary_FindMoveTypeSprite(PokemonSummary *summary, u8 *slot, s16 *x, s16 *y) {
    s16 targetY = (*slot << 5) + 16;
    s16 i;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Sprite_GetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TYPES + i], x, y);
        if (targetY == *y) {
            *slot = i;
            return;
        }
    }
}

static void PokemonSummary_SwapMoveTypeSprites(PokemonSummary *summary, u8 slotA, u8 slotB) {
    s16 posA[2];
    s16 posB[2];
    PokemonSummary_FindMoveTypeSprite(summary, &slotA, &posA[1], &posA[0]);
    PokemonSummary_FindMoveTypeSprite(summary, &slotB, &posB[1], &posB[0]);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TYPES + slotA], posB[1], posB[0]);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_TYPES + slotB], posA[1], posA[0]);
}

static void PokemonSummary_SetMoveCategorySprite(PokemonSummary *summary, u16 move) {
    int category = GetMoveAttr(move, MOVEATTR_CLASS);
    NarcId narc = MoveCategoryIcon_GetNarc();
    int charFile = MoveCategoryIcon_GetCharFile(category);
    SpriteSystem_ReplaceCharResObj(summary->spriteSystem, summary->spriteManager, narc, charFile, TRUE, 10);
    thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_MOVE_CATEGORY], MoveCategoryIcon_GetPalette(category) + 3);
}

// The slots after the four moves are the move to learn and the cancel button.
static void PokemonSummary_UpdateMoveCursorSprite(PokemonSummary *summary) {
    u32 slot = summary->moveSlot;
    switch (slot) {
    case POKEMON_SUMMARY_MOVE_SLOT_NEW:
        if (summary->args->mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 68, slot * 32 + 40);
        } else {
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 68, slot * 32 + 24);
        }
        Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
        break;
    case POKEMON_SUMMARY_MOVE_SLOT_CANCEL:
        if (summary->args->mode == POKEMON_SUMMARY_MODE_FORGET_MOVE) {
            Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 220, 176);
            Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 3);
        }
        break;
    default:
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 68, slot * 32 + 24);
        Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], 0);
        break;
    }
}

static void PokemonSummary_ShowSwapCursorSprite(PokemonSummary *summary) {
    s16 pos[2];
    Sprite_GetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CURSOR], &pos[1], &pos[0]);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], pos[1], pos[0]);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], TRUE);
}

static void PokemonSummary_ResetSwapCursorSprite(PokemonSummary *summary) {
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], 68, 168);
    Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_SWAP_CURSOR], 0);
}

static void PokemonSummary_InitSheenSparkles(PokemonSummary *summary) {
    u32 i;
    summary->sparkleState = 0;
    summary->unk7C3 = 0;
    summary->unk7C2 = 0;
    if (summary->mon.contestStats[5] == 0) {
        summary->numSparkles = 0;
    } else if (summary->mon.contestStats[5] == 255) {
        summary->numSparkles = 12;
    } else {
        summary->numSparkles = (12 * summary->mon.contestStats[5]) >> 8;
    }
    for (i = POKEMON_SUMMARY_SPRITE_SHEEN_SPARKLES; i <= POKEMON_SUMMARY_SPRITE_SHEEN_SPARKLES + 11; i++) {
        Sprite_SetDrawFlag(summary->sprites[i], FALSE);
        Sprite_SetAnimationFrame(summary->sprites[i], 0);
    }
}

static void PokemonSummary_UpdateMarkingSprites(PokemonSummary *summary) {
    u32 i;
    for (i = 0; i < 6; i++) {
        if (summary->mon.markings & (1 << i)) {
            Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_MARKINGS + i], 1);
        } else {
            Sprite_SetAnimCtrlSeq(summary->sprites[POKEMON_SUMMARY_SPRITE_MARKINGS + i], 0);
        }
    }
    if (summary->mon.shiny == TRUE && !summary->mon.isEgg) {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY], TRUE);
    } else {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_SHINY], FALSE);
    }
    if (summary->mon.pokerus == POKEMON_SUMMARY_POKERUS_CURED) {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKERUS_CURED], TRUE);
    } else {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_POKERUS_CURED], FALSE);
    }
}

static void PokemonSummary_ShowConditionChangeSprites(PokemonSummary *summary) {
    u8 i;
    for (i = 0; i < 5; i++) {
        if ((summary->unk7BE & (1 << i)) != 0) {
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CHANGES + i], TRUE);
        }
    }
}

// Loads a Pokemon's icon graphics into the sprite's VRAM.
static void PokemonSummary_LoadMonIcon(PokemonSummary *summary, void *mon, int sprite) {
    NNSG2dCharacterData *charData;
    void *file;
    u32 location = NNS_G2dGetImageLocation(Sprite_GetImageProxy(summary->sprites[sprite]), NNS_G2D_VRAM_TYPE_2DSUB);
    int fileId;
    if (summary->args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
        fileId = Boxmon_GetIconNaix(mon);
    } else {
        fileId = Pokemon_GetIconNaix(mon);
    }
    file = GfGfxLoader_GetCharData(NARC_poketool_icongra_poke_icon, fileId, FALSE, &charData, HEAP_ID_19);
    DC_FlushRange(charData->pRawData, 0x200);
    GXS_LoadOBJ(charData->pRawData, location, 0x200);
    Heap_Free(file);
}

static void PokemonSummary_LoadShownMonIcon(PokemonSummary *summary) {
    void *mon = PokemonSummary_GetShownMon(summary);
    int palette;
    PokemonSummary_LoadMonIcon(summary, mon, POKEMON_SUMMARY_SPRITE_MON_ICON);
    palette = GetMonIconPaletteEx(summary->mon.species, summary->mon.form, summary->mon.isEgg);
    thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_MON_ICON], palette + 12);
    Sprite_SetFlipMode_Int(summary->sprites[POKEMON_SUMMARY_SPRITE_MON_ICON], 1 ^ GetMonBaseStat_HandleAlternateForm(summary->mon.species, summary->mon.form, BASE_FLIP));
}

// The party's icons (only the shown Pokemon's when not viewing a party).
static void PokemonSummary_LoadPartyIcons(PokemonSummary *summary) {
    void *mon = PokemonSummary_GetShownMon(summary);
    int count;
    int i;

    switch (summary->args->monDataType) {
    case POKEMON_SUMMARY_MON_ARRAY:
        count = 1;
        break;
    case POKEMON_SUMMARY_BOX_MON_ARRAY:
        count = 0;
        break;
    case POKEMON_SUMMARY_PARTY:
        count = summary->args->partyCount;
        break;
    }
    for (i = 0; i < count; i++) {
        switch (summary->args->monDataType) {
        case POKEMON_SUMMARY_MON_ARRAY:
            mon = PokemonSummary_GetShownMon(summary);
            thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + i], Pokemon_GetIconPalette(mon) + 12);
            break;
        case POKEMON_SUMMARY_BOX_MON_ARRAY:
            thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + i], Boxmon_GetIconPalette(mon) + 12);
            break;
        case POKEMON_SUMMARY_PARTY:
            mon = Party_GetMonByIndex(summary->args->party, i);
            thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + i], Pokemon_GetIconPalette(mon) + 12);
            break;
        }
        PokemonSummary_LoadMonIcon(summary, mon, POKEMON_SUMMARY_SPRITE_PARTY_ICONS + i);
    }
    for (; i < PARTY_SIZE; i++) {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + i], FALSE);
    }
}

static void PokemonSummary_SetBoxMonIconPos(PokemonSummary *summary) {
    PokemonSummaryArgs *args = summary->args;
    if (args->monDataType == POKEMON_SUMMARY_BOX_MON_ARRAY) {
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS], 215, 80);
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + 1], 215, 80);
    }
}

// A box Pokemon's icon alternates between the first two party icon sprites.
static void PokemonSummary_AlternateBoxMonIcon(PokemonSummary *summary) {
    void *mon;
    if (summary->args->monDataType != POKEMON_SUMMARY_BOX_MON_ARRAY) {
        return;
    }
    mon = PokemonSummary_GetShownMon(summary);
    if (summary->boxIconSprite == 0) {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS], TRUE);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + 1], FALSE);
        PokemonSummary_LoadMonIcon(summary, mon, POKEMON_SUMMARY_SPRITE_PARTY_ICONS);
        thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS], Boxmon_GetIconPalette(mon) + 12);
    } else {
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS], FALSE);
        thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + 1], TRUE);
        PokemonSummary_LoadMonIcon(summary, mon, POKEMON_SUMMARY_SPRITE_PARTY_ICONS + 1);
        thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_PARTY_ICONS + 1], Boxmon_GetIconPalette(mon) + 12);
    }
    summary->boxIconSprite ^= 1;
}

static void PokemonSummary_ShowMonIconSprite(PokemonSummary *summary) {
    if (summary->page == POKEMON_SUMMARY_PAGE_STATS) {
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MON_ICON], 160, 16);
    } else {
        Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_MON_ICON], 32, 68);
    }
    thunk_Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_MON_ICON], TRUE);
}

// A condition chart corner: from the chart's center towards its tip, by the contest stat.
static s16 PokemonSummary_GetConditionPoint(int stat, s16 tip, s16 center) {
    u32 delta;
    if (center > tip) {
        delta = ((u32)((center - tip) * (stat + 44)) << 16) / 300;
        delta >>= 16;
        return center - (s16)delta;
    }
    delta = ((u32)((tip - center) * (stat + 44)) << 16) / 300;
    delta >>= 16;
    return center + (s16)delta;
}

static void PokemonSummary_ShowConditionSprites(PokemonSummary *summary) {
    s16 x;
    x = PokemonSummary_GetConditionPoint(summary->mon.contestStats[0], 88, 88);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_COOL], x, PokemonSummary_GetConditionPoint(summary->mon.contestStats[0], 49, 73));
    x = PokemonSummary_GetConditionPoint(summary->mon.contestStats[1], 110, 88);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_BEAUTY], x, PokemonSummary_GetConditionPoint(summary->mon.contestStats[1], 65, 73));
    x = PokemonSummary_GetConditionPoint(summary->mon.contestStats[2], 103, 88);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CUTE], x, PokemonSummary_GetConditionPoint(summary->mon.contestStats[2], 92, 73));
    x = PokemonSummary_GetConditionPoint(summary->mon.contestStats[3], 72, 87);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_SMART], x, PokemonSummary_GetConditionPoint(summary->mon.contestStats[3], 92, 73));
    x = PokemonSummary_GetConditionPoint(summary->mon.contestStats[4], 65, 87);
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_TOUGH], x, PokemonSummary_GetConditionPoint(summary->mon.contestStats[4], 65, 73));
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_COOL], TRUE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_BEAUTY], TRUE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CUTE], TRUE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_SMART], TRUE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_TOUGH], TRUE);
}

static void PokemonSummary_HideConditionSprites(PokemonSummary *summary) {
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_COOL], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_BEAUTY], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_CUTE], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_SMART], FALSE);
    Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_CONDITION_TOUGH], FALSE);
}

static void PokemonSummary_SetRibbonSprite(PokemonSummary *summary, int ribbon, int index) {
    int attr = GetRibbonAttr_Int(ribbon, RIBBONDAT_NCGR);
    SpriteSystem_ReplaceCharResObj(summary->spriteSystem, summary->spriteManager, NARC_a_0_3_9, attr, FALSE, index + 25);
    attr = GetRibbonAttr_Int(ribbon, RIBBONDAT_NCLR);
    thunk_Sprite_SetPaletteOverride(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBONS + index], attr + 7);
}

static void PokemonSummary_ShowRibbonSprites(PokemonSummary *summary) {
    u16 i;
    for (i = POKEMON_SUMMARY_SPRITE_RIBBONS; i <= 66; i++) {
        Sprite_SetDrawFlag(summary->sprites[i], FALSE);
    }
    if (summary->page == POKEMON_SUMMARY_PAGE_RIBBONS) {
        for (i = 0; i < POKEMON_SUMMARY_RIBBONS_PER_PAGE; i++) {
            if (i < summary->ribbonCount) {
                Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBONS + i], TRUE);
                PokemonSummary_SetRibbonSprite(summary, PokemonSummary_GetRibbonAt(summary, i), (u8)i);
            }
        }
        Sprite_SetAnimCtrlSeq(summary->sprites[66], 0);
    }
}

static void PokemonSummary_UpdateRibbonSprites(PokemonSummary *summary) {
    u16 i;
    for (i = 0; i < POKEMON_SUMMARY_RIBBONS_PER_PAGE; i++) {
        if (summary->ribbonRow * POKEMON_SUMMARY_RIBBONS_PER_PAGE + i < summary->ribbonCount) {
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBONS + i], TRUE);
            PokemonSummary_SetRibbonSprite(summary, PokemonSummary_GetRibbonAt(summary, i), (u8)i);
        } else {
            Sprite_SetDrawFlag(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBONS + i], FALSE);
        }
    }
}

static void PokemonSummary_UpdateRibbonCursorSprite(PokemonSummary *summary) {
    int cursor = summary->ribbonCursor;
    int column = cursor % POKEMON_SUMMARY_RIBBON_COLUMNS;
    int row = cursor / POKEMON_SUMMARY_RIBBON_COLUMNS;
    Sprite_SetPositionXY(summary->sprites[POKEMON_SUMMARY_SPRITE_RIBBON_CURSOR], column * 32 + 32, row * 40 + 24);
}

static void PokemonSummary_AnimateRibbonSprite66(PokemonSummary *summary) {
    if (Sprite_GetDrawFlag(summary->sprites[66]) == TRUE) {
        Sprite_UpdateAnim(summary->sprites[66], FX32_ONE);
    }
}
