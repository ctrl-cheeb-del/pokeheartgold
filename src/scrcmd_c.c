#include "poke_overlay.h"
#define _IN_SCRCMD_C

#include "constants/events.h"
#include "constants/phone_contacts.h"
#include "constants/trainers.h"

#include "field/field_camera.h"
#include "field/legend_cutscene_camera.h"
#include "field/map_load_manager.h"
#include "field/map_prop.h"
#include "field/rock_smash_item.h"
#include "field/signpost.h"
#include "frontier/frontier.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0202.h"
#include "overlay_2/event_cutscene.h"
#include "overlay_2/fashion_case_gifts.h"
#include "overlay_2/gear_phone_calls.h"

#include "alph_puzzle.h"
#include "bg_window.h"
#include "blackout.h"
#include "certificates_app.h"
#include "choose_starter.h"
#include "daycare.h"
#include "easy_chat.h"
#include "encounter.h"
#include "fashion_case.h"
#include "field_bgm.h"
#include "field_roamer.h"
#include "field_system.h"
#include "field_take_photo.h"
#include "field_warp_tasks.h"
#include "follow_mon.h"
#include "game_clear.h"
#include "game_stats.h"
#include "gymmick_init.h"
#include "launch_application.h"
#include "map_events.h"
#include "map_object.h"
#include "math_util.h"
#include "metatile_behavior.h"
#include "npc_trade.h"
#include "overlay_01.h"
#include "player_avatar_actions.h"
#include "headbutt_encounter.h"
#include "overlay_03.h"
#include "overlay_04.h"
#include "mailbox_app.h"
#include "overlay_26.h"
#include "battle_room_results.h"
#include "overlay_87.h"
#include "party_menu.h"
#include "player_avatar.h"
#include "pokedex.h"
#include "pokewalker.h"
#include "render_text.h"
#include "render_window.h"
#include "safari_zone.h"
#include "save_arrays.h"
#include "save_follow_mon.h"
#include "save_link_ruleset.h"
#include "save_local_field_data.h"
#include "scrcmd.h"
#include "screen_fade.h"
#include "script_pokemon_util.h"
#include "sound_system.h"
#include "sys_flags.h"
#include "sys_vars.h"
#include "system.h"
#include "task.h"
#include "text.h"
#include "trainer_memo.h"
#include "friend_roster.h"
#include "comm_wireless.h"
#include "communication_core.h"
#include "link_synchronization.h"
#include "comm_state.h"
#include "wireless_status_icon.h"
#include "field_terrain.h"
#include "field_overworld_transition.h"
#include "field_overworld_restore.h"
#include "field_time_events.h"
#include "field_transition_tasks.h"
#include "comm_player_manager.h"
#include "communication_club_link.h"
#include "union_room.h"
#include "union_room_talk.h"
#include "union_room_objects.h"
#include "union_room_avatar.h"
#include "field_misc_util.h"
#include "map_object_movement_utilities.h"
#include "map_object_movement_commands.h"
#include "map_object_follow.h"
#include "field_warp_reset_suppress.h"
#include "trainer_card_data.h"
#include "scrcmd_link_sync.h"
#include "field_misc_events.h"
#include "wifi_club.h"
#include "field_comm_cmds.h"
#include "gear_phone_ring_manager.h"
#include "phone_rematch.h"
#include "pokeathlon_course_task.h"
#include "battle_greeting_task.h"
#include "spin_trade_flow.h"
#include "safari_zone_encounters.h"
#include "magnet_train_ride.h"
#include "ship_voyage.h"
#include "legendary_cinematic_task.h"
#include "view_rankings_task.h"
#include "swarm.h"
#include "use_item_on_mon.h"

FS_EXTERN_OVERLAY(OVY_26);
FS_EXTERN_OVERLAY(npc_trade);
FS_EXTERN_OVERLAY(OVY_20);
FS_EXTERN_OVERLAY(bug_contest);
FS_EXTERN_OVERLAY(OVY_21);
FS_EXTERN_OVERLAY(OVY_22);
FS_EXTERN_OVERLAY(OVY_25);

BOOL NativeScript_WaitYesNo(ScriptContext *ctx);
BOOL ScrNative_WaitMonPicAnim(ScriptContext *ctx);
BOOL ScrNative_WaitApplication(ScriptContext *ctx);
LocalMapObject *Script_GetMapObjectByPerson(FieldSystem *fieldSystem, u16 person);
void _ScheduleObjectEventMovement(FieldSystem *fieldSystem, EventObjectMovementMan *movementMan, MovementScriptCommand *cmds);
void Script_SetMonSeenFlagBySpecies(FieldSystem *fieldSystem, u16 species);

#include "data/fieldmap.h"

static const WindowTemplate _020FAC94 = {
    .bgId = 3,
    .left = 25,
    .top = 13,
    .width = 6,
    .height = 4,
    .palette = 13,
    .baseTile = 0x021F,
};

static const u8 sConditionTable[6][3] = {
    //<  =  >
    { 1, 0, 0 }, // lt
    { 0, 1, 0 }, // eq
    { 0, 0, 1 }, // gt
    { 1, 1, 0 }, // le
    { 0, 1, 1 }, // ge
    { 1, 0, 1 }, // ne
};

static u8 _021D415C;

BOOL ScrCmd_Nop(ScriptContext *ctx) {
#pragma unused(ctx)
    return FALSE;
}

BOOL ScrCmd_Dummy(ScriptContext *ctx) {
#pragma unused(ctx)
    return FALSE;
}

BOOL ScrCmd_End(ScriptContext *ctx) {
    StopScript(ctx);
    return FALSE;
}

static BOOL RunPauseTimer(ScriptContext *ctx);

BOOL ScrCmd_Wait(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 frames_to_wait = ScriptReadHalfword(ctx);
    u16 ptr_offset = ScriptReadHalfword(ctx);
    u16 *ret_ptr = GetVarPointer(fieldSystem, ptr_offset);
    *ret_ptr = frames_to_wait;

    ctx->data[0] = ptr_offset;
    SetupNativeScript(ctx, RunPauseTimer);

    return TRUE;
}

static BOOL RunPauseTimer(ScriptContext *ctx) {
    u16 *frames_to_wait = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    (*frames_to_wait)--;

    return *frames_to_wait == 0;
}

BOOL ScrCmd_DebugWatch(ScriptContext *ctx) {
    u16 unused_var = ScriptGetVar(ctx);
    return FALSE;
}

BOOL ScrCmd_LoadByte(ScriptContext *ctx) {
    u8 reg = ScriptReadByte(ctx);
    u8 value = ScriptReadByte(ctx);

    ctx->data[reg] = value;

    return FALSE;
}

BOOL ScrCmd_LoadWord(ScriptContext *ctx) {
    u8 reg = ScriptReadByte(ctx);
    u32 value = ScriptReadWord(ctx);

    ctx->data[reg] = value;

    return FALSE;
}

BOOL ScrCmd_LoadByteFromAddr(ScriptContext *ctx) {
    u8 reg = ScriptReadByte(ctx);
    u8 *address = (u8 *)ScriptReadWord(ctx);

    ctx->data[reg] = *address;

    return FALSE;
}

BOOL ScrCmd_WriteByteToAddr(ScriptContext *ctx) {
    u8 *address = (u8 *)ScriptReadWord(ctx);
    *address = ScriptReadByte(ctx);

    return FALSE;
}

BOOL ScrCmd_SetPtrByte(ScriptContext *ctx) {
    u8 *address = (u8 *)ScriptReadWord(ctx);
    u8 reg = ScriptReadByte(ctx);

    *address = ctx->data[reg];

    return FALSE;
}

BOOL ScrCmd_CopyLocal(ScriptContext *ctx) {
    u8 dest_reg = ScriptReadByte(ctx);
    u8 src_reg = ScriptReadByte(ctx);

    ctx->data[dest_reg] = ctx->data[src_reg];

    return FALSE;
}

BOOL ScrCmd_CopyByte(ScriptContext *ctx) {
    u8 *dest_address = (u8 *)ScriptReadWord(ctx);
    u8 *src_address = (u8 *)ScriptReadWord(ctx);

    *dest_address = *src_address;

    return FALSE;
}

static u8 Compare(u32 a, u32 b) {
    if (a < b) {
        return SCRIPT_COMPARISON_RESULT_LESS;
    } else if (a == b) {
        return SCRIPT_COMPARISON_RESULT_EQUAL;
    } else {
        return SCRIPT_COMPARISON_RESULT_GREATER;
    }
}

BOOL ScrCmd_CompareLocalToLocal(ScriptContext *ctx) {
    u8 a = ctx->data[ScriptReadByte(ctx)];
    u8 b = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareLocalToValue(ScriptContext *ctx) {
    u8 a = ctx->data[ScriptReadByte(ctx)];
    u8 b = ScriptReadByte(ctx);

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareLocalToAddr(ScriptContext *ctx) {
    u8 a = ctx->data[ScriptReadByte(ctx)];
    u8 b = *(u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareAddrToLocal(ScriptContext *ctx) {
    u8 a = *(u8 *)ScriptReadWord(ctx);
    u8 b = ctx->data[ScriptReadByte(ctx)];

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareAddrToValue(ScriptContext *ctx) {
    u8 a = *(u8 *)ScriptReadWord(ctx);
    u8 b = ScriptReadByte(ctx);

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareAddrToAddr(ScriptContext *ctx) {
    u8 a = *(u8 *)ScriptReadWord(ctx);
    u8 b = *(u8 *)ScriptReadWord(ctx);

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareVarToValue(ScriptContext *ctx) {
    u16 a = *ScriptGetVarPointer(ctx);
    u16 b = ScriptReadHalfword(ctx);

    ctx->comparisonResult = Compare(a, b);

    return FALSE;
}

BOOL ScrCmd_CompareVarToVar(ScriptContext *ctx) {
    u16 *a_ptr = ScriptGetVarPointer(ctx);
    u16 *b_ptr = ScriptGetVarPointer(ctx);

    ctx->comparisonResult = Compare(*a_ptr, *b_ptr);

    return FALSE;
}

BOOL ScrCmd_RunScript(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *num_active_script_contexts = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_CONTEXT_COUNT);
    ScriptContext **new_context_ptr = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SCRIPT_CONTEXT_1);

    u16 script_to_run = ScriptReadHalfword(ctx);
    *new_context_ptr = CreateScriptContext(fieldSystem, script_to_run);
    (*num_active_script_contexts)++;

    return TRUE;
}

static BOOL ScrNative_WaitStd(ScriptContext *ctx);

BOOL ScrCmd_CallStd(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *stdWaitFlags = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_FIELD_07);
    u8 *num_active_script_contexts = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_CONTEXT_COUNT);
    ScriptContext **new_context_ptr = (ScriptContext **)FieldSysGetAttrAddr(fieldSystem, (ScriptEnvField)(SCRIPTENV_SCRIPT_CONTEXT_0 + *num_active_script_contexts));

    u16 script_to_run = ScriptReadHalfword(ctx);
    ScriptContext *new_context = CreateScriptContext(fieldSystem, script_to_run);
    *new_context_ptr = new_context;

    new_context->id = *num_active_script_contexts;
    (*num_active_script_contexts)++;

    *stdWaitFlags |= (1 << ctx->id);

    SetupNativeScript(ctx, ScrNative_WaitStd);
    return TRUE;
}

static BOOL ScrNative_WaitStd(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *stdWaitFlags = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_FIELD_07);
    u8 *unused = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_CONTEXT_COUNT);

    return (*stdWaitFlags & (1 << ctx->id)) == 0;
}

BOOL ScrCmd_RestartCurrentScript(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *stdWaitFlags = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_FIELD_07);
    u8 *unused = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_CONTEXT_COUNT);

    *stdWaitFlags ^= (1 << (ctx->id - 1));
    return FALSE;
}

BOOL ScrCmd_GoTo(ScriptContext *ctx) {
    u32 offset_in_script = ScriptReadWord(ctx);
    ScriptJump(ctx, ctx->script_ptr + offset_in_script);

    return FALSE;
}

BOOL ScrCmd_ObjectGoTo(ScriptContext *ctx) {
    LocalMapObject **lmo = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u8 id = ScriptReadByte(ctx);

    u32 offset_in_script = ScriptReadWord(ctx);
    if (id == MapObject_GetID(*lmo)) {
        ScriptJump(ctx, ctx->script_ptr + offset_in_script);
    }

    return FALSE;
}

BOOL ScrCmd_BGGoTo(ScriptContext *ctx) {
    u32 bg = TaskManager_GetBgGoToId(ctx->taskman);
    u8 required_bg = ScriptReadByte(ctx);

    u32 offset_in_script = ScriptReadWord(ctx);
    if (bg == required_bg) {
        ScriptJump(ctx, ctx->script_ptr + offset_in_script);
    }

    return FALSE;
}

BOOL ScrCmd_DirectionGoTo(ScriptContext *ctx) {
    u32 *direction = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_FACING_DIRECTION);
    u8 required_direction = ScriptReadByte(ctx);

    u32 offset_in_script = ScriptReadWord(ctx);
    if (*direction == required_direction) {
        ScriptJump(ctx, ctx->script_ptr + offset_in_script);
    }

    return FALSE;
}

BOOL ScrCmd_Call(ScriptContext *ctx) {
    u32 offset_in_script = ScriptReadWord(ctx);
    ScriptCall(ctx, ctx->script_ptr + offset_in_script);

    return FALSE;
}

BOOL ScrCmd_Return(ScriptContext *ctx) {
    ScriptReturn(ctx);
    return FALSE;
}

BOOL ScrCmd_GoToIf(ScriptContext *ctx) {
    u8 condition = ScriptReadByte(ctx);
    u32 offset_in_script = ScriptReadWord(ctx);

    if (sConditionTable[condition][ctx->comparisonResult] == 1) {
        ScriptJump(ctx, ctx->script_ptr + offset_in_script);
    }

    return FALSE;
}

BOOL ScrCmd_CallIf(ScriptContext *ctx) {
    u8 condition = ScriptReadByte(ctx);
    u32 offset_in_script = ScriptReadWord(ctx);

    if (sConditionTable[condition][ctx->comparisonResult] == 1) {
        ScriptCall(ctx, ctx->script_ptr + offset_in_script);
    }

    return FALSE;
}

BOOL ScrCmd_SetFlag(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag_to_set = ScriptReadHalfword(ctx);

    FieldSystem_FlagSet(fieldSystem, flag_to_set);

    return FALSE;
}

BOOL ScrCmd_ClearFlag(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag_to_clear = ScriptReadHalfword(ctx);

    FieldSystem_FlagClear(fieldSystem, flag_to_clear);

    return FALSE;
}

BOOL ScrCmd_CheckFlag(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag_to_check = ScriptReadHalfword(ctx);

    ctx->comparisonResult = FieldSystem_FlagCheck(fieldSystem, flag_to_check);

    return FALSE;
}

BOOL ScrCmd_CheckFlagVar(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *flag_in_var_to_check = ScriptGetVarPointer(ctx);
    u16 *ret_ptr = ScriptGetVarPointer(ctx);

    *ret_ptr = FieldSystem_FlagCheck(fieldSystem, *flag_in_var_to_check);

    return FALSE;
}

BOOL ScrCmd_SetFlagVar(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *flag_in_var_to_set = ScriptGetVarPointer(ctx);

    FieldSystem_FlagSet(fieldSystem, *flag_in_var_to_set);

    return FALSE;
}

BOOL ScrCmd_ClearFlagVar(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *flag_in_var_to_clear = ScriptGetVarPointer(ctx);

    FieldSystem_FlagClear(fieldSystem, *flag_in_var_to_clear);

    return FALSE;
}

BOOL ScrCmd_SetTrainerFlag(ScriptContext *ctx) {
    u16 flag_to_set = ScriptGetVar(ctx);

    TrainerFlagSet(ctx->fieldSystem->saveData, flag_to_set);

    return FALSE;
}

BOOL ScrCmd_ClearTrainerFlag(ScriptContext *ctx) {
    u16 flag_to_clear = ScriptGetVar(ctx);

    TrainerFlagClear(ctx->fieldSystem->saveData, flag_to_clear);

    return FALSE;
}

BOOL ScrCmd_CheckTrainerFlag(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 flag_to_check = ScriptGetVar(ctx);

    ctx->comparisonResult = TrainerFlagCheck(fieldSystem->saveData, flag_to_check);

    return FALSE;
}

BOOL ScrCmd_AddVar(ScriptContext *ctx) {
    u16 *dest_var = ScriptGetVarPointer(ctx);
    u16 addend = ScriptGetVar(ctx);

    *dest_var += addend;

    return FALSE;
}

BOOL ScrCmd_SubVar(ScriptContext *ctx) {
    u16 *dest_var = ScriptGetVarPointer(ctx);
    u16 subtrahend = ScriptGetVar(ctx);

    *dest_var -= subtrahend;

    return FALSE;
}

BOOL ScrCmd_SetVar(ScriptContext *ctx) {
    u16 *dest_var = ScriptGetVarPointer(ctx);
    u16 value = ScriptReadHalfword(ctx);

    *dest_var = value;

    return FALSE;
}

BOOL ScrCmd_CopyVar(ScriptContext *ctx) {
    u16 *dest_var = ScriptGetVarPointer(ctx);
    u16 *src_var = ScriptGetVarPointer(ctx);

    *dest_var = *src_var;

    return FALSE;
}

BOOL ScrCmd_SetOrCopyVar(ScriptContext *ctx) {
    u16 *dest_var = ScriptGetVarPointer(ctx);
    u16 src_var = ScriptGetVar(ctx);

    *dest_var = src_var;

    return FALSE;
}

BOOL ScrCmd_NPCMsgAutoScrollInLink(ScriptContext *ctx) {
    u8 msg_no = ScriptReadByte(ctx);

    if (!Comm_IsActive()) {
        ovFieldMain_ShowMessage(ctx, ctx->msgdata, msg_no, TRUE, NULL);
    } else {
        struct MessagePrintOptions printOptions;
        ovFieldMain_InitMessagePrintOptions(&printOptions, ctx);
        printOptions.textFrameDelay = 1;
        printOptions.autoScroll = 1;
        ovFieldMain_ShowMessage(ctx, ctx->msgdata, msg_no, FALSE, &printOptions);
    }

    SetupNativeScript(ctx, ScrNative_WaitTextPrinter);
    return TRUE;
}

static BOOL NativeScript_WaitABPress(ScriptContext *ctx);

BOOL ScrCmd_WaitABPress(ScriptContext *ctx) {
    SetupNativeScript(ctx, NativeScript_WaitABPress);
    return TRUE;
}

static BOOL NativeScript_WaitABPress(ScriptContext *ctx) {
    return (gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) != 0;
}

static BOOL NativeScript_WaitButtonOrDelay(ScriptContext *ctx);

BOOL ScrCmd_WaitButtonOrDelay(ScriptContext *ctx) {
    ctx->data[0] = ScriptGetVar(ctx);
    SetupNativeScript(ctx, NativeScript_WaitButtonOrDelay);
    return TRUE;
}

static BOOL NativeScript_WaitButtonOrDelay(ScriptContext *ctx) {
    if ((gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) != 0) {
        return TRUE;
    }

    return --ctx->data[0] == 0;
}

static BOOL NativeScript_WaitButton(ScriptContext *ctx);

BOOL ScrCmd_WaitButton(ScriptContext *ctx) {
    SetupNativeScript(ctx, NativeScript_WaitButton);
    return TRUE;
}

static BOOL NativeScript_WaitButton(ScriptContext *ctx) {
    int new_keys = gSystem.newKeys;

    if ((new_keys & (PAD_BUTTON_A | PAD_BUTTON_B)) != 0) {
        return TRUE;
    }

    if ((new_keys & PAD_KEY_UP) != 0) {
        PlayerAvatar_SetFacingDirection(ctx->fieldSystem->playerAvatar, DIR_NORTH);
    } else if ((new_keys & PAD_KEY_DOWN) != 0) {
        PlayerAvatar_SetFacingDirection(ctx->fieldSystem->playerAvatar, DIR_SOUTH);
    } else if ((new_keys & PAD_KEY_LEFT) != 0) {
        PlayerAvatar_SetFacingDirection(ctx->fieldSystem->playerAvatar, DIR_WEST);
    } else if ((new_keys & PAD_KEY_RIGHT) != 0) {
        PlayerAvatar_SetFacingDirection(ctx->fieldSystem->playerAvatar, DIR_EAST);
    } else {
        return FALSE;
    }

    return TRUE;
}

static BOOL NativeScript_WaitButtonOrDpad(ScriptContext *ctx);

BOOL ScrCmd_WaitButtonOrDpad(ScriptContext *ctx) {
    SetupNativeScript(ctx, NativeScript_WaitButtonOrDpad);
    return TRUE;
}

static BOOL NativeScript_WaitButtonOrDpad(ScriptContext *ctx) {
    if ((gSystem.newKeys & (PAD_BUTTON_A | PAD_BUTTON_B)) != 0) {
        return TRUE;
    }

    if ((gSystem.newKeys & (PAD_KEY_UP | PAD_KEY_DOWN | PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
        return TRUE;
    }

    return FALSE;
}

BOOL ScrCmd_OpenMsg(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *windowOpen = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_FIELD_08);

    DialogBox_AddWindowToLayer3(fieldSystem->bgConfig, FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), GF_BG_LYR_MAIN_3);
    DialogBox_LoadFrame(FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData));

    fieldSystem->textbox_open = TRUE;
    *windowOpen = 1;

    return FALSE;
}

BOOL ScrCmd_CloseMsg(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    Window *window = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW);
    u8 *windowOpen = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_FIELD_08);

    ClearFrameAndWindow2(window, 0);
    RemoveWindow(window);

    fieldSystem->textbox_open = FALSE;
    *windowOpen = 0;

    return FALSE;
}

BOOL ScrCmd_HoldMsg(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    Window *window = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW);
    u8 *windowOpen = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_FIELD_08);

    RemoveWindow(window);

    fieldSystem->textbox_open = FALSE;
    *windowOpen = 0;

    return FALSE;
}

static BOOL NativeScript_ScrollMsgBg(ScriptContext *ctx);

BOOL ScrCmd_ScrollMsgBg(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *var_8008 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8008);
    u16 *var_8004 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8004);
    u16 *var_8009 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8009);
    u16 *var_800A = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800A);
    u16 *var_8005 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8005);
    u16 *var_800B = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800B);

    *var_8008 = ScriptReadByte(ctx);
    *var_8004 = ScriptReadByte(ctx);
    *var_8009 = ScriptReadByte(ctx);
    *var_800A = ScriptReadByte(ctx);
    *var_8005 = ScriptReadByte(ctx);
    *var_800B = ScriptReadByte(ctx);

    SetupNativeScript(ctx, NativeScript_ScrollMsgBg);
    return TRUE;
}

static BOOL NativeScript_ScrollMsgBg(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *var_8008 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8008);
    u16 *var_8009 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8009);
    u16 *var_800A = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800A);
    u16 *var_800B = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_800B);
    u16 *var_8004 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8004);
    u16 *var_8005 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SPECIAL_VAR_8005);

    if (*var_8004 == 0 && *var_8005 == 0) {
        return TRUE;
    }

    if (*var_8008 != 0) {
        if (*var_8009 == 0) {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_X, *var_8008);
        } else {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SUB_X, *var_8008);
        }
    }

    if (*var_800A != 0) {
        if (*var_800B == 0) {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_ADD_Y, *var_800A);
        } else {
            BgSetPosTextAndCommit(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, BG_POS_OP_SUB_Y, *var_800A);
        }
    }

    if (*var_8004 != 0) {
        (*var_8004)--;
    }

    if (*var_8005 != 0) {
        (*var_8005)--;
    }

    return FALSE;
}

BOOL ScrCmd_DirectionSignpost(ScriptContext *ctx) {
    u8 type;

    FieldSystem *fieldSystem = ctx->fieldSystem;
    String **tmp_str = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_1);
    String **pStrBuf = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_0);
    MessageFormat **msg_fmt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 msg_no = ScriptReadByte(ctx);
    type = ScriptReadByte(ctx);
    u16 map = ScriptReadHalfword(ctx);
    u16 unused_result_var_id = ScriptReadHalfword(ctx);

    fieldSystem->textbox_open = TRUE;

    Signpost_SetParam(fieldSystem->signpost, type, map);
    Signpost_SetCommand(fieldSystem->signpost, MAPSIGNCOMMAND_SHOW);
    Signpost_DoCurrentCommand(fieldSystem);

    ReadMsgDataIntoString(ctx->msgdata, msg_no, *tmp_str);
    StringExpandPlaceholders(*msg_fmt, *pStrBuf, *tmp_str);
    Window *window = Signpost_GetWindow(fieldSystem->signpost);
    AddTextPrinterParameterizedWithColor(window, 1, *pStrBuf, 0, 0, TEXT_SPEED_INSTANT, MAKE_TEXT_COLOR(2, 10, 15), NULL);

    return TRUE;
}

BOOL ScrCmd_SetSignpostMap(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 type = ScriptReadByte(ctx);
    u16 map = ScriptReadHalfword(ctx);

    fieldSystem->textbox_open = TRUE;

    Signpost_SetParam(fieldSystem->signpost, type, map);
    Signpost_SetCommand(fieldSystem->signpost, MAPSIGNCOMMAND_SHOW);

    return TRUE;
}

BOOL ScrCmd_SetSignpostAction(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    Signpost_SetCommand(fieldSystem->signpost, ScriptReadByte(ctx));
    return TRUE;
}

static BOOL NativeScript_WaitSignpostAction(ScriptContext *ctx);

BOOL ScrCmd_WaitSignpostAction(ScriptContext *ctx) {
    if (Signpost_CommandIsFinished(ctx->fieldSystem->signpost) == TRUE) {
        return FALSE;
    }

    SetupNativeScript(ctx, NativeScript_WaitSignpostAction);
    return TRUE;
}

static BOOL NativeScript_WaitSignpostAction(ScriptContext *ctx) {
    return Signpost_CommandIsFinished(ctx->fieldSystem->signpost) == TRUE;
}

static BOOL NativeScript_WaitTrainerTips(ScriptContext *ctx);

BOOL ScrCmd_TrainerTips(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *printer_id_ptr = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);
    String **pUnformattedString = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_1);
    String **pFormattedString = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_0);
    MessageFormat **msg_fmt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 msg_no = ScriptReadByte(ctx);
    u16 result_var_id = ScriptReadHalfword(ctx);

    ReadMsgDataIntoString(ctx->msgdata, msg_no, *pUnformattedString);
    StringExpandPlaceholders(*msg_fmt, *pFormattedString, *pUnformattedString);

    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(AUTO_SCROLL_OFF);
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);

    Window *window = Signpost_GetWindow(fieldSystem->signpost);
    u8 text_speed = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(fieldSystem->saveData));
    *printer_id_ptr = AddTextPrinterParameterizedWithColor(window, 1, *pFormattedString, 0, 0, text_speed, MAKE_TEXT_COLOR(2, 10, 15), NULL);

    ctx->data[0] = result_var_id;
    SetupNativeScript(ctx, NativeScript_WaitTrainerTips);
    return TRUE;
}

static BOOL NativeScript_WaitTrainerTips(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 *printer_id_ptr = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);
    u16 *ret_ptr = GetVarPointer(fieldSystem, ctx->data[0]);
    u8 unused = Signpost_GetType(fieldSystem->signpost);

    u16 direction = 0xFFFF;

    if (DialogBox_IsPrintFinished(*printer_id_ptr) == TRUE) {
        *ret_ptr = 2;
        return TRUE;
    }

    int new_keys = gSystem.newKeys;
    if ((new_keys & PAD_KEY_UP) != 0) {
        direction = DIR_NORTH;
    } else if ((new_keys & PAD_KEY_DOWN) != 0) {
        direction = DIR_SOUTH;
    } else if ((new_keys & PAD_KEY_LEFT) != 0) {
        direction = DIR_WEST;
    } else if ((new_keys & PAD_KEY_RIGHT) != 0) {
        direction = DIR_EAST;
    }

    if (direction != 0xFFFF) {
        RemoveTextPrinter(*printer_id_ptr);
        PlayerAvatar_SetFacingDirection(ctx->fieldSystem->playerAvatar, direction);
        *ret_ptr = 0;
        ctx->fieldSystem->textbox_open = FALSE;
        return TRUE;
    }

    return FALSE;
}

static BOOL NativeScript_WaitSignpost(ScriptContext *ctx);

BOOL ScrCmd_WaitSignpost(ScriptContext *ctx) {
    ctx->data[0] = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, NativeScript_WaitSignpost);
    return TRUE;
}

static BOOL NativeScript_WaitSignpost(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *ret_ptr = GetVarPointer(fieldSystem, ctx->data[0]);
    u16 direction = 0xFFFF;
    int new_keys = gSystem.newKeys;

    if ((new_keys & (PAD_BUTTON_A | PAD_BUTTON_B)) != 0) {
        *ret_ptr = 0;
        fieldSystem->textbox_open = FALSE;
        return TRUE;
    }

    if ((new_keys & PAD_KEY_UP) != 0) {
        direction = DIR_NORTH;
    } else if ((new_keys & PAD_KEY_DOWN) != 0) {
        direction = DIR_SOUTH;
    } else if ((new_keys & PAD_KEY_LEFT) != 0) {
        direction = DIR_WEST;
    } else if ((new_keys & PAD_KEY_RIGHT) != 0) {
        direction = DIR_EAST;
    }

    if (direction != 0xFFFF) {
        PlayerAvatar_SetFacingDirection(ctx->fieldSystem->playerAvatar, direction);
        *ret_ptr = 0;
        fieldSystem->textbox_open = FALSE;
        return TRUE;
    }

    return FALSE;
}

BOOL ScrCmd_ReopenStartMenuOnEnd(ScriptContext *ctx) {
    Script_ReopenStartMenuOnEnd(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_YesNo(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    struct ListMenu2D **listMenu2D = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LIST_MENU_2D);
    u16 data = ScriptReadHalfword(ctx);
    LoadUserFrameGfx1(fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, HEAP_ID_FIELD1);
    *listMenu2D = Std_CreateYesNoMenu(fieldSystem->bgConfig, &_020FAC94, 0x3D9, 11, HEAP_ID_FIELD1);
    ctx->data[0] = data;
    SetupNativeScript(ctx, NativeScript_WaitYesNo);
    return TRUE;
}

BOOL NativeScript_WaitYesNo(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    struct ListMenu2D **listMenu2D = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LIST_MENU_2D);
    u16 *ret_p = GetVarPointer(fieldSystem, ctx->data[0]);
    int selection = Handle2dMenuInput_DeleteOnFinish(*listMenu2D, HEAP_ID_FIELD1);
    if (selection == LIST_NOTHING_CHOSEN) {
        return FALSE;
    } else {
        if (selection == 0) {
            *ret_p = 0; // yes
        } else {
            *ret_p = 1; // no
        }
        return TRUE;
    }
}

BOOL ScrCmd_AddWaitingIcon(ScriptContext *ctx) {
    Window *window = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW);
    WaitingIcon **waitingIcon = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WAITING_ICON);
    *waitingIcon = WaitingIcon_New(window, 0x3E2);
    return FALSE;
}

BOOL ScrCmd_RemoveWaitingIcon(ScriptContext *ctx) {
    WaitingIcon **waitingIcon = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WAITING_ICON);
    WaitingIcon_Delete(*waitingIcon);
    return FALSE;
}

static void Script_CreateMenuFromArgs(ScriptContext *ctx, struct ScriptMenu **outMenu, MsgData *msgData) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    MessageFormat **msgFmt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    u8 initCursorPos = ScriptReadByte(ctx);
    u8 cancellable = ScriptReadByte(ctx);
    u16 var = ScriptReadHalfword(ctx);
    *outMenu = ScriptMenu_Create(fieldSystem, x, y, initCursorPos, cancellable, GetVarPointer(fieldSystem, var), *msgFmt, FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_WINDOW), msgData);
    ctx->data[0] = var;
}

BOOL ScrCmd_MultichoiceInitStdGmm(ScriptContext *ctx) {
    Script_CreateMenuFromArgs(ctx, FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW), NULL);
    return TRUE;
}

BOOL ScrCmd_MultichoiceInit(ScriptContext *ctx) {
    Script_CreateMenuFromArgs(ctx, FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW), ctx->msgdata);
    return TRUE;
}

BOOL ScrCmd_MultichoiceItemAdd(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u8 msgId = ScriptReadByte(ctx);
    u8 value = ScriptReadByte(ctx);
    ScriptMenu_AddItem(*pp_menu, msgId, value);
    return FALSE;
}

BOOL ScrCmd_MultichoiceAddItemVar(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u16 msgId = ScriptGetVar(ctx);
    u16 value = ScriptGetVar(ctx);
    ScriptMenu_AddItem(*pp_menu, msgId, value);
    return FALSE;
}

BOOL NativeScript_WaitMultichoice(ScriptContext *ctx);

BOOL ScrCmd_MultichoiceExec(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ScriptMenu_ShowMultichoice(*pp_menu);
    SetupNativeScript(ctx, NativeScript_WaitMultichoice);
    return TRUE;
}

BOOL NativeScript_WaitMultichoice(ScriptContext *ctx) {
    return *GetVarPointer(ctx->fieldSystem, ctx->data[0]) != 0xEEEE;
}

BOOL NativeScript_WaitMultichoiceUnionRoom(ScriptContext *ctx);

BOOL ScrCmd_MultichoiceShowUnionRoom(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ScriptMenu_ShowMultichoice(*pp_menu);
    SetupNativeScript(ctx, NativeScript_WaitMultichoiceUnionRoom);
    return TRUE;
}

BOOL NativeScript_WaitMultichoiceUnionRoom(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_var = GetVarPointer(fieldSystem, ctx->data[0]);
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MENU_WINDOW);
    if (*p_var == 0xEEEE) {
        if (UnionRoom_PartnerCancelled(fieldSystem->unionRoom)) {
            *p_var = 8;
            ScriptMenu_CloseMultichoice(*pp_menu);
            return TRUE;
        } else {
            return FALSE;
        }
    } else {
        return TRUE;
    }
}

BOOL ScrCmd_ScriptListMenuInitStdGmm(ScriptContext *ctx) {
    Script_CreateMenuFromArgs(ctx, FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW), NULL);
    return TRUE;
}

BOOL ScrCmd_ScriptListMenuInit(ScriptContext *ctx) {
    Script_CreateMenuFromArgs(ctx, FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW), ctx->msgdata);
    return TRUE;
}

BOOL ScrCmd_ScriptListMenuItemAdd(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u16 msgId = ScriptGetVar(ctx);
    u16 helpMsgId = ScriptGetVar(ctx);
    u16 value = ScriptGetVar(ctx);
    ScriptMenu_AddListItem(*pp_menu, (u8)msgId, (u8)helpMsgId, (u8)value);
    return FALSE;
}

BOOL ScrCmd_ScriptListMenuExec(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    ScriptMenu_ShowList(*pp_menu);
    SetupNativeScript(ctx, NativeScript_WaitMultichoice);
    return TRUE;
}

BOOL ScrCmd_MultichoiceShowListWithWidth(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u16 var = ScriptGetVar(ctx);
    ScriptMenu_ShowListWithWidth(*pp_menu, var);
    SetupNativeScript(ctx, NativeScript_WaitMultichoice);
    return TRUE;
}

BOOL ScrCmd_MultichoiceShowListAtPosition(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u16 *scrollPtr = ScriptGetVarPointer(ctx);
    u16 *rowPtr = ScriptGetVarPointer(ctx);
    ScriptMenu_ShowListAtPosition(*pp_menu, scrollPtr, rowPtr);
    SetupNativeScript(ctx, NativeScript_WaitMultichoice);
    return TRUE;
}

BOOL ScrCmd_MultichoiceGridExec(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u8 val = ScriptReadByte(ctx);
    ScriptMenu_ShowMultichoiceGrid(*pp_menu, val);
    SetupNativeScript(ctx, NativeScript_WaitMultichoice);
    return TRUE;
}

BOOL ScrCmd_MultichoiceSetAnchorRight(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u8 val = ScriptReadByte(ctx);
    ScriptMenu_SetAnchorRight(*pp_menu, val);
    return TRUE;
}

BOOL ScrCmd_MultichoiceSetAnchorBottom(ScriptContext *ctx) {
    struct ScriptMenu **pp_menu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MENU_WINDOW);
    u8 val = ScriptReadByte(ctx);
    ScriptMenu_SetAnchorBottom(*pp_menu, val);
    return TRUE;
}

BOOL ScrCmd_ApplyMovement(ScriptContext *ctx) {
    u16 person = ScriptGetVar(ctx);
    u32 offset = ScriptReadWord(ctx);
    LocalMapObject *object = Script_GetMapObjectByPerson(ctx->fieldSystem, person);
    EventObjectMovementMan *movementMan;
    u8 *movementCounter;

    if (object == NULL) {
        GF_ASSERT(person == obj_partner_poke);
        return FALSE;
    }
    if (person == obj_partner_poke) {
        FollowMonDraw_ClearBob(object);
    }
    movementMan = EventObjectMovementMan_Create(object, (const MovementScriptCommand *)(ctx->script_ptr + offset));
    movementCounter = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);
    (*movementCounter)++;
    _ScheduleObjectEventMovement(ctx->fieldSystem, movementMan, NULL);
    return FALSE;
}

BOOL ScrCmd_WalkPersonToCoords(ScriptContext *ctx) {
    u16 person = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 z = ScriptGetVar(ctx);
    u16 now_x, now_z;
    int i;
    LocalMapObject *object = Script_GetMapObjectByPerson(ctx->fieldSystem, person);
    MovementScriptCommand *cmd;
    EventObjectMovementMan *movementMan;
    u8 *movementCounter;

    GF_ASSERT(object != NULL);
    cmd = Heap_Alloc(HEAP_ID_FIELD1, 64 * sizeof(MovementScriptCommand));
    now_x = MapObject_GetXCoord(object);
    now_z = MapObject_GetZCoord(object);
    i = 0;
    if (now_x < x) {
        cmd[i].command = MOVEMENT_STEP_RIGHT;
        cmd[i].length = x - now_x;
        i++;
    } else if (now_x > x) {
        cmd[i].command = MOVEMENT_STEP_LEFT;
        cmd[i].length = now_x - x;
        i++;
    }
    if (now_z < z) {
        cmd[i].command = MOVEMENT_STEP_UP;
        cmd[i].length = z - now_z;
        i++;
    } else if (now_z > z) {
        cmd[i].command = MOVEMENT_STEP_DOWN;
        cmd[i].length = now_z - z;
        i++;
    }
    cmd[i].command = MOVEMENT_STEP_END;
    cmd[i].length = 0;

    movementMan = EventObjectMovementMan_Create(object, cmd);
    movementCounter = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);
    (*movementCounter)++;
    _ScheduleObjectEventMovement(ctx->fieldSystem, movementMan, cmd);
    return FALSE;
}

LocalMapObject *Script_GetMapObjectByPerson(FieldSystem *fieldSystem, u16 person) {
    if (person == 0xF2) {
        return MapObjectManager_GetFirstActiveObjectWithMovement(fieldSystem->mapObjectManager, 0x30);
    } else if (person == 0xF1) {
        LocalMapObject **attr = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_CAMERA_TARGET);
        return *attr;
    } else {
        return MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, person);
    }
}

static BOOL IsAllMovementFinished(ScriptContext *ctx);

BOOL ScrCmd_WaitMovement(ScriptContext *ctx) {
    SetupNativeScript(ctx, IsAllMovementFinished);
    return TRUE;
}

static BOOL IsAllMovementFinished(ScriptContext *ctx) {
    u8 *movCounter = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);
    return *movCounter == 0;
}

struct ObjectMovementTaskEnv {
    SysTask *task;
    EventObjectMovementMan *movementMan;
    struct MovementScriptCommand *cmd;
    FieldSystem *fieldSystem;
};

void _RunObjectEventMovement(SysTask *task, struct ObjectMovementTaskEnv *env);

void _ScheduleObjectEventMovement(FieldSystem *fieldSystem, EventObjectMovementMan *movementMan, MovementScriptCommand *cmds) {
    struct ObjectMovementTaskEnv *env = Heap_Alloc(HEAP_ID_FIELD1, sizeof(struct ObjectMovementTaskEnv));
    if (env == NULL) {
        GF_ASSERT(FALSE);
        return;
    }
    env->fieldSystem = fieldSystem;
    env->movementMan = movementMan;
    env->cmd = cmds;
    env->task = SysTask_CreateOnMainQueue((SysTaskFunc)_RunObjectEventMovement, env, 0);
}

void _RunObjectEventMovement(SysTask *task, struct ObjectMovementTaskEnv *env) {
    u8 *movementCnt = FieldSysGetAttrAddr(env->fieldSystem, SCRIPTENV_ACTIVE_MOVEMENT_COUNTER);
    if (EventObjectMovementMan_IsFinish(env->movementMan) == TRUE) {
        EventObjectMovementMan_Delete(env->movementMan);
        SysTask_Destroy(env->task);
        if (env->cmd != NULL) {
            Heap_Free(env->cmd);
        }
        Heap_Free(env);
        if (*movementCnt == 0) {
            GF_ASSERT(FALSE);
        } else {
            (*movementCnt)--;
        }
    }
}

BOOL _WaitFollowMonPaused(ScriptContext *ctx);

BOOL ScrCmd_LockAll(ScriptContext *ctx) {
    LocalMapObject **p_lastInteracted;
    LocalMapObject *followingPoke;
    FieldSystem *fieldSystem = ctx->fieldSystem;

    p_lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    if (*p_lastInteracted == NULL) {
        MapObjectManager_PauseAllMovement(fieldSystem->mapObjectManager);
        followingPoke = FollowMon_GetMapObject(fieldSystem);
        if (FollowMon_IsActive(fieldSystem) && MapObject_CheckSingleMovement(followingPoke)) {
            MapObject_UnpauseMovement(followingPoke);
            SetupNativeScript(ctx, _WaitFollowMonPaused);
            return TRUE;
        }
    } else {
        ScrCmd_LockLastTalked(ctx);
    }
    return TRUE;
}

static inline BOOL _CheckMovementPauseWaitFlag(u8 mask) {
    return _021D415C & mask;
}

static inline void _SetMovementPauseWaitFlag(u8 mask) {
    _021D415C |= mask;
}

static inline void _ClearMovementPauseWaitFlag(u8 mask) {
    _021D415C &= (u8)~mask; // explicit cast is required to match
}

static inline BOOL _AllMovementPauseWaitsFinish(void) {
    return _021D415C == 0;
}

static inline void _ResetMovementPauseWaitFlags(void) {
    _021D415C = 0;
}

static BOOL _WaitMovementPauseBeforeMsg(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    LocalMapObject *playerObj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    LocalMapObject *mapObject;

    if (_CheckMovementPauseWaitFlag(1)) {
        if (MapObject_IsMovementPaused(playerObj) == TRUE) {
            MapObject_PauseMovement(playerObj);
            _ClearMovementPauseWaitFlag(1);
        }
    }

    if (_CheckMovementPauseWaitFlag(4)) {
        if (MapObject_CheckSingleMovement(*p_lastInteracted) == FALSE) {
            MapObject_PauseMovement(*p_lastInteracted);
            _ClearMovementPauseWaitFlag(4);
        }
    }

    if (_CheckMovementPauseWaitFlag(2)) {
        mapObject = MapObjectManager_GetFirstActiveObjectWithMovement(fieldSystem->mapObjectManager, 0x30);
        if (MapObject_CheckSingleMovement(mapObject) == FALSE) {
            MapObject_PauseMovement(mapObject);
            _ClearMovementPauseWaitFlag(2);
        }
    }

    if (_CheckMovementPauseWaitFlag(8)) {
        mapObject = MapObject_FindTrainerPartner(*p_lastInteracted);
        if (MapObject_CheckSingleMovement(mapObject) == FALSE) {
            MapObject_PauseMovement(mapObject);
            _ClearMovementPauseWaitFlag(8);
        }
    }

    return _AllMovementPauseWaitsFinish();
}

BOOL _WaitFollowMonPaused(ScriptContext *ctx) {
    LocalMapObject *tsurePoke = FollowMon_GetMapObject(ctx->fieldSystem);
    if (MapObject_CheckSingleMovement(tsurePoke) == FALSE) {
        MapObject_PauseMovement(tsurePoke);
        return TRUE;
    }

    return FALSE;
}

BOOL ScrCmd_LockLastTalked(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    LocalMapObject *playerObject = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    LocalMapObject *followMonObj = MapObjectManager_GetFirstActiveObjectWithMovement(fieldSystem->mapObjectManager, 0x30);
    LocalMapObject *partnerObj = MapObject_FindTrainerPartner(*p_lastInteracted);
    MapObjectManager *mapObjectManager = fieldSystem->mapObjectManager;

    _ResetMovementPauseWaitFlags();

    MapObjectManager_PauseAllMovement(mapObjectManager);

    if (MapObject_IsMovementPaused(playerObject) == FALSE) {
        _SetMovementPauseWaitFlag(1);
        MapObject_UnpauseMovement(playerObject);
    }

    if (MapObject_CheckSingleMovement(*p_lastInteracted) != FALSE) {
        _SetMovementPauseWaitFlag(4);
        MapObject_UnpauseMovement(*p_lastInteracted);
    }

    if (followMonObj != NULL && FollowMon_IsActive(fieldSystem) && MapObject_CheckSingleMovement(followMonObj) == FALSE) {
        _SetMovementPauseWaitFlag(2);
        MapObject_UnpauseMovement(followMonObj);
    }

    if (partnerObj != NULL && MapObject_CheckSingleMovement(partnerObj) != FALSE) {
        _SetMovementPauseWaitFlag(8);
        MapObject_UnpauseMovement(partnerObj);
    }

    SetupNativeScript(ctx, _WaitMovementPauseBeforeMsg);
    return TRUE;
}

BOOL ScrCmd_ReleaseAll(ScriptContext *ctx) {
    MapObjectManager_UnpauseAllMovement(ctx->fieldSystem->mapObjectManager);
    return TRUE;
}

BOOL ScrCmd_Lock(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 objectId = ScriptReadHalfword(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, objectId);
    if (object != NULL) {
        MapObject_PauseMovement(object);
    } else {
        GF_ASSERT(objectId == obj_partner_poke);
    }
    return FALSE;
}

BOOL ScrCmd_Release(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 objectId = ScriptReadHalfword(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, objectId);
    if (object != NULL) {
        MapObject_UnpauseMovement(object);
    } else {
        GF_ASSERT(objectId == obj_partner_poke);
    }
    return FALSE;
}

BOOL ScrCmd_ShowPerson(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 objectId = ScriptGetVar(ctx);
    u32 nobjs = Field_GetNumObjectEvents(fieldSystem);
    const ObjectEvent *objectEvents = Field_GetObjectEvents(fieldSystem);
    GF_ASSERT(MapObject_CreateFromObjectEventWithId(fieldSystem->mapObjectManager, objectId, nobjs, fieldSystem->location->mapId, objectEvents));
    return FALSE;
}

BOOL ScrCmd_HidePerson(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 objectId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, objectId);
    if (object == NULL) {
        GF_ASSERT(FALSE);
    } else {
        MapObject_Delete(object);
    }
    return FALSE;
}

BOOL ScrCmd_CreateCameraTarget(ScriptContext *ctx) {
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    LocalMapObject **p_cameraObj = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_CAMERA_TARGET);
    VecFx32 *pos;
    *p_cameraObj = MapObject_Create(ctx->fieldSystem->mapObjectManager, x, y, 0, SPRITE_CAMERA_FOCUS, 0, ctx->fieldSystem->location->mapId);
    MapObject_UpdateHeight(*p_cameraObj);
    MapObject_SetInvisible(*p_cameraObj, TRUE);
    MapObject_ClearFlag18(*p_cameraObj, FALSE);
    pos = MapObject_GetPositionVector(*p_cameraObj);
    MapLoadManager_TrackTarget(pos, ctx->fieldSystem->mapLoadManager);
    Camera_SetFixedTarget(pos, ctx->fieldSystem->camera);
    return FALSE;
}

BOOL ScrCmd_RemoveCameraTarget(ScriptContext *ctx) {
    LocalMapObject **p_cameraObj = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_CAMERA_TARGET);
    VecFx32 *pos;
    MapObject_Remove(*p_cameraObj);
    pos = MapObject_GetPositionVector(MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, obj_player));
    MapLoadManager_TrackTarget(pos, ctx->fieldSystem->mapLoadManager);
    Camera_SetFixedTarget(pos, ctx->fieldSystem->camera);
    return FALSE;
}

BOOL ScrCmd_CreateCameraFocusObject(ScriptContext *ctx) {
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    LocalMapObject **p_cameraObj = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_CAMERA_TARGET);
    *p_cameraObj = MapObject_Create(ctx->fieldSystem->mapObjectManager, x, y, 0, SPRITE_CAMERA_FOCUS, 0, ctx->fieldSystem->location->mapId);
    MapObject_UpdateHeight(*p_cameraObj);
    MapObject_SetInvisible(*p_cameraObj, TRUE);
    MapObject_ClearFlag18(*p_cameraObj, FALSE);
    return FALSE;
}

BOOL ScrCmd_RemoveCameraFocusObject(ScriptContext *ctx) {
    LocalMapObject **p_cameraObj = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_CAMERA_TARGET);
    MapObject_Remove(*p_cameraObj);
    return FALSE;
}

BOOL ScrCmd_FacePlayer(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u32 rvsDir = GetOppositeDirection(PlayerAvatar_GetFacingDirection(fieldSystem->playerAvatar));
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u32 oldDir;
    int x, y;
    int metatile;

    if (*p_lastInteracted == NULL) {
        return FALSE;
    }
    oldDir = MapObject_GetFacingDirection(*p_lastInteracted);
    MapObject_SetFacingAndUpdateDraw(*p_lastInteracted, rvsDir);
    if (MapObject_GetID(*p_lastInteracted) == obj_partner_poke) {
        if (FollowMonObject_IsLarge(*p_lastInteracted) && oldDir != rvsDir) {
            MapObject_GetCoordsBehind(*p_lastInteracted, &x, &y);
            metatile = GetMetatileBehavior(fieldSystem, x, y);
            if (rvsDir == 2 || rvsDir == 3) {
                if (MetatileBehavior_IsTallGrass(metatile) == TRUE) {
                    TallGrass_SpawnAt(*p_lastInteracted, FALSE, x, y, TRUE);
                } else if (MetatileBehavior_IsVeryTallGrass(metatile) == TRUE) {
                    VeryTallGrass_SpawnAt(*p_lastInteracted, FALSE, x, y, TRUE);
                }
            }
            if (MetatileBehavior_IsTallGrass(metatile) == FALSE
                && MetatileBehavior_IsVeryTallGrass(metatile) == FALSE
                && MapObject_CheckWaterBehavior(*p_lastInteracted, metatile) == FALSE
                && MetatileBehavior_IsPuddle(metatile) == FALSE
                && MetatileBehavior_IsShallowWater(metatile) == FALSE
                && MapObject_CheckSnowBehavior(*p_lastInteracted, metatile) == FALSE
                && MetatileBehavior_IsMud(metatile) == FALSE
                && MetatileBehavior_IsReflective(metatile) == FALSE) {
                MapObject_ClearFlagsBits(*p_lastInteracted, MAPOBJECTFLAG_UNK20);
            }
        }
    }
    return FALSE;
}

BOOL ScrCmd_GetPlayerCoords(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_x = ScriptGetVarPointer(ctx);
    u16 *p_z = ScriptGetVarPointer(ctx);

    *p_x = PlayerAvatar_GetXCoord(fieldSystem->playerAvatar);
    *p_z = PlayerAvatar_GetZCoord(fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_GetPersonCoords(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 personId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, personId);
    u16 *p_x = ScriptGetVarPointer(ctx);
    u16 *p_z = ScriptGetVarPointer(ctx);

    if (object != NULL) {
        *p_x = MapObject_GetXCoord(object);
        *p_z = MapObject_GetZCoord(object);
    } else {
        *p_x = 255;
        *p_z = 255;
        GF_ASSERT(personId == obj_partner_poke);
    }
    return FALSE;
}

BOOL ScrCmd_GetPlayerFacing(ScriptContext *ctx) {
    u16 *p_direction = ScriptGetVarPointer(ctx);
    *p_direction = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_OffsetPlayerAndCamera(ScriptContext *ctx) {
    VecFx32 shift_v;

    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 z = ScriptGetVar(ctx);

    shift_v.x = FX32_CONST(x);
    shift_v.y = FX32_CONST(y);
    shift_v.z = FX32_CONST(z);

    MapObject_SetDrawOffset(PlayerAvatar_GetMapObject(ctx->fieldSystem->playerAvatar), &shift_v);
    Camera_OffsetLookAtPosAndTarget(&shift_v, ctx->fieldSystem->camera);
    return FALSE;
}

BOOL ScrCmd_SetObjectKeep(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    u8 arg = ScriptReadByte(ctx);
    MapObject_SetKeep(object, (BOOL)arg);
    return FALSE;
}

BOOL ScrCmd_ChangeObjectMovement(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    u16 arg = ScriptReadHalfword(ctx);
    if (object != NULL) {
        MapObject_ChangeMovement(object, arg);
    }
    return FALSE;
}

BOOL ScrCmd_GetObjectMovementType(ScriptContext *ctx) {
    u16 *p_dest = ScriptGetVarPointer(ctx);
    *p_dest = 0;
    u16 objectId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    if (object != NULL) {
        *p_dest = MapObject_GetMovement(object);
    }
    return FALSE;
}

BOOL ScrCmd_GetPartyMonUnownLetter(ScriptContext *ctx) {
    u16 partyIdx = ScriptGetVar(ctx);
    u16 *p_dest = ScriptGetVarPointer(ctx);
    *p_dest = GetMonUnownLetter(Party_GetMonByIndex(SaveArray_Party_Get(ctx->fieldSystem->saveData), partyIdx));
    return FALSE;
}

BOOL ScrCmd_PartySelectUI(ScriptContext *ctx) {
    PartyMenuArgs **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *partyMenu = PartyMenu_LaunchApp_PartySelect(HEAP_ID_FIELD3, ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_ChoosePartyMonForTrade(ScriptContext *ctx) { // todo: trade screen
    PartyMenuArgs **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *partyMenu = PartyMenu_LaunchApp_InGameTrade(HEAP_ID_FIELD3, ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_UnionRoomBattlePartySelect(ScriptContext *ctx) { // todo: union pokemon selection
    PartyMenuArgs **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *partyMenu = TaskManager_LaunchPartyMenu_UnionRoomBattleSelect(ctx->fieldSystem->taskman, HEAP_ID_FIELD3);
    return TRUE;
}

BOOL ScrCmd_GetPartySelection(ScriptContext *ctx) { // todo: get selected pokemon slot
    u16 *dest_p = ScriptGetVarPointer(ctx);
    PartyMenuArgs **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    GF_ASSERT(*partyMenu != NULL);
    *dest_p = PartyMenuArgs_GetSlot(*partyMenu);
    if (*dest_p == 7) {
        *dest_p = 255;
    }
    Heap_Free(*partyMenu);
    *partyMenu = NULL;
    return FALSE;
}

BOOL ScrCmd_BattleHallGetPartySelection(ScriptContext *ctx) {
    u16 *p_firstSlot = ScriptGetVarPointer(ctx);
    u16 *p_secondSlot = ScriptGetVarPointer(ctx);
    PartyMenuArgs **partyMenuPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    PartyMenuArgs *partyMenu;
    int partySlot;
    partyMenu = *partyMenuPtr;
    GF_ASSERT(*partyMenuPtr != NULL);
    partySlot = PartyMenuArgs_GetSlot(*partyMenuPtr);
    if (partySlot == 7) {
        *p_firstSlot = 255;
    } else if (partySlot == 6) {
        *p_firstSlot = partyMenu->selectedOrder[0];
        (*p_firstSlot)--;
        *p_secondSlot = partyMenu->selectedOrder[1];
        if (*p_secondSlot != 0) {
            (*p_secondSlot)--;
        }
    }
    Heap_Free(*partyMenuPtr);
    *partyMenuPtr = NULL;
    return FALSE;
}

BOOL ScrCmd_BattleCastleGetPartySelection(ScriptContext *ctx) {
    u16 *p_firstSlot = ScriptGetVarPointer(ctx);
    u16 *p_secondSlot = ScriptGetVarPointer(ctx);
    u16 *p_thirdSlot = ScriptGetVarPointer(ctx);
    struct PartyMenuArgs **partyMenuPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    struct PartyMenuArgs *partyMenu = *partyMenuPtr;
    GF_ASSERT(partyMenu != NULL);
    int partySlot = PartyMenuArgs_GetSlot(*partyMenuPtr);
    if (partySlot == 7) {
        *p_firstSlot = 255;
    } else if (partySlot == 6) {
        *p_firstSlot = partyMenu->selectedOrder[0];
        (*p_firstSlot)--;
        *p_secondSlot = partyMenu->selectedOrder[1];
        (*p_secondSlot)--;
        *p_thirdSlot = partyMenu->selectedOrder[2];
        if (*p_thirdSlot != 0) {
            (*p_thirdSlot)--;
        }
    }
    Heap_Free(*partyMenuPtr);
    *partyMenuPtr = NULL;
    return FALSE;
}

BOOL ScrCmd_BattleArcadeGetPartySelection(ScriptContext *ctx) {
    u16 *p_firstSlot = ScriptGetVarPointer(ctx);
    u16 *p_secondSlot = ScriptGetVarPointer(ctx);
    u16 *p_thirdSlot = ScriptGetVarPointer(ctx);
    struct PartyMenuArgs **partyMenuPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    struct PartyMenuArgs *partyMenu = *partyMenuPtr;
    GF_ASSERT(partyMenu != NULL);
    int partySlot = PartyMenuArgs_GetSlot(*partyMenuPtr);
    if (partySlot == 7) {
        *p_firstSlot = 255;
    } else if (partySlot == 6) {
        *p_firstSlot = partyMenu->selectedOrder[0];
        (*p_firstSlot)--;
        *p_secondSlot = partyMenu->selectedOrder[1];
        (*p_secondSlot)--;
        *p_thirdSlot = partyMenu->selectedOrder[2];
        if (*p_thirdSlot != 0) {
            (*p_thirdSlot)--;
        }
    }
    Heap_Free(*partyMenuPtr);
    *partyMenuPtr = NULL;
    return FALSE;
}

BOOL ScrCmd_GetMoveSelection(ScriptContext *ctx) {
    u8 mode = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    MoveSelectionResult **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA); // presumably move selection data?
    GF_ASSERT(*p_work != NULL);
    if (mode == 1) {
        *p_ret = MoveSelectionResult_GetMoveSlot(*p_work);
    } else {
        *p_ret = MoveSelectionResult_GetPartySlot(*p_work);
    }
    Heap_Free(*p_work);
    *p_work = NULL;
    return FALSE;
}

BOOL ScrCmd_PokemonSummaryScreen(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u8 onlySkillsPanel = ScriptReadByte(ctx);
    u16 partySlot = ScriptGetVar(ctx);
    u16 moveToLearn = ScriptGetVar(ctx);
    if (onlySkillsPanel == TRUE) {
        *p_work = LearnForgetMove_LaunchApp(HEAP_ID_FIELD3, ctx->fieldSystem, partySlot, moveToLearn);
    } else {
        *p_work = PokemonSummary_LaunchApp(HEAP_ID_FIELD3, ctx->fieldSystem, partySlot, moveToLearn);
    }
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_GetPhoneBookRematch(ScriptContext *ctx) {
    u16 idx = ScriptGetVar(ctx);
    u16 *pRet = ScriptGetVarPointer(ctx);
    struct PhoneBook *phoneBook = AllocAndReadPhoneBook(HEAP_ID_FIELD3);
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_26), OVY_LOAD_ASYNC);
    *pRet = PhoneBookTrainerGetRematchInfo(idx, ctx->fieldSystem->saveData, phoneBook, Field_GetTimeOfDayWildParam(ctx->fieldSystem));
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_26));
    FreePhoneBook(phoneBook);
    return FALSE;
}

BOOL ScrCmd_GetWeatherType(ScriptContext *ctx) {
    u16 *p_dest = ScriptGetVarPointer(ctx);
    *p_dest = LocalFieldData_GetWeatherType(Save_LocalFieldData_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrNative_WaitApplication_DestroyTaskData(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    void **p_work = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return FALSE;
    }
    Heap_Free(*p_work);
    *p_work = NULL;
    return TRUE;
}

static BOOL ScrNative_WaitPCBox(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    void **p_work = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return FALSE;
    }
    FieldSystem_TryTriggerBillPCFullCall(fieldSystem);
    Heap_Free(*p_work);
    *p_work = NULL;
    return TRUE;
}

static BOOL ScrNative_RunSpinTradeFlow(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    void **p_work = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    if (!SpinTradeFlow_Run(*p_work)) {
        return FALSE;
    }
    *p_work = NULL;
    return TRUE;
}

BOOL ScrNative_WaitApplication(ScriptContext *ctx) {
    if (!FieldSystem_ApplicationIsRunning(ctx->fieldSystem)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_RestoreOverworld(ScriptContext *ctx) {
    CallTask_RestoreOverworld(ctx->fieldSystem->taskman);
    return TRUE;
}

BOOL ScrCmd_LeaveOverworld(ScriptContext *ctx) {
    CallTask_LeaveOverworld(ctx->fieldSystem->taskman);
    return TRUE;
}

static BOOL Fashion_IsEntrySaved(FieldSystem *fieldSystem, int isLarge, int entryIndex) {
    SaveFashionData *fashionData = Save_FashionData_Get(fieldSystem->saveData);
    if (isLarge == 0) {
        if (!Save_FashionData_IsEntrySaved(fashionData, entryIndex)) {
            return FALSE;
        }
    } else {
        if (!Save_FashionData_IsLargeEntrySaved(fashionData, entryIndex)) {
            return FALSE;
        }
    }
    return TRUE;
}

static FashionAppData *FashionAppData_New(enum HeapID heapID, FieldSystem *fieldSystem, int isLarge, int entryIndex) {
    SaveFashionData *saveFashionData = Save_FashionData_Get(fieldSystem->saveData);
    FashionAppData *fashionAppData;
    if (!Fashion_IsEntrySaved(fieldSystem, isLarge, entryIndex)) {
        return NULL;
    }
    fashionAppData = Heap_Alloc(heapID, sizeof(FashionAppData));
    memset(fashionAppData, 0, sizeof(FashionAppData));
    fashionAppData->saveFashionData = saveFashionData;
    fashionAppData->mode = isLarge;
    fashionAppData->entryIndex = entryIndex;
    return fashionAppData;
}

BOOL ScrCmd_StartPalPadRegistration(ScriptContext *ctx) {
    FieldSystem_StartPalPadRegistration(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_OpenWifiClub(ScriptContext *ctx) {
    CallTask_WifiClub(ctx->taskman);
    return TRUE;
}

BOOL ScrCmd_FashionAppGetEntryIndex(ScriptContext *ctx) {
    struct FashionAppData **p_data = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 *p_dest = ScriptGetVarPointer(ctx);
    *p_dest = (*p_data)->entryIndex;
    Heap_Free(*p_data);
    return FALSE;
}

BOOL ScrCmd_GetLocalNetId(ScriptContext *ctx) {
    u16 *p_dest = ScriptGetVarPointer(ctx);
    *p_dest = Comm_GetLocalNetId();
    return TRUE;
}

BOOL ScrCmd_ShowPokemonPicWindow(ScriptContext *ctx) {
    struct PokepicManager **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 species = ScriptGetVar(ctx);
    u16 gender = ScriptGetVar(ctx);
    LoadUserFrameGfx1(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 0xB, 0, HEAP_ID_FIELD1);
    *p_work = DrawPokemonPicFromSpecies(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 10, 5, 11, 0x3D9, species, gender, HEAP_ID_FIELD1);
    Script_SetMonSeenFlagBySpecies(ctx->fieldSystem, species);
    return FALSE;
}

BOOL ScrCmd_ShowPartyMonPic(ScriptContext *ctx) {
    struct PokepicManager **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 partyIdx = ScriptGetVar(ctx);
    Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(ctx->fieldSystem->saveData), partyIdx);
    LoadUserFrameGfx1(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 0xB, 0, HEAP_ID_FIELD1);
    *p_work = DrawPokemonPicFromMon(ctx->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 10, 5, 11, 0x3D9, mon, HEAP_ID_FIELD1);
    return FALSE;
}

BOOL ScrCmd_ClosePokemonPicWindow(ScriptContext *ctx) {
    u8 **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    **p_work = 1;
    return TRUE;
}

BOOL ScrCmd_AnimateMonPic(ScriptContext *ctx) {
    u8 **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    **p_work = 2;
    return TRUE;
}

BOOL ScrCmd_WaitMonPicAnim(ScriptContext *ctx) {
    ctx->data[0] = ScriptReadHalfword(ctx);
    SetupNativeScript(ctx, ScrNative_WaitMonPicAnim);
    return TRUE;
}

BOOL ScrNative_WaitMonPicAnim(ScriptContext *ctx) {
    u8 **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 *dest_p = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    return **p_work != 3;
}

BOOL ScrCmd_SetLastTalkedTrainerMovement(ScriptContext *ctx) {
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_26), OVY_LOAD_ASYNC);
    if (*p_lastInteracted != NULL) {
        SetTalkedTrainerMovement(ctx->fieldSystem, *p_lastInteracted);
    }
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_26));
    return FALSE;
}

BOOL ScrCmd_EditBattleGreeting(ScriptContext *ctx) {
    u16 *var_p = ScriptGetVarPointer(ctx);
    CallTask_EditBattleGreeting(ctx->taskman, var_p);
    return TRUE;
}

BOOL ScrCmd_OpenDressUp(ScriptContext *ctx) {
    u16 partyIdx = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 showTutorial = ScriptGetVar(ctx);
    CallTask_DressUp(ctx->fieldSystem->taskman, p_ret, ctx->fieldSystem->saveData, partyIdx, showTutorial);
    return TRUE;
}

BOOL ScrCmd_OpenAccessoryPortrait(ScriptContext *ctx) {
    struct FashionAppData **fashionAppData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 entryIndex = ScriptReadHalfword(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *fashionAppData = FashionAppData_New(HEAP_ID_FIELD2, ctx->fieldSystem, 0, entryIndex);
    if (*fashionAppData == NULL) {
        *p_ret = 1;
        return TRUE;
    } else {
        *p_ret = 0;
        AccessoryPortrait_LaunchApp(ctx->fieldSystem, *fashionAppData);
        SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
        return TRUE;
    }
}

BOOL ScrCmd_FashionEntryIsSaved(ScriptContext *ctx) {
    u16 entryIndex = ScriptReadHalfword(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (Fashion_IsEntrySaved(ctx->fieldSystem, 0, entryIndex) == TRUE) {
        *p_ret = 1;
        return TRUE;
    } else {
        *p_ret = 0;
        return TRUE;
    }
}

BOOL ScrCmd_FashionEntrySetMailWord(ScriptContext *ctx) {
    u16 word = ScriptGetVar(ctx);
    FashionEntry_SetMailMessageWord(Save_FashionData_GetEntry(Save_FashionData_Get(ctx->fieldSystem->saveData), 0), word);
    return TRUE;
}

BOOL ScrCmd_OpenGeonetGlobe(ScriptContext *ctx) {
    GeonetGlobe_LaunchApp(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_OpenBallCapsuleEditor(ScriptContext *ctx) {
    CallTask_BallCapsuleEditor(ctx->taskman, ctx->fieldSystem->saveData);
    return TRUE;
}

BOOL ScrCmd_TownMap(ScriptContext *ctx) {
    PokegearArgs **p_townMap = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_townMap = PokegearTownMap_LaunchApp(ctx->fieldSystem, 1);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_OpenBattleRoomResults(ScriptContext *ctx) {
    u16 showLeaders = ScriptGetVar(ctx);
    u16 sp0 = ScriptGetVar(ctx);
    BattleRoomResultsArgs **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_work = Heap_Alloc(HEAP_ID_FIELD2, sizeof(struct BattleRoomResultsArgs));
    BattleRoomResultsArgs_Init(*p_work, showLeaders, sp0, ctx);
    BattleRoomResults_LaunchApp(ctx->fieldSystem, *p_work);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_OpenPCBox(ScriptContext *ctx) { // todo: PC box screen
    PCBoxArgs **p_work;

    p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_work = PCBoxAppData_New(ctx);
    PCBox_LaunchApp(ctx->fieldSystem, *p_work);
    SetupNativeScript(ctx, ScrNative_WaitPCBox);
    return TRUE;
}

BOOL ScrCmd_OpenDrawingSession(ScriptContext *ctx) {
    DrawingSession_LaunchApp(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_OpenLinkTrainerCard(ScriptContext *ctx) {
    LinkTrainerCard_StartTask(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_OpenWirelessTrade(ScriptContext *ctx) {
    CallTask_WirelessTrade(ctx->fieldSystem->taskman);
    return TRUE;
}

BOOL ScrCmd_OpenRecordMixing(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_work = RecordMixing_LaunchApp(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_HOFCredits(ScriptContext *ctx) {
    u16 vsTrainerRed = ScriptReadHalfword(ctx);
    CallTask_GameClear(ctx->fieldSystem->taskman, vsTrainerRed);
    return TRUE;
}

BOOL ScrCmd_OpenHallOfFameShowcase(ScriptContext *ctx) {
    HallOfFame **hof = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA); // todo: hall of fame data
    *hof = HallOfFameShowcase_LaunchApp(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_CheckHallOfFameSaveInvalid(ScriptContext *ctx) {
    int saveOk;
    HallOfFame *hof = LoadHallOfFame(ctx->fieldSystem->saveData, HEAP_ID_FIELD1, &saveOk);
    u16 *p_var = ScriptGetVarPointer(ctx);
    *p_var = 0;
    if (saveOk == 2) {
        *p_var = 1;
    }
    Heap_Free(hof);
    return FALSE;
}

BOOL ScrCmd_OpenGts(ScriptContext *ctx) {
    u16 connectDirectly = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (Comm_HasWifiProfile(ctx->fieldSystem->saveData)) {
        *p_ret = 1;
        Gts_LaunchApp(ctx->fieldSystem, connectDirectly);
        SetupNativeScript(ctx, ScrNative_WaitApplication);
    } else {
        *p_ret = 0;
    }
    return TRUE;
}

BOOL ScrCmd_OpenWifiClubWithResult(ScriptContext *ctx) {
    u16 *var_p = ScriptGetVarPointer(ctx);
    CallTask_WifiClubWithResult(ctx->taskman, var_p);
    return TRUE;
}

BOOL ScrCmd_ChooseStarter(ScriptContext *ctx) {
    LaunchStarterChoiceScene(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_BagSelectItem(ScriptContext *ctx) { // todo: bag select screen
    void **p_work;
    u8 pocketType = ScriptReadByte(ctx) != 0 ? POCKET_TYPE_BERRIES : POCKET_TYPE_ITEMS;
    p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    GF_ASSERT(*p_work == NULL);
    *p_work = Bag_LaunchApp_WithPocket(ctx->fieldSystem, pocketType);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_BagGetSelectedItem(ScriptContext *ctx) { // todo: bag select screen result
    u16 *p_ret = ScriptGetVarPointer(ctx);
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    GF_ASSERT(*p_work != NULL);
    *p_ret = BagView_SelectResult(*p_work);
    Heap_Free(*p_work);
    *p_work = NULL;
    return FALSE;
}

BOOL ScrCmd_BagSelectItemNoResult(ScriptContext *ctx) { // unknown? possibly daycare select screen??
    void **p_work;
    u8 pocketType = ScriptReadByte(ctx) != 0 ? POCKET_TYPE_BERRIES : POCKET_TYPE_ITEMS;
    p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    GF_ASSERT(*p_work == NULL);
    *p_work = Bag_LaunchApp_WithPocket(ctx->fieldSystem, pocketType);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_NamePlayer(ScriptContext *ctx) {
    u16 *p_var = ScriptGetVarPointer(ctx);
    CallTask_NamingScreen(ctx->taskman, NAME_SCREEN_PLAYER, 0, PLAYER_NAME_LENGTH, 0, NULL, p_var);
    return TRUE;
}

BOOL ScrCmd_NameRival(ScriptContext *ctx) {
    u16 *p_var = ScriptGetVarPointer(ctx);
    CallTask_NamingScreen(ctx->taskman, NAME_SCREEN_RIVAL, 0, PLAYER_NAME_LENGTH, 0, NULL, p_var);
    return TRUE;
}

BOOL ScrCmd_NicknameInput(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 partyPos = ScriptGetVar(ctx);
    BugContest *contest;
    Pokemon *mon;
    u16 nickname[20];
    u16 *var_ret;
    int species;

    if (partyPos == 255) {
        contest = FieldSystem_BugContest_Get(fieldSystem);
        if (!contest->caught_poke) {
            return TRUE;
        }
        mon = contest->mon;
    } else {
        mon = Party_GetMonByIndex(SaveArray_Party_Get(fieldSystem->saveData), partyPos);
    }
    GetMonData(mon, MON_DATA_NICKNAME, nickname);
    var_ret = ScriptGetVarPointer(ctx);
    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    CallTask_NamingScreen(ctx->taskman, NAME_SCREEN_POKEMON, species, POKEMON_NAME_LENGTH, partyPos, nickname, var_ret);
    return TRUE;
}

BOOL ScrCmd_RunSpinTradeFlow(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_work = SpinTradeFlow_New(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_RunSpinTradeFlow);
    return TRUE;
}

BOOL ScrCmd_CheckUnionRoomPartnerVersionNotDummy(ScriptContext *ctx) {
    u16 *ret_p = ScriptGetVarPointer(ctx);
    u32 partnerVersion = UnionRoom_GetPartnerGameVersion();
    u32 dummyVersion = PlayerData_GetDummyGameVersion();
    if (partnerVersion == dummyVersion) {
        *ret_p = FALSE;
    } else {
        *ret_p = TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_PromptEasyChatOneWord(ScriptContext *ctx) {
    u16 kind = ScriptGetVar(ctx);
    EasyChatResult *result = (EasyChatResult *)ScriptGetVarPointer(ctx);
    u16 *p_word1 = ScriptGetVarPointer(ctx);

    *p_word1 = 0xFFFF;
    CallTask_EasyChat(ctx->fieldSystem->taskman, kind, result, p_word1, NULL);
    return TRUE;
}

BOOL ScrCmd_PromptEasyChat(ScriptContext *ctx) {
    EasyChatResult *result = (EasyChatResult *)ScriptGetVarPointer(ctx);
    u16 *p_word1 = ScriptGetVarPointer(ctx);
    u16 *p_word2 = ScriptGetVarPointer(ctx);

    *p_word1 = 0xFFFF;
    *p_word2 = 0xFFFF;
    CallTask_EasyChat(ctx->fieldSystem->taskman, 1, result, p_word1, p_word2);
    return TRUE;
}

BOOL ScrCmd_BufferEasyChatWord(ScriptContext *ctx) {
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 idx = ScriptGetVar(ctx);
    u16 word = ScriptGetVar(ctx);
    BufferECWord(*p_msgFmt, idx, word);
    return FALSE;
}

BOOL ScrCmd_FadeScreen(ScriptContext *ctx) {
    u16 duration = ScriptReadHalfword(ctx);
    u16 speed = ScriptReadHalfword(ctx);
    u16 type = ScriptReadHalfword(ctx);
    u16 color = ScriptReadHalfword(ctx);
    BeginNormalPaletteFade(FADE_BOTH_SCREENS, (enum FadeType)type, (enum FadeType)type, color, duration, speed, HEAP_ID_FIELD1);
    ResetVisibleHardwareWindows(PM_LCD_TOP);
    ResetVisibleHardwareWindows(PM_LCD_BOTTOM);
    return FALSE;
}

BOOL NativeScript_WaitFade(ScriptContext *ctx);

BOOL ScrCmd_WaitFade(ScriptContext *ctx) {
    SetupNativeScript(ctx, NativeScript_WaitFade);
    return TRUE;
}

BOOL NativeScript_WaitFade(ScriptContext *ctx) {
    return IsPaletteFadeFinished() == TRUE;
}

BOOL ScrCmd_Warp(ScriptContext *ctx) {
    u16 mapId = ScriptGetVar(ctx);
    u16 unused = ScriptReadHalfword(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 direction = ScriptGetVar(ctx);
    CallTask_ScriptWarp(ctx->taskman, mapId, -1, x, y, direction);
    return TRUE;
}

BOOL ScrCmd_WarpToColosseum(ScriptContext *ctx) {
    u16 mapId = ScriptReadHalfword(ctx);
    u16 unused = ScriptReadHalfword(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 direction = ScriptReadHalfword(ctx);
    CallTask_WarpToColosseum(ctx->fieldSystem->taskman, mapId, -1, x, y, direction);
    return TRUE;
}

BOOL ScrCmd_ReturnFromColosseum(ScriptContext *ctx) {
    CallTask_ReturnFromColosseum(ctx->fieldSystem->taskman);
    return TRUE;
}

BOOL ScrCmd_GetPreviousMapId(ScriptContext *ctx) {
    Location *location = LocalFieldData_GetPreviousPosition(Save_LocalFieldData_Get(ctx->fieldSystem->saveData));
    u16 *ret_p = ScriptGetVarPointer(ctx);
    *ret_p = location->mapId;
    return FALSE;
}

BOOL ScrCmd_GetCurrentMapId(ScriptContext *ctx) {
    u16 *ret_p = ScriptGetVarPointer(ctx);
    *ret_p = ctx->fieldSystem->location->mapId;
    return FALSE;
}

BOOL ScrCmd_GetMapPokeCenterOrLeagueType(ScriptContext *ctx) {
    u16 mapId = ScriptGetVar(ctx);
    u16 *ret_p = ScriptGetVarPointer(ctx);

    *ret_p = 0;
    if (MapHeader_MapIsPokemonCenter(mapId) == TRUE) {
        *ret_p = 1;
    } else if (MapHeader_MapIsPokemonLeagueLobby(mapId) == TRUE) {
        *ret_p = 2;
    }

    return FALSE;
}

BOOL ScrCmd_RockClimb(ScriptContext *ctx) {
    u16 partySlot = ScriptGetVar(ctx);
    int playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_RockClimb(ctx->taskman, playerDirection, partySlot);
    return TRUE;
}

BOOL ScrCmd_Surf(ScriptContext *ctx) {
    u16 partySlot = ScriptGetVar(ctx);
    int playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_Surf(ctx->taskman, playerDirection, partySlot);
    return TRUE;
}

BOOL ScrCmd_Waterfall(ScriptContext *ctx) {
    u16 partySlot = ScriptGetVar(ctx);
    int playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_Waterfall(ctx->taskman, playerDirection, partySlot);
    return TRUE;
}

BOOL ScrCmd_FlyWarp(ScriptContext *ctx) {
    u16 mapId = ScriptReadHalfword(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    CallFieldTask_FlyWarp(ctx->fieldSystem, mapId, -1, x, y, DIR_SOUTH);
    return TRUE;
}

BOOL ScrCmd_FlashEffect(ScriptContext *ctx) {
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(ctx->fieldSystem->saveData);
    LocalFieldData_SetWeatherType(localFieldData, 12);
    WeatherManager_ChangeWeather(ctx->fieldSystem->mapSystems->weatherManager, LocalFieldData_GetWeatherType(localFieldData));
    return TRUE;
}

BOOL ScrCmd_Whirlpool(ScriptContext *ctx) {
    u16 partySlot = ScriptGetVar(ctx);
    int playerDirection = PlayerAvatar_GetFacingDirection(ctx->fieldSystem->playerAvatar);
    CallFieldTask_Whirlpool(ctx->taskman, playerDirection, partySlot);
    return TRUE;
}

BOOL NativeScript_WaitFieldMoveCutIn(ScriptContext *ctx);

BOOL ScrCmd_PlayFieldMoveCutIn(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 partyIdx = ScriptGetVar(ctx);
    Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(ctx->fieldSystem->saveData), partyIdx);
    u32 playerGender = PlayerAvatar_GetGender(ctx->fieldSystem->playerAvatar);
    *p_work = FieldMoveCutIn_Start(ctx->fieldSystem, FIELD_MOVE_CUT_IN_BANNER, mon, playerGender);
    SetupNativeScript(ctx, NativeScript_WaitFieldMoveCutIn);
    return TRUE;
}

BOOL NativeScript_WaitFieldMoveCutIn(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    if (FieldMoveCutIn_IsFinished(*p_work) == TRUE) {
        FieldMoveCutIn_Delete(*p_work);
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_PlayerOnBikeCheck(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (PlayerAvatar_GetState(ctx->fieldSystem->playerAvatar) == PLAYER_STATE_CYCLING) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_PlayerOnBikeSet(ScriptContext *ctx) {
    u8 flag = ScriptReadByte(ctx);
    if (flag == TRUE) {
        FieldBGM_SetOverride(ctx->fieldSystem, SEQ_GS_BICYCLE);
        FieldBGM_TryFadeOut(ctx->fieldSystem, SEQ_GS_BICYCLE, 1);
        Field_PlayerAvatar_OrrTransitionFlags(ctx->fieldSystem->playerAvatar, PLAYER_TRANSITION_CYCLING);
        Field_PlayerAvatar_ApplyTransitionFlags(ctx->fieldSystem->playerAvatar);
    } else {
        Field_PlayerAvatar_OrrTransitionFlags(ctx->fieldSystem->playerAvatar, PLAYER_TRANSITION_WALKING);
        Field_PlayerAvatar_ApplyTransitionFlags(ctx->fieldSystem->playerAvatar);
        FieldBGM_SetOverride(ctx->fieldSystem, 0);
        FieldBGM_TryFadeOut(ctx->fieldSystem, FieldBGM_GetEffective(ctx->fieldSystem, ctx->fieldSystem->location->mapId), 1);
    }
    return FALSE;
}

BOOL ScrCmd_SetBicycleBGMOverride(ScriptContext *ctx) {
    FieldBGM_SetOverride(ctx->fieldSystem, SEQ_PL_BICYCLE);
    return FALSE;
}

BOOL ScrCmd_SetBikeStateLock(ScriptContext *ctx) {
    BOOL lock = ScriptReadByte(ctx);
    PlayerAvatar_SetBikeStateLock(ctx->fieldSystem->playerAvatar, lock);
    return FALSE;
}

BOOL ScrCmd_GetPlayerState(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = PlayerAvatar_GetState(ctx->fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_SetAvatarBits(ScriptContext *ctx) {
    u16 flags = ScriptReadHalfword(ctx);
    PlayerAvatar_SetTransitionFlagsBits(ctx->fieldSystem->playerAvatar, flags);
    return TRUE;
}

BOOL ScrCmd_UpdateAvatarState(ScriptContext *ctx) {
    Field_PlayerAvatar_ApplyTransitionFlags(ctx->fieldSystem->playerAvatar);
    return FALSE;
}

BOOL ScrCmd_GetSwarmMapAndSpecies(ScriptContext *ctx) {
    RoamerSaveData *roamerSave = Save_Roamers_Get(ctx->fieldSystem->saveData);
    u16 *p_mapno = ScriptGetVarPointer(ctx);
    u16 *p_species = ScriptGetVarPointer(ctx);
    GetSwarmInfoFromRand(Roamers_GetRand(roamerSave, 2), p_mapno, p_species);
    return FALSE;
}

BOOL ScrCmd_GetStarterChoice(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Save_VarsFlags_GetStarter(Save_VarsFlags_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_SetStarterChoice(ScriptContext *ctx) {
    u16 choice = ScriptGetVar(ctx);
    Save_VarsFlags_SetStarter(Save_VarsFlags_Get(ctx->fieldSystem->saveData), choice);
    return FALSE;
}

BOOL ScrCmd_TrainerMessage(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;

    u16 *p_scripno = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_NUMBER);
    String **p_strbuf1 = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_STRING_BUFFER_0);
    u8 *p_printerno = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_TEXT_PRINTER_NUMBER);
    u16 trainerno = ScriptGetVar(ctx);
    u16 msgno = ScriptGetVar(ctx);

    GetTrainerMessageByIdPair(trainerno, msgno, *p_strbuf1, HEAP_ID_FIELD2);
    FillWindowPixelBuffer(FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW), 15);
    *p_printerno = DialogBox_PrintMessage(
        FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_WINDOW),
        *p_strbuf1,
        Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData),
        TRUE);
    SetupNativeScript(ctx, ScrNative_WaitTextPrinter);
    return TRUE;
}

BOOL ScrNative_WaitCommClubJoinResult(ScriptContext *ctx);

BOOL ScrCmd_CommClubJoin(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 commType = ScriptGetVar(ctx);
    u16 course = ScriptGetVar(ctx);
    u16 sp4 = ScriptGetVar(ctx);
    u16 retVarId = ScriptReadHalfword(ctx);
    CommClub_StartJoin(fieldSystem, commType, course, sp4);
    ctx->data[0] = retVarId;
    SetupNativeScript(ctx, ScrNative_WaitCommClubJoinResult);
    return TRUE;
}

BOOL ScrNative_WaitCommClubJoinResult(ScriptContext *ctx) {
    u16 *p_ret = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    int result = CommClub_PollJoinResult();
    if (result == 0) {
        return FALSE;
    } else {
        *p_ret = result;
        return TRUE;
    }
}

BOOL ScrNative_WaitCommClubHostResult(ScriptContext *ctx);

BOOL ScrCmd_CommClubHost(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 commType = ScriptGetVar(ctx);
    u16 course = ScriptGetVar(ctx);
    u16 sp4 = ScriptGetVar(ctx);
    u16 retVarId = ScriptReadHalfword(ctx);
    CommClub_StartHost(fieldSystem, commType, course, sp4);
    ctx->data[0] = retVarId;
    SetupNativeScript(ctx, ScrNative_WaitCommClubHostResult);
    return TRUE;
}

BOOL ScrNative_WaitCommClubHostResult(ScriptContext *ctx) {
    u16 *p_ret = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    int result = CommClub_PollHostResult();
    if (result == 0) {
        return FALSE;
    } else {
        *p_ret = result;
        return TRUE;
    }
}

BOOL ScrCmd_Dummy228(ScriptContext *ctx) {
    u16 unused = ScriptReadHalfword(ctx);
    return TRUE;
}

BOOL ScrCmd_Dummy229(ScriptContext *ctx) {
    u16 unused = ScriptReadHalfword(ctx);
    return TRUE;
}

BOOL ScrCmd_LinkBattle(ScriptContext *ctx) {
    struct LinkBattleScriptWork **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    struct LinkBattleScriptWork *work = *p_work;
    CallTask_LinkBattle(ctx->fieldSystem->taskman, &work->selectedOrder, 5);
    Heap_Free(work);
    *p_work = NULL;
    return TRUE;
}

BOOL ScrCmd_Dummy231(ScriptContext *ctx) {
    // dummy
    return TRUE;
}

BOOL ScrCmd_SetDynamicWarp(ScriptContext *ctx) {
    Location warp;
    warp.mapId = ScriptGetVar(ctx);
    warp.warpId = ScriptGetVar(ctx);
    warp.x = ScriptGetVar(ctx);
    warp.y = ScriptGetVar(ctx);
    warp.direction = ScriptGetVar(ctx);
    LocalFieldData_SetDynamicWarp(Save_LocalFieldData_Get(ctx->fieldSystem->saveData), &warp);
    return FALSE;
}

BOOL ScrCmd_GetDynamicWarpFloorNo(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    Location *warp = LocalFieldData_GetDynamicWarp(Save_LocalFieldData_Get(ctx->fieldSystem->saveData));
    *p_ret = MapNumToFloorNo(warp->mapId);
    return FALSE;
}

BOOL ScrCmd_ElevatorCurFloorBox(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 floor = ScriptGetVar(ctx);
    PrintCurFloorInNewWindow(fieldSystem, x, y, p_ret, *p_msgFmt, floor);
    return FALSE;
}

BOOL ScrCmd_CountJohtoDexSeen(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Pokedex_CountJohtoDexSeen(pokedex);
    return FALSE;
}

BOOL ScrCmd_CountJohtoDexOwned(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Pokedex_CountJohtoDexOwned(pokedex);
    return FALSE;
}

BOOL ScrCmd_CountNationalDexSeen(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Pokedex_CountNationalDexSeen(pokedex);
    return FALSE;
}

BOOL ScrCmd_CountNationalDexOwned(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Pokedex_CountNationalDexOwned(pokedex);
    return FALSE;
}

BOOL ScrCmd_Dummy247(ScriptContext *ctx) {
    // dummy
    return FALSE;
}

BOOL ScrCmd_GetDexEvalResult(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    PlayerProfile *profile = Save_PlayerData_GetProfile(ctx->fieldSystem->saveData);
    u8 kind = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 *p_ret2 = ScriptGetVarPointer(ctx);

    if (kind == 0) {
        *p_ret = GetOakJohtoDexRating(Pokedex_CountJohtoOwned_ExcludeMythical(pokedex), PlayerProfile_GetTrainerGender(profile), p_ret2);
    } else {
        *p_ret = GetOakNationalDexRating(Pokedex_CountNationalOwned_ExcludeMythical(pokedex), PlayerProfile_GetTrainerGender(profile), p_ret2);
    }
    return FALSE;
}

BOOL ScrCmd_RocketTrapBattle(ScriptContext *ctx) {
    u32 *winFlag = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_BATTLE_WIN_FLAG);
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    SetupAndStartWildBattle(ctx->taskman, species, level, winFlag, FALSE, FALSE);
    return TRUE;
}

BOOL ScrCmd_WildBattle(ScriptContext *ctx) {
    u32 *winFlag = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_BATTLE_WIN_FLAG);
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    u8 shiny = ScriptReadByte(ctx);
    SetupAndStartWildBattle(ctx->taskman, species, level, winFlag, TRUE, shiny);
    return TRUE;
}

BOOL ScrCmd_FatefulWildBattle(ScriptContext *ctx) {
    u32 *winFlag = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_BATTLE_WIN_FLAG);
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    SetupAndStartFatefulWildBattle(ctx->taskman, species, level, winFlag, TRUE);
    return TRUE;
}

BOOL ScrCmd_StartFirstBattle(ScriptContext *ctx) {
    u16 species = ScriptGetVar(ctx);
    u16 level = ScriptGetVar(ctx);
    SetupAndStartFirstBattle(ctx->taskman, species, level);
    return TRUE;
}

BOOL ScrCmd_CatchingTutorial(ScriptContext *ctx) {
    SetupAndStartTutorialBattle(ctx->taskman);
    return TRUE;
}

BOOL ScrCmd_OpenTrainerCardSignature(ScriptContext *ctx) {
    TrainerCardSignature_LaunchApp(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_GetSaveFileState(ScriptContext *ctx) {
    SaveData *saveData = ctx->fieldSystem->saveData;
    u16 *p_ret = ScriptGetVarPointer(ctx);

    if (Save_FileDoesNotBelongToPlayer(saveData)) {
        *p_ret = 0;
    } else if (!Save_FileExists(saveData)) {
        *p_ret = 1;
    } else if (Save_NumModifiedPCBoxesIsMany(saveData)) {
        *p_ret = 2;
    } else {
        *p_ret = 3;
    }
    return FALSE;
}

BOOL ScrCmd_SaveGameNormal(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);

    *p_ret = Field_SaveGameNormal(fieldSystem);
    return FALSE;
}

BOOL ScrCmd_SaveWipeExtraChunks(ScriptContext *ctx) {
    Save_WipeExtraChunks(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL ScrCmd_CheckExtraSaveChunksExist(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Save_CheckExtraChunksExist(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL NativeScript_WaitLinkSync(ScriptContext *ctx);

BOOL ScrCmd_LinkSyncAndWait(ScriptContext *ctx) {
    u16 syncState = ScriptGetVar(ctx);
    ctx->data[0] = syncState;
    LinkSync_StartSync(syncState);
    SetupNativeScript(ctx, NativeScript_WaitLinkSync);
    return TRUE;
}

BOOL NativeScript_WaitLinkSync(ScriptContext *ctx) {
    if (Comm_CountConnected() < 2) {
        return TRUE;
    } else {
        return LinkSync_IsSynced(ctx->data[0]);
    }
}

BOOL ScrCmd_LinkSyncClearPackets(ScriptContext *ctx) {
    LinkSync_ClearPackets();
    return FALSE;
}

BOOL ScrCmd_GetUnionRoomPartnerHometownMsg(ScriptContext *ctx) {
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 *p_ret = ScriptGetVarPointer(ctx);

    *p_ret = UnionRoom_GetPartnerHometownMsg(*p_msgFmt);
    return FALSE;
}

BOOL ScrCmd_GetUnionRoomOwnChatMsg(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);

    *p_ret = UnionRoom_GetOwnChatMessageMsg(ctx->fieldSystem->unionRoom, *p_msgFmt);
    return FALSE;
}

BOOL ScrCmd_UnionRoomSetActivity(ScriptContext *ctx) {
    u16 command = ScriptReadHalfword(ctx);
    if (command == 5 || command == 7 || command == 9 || command == 6 || command == 12 || command == 10) {
        CommState_SetUnionAppLinkMode();
    } else if (command == 11) {
        CommState_SetUnionRoomLinkMode();
    }
    if (!Comm_GetLocalNetId()) {
        UnionRoom_SetBeaconActivity(command);
    }
    return FALSE;
}

BOOL ScrCmd_BufferUnionRoomPartnerLanguage(ScriptContext *ctx) {
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u16 mode = ScriptReadHalfword(ctx);
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem));
    SaveEasyChat *easyChat = Save_EasyChat_Get(FieldSystem_GetSaveData(ctx->fieldSystem));
    u16 objId;

    if (mode == 0) {
        objId = MapObject_GetID(*p_lastInteracted);
    } else {
        objId = 0;
    }
    UnionRoom_BufferPartnerLanguage(*p_msgFmt, mode, objId, profile, easyChat);
    return FALSE;
}

BOOL ScrCmd_FieldCommRegisterCommands(ScriptContext *ctx) {
    FieldComm_RegisterCommands(ctx->fieldSystem);
    return FALSE;
}

BOOL NativeScript_WaitPartnerLeft(ScriptContext *ctx);

BOOL ScrCmd_UnionRoomRequestLeaveAll(ScriptContext *ctx) {
    UnionRoomObjects_RequestLeaveAll(ctx->fieldSystem->unionRoomObjects);
    CommState_ResumeAlternateSearch();
    SetupNativeScript(ctx, NativeScript_WaitPartnerLeft);
    return TRUE;
}

BOOL NativeScript_WaitPartnerLeft(ScriptContext *ctx) {
    return Comm_CountConnected() < 2;
}

BOOL ScrCmd_GetUnionRoomTalkMsg(ScriptContext *ctx) {
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 kind = ScriptReadHalfword(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    *p_ret = UnionRoom_GetTalkMsg(ctx->fieldSystem->unionRoom, MapObject_GetID(*p_lastInteracted), kind, *p_msgFmt);
    return FALSE;
}

BOOL ScrCmd_GetUnionRoomBattleCancel(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = UnionRoom_GetBattleCancel(ctx->fieldSystem->unionRoom);
    if (*p_ret) {
        void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
        Heap_Free(*p_work);
    }
    return FALSE;
}

BOOL ScrCmd_GetUnionRoomPlayerActivity(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = UnionRoom_GetPlayerActivityType(fieldSystem->unionRoom, MapObject_GetID(*p_lastInteracted));
    return FALSE;
}

BOOL ScrCmd_UnionRoomRequestJoinPlayer(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    LocalMapObject **p_lastInteracted = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_LAST_INTERACTED);
    u16 kind = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = UnionRoom_RequestJoinPlayer(fieldSystem->unionRoom, MapObject_GetID(*p_lastInteracted), kind);
    return FALSE;
}

BOOL ScrNative_WaitUnionRoomJoinStatus(ScriptContext *ctx);

BOOL ScrCmd_UnionRoomWaitJoinStatus(ScriptContext *ctx) {
    u16 var_idx = ScriptReadHalfword(ctx);
    ctx->data[0] = var_idx;
    SetupNativeScript(ctx, ScrNative_WaitUnionRoomJoinStatus);
    return TRUE;
}

BOOL ScrNative_WaitUnionRoomJoinStatus(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    int result = UnionRoom_GetJoinStatus(fieldSystem->unionRoom);
    u16 *p_ret = GetVarPointer(fieldSystem, ctx->data[0]);
    if (result == 0) {
        return FALSE;
    } else {
        *p_ret = result;
        return TRUE;
    }
}

BOOL ScrCmd_UnionRoomRestoreObjects(ScriptContext *ctx) {
    UnionRoomObjects_RestoreAfterScript(ctx->fieldSystem->mapObjectManager, ctx->fieldSystem->unionRoomObjects);
    return FALSE;
}

BOOL ScrCmd_UnionRoomRefuseJoins(ScriptContext *ctx) {
    UnionRoom_SetBeaconActivity(4);
    CommState_RefuseJoinsAndRestart();
    return FALSE;
}

BOOL ScrCmd_UnionRoomResumeSearch(ScriptContext *ctx) {
    CommState_SetUnionRoomLinkMode();
    CommState_ResumeAlternateSearch();
    UnionRoom_SetBeaconActivity(0);
    return FALSE;
}

BOOL ScrCmd_UnionRoomSendTalkResponse(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 mode = ScriptGetVar(ctx);
    u16 value = ScriptGetVar(ctx);
    UnionRoom_SendTalkResponse(fieldSystem->unionRoom, mode, value);
    return FALSE;
}

BOOL ScrNative_WaitUnionRoomTalkChoice(ScriptContext *ctx);

BOOL ScrCmd_UnionRoomWaitTalkChoice(ScriptContext *ctx) {
    u16 var_idx = ScriptReadHalfword(ctx);
    ctx->data[0] = var_idx;
    SetupNativeScript(ctx, ScrNative_WaitUnionRoomTalkChoice);
    return TRUE;
}

BOOL ScrNative_WaitUnionRoomTalkChoice(ScriptContext *ctx) {
    u16 *p_ret = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    u32 choice = UnionRoom_GetTalkChoice(ctx->fieldSystem->unionRoom);
    if (choice >= 1) {
        *p_ret = choice;
        UnionRoom_ResetTalkReplies(ctx->fieldSystem->unionRoom);
        return TRUE;
    } else {
        *p_ret = 0;
        return FALSE;
    }
}

BOOL ScrNative_UnionRoomWaitTalkReply(ScriptContext *ctx);

BOOL ScrCmd_UnionRoomWaitTalkReply(ScriptContext *ctx) {
    u16 var_idx = ScriptReadHalfword(ctx);
    ctx->data[0] = var_idx;
    SetupNativeScript(ctx, ScrNative_UnionRoomWaitTalkReply);
    return TRUE;
}

BOOL ScrNative_UnionRoomWaitTalkReply(ScriptContext *ctx) {
    u16 *p_ret = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    int reply = UnionRoom_GetTalkReply(ctx->fieldSystem->unionRoom);
    if (gSystem.newKeys & PAD_BUTTON_B) {
        reply = UnionRoom_TrySendTalkCancel(ctx->fieldSystem->unionRoom, 8);
    }
    if (reply != 0) {
        *p_ret = reply;
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_EnterUnionRoom(ScriptContext *ctx) {
    CallTask_EnterUnionRoom(ctx->fieldSystem->taskman);
    return TRUE;
}

BOOL ScrCmd_BufferUnionRoomAvatarChoices(ScriptContext *ctx) {
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem));
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    BufferUnionRoomAvatarChoicesNames(
        PlayerProfile_GetTrainerID(profile),
        PlayerProfile_GetTrainerGender(profile),
        *p_msgFmt);
    return FALSE;
}

BOOL ScrCmd_UnionRoomAvatarIdxToTrainerClass(ScriptContext *ctx) {
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem));
    u16 choice = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = UnionRoomAvatarIdxToSprite(
        PlayerProfile_GetTrainerID(profile),
        PlayerProfile_GetTrainerGender(profile),
        choice);
    *p_ret = GetUnionRoomAvatarAttrBySprite(
        PlayerProfile_GetTrainerGender(profile),
        *p_ret,
        2);
    return FALSE;
}

BOOL ScrCmd_UnionRoomAvatarIdxToSprite(ScriptContext *ctx) {
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem));
    u16 choice = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = UnionRoomAvatarIdxToSprite(
        PlayerProfile_GetTrainerID(profile),
        PlayerProfile_GetTrainerGender(profile),
        choice);
    return FALSE;
}

BOOL ScrCmd_SetPlayerProfileAvatar(ScriptContext *ctx) {
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem));
    u16 choice = ScriptGetVar(ctx);
    PlayerProfile_SetAvatar(profile, choice);
    return FALSE;
}

BOOL ScrCmd_OverworldWhiteOut(ScriptContext *ctx) {
    CallTask_Blackout(ctx->taskman);
    return TRUE;
}

BOOL ScrCmd_SetSpawn(ScriptContext *ctx) {
    u16 spawnPoint = ScriptGetVar(ctx);
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(ctx->fieldSystem->saveData);
    LocalFieldData_SetBlackoutSpawn(localFieldData, spawnPoint);
    return FALSE;
}

BOOL ScrCmd_GetPlayerGender(ScriptContext *ctx) {
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem));
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = PlayerProfile_GetTrainerGender(profile);
    return FALSE;
}

BOOL ScrCmd_HealParty(ScriptContext *ctx) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(ctx->taskman); // ???
    HealParty(SaveArray_Party_Get(fieldSystem->saveData));
    return FALSE;
}

BOOL NativeScript_WaitCommShutdown(ScriptContext *ctx);

BOOL ScrCmd_CommClubExit(ScriptContext *ctx) {
    CommClubLink_Exit();
    SetupNativeScript(ctx, NativeScript_WaitCommShutdown);
    return TRUE;
}

BOOL NativeScript_WaitCommShutdown(ScriptContext *ctx) {
    if (CommState_Exists() != TRUE && CommWireless_Exists() != TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_CommClubLinkExit(ScriptContext *ctx) {
    CommClubLink_ExitSynced();
    SetupNativeScript(ctx, NativeScript_WaitCommShutdown);
    return TRUE;
}

BOOL ScrCmd_CommClubStartCardExchange(ScriptContext *ctx) {
    CommClubLink_StartCardExchange(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_SetCommPlayerFacing(ScriptContext *ctx) {
    u16 val = ScriptReadHalfword(ctx);
    CommPlayerManager_SetLocalFacing(val);
    return FALSE;
}

BOOL ScrCmd_BagPocketHasItems(ScriptContext *ctx) {
    u16 pocket = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Bag_PocketNotEmpty(Save_Bag_Get(ctx->fieldSystem->saveData), pocket);
    return FALSE;
}

BOOL ScrCmd_MovePerson(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    Field_SetEventDefaultXYPos(ctx->fieldSystem, objectId, x, y);
    return FALSE;
}

BOOL ScrCmd_MovePersonFacing(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    u16 z = ScriptGetVar(ctx);
    u16 direction = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    MapObject_SetPositionFromXYZAndDirection(object, x, y, z, direction);
    MapObject_UpdateHeight(object);
    return FALSE;
}

BOOL ScrCmd_SetObjectMovementType(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 movementType = ScriptGetVar(ctx);
    Field_SetEventDefaultMovement(ctx->fieldSystem, objectId, movementType);
    return FALSE;
}

BOOL ScrCmd_SetObjectFacing(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 facing = ScriptGetVar(ctx);
    Field_SetEventDefaultDirection(ctx->fieldSystem, objectId, facing);
    return FALSE;
}

BOOL ScrCmd_MoveWarp(ScriptContext *ctx) {
    u16 warpId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    Field_SetWarpXYPos(ctx->fieldSystem, warpId, x, y);
    return FALSE;
}

BOOL ScrCmd_MoveBGEvent(ScriptContext *ctx) {
    u16 bgId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    Field_SetBgEventXYPos(ctx->fieldSystem, bgId, x, y);
    return FALSE;
}

BOOL ScrCmd_SetObjectFacingAndUpdateDraw(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 dir = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    GF_ASSERT(object != NULL);
    MapObject_SetFacingAndUpdateDraw(object, dir);
    return FALSE;
}

BOOL ScrCmd_WriteScriptEnvField34(ScriptContext *ctx) {
    u16 **r5 = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_FIELD_34);
    u16 value = ScriptGetVar(ctx);
    if (*r5 != NULL) {
        **r5 = value;
    }
    return FALSE;
}

BOOL ScrCmd_DoorAnimationLoad(ScriptContext *ctx) {
    u16 chunkX = ScriptReadHalfword(ctx);
    u16 chunkZ = ScriptReadHalfword(ctx);
    u16 localX = ScriptGetVar(ctx);
    u16 localZ = ScriptGetVar(ctx);
    u8 tag = ScriptReadByte(ctx);
    DoorAnimation_Load(ctx->fieldSystem, localX + 32 * chunkX, localZ + 32 * chunkZ, tag);
    return FALSE;
}

BOOL ScrCmd_DoorAnimationWait(ScriptContext *ctx) {
    u8 tag = ScriptReadByte(ctx);
    DoorAnimation_WaitForEnd(ctx->fieldSystem, tag);
    return TRUE;
}

BOOL ScrCmd_DoorAnimationUnload(ScriptContext *ctx) {
    u8 tag = ScriptReadByte(ctx);
    DoorAnimation_Unload(ctx->fieldSystem, tag);
    return FALSE;
}

BOOL ScrCmd_DoorAnimationOpen(ScriptContext *ctx) {
    u8 tag = ScriptReadByte(ctx);
    DoorAnimation_PlayOpen(ctx->fieldSystem, tag);
    return FALSE;
}

BOOL ScrCmd_DoorAnimationClose(ScriptContext *ctx) {
    u8 tag = ScriptReadByte(ctx);
    DoorAnimation_PlayClose(ctx->fieldSystem, tag);
    return FALSE;
}

BOOL ScrCmd_EcruteakGymInit(ScriptContext *ctx) {
    InitEcruteakGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_EcruteakGymBindCandleToTrainer(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    if (Save_Gymmick_GetType(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem))) != GYMMICK_ECRUTEAK) {
        return FALSE;
    }
    EcruteakGymmick_BindCandleToTrainerObject(fieldSystem);
    return FALSE;
}

BOOL ScrCmd_EcruteakGymUnbindCandleFromTrainer(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    if (Save_Gymmick_GetType(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem))) != GYMMICK_ECRUTEAK) {
        return FALSE;
    }
    EcruteakGymmick_UnbindCandle(fieldSystem);
    return FALSE;
}

BOOL ScrCmd_EcruteakGymExtinguishCandle(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 useLastInteracted = ScriptReadByte(ctx);
    if (Save_Gymmick_GetType(Save_GetGymmickPtr(FieldSystem_GetSaveData(fieldSystem))) != GYMMICK_ECRUTEAK) {
        return TRUE;
    }
    EcruteakGymmick_ExtinguishCandle(fieldSystem, (useLastInteracted != 0) ? SCRIPTENV_LAST_INTERACTED : SCRIPTENV_ENGAGED_TRAINER_0_EVENT);
    return TRUE;
}

BOOL ScrCmd_CianwoodGymInit(ScriptContext *ctx) {
    InitCianwoodGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_CianwoodGymTurnWinch(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = CianwoodGymmick_ActivateWinch(fieldSystem);
    return TRUE;
}

BOOL ScrCmd_VermilionGymInit(ScriptContext *ctx) {
    InitVermilionGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_VermilionGymLockAction(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 lockno = ScriptReadByte(ctx);
    u8 relock = ScriptReadByte(ctx);
    VermilionGymmick_GateAction(fieldSystem, lockno, relock);
    return TRUE;
}

BOOL ScrCmd_VermilionGymCanCheck(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 canId = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = VermilionGymmick_SwitchCheck(fieldSystem, canId);
    return FALSE;
}

BOOL ScrCmd_ResampleVermilionGymCans(ScriptContext *ctx) {
    PlaceVermilionGymSwitches(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_VioletGymInit(ScriptContext *ctx) {
    InitVioletGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_VioletGymElevator(ScriptContext *ctx) {
    VioletGymmick_ElevatorAction(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_AzaleaGymInit(ScriptContext *ctx) {
    InitAzaleaGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_AzaleaGymSpinarak(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 spinarakNo = ScriptReadByte(ctx);
    BeginAzaleaGymSpinarakRide(fieldSystem, spinarakNo);
    return TRUE;
}

BOOL ScrCmd_AzaleaGymSwitch(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 switchNo = ScriptReadByte(ctx);
    FlipAzaleaGymSwitch(fieldSystem, switchNo);
    return TRUE;
}

BOOL ScrCmd_BlackthornGymInit(ScriptContext *ctx) {
    InitBlackthornGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_FuchsiaGymInit(ScriptContext *ctx) {
    InitFuchsiaGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_ViridianGymInit(ScriptContext *ctx) {
    InitViridianGym(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_GetPlayerXYZ(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_x = ScriptGetVarPointer(ctx);
    u16 *p_y = ScriptGetVarPointer(ctx);
    u16 *p_z = ScriptGetVarPointer(ctx);
    LocalMapObject *playerObj = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    *p_x = MapObject_GetXCoord(playerObj);
    *p_y = MapObject_GetYCoord(playerObj) / 2;
    *p_z = MapObject_GetZCoord(playerObj);
    return FALSE;
}

BOOL ScrCmd_EggHatchAnim(ScriptContext *ctx) {
    HatchEggInParty(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_MakeObjectVisible(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 objId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, objId);
    GF_ASSERT(object != NULL);
    MapObject_SetInvisible(object, FALSE);
    return FALSE;
}

BOOL ScrCmd_MakeObjectInvisible(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 objId = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, objId);
    GF_ASSERT(object != NULL);
    MapObject_SetInvisible(object, TRUE);
    return FALSE;
}

BOOL ScrCmd_OpenMailbox(ScriptContext *ctx) {                                                                // todo: mail screen
    MailboxAppArgs **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA); // MailAppData
    *p_work = Mailbox_LaunchApp(ctx->fieldSystem, HEAP_ID_FIELD2);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_CountMailboxMessages(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Mailbox_CountMessages(Save_Mailbox_Get(fieldSystem->saveData), 0);
    return FALSE;
}

BOOL ScrCmd_ViewRankings(ScriptContext *ctx) {
    u16 pageScrollParam = ScriptGetVar(ctx);
    u16 cursorPos = ScriptGetVar(ctx);
    FieldSystem_LaunchTask_ViewRankingsApp(ctx->fieldSystem, pageScrollParam, cursorPos);
    return TRUE;
}

BOOL ScrCmd_GetCurrentTimeOfDay(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Field_GetTimeOfDay(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_Random(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 modulo = ScriptGetVar(ctx);
    *p_ret = LCRandom() % modulo;
    return TRUE;
}

BOOL ScrCmd_Random2(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 modulo = ScriptGetVar(ctx);
    *p_ret = LCRandom() % modulo;
    return TRUE;
}

BOOL ScrCmd_GiveAccessory(ScriptContext *ctx) {
    u16 id = ScriptGetVar(ctx);
    u16 quantity = ScriptGetVar(ctx);
    FashionCase_GiveFashionItem(Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData)), id, quantity);
    return FALSE;
}

BOOL ScrCmd_CanGiveAccessory(ScriptContext *ctx) {
    u16 id = ScriptGetVar(ctx);
    u16 quantity = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FashionCase_CanGiveAccessory(Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData)), id, quantity);
    return FALSE;
}

BOOL ScrCmd_HasAccessoryCount(ScriptContext *ctx) {
    u16 id = ScriptGetVar(ctx);
    u16 quantity = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = quantity <= FashionCase_GetAccessoryCount(Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData)), id);
    return FALSE;
}

BOOL ScrCmd_GiveContestBackground(ScriptContext *ctx) {
    u16 id = ScriptGetVar(ctx);
    FashionCase_GiveContestBackground(Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData)), id);
    return FALSE;
}

BOOL ScrCmd_HasWallpaper(ScriptContext *ctx) {
    u16 index = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FashionCase_HasWallpaper(Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData)), index);
    return FALSE;
}

BOOL ScrCmd_CheckJohtoDexComplete(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FALSE;
    if (Pokedex_JohtoDexIsComplete(pokedex) == TRUE) {
        *p_ret = TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_CheckNationalDexComplete(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FALSE;
    if (Pokedex_NationalDexIsComplete(pokedex) == TRUE) {
        *p_ret = TRUE;
    }
    return FALSE;
}

BOOL ScrCmd_ShowCertificate(ScriptContext *ctx) {
    CertificatesArgs **args = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 certificateId = ScriptGetVar(ctx);
    *args = Certificates_LaunchApp(ctx->fieldSystem, HEAP_ID_FIELD3, certificateId);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_Dummy427(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    // dummy
    return FALSE;
}

BOOL ScrCmd_IncGameStat(ScriptContext *ctx) {
    u16 statno = ScriptReadHalfword(ctx);
    GameStats_Inc(Save_GameStats_Get(ctx->fieldSystem->saveData), statno);
    return FALSE;
}

BOOL ScrCmd_GetGameStatHiLo(ScriptContext *ctx) {
    u16 statIdx = ScriptReadHalfword(ctx);
    u16 hiVarId = ScriptReadHalfword(ctx);
    u16 loVarId = ScriptReadHalfword(ctx);
    u16 *p_ret_hi = GetVarPointer(ctx->fieldSystem, hiVarId);
    u16 *p_ret_lo = GetVarPointer(ctx->fieldSystem, loVarId);
    u32 statval = GameStats_GetCapped(Save_GameStats_Get(ctx->fieldSystem->saveData), statIdx);
    *p_ret_hi = (statval & 0xFFFF0000) >> 16;
    *p_ret_lo = statval & 0x0000FFFF;
    return FALSE;
}

BOOL ScrCmd_ModifyGameStat(ScriptContext *ctx) {
    u16 statIdx = ScriptReadHalfword(ctx);
    u16 value_hi = ScriptReadHalfword(ctx);
    u16 value_lo = ScriptReadHalfword(ctx);
    u8 action = ScriptReadByte(ctx);

    u32 value = (value_hi << 16) | value_lo;
    switch (action) {
    case 0:
        GameStats_Add(Save_GameStats_Get(ctx->fieldSystem->saveData), statIdx, value);
        break;
    case 1:
        GameStats_SetCapped(Save_GameStats_Get(ctx->fieldSystem->saveData), statIdx, value);
        break;
    case 2:
        GameStats_UpdateBounded(Save_GameStats_Get(ctx->fieldSystem->saveData), statIdx, value);
        break;
    }
    return FALSE;
}

BOOL ScrCmd_AddGameStat(ScriptContext *ctx) {
    u16 statIdx = ScriptReadHalfword(ctx);
    u16 value = ScriptGetVar(ctx);
    GameStats_Add(Save_GameStats_Get(ctx->fieldSystem->saveData), statIdx, value);
    return FALSE;
}

BOOL ScrCmd_AddGameStatWord(ScriptContext *ctx) {
    u16 statIdx = ScriptReadHalfword(ctx);
    u32 value = ScriptReadWord(ctx);
    GameStats_Add(Save_GameStats_Get(ctx->fieldSystem->saveData), statIdx, value);
    return FALSE;
}

BOOL ScrCmd_SafariZoneAction(ScriptContext *ctx) {
    LocalFieldData *localFieldData = Save_LocalFieldData_Get(ctx->fieldSystem->saveData);
    SaveVarsFlags *varsFlags = Save_VarsFlags_Get(ctx->fieldSystem->saveData);
    SafariZone *safariZone = Save_SafariZone_Get(ctx->fieldSystem->saveData);
    u8 action = ScriptReadByte(ctx);
    u8 areaSet = ScriptReadByte(ctx);
    u16 *p_nSafariBall = LocalFieldData_GetSafariBallsCounter(localFieldData);
    u16 *p_nSafariSteps = LocalFieldData_GetSafariStepsCounter(localFieldData);
    int level;

    switch (action) {
    case 0:
        Save_VarsFlags_SetSafariSysFlag(varsFlags);
        SafariZone_SetActiveAreaSet(safariZone, areaSet);
        *p_nSafariBall = 30;
        *p_nSafariSteps = 0;
        break;
    case 1:
        Save_VarsFlags_ClearSafariSysFlag(varsFlags);
        SafariZone_SetActiveAreaSet(safariZone, 1);
        level = SafariZone_GetLevel(safariZone);
        if (level != 0) {
            SaveData_SafariZone_CheckAreasWithUpdatedEncounters(ctx->fieldSystem->saveData, level);
            SafariZone_SetLevel(safariZone, 0);
        }
        *p_nSafariBall = 0;
        *p_nSafariSteps = 0;
        break;
    }
    return FALSE;
}

BOOL ScrCmd_LighthouseLightUp(ScriptContext *ctx) {
    ShowLighthouseLightUp(ctx->taskman);
    return TRUE;
}

BOOL ScrCmd_TogglePlayerAutoHeightUpdate(ScriptContext *ctx) {
    u8 arg = ScriptReadByte(ctx);
    PlayerAvatar_ToggleAutomaticHeightUpdating(ctx->fieldSystem->playerAvatar, arg);
    return TRUE;
}

BOOL ScrCmd_EnableMassOutbreaks(ScriptContext *ctx) {
    RoamerSave_SetOutbreakActive(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL ScrCmd_CreateRoamer(ScriptContext *ctx) {
    u8 roamerNo = ScriptReadByte(ctx);
    Save_CreateRoamerByID(ctx->fieldSystem->saveData, roamerNo);
    return FALSE;
}

BOOL ScrCmd_LoadNPCTrade(ScriptContext *ctx) {
    NPCTradeAppData **p_tradeWork = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u8 tradeNo = ScriptReadByte(ctx);

    HandleLoadOverlay(FS_OVERLAY_ID(npc_trade), OVY_LOAD_ASYNC);
    *p_tradeWork = NPCTradeApp_Init(HEAP_ID_FIELD2, (NpcTradeNum)tradeNo);
    return FALSE;
}

BOOL ScrCmd_GetOfferedSpecies(ScriptContext *ctx) {
    NPCTradeAppData **p_tradeWork = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = NPCTradeApp_GetOfferedSpecies(*p_tradeWork);
    return FALSE;
}

BOOL ScrCmd_NPCTradeGetReqSpecies(ScriptContext *ctx) {
    NPCTradeAppData **p_tradeWork = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = NPCTradeApp_GetRequestedSpecies(*p_tradeWork);
    return FALSE;
}

BOOL ScrCmd_GetNPCTradeUnusedFlag(ScriptContext *ctx) {
    NPCTradeAppData **p_tradeWork = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = NPCTradeApp_GetUnusedFlag(*p_tradeWork);
    return FALSE;
}

BOOL ScrCmd_NPCTradeExec(ScriptContext *ctx) {
    NPCTradeAppData **p_tradeWork = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 arg = ScriptGetVar(ctx);
    CallTask_NPCTrade(ctx->taskman, *p_tradeWork, arg, HEAP_ID_FIELD2);
    return TRUE;
}

BOOL ScrCmd_NPCTradeEnd(ScriptContext *ctx) {
    NPCTradeAppData **p_tradeWork = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    NPCTradeApp_Delete(*p_tradeWork);
    UnloadOverlayByID(FS_OVERLAY_ID(npc_trade));
    return FALSE;
}

BOOL ScrCmd_GiveLoanMon(ScriptContext *ctx) {
    u8 tradeno = ScriptReadByte(ctx);
    u8 level = ScriptReadByte(ctx);
    u16 mapno = ScriptReadHalfword(ctx);
    HandleLoadOverlay(FS_OVERLAY_ID(npc_trade), OVY_LOAD_ASYNC);
    NPCTrade_MakeAndGiveLoanMon(ctx->fieldSystem, (NpcTradeNum)tradeno, level, mapno);
    UnloadOverlayByID(FS_OVERLAY_ID(npc_trade));
    return FALSE;
}

BOOL ScrCmd_CheckReturnLoanMon(ScriptContext *ctx) {
    u8 tradeno = ScriptReadByte(ctx);
    u16 idx = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    HandleLoadOverlay(FS_OVERLAY_ID(npc_trade), OVY_LOAD_ASYNC);
    *p_ret = NPCTrade_CanGiveUpLoanMon(ctx->fieldSystem, (NpcTradeNum)tradeno, idx);
    UnloadOverlayByID(FS_OVERLAY_ID(npc_trade));
    return FALSE;
}

BOOL ScrCmd_Dummy475(ScriptContext *ctx) {
    // dummy
    return FALSE;
}

BOOL ScrCmd_EnablePokedexFormDetection(ScriptContext *ctx) {
    Pokedex_EnableFormDetection(Save_Pokedex_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_NatDexFlagAction(ScriptContext *ctx) {
    u8 action = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = 0;
    if (action == 1) {
        Pokedex_SetNatDexFlag(Save_Pokedex_Get(ctx->fieldSystem->saveData));
        PlayerProfile_SetNatDexFlag(Save_PlayerData_GetProfile(ctx->fieldSystem->saveData));
    } else if (action == 2) {
        *p_ret = Pokedex_GetNatDexFlag(Save_Pokedex_Get(ctx->fieldSystem->saveData));
    } else {
        GF_ASSERT(FALSE);
    }
    return FALSE;
}

BOOL ScrCmd_GetEVTotal(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 partyIdx = ScriptGetVar(ctx);
    Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(ctx->fieldSystem->saveData), partyIdx);

    int hpEv = GetMonData(mon, MON_DATA_HP_EV, NULL);
    int atkEv = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    int defEv = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    int speedEv = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    int spAtkEv = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    int spDefEv = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    *p_ret = hpEv + atkEv + defEv + speedEv + spAtkEv + spDefEv;
    return FALSE;
}

BOOL ScrCmd_GetWeekday(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    RTCDate date;
    GF_RTC_CopyDate(&date);
    *p_ret = date.week;
    return FALSE;
}

BOOL ScrCmd_StartBattleRegulationMenuTask(ScriptContext *ctx) {
    u16 *result = ScriptGetVarPointer(ctx);
    StartTask_BattleRegulationMenu(ctx->taskman, result);
    return TRUE;
}

BOOL ScrCmd_PokeCenAnim(ScriptContext *ctx) {
    u16 kind = ScriptGetVar(ctx);
    PokecenterAnimCreate(ctx->fieldSystem, kind);
    return TRUE;
}

BOOL ScrCmd_ElevatorAnim(ScriptContext *ctx) {
    u16 direction = ScriptGetVar(ctx);
    u16 length = ScriptGetVar(ctx);
    ElevatorAnimCreate(ctx->fieldSystem, direction, length);
    return TRUE;
}

BOOL ScrCmd_GetGameVersion(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = GAME_VERSION;
    return FALSE;
}

BOOL ScrCmd_PrimoPasswordCheck1(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(fieldSystem));
    u16 *p_ret = ScriptGetVarPointer(ctx);
    PCStorage *pcStorage = SaveArray_PCStorage_Get(fieldSystem->saveData);
    u16 a = ScriptGetVar(ctx);
    u16 b = ScriptGetVar(ctx);
    u16 c = ScriptGetVar(ctx);
    u16 d = ScriptGetVar(ctx);
    int wallpaper = PrimoPassword_CheckWallpaper(profile, a, b, c, d, HEAP_ID_FIELD1);
    if (wallpaper == -1 || wallpaper > 7) {
        *p_ret = 0xFF;
        return FALSE;
    } else if (PCStorage_IsBonusWallpaperUnlocked(pcStorage, wallpaper)) {
        *p_ret = 0;
    } else {
        PCStorage_UnlockBonusWallpaper(pcStorage, wallpaper);
        *p_ret = wallpaper + 1;
    }
    return FALSE;
}

BOOL ScrCmd_PrimoPasswordCheck2(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    PlayerProfile *profile = Save_PlayerData_GetProfile(FieldSystem_GetSaveData(fieldSystem));
    u16 *p_ret = ScriptGetVarPointer(ctx);
    PCStorage *pcStorage = SaveArray_PCStorage_Get(fieldSystem->saveData);
    u16 a = ScriptGetVar(ctx);
    u16 b = ScriptGetVar(ctx);
    u16 c = ScriptGetVar(ctx);
    u16 d = ScriptGetVar(ctx);
    int result = PrimoPassword_Check2(profile, a, b, c, d, HEAP_ID_FIELD1);
    if (result == -1) {
        *p_ret = 0xFF;
        return FALSE;
    } else {
        *p_ret = result;
    }
    return FALSE;
}

BOOL ScrCmd_PCPropLoadAnimation(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 tag = ScriptReadByte(ctx);
    PCProp_LoadAnimations(fieldSystem, tag);
    return FALSE;
}

BOOL ScrCmd_PCPropPowerOn(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 tag = ScriptReadByte(ctx);
    PCProp_PlayPowerOnAnimation(fieldSystem, tag);
    return FALSE;
}

BOOL ScrCmd_PCPropPowerOff(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u8 tag = ScriptReadByte(ctx);
    PCProp_PlayPowerOffAnimation(fieldSystem, tag);
    return FALSE;
}

void Script_SetMonSeenFlagBySpecies(FieldSystem *fieldSystem, u16 species) {
    Pokedex *pokedex = Save_Pokedex_Get(fieldSystem->saveData);
    Pokemon *mon = AllocMonZeroed(HEAP_ID_FIELD3);
    ZeroMonData(mon);
    CreateMon(mon, species, 50, 32, FALSE, 0, OT_ID_PLAYER_ID, 0);
    Pokedex_SetMonSeenFlag(pokedex, mon);
    Heap_Free(mon);
}

BOOL ScrCmd_SetMonSeenFlag(ScriptContext *ctx) {
    u16 species = ScriptGetVar(ctx);
    Script_SetMonSeenFlagBySpecies(ctx->fieldSystem, species);
    return FALSE;
}

BOOL ScrCmd_CountPCEmptySpace(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = PCStorage_CountEmptySpotsInAllBoxes(SaveArray_PCStorage_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_PlayerMovementSavingSet(ScriptContext *ctx) {
    SysTask **p_task = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_FIELD_B8);
    *p_task = PLAYER_STATE_WALKING;
    *p_task = Field_PlayerMovementSavingSet(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_PlayerMovementSavingClear(ScriptContext *ctx) {
    SysTask **p_task = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_FIELD_B8);
    Field_PlayerMovementSavingClear(*p_task);
    return TRUE;
}

BOOL ScrCmd_HallOfFameAnim(ScriptContext *ctx) {
    u16 kind = ScriptGetVar(ctx);
    HallOfFame_StartBallAnim(ctx->fieldSystem, kind);
    return TRUE;
}

BOOL ScrCmd_AddSpecialGameStat(ScriptContext *ctx) {
    u16 statno = ScriptReadHalfword(ctx);
    GameStats_AddScore(Save_GameStats_Get(ctx->fieldSystem->saveData), statno);
    return FALSE;
}

BOOL ScrCmd_PartyHasSpecies(ScriptContext *ctx) {
    u16 species = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Party_HasMon(SaveArray_Party_Get(ctx->fieldSystem->saveData), species);
    return TRUE;
}

BOOL ScrCmd_SetPartyDeoxysForm(ScriptContext *ctx) {
    u16 form = ScriptGetVar(ctx);
    Party *party = SaveArray_Party_Get(ctx->fieldSystem->saveData);
    int partyCount = Party_GetCount(party);
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    int i;

    for (i = 0; i < partyCount; i++) {
        Pokemon *mon = Party_GetMonByIndex(party, i);
        if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_DEOXYS) {
            SetMonData(mon, MON_DATA_FORM, &form);
            CalcMonLevelAndStats(mon);
            Pokedex_SetMonCaughtFlag(pokedex, mon);
        }
    }
    return TRUE;
}

BOOL ScrCmd_CountPartyBurmyForms(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    Party *party = SaveArray_Party_Get(ctx->fieldSystem->saveData);
    int partyCount = Party_GetCount(party);

    int forms[PARTY_SIZE] = {
        0x07FFFFFF,
        0x07FFFFFF,
        0x07FFFFFF,
        0x07FFFFFF,
        0x07FFFFFF,
        0x07FFFFFF,
    };
    int uniqueForms = 0;
    int i;

    for (i = 0; i < partyCount; i++) {
        int j;
        BOOL hasMultiple;
        Pokemon *mon = Party_GetMonByIndex(party, i);
        u32 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
        u32 form = GetMonData(mon, MON_DATA_FORM, NULL);
        if (species == SPECIES_BURMY) {
            hasMultiple = FALSE;
            for (j = 0, forms[i] = form; j < i; j++) {
                if (forms[j] == form) {
                    hasMultiple = TRUE;
                }
            }
            if (!hasMultiple) {
                uniqueForms++;
            }
        }
    }
    *p_ret = uniqueForms;
    return TRUE;
}

BOOL ScrCmd_SetFlagUnk975(ScriptContext *ctx) {
    SetFlag975(Save_VarsFlags_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_ClearFlagUnk975(ScriptContext *ctx) {
    ClearFlag975(Save_VarsFlags_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_GetCurrentHour(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Field_GetHour(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_SpinObject(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 turns = ScriptGetVar(ctx);
    u16 step = ScriptGetVar(ctx);
    u16 xRadius = ScriptGetVar(ctx);
    u16 zRadius = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    GF_ASSERT(object != NULL);
    CallTask_SpinMapObject(ctx->taskman, object, turns, step, xRadius, zRadius);
    return TRUE;
}

BOOL ScrCmd_BlinkObject(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u16 cycles = ScriptGetVar(ctx);
    u16 interval = ScriptGetVar(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    GF_ASSERT(object != NULL);
    CallTask_BlinkMapObject(ctx->taskman, object, cycles, interval);
    return TRUE;
}

BOOL ScrCmd_HasAllRegisInParty(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Save_PlayerHasAllRegisInParty(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL ScrCmd_GetRandomGivableAccessory(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    FashionCase *fashionCase = Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData));
    int i, k, n = 0;
    u16 canGive[16];

    // UB: Since canGive is not initialized, it is possible
    // (though unlikely) that some element could randomly
    // be equal to 1 unintentionally on entry.
    for (i = 0; i < 16; i++) {
        if (FashionCase_CanGiveAccessory(fashionCase, i + 34, 1) == TRUE) {
            canGive[i] = 1;
            n++;
        }
    }
    if (n == 0) {
        *p_ret = -1;
        return FALSE;
    }
    k = LCRandom() % n;
    for (i = 0; i < 16; i++) {
        if (canGive[i] == 1) {
            if (k == 0) {
                break;
            }
            k--;
        }
    }
    GF_ASSERT(i < 16);
    *p_ret = i + 34;
    return FALSE;
}

BOOL ScrCmd_GetAgbCartridgeVersion(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = gSystem.agbCartridgeVersion;
    return TRUE;
}

BOOL ScrCmd_MapEventKeyAction(ScriptContext *ctx) {
    u16 key = ScriptGetVar(ctx);
    u8 action = ScriptReadByte(ctx);
    SaveVarsFlags *varsFlags = Save_VarsFlags_Get(ctx->fieldSystem->saveData);
    if (action) {
        Save_VarsFlags_SetMapEventKey(varsFlags, key);
    } else {
        Save_VarsFlags_ClearMapEventKey(varsFlags, key);
    }
    return FALSE;
}

BOOL ScrCmd_BufferBackgroundName(ScriptContext *ctx) {
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    u8 bufferId = ScriptReadByte(ctx);
    u16 backgroundId = ScriptGetVar(ctx);
    BufferContestBackgroundName(*p_msgFmt, bufferId, backgroundId);
    return TRUE;
}

BOOL ScrCmd_GetVar4041(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Save_VarsFlags_GetVar4041(Save_VarsFlags_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_TakeFashionAccessory(ScriptContext *ctx) {
    u16 id = ScriptGetVar(ctx);
    u16 quantity = ScriptGetVar(ctx);
    FashionCase_TakeAccessory(Save_FashionData_GetFashionCase(Save_FashionData_Get(ctx->fieldSystem->saveData)), id, quantity);
    return FALSE;
}

BOOL ScrCmd_RandomizeVar4041(ScriptContext *ctx) {
    Save_VarsFlags_RandomizeVar4041(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL ScrCmd_UnlockRandomTrendySaying(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 wordIdx = ScriptGetVar(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    int trendy = Save_EasyChat_SetRandomTrendySaying(Save_EasyChat_Get(ctx->fieldSystem->saveData));
    if (trendy == 32) {
        *p_ret = 0xFFFF;
        return FALSE;
    }
    *p_ret = trendy;
    BufferECWord(*p_msgFmt, wordIdx, TrendyWordIdxToECWord(trendy));
    return FALSE;
}

BOOL ScrCmd_CheckAllTrendySayingsUnlocked(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Save_EasyChat_TrendySayingsUnlockedAllCheck(Save_EasyChat_Get(ctx->fieldSystem->saveData)) == TRUE;
    return FALSE;
}

BOOL ScrCmd_CheckVar4042AtLeast5(ScriptContext *ctx) {
    SaveVarsFlags *varsFlags = Save_VarsFlags_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Save_VarsFlags_GetVar4042(varsFlags) >= 5;
    return FALSE;
}

BOOL ScrCmd_CheckIsPlayerBirthday(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    FieldSystem *fieldSystem = ctx->fieldSystem;
    SysInfo *sysInfo = Save_SysInfo_Get(fieldSystem->saveData);
    if (Save_SysInfo_GetBirthMonth(sysInfo) == Field_GetMonth(fieldSystem) && Save_SysInfo_GetBirthDay(sysInfo) == Field_GetDay(fieldSystem)) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_CountUnownLettersRegistered(ScriptContext *ctx) {
    Pokedex *pokedex = Save_Pokedex_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Pokedex_GetSeenFormNum_Unown(pokedex, TRUE);
    return FALSE;
}

BOOL ScrCmd_CheckEventKey(ScriptContext *ctx) {
    u8 mode = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    SaveVarsFlags *varsFlags = Save_VarsFlags_Get(ctx->fieldSystem->saveData);
    GF_ASSERT(mode <= 1);
    *p_ret = Save_VarsFlags_CheckEventKey(varsFlags, mode);
    return FALSE;
}

BOOL ScrCmd_GetHallOfFameEntryCount(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    int loadResult;
    HallOfFame *hof = LoadHallOfFame(ctx->fieldSystem->saveData, HEAP_ID_FIELD3, &loadResult);
    if (loadResult == 0) {
        *p_ret = 0;
        Heap_Free(hof);
        return TRUE;
    } else if (loadResult == 1) {
        *p_ret = Save_HOF_TranslateRecordIdx(hof, 0);
        Heap_Free(hof);
        return TRUE;
    } else if (loadResult == 2) {
        *p_ret = 0;
        Heap_Free(hof);
        return TRUE;
    } else {
        *p_ret = 0;
        return TRUE;
    }
}

BOOL ScrCmd_ChoosePartyMonForDayCare(ScriptContext *ctx) {
    u16 partySlot = ScriptGetVar(ctx);
    PartyMenuArgs **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_work = PartyMenu_LaunchApp_DayCare(HEAP_ID_FIELD3, ctx->fieldSystem, partySlot);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_GetDayCarePartySelection(ScriptContext *ctx) {
    u16 *p_slot = ScriptGetVarPointer(ctx);
    u16 *p_action = ScriptGetVarPointer(ctx);
    struct PartyMenuArgs **partyMenu = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    GF_ASSERT(*partyMenu != NULL);
    *p_slot = PartyMenuArgs_GetSlot(*partyMenu);
    if (*p_slot == 7) {
        *p_slot = 255;
    }
    *p_action = PartyMenuArgs_GetSelectedAction(*partyMenu);
    *p_action = (*p_action == TRUE);
    Heap_Free(*partyMenu);
    *partyMenu = NULL;
    return FALSE;
}

BOOL ScrCmd_RandomChance(ScriptContext *ctx) {
    u8 limit = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 rnd;
    if (limit > 100) {
        limit = 100;
    }
    rnd = LCRandom() % 101;
    if (rnd <= limit) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_StartFieldMoveEffect(ScriptContext *ctx) {
    u16 my_case = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    FieldSystem *fieldSystem = ctx->fieldSystem;
    switch (my_case) {
    case 0:
        ScriptFieldMoveEffect_Start(fieldSystem, p_ret, 0, HEAP_ID_FIELD3);
        break;
    case 1:
        ScriptFieldMoveEffect_Start(fieldSystem, p_ret, 1, HEAP_ID_FIELD3);
        break;
    case 2:
        ScriptFieldMoveEffect_Start(fieldSystem, p_ret, 2, HEAP_ID_FIELD3);
        break;
    case 3:
        ScriptFieldMoveEffect_Start(fieldSystem, p_ret, 3, HEAP_ID_FIELD3);
        break;
    case 4:
        ScriptFieldMoveEffect_Start(fieldSystem, p_ret, 4, HEAP_ID_FIELD3);
        break;
    case 5:
        ScriptFieldMoveEffect_Start(fieldSystem, p_ret, 5, HEAP_ID_FIELD3);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return TRUE;
}

BOOL ScrCmd_CheckHasWifiProfile(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = Comm_HasWifiProfile(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL ScrCmd_CountWifiFriends(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FriendRoster_CountFriends(Save_FriendRoster_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_ItemIsPlate(ScriptContext *ctx) {
    u16 itemId = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = 0;
    if (itemId >= 0x12A && itemId <= 0x139) {
        *p_ret = 1;
    }
    return FALSE;
}

BOOL ScrCmd_CheckEasyChatWordsMatchFixedPhrase(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u16 word1 = ScriptGetVar(ctx);
    u16 word2 = ScriptGetVar(ctx);
    u16 word3 = ScriptGetVar(ctx);
    u16 word4 = ScriptGetVar(ctx);
    String *phraseStr;
    String *answerStr;
    MessageFormat *msgFmt = MessageFormat_New(HEAP_ID_FIELD3);
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0202_bin, HEAP_ID_FIELD3);
    BufferECWord(msgFmt, 0, word1);
    BufferECWord(msgFmt, 1, word2);
    BufferECWord(msgFmt, 2, word3);
    BufferECWord(msgFmt, 3, word4);
    phraseStr = ReadMsgData_ExpandPlaceholders(msgFmt, msgData, msg_0202_00001, HEAP_ID_FIELD3);
    answerStr = NewString_ReadMsgData(msgData, msg_0202_00000);
    *p_ret = String_Compare(phraseStr, answerStr) == FALSE;
    String_Delete(phraseStr);
    String_Delete(answerStr);
    DestroyMsgData(msgData);
    MessageFormat_Delete(msgFmt);
    return FALSE;
}

BOOL ScrCmd_SetMysteryGiftActive(ScriptContext *ctx) {
    Save_SysInfo_SetMysteryGiftActive(Save_SysInfo_Get(ctx->fieldSystem->saveData), 1);
    return FALSE;
}

BOOL ScrCmd_GetUnionRoomPartnerHometownMsg2(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    *p_ret = UnionRoom_GetPartnerHometownMsg(*p_msgFmt);
    return FALSE;
}

BOOL ScrCmd_CreateWirelessStatusIcon(ScriptContext *ctx) {
    WirelessStatusIcon_Create();
    return FALSE;
}

BOOL ScrCmd_DestroyWirelessStatusIcon(ScriptContext *ctx) {
    WirelessStatusIcon_Destroy();
    return FALSE;
}

BOOL ScrCmd_SyncMapObjectsToSave(ScriptContext *ctx) {
    FieldSystem_SyncMapObjectsToSave(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_SetSpecialSpawnWarp(ScriptContext *ctx) {
    u16 mapId = ScriptGetVar(ctx);
    u16 x = ScriptGetVar(ctx);
    u16 y = ScriptGetVar(ctx);
    Location *specialSpawn = LocalFieldData_GetSpecialSpawnWarpPtr(Save_LocalFieldData_Get(ctx->fieldSystem->saveData));
    specialSpawn->mapId = mapId;
    specialSpawn->x = x;
    specialSpawn->y = y;
    specialSpawn->warpId = -1;
    specialSpawn->direction = DIR_SOUTH;
    return FALSE;
}

BOOL ScrCmd_ClearObjectFlag18(ScriptContext *ctx) {
    u16 objectId = ScriptGetVar(ctx);
    u8 clear = ScriptReadByte(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    GF_ASSERT(object != NULL);
    MapObject_ClearFlag18(object, clear);
    return FALSE;
}

BOOL ScrCmd_GetTrcardStars(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FieldSystem_GetTrainerCardStars(fieldSystem);
    return FALSE;
}

BOOL ScrCmd_ShowSaveStats(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    struct SaveStatsPrinter **saveStatsPrinter = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SAVE_STATS_PRINTER);
    if (!Save_FileDoesNotBelongToPlayer(fieldSystem->saveData)) {
        *saveStatsPrinter = Field_SaveStatsPrinter_New(fieldSystem, HEAP_ID_FIELD1, 3);
        Field_SaveStatsPrinter_Print(*saveStatsPrinter);
    }
    return FALSE;
}

BOOL ScrCmd_HideSaveStats(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    struct SaveStatsPrinter **saveStatsPrinter = FieldSysGetAttrAddr(fieldSystem, SCRIPTENV_SAVE_STATS_PRINTER);
    if (!Save_FileDoesNotBelongToPlayer(fieldSystem->saveData)) {
        Field_SaveStatsPrinter_RemoveFromScreen(*saveStatsPrinter);
        Field_SaveStatsPrinter_Delete(*saveStatsPrinter);
    }
    return FALSE;
}

BOOL ScrCmd_SetWarpResetSuppressed(ScriptContext *ctx) {
    u8 suppressed = ScriptReadByte(ctx);
    FieldSystem_SetWarpResetSuppressed(ctx->fieldSystem, suppressed);
    return FALSE;
}

BOOL ScrCmd_LaunchFrontier(ScriptContext *ctx) {
    FrontierLaunchArgs **pArgs = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u8 frontierMapId = ScriptReadByte(ctx);
    FrontierLaunchArgs *args = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(FrontierLaunchArgs));
    MI_CpuClear8(args, sizeof(FrontierLaunchArgs));
    *pArgs = args;
    if (frontierMapId == 5 || frontierMapId == 6) {
        args->frontierFsys = ctx->fieldSystem->frontierFsys;
    } else {
        args->frontierFsys = NULL;
    }
    args->options = Save_PlayerData_GetOptionsAddr(ctx->fieldSystem->saveData);
    args->frontierMapId = frontierMapId;
    args->saveData = ctx->fieldSystem->saveData;
    args->mapId = ctx->fieldSystem->location->mapId;
    args->bagCursor = ctx->fieldSystem->bagCursor;
    args->keyPressedSave = ctx->fieldSystem->keyPressedSave;
    CallApplicationAsTask(ctx->taskman, &gOverlayTemplate_Frontier, args);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_OpenFrontierRecords(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u16 mode = ScriptGetVar(ctx);
    u16 facility = ScriptGetVar(ctx);
    u16 species = ScriptGetVar(ctx);
    *p_work = FrontierRecords_LaunchApp(ctx->fieldSystem, mode, facility, species, HEAP_ID_FIELD3);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_ScratchOffCard(ScriptContext *ctx) {
    ScratchOffCardsArgs **scratchCardData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *scratchCardData = ScratchOffCards_LaunchApp(ctx->fieldSystem, HEAP_ID_FIELD3);
    SetupNativeScript(ctx, ScrNative_WaitApplication);
    return TRUE;
}

BOOL ScrCmd_ScratchOffCardEnd(ScriptContext *ctx) {
    ScratchOffCardsArgs **scratchCardData = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    Heap_Free(*scratchCardData);
    *scratchCardData = NULL;
    return TRUE;
}

BOOL ScrCmd_GetScratchOffPrize(ScriptContext *ctx) {
    u16 cardno = ScriptGetVar(ctx);
    u16 *p_ret1 = ScriptGetVarPointer(ctx);
    u16 *p_ret2 = ScriptGetVarPointer(ctx);
    ScratchOffCardsArgs **scratchCardDataPtr = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    ScratchOffCardsArgs *scratchCardData = *scratchCardDataPtr;
    *p_ret1 = scratchCardData->prizeItems[cardno];
    *p_ret2 = scratchCardData->prizeKinds[cardno];
    return FALSE;
}

BOOL ScrCmd_LaunchGlobalTerminal(ScriptContext *ctx) {
    u16 r6 = ScriptGetVar(ctx);
    u16 connectDirectly = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (Comm_HasWifiProfile(ctx->fieldSystem->saveData)) {
        *p_ret = 1;
        GlobalTerminal_LaunchApp(ctx->fieldSystem, connectDirectly, r6);
        SetupNativeScript(ctx, ScrNative_WaitApplication);
    } else {
        *p_ret = 0;
    }
    return TRUE;
}

BOOL ScrCmd_LaunchWiFiPlaza(ScriptContext *ctx) {
    u16 *p_var = ScriptGetVarPointer(ctx);
    if (Comm_HasWifiProfile(ctx->fieldSystem->saveData)) {
        CallTask_WiFiPlaza(ctx->taskman, *p_var);
    }
    return TRUE;
}

BOOL ScrCmd_CheckABHeld(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = 0;
    if (gSystem.heldKeys & PAD_BUTTON_A) {
        *p_ret = 1;
    }
    if (gSystem.heldKeys & PAD_BUTTON_B) {
        *p_ret = 1;
    }
    return FALSE;
}

u32 GetOwnedRotomFormsMask(SaveData *saveData);

BOOL ScrCmd_GetOwnedRotomForms(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *hasHeat = ScriptGetVarPointer(ctx);
    u16 *hasWash = ScriptGetVarPointer(ctx);
    u16 *hasFrost = ScriptGetVarPointer(ctx);
    u16 *hasFan = ScriptGetVarPointer(ctx);
    u16 *hasMow = ScriptGetVarPointer(ctx);
    u32 flag;

    *hasHeat = FALSE;
    *hasWash = FALSE;
    *hasFrost = FALSE;
    *hasFan = FALSE;
    *hasMow = FALSE;

    flag = GetOwnedRotomFormsMask(fieldSystem->saveData);
    if (((flag >> ROTOM_HEAT) & 1) == 1) {
        *hasHeat = TRUE;
    }
    if (((flag >> ROTOM_WASH) & 1) == 1) {
        *hasWash = TRUE;
    }
    if (((flag >> ROTOM_FROST) & 1) == 1) {
        *hasFrost = TRUE;
    }
    if (((flag >> ROTOM_FAN) & 1) == 1) {
        *hasFan = TRUE;
    }
    if (((flag >> ROTOM_MOW) & 1) == 1) {
        *hasMow = TRUE;
    }
    return TRUE;
}

u32 GetOwnedRotomFormsMask(SaveData *saveData) {
    u32 ret = 0;
    Party *party = SaveArray_Party_Get(saveData);
    int partyCount = Party_GetCount(party);
    int i, j;

    for (i = 0; i < partyCount; i++) {
        Pokemon *mon = Party_GetMonByIndex(party, i);
        if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_ROTOM && !GetMonData(mon, MON_DATA_IS_EGG, NULL)) {
            ret |= 1 << GetMonData(mon, MON_DATA_FORM, NULL);
        }
    }

    Daycare *dayCare = Save_Daycare_Get(saveData);
    for (i = 0; i < 2; i++) {
        BoxPokemon *boxMon = DaycareMon_GetBoxMon(Save_Daycare_GetMonX(dayCare, i));
        if (GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL) == SPECIES_ROTOM && !GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
            ret |= 1 << GetBoxMonData(boxMon, MON_DATA_FORM, NULL);
        }
    }

    PCStorage *pcStorage = SaveArray_PCStorage_Get(saveData);
    for (i = 0; i < (u32)NUM_BOXES; i++) {
        for (j = 0; j < MONS_PER_BOX; j++) {
            BoxPokemon *boxMon = PCStorage_GetMonByIndexPair(pcStorage, i, j);
            if (GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL) == SPECIES_ROTOM && !GetBoxMonData(boxMon, MON_DATA_IS_EGG, NULL)) {
                ret |= 1 << GetBoxMonData(boxMon, MON_DATA_FORM, NULL);
            }
        }
    }

    Pokemon *walkerMon = AllocMonZeroed(HEAP_ID_FIELD3);
    BoxPokemon *walkerBoxMon = Mon_GetBoxMon(walkerMon);
    POKEWALKER *pokeWalker = Save_Pokewalker_Get(saveData);
    if (Pokewalker_TryGetBoxMon(pokeWalker, walkerBoxMon)) {
        if (GetBoxMonData(walkerBoxMon, MON_DATA_SPECIES, NULL) == SPECIES_ROTOM && !GetBoxMonData(walkerBoxMon, MON_DATA_IS_EGG, NULL)) {
            ret |= 1 << GetBoxMonData(walkerBoxMon, MON_DATA_FORM, NULL);
        }
    }
    Heap_Free(walkerMon);

    return ret;
}

BOOL ScrCmd_AddSpecialGameStat2(ScriptContext *ctx) {
    u16 statno = ScriptReadHalfword(ctx);
    GameStats_AddScore(Save_GameStats_Get(ctx->fieldSystem->saveData), statno);
    return FALSE;
}

BOOL ScrCmd_CheckFieldHeapFreeSize(ScriptContext *ctx) {
    static u32 sHeap4Size;
    static u32 sHeap32Size;
    static u32 sHeap11Size;
    u16 action = ScriptGetVar(ctx);
    u32 heap11Size = HeapExp_FndGetTotalFreeSize(HEAP_ID_FIELD2);
    u32 heap4Size = HeapExp_FndGetTotalFreeSize(HEAP_ID_FIELD1);
    u32 heap32Size = HeapExp_FndGetTotalFreeSize(HEAP_ID_FIELD3);

    if (action == 0) {
        sHeap11Size = heap11Size;
        sHeap4Size = heap4Size;
        sHeap32Size = heap32Size;
    } else {
        GF_ASSERT(heap11Size == sHeap11Size);
        // GF_ASSERT(heap4Size == sHeap4Size);
        GF_ASSERT(heap32Size == sHeap32Size);
    }
    return FALSE;
}

BOOL ScrCmd_CheckPlazaLoginTimeElapsed(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (GF_RTC_DateTimeToSec() - fieldSystem->plazaLoginTime >= 120) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_UpdatePartyGiratinaFormsAndCaughtFlags(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 forceOrigin = ScriptGetVar(ctx);
    Party *party = SaveArray_Party_Get(ctx->fieldSystem->saveData);
    int i, partyCount;
    Pokemon *mon;

    Party_UpdateAllGiratina_DistortionWorld(party, forceOrigin);
    partyCount = Party_GetCount(party);
    for (i = 0; i < partyCount; i++) {
        mon = Party_GetMonByIndex(party, i);
        if (!GetMonData(mon, MON_DATA_IS_EGG, NULL)) {
            Pokedex_SetMonCaughtFlag(Save_Pokedex_Get(fieldSystem->saveData), mon);
        }
    }
    return FALSE;
}

BOOL ScrCmd_FollowerPokeIsEventTrigger(ScriptContext *ctx) {
    u8 event = ScriptReadByte(ctx);
    u16 partySlot = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    Pokemon *mon;
    int species;

    *p_ret = 0;
    mon = Party_GetMonByIndex(SaveArray_Party_Get(ctx->fieldSystem->saveData), partySlot);

    if (event >= NUM_EVENTS) {
        return FALSE;
    }
    if (GetMonData(mon, MON_DATA_IS_EGG, NULL) || GetMonData(mon, MON_DATA_CHECKSUM_FAILED, NULL)) {
        return FALSE;
    }
    if (!MonMetadataMatchesEvent(event, mon, GetMonData(mon, MON_DATA_OT_ID, NULL) == PlayerProfile_GetTrainerID(Save_PlayerData_GetProfile(ctx->fieldSystem->saveData)))) {
        return FALSE;
    }

    species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    switch (event) {
    case EVENT_SPIKY_EARED_PICHU:
        if ((species == SPECIES_PICHU || species == SPECIES_PIKACHU || species == SPECIES_RAICHU) && MonIsShiny(mon)) {
            *p_ret = 1;
        }
        break;
    case EVENT_ARCEUS_HALL_OF_ORIGIN:
    case EVENT_ARCEUS_MOVIE_GIFT:
        if (species == SPECIES_ARCEUS) {
            *p_ret = 1;
        }
        break;
    case EVENT_CELEBI:
        if (species == SPECIES_CELEBI) {
            *p_ret = 1;
        }
        break;
    }

    return FALSE;
}

BOOL ScrCmd_FollowMonIsLarge(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FollowMonObject_IsLarge(MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, obj_partner_poke));
    return FALSE;
}

BOOL ScrCmd_FollowMonShowEmoteBubble(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    FieldSystem_ShowEmoteBubble(fieldSystem, MapObjectManager_GetFirstActiveObjectByID(fieldSystem->mapObjectManager, obj_partner_poke), 0);
    return TRUE;
}

BOOL ScrCmd_SwapPlayerAndFollowMonPositions(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 mode = ScriptReadHalfword(ctx);
    LocalMapObject *obj1, *obj2;
    if (mode == 1) {
        obj1 = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
        obj2 = FollowMon_GetMapObject(fieldSystem);
    } else if (mode == 2) {
        obj1 = FollowMon_GetMapObject(fieldSystem);
        obj2 = PlayerAvatar_GetMapObject(fieldSystem->playerAvatar);
    } else {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    MapObjects_SwapPositions(obj1, obj2, ctx->taskman);
    return TRUE;
}

BOOL ScrCmd_FollowMonHopIntoBall(ScriptContext *ctx) {
    FollowMon_StartHopIntoBall(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_FollowMonRecall(ScriptContext *ctx) {
    if (FollowMon_StartRecall(ctx->fieldSystem)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_FollowMonFacePlayer(ScriptContext *ctx) {
    BOOL doFace = TRUE;
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        if (FollowMonObject_IsLarge(FollowMon_GetMapObject(ctx->fieldSystem))) {
            LocalMapObject *myObject = PlayerAvatar_GetMapObject(FieldSystem_GetPlayerAvatar(ctx->fieldSystem));
            int facingDirection = PlayerAvatar_GetFacingDirection(FieldSystem_GetPlayerAvatar(ctx->fieldSystem));
            int playerX = MapObject_GetXCoord(myObject);
            int deltaX = GetDeltaXByFacingDirection(facingDirection) * 2;
            s32 playerY = MapObject_GetYCoord(myObject);
            int playerZ = MapObject_GetZCoord(myObject);
            int deltaY = GetDeltaYByFacingDirection(facingDirection) * 2;
            u8 facingTile = GetMetatileBehavior(ctx->fieldSystem, playerX + deltaX, playerZ + deltaY);
            VecFx32 posVec;
            MapObject_CopyPositionVector(myObject, &posVec);
            if (FieldSystem_CheckCollisionAndHeight(ctx->fieldSystem, &posVec, playerX + deltaX, playerZ + deltaY, 0) || MetatileBehavior_IsSurfableWater(facingTile) || MapObject_IsTileOccupiedInLink(myObject, playerX + deltaX, playerY, playerZ + deltaY)) {
                doFace = FALSE;
            }
        }
        if (doFace) {
            return ScrCmd_FacePlayer(ctx);
        }
    }
    return FALSE;
}

BOOL ScrCmd_ToggleFollowingPokemonMovement(ScriptContext *ctx) {
    u16 mode = ScriptReadHalfword(ctx);
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        if (mode) {
            MapObject_PauseMovement(FollowMon_GetMapObject(ctx->fieldSystem));
        } else {
            MapObject_UnpauseMovement(FollowMon_GetMapObject(ctx->fieldSystem));
        }
    }
    return FALSE;
}

static BOOL NativeScript_WaitFollowingPokemonMovement(ScriptContext *ctx);

BOOL ScrCmd_WaitFollowingPokemonMovement(ScriptContext *ctx) {
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        SetupNativeScript(ctx, NativeScript_WaitFollowingPokemonMovement);
    }
    return TRUE;
}

BOOL ScrCmd_FollowingPokemonMovement(ScriptContext *ctx) {
    u16 movement = ScriptReadHalfword(ctx);
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        MapObject_ChangeMovement(MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, obj_partner_poke), movement);
    }
    return TRUE;
}

static BOOL NativeScript_WaitFollowingPokemonMovement(ScriptContext *ctx) {
    if (MapObject_IsMovementPaused(FollowMon_GetMapObject(ctx->fieldSystem))) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_FollowMonSetPositionNextToPlayer(ScriptContext *ctx) {
    u8 direction = ScriptReadByte(ctx);
    u8 facing = ScriptReadByte(ctx);
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        LocalMapObject *playerObj = PlayerAvatar_GetMapObject(ctx->fieldSystem->playerAvatar);
        LocalMapObject *tsurePokeObj = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, obj_partner_poke);
        MapObject_SetPositionNextTo(playerObj, tsurePokeObj, direction, facing);
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonReleaseNextToPlayer(ScriptContext *ctx) {
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        LocalMapObject *object = FollowMon_GetMapObject(ctx->fieldSystem);
        if (FollowMon_GetPermissionBySpeciesAndMap(FollowMon_GetSpecies(object), ctx->fieldSystem->location->mapId)) {
            FollowMon_SetReleaseBallPending(object, 1);
            FollowMon_SetHideUntilStepBit(object, TRUE);
            FollowMon_MoveToPlayer(ctx->fieldSystem, 1);
        }
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonMoveToPlayer(ScriptContext *ctx) {
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        LocalMapObject *object = FollowMon_GetMapObject(ctx->fieldSystem);
        if (FollowMon_GetPermissionBySpeciesAndMap(FollowMon_GetSpecies(object), ctx->fieldSystem->location->mapId)) {
            FollowMon_MoveToPlayer(ctx->fieldSystem, 1);
        }
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonSpawnReleaseBall(ScriptContext *ctx) {
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, obj_partner_poke);
        FollowMon_SpawnReleaseBall(object);
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonResetMovement(ScriptContext *ctx) {
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, obj_partner_poke);
        FollowPlayerMovement_Reset(object);
    }
    return TRUE;
}

BOOL ScrCmd_StartCameraShift(ScriptContext *ctx) {
    u16 mode = ScriptReadHalfword(ctx);
    FieldCameraShift_Start(ctx->fieldSystem->cameraShift, mode);
    return TRUE;
}

BOOL ScrCmd_Pokeathlon(ScriptContext *ctx) {
    u8 mode = ScriptReadByte(ctx);
    u8 isSupreme = ScriptReadByte(ctx);
    u16 course = ScriptGetVar(ctx);
    u16 *p_shouldFreeHeap = ScriptGetVarPointer(ctx);
    u16 *p_totalPoints = ScriptGetVarPointer(ctx);
    u16 *p_points = ScriptGetVarPointer(ctx);
    u16 *p_rank = ScriptGetVarPointer(ctx);
    CallTask_PokeathlonCourse(ctx->fieldSystem, mode, isSupreme, course, p_shouldFreeHeap, p_totalPoints, p_points, p_rank);
    return TRUE;
}

BOOL ScrCmd_GetFriendSprite(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (PlayerProfile_GetTrainerGender(Save_PlayerData_GetProfile(FieldSystem_GetSaveData(ctx->fieldSystem))) != PLAYER_GENDER_MALE) {
        *p_ret = SPRITE_HERO;
    } else {
        *p_ret = SPRITE_HEROINE;
    }
    return TRUE;
}

BOOL ScrCmd_RegisterPokegearCard(ScriptContext *ctx) {
    SavePokegear *pokegear = SaveData_Pokegear_Get(FieldSystem_GetSaveData(ctx->fieldSystem));
    u8 card = ScriptReadByte(ctx);
    switch (card) {
    case 1:
        SavePokegear_RegisterCard(pokegear, 1);
        break;
    case 2:
        SavePokegear_RegisterCard(pokegear, 2);
        break;
    case 0:
    default:
        SavePokegear_RegisterCard(pokegear, 0);
        break;
    }
    return FALSE;
}

BOOL ScrCmd_SetPokegearMapUnlockLevel(ScriptContext *ctx) {
    Pokegear_SetMapUnlockLevel(SaveData_Pokegear_Get(ctx->fieldSystem->saveData), ScriptReadByte(ctx));
    return FALSE;
}

BOOL ScrCmd_RegisterGearNumber(ScriptContext *ctx) {
    SavePokegear *pokegear = SaveData_Pokegear_Get(FieldSystem_GetSaveData(ctx->fieldSystem));
    u8 number = ScriptGetVar(ctx);
    if (number < NUM_PHONE_CONTACTS) {
        SavePokegear_RegisterPhoneNumber(pokegear, number);
    }
    return FALSE;
}

BOOL ScrCmd_CheckRegisteredPhoneNumber(ScriptContext *ctx) {
    SavePokegear *pokegear = SaveData_Pokegear_Get(FieldSystem_GetSaveData(ctx->fieldSystem));
    u8 number = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (number < NUM_PHONE_CONTACTS) {
        *p_ret = SavePokegear_IsNumberRegistered(pokegear, number);
        if (*p_ret == 0xFF) {
            *p_ret = FALSE;
        } else {
            *p_ret = TRUE;
        }
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_SetPhoneCall(ScriptContext *ctx) {
    u16 callerId = ScriptGetVar(ctx);
    u16 isScriptedCall = ScriptGetVar(ctx);
    u16 callScriptID = ScriptGetVar(ctx);
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA); // PhoneCallAppData
    GearPhoneRingManager_StartRinging(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem));
    ctx->fieldSystem->suppressBottomScreenDim = TRUE;
    GearPhoneRingManager_SetCallerParams(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem), callerId, 0xFF, 0, isScriptedCall, callScriptID);
    return TRUE;
}

BOOL ScrCmd_RunPhoneCall(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    *p_work = PokegearPhone_LaunchApp(ctx->fieldSystem);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_LoadPhoneDat(ScriptContext *ctx) {
    u16 idx = ScriptGetVar(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = LoadPhoneBookEntryI(idx, GearPhoneRingManager_GetCallerPhoneBookEntry(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem)), HEAP_ID_FIELD3);
    return FALSE;
}

BOOL ScrCmd_GetPhoneContactMsgIds(ScriptContext *ctx) {
    u16 *p_scriptno = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_ACTIVE_SCRIPT_NUMBER);
    u8 msgIndex = ScriptReadByte(ctx);
    u16 *pPhoneMsgGmm = ScriptGetVarPointer(ctx);
    u16 *p_ret_msg = ScriptGetVarPointer(ctx);
    PhoneBookEntry *entry = GearPhoneRingManager_GetCallerPhoneBookEntry(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem));
    *pPhoneMsgGmm = GetPhoneMessageGmm(entry->id);
    u16 msgId, p_ret_gmm;

    if (entry->id == 0xFF) {
        *p_ret_msg = 0;
        return TRUE;
    }
    if (msgIndex > 4) {
        msgIndex = 0;
    }
    p_ret_gmm = ScriptNumToTrainerNum(*p_scriptno);
    msgId = msgIndex + 1;
    if (p_ret_gmm >= LAST_TRAINER_INDEX) {
        *p_ret_msg = msgId;
    } else if ((u16)TrainerNumIsDouble(ScriptNumToTrainerNum(*p_scriptno)) == FALSE) {
        *p_ret_msg = msgId;
    } else {
        ScriptNoToDoublePartnerNo(*p_scriptno);
        *p_ret_msg = msgId;
    }
    return FALSE;
}

BOOL ScrCmd_ClearPhoneRematchSeeking(ScriptContext *ctx) {
    u16 idx = ScriptGetVar(ctx);
    PhoneCallPersistentState_PhoneRematches_SetSeeking(SaveData_GetPhoneCallPersistentState(ctx->fieldSystem->saveData), idx, FALSE);
    return FALSE;
}

BOOL ScrCmd_GetPhoneContactRandomGiftBerry(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    PhoneBookEntry *entry = GearPhoneRingManager_GetCallerPhoneBookEntry(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem));
    if (entry->gift == ITEM_CHERI_BERRY) {
        *p_ret = ITEM_CHERI_BERRY + (LCRandom() % 10);
    } else {
        *p_ret = entry->gift;
    }
    return FALSE;
}

BOOL ScrCmd_GetPhoneContactGiftItem(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    PhoneBookEntry *entry = GearPhoneRingManager_GetCallerPhoneBookEntry(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem));
    PhoneCallPersistentState *callPersistentState = SaveData_GetPhoneCallPersistentState(ctx->fieldSystem->saveData);
    *p_ret = PhoneCallPersistentState_PhoneRematches_GiftItemIdGet(callPersistentState, entry->id);
    PhoneCallPersistentState_PhoneRematches_GiftItemIdSet(callPersistentState, entry->id, ITEM_NONE);
    return FALSE;
}

BOOL ScrCmd_SetPhoneCallTrigger(ScriptContext *ctx) {
    u8 callTrigger = ScriptReadByte(ctx);
    GearPhoneRingManager_SetCallTrigger(FieldSystem_GetGearPhoneRingManager(ctx->fieldSystem), callTrigger, ScriptReadByte(ctx));
    return FALSE;
}

BOOL UnsetPhoneCallTrigger(ScriptContext *ctx) {
    PhoneCallPersistentState_ClearCallTriggerFlag(SaveData_GetPhoneCallPersistentState(ctx->fieldSystem->saveData), ScriptReadByte(ctx));
    return FALSE;
}

BOOL ScrCmd_CameronPhoto(ScriptContext *ctx) {
    u16 photo_num = ScriptReadHalfword(ctx);
    FieldSystem_TakePhoto(ctx->fieldSystem, photo_num);
    return TRUE;
}

BOOL ScrCmd_CountSavedPhotos(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = PhotoAlbum_GetNumSaved(Save_PhotoAlbum_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_OpenPhotoAlbum(ScriptContext *ctx) {
    FieldSystem_ViewSavedPhotos(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_PlaceStarterBallsInElmsLab(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    const VecFx32 ballCoords[3] = {
        { FX32_CONST(131), 0, FX32_CONST(65) },
        { FX32_CONST(141), 0, FX32_CONST(65) },
        { FX32_CONST(136), 0, FX32_CONST(72) },
    };
    int n, i;

    int partyCount = Party_GetCount(SaveArray_Party_Get(fieldSystem->saveData));
    if (FieldSystem_FlagCheck(fieldSystem, FLAG_GOT_TM51_FROM_FALKNER)) {
        n = 0;
    } else if (FieldSystem_FlagCheck(fieldSystem, FLAG_MET_PASSERBY_BOY)) {
        n = 1;
    } else if (partyCount > 0) {
        n = 2;
    } else {
        n = 3;
    }
    for (i = 0; i < n; i++) {
        MapPropManager_LoadOne(fieldSystem->mapPropManager, 0x8D, &ballCoords[i], 0, fieldSystem->mapPropAnimationManager);
    }
    return FALSE;
}

BOOL ScrCmd_GetObjectFacing(ScriptContext *ctx) {
    u16 objectId = ScriptReadHalfword(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    LocalMapObject *object = MapObjectManager_GetFirstActiveObjectByID(ctx->fieldSystem->mapObjectManager, objectId);
    if (object != NULL) {
        *p_ret = MapObject_GetFacingDirection(object);
    } else {
        *p_ret = DIR_NORTH;
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonInteract(ScriptContext *ctx) {
    FieldSystem_FollowMonInteract(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_LaunchPokeathlonRecordsApp(ScriptContext *ctx) {
    void **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u8 action = ScriptReadByte(ctx);
    switch (action) {
    case 1:
        *p_work = PokeathlonMedals_LaunchApp(ctx->fieldSystem);
        break;
    case 2:
        *p_work = PokeathlonEventRecord_LaunchApp(ctx->fieldSystem);
        break;
    case 3:
        *p_work = PokeathlonTrophies_LaunchApp(ctx->fieldSystem);
        break;
    default:
    case 0:
        *p_work = PokeathlonCourseRecord_LaunchApp(ctx->fieldSystem);
        break;
    }
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_AlphPuzzle(ScriptContext *ctx) { // this just loads a different puzzle with another ID
    AlphPuzzleArgs **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_RUNNING_APP_DATA);
    u8 puzzle = ScriptReadByte(ctx);
    if (puzzle > 4) {
        puzzle = 0;
    }
    *p_work = AlphPuzzle_LaunchApp(ctx->fieldSystem, puzzle);
    SetupNativeScript(ctx, ScrNative_WaitApplication_DestroyTaskData);
    return TRUE;
}

BOOL ScrCmd_MagnetTrainRide(ScriptContext *ctx) {
    u8 r7 = ScriptReadByte(ctx);
    u8 r6 = ScriptReadByte(ctx);
    u16 mapId = ScriptReadHalfword(ctx);
    u16 x = ScriptReadHalfword(ctx);
    u16 y = ScriptReadHalfword(ctx);
    CallTask_MagnetTrainRide(ctx->fieldSystem, r7, r6, mapId, x, y);
    return TRUE;
}

BOOL ScrCmd_ShipVoyage(ScriptContext *ctx) {
    u8 r7 = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);
    u16 mapId = ScriptReadHalfword(ctx);
    u16 x = ScriptReadHalfword(ctx);
    u16 y = ScriptReadHalfword(ctx);
    CallTask_ShipVoyage(ctx->fieldSystem, r7, direction, mapId, x, y);
    return TRUE;
}

BOOL ScrCmd_Cinematic(ScriptContext *ctx) {
    u16 scene = ScriptReadHalfword(ctx);
    CallTask_LegendaryCinematic(ctx->fieldSystem, scene);
    return TRUE;
}

BOOL ScrCmd_GetFollowPokePartyIndex(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = GetIdxOfFirstAliveMonInParty_CrashIfNone(SaveArray_Party_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_FollowMonFlash(ScriptContext *ctx) {
    u8 step = ScriptReadByte(ctx);
    u8 period = ScriptReadByte(ctx);
    if (FollowMon_StartFlash(ctx->fieldSystem, step, period)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_FollowMonIsActive(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (FollowMon_IsActive(ctx->fieldSystem)) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonIsInactiveOrVisible(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (!FollowMon_IsActive(ctx->fieldSystem)) {
        *p_ret = TRUE;
    } else if (FollowMon_CheckVisibleFlag(ctx->fieldSystem)) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonGrowAndShrink(ScriptContext *ctx) {
    FollowMon_StartGrowAndShrink(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_FollowMonAddMood(ScriptContext *ctx) {
    s8 mood = ScriptReadByte(ctx);
    FollowMonMood_Add(ctx->fieldSystem->followMonMood, mood);
    return FALSE;
}

BOOL ScrCmd_FirstAliveMonHasType(ScriptContext *ctx) {
    u8 type = ScriptReadByte(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (FieldSystem_FirstAliveMonHasType(ctx->fieldSystem, type)) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonJumpOnSpot(ScriptContext *ctx) {
    u8 count = ScriptReadByte(ctx);
    FollowMon_JumpOnSpot(ctx->fieldSystem, count);
    return TRUE;
}

BOOL NativeScript_WaitTouchscreenMenuHidden(ScriptContext *ctx);

BOOL ScrCmd_TouchscreenMenuHide(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    if (FieldSystem_GetBottomScreenAppId(fieldSystem) == BOTTOM_SCREEN_APP_CHOICE_MENU) {
        return FALSE;
    }
    FieldSystem_SwitchBottomScreenApp(fieldSystem, BOTTOM_SCREEN_APP_CHOICE_MENU, 0);
    SetupNativeScript(ctx, NativeScript_WaitTouchscreenMenuHidden);
    fieldSystem->savedBottomScreenAppId = BOTTOM_SCREEN_APP_CHOICE_MENU;
    return TRUE;
}

BOOL NativeScript_WaitTouchscreenMenuHidden(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = GetVarPointer(fieldSystem, ctx->data[0]);
    int appId = FieldSystem_GetBottomScreenAppId(fieldSystem);
    int appState = FieldSystem_GetBottomScreenAppState(fieldSystem);
    if (appId == BOTTOM_SCREEN_APP_CHOICE_MENU && appState == BOTTOM_SCREEN_APP_STATE_RUNNING) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL NativeScript_WaitTouchscreenMenuShown(ScriptContext *ctx);

BOOL ScrCmd_TouchscreenMenuShow(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    FieldSystem_SwitchBottomScreenApp(fieldSystem, BOTTOM_SCREEN_APP_TOUCHSCREEN_MENU, 0);
    SetupNativeScript(ctx, NativeScript_WaitTouchscreenMenuShown);
    fieldSystem->savedBottomScreenAppId = BOTTOM_SCREEN_APP_TOUCHSCREEN_MENU;
    return TRUE;
}

BOOL NativeScript_WaitTouchscreenMenuShown(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = GetVarPointer(fieldSystem, ctx->data[0]);
    int appId = FieldSystem_GetBottomScreenAppId(fieldSystem);
    int appState = FieldSystem_GetBottomScreenAppState(fieldSystem);
    if (appId == BOTTOM_SCREEN_APP_TOUCHSCREEN_MENU && appState == BOTTOM_SCREEN_APP_STATE_RUNNING) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_SetSavedBottomScreenApp(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 appId = ScriptReadHalfword(ctx);
    FieldSystem_SetSavedBottomScreenAppId(fieldSystem, appId);
    return FALSE;
}

BOOL NativeScript_WaitTouchscreenMenuChoice(ScriptContext *ctx);

BOOL ScrCmd_GetMenuChoice(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 var_ret = ScriptReadHalfword(ctx);
    ctx->data[0] = var_ret;
    FieldSystem_SetTouchscreenChoiceMenuState(fieldSystem, BOTTOM_SCREEN_APP_CHOICE_MENU, TOUCHSCREEN_CHOICE_MENU_STATE_SHOW_YES_NO, &ctx->data[1]);
    SetupNativeScript(ctx, NativeScript_WaitTouchscreenMenuChoice);
    return TRUE;
}

BOOL NativeScript_WaitTouchscreenMenuChoice(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    u16 *p_ret = GetVarPointer(fieldSystem, ctx->data[0]);
    int appId = FieldSystem_GetBottomScreenAppId(fieldSystem);
    int menuState = FieldSystem_GetTouchscreenChoiceMenuState(fieldSystem);
    if (appId == BOTTOM_SCREEN_APP_CHOICE_MENU && menuState == TOUCHSCREEN_CHOICE_MENU_STATE_DONE) {
        *p_ret = ctx->data[1];
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_MenuInitStdGmm(ScriptContext *ctx) {
    Script_CreateMenuFromArgs(ctx, FieldSystem_GetTouchscreenChoiceMenuList(ctx->fieldSystem), NULL);
    return TRUE;
}

BOOL ScrCmd_MenuInit(ScriptContext *ctx) {
    Script_CreateMenuFromArgs(ctx, FieldSystem_GetTouchscreenChoiceMenuList(ctx->fieldSystem), ctx->msgdata);
    return TRUE;
}

BOOL ScrCmd_MenuItemAdd(ScriptContext *ctx) {
    struct ScriptMenu **p_menu = FieldSystem_GetTouchscreenChoiceMenuList(ctx->fieldSystem);
    u16 msgId = ScriptGetVar(ctx);
    u16 where = ScriptGetVar(ctx);
    u16 value = ScriptGetVar(ctx);
    ScriptMenu_AddListItem(*p_menu, msgId, where, value);
    return FALSE;
}

BOOL NativeScript_WaitMenuExec(ScriptContext *ctx);
BOOL MenuExec_PrintItemHelp(struct ScriptMenu *menu, int idx);

BOOL ScrCmd_MenuExec(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    struct ScriptMenu **p_menu = FieldSystem_GetTouchscreenChoiceMenuList(fieldSystem);
    u16 *p_ret = GetVarPointer(fieldSystem, ctx->data[0]);
    FieldSystem_SetTouchscreenChoiceMenuState(fieldSystem, BOTTOM_SCREEN_APP_CHOICE_MENU, TOUCHSCREEN_CHOICE_MENU_STATE_SHOW_LIST, p_ret);
    FieldSystem_SetTouchscreenChoiceMenuCallback(fieldSystem, MenuExec_PrintItemHelp, *p_menu);
    SetupNativeScript(ctx, NativeScript_WaitMenuExec);
    return TRUE;
}

BOOL NativeScript_WaitMenuExec(ScriptContext *ctx) {
    FieldSystem *fieldSystem = ctx->fieldSystem;
    struct ScriptMenu **p_menu = FieldSystem_GetTouchscreenChoiceMenuList(fieldSystem);
    u16 *p_ret = GetVarPointer(fieldSystem, ctx->data[0]);
    if (*p_ret == 0xEEEE) {
        return FALSE;
    } else {
        ScriptMenu_Free(*p_menu);
        return TRUE;
    }
}

BOOL MenuExec_PrintItemHelp(struct ScriptMenu *menu, int idx) {
    ScriptMenu_PrintItemHelpMessage(menu, idx);
    return FALSE;
}

static u32 GetMaxBankTransactionAmount(FieldSystem *fieldSystem, int action) {
    u32 ret;
    u32 wallet = PlayerProfile_GetMoney(Save_PlayerData_GetProfile(fieldSystem->saveData));
    u32 bank = PhoneCallPersistentState_MomSavings_BalanceAction(SaveData_GetPhoneCallPersistentState(fieldSystem->saveData), MOMS_BALANCE_GET, 0);
    switch (action) {
    case 0:
        ret = MAX_MONEY - bank;
        if (wallet <= ret) {
            ret = wallet;
        }
        break;
    case 1:
        ret = MAX_MONEY - wallet;
        if (bank <= ret) {
            ret = bank;
        }
        break;
    default:
        GF_ASSERT(FALSE);
    }
    return ret;
}

BOOL NativeScript_WaitBankTransaction(ScriptContext *ctx);

BOOL ScrCmd_BankTransaction(ScriptContext *ctx) {
    struct BankTransactionWork **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 mode = ScriptReadHalfword(ctx);
    u16 var_ret = ScriptReadHalfword(ctx);
    struct BankTransactionWork *work = *p_work = Heap_Alloc(HEAP_ID_FIELD1, sizeof(struct BankTransactionWork)); // statement must be this way to match
    work->sub = Heap_Alloc(HEAP_ID_FIELD1, sizeof(struct BankTransactionWorkSub));
    work->mode = mode;
    work->sub->max = GetMaxBankTransactionAmount(ctx->fieldSystem, mode);
    work->sub->selected = -1;
    FieldSystem_SwitchBottomScreenApp(ctx->fieldSystem, BOTTOM_SCREEN_APP_NUMBER_ENTRY, work->sub);
    ctx->data[0] = var_ret;
    SetupNativeScript(ctx, NativeScript_WaitBankTransaction);
    return TRUE;
}

BOOL NativeScript_WaitBankTransaction(ScriptContext *ctx) {
    struct BankTransactionWork **p_work = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MISC_DATA_PTR);
    u16 *p_ret = GetVarPointer(ctx->fieldSystem, ctx->data[0]);
    struct BankTransactionWork *work = *p_work;
    if (work->sub->selected == -1) {
        return FALSE;
    } else if (work->sub->selected == 0) {
        *p_ret = 1;
    } else {
        SaveData *saveData = ctx->fieldSystem->saveData;
        switch (work->mode) {
        case 0:
            PlayerProfile_SubMoney(Save_PlayerData_GetProfile(saveData), work->sub->selected);
            PhoneCallPersistentState_MomSavings_BalanceAction(SaveData_GetPhoneCallPersistentState(saveData), MOMS_BALANCE_ADD, work->sub->selected);
            break;
        case 1:
            PlayerProfile_AddMoney(Save_PlayerData_GetProfile(saveData), work->sub->selected);
            PhoneCallPersistentState_MomSavings_BalanceAction(SaveData_GetPhoneCallPersistentState(saveData), MOMS_BALANCE_SUB, work->sub->selected);
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
        *p_ret = 0;
    }
    Heap_Free(work->sub);
    Heap_Free(*p_work);
    return TRUE;
}

BOOL ScrCmd_BankOrWalletIsFull(ScriptContext *ctx) {
    u16 action = ScriptReadHalfword(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (action == 0) {
        if (PhoneCallPersistentState_MomSavings_BalanceAction(SaveData_GetPhoneCallPersistentState(ctx->fieldSystem->saveData), MOMS_BALANCE_GET, 0) == MAX_MONEY) {
            *p_ret = TRUE;
        } else {
            *p_ret = FALSE;
        }
    } else {
        if (PlayerProfile_GetMoney(Save_PlayerData_GetProfile(ctx->fieldSystem->saveData)) == MAX_MONEY) {
            *p_ret = TRUE;
        } else {
            *p_ret = FALSE;
        }
    }
    return TRUE;
}

BOOL ScrCmd_RockSmashItemCheck(ScriptContext *ctx) {
    u16 followMonUsingHM = ScriptGetVar(ctx);
    u16 *itemFound = ScriptGetVarPointer(ctx);
    u16 *item = ScriptGetVarPointer(ctx);
    FieldSystem_RockSmashItemCheck(ctx->fieldSystem, (u8)followMonUsingHM, itemFound, item);
    return TRUE;
}

BOOL ScrCmd_TryHeadbuttEncounter(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    FieldSystem_TryHeadbuttEncounter(ctx->fieldSystem, p_ret);
    return TRUE;
}

BOOL ScrCmd_LegendCutsceneClearBellAnimBegin(ScriptContext *ctx) {
    LegendCutscene_BeginClearBellAnim(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneClearBellAnimEnd(ScriptContext *ctx) {
    LegendCutscene_EndClearBellAnim(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneClearBellRiseFromBag(ScriptContext *ctx) {
    LegendCutscene_ClearBellRiseFromBag(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneClearBellShimmer(ScriptContext *ctx) {
    u8 clearBellOnly = ScriptReadHalfword(ctx);
    LegendCutscene_ClearBellShimmer(ctx->fieldSystem, clearBellOnly);
    return TRUE;
}

BOOL ScrCmd_LegendCutsceneLugiaEyeGlimmerEffect(ScriptContext *ctx) {
    LegendCutscene_LugiaEyeGlimmerEffect(ctx->fieldSystem);
    return TRUE;
}

// Unreferenced
BOOL ScrCmd_UnusedHoOhAnim(ScriptContext *ctx) {
    LegendCutscene_StartUnusedHoOhAnim(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_LegendCutsceneMoveCameraTo(ScriptContext *ctx) {
    u8 destIndex = ScriptReadHalfword(ctx);
    LegendCutscene_MoveCamera(ctx->fieldSystem, destIndex);
    return FALSE;
}

BOOL ScrCmd_LegendCutscenePanCameraTo(ScriptContext *ctx) {
    u8 destIndex = ScriptReadHalfword(ctx);
    LegendCutscene_StartPanCameraTo(ctx->fieldSystem, destIndex);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneWaitCameraPan(ScriptContext *ctx) {
    LegendCutscene_WaitCameraPan(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_LegendCutsceneBirdFinalApproach(ScriptContext *ctx) {
    LegendCutscene_BirdFinalApproach(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_LegendCutsceneWavesOrLeavesEffectBegin(ScriptContext *ctx) {
    LegendCutscene_BeginWavesOrLeavesEffect(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneWavesOrLeavesEffectEnd(ScriptContext *ctx) {
    LegendCutscene_EndWavesOrLeavesEffect(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneLugiaArrivesEffectBegin(ScriptContext *ctx) {
    LegendCutscene_BeginLugiaArrivesEffect(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneLugiaArrivesEffectEnd(ScriptContext *ctx) {
    LegendCutscene_EndLugiaArrivesEffect(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_LegendCutsceneLugiaArrivesEffectCameraPan(ScriptContext *ctx) {
    LegendCutscene_LugiaArrivesEffectCameraPan(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_SetFollowMonInhibitState(ScriptContext *ctx) {
    Save_FollowMon_SetInhibitFlagState(Save_FollowMon_Get(ctx->fieldSystem->saveData), ScriptReadByte(ctx));
    return FALSE;
}

// Loads an overlay containing additional script commands or data
BOOL ScrCmd_ScriptOverlayCmd(ScriptContext *ctx) {
    u8 ovy = ScriptReadByte(ctx);
    u8 action = ScriptReadByte(ctx);

    static const FSOverlayID _020FACB0[] = {
        FS_OVERLAY_ID(OVY_20),
        FS_OVERLAY_ID(bug_contest),
        FS_OVERLAY_ID(OVY_21),
        FS_OVERLAY_ID(OVY_22),
        FS_OVERLAY_ID(OVY_25),
    };

    if (ovy >= NELEMS(_020FACB0)) {
        return FALSE;
    }

    if (action == 0) {
        HandleLoadOverlay(_020FACB0[ovy], OVY_LOAD_ASYNC);
    } else {
        UnloadOverlayByID(_020FACB0[ovy]);
    }

    return FALSE;
}

BOOL ScrCmd_CheckBankBalance(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    u32 check_amt = ScriptReadWord(ctx);
    if (PhoneCallPersistentState_MomSavings_BalanceAction(SaveData_GetPhoneCallPersistentState(ctx->fieldSystem->saveData), MOMS_BALANCE_GET, 0) >= check_amt) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_BufferRulesetName(ScriptContext *ctx) {
    u16 ruleset = ScriptReadHalfword(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    BattleRegulation_BufferName(ctx->fieldSystem, *p_msgFmt, ruleset);
    return FALSE;
}

BOOL ScrCmd_BufferBattleRegulationName(ScriptContext *ctx) {
    u16 *p_var = ScriptGetVarPointer(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    BattleRegulation_BufferName(ctx->fieldSystem, *p_msgFmt, *p_var);
    return FALSE;
}

BOOL ScrCmd_SetActiveBattleRegulation(ScriptContext *ctx) {
    u16 *p_var = ScriptGetVarPointer(ctx);
    BattleRegulation_SetActiveRuleset(ctx->fieldSystem, *p_var);
    return FALSE;
}

BOOL ScrCmd_ShowBattleRegulationWindow(ScriptContext *ctx) {
    Window **p_moneyBox = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MONEY_BOX);
    u16 *p_var = ScriptGetVarPointer(ctx);
    *p_moneyBox = BattleRegulationWindow_New(ctx->fieldSystem, *p_var);
    return FALSE;
}

BOOL ScrCmd_HideBattleRegulationWindow(ScriptContext *ctx) {
    Window **p_moneyBox = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MONEY_BOX);
    BattleRegulationWindow_Delete(*p_moneyBox);
    return FALSE;
}

BOOL ScrCmd_CheckPartyBattleRegulation(ScriptContext *ctx) {
    u16 *p_ruleset = ScriptGetVarPointer(ctx);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    *p_ret = BattleRegulation_CheckParty(ctx->fieldSystem, *p_msgFmt, *p_ruleset);
    return FALSE;
}

BOOL ScrCmd_LoadEventSoundEffects(ScriptContext *ctx) {
    Sound_LoadSceneSoundEffects(75);
    return FALSE;
}

BOOL ScrCmd_ShayminRevertToLandForm(ScriptContext *ctx) {
    StartShayminRevertToLandForm(ctx->fieldSystem->taskman);
    return TRUE;
}

BOOL ScrCmd_CelebiTimeTravel(ScriptContext *ctx) {
    FieldSystem_BeginCelebiTimeTravelCutsceneTask(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_SetFlag99A(ScriptContext *ctx) {
    SetFlag99A(Save_VarsFlags_Get(ctx->fieldSystem->saveData));
    return FALSE;
}

BOOL ScrCmd_UnownCircle(ScriptContext *ctx) {
    FieldSystem_BeginSinjohCutsceneTask(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_SinjohGetEggCutscene(ScriptContext *ctx) {
    FieldSystem_BeginSinjohGetEggCutsceneTask(ctx->fieldSystem, ScriptReadByte(ctx));
    return TRUE;
}

BOOL ScrCmd_MystriStageGymmickInit(ScriptContext *ctx) {
    FieldSystem_InitMystriStageGymmick(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_SinjohFreezeAllModels(ScriptContext *ctx) {
    SinjohGymmick_FreezeAllModels(ctx->fieldSystem);
    return FALSE;
}

BOOL ScrCmd_SinjohSetChosenLegend(ScriptContext *ctx) {
    SinjohGymmick_SetChosenLegend(ctx->fieldSystem, ScriptReadByte(ctx));
    return TRUE;
}

BOOL ScrCmd_CustomSafariLinkExchange(ScriptContext *ctx) {
    CustomSafariLink_ExchangeAreaSets(ctx->fieldSystem);
    return TRUE;
}

BOOL ScrCmd_BufferSafariLinkLeaderName(ScriptContext *ctx) {
    u16 *p_var = ScriptGetVarPointer(ctx);
    MessageFormat **p_msgFmt = FieldSysGetAttrAddr(ctx->fieldSystem, SCRIPTENV_MESSAGE_FORMAT);
    PlayerProfile *profile = PlayerProfile_New(HEAP_ID_FIELD1);
    SafariZone_GetLinkLeaderToProfile(Save_SafariZone_Get(ctx->fieldSystem->saveData), profile);
    BufferPlayersName(*p_msgFmt, *p_var, profile);
    Heap_Free(profile);
    return FALSE;
}

BOOL ScrCmd_CheckSafariZoneLinked(ScriptContext *ctx) {
    SafariZone *safariZone = Save_SafariZone_Get(ctx->fieldSystem->saveData);
    u16 *p_ret = ScriptGetVarPointer(ctx);
    SafariZone_DeactivateLinkIfExpired(safariZone);
    if (SafariZone_IsCurrentlyLinked(safariZone)) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_FollowMonIsNextToPlayer(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (FollowMon_IsNextToPlayer(ctx->fieldSystem)) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_CheckGiftAccessoriesFull(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (FashionCase_GiftAccessoriesFull(ctx->fieldSystem->saveData) == TRUE) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_GetRandomGiftAccessory(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FashionCase_GetRandomGiftAccessory();
    return FALSE;
}

BOOL ScrCmd_CheckHasAllBackdrops(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (FashionCase_HasAllBackdrops(ctx->fieldSystem->saveData) == TRUE) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}

BOOL ScrCmd_GetRandomMissingBackdrop(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    *p_ret = FashionCase_GetRandomMissingBackdrop(ctx->fieldSystem->saveData);
    return FALSE;
}

BOOL ScrCmd_CheckHasLinkBattleRuleset(ScriptContext *ctx) {
    u16 *p_ret = ScriptGetVarPointer(ctx);
    if (Save_LinkBattleRuleset_GetByIndex(ctx->fieldSystem->saveData, 0) != NULL) {
        *p_ret = TRUE;
    } else {
        *p_ret = FALSE;
    }
    return FALSE;
}
