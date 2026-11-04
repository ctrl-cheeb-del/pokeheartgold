#include "application/plaza_game.h"

#include "global.h"

#include "constants/gx.h"
#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0236.h"
#include "wifi_plaza/wifi_plaza_internal.h"

#include "assert.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_command.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "filesystem.h"
#include "font.h"
#include "friend_roster.h"
#include "game_stats.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "link_synchronization.h"
#include "math_util.h"
#include "oam_manager.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "options.h"
#include "overlay_00_thumb.h"
#include "render_text.h"
#include "scanline_effect.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite_transfer.h"
#include "system.h"
#include "text.h"
#include "vram_transfer_manager.h"
#include "wireless_status_icon.h"

int Comm_FindFriendSlot(SaveData *saveData, void *friendData, u32 *index);

enum PlazaGameKind {
    PLAZA_GAME_SWALOT_PLOP,
    PLAZA_GAME_MIME_JR_TOP,
    PLAZA_GAME_WOBBUFFET_POP,
};

enum PlazaGameCommandId {
    PLAZA_GAME_CMD_VOTE_YES = COMM_BASE_COMMAND_COUNT,
    PLAZA_GAME_CMD_VOTE_NO,
    PLAZA_GAME_CMD_CONTINUE,
    PLAZA_GAME_CMD_QUIT,
    PLAZA_GAME_CMD_SELECTION,
};

enum PlazaGameTitleSlideInState {
    PLAZA_GAME_TITLE_SLIDE_IN,
    PLAZA_GAME_TITLE_BOUNCE_OUT,
    PLAZA_GAME_TITLE_BOUNCE_BACK,
    PLAZA_GAME_TITLE_SLIDE_IN_DONE,
};

enum PlazaGameTitleSlideOutState {
    PLAZA_GAME_TITLE_SLIDE_OUT,
    PLAZA_GAME_TITLE_CLEAR,
};

enum PlazaGameSignState {
    PLAZA_GAME_SIGN_IDLE,
    PLAZA_GAME_SIGN_CREATE,
    PLAZA_GAME_SIGN_OPEN_WINDOW,
    PLAZA_GAME_SIGN_SHOW,
    PLAZA_GAME_SIGN_CLOSE_WINDOW,
    PLAZA_GAME_SIGN_FREE,
};

enum PlazaGameEntryState {
    PLAZA_GAME_ENTRY_FADE_IN,
    PLAZA_GAME_ENTRY_WAIT_FADE_IN,
    PLAZA_GAME_ENTRY_WAIT_TITLE,
    PLAZA_GAME_ENTRY_PRINT_ACCEPTED,
    PLAZA_GAME_ENTRY_WAIT_ACCEPTED,
    PLAZA_GAME_ENTRY_HIDE_ACCEPTED,
    PLAZA_GAME_ENTRY_WAIT_TITLE_SLIDE_OUT,
    PLAZA_GAME_ENTRY_SHOW_PLAYERS,
    PLAZA_GAME_ENTRY_WAIT_PLAYERS,
    PLAZA_GAME_ENTRY_START_SYNC,
    PLAZA_GAME_ENTRY_WAIT_SYNC,
    PLAZA_GAME_ENTRY_SLIDE_OUT_PLAYERS,
    PLAZA_GAME_ENTRY_WAIT_PLAYERS_SLIDE_OUT,
    PLAZA_GAME_ENTRY_FADE_OUT,
    PLAZA_GAME_ENTRY_WAIT_FADE_OUT,
    PLAZA_GAME_ENTRY_WAIT_SELECTION,
    PLAZA_GAME_ENTRY_DONE,
};

enum PlazaGameContinueState {
    PLAZA_GAME_CONTINUE_FADE,
    PLAZA_GAME_CONTINUE_WAIT_FADE,
    PLAZA_GAME_CONTINUE_PRINT_PROMPT,
    PLAZA_GAME_CONTINUE_WAIT_PROMPT,
    PLAZA_GAME_CONTINUE_OPEN_YES_NO,
    PLAZA_GAME_CONTINUE_HANDLE_YES_NO,
    PLAZA_GAME_CONTINUE_WAIT_ANSWERS,
    PLAZA_GAME_CONTINUE_PRINT_CANCELED,
    PLAZA_GAME_CONTINUE_WAIT_CANCELED,
    PLAZA_GAME_CONTINUE_WAIT,
    PLAZA_GAME_CONTINUE_FADE_OUT,
    PLAZA_GAME_CONTINUE_WAIT_FADE_OUT,
    PLAZA_GAME_CONTINUE_FINISH,
};

enum PlazaGameRankingState {
    PLAZA_GAME_RANKING_FADE_IN,
    PLAZA_GAME_RANKING_WAIT_FADE_IN,
    PLAZA_GAME_RANKING_PRINT_TITLE,
    PLAZA_GAME_RANKING_WAIT_TITLE,
    PLAZA_GAME_RANKING_HIDE_TITLE,
    PLAZA_GAME_RANKING_NEXT_RANK,
    PLAZA_GAME_RANKING_SHOW_RANK,
    PLAZA_GAME_RANKING_WAIT_PLAYERS,
    PLAZA_GAME_RANKING_START_FLASH,
    PLAZA_GAME_RANKING_WAIT_FLASH,
    PLAZA_GAME_RANKING_PRINT_RESULT,
    PLAZA_GAME_RANKING_WAIT_RESULT,
    PLAZA_GAME_RANKING_PRINT_TAP_TOY,
    PLAZA_GAME_RANKING_WAIT_TAP_TOY,
    PLAZA_GAME_RANKING_HIDE_MESSAGE,
    PLAZA_GAME_RANKING_START_SYNC,
    PLAZA_GAME_RANKING_WAIT_SYNC,
    PLAZA_GAME_RANKING_FADE_OUT,
    PLAZA_GAME_RANKING_WAIT_FADE_OUT,
    PLAZA_GAME_RANKING_RECORD_FRIEND_PLAYS,
    PLAZA_GAME_RANKING_RUN_CONTINUE,
    PLAZA_GAME_RANKING_FINISH,
    PLAZA_GAME_RANKING_WAIT_NO_WINNER,
    PLAZA_GAME_RANKING_SHOW_ALL_LAST,
};

enum PlazaGameTeamState {
    PLAZA_GAME_TEAM_FADE_IN,
    PLAZA_GAME_TEAM_WAIT_FADE_IN,
    PLAZA_GAME_TEAM_PRINT_TITLE,
    PLAZA_GAME_TEAM_WAIT_TITLE,
    PLAZA_GAME_TEAM_HIDE_TITLE,
    PLAZA_GAME_TEAM_SHOW_PLAYERS,
    PLAZA_GAME_TEAM_WAIT_PLAYERS,
    PLAZA_GAME_TEAM_RUN_BALLOONS,
    PLAZA_GAME_TEAM_PRINT_TOTAL,
    PLAZA_GAME_TEAM_WAIT_TOTAL,
    PLAZA_GAME_TEAM_PRINT_TAP_TOY,
    PLAZA_GAME_TEAM_WAIT_TAP_TOY,
    PLAZA_GAME_TEAM_HOLD,
    PLAZA_GAME_TEAM_HOLD_POWERED_UP,
    PLAZA_GAME_TEAM_START_SYNC,
    PLAZA_GAME_TEAM_WAIT_SYNC,
    PLAZA_GAME_TEAM_FADE_OUT,
    PLAZA_GAME_TEAM_WAIT_FADE_OUT,
    PLAZA_GAME_TEAM_RECORD_FRIEND_PLAYS,
    PLAZA_GAME_TEAM_RUN_CONTINUE,
    PLAZA_GAME_TEAM_FINISH,
};

static u8 PlazaGameRoster_GetNetId(const PlazaGameRoster *roster, u32 index);
static void PlazaGameEntry_SetSelection(PlazaGameEntry *entry, int selection);
static void PlazaGameResults_ReceiveVote(PlazaGameResults *results, int netId, BOOL yes);
static void PlazaGameResults_ReceiveContinue(PlazaGameResults *results, u8 result);
static void PlazaGameMotion_Init(PlazaGameMotion *motion, fx32 start, fx32 end, fx32 velocity, int duration);
static BOOL PlazaGameMotion_Update(PlazaGameMotion *motion, int frame);
static void PlazaGame_OffsetScreenTiles(NNSG2dScreenData *screen, u16 offset);
static void PlazaGameGfx_Init(PlazaGameGfx *gfx, int count, enum HeapID heapId);
static void PlazaGameGfx_Free(PlazaGameGfx *gfx);
static PlazaGameGfxRes *PlazaGameGfx_Load(PlazaGameGfx *gfx, NARC *narc, int plttFile, int plttCount, int charFile, int cellFile, int animFile, int id, enum HeapID heapId);
static Sprite *PlazaGameGfx_CreateSprite(PlazaGameGfxRes *gfxRes, SpriteList *spriteList, s16 x, s16 y, u16 priority, enum HeapID heapId);
static void PlazaGameGfx_LoadInto(PlazaGameGfx *gfx, PlazaGameGfxRes *gfxRes, NARC *narc, int plttFile, int plttCount, int charFile, int cellFile, int animFile, volatile int id, volatile enum HeapID heapId);
static void PlazaGameGfx_Unload(PlazaGameGfx *gfx, PlazaGameGfxRes *gfxRes);
static void PlazaGameBg_Init(PlazaGameBg *bg, const GraphicsModes *modes, const PlazaGameBgTemplate *templates, u32 count, enum HeapID heapId);
static void PlazaGameBg_Free(PlazaGameBg *bg);
static void PlazaGameBg_Update(PlazaGameBg *bg);
static void PlazaGameSprites_Init(PlazaGameSprites *sprites, int count, int charCount, int plttCount, enum HeapID heapId);
static void PlazaGameSprites_Free(PlazaGameSprites *sprites);
static void PlazaGameSprites_Update(PlazaGameSprites *sprites);
static void PlazaGameSprites_ApplyOam(PlazaGameSprites *sprites);
static void PlazaGameText_Init(PlazaGameText *text, enum HeapID heapId);
static void PlazaGameText_Free(PlazaGameText *text);
static void PlazaGameText_ResetBuffers(PlazaGameText *text);
static void PlazaGameText_BufferPlayerName(PlazaGameText *text, PlayerProfile *profile);
static void PlazaGameText_BufferCountry(PlazaGameText *text, int country);
static void PlazaGameText_BufferCity(PlazaGameText *text, int country, int region);
static void PlazaGameText_BufferNumber(PlazaGameText *text, int value, int digits);
static void PlazaGameText_BufferTwoDigitNumber(PlazaGameText *text, int value);
static void PlazaGameText_BufferTapToyName(PlazaGameText *text, int tapToy);
static void PlazaGameText_BufferActivityName(PlazaGameText *text, int game);
static void PlazaGameText_Format(PlazaGameText *text, String *dest, int msgNo);
static void PlazaGameText_Print(PlazaGameText *text, int msgNo, Window *window, u8 x, u8 y);
static int PlazaGameText_PrintRightAligned(PlazaGameText *text, int msgNo, Window *window, u8 right, u8 y);
static int PlazaGameText_PrintMessage(PlazaGameText *text, int msgNo, Window *window, String *string, int textSpeed);
static int PlazaGameText_PrintWithColor(PlazaGameText *text, int msgNo, Window *window, u8 x, u8 y, u32 color);
static void PlazaGameMessageBox_Init(PlazaGameMessageBox *messageBox, PlazaGameBg *bg, SaveData *saveData, u32 colorVariant, enum HeapID heapId);
static void PlazaGameMessageBox_Free(PlazaGameMessageBox *messageBox);
static void PlazaGameMessageBox_Show(PlazaGameMessageBox *messageBox, PlazaGameText *text, int msgNo, int index);
static void PlazaGameMessageBox_Hide(PlazaGameMessageBox *messageBox, int index);
static BOOL PlazaGameMessageBox_IsPrinterFinished(PlazaGameMessageBox *messageBox, int index);
static void PlazaGameMessageBox_ShowWaitingIcon(PlazaGameMessageBox *messageBox, int index);
static void PlazaGameMessageBox_HideWaitingIcon(PlazaGameMessageBox *messageBox, int index);
static PlazaGameEntry *PlazaGameEntry_New(const PlazaGameRoster *roster, u16 game, enum HeapID heapId);
static void PlazaGameEntry_LoadGraphics(PlazaGameEntry *entry, enum HeapID heapId);
static void PlazaGameEntry_FreeGraphics(PlazaGameEntry *entry);
static void PlazaGameEntry_MainTask(SysTask *task, void *data);
static void PlazaGameEntry_VBlankTask(SysTask *task, void *data);
static u32 PlazaGame_PickWeighted(const u8 *weights, u32 count);
static BOOL PlazaGameEntry_UpdatePlayers(PlazaGameEntry *entry);
static void PlazaGamePlayer_Init(PlazaGamePlayer *player, int count, int game, NNSG2dScreenData *screen, PlazaGameBg *bg, int index, u32 localIndex, PlazaGameSprites *sprites, PlazaGameGfxRes *gfxRes, enum HeapID heapId);
static void PlazaGamePlayer_PrintName(PlazaGamePlayer *player, PlazaGameText *text, PlayerProfile *profile, int x, s16 y, int highlight);
static void PlazaGamePlayer_PrintLocation(PlazaGamePlayer *player, PlazaGameText *text, int showCountry, int country, int region, s16 x);
static void PlazaGamePlayer_ShowRank(PlazaGamePlayer *player, int rank);
static void PlazaGamePlayer_PrintScore(PlazaGamePlayer *player, PlazaGameText *text, int score, int right, s16 y, int digits);
static void PlazaGamePlayer_ScheduleTransfer(PlazaGamePlayer *player, PlazaGameBg *bg);
static void PlazaGamePlayer_ShowSprite(PlazaGamePlayer *player);
static void PlazaGamePlayer_Free(PlazaGamePlayer *player);
static void PlazaGamePlayer_StartSlideIn(PlazaGamePlayer *player, int x, s16 delay);
static void PlazaGamePlayer_StartSlideOut(PlazaGamePlayer *player, s16 delay);
static BOOL PlazaGamePlayer_UpdateSlide(PlazaGamePlayer *player);
static void PlazaGamePlayer_SetSpritePos(PlazaGamePlayer *player, u32 x);
static int PlazaGame_GetRelativeSeat(u32 count, int index, u32 localIndex);
static void PlazaGameLineScroll_Init(PlazaGameLineScroll *lineScroll, PlazaGameBg *bg, enum HeapID heapId);
static void PlazaGameLineScroll_Free(PlazaGameLineScroll *lineScroll);
static void PlazaGameLineScroll_SetPlayer(PlazaGameLineScroll *lineScroll, PlazaGamePlayer *player);
static void PlazaGameLineScroll_Swap(PlazaGameLineScroll *lineScroll);
static void PlazaGameLineScroll_HBlank(void *data);
static void PlazaGamePlayerInfo_Init(PlazaGamePlayerInfo *info, const PlazaGameRoster *roster);
static int PlazaGamePlayerInfo_HasDifferentCountries(const PlazaGameRoster *roster, const u8 *countries);
static u32 PlazaGame_GetPoweredUpTapToy(u32 tapToy);
static void PlazaGameTitle_Init(PlazaGameTitle *title, PlazaGameBg *bg, PlazaGameText *text, int game, NARC *narc, enum HeapID heapId);
static void PlazaGameTitle_Free(PlazaGameTitle *title);
static void PlazaGameTitle_StartSlideIn(PlazaGameTitle *title, PlazaGameBg *bg, enum HeapID heapId);
static void PlazaGameTitle_StartSlideOut(PlazaGameTitle *title, PlazaGameBg *bg);
static BOOL PlazaGameTitle_UpdateSlideIn(PlazaGameTitle *title, PlazaGameBg *bg);
static BOOL PlazaGameTitle_UpdateSlideOut(PlazaGameTitle *title, PlazaGameBg *bg);
static void PlazaGameTitle_SetScroll(PlazaGameTitle *title, PlazaGameBg *bg, int value);
static void PlazaGameTitle_ScheduleScroll(PlazaGameTitle *title, PlazaGameBg *bg, int value);
static void PlazaGame_LoadGamePalette(NARC *narc, int game, enum HeapID heapId);
static PlazaGameResults *PlazaGameResults_New(const PlazaGameRoster *roster, const PlazaGameResultData *data, u8 game, enum HeapID heapId);
static void PlazaGameResults_LoadGraphics(PlazaGameResults *results, enum HeapID heapId);
static void PlazaGameResults_FreeGraphics(PlazaGameResults *results);
static void PlazaGameResults_RankingTask(SysTask *task, void *data);
static void PlazaGameResults_TeamTask(SysTask *task, void *data);
static void PlazaGameResults_VBlankTask(SysTask *task, void *data);
static void PlazaGameResults_LoadFlashPalette(PlazaGameResults *results, NARC *narc, enum HeapID heapId);
static void PlazaGameResults_StartFlash(PlazaGameResults *results);
static inline u8 *PlazaGameResults_GetFlashColors(PlazaGameResults *results, u8 *data, u32 slot);
static void PlazaGameResults_UpdateFlash(PlazaGameResults *results);
static void PlazaGameResults_FreeFlashPalette(PlazaGameResults *results);
static void PlazaGameContinue_Init(PlazaGameContinue *prompt, PlazaGameBg *bg, u8 voiceChat, enum HeapID heapId);
static void PlazaGameContinue_Free(PlazaGameContinue *prompt);
static BOOL PlazaGameContinue_Run(PlazaGameContinue *prompt, PlazaGameMessageBox *messageBox, PlazaGameText *text, int game, volatile enum HeapID heapId);
static u8 PlazaGameContinue_GetResult(const PlazaGameContinue *prompt);
static void PlazaGameContinue_ReceiveVote(PlazaGameContinue *prompt, int netId, BOOL yes, int count);
static void PlazaGameContinue_SetResult(PlazaGameContinue *prompt, u8 result);
static void PlazaGameBalloons_Init(PlazaGameBalloons *balloons, PlazaGameBg *bg, PlazaGameSprites *sprites, PlazaGameGfx *gfx, NARC *narc, enum HeapID heapId);
static void PlazaGameBalloons_Free(PlazaGameBalloons *balloons);
static void PlazaGameBalloons_Start(PlazaGameBalloons *balloons, int total);
static BOOL PlazaGameBalloons_Update(PlazaGameBalloons *balloons, PlazaGameBg *bg);
static void PlazaGameResults_ShowPlayer(PlazaGameResults *results, int index, int rank);
static BOOL PlazaGameResults_UpdatePlayers(PlazaGameResults *results);
static void PlazaGameResults_PlayFanfare(PlazaGameResults *results);
static BOOL PlazaGameResults_IsFanfareDone(PlazaGameResults *results);
static void PlazaGameResults_RecordFriendPlays(PlazaGameResults *results);
static int PlazaGameResults_GetScoreThreshold(PlazaGameResults *results);
static void PlazaGameResults_ReportWinners(PlazaGameResults *results);
static void PlazaGameResults_ReportTeamWin(PlazaGameResults *results);
static inline void PlazaGameSignWindow_SetInsidePlanes(u32 planes, BOOL effect);
static void PlazaGameSignWindow_Init(PlazaGameSignWindow *window, PlazaGameGfxRes *gfxRes, SpriteList *spriteList, enum HeapID heapId);
static BOOL PlazaGameSignWindow_Open(PlazaGameSignWindow *window);
static BOOL PlazaGameSignWindow_Close(PlazaGameSignWindow *window);
static void PlazaGameSignWindow_Move(PlazaGameSignWindow *window, int delta);
static void PlazaGameSignWindow_Free(PlazaGameSignWindow *window);
static void PlazaGameSignWindow_UpdateLines(PlazaGameSignWindow *window);
static void PlazaGameSignWindow_CommitLinesTask(SysTask *task, void *data);
static void PlazaGameSignWindow_HBlank(void *data);
static void PlazaGameSign_CountdownTask(SysTask *task, void *data);
static void PlazaGameSign_FinishTask(SysTask *task, void *data);
static const void *PlazaGame_GetCommandTable(void);
static int PlazaGame_GetCommandCount(void);
static void PlazaGameResults_InitCommands(PlazaGameResults *results);
static void PlazaGameEntry_InitCommands(PlazaGameEntry *entry);

void PlazaGameRoster_Init(PlazaGameRoster *roster, u32 fromLobby, SaveData *saveData, u8 voiceChat, PlazaGameArgs *args) {
    int netId;
    int localNetId;
    int count;
    memset(roster, 0, sizeof(PlazaGameRoster));
    roster->count = CommPlayerInfo_CountAccepted();
    localNetId = Comm_GetLocalNetId();
    count = 0;
    for (netId = 0; netId < PLAZA_GAME_MAX_PLAYERS; netId++) {
        if (CommPlayerInfo_GetProfile(netId) != NULL) {
            if (localNetId == netId) {
                roster->localIndex = count;
            }
            roster->netIds[count] = netId;
            count++;
        }
    }
    GF_ASSERT(count == roster->count);
    if (fromLobby == 0) {
        roster->launchedFromField = TRUE;
    }
    roster->saveData = saveData;
    roster->voiceChat = voiceChat;
    roster->args = args;
}

int PlazaGameRoster_GetIndexOfNetId(const PlazaGameRoster *roster, u32 netId) {
    int i;
    for (i = 0; i < roster->count; i++) {
        if (netId == roster->netIds[i]) {
            return i;
        }
    }
    return 4;
}

static u8 PlazaGameRoster_GetNetId(const PlazaGameRoster *roster, u32 index) {
    GF_ASSERT(index < roster->count);
    return roster->netIds[index];
}

BOOL PlazaGameRoster_IsSpecialVisitor(const PlazaGameRoster *roster, u32 netId) {
    int index;
    if (netId >= PLAZA_GAME_MAX_PLAYERS) {
        GF_ASSERT(netId < PLAZA_GAME_MAX_PLAYERS);
        return FALSE;
    }
    index = roster->args->slots[netId];
    if (index == -1) {
        return FALSE;
    }
    return roster->args->specialVisitors[index];
}

PlayerProfile *PlazaGameRoster_GetProfile(const PlazaGameRoster *roster, u32 netId) {
    if (netId >= PLAZA_GAME_MAX_PLAYERS) {
        GF_ASSERT(netId < PLAZA_GAME_MAX_PLAYERS);
        return NULL;
    }
    if (roster->launchedFromField == 1) {
        int index = PlazaGameRoster_GetIndexOfNetId(roster, netId);
        return index == roster->localIndex ? Save_PlayerData_GetProfile(roster->saveData) : CommPlayerInfo_GetProfile(netId);
    } else {
        GF_ASSERT(roster->args != NULL);
        return roster->args->profiles[netId];
    }
}

PlazaGameEntry *PlazaGameEntry_NewSwalotPlop(const PlazaGameRoster *roster, enum HeapID heapId) {
    return PlazaGameEntry_New(roster, PLAZA_GAME_SWALOT_PLOP, heapId);
}

PlazaGameEntry *PlazaGameEntry_NewMimeJrTop(const PlazaGameRoster *roster, enum HeapID heapId) {
    return PlazaGameEntry_New(roster, PLAZA_GAME_MIME_JR_TOP, heapId);
}

PlazaGameEntry *PlazaGameEntry_NewWobbuffetPop(const PlazaGameRoster *roster, enum HeapID heapId) {
    return PlazaGameEntry_New(roster, PLAZA_GAME_WOBBUFFET_POP, heapId);
}

void PlazaGameEntry_Free(PlazaGameEntry *entry) {
    int i;
    SysTask_Destroy(entry->task);
    SysTask_Destroy(entry->vblankTask);
    PlazaGameLineScroll_Free(&entry->lineScroll);
    PlazaGameTitle_Free(&entry->title);
    for (i = 0; i < entry->roster.count; i++) {
        PlazaGamePlayer_Free(&entry->players[i]);
    }
    PlazaGameMessageBox_Free(&entry->messageBox);
    PlazaGameEntry_FreeGraphics(entry);
    PlazaGameText_Free(&entry->text);
    PlazaGameGfx_Free(&entry->gfx);
    PlazaGameSprites_Free(&entry->sprites);
    PlazaGameBg_Free(&entry->bg);
    Heap_Free(entry);
}

BOOL PlazaGameEntry_IsDone(const PlazaGameEntry *entry) {
    return entry->state >= PLAZA_GAME_ENTRY_DONE;
}

u8 PlazaGameEntry_GetSelection(const PlazaGameEntry *entry) {
    GF_ASSERT(entry->selectionReceived == 1);
    return entry->selection;
}

PlazaGameResults *PlazaGameResults_NewSwalotPlop(const PlazaGameRoster *roster, const PlazaGameResultData *data, enum HeapID heapId) {
    return PlazaGameResults_New(roster, data, PLAZA_GAME_SWALOT_PLOP, heapId);
}

PlazaGameResults *PlazaGameResults_NewMimeJrTop(const PlazaGameRoster *roster, const PlazaGameResultData *data, enum HeapID heapId) {
    return PlazaGameResults_New(roster, data, PLAZA_GAME_MIME_JR_TOP, heapId);
}

PlazaGameResults *PlazaGameResults_NewWobbuffetPop(const PlazaGameRoster *roster, const PlazaGameResultData *data, enum HeapID heapId) {
    return PlazaGameResults_New(roster, data, PLAZA_GAME_WOBBUFFET_POP, heapId);
}

void PlazaGameResults_Free(PlazaGameResults *results) {
    int i;
    SysTask_Destroy(results->task);
    SysTask_Destroy(results->vblankTask);
    PlazaGameLineScroll_Free(&results->lineScroll);
    for (i = 0; i < results->roster.count; i++) {
        PlazaGamePlayer_Free(&results->players[i]);
    }
    PlazaGameContinue_Free(&results->continuePrompt);
    PlazaGameResults_FreeGraphics(results);
    PlazaGameMessageBox_Free(&results->messageBox);
    PlazaGameText_Free(&results->text);
    PlazaGameGfx_Free(&results->gfx);
    PlazaGameSprites_Free(&results->sprites);
    PlazaGameBg_Free(&results->bg);
    G2_BlendNone();
    G2S_BlendNone();
    GF_DestroyVramTransferManager();
    Heap_Free(results);
}

u8 PlazaGameResults_IsDone(const PlazaGameResults *results) {
    return results->done;
}

u8 PlazaGameResults_GetContinue(const PlazaGameResults *results) {
    return results->continueResult;
}

void PlazaGame_CalcRanks(PlazaGameResultData *data, u32 count) {
    u8 order[4];
    int i;
    int j;
    for (i = 0; i < count; i++) {
        for (j = i; j > 0; j--) {
            if (data->scores[i] <= data->scores[order[j - 1]]) {
                break;
            }
            order[j] = order[j - 1];
        }
        order[j] = i;
    }
    for (i = 0; i < count; i++) {
        int rank = i;
        if (i > 0 && data->scores[order[i]] == data->scores[order[i - 1]]) {
            rank = data->ranks[order[i - 1]];
        }
        data->ranks[order[i]] = rank;
    }
}

static void PlazaGameEntry_SetSelection(PlazaGameEntry *entry, int selection) {
    entry->selection = selection;
    entry->selectionReceived = 1;
}

static void PlazaGameResults_ReceiveVote(PlazaGameResults *results, int netId, BOOL yes) {
    if (!results->roster.localIndex) {
        PlazaGameContinue_ReceiveVote(&results->continuePrompt, netId, yes, results->roster.count);
    }
}

static void PlazaGameResults_ReceiveContinue(PlazaGameResults *results, u8 result) {
    PlazaGameContinue_SetResult(&results->continuePrompt, result);
}

BOOL PlazaGameRoster_CheckConnectionLost(PlazaGameRoster *roster) {
    BOOL result = FALSE;

    if (roster->args != NULL) {
        if (roster->count != Comm_CountConnected()) {
            result = TRUE;
        }
        if (CommState_WasWifiDisconnected() == 1) {
            result = TRUE;
        }
        if (CommState_GetWifiMatchStatus() >= WIFI_MATCH_STATUS_OTHER) {
            result = TRUE;
        }
        if (result == TRUE) {
            roster->args->connectionLost = TRUE;
        }
        if (roster->args->connectionLost == TRUE) {
            result = TRUE;
        }
    }
    return result;
}

BOOL PlazaGameRoster_ProcessConnectionLost(PlazaGameRoster *roster) {
    GF_ASSERT(roster->args != NULL);
    GF_ASSERT(roster->args->connectionLost == TRUE);
    if (CommPlayerInfo_Exists() == TRUE) {
        CommPlayerInfo_Free();
        CommState_EndPlazaMatch();
    } else if (CommState_IsWifiInLobby() == TRUE) {
        return TRUE;
    }
    return FALSE;
}

PlazaGameSign *PlazaGameSign_New(SpriteList *spriteList, enum HeapID heapId) {
    PlazaGameSign *sign = Heap_Alloc(heapId, sizeof(PlazaGameSign));
    memset(sign, 0, sizeof(PlazaGameSign));
    sign->spriteList = spriteList;
    sign->narc = NARC_New(NARC_a_1_9_8, heapId);
    PlazaGameGfx_Init(&sign->gfx, 1, heapId);
    sign->gfxRes = PlazaGameGfx_Load(&sign->gfx, sign->narc, 3, 3, 2, 1, 0, 5000, heapId);
    return sign;
}

void PlazaGameSign_Free(PlazaGameSign *sign) {
    if (sign->task != NULL) {
        SysTask_Destroy(sign->task);
        sign->task = NULL;
    }
    if (sign->sprite != NULL) {
        Sprite_Delete(sign->sprite);
    }
    PlazaGameSignWindow_Free(&sign->window);
    PlazaGameGfx_Free(&sign->gfx);
    NARC_Delete(sign->narc);
    Heap_Free(sign);
}

int PlazaGameSign_GetPlttOffset(PlazaGameSign *sign) {
    return SpriteTransfer_GetPlttOffset(SpriteResourceCollection_Find(sign->gfx.managers[GF_GFX_RES_TYPE_PLTT], 5000), NNS_G2D_VRAM_TYPE_2DMAIN);
}

void PlazaGameSign_StartCountdown(PlazaGameSign *sign) {
    GF_ASSERT(sign->task == NULL);
    sign->task = SysTask_CreateOnMainQueue(PlazaGameSign_CountdownTask, sign, 0);
    sign->state = PLAZA_GAME_SIGN_CREATE;
}

void PlazaGameSign_StartFinish(PlazaGameSign *sign) {
    GF_ASSERT(sign->task == NULL);
    sign->task = SysTask_CreateOnMainQueue(PlazaGameSign_FinishTask, sign, 0);
    sign->state = PLAZA_GAME_SIGN_CREATE;
    PlaySE(SEQ_SE_DP_PINPON);
}

BOOL PlazaGameSign_IsDone(const PlazaGameSign *sign) {
    if (sign->state == PLAZA_GAME_SIGN_IDLE) {
        return TRUE;
    }
    return FALSE;
}

static void PlazaGameMotion_Init(PlazaGameMotion *motion, fx32 start, fx32 end, fx32 velocity, int duration) {
    fx32 distance = end - start - FX_Mul(velocity, duration << FX32_SHIFT);
    fx32 accel = FX_Div(FX_Mul(distance, 2 * FX32_ONE), (duration * duration) << FX32_SHIFT);
    motion->current = start;
    motion->start = start;
    motion->velocity = velocity;
    motion->accel = accel;
    motion->duration = duration;
}

static BOOL PlazaGameMotion_Update(PlazaGameMotion *motion, int frame) {
    BOOL done;
    fx32 linear;
    fx32 quadratic;
    if (frame >= motion->duration) {
        frame = motion->duration;
        done = TRUE;
    } else {
        done = FALSE;
    }
    linear = FX_Mul(motion->velocity, frame << FX32_SHIFT);
    quadratic = FX_Mul(motion->accel, (frame * frame) << FX32_SHIFT);
    quadratic = FX_Div(quadratic, 2 * FX32_ONE);
    motion->current = motion->start + (linear + quadratic);
    return done;
}

static void PlazaGame_OffsetScreenTiles(NNSG2dScreenData *screen, u16 offset) {
    int i;
    int count = screen->szByte / 2;
    u16 *tiles = (u16 *)screen->rawData;
    for (i = 0; i < count; i++) {
        tiles[i] += offset;
    }
}

static void PlazaGameGfx_Init(PlazaGameGfx *gfx, int count, enum HeapID heapId) {
    int i;
    for (i = 0; i < 4; i++) {
        gfx->managers[i] = Create2DGfxResObjMan(count, (GfGfxResType)i, heapId);
    }
    gfx->records = Heap_Alloc(heapId, count * sizeof(PlazaGameGfxRes));
    memset(gfx->records, 0, count * sizeof(PlazaGameGfxRes));
    gfx->count = count;
}

static void PlazaGameGfx_Free(PlazaGameGfx *gfx) {
    u32 i;
    for (i = 0; i < gfx->count; i++) {
        if (gfx->records[i].active == 1) {
            PlazaGameGfx_Unload(gfx, &gfx->records[i]);
        }
    }
    {
        int j;
        for (j = 0; j < 4; j++) {
            Destroy2DGfxResObjMan(gfx->managers[j]);
        }
    }
    Heap_Free(gfx->records);
}

static PlazaGameGfxRes *PlazaGameGfx_Load(PlazaGameGfx *gfx, NARC *narc, int plttFile, int plttCount, int charFile, int cellFile, int animFile, int id, enum HeapID heapId) {
    u32 i;
    PlazaGameGfxRes *gfxRes = NULL;
    for (i = 0; i < gfx->count; i++) {
        if (gfx->records[i].active == 0) {
            gfxRes = &gfx->records[i];
            break;
        }
    }
    GF_ASSERT(gfxRes != NULL);
    PlazaGameGfx_LoadInto(gfx, gfxRes, narc, plttFile, plttCount, charFile, cellFile, animFile, id, heapId);
    return gfxRes;
}

static Sprite *PlazaGameGfx_CreateSprite(PlazaGameGfxRes *gfxRes, SpriteList *spriteList, s16 x, s16 y, u16 priority, enum HeapID heapId) {
    SimpleSpriteTemplate template;
    template.spriteList = spriteList;
    template.header = &gfxRes->header;
    template.position.x = x << FX32_SHIFT;
    template.position.y = y << FX32_SHIFT;
    template.priority = priority;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.heapID = heapId;
    return Sprite_Create(&template);
}

static void PlazaGameGfx_LoadInto(PlazaGameGfx *gfx, PlazaGameGfxRes *gfxRes, NARC *narc, int plttFile, int plttCount, int charFile, int cellFile, int animFile, volatile int id, volatile enum HeapID heapId) {
    enum HeapID heap;
    int resId;
    GF_ASSERT(!gfxRes->active);
    gfxRes->active = 1;
    resId = id;
    heap = heapId;
    gfxRes->resources[GF_GFX_RES_TYPE_CHAR] = AddCharResObjFromOpenNarc(gfx->managers[GF_GFX_RES_TYPE_CHAR], narc, charFile, FALSE, resId, NNS_G2D_VRAM_TYPE_2DMAIN, heap);
    gfxRes->resources[GF_GFX_RES_TYPE_PLTT] = AddPlttResObjFromOpenNarc(gfx->managers[GF_GFX_RES_TYPE_PLTT], narc, plttFile, FALSE, resId, NNS_G2D_VRAM_TYPE_2DMAIN, plttCount, heap);
    gfxRes->resources[GF_GFX_RES_TYPE_CELL] = AddCellOrAnimResObjFromOpenNarc(gfx->managers[GF_GFX_RES_TYPE_CELL], narc, cellFile, FALSE, resId, GF_GFX_RES_TYPE_CELL, heap);
    gfxRes->resources[GF_GFX_RES_TYPE_ANIM] = AddCellOrAnimResObjFromOpenNarc(gfx->managers[GF_GFX_RES_TYPE_ANIM], narc, animFile, FALSE, resId, GF_GFX_RES_TYPE_ANIM, heap);
    GF_ASSERT(SpriteTransfer_CreateCharTransferTask_AllocAtEnd(gfxRes->resources[GF_GFX_RES_TYPE_CHAR]));
    GF2DGfxResObj_FreeData(gfxRes->resources[GF_GFX_RES_TYPE_CHAR]);
    GF_ASSERT(SpriteTransfer_CreatePlttTransferTask(gfxRes->resources[GF_GFX_RES_TYPE_PLTT]));
    GF2DGfxResObj_FreeData(gfxRes->resources[GF_GFX_RES_TYPE_PLTT]);
    CreateSpriteResourcesHeader(&gfxRes->header, resId, resId, resId, resId, -1, -1, FALSE, 1, gfx->managers[GF_GFX_RES_TYPE_CHAR], gfx->managers[GF_GFX_RES_TYPE_PLTT], gfx->managers[GF_GFX_RES_TYPE_CELL], gfx->managers[GF_GFX_RES_TYPE_ANIM], NULL, NULL);
}

static void PlazaGameGfx_Unload(PlazaGameGfx *gfx, PlazaGameGfxRes *gfxRes) {
    int i;
    GF_ASSERT(gfxRes->active == 1);
    gfxRes->active = 0;
    SpriteTransfer_DeleteCharTransferTask(gfxRes->resources[GF_GFX_RES_TYPE_CHAR]);
    SpriteTransfer_DeletePlttTransferTask(gfxRes->resources[GF_GFX_RES_TYPE_PLTT]);
    for (i = 0; i < 4; i++) {
        DestroySingle2DGfxResObj(gfx->managers[i], gfxRes->resources[i]);
    }
}

static void PlazaGameBg_Init(PlazaGameBg *bg, const GraphicsModes *modes, const PlazaGameBgTemplate *templates, u32 count, enum HeapID heapId) {
    u32 i;
    const PlazaGameBgTemplate *bgTemplate;
    const PlazaGameBgTemplate *current;
    SetBothScreensModesAndDisable(modes);
    bg->bgConfig = BgConfig_Alloc(heapId);
    bg->templates = templates;
    bg->count = count;
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    bgTemplate = templates;
    for (i = 0; i < count; i++) {
        current = &templates[i];
        InitBgFromTemplate(bg->bgConfig, current->bgId, &bgTemplate->template, GF_BG_TYPE_TEXT);
        BG_ClearCharDataRange(current->bgId, 0x20, 0, heapId);
        BgClearTilemapBufferAndCommit(bg->bgConfig, current->bgId);
        BgSetPosTextAndCommit(bg->bgConfig, current->bgId, BG_POS_OP_SET_X, 0);
        BgSetPosTextAndCommit(bg->bgConfig, current->bgId, BG_POS_OP_SET_Y, 0);
        bgTemplate++;
    }
}

static void PlazaGameBg_Free(PlazaGameBg *bg) {
    u32 i;
    BgSetPosTextAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SET_Y, 0);
    for (i = 0; i < bg->count; i++) {
        FreeBgTilemapBuffer(bg->bgConfig, bg->templates[i].bgId);
    }
    Heap_Free(bg->bgConfig);
}

static void PlazaGameBg_Update(PlazaGameBg *bg) {
    DoScheduledBgGpuUpdates(bg->bgConfig);
}

static void PlazaGameSprites_Init(PlazaGameSprites *sprites, int count, int charCount, int plttCount, enum HeapID heapId) {
    ObjCharTransferTemplate template;
    enum HeapID heap;
    NNS_G2dInitOamManagerModule();
    heap = *(volatile enum HeapID *)&heapId;
    OamManager_Create(0, 126, 0, 31, 0, 126, 0, 31, heap);
    template = gPlazaGameObjCharTransfer;
    template.maxTasks = charCount;
    template.heapID = heap;
    ObjCharTransfer_InitEx(&template, GX_OBJVRAMMODE_CHAR_1D_32K, GX_OBJVRAMMODE_CHAR_1D_32K);
    ObjPlttTransfer_Init(plttCount, heap);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
    G2dRenderer_SetObjCharTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN, GX_OBJVRAMMODE_CHAR_1D_32K);
    G2dRenderer_SetPlttTransferReservedRegion(NNS_G2D_VRAM_TYPE_2DMAIN);
    sprites->spriteList = G2dRenderer_Init(count, &sprites->renderer, heap);
    WirelessStatusIcon_Create();
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
    GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
}

static void PlazaGameSprites_Free(PlazaGameSprites *sprites) {
    SpriteList_Delete(sprites->spriteList);
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
    OamManager_Free();
}

static void PlazaGameSprites_Update(PlazaGameSprites *sprites) {
    SpriteList_RenderAndAnimateSprites(sprites->spriteList);
}

static void PlazaGameSprites_ApplyOam(PlazaGameSprites *sprites) {
    OamManager_ApplyAndResetBuffers();
}

static void PlazaGameText_Init(PlazaGameText *text, enum HeapID heapId) {
    text->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0236_bin, heapId);
    text->msgFormat = MessageFormat_New_Custom(8, 64, heapId);
    text->string = String_New(128, heapId);
    text->buffer = String_New(128, heapId);
    LoadFontPal1(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_12_OFFSET, heapId);
    LoadFontPal1(GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_12_OFFSET, heapId);
}

static void PlazaGameText_Free(PlazaGameText *text) {
    String_Delete(text->buffer);
    String_Delete(text->string);
    MessageFormat_Delete(text->msgFormat);
    DestroyMsgData(text->msgData);
}

static void PlazaGameText_ResetBuffers(PlazaGameText *text) {
    MessageFormat_ResetBuffers(text->msgFormat);
}

static void PlazaGameText_BufferPlayerName(PlazaGameText *text, PlayerProfile *profile) {
    BufferPlayersName(text->msgFormat, 0, profile);
}

static void PlazaGameText_BufferCountry(PlazaGameText *text, int country) {
    BufferCountryName(text->msgFormat, 0, country);
}

static void PlazaGameText_BufferCity(PlazaGameText *text, int country, int region) {
    BufferCityName(text->msgFormat, 0, country, region);
}

static void PlazaGameText_BufferNumber(PlazaGameText *text, int value, int digits) {
    BufferIntegerAsString(text->msgFormat, 0, value, digits, PRINTING_MODE_RIGHT_ALIGN, TRUE);
}

static void PlazaGameText_BufferTwoDigitNumber(PlazaGameText *text, int value) {
    BufferIntegerAsString(text->msgFormat, 0, value, 2, PRINTING_MODE_RIGHT_ALIGN, TRUE);
}

static void PlazaGameText_BufferTapToyName(PlazaGameText *text, int tapToy) {
    BufferWiFiPlazaInstrumentName(text->msgFormat, 1, tapToy);
}

static void PlazaGameText_BufferActivityName(PlazaGameText *text, int game) {
    BufferWiFiPlazaActivityName(text->msgFormat, 0, game);
}

static void PlazaGameText_Format(PlazaGameText *text, String *dest, int msgNo) {
    ReadMsgDataIntoString(text->msgData, msgNo, text->buffer);
    StringExpandPlaceholders(text->msgFormat, dest, text->buffer);
}

static void PlazaGameText_Print(PlazaGameText *text, int msgNo, Window *window, u8 x, u8 y) {
    PlazaGameText_PrintWithColor(text, msgNo, window, x, y, MAKE_TEXT_COLOR(15, 14, 0));
}

static int PlazaGameText_PrintRightAligned(PlazaGameText *text, int msgNo, Window *window, u8 right, u8 y) {
    int x;
    ReadMsgDataIntoString(text->msgData, msgNo, text->buffer);
    StringExpandPlaceholders(text->msgFormat, text->string, text->buffer);
    x = right - FontID_String_GetWidth(0, text->string, 0);
    if (x < 0) {
        x = 0;
    }
    return AddTextPrinterParameterizedWithColor(window, 0, text->string, x, y, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
}

static int PlazaGameText_PrintMessage(PlazaGameText *text, int msgNo, Window *window, String *string, int textSpeed) {
    ReadMsgDataIntoString(text->msgData, msgNo, text->buffer);
    StringExpandPlaceholders(text->msgFormat, string, text->buffer);
    return AddTextPrinterParameterizedWithColor(window, 1, string, 0, 0, textSpeed, MAKE_TEXT_COLOR(1, 2, 15), NULL);
}

static int PlazaGameText_PrintWithColor(PlazaGameText *text, int msgNo, Window *window, u8 x, u8 y, u32 color) {
    ReadMsgDataIntoString(text->msgData, msgNo, text->buffer);
    StringExpandPlaceholders(text->msgFormat, text->string, text->buffer);
    return AddTextPrinterParameterizedWithColor(window, 0, text->string, x, y, TEXT_SPEED_NOTRANSFER, color, NULL);
}

static void PlazaGameMessageBox_Init(PlazaGameMessageBox *messageBox, PlazaGameBg *bg, SaveData *saveData, u32 colorVariant, enum HeapID heapId) {
    int frame = Options_GetFrame(Save_PlayerData_GetOptionsAddr(saveData));
    Window *window;
    int i;
    TextFlags_BeginAutoScroll(TRUE);
    LoadUserFrameGfx2(bg->bgConfig, GF_BG_LYR_MAIN_2, 1, 13, frame, heapId);
    LoadUserFrameGfx2(bg->bgConfig, GF_BG_LYR_SUB_0, 1, 13, frame, heapId);
    window = messageBox->windows;
    i = 0;
    do {
        GFBgLayer bgId;
        u8 y;
        if (i == 0) {
            bgId = GF_BG_LYR_MAIN_2;
            y = 19;
        } else {
            bgId = GF_BG_LYR_SUB_0;
            y = 1;
        }
        AddWindowParameterized(bg->bgConfig, window, bgId, 2, y, 27, 4, 12, 31);
        FillWindowPixelBuffer(window, 0);
        messageBox->strings[i] = String_New(128, heapId);
        window++;
        i++;
    } while (i < 2);
    messageBox->colorVariant = colorVariant;
}

static void PlazaGameMessageBox_Free(PlazaGameMessageBox *messageBox) {
    int i = 0;
    do {
        PlazaGameMessageBox_Hide(messageBox, i);
        String_Delete(messageBox->strings[i]);
        RemoveWindow(&messageBox->windows[i]);
        i++;
    } while (i < 2);
    TextFlags_EndAutoScroll();
}

static void PlazaGameMessageBox_Show(PlazaGameMessageBox *messageBox, PlazaGameText *text, int msgNo, int index) {
    u32 i;
    u16 printerId;
    Window *window;

    if (messageBox->colorVariant == 1) {
        for (i = 0; i < NELEMS(gPlazaGameAltMessages); i++) {
            if (msgNo == gPlazaGameAltMessages[i][0]) {
                msgNo = gPlazaGameAltMessages[i][1];
            }
        }
    }
    printerId = messageBox->printerIds[index];
    if (TextPrinterCheckActive(printerId)) {
        RemoveTextPrinter(messageBox->printerIds[index]);
    }
    PlazaGameMessageBox_HideWaitingIcon(messageBox, index);
    window = &messageBox->windows[index];
    FillWindowPixelBuffer(window, 15);
    messageBox->printerIds[index] = PlazaGameText_PrintMessage(text, msgNo, window, messageBox->strings[index], 1);
    DrawFrameAndWindow2(window, TRUE, 1, 13);
    ScheduleWindowCopyToVram(window);
}

static void PlazaGameMessageBox_Hide(PlazaGameMessageBox *messageBox, int index) {
    PlazaGameMessageBox_HideWaitingIcon(messageBox, index);
    if (TextPrinterCheckActive(messageBox->printerIds[index])) {
        RemoveTextPrinter(messageBox->printerIds[index]);
    }
    ClearFrameAndWindow2(&messageBox->windows[index], TRUE);
    ClearWindowTilemapAndScheduleTransfer(&messageBox->windows[index]);
}

static BOOL PlazaGameMessageBox_IsPrinterFinished(PlazaGameMessageBox *messageBox, int index) {
    if (!TextPrinterCheckActive(messageBox->printerIds[index])) {
        return TRUE;
    }
    return FALSE;
}

static void PlazaGameMessageBox_ShowWaitingIcon(PlazaGameMessageBox *messageBox, int index) {
    WaitingIcon **waitingIcon = &messageBox->waitingIcons[index];
    if (*waitingIcon == NULL) {
        *waitingIcon = WaitingIcon_New(&messageBox->windows[index], 1);
    }
}

static void PlazaGameMessageBox_HideWaitingIcon(PlazaGameMessageBox *messageBox, int index) {
    if (messageBox->waitingIcons[index] != NULL) {
        WaitingIcon_DeleteWithoutRestore(messageBox->waitingIcons[index]);
        messageBox->waitingIcons[index] = NULL;
    }
}

static PlazaGameEntry *PlazaGameEntry_New(const PlazaGameRoster *roster, u16 game, enum HeapID heapId) {
    PlazaGameEntry *entry;
    Sound_SetSceneAndPlayBGM(19, SEQ_GS_WIFIGAME, 0);
    entry = Heap_Alloc(heapId, sizeof(PlazaGameEntry));
    memset(entry, 0, sizeof(PlazaGameEntry));
    memcpy(&entry->roster, roster, sizeof(PlazaGameRoster));
    entry->game = game;
    G2_BlendNone();
    G2S_BlendNone();
    reg_GX_DISPCNT &= ~(REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK);
    reg_GXS_DB_DISPCNT &= ~(REG_GXS_DB_DISPCNT_W0_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_OW_MASK);
    GfGfx_SetBanks(&gPlazaGameEntryBanks);
    entry->heapId = heapId;
    PlazaGameEntry_InitCommands(entry);
    PlazaGamePlayerInfo_Init(&entry->info, &entry->roster);
    PlazaGameBg_Init(&entry->bg, &gPlazaGameEntryGraphicsModes, gPlazaGameEntryBgTemplates, 5, heapId);
    PlazaGameSprites_Init(&entry->sprites, 16, 1, 1, heapId);
    PlazaGameGfx_Init(&entry->gfx, 1, heapId);
    PlazaGameText_Init(&entry->text, heapId);
    PlazaGameEntry_LoadGraphics(entry, heapId);
    PlazaGameMessageBox_Init(&entry->messageBox, &entry->bg, entry->roster.saveData, PlazaGameRoster_IsSpecialVisitor(&entry->roster, PlazaGameRoster_GetNetId(&entry->roster, entry->roster.localIndex)), heapId);
    entry->task = SysTask_CreateOnMainQueue(PlazaGameEntry_MainTask, entry, 0);
    entry->vblankTask = SysTask_CreateOnVWaitQueue(PlazaGameEntry_VBlankTask, entry, 0);
    if (entry->roster.voiceChat) {
        WifiConnection_StartVoiceChat(heapId);
    }
    {
        GameStats *gameStats = Save_GameStats_Get(entry->roster.saveData);
        if (entry->roster.launchedFromField) {
            GameStats_AddScore(gameStats, 39);
        }
    }
    return entry;
}

static void PlazaGameEntry_LoadGraphics(PlazaGameEntry *entry, enum HeapID heapId) {
    NARC *narc = NARC_New(NARC_a_1_9_8, heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x120, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 6, entry->bg.bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapId);
    entry->screenRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 9, FALSE, &entry->screen, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 8, entry->bg.bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, heapId);
    PlazaGame_LoadGamePalette(narc, entry->game, heapId);
    entry->gfxRes = PlazaGameGfx_Load(&entry->gfx, narc, 11, 5, 12, 13, 14, 5000, heapId);
    PlazaGameTitle_Init(&entry->title, &entry->bg, &entry->text, entry->game, narc, heapId);
    NARC_Delete(narc);
}

static void PlazaGameEntry_FreeGraphics(PlazaGameEntry *entry) {
    Heap_Free(entry->screenRaw);
}

static void PlazaGameEntry_MainTask(SysTask *task, void *data) {
    PlazaGameEntry *entry = data;
    u32 selection;
    int i;
    int showCountries;
    switch (entry->state) {
    case PLAZA_GAME_ENTRY_FADE_IN:
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0xFFFF, 6, 1, (enum HeapID)entry->heapId);
        PlazaGameTitle_StartSlideIn(&entry->title, &entry->bg, (enum HeapID)entry->heapId);
        entry->state++;
        break;
    case PLAZA_GAME_ENTRY_WAIT_FADE_IN:
        PlazaGameTitle_UpdateSlideIn(&entry->title, &entry->bg);
        if (IsPaletteFadeFinished() == TRUE) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_WAIT_TITLE:
        if (PlazaGameTitle_UpdateSlideIn(&entry->title, &entry->bg) == TRUE) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_PRINT_ACCEPTED:
        PlazaGameMessageBox_Show(&entry->messageBox, &entry->text, msg_0236_00000, 0);
        entry->state++;
        break;
    case PLAZA_GAME_ENTRY_WAIT_ACCEPTED:
        if (PlazaGameMessageBox_IsPrinterFinished(&entry->messageBox, 0)) {
            entry->state++;
            entry->timer = 64;
        }
        break;
    case PLAZA_GAME_ENTRY_HIDE_ACCEPTED:
        if (entry->timer != 0) {
            entry->timer--;
            if (entry->timer == 0) {
                PlazaGameMessageBox_Hide(&entry->messageBox, 0);
                PlazaGameTitle_StartSlideOut(&entry->title, &entry->bg);
                entry->state++;
            }
        }
        break;
    case PLAZA_GAME_ENTRY_WAIT_TITLE_SLIDE_OUT:
        if (PlazaGameTitle_UpdateSlideOut(&entry->title, &entry->bg) == TRUE) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_SHOW_PLAYERS:
        PlazaGameLineScroll_Init(&entry->lineScroll, &entry->bg, (enum HeapID)entry->heapId);
        showCountries = PlazaGamePlayerInfo_HasDifferentCountries(&entry->roster, entry->info.countries);
        for (i = 0; i < entry->roster.count; i++) {
            PlazaGamePlayer_Init(&entry->players[i], entry->roster.count, entry->game, entry->screen, &entry->bg, i, entry->roster.localIndex, &entry->sprites, entry->gfxRes, (enum HeapID)entry->heapId);
            PlazaGamePlayer_PrintName(&entry->players[i], &entry->text, entry->info.profiles[i], 8, 0, PlazaGameRoster_IsSpecialVisitor(&entry->roster, PlazaGameRoster_GetNetId(&entry->roster, i)));
            PlazaGamePlayer_PrintLocation(&entry->players[i], &entry->text, showCountries, entry->info.countries[i], entry->info.regions[i], 8);
            PlazaGamePlayer_StartSlideIn(&entry->players[i], -8, i * 3);
        }
        for (i = 0; i < entry->roster.count; i++) {
            PlazaGamePlayer_ScheduleTransfer(&entry->players[i], &entry->bg);
            PlazaGamePlayer_ShowSprite(&entry->players[i]);
        }
        entry->timer = 92;
        entry->state++;
        break;
    case PLAZA_GAME_ENTRY_WAIT_PLAYERS:
        if (PlazaGameEntry_UpdatePlayers(entry) == TRUE) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_START_SYNC:
        entry->timer--;
        if (entry->timer == 0) {
            entry->state++;
            LinkSync_StartSync(0x81);
            if (entry->roster.voiceChat) {
                WifiConnection_StopVoiceChat();
            }
        }
        break;
    case PLAZA_GAME_ENTRY_WAIT_SYNC:
        if (LinkSync_IsSynced(0x81)) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_SLIDE_OUT_PLAYERS:
        for (i = 0; i < entry->roster.count; i++) {
            PlazaGamePlayer_StartSlideOut(&entry->players[i], i * 3);
        }
        entry->state++;
        entry->timer = 8;
        break;
    case PLAZA_GAME_ENTRY_WAIT_PLAYERS_SLIDE_OUT:
        entry->timer--;
        PlazaGameEntry_UpdatePlayers(entry);
        if (entry->timer == 0) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_FADE_OUT:
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, (enum HeapID)entry->heapId);
        PlazaGameEntry_UpdatePlayers(entry);
        if (entry->roster.localIndex == 0) {
            switch (entry->game) {
            case PLAZA_GAME_SWALOT_PLOP:
                selection = PlazaGame_PickWeighted(gPlazaGameSwalotPlopSelectionWeights, 3);
                break;
            case PLAZA_GAME_MIME_JR_TOP:
                selection = PlazaGame_PickWeighted(gPlazaGameMimeJrTopSelectionWeights, 2);
                break;
            case PLAZA_GAME_WOBBUFFET_POP:
                selection = PlazaGame_PickWeighted(gPlazaGameWobbuffetPopSelectionWeights, 3);
                break;
            }
            Comm_SendCommand(PLAZA_GAME_CMD_SELECTION, &selection, sizeof(selection));
        }
        entry->state++;
        break;
    case PLAZA_GAME_ENTRY_WAIT_FADE_OUT:
        PlazaGameEntry_UpdatePlayers(entry);
        if (IsPaletteFadeFinished() == TRUE) {
            PlazaGameLineScroll_Free(&entry->lineScroll);
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_WAIT_SELECTION:
        if (entry->selectionReceived == 1) {
            entry->state++;
        }
        break;
    case PLAZA_GAME_ENTRY_DONE:
        break;
    }
    PlazaGameSprites_Update(&entry->sprites);
    ScheduleSetBgPosText(entry->bg.bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_Y, 2);
    ScheduleSetBgPosText(entry->bg.bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_ADD_Y, 2);
}

static void PlazaGameEntry_VBlankTask(SysTask *task, void *data) {
    PlazaGameEntry *entry = data;
    PlazaGameBg_Update(&entry->bg);
    PlazaGameSprites_ApplyOam(&entry->sprites);
    PlazaGameLineScroll_Swap(&entry->lineScroll);
}

static u32 PlazaGame_PickWeighted(const u8 *weights, u32 count) {
    u32 random = MTRandom() % 100;
    u32 sum = 0;
    u32 i;

    for (i = 0; i < count; i++) {
        sum += weights[i];
        if (sum > random) {
            return i;
        }
    }
    GF_ASSERT(FALSE);
    return count - 1;
}

static BOOL PlazaGameEntry_UpdatePlayers(PlazaGameEntry *entry) {
    int i;
    BOOL allDone;
    allDone = TRUE;
    i = 0;
    if (i < entry->roster.count) {
        PlazaGamePlayer *player = entry->players;
        u8 *row = (u8 *)entry;
        PlazaGamePlayer *scrollPlayer = player;
        do {
            if (((PlazaGameEntry *)row)->players[0].sprite != NULL) {
                BOOL done = PlazaGamePlayer_UpdateSlide(player);
                PlazaGameLineScroll_SetPlayer(&entry->lineScroll, scrollPlayer);
                if (!done) {
                    allDone = FALSE;
                }
            } else {
                allDone = FALSE;
            }
            row += sizeof(PlazaGamePlayer);
            player++;
            scrollPlayer++;
            i++;
        } while (i < entry->roster.count);
    }
    return allDone;
}

static void PlazaGamePlayer_Init(PlazaGamePlayer *player, int count, int game, NNSG2dScreenData *screen, PlazaGameBg *bg, int index, u32 localIndex, PlazaGameSprites *sprites, PlazaGameGfxRes *gfxRes, enum HeapID heapId) {
    u32 tableOffset;
    int row;
    int anim;
    int y;
    int seat;
    s16 spriteY;

    switch (game) {
    case PLAZA_GAME_SWALOT_PLOP:
    case PLAZA_GAME_WOBBUFFET_POP:
        seat = PlazaGame_GetRelativeSeat(count, index, localIndex);
        break;
    case PLAZA_GAME_MIME_JR_TOP:
        if (localIndex > index) {
            seat = index + 1;
        } else if (localIndex == index) {
            seat = 0;
        } else {
            seat = index;
        }
        break;
    default:
        seat = index;
        break;
    }
    SetBgPriority(GF_BG_LYR_MAIN_1, 2);
    SetBgPriority(GF_BG_LYR_MAIN_0, 1);
    tableOffset = count * 12;
    row = ((const u8 *)gPlazaGameSeatRowsByCount + tableOffset)[seat];
    AddWindowParameterized(bg->bgConfig, &player->window, GF_BG_LYR_MAIN_0, 5, row + 1, 26, 4, 12, index * 104 + 513);
    FillWindowPixelBuffer(&player->window, 0);
    CopyToBgTilemapRect(bg->bgConfig, GF_BG_LYR_MAIN_1, 0, row, 32, 6, screen->rawData, 0, ((const u8 *)gPlazaGameScreenRowsByCount + tableOffset)[index], screen->screenWidth >> 3, screen->screenHeight >> 3);
    y = row * 8;
    anim = ((const u8 *)gPlazaGameSeatAnimsByCount + tableOffset)[seat];
    spriteY = gPlazaGamePlayerSpriteY[anim * 2];
    Sprite_SetAnimCtrlSeq(player->sprite = PlazaGameGfx_CreateSprite(gfxRes, sprites->spriteList, (u8)gPlazaGamePlayerSpritePositions[anim * 2], (u8)(spriteY + y), 0, heapId), anim);
    Sprite_SetPalOffset(player->sprite, index);
    Sprite_SetDrawFlag(player->sprite, FALSE);
    Sprite_SetAnimActiveFlag(player->sprite, TRUE);
    y += 21;
    player->rankSprite = PlazaGameGfx_CreateSprite(gfxRes, sprites->spriteList, 24, (u8)y, 0, heapId);
    Sprite_SetAnimCtrlSeq(player->rankSprite, 0);
    Sprite_SetDrawFlag(player->rankSprite, FALSE);
    player->index = index;
    player->seat = seat;
    player->count = count;
}

static void PlazaGamePlayer_PrintName(PlazaGamePlayer *player, PlazaGameText *text, PlayerProfile *profile, int x, s16 y, int highlight) {
    PlazaGameText_BufferPlayerName(text, profile);
    if (highlight == 1) {
        PlazaGameText_PrintWithColor(text, msg_0236_00010, &player->window, x, y, MAKE_TEXT_COLOR(5, 6, 0));
    } else {
        PlazaGameText_Print(text, msg_0236_00010, &player->window, x, y);
    }
}

static void PlazaGamePlayer_PrintLocation(PlazaGamePlayer *player, PlazaGameText *text, int showCountry, int country, int region, s16 x) {
    if (showCountry != 0) {
        if (country != 0) {
            PlazaGameText_ResetBuffers(text);
            PlazaGameText_BufferCountry(text, country);
            PlazaGameText_Print(text, msg_0236_00011, &player->window, x, 16);
        }
    } else {
        if (country != 0) {
            PlazaGameText_ResetBuffers(text);
            PlazaGameText_BufferCity(text, country, region);
            PlazaGameText_Print(text, msg_0236_00012, &player->window, x, 16);
        }
    }
}

static void PlazaGamePlayer_ShowRank(PlazaGamePlayer *player, int rank) {
    Sprite_SetDrawFlag(player->rankSprite, TRUE);
    Sprite_SetAnimCtrlSeq(player->rankSprite, rank + 4);
    Sprite_SetAnimActiveFlag(player->rankSprite, TRUE);
}

static void PlazaGamePlayer_PrintScore(PlazaGamePlayer *player, PlazaGameText *text, int score, int right, s16 y, int digits) {
    PlazaGameText_BufferNumber(text, score, digits);
    if (digits == 5) {
        PlazaGameText_PrintRightAligned(text, msg_0236_00014, &player->window, right, y);
    } else {
        PlazaGameText_PrintRightAligned(text, msg_0236_00013, &player->window, right, y);
    }
}

static void PlazaGamePlayer_ScheduleTransfer(PlazaGamePlayer *player, PlazaGameBg *bg) {
    ScheduleWindowCopyToVram(&player->window);
    ScheduleBgTilemapBufferTransfer(bg->bgConfig, GF_BG_LYR_MAIN_1);
}

static void PlazaGamePlayer_ShowSprite(PlazaGamePlayer *player) {
    Sprite_SetDrawFlag(player->sprite, TRUE);
}

static void PlazaGamePlayer_Free(PlazaGamePlayer *player) {
    if (player->sprite != NULL) {
        Sprite_Delete(player->sprite);
        player->sprite = NULL;
    }
    if (player->rankSprite != NULL) {
        Sprite_Delete(player->rankSprite);
        player->rankSprite = NULL;
    }
    if (WindowIsInUse(&player->window) == TRUE) {
        RemoveWindow(&player->window);
    }
}

static void PlazaGamePlayer_StartSlideIn(PlazaGamePlayer *player, int x, s16 delay) {
    float end;
    if (x > 0) {
        end = 0.5f + (float)(x << FX32_SHIFT);
    } else {
        end = (float)(x << FX32_SHIFT) - 0.5f;
    }
    PlazaGameMotion_Init(&player->motion, -255 * FX32_ONE, (int)end, 28 * FX32_ONE, 8);
    player->frame = 0;
    player->delay = delay;
    player->se = SEQ_SE_PL_MNGM_IN;
    PlazaGamePlayer_SetSpritePos(player, -(player->motion.current >> FX32_SHIFT));
}

static void PlazaGamePlayer_StartSlideOut(PlazaGamePlayer *player, s16 delay) {
    PlazaGameMotion_Init(&player->motion, player->motion.current, -255 * FX32_ONE, 0, 8);
    player->frame = 0;
    player->delay = delay;
    player->se = SEQ_SE_PL_MNGM_OUT;
    PlazaGamePlayer_SetSpritePos(player, -(player->motion.current >> FX32_SHIFT));
}

static BOOL PlazaGamePlayer_UpdateSlide(PlazaGamePlayer *player) {
    BOOL done;
    if (player->delay <= 0) {
        if (player->frame == 0) {
            PlaySE(player->se);
        }
        player->frame++;
        done = PlazaGameMotion_Update(&player->motion, player->frame);
        PlazaGamePlayer_SetSpritePos(player, -(player->motion.current >> FX32_SHIFT));
        return done;
    } else {
        player->delay--;
        return FALSE;
    }
}

static void PlazaGamePlayer_SetSpritePos(PlazaGamePlayer *player, u32 x) {
    VecFx32 pos;
    const u8(*rows)[12] = gPlazaGameSeatRows;
    u32 table = player->count - 1;
    const u8(*anims)[12] = gPlazaGameSeatAnims;
    u8 anim = anims[table][player->seat];
    u8 y = gPlazaGamePlayerSpriteY[anim * 2] + rows[table][player->seat] * 8;
    u8 spriteX = gPlazaGamePlayerSpritePositions[anim * 2];
    pos.x = (spriteX + x) << FX32_SHIFT;
    pos.y = y << FX32_SHIFT;
    Sprite_SetMatrix(player->sprite, &pos);
    x += 24;
    table = player->count - 1;
    y = rows[table][player->seat] * 8 + 21;
    pos.x = x << FX32_SHIFT;
    pos.y = y << FX32_SHIFT;
    Sprite_SetMatrix(player->rankSprite, &pos);
}

static int PlazaGame_GetRelativeSeat(u32 count, int index, u32 localIndex) {
    int localSeat;
    int seat;
    u32 i;
    int result;
    for (i = 0; i < count; i++) {
        if (index == gPlazaGameSeatOrders[count - 1][i]) {
            seat = i;
        }
        if (localIndex == gPlazaGameSeatOrders[count - 1][i]) {
            localSeat = i;
        }
    }
    result = seat - localSeat;
    if (result < 0) {
        result += count;
    }
    return result;
}

static void PlazaGameLineScroll_Init(PlazaGameLineScroll *lineScroll, PlazaGameBg *bg, enum HeapID heapId) {
    int i;

    GF_ASSERT(lineScroll->buffer == NULL);
    lineScroll->bg = bg;
    BgSetPosTextAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, -255);
    BgSetPosTextAndCommit(lineScroll->bg->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, -255);
    for (i = 0; i < 2; i++) {
        MIi_CpuClear16(0xFF01, lineScroll->buffers[i], sizeof(lineScroll->buffers[i]));
    }
    lineScroll->buffer = DoubleBuffer_New(heapId, lineScroll->buffers[0], lineScroll->buffers[1]);
    DoubleBuffer_SetEnabled(lineScroll->buffer, 0);
    Main_SetHBlankIntrCB(PlazaGameLineScroll_HBlank, lineScroll);
}

static void PlazaGameLineScroll_Free(PlazaGameLineScroll *lineScroll) {
    if (lineScroll->buffer != NULL) {
        Main_SetHBlankIntrCB(NULL, NULL);
        DoubleBuffer_Delete(lineScroll->buffer);
        lineScroll->buffer = NULL;
    }
}

static void PlazaGameLineScroll_SetPlayer(PlazaGameLineScroll *lineScroll, PlazaGamePlayer *player) {
    u16 *lines;
    int i;
    int stride;
    GF_ASSERT(lineScroll->buffer);
    lines = DoubleBuffer_GetCurrent(lineScroll->buffer);
    stride = 12;
    for (i = 0; i < 48; i++) {
        int offset = i - 1;
        int line = offset + gPlazaGameSeatRows[player->count - 1][player->seat] * 8;
        if (line < 0) {
            line += 192;
        }
        lines[line] = player->motion.current >> FX32_SHIFT;
    }
    DoubleBuffer_SetEnabled(lineScroll->buffer, 1);
}

static void PlazaGameLineScroll_Swap(PlazaGameLineScroll *lineScroll) {
    DoubleBuffer *buffer = lineScroll->buffer;
    if (buffer != NULL) {
        DoubleBuffer_Swap(buffer);
        DoubleBuffer_SetEnabled(lineScroll->buffer, 0);
    }
}

static void PlazaGameLineScroll_HBlank(void *data) {
    PlazaGameLineScroll *lineScroll = data;
    s16 *values;
    s32 line = reg_GX_VCOUNT;

    if (line < 192) {
        values = DoubleBuffer_GetOther(lineScroll->buffer);
        if ((reg_GX_DISPSTAT & REG_GX_DISPSTAT_HBLK_MASK) != 0) {
            BgSetPosTextAndCommit(lineScroll->bg->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, values[line]);
            BgSetPosTextAndCommit(lineScroll->bg->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, values[line]);
        }
    }
}

static void PlazaGamePlayerInfo_Init(PlazaGamePlayerInfo *info, const PlazaGameRoster *roster) {
    int i;
    for (i = 0; i < roster->count; i++) {
        info->profiles[i] = PlazaGameRoster_GetProfile(roster, roster->netIds[i]);
        GF_ASSERT(info->profiles[i]);
        info->countries[i] = CommPlayerInfo_GetCountry(roster->netIds[i]);
        info->regions[i] = CommPlayerInfo_GetRegion(roster->netIds[i]);
    }
}

static int PlazaGamePlayerInfo_HasDifferentCountries(const PlazaGameRoster *roster, const u8 *countries) {
    int i;
    int result;
    result = 0;
    i = 0;
    for (; i < roster->count - 1; i++) {
        int next = countries[i + 1];
        int current = countries[i];
        if (current == next && current != 0 && next != 0) {
        } else {
            result = 1;
        }
    }
    return result;
}

static u32 PlazaGame_GetPoweredUpTapToy(u32 tapToy) {
    u32 level = tapToy % 3;
    u32 kind = tapToy / 3;
    if (level + 1 < 3) {
        level++;
    }
    kind += kind * 2;
    kind += level;
    return kind;
}

static void PlazaGameTitle_Init(PlazaGameTitle *title, PlazaGameBg *bg, PlazaGameText *text, int game, NARC *narc, enum HeapID heapId) {
    AddWindowParameterized(bg->bgConfig, &title->window, GF_BG_LYR_MAIN_1, 6, 11, 20, 10, 8, 513);
    FillWindowPixelBuffer(&title->window, 0);
    title->string = String_New(128, heapId);
    PlazaGameText_BufferActivityName(text, game);
    PlazaGameText_Format(text, title->string, msg_0236_00016);
    title->game = game;
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 7, bg->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 10, bg->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, FALSE, heapId);
}

static void PlazaGameTitle_Free(PlazaGameTitle *title) {
    RemoveWindow(&title->window);
    String_Delete(title->string);
}

static void PlazaGameTitle_StartSlideIn(PlazaGameTitle *title, PlazaGameBg *bg, enum HeapID heapId) {
    u32 width;
    title->frame = 0;
    title->state = PLAZA_GAME_TITLE_SLIDE_IN;
    PlazaGameMotion_Init(&title->motion, gPlazaGameTitleSlideInStartX[title->game], gPlazaGameTitleRestX[title->game], gPlazaGameTitleSlideInVelocity[title->game], 16);
    PlazaGameTitle_SetScroll(title, bg, title->motion.current >> FX32_SHIFT);
    FontID_Alloc(2, heapId);
    width = FontID_String_GetWidth(2, title->string, 0);
    AddTextPrinterParameterizedWithColor(&title->window, 2, title->string, 80 - (width >> 1), 0, TEXT_SPEED_INSTANT, gPlazaGameTitleColors[title->game], NULL);
    FontID_Release(2);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
}

static void PlazaGameTitle_StartSlideOut(PlazaGameTitle *title, PlazaGameBg *bg) {
    title->frame = 0;
    title->state = PLAZA_GAME_TITLE_SLIDE_OUT;
    PlazaGameMotion_Init(&title->motion, gPlazaGameTitleRestX[title->game], gPlazaGameTitleSlideOutEndX[title->game], gPlazaGameTitleSlideOutVelocity[title->game], 8);
    PlazaGameTitle_ScheduleScroll(title, bg, title->motion.current >> FX32_SHIFT);
}

static BOOL PlazaGameTitle_UpdateSlideIn(PlazaGameTitle *title, PlazaGameBg *bg) {
    BOOL done;

    switch (title->state) {
    case PLAZA_GAME_TITLE_SLIDE_IN:
        done = PlazaGameMotion_Update(&title->motion, title->frame);
        PlazaGameTitle_ScheduleScroll(title, bg, title->motion.current >> FX32_SHIFT);
        title->frame++;
        if (done == 1) {
            PlaySE(SEQ_SE_PL_FCALL);
            PlazaGameMotion_Init(&title->motion, gPlazaGameTitleRestX[title->game], gPlazaGameTitleBounceX[title->game], gPlazaGameTitleBounceOutVelocity[title->game], 4);
            title->state++;
            title->frame = 0;
        }
        break;
    case PLAZA_GAME_TITLE_BOUNCE_OUT:
        done = PlazaGameMotion_Update(&title->motion, title->frame);
        PlazaGameTitle_ScheduleScroll(title, bg, title->motion.current >> FX32_SHIFT);
        title->frame++;
        if (done == 1) {
            PlazaGameMotion_Init(&title->motion, gPlazaGameTitleBounceX[title->game], gPlazaGameTitleRestX[title->game], gPlazaGameTitleBounceBackVelocity[title->game], 4);
            title->state++;
            title->frame = 0;
        }
        break;
    case PLAZA_GAME_TITLE_BOUNCE_BACK:
        done = PlazaGameMotion_Update(&title->motion, title->frame);
        PlazaGameTitle_ScheduleScroll(title, bg, title->motion.current >> FX32_SHIFT);
        title->frame++;
        if (done == 1) {
            title->state++;
        }
        break;
    case PLAZA_GAME_TITLE_SLIDE_IN_DONE:
        return TRUE;
    }
    return FALSE;
}

static BOOL PlazaGameTitle_UpdateSlideOut(PlazaGameTitle *title, PlazaGameBg *bg) {
    BOOL done;
    switch (title->state) {
    case PLAZA_GAME_TITLE_SLIDE_OUT:
        done = PlazaGameMotion_Update(&title->motion, title->frame);
        PlazaGameTitle_ScheduleScroll(title, bg, title->motion.current >> FX32_SHIFT);
        title->frame++;
        if (done == 1) {
            title->state++;
        }
        break;
    case PLAZA_GAME_TITLE_CLEAR:
        ClearWindowTilemapAndCopyToVram(&title->window);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_OFF);
        PlazaGameTitle_SetScroll(title, bg, 0);
        BgClearTilemapBufferAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_0);
        BgClearTilemapBufferAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_1);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG0, GF_PLANE_TOGGLE_ON);
        return TRUE;
    }
    return FALSE;
}

static void PlazaGameTitle_SetScroll(PlazaGameTitle *title, PlazaGameBg *bg, int value) {
    switch (title->game) {
    case PLAZA_GAME_SWALOT_PLOP:
    case PLAZA_GAME_MIME_JR_TOP:
        BgSetPosTextAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, value);
        BgSetPosTextAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, value);
        break;
    case PLAZA_GAME_WOBBUFFET_POP:
        BgSetPosTextAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, value);
        BgSetPosTextAndCommit(bg->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, value);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

static void PlazaGameTitle_ScheduleScroll(PlazaGameTitle *title, PlazaGameBg *bg, int value) {
    switch (title->game) {
    case PLAZA_GAME_SWALOT_PLOP:
    case PLAZA_GAME_MIME_JR_TOP:
        ScheduleSetBgPosText(bg->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_X, value);
        ScheduleSetBgPosText(bg->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_X, value);
        break;
    case PLAZA_GAME_WOBBUFFET_POP:
        ScheduleSetBgPosText(bg->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, value);
        ScheduleSetBgPosText(bg->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, value);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

static void PlazaGame_LoadGamePalette(NARC *narc, int game, enum HeapID heapId) {
    int offset;
    int palette;
    switch (game) {
    case PLAZA_GAME_SWALOT_PLOP:
        palette = 1;
        break;
    case PLAZA_GAME_MIME_JR_TOP:
        palette = 2;
        break;
    case PLAZA_GAME_WOBBUFFET_POP:
        palette = 0;
        break;
    default:
        palette = 1;
        break;
    }
    offset = palette * 0x20;
    GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc(narc, 5, GF_PAL_LOCATION_MAIN_BG, offset, GF_PAL_SLOT_5_OFFSET, 0x20, heapId);
    GfGfxLoader_GXLoadPalWithSrcOffsetFromOpenNarc(narc, 5, GF_PAL_LOCATION_SUB_BG, offset, GF_PAL_SLOT_5_OFFSET, 0x20, heapId);
}

typedef struct PlazaGameRosterBytes {
    u8 bytes[sizeof(PlazaGameRoster)];
} PlazaGameRosterBytes;

typedef struct PlazaGameResultDataBytes {
    u8 bytes[sizeof(PlazaGameResultData)];
} PlazaGameResultDataBytes;

static PlazaGameResults *PlazaGameResults_New(const PlazaGameRoster *roster, const PlazaGameResultData *data, u8 game, enum HeapID heapId) {
    PlazaGameResults *results = Heap_Alloc(heapId, sizeof(PlazaGameResults));
    memset(results, 0, sizeof(PlazaGameResults));
    *(PlazaGameResultDataBytes *)&results->data = *(const PlazaGameResultDataBytes *)data;
    *(PlazaGameRosterBytes *)&results->roster = *(const PlazaGameRosterBytes *)roster;
    results->game = game;
    PlazaGameResults_InitCommands(results);
    G2_BlendNone();
    G2S_BlendNone();
    reg_GX_DISPCNT &= ~(REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK);
    reg_GXS_DB_DISPCNT &= ~(REG_GXS_DB_DISPCNT_W0_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_OW_MASK);
    GfGfx_SetBanks(&gPlazaGameResultsBanks);
    results->heapId = heapId;
    PlazaGamePlayerInfo_Init(&results->info, &results->roster);
    GF_CreateVramTransferManager(16, heapId);
    PlazaGameBg_Init(&results->bg, &gPlazaGameResultsGraphicsModes, gPlazaGameResultsBgTemplates, 6, heapId);
    PlazaGameSprites_Init(&results->sprites, 32, 2, 2, heapId);
    PlazaGameGfx_Init(&results->gfx, 2, heapId);
    PlazaGameText_Init(&results->text, heapId);
    PlazaGameResults_LoadGraphics(results, heapId);
    PlazaGameMessageBox_Init(&results->messageBox, &results->bg, results->roster.saveData, PlazaGameRoster_IsSpecialVisitor(&results->roster, PlazaGameRoster_GetNetId(&results->roster, results->roster.localIndex)), heapId);
    PlazaGameContinue_Init(&results->continuePrompt, &results->bg, results->roster.voiceChat, heapId);
    results->showCountries = PlazaGamePlayerInfo_HasDifferentCountries(&results->roster, results->info.countries);
    switch (results->game) {
    case PLAZA_GAME_SWALOT_PLOP:
    case PLAZA_GAME_MIME_JR_TOP:
        results->task = SysTask_CreateOnMainQueue(PlazaGameResults_RankingTask, results, 0);
        break;
    case PLAZA_GAME_WOBBUFFET_POP:
        results->task = SysTask_CreateOnMainQueue(PlazaGameResults_TeamTask, results, 0);
        break;
    default:
        GF_ASSERT(FALSE);
        results->task = SysTask_CreateOnMainQueue(PlazaGameResults_RankingTask, results, 0);
        break;
    }
    results->vblankTask = SysTask_CreateOnVWaitQueue(PlazaGameResults_VBlankTask, results, 0);
    if (results->roster.voiceChat) {
        WifiConnection_StartVoiceChat(heapId);
    }
    return results;
}

static void PlazaGameResults_LoadGraphics(PlazaGameResults *results, enum HeapID heapId) {
    NARC *narc = NARC_New(NARC_a_1_9_8, heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0x120, heapId);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0x120, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 6, results->bg.bgConfig, GF_BG_LYR_MAIN_1, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 6, results->bg.bgConfig, GF_BG_LYR_SUB_1, 0, 0x4000, FALSE, heapId);
    results->screenRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 9, FALSE, &results->screen, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 8, results->bg.bgConfig, GF_BG_LYR_MAIN_3, 0, 0, FALSE, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 8, results->bg.bgConfig, GF_BG_LYR_SUB_1, 0, 0, FALSE, heapId);
    PlazaGame_LoadGamePalette(narc, results->game, heapId);
    results->gfxRes = PlazaGameGfx_Load(&results->gfx, narc, 11, 5, 12, 13, 14, 5000, heapId);
    PlazaGameResults_LoadFlashPalette(results, narc, heapId);
    PlazaGameBalloons_Init(&results->balloons, &results->bg, &results->sprites, &results->gfx, narc, heapId);
    NARC_Delete(narc);
}

static void PlazaGameResults_FreeGraphics(PlazaGameResults *results) {
    PlazaGameBalloons_Free(&results->balloons);
    Heap_Free(results->screenRaw);
    PlazaGameResults_FreeFlashPalette(results);
}

static void PlazaGameResults_RankingTask(SysTask *task, void *data) {
    PlazaGameResults *results = data;

    switch (results->state) {
    case PLAZA_GAME_RANKING_FADE_IN: {
        int i;
        int threshold;
        results->prevTapToy = results->roster.args->tapToy;
        if (results->roster.launchedFromField == 1) {
            results->tapToyPoweredUp = FALSE;
        } else {
            threshold = PlazaGameResults_GetScoreThreshold(results);
            i = results->roster.localIndex;
            if (results->data.ranks[i] == 0 && results->data.scores[i] > (u32)threshold) {
                results->roster.args->tapToy = PlazaGame_GetPoweredUpTapToy(results->roster.args->tapToy);
                results->tapToyPoweredUp = TRUE;
            } else {
                results->tapToyPoweredUp = FALSE;
            }
            if (results->roster.localIndex == 0) {
                PlazaGameResults_ReportWinners(results);
            }
        }
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0xFFFF, 6, 1, (enum HeapID)results->heapId);
        results->state++;
        break;
    }
    case PLAZA_GAME_RANKING_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            results->state++;
        }
        break;
    case PLAZA_GAME_RANKING_PRINT_TITLE:
        PlazaGameMessageBox_Show(&results->messageBox, &results->text, msg_0236_00001, 0);
        results->state++;
        break;
    case PLAZA_GAME_RANKING_WAIT_TITLE:
        if (PlazaGameMessageBox_IsPrinterFinished(&results->messageBox, 0)) {
            results->timer = 64;
            results->state++;
        }
        break;
    case PLAZA_GAME_RANKING_HIDE_TITLE: {
        int i;
        u32 threshold;
        BOOL noWinner;
        if (results->timer == 0) {
            break;
        }
        results->timer--;
        if (results->timer != 0) {
            break;
        }
        noWinner = TRUE;
        PlazaGameMessageBox_Hide(&results->messageBox, 0);
        PlazaGameLineScroll_Init(&results->lineScroll, &results->bg, (enum HeapID)results->heapId);
        threshold = PlazaGameResults_GetScoreThreshold(results);
        for (i = 0; i < results->roster.count; i++) {
            if (results->data.scores[i] > threshold) {
                noWinner = FALSE;
            }
        }
        if (noWinner == TRUE) {
            results->delay = 16;
            results->state = PLAZA_GAME_RANKING_WAIT_NO_WINNER;
        } else {
            results->state++;
            results->rankStep = 4;
        }
        break;
    }
    case PLAZA_GAME_RANKING_NEXT_RANK: {
        int i;
        BOOL found = FALSE;
        do {
            results->rankStep--;
            for (i = 0; i < results->roster.count; i++) {
                if (results->rankStep == results->data.ranks[i]) {
                    found = TRUE;
                }
            }
        } while (!found);
        switch (results->rankStep) {
        case 2:
        case 3:
            results->delay = 16;
            break;
        case 0:
        case 1:
            results->delay = 32;
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
        PlazaGameResults_UpdatePlayers(results);
        results->state++;
        break;
    }
    case PLAZA_GAME_RANKING_SHOW_RANK: {
        int i;
        BOOL show;
        results->delay--;
        PlazaGameResults_UpdatePlayers(results);
        if (results->delay == 0) {
            for (i = 0; i < results->roster.count; i++) {
                show = FALSE;
                if (results->rankStep == results->data.ranks[i]) {
                    show = TRUE;
                } else if (results->rankStep == 1 && results->data.ranks[i] == 0) {
                    show = TRUE;
                }
                if (show) {
                    PlazaGameResults_ShowPlayer(results, i, results->data.ranks[i]);
                }
            }
            if (results->rankStep > 1) {
                results->state = PLAZA_GAME_RANKING_NEXT_RANK;
            } else {
                results->state++;
            }
        }
        break;
    }
    case PLAZA_GAME_RANKING_WAIT_PLAYERS:
        if (PlazaGameResults_UpdatePlayers(results)) {
            results->state++;
        }
        break;
    case PLAZA_GAME_RANKING_START_FLASH:
        results->state++;
        PlazaGameResults_StartFlash(results);
        results->timer = 30;
        break;
    case PLAZA_GAME_RANKING_WAIT_FLASH:
        if (results->timer != 0) {
            results->timer--;
        }
        if (results->timer == 0) {
            results->state = PLAZA_GAME_RANKING_PRINT_RESULT;
            results->timer = 0;
        }
        break;
    case PLAZA_GAME_RANKING_PRINT_RESULT: {
        int i;
        int msgNo;
        i = results->roster.localIndex;
        if (results->data.ranks[i] == 0) {
            msgNo = msg_0236_00017;
        } else {
            msgNo = msg_0236_00018;
        }
        PlazaGameText_BufferPlayerName(&results->text, results->info.profiles[i]);
        PlazaGameMessageBox_Show(&results->messageBox, &results->text, msgNo, 0);
        results->state++;
        break;
    }
    case PLAZA_GAME_RANKING_WAIT_RESULT:
        if (PlazaGameMessageBox_IsPrinterFinished(&results->messageBox, 0) && PlazaGameResults_IsFanfareDone(results) == TRUE) {
            if (results->roster.launchedFromField == 1) {
                results->timer = 102;
                results->state = PLAZA_GAME_RANKING_HIDE_MESSAGE;
            } else {
                results->timer = 102;
                results->state++;
            }
        }
        break;
    case PLAZA_GAME_RANKING_PRINT_TAP_TOY: {
        int i;
        int msgNo;
        if (results->timer != 0) {
            results->timer--;
            break;
        }
        if (results->tapToyPoweredUp != 0) {
            PlazaGameText_BufferTapToyName(&results->text, results->roster.args->tapToy);
            if (results->prevTapToy == results->roster.args->tapToy) {
                msgNo = msg_0236_00019;
            } else {
                msgNo = msg_0236_00002;
            }
        } else {
            msgNo = msg_0236_00009;
        }
        i = results->roster.localIndex;
        PlazaGameText_BufferPlayerName(&results->text, results->info.profiles[i]);
        PlazaGameMessageBox_Show(&results->messageBox, &results->text, msgNo, 0);
        results->state = PLAZA_GAME_RANKING_WAIT_TAP_TOY;
        break;
    }
    case PLAZA_GAME_RANKING_WAIT_TAP_TOY:
        if (PlazaGameMessageBox_IsPrinterFinished(&results->messageBox, 0)) {
            results->timer = 102;
            results->state++;
        }
        break;
    case PLAZA_GAME_RANKING_HIDE_MESSAGE:
        if (results->timer == 0) {
            break;
        }
        results->timer--;
        if (results->timer != 0) {
            break;
        }
        PlazaGameMessageBox_Hide(&results->messageBox, 0);
        results->timer = 30;
        results->state++;
        break;
    case PLAZA_GAME_RANKING_START_SYNC:
        if (results->timer != 0) {
            results->timer--;
            break;
        }
        LinkSync_StartSync(0x82);
        if (results->roster.voiceChat != 0) {
            WifiConnection_StopVoiceChat();
        }
        results->state++;
        break;
    case PLAZA_GAME_RANKING_WAIT_SYNC:
        if (LinkSync_IsSynced(0x82)) {
            if (results->roster.launchedFromField != 0) {
                results->state = PLAZA_GAME_RANKING_RECORD_FRIEND_PLAYS;
            } else {
                results->state++;
            }
        }
        break;
    case PLAZA_GAME_RANKING_FADE_OUT:
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, (enum HeapID)results->heapId);
        results->state++;
        break;
    case PLAZA_GAME_RANKING_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            results->state = PLAZA_GAME_RANKING_FINISH;
        }
        break;
    case PLAZA_GAME_RANKING_RECORD_FRIEND_PLAYS:
        PlazaGameResults_RecordFriendPlays(results);
        results->state++;
        break;
    case PLAZA_GAME_RANKING_RUN_CONTINUE:
        if (PlazaGameContinue_Run(&results->continuePrompt, &results->messageBox, &results->text, results->game, (enum HeapID)results->heapId)) {
            results->continueResult = PlazaGameContinue_GetResult(&results->continuePrompt);
            results->state++;
        }
        break;
    case PLAZA_GAME_RANKING_FINISH:
        PlazaGameLineScroll_Free(&results->lineScroll);
        results->done = TRUE;
        break;
    case PLAZA_GAME_RANKING_WAIT_NO_WINNER:
        results->delay--;
        if (results->delay == 0) {
            results->state++;
        }
        break;
    case PLAZA_GAME_RANKING_SHOW_ALL_LAST: {
        int i;
        for (i = 0; i < results->roster.count; i++) {
            results->data.ranks[i] = results->roster.count - 1;
            PlazaGameResults_ShowPlayer(results, i, results->data.ranks[i]);
        }
        results->state = PLAZA_GAME_RANKING_WAIT_PLAYERS;
        break;
    }
    default:
        break;
    }
    PlazaGameResults_UpdateFlash(results);
    PlazaGameSprites_Update(&results->sprites);
    ScheduleSetBgPosText(results->bg.bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_Y, 2);
    ScheduleSetBgPosText(results->bg.bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_ADD_Y, 2);
}

static void PlazaGameResults_TeamTask(SysTask *task, void *data) {
    PlazaGameResults *results = data;
    int i;
    switch (results->state) {
    case PLAZA_GAME_TEAM_FADE_IN:
        if (results->roster.launchedFromField == 1) {
            results->tapToyPoweredUp = FALSE;
        } else {
            if (results->data.total >= 10) {
                results->roster.args->tapToy = PlazaGame_GetPoweredUpTapToy(results->roster.args->tapToy);
                results->tapToyPoweredUp = TRUE;
            } else {
                results->tapToyPoweredUp = FALSE;
            }
            if (results->roster.localIndex == 0) {
                PlazaGameResults_ReportTeamWin(results);
            }
        }
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0xFFFF, 6, 1, (enum HeapID)results->heapId);
        results->state++;
        break;
    case PLAZA_GAME_TEAM_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            results->state++;
            results->rankStep = 4;
        }
        break;
    case PLAZA_GAME_TEAM_PRINT_TITLE:
        PlazaGameMessageBox_Show(&results->messageBox, &results->text, msg_0236_00001, 0);
        results->state++;
        break;
    case PLAZA_GAME_TEAM_WAIT_TITLE:
        if (PlazaGameMessageBox_IsPrinterFinished(&results->messageBox, 0)) {
            results->timer = 102;
            results->state++;
        }
        break;
    case PLAZA_GAME_TEAM_HIDE_TITLE:
        if (results->timer != 0) {
            results->timer--;
            if (results->timer == 0) {
                PlazaGameMessageBox_Hide(&results->messageBox, 0);
                results->state++;
            }
        }
        break;
    case PLAZA_GAME_TEAM_SHOW_PLAYERS:
        PlazaGameLineScroll_Init(&results->lineScroll, &results->bg, (enum HeapID)results->heapId);
        for (i = 0; i < results->roster.count; i++) {
            PlazaGamePlayer_Init(&results->players[i], results->roster.count, results->game, results->screen, &results->bg, i, results->roster.localIndex, &results->sprites, results->gfxRes, (enum HeapID)results->heapId);
            PlazaGamePlayer_PrintName(&results->players[i], &results->text, results->info.profiles[i], 8, 0, PlazaGameRoster_IsSpecialVisitor(&results->roster, PlazaGameRoster_GetNetId(&results->roster, i)));
            PlazaGamePlayer_PrintLocation(&results->players[i], &results->text, results->showCountries, results->info.countries[i], results->info.regions[i], 8);
            PlazaGamePlayer_ScheduleTransfer(&results->players[i], &results->bg);
            PlazaGamePlayer_ShowSprite(&results->players[i]);
            PlazaGamePlayer_StartSlideIn(&results->players[i], -8, i * 3);
        }
        results->state++;
        results->timer = 16;
        break;
    case PLAZA_GAME_TEAM_WAIT_PLAYERS:
        if (PlazaGameResults_UpdatePlayers(results) == TRUE) {
            results->timer--;
            if (results->timer == 0) {
                PlazaGameBalloons_Start(&results->balloons, results->data.total);
                results->state++;
            }
        }
        break;
    case PLAZA_GAME_TEAM_RUN_BALLOONS:
        if (PlazaGameBalloons_Update(&results->balloons, &results->bg) == TRUE) {
            if (results->tapToyPoweredUp == TRUE) {
                PlazaGameResults_PlayFanfare(results);
            }
            results->state++;
        }
        break;
    case PLAZA_GAME_TEAM_PRINT_TOTAL:
        PlazaGameText_BufferTwoDigitNumber(&results->text, results->data.total);
        PlazaGameMessageBox_Show(&results->messageBox, &results->text, msg_0236_00007, 0);
        results->timer = 102;
        results->state++;
        break;
    case PLAZA_GAME_TEAM_WAIT_TOTAL:
        if (PlazaGameMessageBox_IsPrinterFinished(&results->messageBox, 0) == TRUE) {
            if (results->timer == 0) {
                if (PlazaGameResults_IsFanfareDone(results) == TRUE) {
                    if (results->roster.launchedFromField == 1) {
                        results->timer = 102;
                        results->state = PLAZA_GAME_TEAM_HOLD;
                    } else {
                        results->state++;
                    }
                }
            } else {
                results->timer--;
            }
        }
        break;
    case PLAZA_GAME_TEAM_PRINT_TAP_TOY:
        PlazaGameMessageBox_Show(&results->messageBox, &results->text, results->tapToyPoweredUp ? msg_0236_00008 : msg_0236_00009, 0);
        results->state++;
        break;
    case PLAZA_GAME_TEAM_WAIT_TAP_TOY:
        if (PlazaGameMessageBox_IsPrinterFinished(&results->messageBox, 0)) {
            results->timer = 102;
            if (results->tapToyPoweredUp) {
                results->state = PLAZA_GAME_TEAM_HOLD_POWERED_UP;
            } else {
                results->state++;
            }
        }
        break;
    case PLAZA_GAME_TEAM_HOLD:
        if (results->timer != 0) {
            results->timer--;
            if (results->timer == 0) {
                results->state = PLAZA_GAME_TEAM_START_SYNC;
            }
        }
        break;
    case PLAZA_GAME_TEAM_HOLD_POWERED_UP:
        if (results->timer != 0) {
            results->timer--;
        }
        if (results->timer == 0) {
            results->state = PLAZA_GAME_TEAM_START_SYNC;
        }
        break;
    case PLAZA_GAME_TEAM_START_SYNC:
        if (results->roster.voiceChat) {
            WifiConnection_StopVoiceChat();
        }
        LinkSync_StartSync(0x82);
        results->state++;
        break;
    case PLAZA_GAME_TEAM_WAIT_SYNC:
        if (LinkSync_IsSynced(0x82)) {
            if (results->roster.launchedFromField) {
                results->state = PLAZA_GAME_TEAM_RECORD_FRIEND_PLAYS;
            } else {
                results->state++;
            }
        }
        break;
    case PLAZA_GAME_TEAM_FADE_OUT:
        BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, (enum HeapID)results->heapId);
        results->state++;
        break;
    case PLAZA_GAME_TEAM_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            results->state = PLAZA_GAME_TEAM_FINISH;
        }
        break;
    case PLAZA_GAME_TEAM_RECORD_FRIEND_PLAYS:
        PlazaGameResults_RecordFriendPlays(results);
        results->state++;
        break;
    case PLAZA_GAME_TEAM_RUN_CONTINUE:
        if (PlazaGameContinue_Run(&results->continuePrompt, &results->messageBox, &results->text, results->game, (enum HeapID)results->heapId)) {
            results->continueResult = PlazaGameContinue_GetResult(&results->continuePrompt);
            results->state++;
        }
        break;
    case PLAZA_GAME_TEAM_FINISH:
        PlazaGameLineScroll_Free(&results->lineScroll);
        results->done = TRUE;
        break;
    }
    PlazaGameResults_UpdateFlash(results);
    PlazaGameSprites_Update(&results->sprites);
    ScheduleSetBgPosText(results->bg.bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_Y, 2);
    ScheduleSetBgPosText(results->bg.bgConfig, GF_BG_LYR_SUB_1, BG_POS_OP_ADD_Y, 2);
}

static void PlazaGameResults_VBlankTask(SysTask *task, void *data) {
    PlazaGameResults *results = data;
    GF_RunVramTransferTasks();
    PlazaGameBg_Update(&results->bg);
    PlazaGameSprites_ApplyOam(&results->sprites);
    PlazaGameLineScroll_Swap(&results->lineScroll);
}

static void PlazaGameResults_LoadFlashPalette(PlazaGameResults *results, NARC *narc, enum HeapID heapId) {
    results->flashPlttRaw = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, &results->flashPltt, heapId);
}

static void PlazaGameResults_StartFlash(PlazaGameResults *results) {
    int i;
    int count;

    results->flashEnabled = 1;
    count = results->roster.count;
    for (i = 0; i < count; i++) {
        if (results->data.ranks[i] == 0 && results->roster.localIndex == i) {
            PlazaGameResults_PlayFanfare(results);
            return;
        }
    }
}

static inline u8 *PlazaGameResults_GetFlashColors(PlazaGameResults *results, u8 *data, u32 slot) {
    if (results->flashFrame == 0) {
        return data + (slot + 3) * 32;
    } else {
        return data + (slot + 7) * 32;
    }
}

static void PlazaGameResults_UpdateFlash(PlazaGameResults *results) {
    if (results->flashEnabled != 0) {
        if (results->flashFrame == 0 || results->flashFrame == 8) {
            int i;
            const u8 *slot;
            i = 0;
            if (i < results->roster.count) {
                slot = gPlazaGameResultsFlashSlots;
                do {
                    if (results->data.ranks[i] == 0) {
                        u32 index = *slot;
                        u32 dest = index * 32;
                        u8 *colors = results->flashPltt->pRawData;
                        GF_ASSERT(GF_CreateNewVramTransferTask(NNS_GFD_DST_2D_BG_PLTT_MAIN, dest, PlazaGameResults_GetFlashColors(results, colors, index), 32));
                    }
                    slot++;
                    i++;
                } while (i < results->roster.count);
            }
        }
        results->flashFrame = ((int)results->flashFrame + 1) % 16;
    }
}

static void PlazaGameResults_FreeFlashPalette(PlazaGameResults *results) {
    Heap_Free(results->flashPlttRaw);
}

static void PlazaGameContinue_Init(PlazaGameContinue *prompt, PlazaGameBg *bg, u8 voiceChat, enum HeapID heapId) {
    memset(prompt, 0, sizeof(PlazaGameContinue));
    prompt->template.bgConfig = bg->bgConfig;
    prompt->template.bgId = GF_BG_LYR_SUB_0;
    prompt->template.tileStart = 139;
    prompt->template.plttSlot = 2;
    prompt->template.x = 24;
    prompt->template.y = 8;
    prompt->template.shapeParam = 0;
    prompt->prompt = YesNoPrompt_Create(heapId);
    prompt->voiceChat = voiceChat;
    prompt->allYes = TRUE;
}

static void PlazaGameContinue_Free(PlazaGameContinue *prompt) {
    YesNoPrompt_Destroy(prompt->prompt);
}

static BOOL PlazaGameContinue_Run(PlazaGameContinue *prompt, PlazaGameMessageBox *messageBox, PlazaGameText *text, int game, volatile enum HeapID heapId) {
    switch (prompt->state) {
    case PLAZA_GAME_CONTINUE_FADE: {
        enum HeapID heap = heapId;
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_IN, RGB_BLACK, 6, 1, heap);
        WirelessStatusIcon_ShowOnBothScreens(FALSE, heapId);
        if (prompt->voiceChat) {
            WifiConnection_StartVoiceChat(heap);
        }
        prompt->state++;
    } break;
    case PLAZA_GAME_CONTINUE_WAIT_FADE:
        if (IsPaletteFadeFinished()) {
            prompt->state++;
        }
        break;
    case PLAZA_GAME_CONTINUE_PRINT_PROMPT:
        PlazaGameText_BufferActivityName(text, game);
        PlazaGameMessageBox_Show(messageBox, text, msg_0236_00003, 1);
        prompt->state++;
        break;
    case PLAZA_GAME_CONTINUE_WAIT_PROMPT:
        if (PlazaGameMessageBox_IsPrinterFinished(messageBox, 1) == TRUE) {
            prompt->state++;
        }
        break;
    case PLAZA_GAME_CONTINUE_OPEN_YES_NO:
        YesNoPrompt_InitFromTemplate(prompt->prompt, &prompt->template);
        prompt->state++;
        break;
    case PLAZA_GAME_CONTINUE_HANDLE_YES_NO: {
        int response = YesNoPrompt_HandleInput(prompt->prompt);
        if ((u32)response - 1u <= 1u) {
            if (response == YESNORESPONSE_YES) {
                Comm_SendCommand(PLAZA_GAME_CMD_VOTE_YES, NULL, 0);
            } else if (response == YESNORESPONSE_NO) {
                Comm_SendCommand(PLAZA_GAME_CMD_VOTE_NO, NULL, 0);
            }
            PlazaGameMessageBox_Show(messageBox, text, msg_0236_00015, 1);
            PlazaGameMessageBox_ShowWaitingIcon(messageBox, 1);
            YesNoPrompt_Reset(prompt->prompt);
            prompt->state++;
        }
    } break;
    case PLAZA_GAME_CONTINUE_WAIT_ANSWERS:
        if (prompt->received) {
            if (prompt->result) {
                prompt->state = PLAZA_GAME_CONTINUE_FADE_OUT;
            } else {
                prompt->state++;
            }
        }
        break;
    case PLAZA_GAME_CONTINUE_PRINT_CANCELED:
        PlazaGameMessageBox_Show(messageBox, text, msg_0236_00006, 1);
        prompt->state++;
        break;
    case PLAZA_GAME_CONTINUE_WAIT_CANCELED:
        if (PlazaGameMessageBox_IsPrinterFinished(messageBox, 1) == TRUE) {
            prompt->state++;
            prompt->timer = 102;
        }
        break;
    case PLAZA_GAME_CONTINUE_WAIT:
        prompt->timer--;
        if (prompt->timer == 0) {
            prompt->state++;
        }
        break;
    case PLAZA_GAME_CONTINUE_FADE_OUT:
        BeginNormalPaletteFade(FADE_SUB_ONLY, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, heapId);
        prompt->state++;
        break;
    case PLAZA_GAME_CONTINUE_WAIT_FADE_OUT:
        if (IsPaletteFadeFinished()) {
            WirelessStatusIcon_Destroy();
            if (prompt->voiceChat) {
                WifiConnection_StopVoiceChat();
            }
            prompt->state++;
        }
        break;
    case PLAZA_GAME_CONTINUE_FINISH:
        return TRUE;
    }
    return FALSE;
}

static u8 PlazaGameContinue_GetResult(const PlazaGameContinue *prompt) {
    return prompt->result;
}

static void PlazaGameContinue_ReceiveVote(PlazaGameContinue *prompt, int netId, BOOL yes, int count) {
    int bit = 1 << netId;
    int i;
    u32 votes;
    if (!(prompt->votes & bit)) {
        if (yes == 0) {
            prompt->allYes = FALSE;
        }
        prompt->votes |= bit;
    }
    votes = 0;
    for (i = votes; i < PLAZA_GAME_MAX_PLAYERS; i++) {
        if (prompt->votes & (1 << i)) {
            votes++;
        }
    }
    if (votes == count) {
        if (prompt->allYes) {
            Comm_SendCommand(PLAZA_GAME_CMD_CONTINUE, NULL, 0);
        } else {
            Comm_SendCommand(PLAZA_GAME_CMD_QUIT, NULL, 0);
        }
    }
}

static void PlazaGameContinue_SetResult(PlazaGameContinue *prompt, u8 result) {
    prompt->received = TRUE;
    prompt->result = result;
}

static void PlazaGameBalloons_Init(PlazaGameBalloons *balloons, PlazaGameBg *bg, PlazaGameSprites *sprites, PlazaGameGfx *gfx, NARC *narc, enum HeapID heapId) {
    s16 spriteY;
    int y;
    int base;
    int row;
    memset(balloons, 0, sizeof(PlazaGameBalloons));
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 24, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_14_OFFSET, 32, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 25, bg->bgConfig, GF_BG_LYR_MAIN_2, 139, 0, FALSE, heapId);
    balloons->screenRaw = GfGfxLoader_GetScrnDataFromOpenNarc(narc, 26, FALSE, &balloons->screen, heapId);
    balloons->gfxRes = PlazaGameGfx_Load(gfx, narc, 15, 1, 16, 17, 18, 5001, heapId);
    y = 40;
    row = 0;
    base = 0;
    do {
        int col;
        int x = 74;
        col = 0;
        spriteY = y;
        for (; col < 5; col++, x += 24) {
            PlazaGameBalloons *slot = (PlazaGameBalloons *)((u8 *)balloons + 4 * (col + base));
            slot->sprites[0] = PlazaGameGfx_CreateSprite(balloons->gfxRes, sprites->spriteList, x, spriteY, 0, heapId);
            Sprite_SetDrawFlag(slot->sprites[0], FALSE);
            Sprite_SetAnimCtrlSeq(slot->sprites[0], row);
            Sprite_SetPriority(slot->sprites[0], 0);
        }
        y += 36;
        base += 5;
        row++;
    } while (row < 3);
}

static void PlazaGameBalloons_Free(PlazaGameBalloons *balloons) {
    int i;
    for (i = 0; i < 15; i++) {
        Sprite_Delete(balloons->sprites[i]);
    }
    Heap_Free(balloons->screenRaw);
}

static void PlazaGameBalloons_Start(PlazaGameBalloons *balloons, int total) {
    balloons->total = total;
    balloons->state = 0;
    balloons->count = 0;
}

static BOOL PlazaGameBalloons_Update(PlazaGameBalloons *balloons, PlazaGameBg *bg) {
    int i;
    switch (balloons->state) {
    case 0:
        PlazaGame_OffsetScreenTiles(balloons->screen, 139);
        LoadRectToBgTilemapRect(bg->bgConfig, GF_BG_LYR_MAIN_2, balloons->screen->rawData, 0, 0, 32, 20);
        BgTilemapRectChangePalette(bg->bgConfig, GF_BG_LYR_MAIN_2, 0, 0, 32, 20, 14);
        ScheduleBgTilemapBufferTransfer(bg->bgConfig, GF_BG_LYR_MAIN_2);
        balloons->state++;
        break;
    case 1:
        if (balloons->count == balloons->total) {
            balloons->state = 3;
            break;
        }
        PlaySE(SEQ_SE_PL_BALLOON07);
        Sprite_SetDrawFlag(balloons->sprites[balloons->count % 15], TRUE);
        balloons->timer = 8;
        balloons->state++;
        break;
    case 2:
        balloons->timer--;
        if (balloons->timer != 0) {
            break;
        }
        balloons->count++;
        if (balloons->count % 15 == 0 && balloons->count != balloons->total) {
            for (i = 0; i < 15; i++) {
                Sprite_SetDrawFlag(balloons->sprites[i], FALSE);
                Sprite_SetAnimCtrlSeq(balloons->sprites[i], 2);
            }
        }
        balloons->state = 1;
        break;
    case 3:
        return TRUE;
    }
    return FALSE;
}

static void PlazaGameResults_ShowPlayer(PlazaGameResults *results, int index, int rank) {
    int offset = index * sizeof(PlazaGamePlayer);
    PlazaGamePlayer *players = results->players;
    u32 highlight;
    int digits;
    PlazaGamePlayer_Init((PlazaGamePlayer *)((u8 *)players + offset), results->roster.count, results->game, results->screen, &results->bg, index, results->roster.localIndex, &results->sprites, results->gfxRes, (enum HeapID)results->heapId);
    highlight = PlazaGameRoster_IsSpecialVisitor(&results->roster, PlazaGameRoster_GetNetId(&results->roster, index));
    PlazaGamePlayer_PrintName((PlazaGamePlayer *)((u8 *)players + offset), &results->text, results->info.profiles[index], 8, 0, highlight);
    PlazaGamePlayer_PrintLocation((PlazaGamePlayer *)((u8 *)players + offset), &results->text, results->showCountries, results->info.countries[index], results->info.regions[index], 8);
    if (results->game == PLAZA_GAME_SWALOT_PLOP) {
        digits = 5;
    } else {
        digits = 6;
    }
    PlazaGamePlayer_PrintScore((PlazaGamePlayer *)((u8 *)players + offset), &results->text, results->data.scores[index], (s16)(176 - gPlazaGameResultsRankOffsets[4 - (rank + 1)]), 0, digits);
    PlazaGamePlayer_ScheduleTransfer((PlazaGamePlayer *)((u8 *)players + offset), &results->bg);
    PlazaGamePlayer_ShowRank((PlazaGamePlayer *)((u8 *)players + offset), rank);
    PlazaGamePlayer_StartSlideIn((PlazaGamePlayer *)((u8 *)players + offset), gPlazaGameResultsRankOffsets[rank], 0);
}

static BOOL PlazaGameResults_UpdatePlayers(PlazaGameResults *results) {
    int i;
    BOOL allDone;
    PlazaGamePlayer *player;
    u8 *row;
    PlazaGamePlayer *scrollPlayer;

    allDone = TRUE;
    i = 0;
    if (i < results->roster.count) {
        player = results->players;
        row = (u8 *)results;
        scrollPlayer = player;
        do {
            if (((PlazaGameResults *)row)->players[0].sprite != NULL) {
                BOOL done = PlazaGamePlayer_UpdateSlide(player);
                PlazaGameLineScroll_SetPlayer(&results->lineScroll, scrollPlayer);
                if (!done) {
                    allDone = FALSE;
                }
            } else {
                allDone = FALSE;
            }
            row += sizeof(PlazaGamePlayer);
            player++;
            scrollPlayer++;
            i++;
        } while (i < results->roster.count);
    }
    return allDone;
}

static void PlazaGameResults_PlayFanfare(PlazaGameResults *results) {
    if (results->fanfareState == 0) {
        PlayFanfare(SEQ_ME_MINIGAME);
        results->fanfareState = 1;
    }
}

static BOOL PlazaGameResults_IsFanfareDone(PlazaGameResults *results) {
    if (results->fanfareState == 1 && !IsFanfarePlaying()) {
        results->fanfareState = 0;
    }
    return results->fanfareState != 1;
}

static void PlazaGameResults_RecordFriendPlays(PlazaGameResults *results) {
    FriendRoster *friends = Save_FriendRoster_Get(results->roster.saveData);
    int i;
    for (i = 0; i < results->roster.count; i++) {
        u32 index;
        void *friendData = CommPlayerInfo_GetExchangeToken(results->roster.netIds[i]);
        int result = Comm_FindFriendSlot(results->roster.saveData, friendData, &index);
        switch (result) {
        case 0:
        case 1:
            switch (results->game) {
            case PLAZA_GAME_SWALOT_PLOP:
                FriendRoster_AddPlazaGame0Plays(friends, index, 1);
                break;
            case PLAZA_GAME_MIME_JR_TOP:
                FriendRoster_AddPlazaGame1Plays(friends, index, 1);
                break;
            case PLAZA_GAME_WOBBUFFET_POP:
                FriendRoster_AddPlazaGame2Plays(friends, index, 1);
                break;
            }
            break;
        }
    }
}

static int PlazaGameResults_GetScoreThreshold(PlazaGameResults *results) {
    switch (results->game) {
    case PLAZA_GAME_SWALOT_PLOP:
        return 0;
    case PLAZA_GAME_MIME_JR_TOP:
        return 0;
    case PLAZA_GAME_WOBBUFFET_POP:
        GF_ASSERT(FALSE);
        return 0;
    }
}

static void PlazaGameResults_ReportWinners(PlazaGameResults *results) {
    u32 ids[4] = { 0 };
    int i;
    int count;
    int threshold;

    count = 0;
    threshold = PlazaGameResults_GetScoreThreshold(results);
    for (i = 0; i < results->roster.count; i++) {
        if (results->data.ranks[i] == 0 && results->data.scores[i] != threshold) {
            ids[count] = results->roster.args->slots[i];
            count++;
        }
    }
    if (count != 0) {
        WiFiPlaza_SendMinigameResultNews(results->roster.args->plazaWork, results->game, count, ids[0], ids[1], ids[2], ids[3]);
    }
}

static void PlazaGameResults_ReportTeamWin(PlazaGameResults *results) {
    if (results->roster.count != 0 && results->data.total >= 10) {
        PlazaGameArgs *args = results->roster.args;
        WiFiPlaza_SendMinigameResultNews(args->plazaWork, results->game, results->roster.count, args->slots[0], args->slots[1], args->slots[2], args->slots[3]);
    }
}

static inline void PlazaGameSignWindow_SetInsidePlanes(u32 planes, BOOL effect) {
    u32 value = (reg_G2_WININ & ~0x3F) | planes;
    if (effect) {
        value |= 0x20;
    }
    reg_G2_WININ = (u16)value;
}

static void PlazaGameSignWindow_Init(PlazaGameSignWindow *window, PlazaGameGfxRes *gfxRes, SpriteList *spriteList, enum HeapID heapId) {
    s32 i;
    u32 windows;
    memset(window->lines, 0, sizeof(window->lines));
    memset(window->pendingLines, 0, sizeof(window->pendingLines));
    window->step = 0;
    window->offset = 0;
    window->task = NULL;
    for (i = 0; i < 2; i++) {
        window->sprites[i] = PlazaGameGfx_CreateSprite(gfxRes, spriteList, gPlazaGameSignWindowSpritePositions[i].x >> FX32_SHIFT, gPlazaGameSignWindowSpritePositions[i].y >> FX32_SHIFT, 0, heapId);
        Sprite_SetAnimCtrlSeq(window->sprites[i], 5);
        Sprite_SetPriority(window->sprites[i], 0);
    }
    windows = (reg_GX_DISPCNT & (REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK)) >> REG_GX_DISPCNT_W0_SHIFT;
    GX_SetVisibleWnd(windows & ~GX_WNDMASK_W0);
    PlazaGameSignWindow_SetInsidePlanes(31, TRUE);
    reg_G2_WIN0H = 0;
    reg_G2_WIN0V = 0;
    *(u8 *)&window->savedOutside = *(vu8 *)&reg_G2_WINOUT;
    window->savedWindows = ((reg_GX_DISPCNT & (REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK)) >> REG_GX_DISPCNT_W0_SHIFT) & GX_WNDMASK_W1;
    window->signOutside.planes = 15;
    window->signOutside.effect = 1;
    Main_SetHBlankIntrCB(PlazaGameSignWindow_HBlank, window);
    Sprite_SetFlipMode(window->sprites[1], 2);
    PlazaGameSignWindow_UpdateLines(window);
}

static BOOL PlazaGameSignWindow_Open(PlazaGameSignWindow *window) {
    BOOL done = FALSE;
    window->step++;
    if (window->step >= 8) {
        window->step = 8;
        done = TRUE;
    }
    PlazaGameSignWindow_Move(window, 1);
    return done;
}

static BOOL PlazaGameSignWindow_Close(PlazaGameSignWindow *window) {
    BOOL done = FALSE;
    window->step--;
    if (window->step <= 0) {
        done = TRUE;
        window->step = 1;
        Sprite_SetDrawFlag(window->sprites[0], FALSE);
        Sprite_SetDrawFlag(window->sprites[1], FALSE);
    }
    PlazaGameSignWindow_Move(window, -1);
    return done;
}

static void PlazaGameSignWindow_Move(PlazaGameSignWindow *window, int delta) {
    int offset;
    int i;
    VecFx32 pos;
    window->offset = window->step * 23 / 8;
    if (window->step + delta <= 8 && window->step + delta >= 0) {
        offset = (window->step + delta) * 23 / 8;
    } else {
        offset = window->offset;
    }
    for (i = 0; i < 2; i++) {
        pos = gPlazaGameSignWindowSpritePositions[i];
        if (i == 0) {
            float distance;
            if (offset > 0) {
                distance = 0.5f + (float)(offset << FX32_SHIFT);
            } else {
                distance = (float)(offset << FX32_SHIFT) - 0.5f;
            }
            pos.y -= (int)distance;
        } else {
            float distance;
            if (offset > 0) {
                distance = 0.5f + (float)(offset << FX32_SHIFT);
            } else {
                distance = (float)(offset << FX32_SHIFT) - 0.5f;
            }
            pos.y += (int)distance;
        }
        Sprite_SetMatrix(window->sprites[i], &pos);
    }
    PlazaGameSignWindow_UpdateLines(window);
}

static void PlazaGameSignWindow_Free(PlazaGameSignWindow *window) {
    int i;
    if (window->task != NULL) {
        SysTask_Destroy(window->task);
        window->task = NULL;
    }
    for (i = 0; i < 2; i++) {
        if (window->sprites[i] != NULL) {
            Sprite_Delete(window->sprites[i]);
            window->sprites[i] = NULL;
        }
    }
    HBlankInterruptDisable();
    GX_SetVisibleWnd(window->savedWindows);
    {
        u32 value = (reg_G2_WINOUT & ~0x3F) | window->savedOutside.planes;
        if (window->savedOutside.effect) {
            value |= 0x20;
        }
        reg_G2_WINOUT = value;
    }
}

static void PlazaGameSignWindow_UpdateLines(PlazaGameSignWindow *window) {
    int i;
    memset(window->pendingLines, 0, sizeof(window->pendingLines));
    for (i = 0; i < 23 - window->offset; i++) {
        window->pendingLines[73 + i] = 1;
        window->pendingLines[121 - i] = 1;
    }
    if (window->task == NULL) {
        window->task = SysTask_CreateOnVWaitQueue(PlazaGameSignWindow_CommitLinesTask, window, 0);
    }
}

static void PlazaGameSignWindow_CommitLinesTask(SysTask *task, void *data) {
    PlazaGameSignWindow *window = data;
    memcpy(window->lines, window->pendingLines, sizeof(window->lines));
    SysTask_Destroy(window->task);
    window->task = NULL;
}

static void PlazaGameSignWindow_HBlank(void *data) {
    PlazaGameSignWindow *window = data;
    int line;
    u32 windows;
    line = ((int)reg_GX_VCOUNT + 1) % 256;
    if (line < 192) {
        windows = (reg_GX_DISPCNT & (REG_GX_DISPCNT_W0_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_OW_MASK)) >> REG_GX_DISPCNT_W0_SHIFT;
        if ((reg_GX_DISPSTAT & REG_GX_DISPSTAT_HBLK_MASK) != 0) {
            if (line < 73 || line > 121) {
                u32 value = (reg_G2_WINOUT & ~0x3F) | window->savedOutside.planes;
                if (window->savedOutside.effect) {
                    value |= 0x20;
                }
                reg_G2_WINOUT = value;
                windows |= window->savedWindows;
            } else {
                u32 value = (reg_G2_WINOUT & ~0x3F) | window->signOutside.planes;
                if (window->signOutside.effect) {
                    value |= 0x20;
                }
                reg_G2_WINOUT = value;
                windows &= ~(window->savedWindows | GX_WNDMASK_W1);
            }
            if (window->lines[line] == 1) {
                GX_SetVisibleWnd(windows | GX_WNDMASK_W0);
            } else {
                GX_SetVisibleWnd(windows & ~GX_WNDMASK_W0);
            }
        }
    }
}

static void PlazaGameSign_CountdownTask(SysTask *task, void *data) {
    PlazaGameSign *sign = data;
    switch (sign->state) {
    case PLAZA_GAME_SIGN_CREATE:
        PlazaGameSignWindow_Init(&sign->window, sign->gfxRes, sign->spriteList, sign->heapId);
        sign->sprite = PlazaGameGfx_CreateSprite(sign->gfxRes, sign->spriteList, 128, 97, 64, sign->heapId);
        Sprite_SetPriority(sign->sprite, 0);
        sign->state++;
        break;
    case PLAZA_GAME_SIGN_OPEN_WINDOW:
        if (PlazaGameSignWindow_Open(&sign->window) == TRUE) {
            sign->state++;
            sign->timer = 0;
        }
        break;
    case PLAZA_GAME_SIGN_SHOW: {
        fx32 prevFrame = Sprite_GetAnimationFrame(sign->sprite);
        fx32 frame;
        Sprite_UpdateAnim(sign->sprite, 2 * FX32_ONE);
        frame = Sprite_GetAnimationFrame(sign->sprite);
        if (prevFrame != frame) {
            switch (frame) {
            case 7:
                PlaySE(SEQ_SE_DP_DECIDE);
                break;
            case 9:
                PlaySE(SEQ_SE_DP_DECIDE);
                break;
            case 11:
                PlaySE(SEQ_SE_DP_DECIDE);
                break;
            case 13:
                PlaySE(SEQ_SE_DP_DECIDE);
                break;
            case 15:
                PlaySE(SEQ_SE_DP_CON_016);
                break;
            }
        }
        if (frame == 15) {
            if (sign->timer == 0) {
                Sprite_SetPalOffsetRespectVramOffset(sign->sprite, 0);
            } else if (sign->timer == 4) {
                Sprite_SetPalOffsetRespectVramOffset(sign->sprite, 1);
            }
            sign->timer++;
            if (sign->timer >= 8) {
                sign->timer = 0;
            }
        }
        if (!Sprite_IsAnimated(sign->sprite)) {
            sign->state++;
            Sprite_SetPalOffsetRespectVramOffset(sign->sprite, 0);
        }
    } break;
    case PLAZA_GAME_SIGN_CLOSE_WINDOW:
        if (PlazaGameSignWindow_Close(&sign->window) == TRUE) {
            Sprite_Delete(sign->sprite);
            sign->sprite = NULL;
            sign->state++;
            sign->timer = 0;
        }
        break;
    case PLAZA_GAME_SIGN_FREE:
        sign->timer++;
        if (sign->timer >= 2) {
            sign->state = PLAZA_GAME_SIGN_IDLE;
            PlazaGameSignWindow_Free(&sign->window);
            SysTask_Destroy(sign->task);
            sign->task = NULL;
        }
        break;
    }
}

static void PlazaGameSign_FinishTask(SysTask *task, void *data) {
    PlazaGameSign *sign = data;
    switch (sign->state) {
    case PLAZA_GAME_SIGN_CREATE:
        PlazaGameSignWindow_Init(&sign->window, sign->gfxRes, sign->spriteList, sign->heapId);
        sign->sprite = PlazaGameGfx_CreateSprite(sign->gfxRes, sign->spriteList, 128, 97, 64, sign->heapId);
        Sprite_SetAnimCtrlSeq(sign->sprite, 1);
        Sprite_SetPriority(sign->sprite, 0);
        sign->state++;
        break;
    case PLAZA_GAME_SIGN_OPEN_WINDOW:
        if (PlazaGameSignWindow_Open(&sign->window) == TRUE) {
            Sprite_SetAnimActiveFlag(sign->sprite, TRUE);
            sign->state++;
            sign->timer = 0;
        }
        break;
    case PLAZA_GAME_SIGN_SHOW:
        sign->timer++;
        if (sign->timer >= 50) {
            sign->state++;
        }
        break;
    case PLAZA_GAME_SIGN_CLOSE_WINDOW:
        if (PlazaGameSignWindow_Close(&sign->window) == TRUE) {
            Sprite_Delete(sign->sprite);
            sign->sprite = NULL;
            sign->timer = 0;
            sign->state++;
        }
        break;
    case PLAZA_GAME_SIGN_FREE:
        sign->timer++;
        if (sign->timer >= 2) {
            sign->state = PLAZA_GAME_SIGN_IDLE;
            PlazaGameSignWindow_Free(&sign->window);
            SysTask_Destroy(sign->task);
            sign->task = NULL;
        }
        break;
    }
}

static const void *PlazaGame_GetCommandTable(void) {
    return gPlazaGameCommands;
}

static int PlazaGame_GetCommandCount(void) {
    return 5;
}

static void PlazaGameResults_InitCommands(PlazaGameResults *results) {
    Comm_RegisterCommandTable(PlazaGame_GetCommandTable(), PlazaGame_GetCommandCount(), results);
}

static void PlazaGameEntry_InitCommands(PlazaGameEntry *entry) {
    Comm_RegisterCommandTable(PlazaGame_GetCommandTable(), PlazaGame_GetCommandCount(), entry);
}

int PlazaGame_GetCommandSizeNone(void) {
    return 0;
}

int PlazaGame_GetCommandSizeU32(void) {
    return sizeof(u32);
}

void PlazaGame_HandleSelectionCommand(int netId, int size, int *data, PlazaGameEntry *entry) {
    PlazaGameEntry_SetSelection(entry, *data);
}

void PlazaGame_HandleVoteYesCommand(int netId, int size, void *data, PlazaGameResults *results) {
    PlazaGameResults_ReceiveVote(results, netId, TRUE);
}

void PlazaGame_HandleVoteNoCommand(int netId, int size, void *data, PlazaGameResults *results) {
    PlazaGameResults_ReceiveVote(results, netId, FALSE);
}

void PlazaGame_HandleContinueCommand(int netId, int size, void *data, PlazaGameResults *results) {
    PlazaGameResults_ReceiveContinue(results, TRUE);
}

void PlazaGame_HandleQuitCommand(int netId, int size, void *data, PlazaGameResults *results) {
    PlazaGameResults_ReceiveContinue(results, FALSE);
}
