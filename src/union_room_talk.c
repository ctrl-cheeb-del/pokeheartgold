#include "union_room_talk.h"

#include "global.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0738_UNION.h"

#include "assert.h"
#include "comm_state.h"
#include "comm_state_internal.h"
#include "comm_wireless.h"
#include "communication_core.h"
#include "communication_player_state.h"
#include "easy_chat.h"
#include "field_system.h"
#include "heap.h"
#include "mail_message.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"
#include "trainer_card_data.h"
#include "union_room.h"
#include "union_room_avatar.h"
#include "union_room_internal.h"

// Union Room talk: the link commands of the talk menu, the script messages for what a player is doing, the activity
// and chat message broadcast in the player's beacon, and the language greeting learned from a foreign player.

static int UnionRoom_GetGroupOfMemberSlot(int slot);
static int UnionRoom_GetPlayerActivityMsg(struct UnionRoom *unionRoom, int slot);
static int UnionRoom_GetSentTalkReplyMsg(int reply, int gender, MessageFormat *msgFmt);
static void UnionRoom_FillStatusMembers(UnionRoomStatus *status, int unused);
static void UnionRoomStatus_Init(UnionRoomStatus *status);

// gender-indexed message ids

static const int sSentTalkReplyMsgs[7][2] = {
    { msg_0738_UNION_00044, msg_0738_UNION_00104 },
    { msg_0738_UNION_00058, msg_0738_UNION_00118 },
    { msg_0738_UNION_00066, msg_0738_UNION_00126 },
    { msg_0738_UNION_00047, msg_0738_UNION_00107 },
    { msg_0738_UNION_00073, msg_0738_UNION_00133 },
    { msg_0738_UNION_00084, msg_0738_UNION_00144 },
    { msg_0738_UNION_00084, msg_0738_UNION_00144 },
};

static const int sUnionRoomChatMsgs[20] = {
    msg_0738_UNION_00169,
    msg_0738_UNION_00170,
    msg_0738_UNION_00171,
    msg_0738_UNION_00172,
    msg_0738_UNION_00173,
    msg_0738_UNION_00174,
    msg_0738_UNION_00175,
    msg_0738_UNION_00176,
    msg_0738_UNION_00177,
    msg_0738_UNION_00178,
    msg_0738_UNION_00179,
    msg_0738_UNION_00180,
    msg_0738_UNION_00181,
    msg_0738_UNION_00182,
    msg_0738_UNION_00183,
    msg_0738_UNION_00184,
    msg_0738_UNION_00185,
    msg_0738_UNION_00186,
    msg_0738_UNION_00187,
    msg_0738_UNION_00188,
};

void UnionRoom_RecvTalkChoice(int netId, int size, u8 *data, FieldSystem *fieldSystem) {
    fieldSystem->unionRoom->talkChoiceReceived = 1;
    fieldSystem->unionRoom->talkChoice = *data;
    if (*data == 4) {
        CommState_SetLinkMode13RequestMode0();
    }
}

void UnionRoom_RecvTalkCancel(int netId, int size, u8 *data, FieldSystem *fieldSystem) {
    fieldSystem->unionRoom->partnerCancelled = 1;
}

BOOL UnionRoom_PartnerCancelled(struct UnionRoom *unionRoom) {
    return unionRoom->partnerCancelled;
}

int UnionRoom_TrySendTalkCancel(struct UnionRoom *unionRoom, int ret) {
    if (unionRoom->talkReply == 0) {
        Comm_SendCommand(0x68, NULL, 0);
        return ret;
    }
    return 0;
}

void UnionRoom_RecvTrainerCard(int netId, int size, void *data) {
    CommPlayerInfo_GetProfile(Comm_GetLocalNetId() ^ 1);
    ((TrainerCardData *)data)->received = 1;
}

TrainerCardData *UnionRoom_GetTrainerCardBuffer(int netId, FieldSystem *fieldSystem) {
    return fieldSystem->unionRoom->cards[netId];
}

void UnionRoom_RecvBattleChoice(int netId, int size, u8 *data, FieldSystem *fieldSystem) {
    fieldSystem->unionRoom->battleChoice[netId] = *data;
}

int UnionRoom_GetBattleCancel(struct UnionRoom *unionRoom) {
    int netId = Comm_GetLocalNetId();
    if (unionRoom->battleChoice[netId] == 2) {
        return 1;
    }
    if (unionRoom->battleChoice[netId ^ 1] == 2) {
        return 2;
    }
    return 0;
}

void UnionRoom_SendBattleChoice(int choice) {
    u8 data;
    data = choice;
    Comm_SendCommand(0x65, &data, 1);
}

static int UnionRoom_GetGroupOfMemberSlot(int slot) {
    int i;
    const u16 *first = gUnionRoomGroupFirstSlot;
    for (i = 0; i < 10; i++, first++) {
        if (*first <= slot && *first + 4 > slot) {
            return i;
        }
    }
    return -1;
}

static int UnionRoom_GetPlayerActivityMsg(struct UnionRoom *unionRoom, int slot) {
    int index, gender;
    UnionRoomRecordInfo *info;
    UnionRoomStatus *status;
    PlayerProfile *profile;

    if (slot > 9) {
        index = UnionRoom_GetGroupOfMemberSlot(slot);
        GF_ASSERT(slot != -1);
    } else {
        index = slot;
    }
    if (unionRoom->records[index] == NULL) {
        return 40;
    }
    profile = CommWireless_GetParentProfile(index);
    info = &unionRoom->records[index]->info;
    status = (UnionRoomStatus *)((u8 *)info + 0x30);
    if (profile == NULL) {
        return 40;
    }
    if (slot > 9) {
        gender = status->memberAvatars[(slot - 10) % 4] >> 7;
    } else {
        gender = PlayerProfile_GetTrainerGender(profile);
    }
    switch (status->activity) {
    case UNION_ACTIVITY_BUSY:
    case UNION_ACTIVITY_LINKED:
        return gUnionRoomActivityBusyMsgs[gender];
    case UNION_ACTIVITY_TRAINER_CARD:
        return gUnionRoomActivityTrainerCardMsgs[(s32)LCRandom() % 2][gender];
    case UNION_ACTIVITY_BATTLE:
        return gUnionRoomActivityBattleMsgs[(s32)LCRandom() % 4][gender];
    case UNION_ACTIVITY_TRADE:
        return gUnionRoomActivityTradeMsgs[(s32)LCRandom() % 2][gender];
    case UNION_ACTIVITY_DRAWING_RECRUIT:
    case UNION_ACTIVITY_DRAWING:
        return gUnionRoomActivityDrawingMsgs[(s32)LCRandom() % 4][gender];
    case UNION_ACTIVITY_RECORD_MIX_RECRUIT:
    case UNION_ACTIVITY_RECORD_MIX:
        return gUnionRoomActivityRecordMixMsgs[(s32)LCRandom() % 4][gender];
    case 3:
    case 10:
    case UNION_ACTIVITY_SPIN_TRADE:
    case UNION_ACTIVITY_SPIN_TRADE_RECRUIT:
        return gUnionRoomActivitySpinTradeMsgs[(s32)LCRandom() % 4][gender];
    }
    return 40;
}

int UnionRoom_GetPartnerHometownMsg(MessageFormat *msgFmt) {
    u8 myCountry = CommPlayerInfo_GetCountry(Comm_GetLocalNetId());
    u8 theirCountry = CommPlayerInfo_GetCountry(Comm_GetLocalNetId() ^ 1);
    u8 myCity = CommPlayerInfo_GetRegion(Comm_GetLocalNetId());
    u8 theirCity = CommPlayerInfo_GetRegion(Comm_GetLocalNetId() ^ 1);

    if (theirCountry == 0) {
        return 15;
    }
    if (theirCountry != 0) {
        BufferCountryName(msgFmt, 3, theirCountry);
        if (theirCity != 0) {
            BufferCityName(msgFmt, 4, theirCountry, theirCity);
        }
    }
    if (myCountry != theirCountry) {
        if (theirCity == 0) {
            return 13;
        }
        if (myCity == theirCity) {
            return 13;
        }
        return 12;
    }
    if (myCity != theirCity) {
        return 14;
    }
    return 15;
}

static int UnionRoom_GetSentTalkReplyMsg(int reply, int gender, MessageFormat *msgFmt) {
    if (reply != 0) {
        return sSentTalkReplyMsgs[reply][gender];
    }
    return UnionRoom_GetPartnerHometownMsg(msgFmt);
}

int UnionRoom_GetTalkMsg(struct UnionRoom *unionRoom, int objId, int kind, MessageFormat *msgFmt) {
    PlayerProfile *profile;
    int gender;

    if (kind == 0) {
        return UnionRoom_GetPlayerActivityMsg(unionRoom, objId - 1);
    }
    profile = CommWireless_GetParentProfile(objId - 1);
    if (profile == NULL) {
        CommState_SetErrorWatch(TRUE, TRUE);
        CommState_SetError(1);
        return 0;
    }
    gender = PlayerProfile_GetTrainerGender(profile);
    switch (kind) {
    case 1:
        return UnionRoom_GetSentTalkReplyMsg(unionRoom->sentTalkReply - 1, gender, msgFmt);
    case 2:
        return gUnionRoomTalkGreetingMsgs[gender];
    case 9:
        if (unionRoom->sentTalkReply == 0) {
            return 0;
        }
        return gUnionRoomTalkAcceptRequestMsgs[unionRoom->sentTalkReply][gender];
    case 19:
    case 20:
    case 21:
        kind -= 19;
        return gUnionRoomTalkRequirementMsgs[kind][gender];
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return gUnionRoomTalkDeclineRequestMsgs[kind - 3][gender];
    case 10:
    case 11:
    case 12:
        kind -= 10;
        return gUnionRoomTalkJoinGroupMsgs[kind][gender];
    case 13:
    case 14:
    case 15:
        kind -= 13;
        return gUnionRoomTalkJoinAcceptedMsgs[kind][gender];
    case 16:
    case 17:
    case 18:
        kind -= 16;
        return gUnionRoomTalkJoinDeclinedMsgs[kind][gender];
    case 22:
        return gUnionRoomTalkAnythingElseMsgs[gender];
    case 23:
        return gUnionRoomTalkComeBackMsgs[gender];
    case 24:
        return gUnionRoomTalkLeaveMsgs[gender];
    case 25:
        return 0xDA;
    case 26:
        return gUnionRoomTalkUntradeableEggMsgs[gender];
    }
    GF_ASSERT(FALSE);
    return 40;
}

u32 UnionRoom_GetPartnerGameVersion(void) {
    PlayerProfile *profile = CommPlayerInfo_GetProfile(Comm_GetLocalNetId() ^ 1);
    GF_ASSERT(profile);
    return PlayerProfile_GetVersion(profile);
}

// The parent lists the players connected to it (net ids 1-4) as its group.
static void UnionRoom_FillStatusMembers(UnionRoomStatus *status, int unused) {
    PlayerProfile *profile;
    int netId;
    int i;
    for (netId = 1; netId < 5; netId++) {
        i = netId - 1;
        profile = CommPlayerInfo_GetProfile(netId);
        if (profile != NULL) {
            if (Comm_GetLocalNetId() == 0) {
                status->memberIds[i] = PlayerProfile_GetTrainerID(profile);
                status->memberAvatars[i] = PlayerProfile_GetAvatar(profile) | (PlayerProfile_GetTrainerGender(profile) << 7);
            }
        } else {
            status->memberIds[i] = 0;
            status->memberAvatars[i] = 0;
        }
    }
}

void UnionRoom_SetBeaconActivity(int activity) {
    UnionRoomStatus status;
    MI_CpuFill8(&status, 0, sizeof(status));
    switch (activity) {
    case UNION_ACTIVITY_LINKED:
        UnionRoom_FillStatusMembers(&status, 2);
        break;
    case UNION_ACTIVITY_TRAINER_CARD:
    case UNION_ACTIVITY_BATTLE:
    case UNION_ACTIVITY_TRADE:
        UnionRoom_FillStatusMembers(&status, 2);
        break;
    case UNION_ACTIVITY_DRAWING:
        UnionRoom_FillStatusMembers(&status, 5);
        break;
    case UNION_ACTIVITY_DRAWING_RECRUIT:
        UnionRoom_FillStatusMembers(&status, 4);
        break;
    case UNION_ACTIVITY_RECORD_MIX:
        UnionRoom_FillStatusMembers(&status, 5);
        break;
    case UNION_ACTIVITY_RECORD_MIX_RECRUIT:
        UnionRoom_FillStatusMembers(&status, 4);
        break;
    case 10:
    case UNION_ACTIVITY_SPIN_TRADE:
        UnionRoom_FillStatusMembers(&status, 5);
        break;
    case 3:
    case UNION_ACTIVITY_SPIN_TRADE_RECRUIT:
        UnionRoom_FillStatusMembers(&status, 4);
        break;
    }
    status.activity = activity;
    CommWireless_SetRuleset(&status);
    CommWireless_RefreshBeacon();
}

int UnionRoom_GetOwnChatMessageMsg(struct UnionRoom *unionRoom, MessageFormat *msgFmt) {
    int i;
    int count = 0;
    int msgNo;
    u16 word;
    for (i = 0; i < 10; i++) {
        if (unionRoom->records[i] != NULL) {
            count++;
        }
    }
    if (count != 0) {
        return 0xA6;
    }
    if (!MailMsg_IsInit(&unionRoom->ownChatMessage)) {
        return 0xA7;
    }
    if (MailMsg_GetMsgBank(&unionRoom->ownChatMessage) != 4) {
        int avatar = PlayerProfile_GetAvatar(unionRoom->profile);
        int gender = PlayerProfile_GetTrainerGender(unionRoom->profile);
        BufferTrainerClassName(msgFmt, 0, GetUnionRoomAvatarAttrBySprite(gender, avatar, 2));
        return 0xA8;
    }
    msgNo = MailMsg_GetMsgNo(&unionRoom->ownChatMessage);
    if (msgNo >= 20) {
        msgNo = 0;
    }
    word = MailMsg_GetFieldI(&unionRoom->ownChatMessage, 0);
    if (word != 0xFFFF) {
        BufferECWord(msgFmt, 0, word);
    }
    return sUnionRoomChatMsgs[msgNo];
}

static void UnionRoomStatus_Init(UnionRoomStatus *status) {
    int i;
    status->activity = UNION_ACTIVITY_NONE;
    for (i = 0; i < 4; i++) {
        status->memberIds[i] = 0;
        status->memberAvatars[i] = 0;
        status->unk10[i] = 0;
        status->unk14[i] = 0;
    }
}

void UnionRoom_SetOwnChatMessage(struct UnionRoom *unionRoom, MailMessage *message) {
    MailMsg_Copy(&unionRoom->ownChatMessage, message);
    unionRoom->ownChatMessageIsNew = 1;
}

MailMessage *UnionRoom_TakeOwnChatMessage(struct UnionRoom *unionRoom) {
    if (unionRoom->ownChatMessageIsNew == 0) {
        return NULL;
    }
    unionRoom->ownChatMessageIsNew = 0;
    return &unionRoom->ownChatMessage;
}

// Buffers both players' names and the partner's language, and lets the player learn the greeting in that language.
void UnionRoom_BufferPartnerLanguage(MessageFormat *msgFmt, u16 mode, u16 objId, PlayerProfile *profile, SaveEasyChat *easyChat) {
    MsgData *msgData;
    PlayerProfile *partner;
    int language;
    int msgNo;
    String *str;

    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0738_UNION_bin, HEAP_ID_FIELD1);
    if (mode == 0) {
        partner = CommWireless_GetParentProfile(objId - 1);
    } else {
        partner = CommPlayerInfo_GetProfile(Comm_GetLocalNetId() ^ 1);
    }
    if (partner == NULL) {
        DestroyMsgData(msgData);
        return;
    }
    BufferPlayersName(msgFmt, 0, partner);
    BufferPlayersName(msgFmt, 1, profile);
    language = PlayerProfile_GetLanguage(partner);
    if (language >= 1 && language <= 7) {
        u16 idx = language - 1;
        if (idx < 7 && gUnionRoomLanguageGreetings[idx] >= 0) {
            Save_EasyChat_SetGreetingFlag(easyChat, gUnionRoomLanguageGreetings[idx]);
        }
    }
    switch (language) {
    case 1:
        msgNo = msg_0738_UNION_00211;
        break;
    case 2:
        msgNo = msg_0738_UNION_00212;
        break;
    case 3:
        msgNo = msg_0738_UNION_00213;
        break;
    case 4:
        msgNo = msg_0738_UNION_00214;
        break;
    case 5:
        msgNo = msg_0738_UNION_00215;
        break;
    case 7:
        msgNo = msg_0738_UNION_00216;
        break;
    default:
        msgNo = msg_0738_UNION_00217;
        break;
    }
    str = NewString_ReadMsgData(msgData, msgNo);
    BufferString(msgFmt, 2, str, 0, 1, language);
    Heap_Free(str);
    DestroyMsgData(msgData);
}

void UnionRoom_BroadcastChatMessage(MailMessage *message) {
    UnionRoomStatus status;
    UnionRoomStatus_Init(&status);
    status.activity = UNION_ACTIVITY_NONE;
    CommWireless_SetMail(message);
    CommWireless_SetRuleset(&status);
    CommWireless_RefreshBeacon();
}

void UnionRoom_ResetTalkReplies(struct UnionRoom *unionRoom) {
    unionRoom->talkReply = 0;
    unionRoom->talkChoice = 0;
    unionRoom->partnerCancelled = 0;
}

void UnionRoom_ResetTalk(struct UnionRoom *unionRoom) {
    unionRoom->connectRequest = 0;
    unionRoom->unk24 = 0;
    unionRoom->talkChoiceReceived = 0;
    unionRoom->talkReply = 0;
    unionRoom->talkChoice = 0;
    unionRoom->unk174 = 0;
    unionRoom->ownChatMessageIsNew = 0;
    unionRoom->partnerCancelled = 0;
}

// Allocates the trainer cards to exchange and builds the player's own; returns the partner's receive buffer.
TrainerCardData *UnionRoom_AllocTrainerCards(struct UnionRoom *unionRoom) {
    int gender;
    int trainerClass;
    unionRoom->ownCard = TrainerCardData_New(HEAP_ID_DEFAULT);
    unionRoom->cards[0] = TrainerCardData_New(HEAP_ID_DEFAULT);
    unionRoom->cards[1] = TrainerCardData_New(HEAP_ID_DEFAULT);
    gender = PlayerProfile_GetTrainerGender(unionRoom->profile);
    trainerClass = GetUnionRoomAvatarAttrBySprite(gender, PlayerProfile_GetAvatar(unionRoom->profile), 0);
    TrainerCardData_Build(0, 0, 0, trainerClass, unionRoom->fieldSystem, (TrainerCardAppArgs *)unionRoom->ownCard);
    return unionRoom->cards[Comm_GetLocalNetId() ^ 1];
}

void UnionRoom_FreeTrainerCards(struct UnionRoom *unionRoom) {
    Heap_Free(unionRoom->cards[0]);
    Heap_Free(unionRoom->cards[1]);
    Heap_Free(unionRoom->ownCard);
}

BOOL UnionRoom_SendTrainerCard(struct UnionRoom *unionRoom) {
    return Comm_SendCommandNoCopy(0x69, unionRoom->ownCard, sizeof(TrainerCardData));
}
