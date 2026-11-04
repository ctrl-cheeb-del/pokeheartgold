#include "field/pal_pad_registration.h"

#include "global.h"

#include "field/bottom_screen_app.h"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0779.h"

#include "bag.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "dialog_box.h"
#include "friend_roster.h"
#include "frontier_save_access.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "options.h"
#include "overlay_01.h"
#include "player_data.h"
#include "render_window.h"
#include "task.h"
#include "text.h"

enum PalPadRegistrationState {
    PAL_PAD_REGISTRATION_STATE_START,
    PAL_PAD_REGISTRATION_STATE_NEXT_PARTNER,
    PAL_PAD_REGISTRATION_STATE_WAIT_ASK_REGISTER,
    PAL_PAD_REGISTRATION_STATE_ANSWER_REGISTER,
    PAL_PAD_REGISTRATION_STATE_WAIT_ASK_DELETE,
    PAL_PAD_REGISTRATION_STATE_ANSWER_DELETE,
    PAL_PAD_REGISTRATION_STATE_WAIT_ASK_GIVE_UP,
    PAL_PAD_REGISTRATION_STATE_ANSWER_GIVE_UP,
    PAL_PAD_REGISTRATION_STATE_FRIEND_ROSTER_APP,
    PAL_PAD_REGISTRATION_STATE_FRIEND_ROSTER_CHOICE,
    PAL_PAD_REGISTRATION_STATE_WAIT_CONFIRM_DELETE,
    PAL_PAD_REGISTRATION_STATE_ANSWER_CONFIRM_DELETE,
    PAL_PAD_REGISTRATION_STATE_END,
};

#define FRIEND_ROSTER_SIZE 32

static BOOL PalPadRegistration_Start(PalPadRegistration *registration);
static BOOL PalPadRegistration_NextPartner(PalPadRegistration *registration);
static BOOL PalPadRegistration_WaitAskRegister(PalPadRegistration *registration);
static BOOL PalPadRegistration_AnswerRegister(PalPadRegistration *registration);
static BOOL PalPadRegistration_WaitAskDelete(PalPadRegistration *registration);
static BOOL PalPadRegistration_AnswerDelete(PalPadRegistration *registration);
static BOOL PalPadRegistration_WaitAskGiveUp(PalPadRegistration *registration);
static BOOL PalPadRegistration_AnswerGiveUp(PalPadRegistration *registration);
static BOOL PalPadRegistration_RunFriendRosterApp(PalPadRegistration *registration);
static BOOL PalPadRegistration_HandleFriendRosterChoice(PalPadRegistration *registration);
static BOOL PalPadRegistration_WaitConfirmDelete(PalPadRegistration *registration);
static BOOL PalPadRegistration_AnswerConfirmDelete(PalPadRegistration *registration);
static BOOL Task_PalPadRegistration(TaskManager *taskman);
static void PalPadRegistration_PrintMessage(PalPadRegistration *registration, u32 msgId);
static void PalPadRegistration_Init(PalPadRegistration *registration);
static void PalPadRegistration_Free(PalPadRegistration *registration);

static BOOL PalPadRegistration_Start(PalPadRegistration *registration) {
    FriendRoster_GetDwcFriendData(Save_FriendRoster_Get(registration->saveData), 0);
    if (!Comm_RegisterLinkedFriends(registration->saveData, registration->requests, HEAP_ID_FIELD1)) {
        return TRUE;
    }
    registration->partnerNetId = 0;
    LoadUserFrameGfx2(registration->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x1E2, 10, (u8)Options_GetFrame(Save_PlayerData_GetOptionsAddr(registration->saveData)), HEAP_ID_FIELD1);
    LoadUserFrameGfx1(registration->fieldSystem->bgConfig, GF_BG_LYR_MAIN_3, 0x3D9, 11, 0, HEAP_ID_FIELD1);
    registration->state = PAL_PAD_REGISTRATION_STATE_NEXT_PARTNER;
    return FALSE;
}

// Asks about the next partner who requested registration; registers directly when the player has no Pal Pad.
static BOOL PalPadRegistration_NextPartner(PalPadRegistration *registration) {
    FriendRoster *roster;
    int i;

    registration->partnerNetId = (u32)-1;
    i = 0;
    if (Comm_CountConnected() > 0) {
        do {
            if (registration->requests[i] == 2) {
                registration->partnerNetId = i;
                registration->requests[i] = 0;
                break;
            }
            i++;
        } while (i < Comm_CountConnected());
    }
    if (registration->partnerNetId == (u32)-1) {
        return TRUE;
    }
    if (Bag_HasItem(Save_Bag_Get(registration->saveData), ITEM_PAL_PAD, 1, HEAP_ID_FIELD1) == TRUE) {
        BufferPlayersName(registration->msgFormat, 0, CommPlayerInfo_GetProfile(registration->partnerNetId));
        PalPadRegistration_PrintMessage(registration, msg_0779_00062);
        registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_ASK_REGISTER;
        return FALSE;
    }
    roster = Save_FriendRoster_Get(registration->saveData);
    for (i = 0; i < FRIEND_ROSTER_SIZE; i++) {
        if (!FriendRoster_IsFriendValid(roster, i)) {
            Comm_StoreFriendFromPlayer(registration->saveData, registration->partnerNetId, i, HEAP_ID_FIELD1, 0);
            break;
        }
    }
    registration->state = PAL_PAD_REGISTRATION_STATE_NEXT_PARTNER;
    return FALSE;
}

static BOOL PalPadRegistration_WaitAskRegister(PalPadRegistration *registration) {
    if (!TextPrinterCheckActive(registration->printerId)) {
        registration->yesNoState = 0;
        registration->state = PAL_PAD_REGISTRATION_STATE_ANSWER_REGISTER;
    }
    return FALSE;
}

static BOOL PalPadRegistration_AnswerRegister(PalPadRegistration *registration) {
    int i;
    FriendRoster *roster;

    if (!PalPadRegistration_RunTouchYesNo(registration)) {
        if (registration->yesNoAnswer == 0) {
            roster = Save_FriendRoster_Get(registration->saveData);
            for (i = 0; i < FRIEND_ROSTER_SIZE; i++) {
                if (!FriendRoster_IsFriendValid(roster, i)) {
                    Comm_StoreFriendFromPlayer(registration->saveData, registration->partnerNetId, i, HEAP_ID_FIELD1, 0);
                    break;
                }
            }
            if (i == FRIEND_ROSTER_SIZE) {
                PalPadRegistration_PrintMessage(registration, msg_0779_00063);
                registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_ASK_DELETE;
                return FALSE;
            }
        }
        registration->state = PAL_PAD_REGISTRATION_STATE_NEXT_PARTNER;
        return FALSE;
    }
    return FALSE;
}

static BOOL PalPadRegistration_WaitAskDelete(PalPadRegistration *registration) {
    if (!TextPrinterCheckActive(registration->printerId)) {
        registration->yesNoState = 0;
        registration->state = PAL_PAD_REGISTRATION_STATE_ANSWER_DELETE;
    }
    return FALSE;
}

static BOOL PalPadRegistration_AnswerDelete(PalPadRegistration *registration) {
    if (!PalPadRegistration_RunTouchYesNo(registration)) {
        if (registration->yesNoAnswer == 0) {
            registration->rosterAppState = 0;
            registration->state = PAL_PAD_REGISTRATION_STATE_FRIEND_ROSTER_APP;
        } else {
            BufferPlayersName(registration->msgFormat, 0, CommPlayerInfo_GetProfile(registration->partnerNetId));
            PalPadRegistration_PrintMessage(registration, msg_0779_00064);
            registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_ASK_GIVE_UP;
        }
    }
    return FALSE;
}

static BOOL PalPadRegistration_WaitAskGiveUp(PalPadRegistration *registration) {
    if (!TextPrinterCheckActive(registration->printerId)) {
        registration->yesNoState = 0;
        registration->state = PAL_PAD_REGISTRATION_STATE_ANSWER_GIVE_UP;
    }
    return FALSE;
}

static BOOL PalPadRegistration_AnswerGiveUp(PalPadRegistration *registration) {
    if (!PalPadRegistration_RunTouchYesNo(registration)) {
        if (registration->yesNoAnswer == 0) {
            registration->state = PAL_PAD_REGISTRATION_STATE_END;
        } else {
            PalPadRegistration_PrintMessage(registration, msg_0779_00063);
            registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_ASK_DELETE;
        }
    }
    return FALSE;
}

static BOOL PalPadRegistration_RunFriendRosterApp(PalPadRegistration *registration) {
    switch (registration->rosterAppState) {
    case 0:
        FieldSystem_SwitchBottomScreenApp(registration->fieldSystem, BOTTOM_SCREEN_APP_FRIEND_ROSTER, &registration->rosterChoice);
        registration->rosterAppState++;
        break;
    case 1:
        if (PalPadRegistration_IsFriendRosterAppRunning(registration) == TRUE) {
            registration->rosterAppState = 0;
            registration->state = PAL_PAD_REGISTRATION_STATE_FRIEND_ROSTER_CHOICE;
        }
        break;
    }
    return FALSE;
}

static BOOL PalPadRegistration_HandleFriendRosterChoice(PalPadRegistration *registration) {
    FriendRoster *roster;
    PlayerProfile *profile;

    switch (registration->rosterChoice) {
    case -2:
        BufferPlayersName(registration->msgFormat, 0, CommPlayerInfo_GetProfile(registration->partnerNetId));
        PalPadRegistration_PrintMessage(registration, msg_0779_00064);
        registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_ASK_GIVE_UP;
        break;
    case -1:
        break;
    default:
        registration->deleteSlot = registration->rosterChoice;
        roster = Save_FriendRoster_Get(registration->saveData);
        profile = PlayerProfile_New(HEAP_ID_FIELD1);
        Save_Profile_PlayerName_Set(profile, FriendRoster_GetPlayerName(roster, registration->deleteSlot));
        BufferPlayersName(registration->msgFormat, 0, profile);
        Heap_Free(profile);
        PalPadRegistration_PrintMessage(registration, msg_0779_00065);
        registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_CONFIRM_DELETE;
        break;
    }
    return FALSE;
}

static BOOL PalPadRegistration_WaitConfirmDelete(PalPadRegistration *registration) {
    if (!TextPrinterCheckActive(registration->printerId)) {
        registration->yesNoState = 0;
        registration->state = PAL_PAD_REGISTRATION_STATE_ANSWER_CONFIRM_DELETE;
    }
    return FALSE;
}

static BOOL PalPadRegistration_AnswerConfirmDelete(PalPadRegistration *registration) {
    FriendRoster *roster = Save_FriendRoster_Get(registration->saveData);

    if (!PalPadRegistration_RunTouchYesNo(registration)) {
        if (registration->yesNoAnswer == 0) {
            FrontierSave_DeleteRow(Save_Frontier_GetStatic(registration->saveData), registration->deleteSlot);
            FriendRoster_RemoveFriend(roster, registration->deleteSlot);
            Comm_StoreFriendFromPlayer(registration->saveData, registration->partnerNetId, FRIEND_ROSTER_SIZE - 1, HEAP_ID_FIELD1, 0);
            registration->state = PAL_PAD_REGISTRATION_STATE_NEXT_PARTNER;
        } else {
            BufferPlayersName(registration->msgFormat, 0, CommPlayerInfo_GetProfile(registration->partnerNetId));
            PalPadRegistration_PrintMessage(registration, msg_0779_00064);
            registration->state = PAL_PAD_REGISTRATION_STATE_WAIT_ASK_GIVE_UP;
        }
    }
    return FALSE;
}

static BOOL Task_PalPadRegistration(TaskManager *taskman) {
    PalPadRegistration *registration = TaskManager_GetEnvironment(taskman);
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);

#pragma unused(fieldSystem)
    switch (registration->state) {
    case PAL_PAD_REGISTRATION_STATE_START:
        if (PalPadRegistration_Start(registration)) {
            registration->state = PAL_PAD_REGISTRATION_STATE_END;
        }
        break;
    case PAL_PAD_REGISTRATION_STATE_NEXT_PARTNER:
        if (PalPadRegistration_NextPartner(registration)) {
            registration->state = PAL_PAD_REGISTRATION_STATE_END;
        }
        break;
    case PAL_PAD_REGISTRATION_STATE_WAIT_ASK_REGISTER:
        PalPadRegistration_WaitAskRegister(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_ANSWER_REGISTER:
        PalPadRegistration_AnswerRegister(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_WAIT_ASK_DELETE:
        PalPadRegistration_WaitAskDelete(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_ANSWER_DELETE:
        PalPadRegistration_AnswerDelete(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_WAIT_ASK_GIVE_UP:
        PalPadRegistration_WaitAskGiveUp(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_ANSWER_GIVE_UP:
        PalPadRegistration_AnswerGiveUp(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_FRIEND_ROSTER_APP:
        PalPadRegistration_RunFriendRosterApp(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_FRIEND_ROSTER_CHOICE:
        PalPadRegistration_HandleFriendRosterChoice(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_WAIT_CONFIRM_DELETE:
        PalPadRegistration_WaitConfirmDelete(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_ANSWER_CONFIRM_DELETE:
        PalPadRegistration_AnswerConfirmDelete(registration);
        break;
    case PAL_PAD_REGISTRATION_STATE_END:
        PalPadRegistration_Free(registration);
        Heap_Free(registration);
        FieldSystem_ResumeProcesses();
        return TRUE;
    }
    return FALSE;
}

static void PalPadRegistration_PrintMessage(PalPadRegistration *registration, u32 msgId) {
    if (WindowIsInUse(&registration->window)) {
        RemoveWindow(&registration->window);
    }
    ReadMsgDataIntoString(registration->msgData, msgId, registration->rawMessage);
    StringExpandPlaceholders(registration->msgFormat, registration->message, registration->rawMessage);
    DialogBox_AddWindowToLayer3(registration->fieldSystem->bgConfig, &registration->window, GF_BG_LYR_MAIN_3);
    DialogBox_LoadFrame(&registration->window, Save_PlayerData_GetOptionsAddr(registration->fieldSystem->saveData));
    registration->printerId = DialogBox_PrintMessage(&registration->window, registration->message, Save_PlayerData_GetOptionsAddr(registration->fieldSystem->saveData), TRUE);
}

static void PalPadRegistration_Init(PalPadRegistration *registration) {
    MI_CpuFill8(registration, 0, sizeof(PalPadRegistration));
    registration->msgFormat = MessageFormat_New(HEAP_ID_FIELD1);
    registration->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, NARC_msg_msg_0779_bin, HEAP_ID_FIELD1);
    registration->message = String_New(110, HEAP_ID_FIELD1);
    registration->rawMessage = String_New(110, HEAP_ID_FIELD1);
}

static void PalPadRegistration_Free(PalPadRegistration *registration) {
    DestroyMsgData(registration->msgData);
    MessageFormat_Delete(registration->msgFormat);
    String_Delete(registration->message);
    String_Delete(registration->rawMessage);
    if (WindowIsInUse(&registration->window)) {
        RemoveWindow(&registration->window);
    }
}

void FieldSystem_StartPalPadRegistration(FieldSystem *fieldSystem) {
    TaskManager *taskman = fieldSystem->taskman;
    PalPadRegistration *registration = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(PalPadRegistration));

    PalPadRegistration_Init(registration);
    registration->fieldSystem = fieldSystem;
    registration->saveData = fieldSystem->saveData;
    registration->state = PAL_PAD_REGISTRATION_STATE_START;
    if (taskman == NULL) {
        FieldSystem_CreateTask(fieldSystem, Task_PalPadRegistration, registration);
    } else {
        TaskManager_Call(taskman, Task_PalPadRegistration, registration);
    }
}
