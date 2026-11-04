#include "global.h"

#include "msgdata/msg.naix"
#include "pokeathlon/pokeathlon.h"
#include "pokeathlon/pokeathlon_course_internal.h"

#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"
#include "pm_string.h"

PokeathlonCourseScoreList *PokeathlonCourseScoreList_New(enum HeapID heapId) {
    PokeathlonCourseScoreList *list = Heap_Alloc(heapId, sizeof(PokeathlonCourseScoreList));
    int i;

    MI_CpuFill8(list, 0, sizeof(PokeathlonCourseScoreList));
    for (i = 0; i < POKEATHLON_COURSE_SCORE_ENTRY_MAX; i++) {
        list->entries[i].text = String_New(37, heapId);
        list->entries[i].name = String_New(11, heapId);
    }
    return list;
}

void PokeathlonCourseScoreList_Free(PokeathlonCourseScoreList *list) {
    int i;

    for (i = 0; i < POKEATHLON_COURSE_SCORE_ENTRY_MAX; i++) {
        String_Delete(list->entries[i].text);
        String_Delete(list->entries[i].name);
    }
    Heap_Free(list);
}

static PokeathlonCourseScore *PokeathlonCourseScoreList_AddEntry(PokeathlonCourseScoreList *list) {
    GF_ASSERT(list->next < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(list->next < list->count);
    return &list->entries[list->next++];
}

PokeathlonCourseScore *PokeathlonCourseScoreList_GetEntry(PokeathlonCourseScoreList *list, u32 index) {
    GF_ASSERT(index < POKEATHLON_PARTICIPANTS);
    GF_ASSERT((s32)index < list->count);
    return &list->entries[index];
}

static void PokeathlonCourseScoreList_Reset(PokeathlonCourseScoreList *list) {
    int i;
    list->count = 0;
    list->unk04 = 0;
    list->next = 0;
    list->sortOrder = 0;
    list->totalsAdded = FALSE;
    for (i = 0; i < POKEATHLON_COURSE_SCORE_ENTRY_MAX; i++) {
        list->ranking[i] = NULL;
    }
}

// Sorts the entries by score (descending for mode 0/1, ascending for mode 2; ties go to the lower participant)
// into ranking[] and gives each entry its rank (tied entries share one).
void PokeathlonCourseScoreList_Rank(PokeathlonCourseScoreList *list, int mode) {
    int order;
    PokeathlonCourseScoreNode nodes[POKEATHLON_COURSE_SCORE_ENTRY_MAX + 1];
    int i;
    int j;
    PokeathlonCourseScoreNode *node;
    PokeathlonCourseScoreNode *cur;
    PokeathlonCourseScoreNode *ranked;
    int prevScore;
    int rank;
    BOOL tie;
    nodes[0].next = nodes[0].prev = &nodes[1];
    nodes[0].entry = NULL;
    switch (mode) {
    case 0:
        order = 1;
        break;
    case 1:
        order = 1;
        break;
    case 2:
        order = 2;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    list->sortOrder = order;
    for (i = 0; i < list->count; i++) {
        node = &nodes[i + 1];
        node->entry = &list->entries[i];
        node->next = NULL;
        node->prev = NULL;
        cur = &nodes[0];
        // BUG: after linking an entry in front of a tied one the search goes on without a break, so the node can be
        // linked a second time further on.
        for (j = 0; j < i; j++) {
            cur = cur->next;
            if (order == 1) {
                if (cur->entry->score < node->entry->score) {
                    cur->prev->next = node;
                    node->prev = cur->prev;
                    node->next = cur;
                    cur->prev = node;
                    break;
                } else if (cur->entry->score == node->entry->score && cur->entry->participant > node->entry->participant) {
                    cur->prev->next = node;
                    node->prev = cur->prev;
                    node->next = cur;
                    cur->prev = node;
                }
            } else {
                if (cur->entry->score > node->entry->score) {
                    cur->prev->next = node;
                    node->prev = cur->prev;
                    node->next = cur;
                    cur->prev = node;
                    break;
                } else if (cur->entry->score == node->entry->score && cur->entry->participant > node->entry->participant) {
                    cur->prev->next = node;
                    node->prev = cur->prev;
                    node->next = cur;
                    cur->prev = node;
                }
            }
        }
        if (j == i) {
            cur->next = node;
            node->prev = cur;
        }
    }
    ranked = &nodes[0];
    prevScore = -1;
    tie = FALSE;
    rank = -1;
    for (i = 0; i < list->count; i++) {
        ranked = ranked->next;
        list->ranking[i] = ranked->entry;
        if (prevScore != ranked->entry->score) {
            prevScore = ranked->entry->score;
            if (tie) {
                rank = i;
                tie = FALSE;
            } else {
                rank++;
            }
        } else {
            tie = TRUE;
        }
        list->ranking[i]->rank = rank;
    }
}

PokeathlonCourseScore *PokeathlonCourseScoreList_GetRanked(PokeathlonCourseScoreList *list, u8 index) {
    GF_ASSERT(index < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(index < list->count);
    return list->ranking[index];
}

void PokeathlonCourseScoreList_Init(PokeathlonCourseScoreList *list) {
    PokeathlonCourseScoreList_Reset(list);
    list->count = 4;
    list->unk04 = 0;
}

s32 PokeathlonCourseScoreList_GetCount(PokeathlonCourseScoreList *list) {
    return list->count;
}

u32 PokeathlonCourseScoreList_GetField04(PokeathlonCourseScoreList *list) {
    return list->unk04;
}

void PokeathlonCourseScoreList_AddPointsToTotals(PokeathlonCourseScoreList *list) {
    int i;
    GF_ASSERT(!list->totalsAdded);
    if (!list->totalsAdded) {
        for (i = 0; i < list->count; i++) {
            list->totals[list->ranking[i]->participant] += list->ranking[i]->points;
        }
        list->totalsAdded = TRUE;
    }
}

void PokeathlonCourseScoreList_SaveEventPoints(PokeathlonCourseScoreList *list, int event) {
    int i;
    u32 points[4] = { 0, 0, 0, 0 };
    GF_ASSERT(event < POKEATHLON_COURSE_EVENT_POINTS_MAX);
    for (i = 0; i < list->count; i++) {
        points[list->ranking[i]->participant] += list->ranking[i]->points;
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        list->eventPoints[event][i] = points[i];
    }
}

u32 PokeathlonCourseScoreList_GetEventPoints(PokeathlonCourseScoreList *list, int event, int participant) {
    GF_ASSERT(event < POKEATHLON_COURSE_EVENT_POINTS_MAX);
    return list->eventPoints[event][participant];
}

// Adds the next score entry and prints its score text (msg 309 #msgno with the score in placeholder idx).
void PokeathlonCourse_AddScoreEntry(PokeathlonCourseData *course, PokeathlonCourseScoreList *list, u32 participant, u32 score, u8 idx, u8 digits, u32 msgno) {
    enum HeapID heapId = PokeathlonCourse_GetHeapID(course);
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, heapId);
    PokeathlonCourseScore *entry = PokeathlonCourseScoreList_AddEntry(list);
    MessageFormat *msgFormat;
    String *string;
    entry->participant = participant;
    entry->score = score;
    msgFormat = MessageFormat_New(heapId);
    BufferIntegerAsString(msgFormat, idx, score, digits, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msgno, heapId);
    MessageFormat_Delete(msgFormat);
    String_Copy(entry->text, string);
    String_Delete(string);
    DestroyMsgData(msgData);
}

// As PokeathlonCourse_AddScoreEntry, with two numbers in the text.
void PokeathlonCourse_AddScoreEntry2(PokeathlonCourseData *course, PokeathlonCourseScoreList *list, u32 participant, u32 score, u32 value1, u32 value2, u8 idx1, u8 idx2, u8 digits1, u8 digits2, u32 msgno) {
    enum HeapID heapId = PokeathlonCourse_GetHeapID(course);
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, heapId);
    PokeathlonCourseScore *entry = PokeathlonCourseScoreList_AddEntry(list);
    MessageFormat *msgFormat;
    String *string;
    entry->participant = participant;
    entry->score = score;
    msgFormat = MessageFormat_New(heapId);
    BufferIntegerAsString(msgFormat, idx1, value1, digits1, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    BufferIntegerAsString(msgFormat, idx2, value2, digits2, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(msgFormat, msgData, msgno, heapId);
    MessageFormat_Delete(msgFormat);
    String_Copy(entry->text, string);
    String_Delete(string);
    DestroyMsgData(msgData);
}

void PokeathlonCourseCmd_RecvEvents(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    PokeathlonCourse_SetEvents(course, data);
    PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_EVENTS);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_EVENT_OVERLAY);
}

// Host: collects every player's participant entry; once all arrived, fills the free slots with NPC teams.
void PokeathlonCourseCmd_RecvParticipant(int netId, int size, void *data, void *context) {
    int count;
    if (PokeathlonCourse_GetNetId(context) == 0) {
        memcpy(PokeathlonCourse_GetParticipantData(context, netId), data, size);
        PokeathlonCourse_IncrementReceivedCount(context);
        count = PokeathlonCourse_GetParticipantCount(context);
        if (count == PokeathlonCourse_GetReceivedCount(context)) {
            if (PokeathlonCourse_GetReceivedCount(context) < POKEATHLON_PARTICIPANTS) {
                u32 missing = POKEATHLON_PARTICIPANTS - PokeathlonCourse_GetReceivedCount(context);
                PokeathlonCourse_SetupNpcParticipants(context, (u8)missing);
            }
            PokeathlonCourse_ResetReceivedCount(context);
            PokeathlonCourse_SetNextState(context, POKEATHLON_COURSE_STATE_SEND_PARTICIPANTS);
        }
    }
}

void PokeathlonCourseCmd_RecvAllParticipants(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    memcpy(PokeathlonCourse_GetParticipantData(course, netId), data, size);
    PokeathlonCourse_LoadPerformanceData(course);
    PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_ALL_PARTICIPANTS);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_PROFILES);
}

void PokeathlonCourseCmd_RecvProfiles(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    if (PokeathlonCourse_GetNetId(course)) {
        memcpy(PokeathlonCourse_GetPlayerProfileFromData(course, 0), data, size);
    }
    PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_PROFILES);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_RECORD);
}

void PokeathlonCourseCmd_RecvRecord(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    PokeathlonCourse_IncrementReceivedCount(course);
    if (PokeathlonCourse_GetParticipantCount(course) == PokeathlonCourse_GetReceivedCount(course)) {
        PokeathlonCourse_ResetReceivedCount(course);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_RECORD);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_START_OPENING);
    }
}

void PokeathlonCourseCmd_RecvPacket(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    u8 *dataCopy = PokeathlonCourse_GetDataCopyArea(course);
    if (((PokeathlonCoursePacket *)data)->isHostPacket) {
        memcpy(dataCopy + POKEATHLON_COURSE_DATA_FRAME_IN, data, size);
    } else {
        memcpy(dataCopy + POKEATHLON_COURSE_DATA_INPUTS + netId * POKEATHLON_COURSE_DATA_SLOT_SIZE, data, size);
    }
}

void PokeathlonCourseCmd_RecvEventData(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_EVENT_DATA);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_EVENT);
}

void PokeathlonCourseCmd_RecvEventResult(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    u8 *dataCopy = PokeathlonCourse_GetDataCopyArea(course);
    if (!PokeathlonCourse_GetNetId(course)) {
        u32 resultSize = PokeathlonCourse_GetEventResultSize(course);
        memcpy(PokeathlonCourse_ToBytes(dataCopy + POKEATHLON_COURSE_DATA_FRAME_OUT) + netId * resultSize, data, resultSize);
        PokeathlonCourse_IncrementReceivedCount(course);
        if (PokeathlonCourse_GetParticipantCount(course) == PokeathlonCourse_GetReceivedCount(course)) {
            PokeathlonCourse_ResetReceivedCount(course);
            PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_EVENT_RESULTS);
        }
    }
}

void PokeathlonCourseCmd_RecvEventResults(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    memcpy(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN, data, size);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_ROUND);
}

// Host: adds a player's per-mon event counters to its counters in the course results.
void PokeathlonCourseCmd_RecvMonCounters(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    u32 *src = data;
    u32 *dst;
    u8 i;
    PokeathlonCourse_GetDataCopyArea(course);
    if (!PokeathlonCourse_GetNetId(course)) {
        dst = PokeathlonCourse_GetFieldData_AtIndex(course, (u8)netId);
        for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
            dst[i * 8 + 0] += src[i * 8 + 0];
            dst[i * 8 + 1] += src[i * 8 + 1];
            dst[i * 8 + 2] += src[i * 8 + 2];
            dst[i * 8 + 3] += src[i * 8 + 3];
            dst[i * 8 + 4] += src[i * 8 + 4];
            dst[i * 8 + 5] += src[i * 8 + 5];
            dst[i * 8 + 6] += src[i * 8 + 6];
            dst[i * 8 + 7] += src[i * 8 + 7];
        }
        PokeathlonCourse_IncrementReceivedCount(course);
        if (PokeathlonCourse_GetParticipantCount(course) == PokeathlonCourse_GetReceivedCount(course)) {
            PokeathlonCourse_ResetReceivedCount(course);
            PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_RESULTS);
        }
    }
}

void PokeathlonCourseCmd_RecvResults(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourse_GetNetId(course);
    PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_COURSE_RESULTS);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_START_CLOSING);
}

void PokeathlonCourseCmd_RecvJuiceRecord(int netId, int size, void *data, void *context) {
    PokeathlonCourseData *course = context;
    PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonCourse_IncrementReceivedCount(course);
    if (PokeathlonCourse_GetParticipantCount(course) == PokeathlonCourse_GetReceivedCount(course)) {
        PokeathlonCourse_ResetReceivedCount(course);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_JUICE_RECORDS_RECEIVED);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_STORE_JUICE_RECORDS);
    }
}

int PokeathlonCourseCmd_EventsSize(void) {
    return POKEATHLON_LINK_ROUNDS;
}

int PokeathlonCourseCmd_ParticipantSize(void) {
    return sizeof(PokeathlonCourseParticipant);
}

int PokeathlonCourseCmd_AllParticipantsSize(void) {
    return sizeof(PokeathlonCourseParticipant) * POKEATHLON_PARTICIPANTS;
}

u32 PokeathlonCourseCmd_ProfilesSize(void) {
    return PlayerProfile_sizeof() * POKEATHLON_PARTICIPANTS;
}

int PokeathlonCourseCmd_RecordSize(void) {
    return sizeof(PokeathlonStatistics);
}

int PokeathlonCourseCmd_PacketSize(void) {
    return POKEATHLON_COURSE_CMD_INLINE_SIZE;
}

int PokeathlonCourseCmd_MonCountersSize(void) {
    return 0x60;
}

int PokeathlonCourseCmd_ResultsSize(void) {
    return 0x180;
}

u32 PokeathlonCourseCmd_JuiceRecordSize(void) {
    return ApricornJuiceRecord_sizeof();
}

void *PokeathlonCourseCmd_GetEventDataBuffer(int netId, void *context) {
    return PokeathlonCourse_GetEventRecvBuffer(context);
}

void *PokeathlonCourseCmd_GetRecordBuffer(int netId, void *context) {
    return PokeathlonCourse_GetRecord(context, netId);
}

void *PokeathlonCourseCmd_GetResultsBuffer(int netId, void *context) {
    return PokeathlonCourse_GetFieldData_AtIndex(context, 0);
}

void *PokeathlonCourseCmd_GetMonCountersBuffer(int netId, void *context, int size) {
    return PokeathlonCourse_GetMonCounters(context) + netId * size;
}

void *PokeathlonCourseCmd_GetJuiceRecordBuffer(int netId, void *context) {
    return PokeathlonCourse_GetJuiceRecord(context, (u8)netId);
}
