#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "pokeathlon/pokeathlon.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_save.h"
#include "pokeathlon/pokeathlon_util.h"

#include "apricorn_box.h"
#include "bg_window.h"
#include "communication_command.h"
#include "communication_core.h"
#include "filesystem.h"
#include "follow_mon.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "msgdata.h"
#include "oam_manager.h"
#include "overlay_manager.h"
#include "player_data.h"
#include "pm_string.h"
#include "pokemon.h"
#include "save_vars_flags.h"
#include "sound.h"
#include "sound_playback.h"
#include "sound_system.h"
#include "sprite.h"
#include "string_util.h"
#include "sys_task_api.h"
#include "vram_transfer_manager.h"

enum {
    FINISH_STATE_SHOW_SPRITE,
    FINISH_STATE_WAIT,
    FINISH_STATE_SHOW_RESULT,
    FINISH_STATE_WAIT_RESULT,
    FINISH_STATE_DONE,
};

enum PokeathlonCourseStartState {
    START_STATE_SHOW_START,
    START_STATE_WAIT_START,
    START_STATE_COUNTDOWN,
};

enum PokeathlonCourseRunWaitState {
    RUN_WAIT_STATE_INIT,
    RUN_WAIT_STATE_INIT_EVENT,
    RUN_WAIT_STATE_RUN,
    RUN_WAIT_STATE_EXIT,
};

static void PokeathlonCourse_ShowStartSprites(PokeathlonCourseData *course);
static BOOL PokeathlonCourse_IsStartAnimDone(PokeathlonCourseData *course);
static BOOL PokeathlonCourse_SendEventResults(PokeathlonCourseData *course);
static void PokeathlonCourse_StoreRoundResults(PokeathlonCourseData *course, int round);
static void PokeathlonCourse_SaveResults(PokeathlonCourseData *course);
static void PokeathlonCourse_SaveCourseRecord(PokeathlonCourseData *course, PokeathlonSave *pokeathlon);
static void PokeathlonCourse_SaveSoloEventRecords(PokeathlonCourseData *course, PokeathlonCourseEventRecord *records);
static void PokeathlonCourse_SaveLinkEventRecords(PokeathlonCourseData *course, PokeathlonCourseLinkEventRecord *records);
static void PokeathlonCourse_SaveSoloEventBests(PokeathlonCourseData *course, Pokeathlon_RecordsSolo *records, u16 *bests);
static void PokeathlonCourse_InsertRankEntry(u32 order, PokeathlonCourseRankEntry *entry, PokeathlonCourseRankEntry *top);
static void PokeathlonCourse_CopySoloRanking(PokeathlonCourseData *course, PokeathlonCourseEventRecord *record, PokeathlonCourseRankEntry *top);
static void PokeathlonCourse_CopyLinkRanking(PokeathlonCourseData *course, PokeathlonCourseLinkEventRecord *record, PokeathlonCourseRankEntry *top);
static BOOL PokeathlonCourse_BeatsRecord(int record, int score, u32 order);
static BOOL PokeathlonCourse_BeatsRecordInOrder(int record, int score, u32 order);
static void PokeathlonCourse_SaveStatistics(PokeathlonCourseData *course, PokeathlonStatistics *statistics);
static void PokeathlonCourse_SaveFriendshipStatues(PokeathlonCourseData *course);
static void PokeathlonCourse_SetCourseMedals(PokeathlonCourseData *course);
static void PokeathlonCourse_SetMonMedals(PokeathlonCourseData *course, u32 medals);
static BOOL PokeathlonCourse_HasAllCourseRecords(PokeathlonSave *pokeathlon);
static BOOL PokeathlonCourse_HasAllMedalsOfAMon(PokeathlonCourseData *course);
static BOOL PokeathlonCourse_BeatsAllEventTargets(PokeathlonCourseData *course);
static void PokeathlonCourse_ChooseEvents(PokeathlonCourseArgs *args, u32 rounds, u8 *eventIds);
static void PokeathlonCourse_MarkerTask(SysTask *task, void *data);
static void PokeathlonCourse_AddToCounter(u32 counter, u32 amount, u32 *counters);
static BOOL PokeathlonCourse_IsNewRecord(PokeathlonCourseData *course);
static void PokeathlonCourse_ChooseNpcTeams(u32 count, u8 courseId, u32 hard, u8 *npcTeams);
static BOOL PokeathlonCourseLink_SendLargeCommand(int cmd, void *data, int size, PokeathlonCourseLink *link);
static PokeathlonCourseCmdQueue *PokeathlonCourseCmdQueue_New(const PokeathlonCourseCmd *cmds, int cmdCount, PokeathlonCourseData *context, enum HeapID heapId);
static void PokeathlonCourseCmdQueue_Task(SysTask *task, void *data);
static void PokeathlonCourseCmdQueue_Free(PokeathlonCourseCmdQueue *queue);
static void PokeathlonCourseCmdQueue_Add(PokeathlonCourseCmdQueue *queue, u32 cmd, void *data, s32 size);
static void PokeathlonCourseCmdQueue_AddLarge(PokeathlonCourseCmdQueue *queue, u32 cmd, void *data, s32 size);

// Reads the performance data (NARC poketool/personal_performance) of every participant's Pokemon.
void PokeathlonCourse_LoadPerformanceData(PokeathlonCourseData *course) {
    PokeathlonCourseData *participantBase = course;
    NARC *narc = NARC_New(NARC_poketool_personal_performance, participantBase->heapId);
    int i;
    int j;
    PokeathlonCoursePerformance *row;
    i = 0;
    row = participantBase->performance.mons[0];
    for (; i < POKEATHLON_PARTICIPANTS; participantBase = (PokeathlonCourseData *)((u8 *)participantBase + sizeof(PokeathlonCourseParticipant)), row += 3, i++) {
        PokeathlonCourseData *monBase = participantBase;
        PokeathlonCoursePerformance *dest = row;
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++, monBase = (PokeathlonCourseData *)((u8 *)monBase + sizeof(PokeathlonCourseMon)), dest++) {
            NARC_ReadWholeMember(narc, PokeathlonCourse_GetPerformanceFileId(monBase->participants[0].mons[0].species, monBase->participants[0].mons[0].form), dest);
        }
    }
    NARC_Delete(narc);
}

PokeathlonCoursePerformance *PokeathlonCourse_GetPerformance(PokeathlonCourseData *course, int participant, int mon) {
    return &course->performance.mons[participant][mon];
}

u8 *PokeathlonCourse_GetMonStats(PokeathlonCourseData *course, int participant, int mon) {
    GF_ASSERT(participant < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(mon < POKEATHLON_TEAM_SIZE);
    return course->participants[participant].mons[mon].stats;
}

int PokeathlonCourse_GetTouchRadius(void) {
    return 0x50;
}

int PokeathlonCourse_GetSpriteSizeType(const PokeathlonCoursePerformance *performance) {
    if (performance == NULL) {
        return 0;
    }
    switch (performance->spriteSizeType) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
}

int PokeathlonCourse_GetCollisionSizeClass(const PokeathlonCoursePerformance *performance) {
    if (performance == NULL) {
        return 0;
    }
    switch (performance->collisionSizeClass) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        GF_ASSERT(FALSE);
        return 0;
    }
}

// Fills the sprite loader info of a participant's Pokemon; isLarge from its follower parameters.
void PokeathlonCourse_GetMonInfo(PokeathlonCourseData *course, int participant, int which, PokeathlonCourseMonInfo *info) {
    u8 followParam[4];
    PokeathlonCourseMon *mon;
    GF_ASSERT(which < POKEATHLON_TEAM_SIZE);
    mon = &PokeathlonCourse_GetParticipantMons(course, participant)[which];
    info->isShiny = mon->isShiny;
    info->species = mon->species;
    info->form = mon->form;
    info->gender = mon->gender;
    info->participant = participant;
    info->personality = mon->personality;
    GF_ASSERT(info->species != SPECIES_NONE);
    if (info->species == SPECIES_NONE) {
        info->species = SPECIES_BULBASAUR;
    }
    ReadWholeNarcMemberByIdPair(followParam, NARC_fielddata_tsurepoke_tp_param, SpeciesToOverworldModelIndexOffset(info->species));
    if (followParam[1] != 0) {
        info->isLarge = TRUE;
    } else {
        info->isLarge = FALSE;
    }
}

// Creates the countdown / finish, new record and time-up sprites of the event HUD.
Sprite **PokeathlonCourse_CreateHudSprites(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList) {
    VecFx32 position;
    VecFx32 timeUpPosition;
    course->countSprite = PokeathlonCourseSprites_CreateCountdown(resources, spriteList, 0, NNS_G2D_VRAM_TYPE_2DMAIN, course->heapId);
    course->newRecordSprite = PokeathlonCourseSprites_CreateNewRecord(resources, spriteList, 0, course->heapId);
    course->timeUpSprite = PokeathlonCourseSprites_CreateTimeUpCountdown(resources, spriteList, 0, course->heapId);
    position.z = 0;
    position.x = 128 * FX32_ONE;
    position.y = (baseY + 96) << FX32_SHIFT;
    Sprite_SetMatrix(course->countSprite, &position);
    course->hudBaseY = baseY;
    timeUpPosition.z = 0;
    timeUpPosition.x = 128 * FX32_ONE;
    timeUpPosition.y = (course->hudBaseY + 72) << FX32_SHIFT;
    Sprite_SetMatrix(course->timeUpSprite, &timeUpPosition);
    course->finishState = FINISH_STATE_SHOW_SPRITE;
    position.y = (baseY + 130) << FX32_SHIFT;
    Sprite_SetMatrix(course->newRecordSprite, &position);
    return &course->countSprite;
}

Sprite **PokeathlonCourse_CreateHudSpritesInPool(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, PokeathlonCourseSpritePool *pool) {
    return PokeathlonCourse_CreateHudSprites(course, baseY, resources, PokeathlonCourseSpritePool_GetSpriteList(pool));
}

// Creates count "Start" sprites at the given positions (offset by baseY).
void PokeathlonCourse_CreateStartSprites(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, NNS_G2D_VRAM_TYPE whichScreen, u8 count, PokeathlonCoursePoint *positions) {
    u8 i;
    VecFx32 position;
    course->startSpriteCount = count;
    for (i = 0; i < count; i++) {
        course->startSprites[i] = PokeathlonCourseSprites_CreateStart(resources, spriteList, whichScreen, 0, course->heapId);
        position.z = 0;
        position.x = positions[i].x << FX32_SHIFT;
        position.y = (baseY + positions[i].y) << FX32_SHIFT;
        Sprite_SetMatrix(course->startSprites[i], &position);
    }
    for (; i < NELEMS(course->startSprites); i++) {
        course->startSprites[i] = NULL;
    }
    course->startState = START_STATE_SHOW_START;
}

void PokeathlonCourse_CreateStartSpritesInPool(PokeathlonCourseData *course, int baseY, PokeathlonCourseSpriteResources *resources, PokeathlonCourseSpritePool *pool, NNS_G2D_VRAM_TYPE whichScreen, u8 count, PokeathlonCoursePoint *positions) {
    PokeathlonCourse_CreateStartSprites(course, baseY, resources, PokeathlonCourseSpritePool_GetSpriteList(pool), whichScreen, count, positions);
}

// "Start" animation, then "3, 2, 1" (one step every 21 frames). Returns TRUE when the event may begin.
BOOL PokeathlonCourse_RunStartCountdown(PokeathlonCourseData *course) {
    BOOL done = FALSE;
    switch (course->startState) {
    case START_STATE_SHOW_START:
        PlaySE(SEQ_SE_GS_TOUCHPEN);
        PokeathlonCourse_ShowStartSprites(course);
        course->startState++;
        break;
    case START_STATE_WAIT_START:
        if (PokeathlonCourse_IsStartAnimDone(course)) {
            course->startState++;
            Sound_SetPlayerPause(PLAYER_BGM, FALSE);
        }
        break;
    case START_STATE_COUNTDOWN:
        if (course->hudTimer == 0) {
            PlaySE(SEQ_SE_GS_STARTCOUNT);
            Sprite_SetDrawFlag(course->countSprite, TRUE);
            Sprite_SetAnimCtrlSeq(course->countSprite, 0);
        } else if (course->hudTimer == 21) {
            PlaySE(SEQ_SE_GS_STARTCOUNT);
            Sprite_SetAnimCtrlSeq(course->countSprite, 1);
        } else if (course->hudTimer == 42) {
            PlaySE(SEQ_SE_GS_STARTCOUNT);
            Sprite_SetAnimCtrlSeq(course->countSprite, 2);
        }
        course->hudTimer++;
        if (course->hudTimer > 63) {
            PlaySE(SEQ_SE_GS_CON_016);
            Sprite_SetDrawFlag(course->countSprite, FALSE);
            course->hudTimer = 0;
            done = TRUE;
        }
        break;
    }
    return done;
}

// Shows the "3, 2, 1" of the last seconds of an event (framesLeft at 30 fps).
void PokeathlonCourse_UpdateTimeUpCountdown(PokeathlonCourseData *course, int framesLeft) {
    int seconds = (framesLeft + 29) / 30;
    if (seconds <= 0) {
        Sprite_SetDrawFlag(course->timeUpSprite, FALSE);
        return;
    }
    if (seconds <= 3) {
        if (course->timeUpSeconds != seconds) {
            PlaySE(SEQ_SE_GS_ENDCOUNT);
            course->timeUpSeconds = seconds;
        }
        Sprite_SetDrawFlag(course->timeUpSprite, TRUE);
        Sprite_SetAnimCtrlSeq(course->timeUpSprite, seconds + 1);
        return;
    }
    Sprite_SetDrawFlag(course->timeUpSprite, FALSE);
}

void PokeathlonCourse_InitMarkers(PokeathlonCourseData *course) {
    u8 i;
    course->markers.count = 0;
    for (i = 0; i < NELEMS(course->markers.markers); i++) {
        GF_ASSERT(!course->markers.markers[i].active);
        course->markers.markers[i].object = NULL;
        course->markers.markers[i].sprite = NULL;
        course->markers.markers[i].task = NULL;
    }
}

// Adds a marker sprite that follows object (up to 3).
Sprite *PokeathlonCourse_AddMarker(PokeathlonCourseData *course, PokeathlonCourseMonObject *object, PokeathlonCourseSpriteResources *resources, SpriteList *spriteList, int priority) {
    PokeathlonCourseMarker *marker;
    if (course->markers.count >= NELEMS(course->markers.markers)) {
        GF_ASSERT(FALSE);
        return NULL;
    }
    marker = &course->markers.markers[(u8)course->markers.count];
    marker->active = TRUE;
    marker->object = object;
    marker->sprite = PokeathlonCourseSprites_CreateMarker(resources, spriteList, priority, course->heapId);
    marker->task = SysTask_CreateOnMainQueue(PokeathlonCourse_MarkerTask, marker, 1);
    course->markers.count++;
    return marker->sprite;
}

void PokeathlonCourse_FreeMarkers(PokeathlonCourseData *course) {
    u8 i;
    for (i = 0; i < NELEMS(course->markers.markers); i++) {
        course->markers.markers[i].active = FALSE;
        course->markers.markers[i].object = NULL;
        course->markers.markers[i].sprite = NULL;
        SysTask_Destroy(course->markers.markers[i].task);
        course->markers.markers[i].task = NULL;
    }
}

void PokeathlonCourse_SetMarkerAnim(PokeathlonCourseData *course, u8 index, int seq) {
    Sprite_TryChangeAnimSeq(course->markers.markers[index].sprite, seq);
}

void PokeathlonCourse_StopMarkerAnims(PokeathlonCourseData *course) {
    u8 i;
    for (i = 0; i < NELEMS(course->markers.markers); i++) {
        GF_ASSERT(course->markers.markers[i].active);
        Sprite_SetAnimActiveFlag(course->markers.markers[i].sprite, FALSE);
    }
}

static void PokeathlonCourse_ShowStartSprites(PokeathlonCourseData *course) {
    u8 i;
    if (course->startSpriteCount != 0) {
        for (i = 0; i < course->startSpriteCount; i++) {
            Sprite_SetDrawFlag(course->startSprites[i], TRUE);
            Sprite_SetAnimCtrlSeq(course->startSprites[i], 0);
        }
    }
}

static BOOL PokeathlonCourse_IsStartAnimDone(PokeathlonCourseData *course) {
    u8 i;
    if (course->startSpriteCount == 0) {
        return TRUE;
    }
    if (!Sprite_IsAnimated(course->startSprites[0])) {
        for (i = 0; i < course->startSpriteCount; i++) {
            Sprite_SetDrawFlag(course->startSprites[i], FALSE);
        }
        return TRUE;
    }
    return FALSE;
}

void PokeathlonCourse_SetHudPlanes(PokeathlonCourseData *course, u32 planes) {
    course->hudPlanes = planes;
}

// "Finish": shows the finish sprite, runs the event's result callback, shows "New record" if the result beats
// the saved record, then waits. Returns TRUE when done.
BOOL PokeathlonCourse_RunFinish(PokeathlonCourseData *course) {
    switch (course->finishState) {
    case FINISH_STATE_SHOW_SPRITE: {
        VecFx32 position;
        Sprite_SetDrawFlag(course->timeUpSprite, FALSE);
        PlaySE(SEQ_SE_GS_FINISH);
        position.z = 0;
        position.x = 128 * FX32_ONE;
        position.y = (course->hudBaseY + 72) << FX32_SHIFT;
        Sprite_SetMatrix(course->countSprite, &position);
        Sprite_SetAnimCtrlSeq(course->countSprite, 3);
        Sprite_SetDrawFlag(course->countSprite, TRUE);
        course->finishState = FINISH_STATE_WAIT;
        break;
    }
    case FINISH_STATE_WAIT:
        course->hudTimer++;
        if (course->hudTimer > 60) {
            course->hudTimer = 0;
            course->finishState = FINISH_STATE_SHOW_RESULT;
        }
        break;
    case FINISH_STATE_SHOW_RESULT:
        if (course->finishCallback) {
            course->finishCallback(course);
        }
        if (PokeathlonCourse_IsNewRecord(course)) {
            PlaySE(SEQ_SE_GS_NEWRECORD);
            Sprite_SetAnimCtrlSeq(course->newRecordSprite, 0);
            Sprite_SetDrawFlag(course->newRecordSprite, TRUE);
        }
        GfGfx_EngineATogglePlanes(course->hudPlanes, TRUE);
        course->finishCallback = NULL;
        course->finishState = FINISH_STATE_WAIT_RESULT;
        break;
    case FINISH_STATE_WAIT_RESULT:
        course->hudTimer++;
        if (course->hudTimer > 120) {
            course->hudTimer = 0;
            course->finishState = FINISH_STATE_DONE;
            return TRUE;
        }
        break;
    case FINISH_STATE_DONE:
        return TRUE;
    }
    return FALSE;
}

// File of a Pokemon's form in NARC poketool/personal_performance.
int PokeathlonCourse_GetPerformanceFileId(int species, int form) {
    return form + gPokeathlonPerformanceFileIds[species];
}

// The course states (PokeathlonCourse_SetNextState) that run between the events, and the event results.

void PokeathlonCourse_DrawEvent(PokeathlonCourseData *data) {
    if (data->eventDrawEnabled) {
        data->event->draw(data, 0);
    }
}

// Host: chooses the events of the course and sends them to every player.
BOOL PokeathlonCourse_State_SendEvents(PokeathlonCourseData *course) {
    BOOL sent = TRUE;
    if (!PokeathlonCourse_GetNetId(course)) {
        PokeathlonCourse_ChooseEvents(course->args, course->rounds, course->eventIds);
        sent = PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_EVENTS, course->eventIds, PokeathlonCourseCmd_EventsSize(), course->link);
    }
    if (sent) {
        PokeathlonCourse_SetNextStateIfNot(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND, POKEATHLON_COURSE_STATE_RUN_EVENT_OVERLAY);
    }
    return FALSE;
}

// Waits for the event that was running to end.
BOOL PokeathlonCourse_State_RunEventOverlay(PokeathlonCourseData *course) {
    if (OverlayManager_Run(course->subOverlay)) {
        OverlayManager *manager = course->subOverlay;
        PokeathlonCourseArgs *args;
        OverlayManager_Delete(manager);
        args = course->args;
        if (args->mode == POKEATHLON_COURSE_MODE_SOLO) {
            if (course->boxCancelled) {
                args->shouldFreeHeap = TRUE;
                PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_EXIT);
            } else {
                args->shouldFreeHeap = FALSE;
                PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_PARTICIPANT);
            }
        } else {
            args->shouldFreeHeap = FALSE;
            PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_WAIT);
        }
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_RunWait(PokeathlonCourseData *course, u8 *state) {
    switch (*state) {
    case RUN_WAIT_STATE_INIT:
        course->event = &gPokeathlonCourseEvent_Wait;
        course->eventInitState = 0;
        PokeathlonCourse_InitStateInfo(gPokeathlonCourseWaitSteps, &course->eventStateInfo);
        (*state)++;
        break;
    case RUN_WAIT_STATE_INIT_EVENT:
        if (PokeathlonCourse_RunSubStateLoop(course)) {
            (*state)++;
        }
        break;
    case RUN_WAIT_STATE_RUN:
        if (course->eventStateInfo.ptr == NULL) {
            (*state)++;
            break;
        }
        if (course->courseState.argsPtr == &course->stateInfo) {
            course->courseState.argsPtr = &course->eventStateInfo;
            course->courseState.exitFlag = 0;
        }
        if (((PokeathlonCourseStepFunc *)course->eventStateInfo.ptr)[course->eventStateInfo.stateIndex](course, &course->eventStateInfo.stateArgsBase)) {
            PokeathlonCourse_SetEventDrawEnabled(course, FALSE);
            course->courseState.argsPtr = &course->stateInfo;
            course->courseState.exitFlag = 0;
            (*state)++;
        }
        break;
    case RUN_WAIT_STATE_EXIT:
        course->event->exit(course, 0);
        GF_ASSERT(!course->work);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_PARTICIPANT);
        break;
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendParticipant(PokeathlonCourseData *course) {
    course->localParticipant.npcTeam = 0;
    if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_PARTICIPANT, &course->localParticipant, PokeathlonCourseCmd_ParticipantSize(), course->link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendParticipants(PokeathlonCourseData *course) {
    PokeathlonCourseParticipant *participants = PokeathlonCourse_GetParticipantData(course, 0);
    int size = PokeathlonCourseCmd_AllParticipantsSize();
    PokeathlonCourseLink *link = PokeathlonCourse_GetSystem(course);
    if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_ALL_PARTICIPANTS, participants, size, link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendProfiles(PokeathlonCourseData *course) {
    BOOL sent = TRUE;
    if (!PokeathlonCourse_GetNetId(course)) {
        sent = PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_PROFILES, course->playerProfiles, PokeathlonCourseCmd_ProfilesSize(), course->link);
    }
    if (sent) {
        PokeathlonCourse_SetNextStateIfNot(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND, POKEATHLON_COURSE_STATE_SEND_RECORD);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendRecord(PokeathlonCourseData *course) {
    course->results.record = *PokeathlonSave_GetStatistics2(Save_Pokeathlon_Get(course->args->saveData));
    if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_RECORD, &course->results.record, PokeathlonCourseCmd_RecordSize(), course->link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_StartOpening(PokeathlonCourseData *course) {
    course->counterEnabled = TRUE;
    PokeathlonCourse_ResetDataCopyArea(course);
    course->event = &gPokeathlonCourseEvent_Opening;
    course->eventInitState = 0;
    PokeathlonCourse_InitStateInfo(gPokeathlonCourseOpeningSteps, &course->eventStateInfo);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_OPENING_START);
    return FALSE;
}

BOOL PokeathlonCourse_State_WaitOpeningStart(PokeathlonCourseData *course) {
    if (PokeathlonCourse_RunSubStateLoop(course)) {
        PokeathlonCoursePacket *packets = (PokeathlonCoursePacket *)PokeathlonCourse_GetDataCopyArea(course);
        packets[0].isHostPacket = FALSE;
        packets[1].isHostPacket = TRUE;
        PokeathlonCourseLink_SetCheckSize(PokeathlonCourse_GetSystem(course), TRUE);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_OPENING);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_OPENING);
        Sound_SetScene(SOUND_SCENE_NONE);
        Sound_SetSceneAndPlayBGM(25, SEQ_GS_PT_OPEN, 0);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_RunOpening(PokeathlonCourseData *course) {
    if (course->eventStateInfo.ptr == NULL) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_OPENING);
        return FALSE;
    }
    if (course->courseState.argsPtr == &course->stateInfo) {
        course->courseState.argsPtr = &course->eventStateInfo;
        course->courseState.exitFlag = 0;
    }
    if (((PokeathlonCourseStepFunc *)course->eventStateInfo.ptr)[course->eventStateInfo.stateIndex](course, &course->eventStateInfo.stateArgsBase)) {
        PokeathlonCourse_SetEventDrawEnabled(course, FALSE);
        course->courseState.argsPtr = &course->stateInfo;
        course->courseState.exitFlag = 0;
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_OPENING);
    } else if (!PokeathlonCourse_GetNetId(course)) {
        u8 *dest;
        u8 *src;
        u32 size;
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[1], PokeathlonCourseCmd_PacketSize(), course->link);
        dest = PokeathlonCourse_ToBytes(&course->packets[2]);
        src = PokeathlonCourse_ToBytes(&course->packets[0]);
        size = sizeof(PokeathlonCoursePacket);
        do {
            *dest++ = *src++;
        } while (--size);
    } else {
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[0], PokeathlonCourseCmd_PacketSize(), course->link);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_EndOpening(PokeathlonCourseData *course) {
    course->event->exit(course, 0);
    GF_ASSERT(course->work == NULL);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_START_EVENT_INTRO);
    return FALSE;
}

BOOL PokeathlonCourse_State_StartEventIntro(PokeathlonCourseData *course) {
    course->event = &gPokeathlonCourseEvent_EventIntro;
    course->eventInitState = 0;
    PokeathlonCourse_InitStateInfo(gPokeathlonEventIntroSteps, &course->eventStateInfo);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_EVENT_INTRO_START);
    return FALSE;
}

BOOL PokeathlonCourse_State_WaitEventIntroStart(PokeathlonCourseData *course) {
    if (PokeathlonCourse_RunSubStateLoop(course)) {
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_EVENT_INTRO);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_EVENT_INTRO);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_RunEventIntro(PokeathlonCourseData *course) {
    if (course->eventStateInfo.ptr == NULL) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_EVENT_INTRO);
        return FALSE;
    }
    if (course->courseState.argsPtr == &course->stateInfo) {
        course->courseState.argsPtr = &course->eventStateInfo;
        course->courseState.exitFlag = 0;
    }
    if (((PokeathlonCourseStepFunc *)course->eventStateInfo.ptr)[course->eventStateInfo.stateIndex](course, &course->eventStateInfo.stateArgsBase)) {
        PokeathlonCourse_SetEventDrawEnabled(course, FALSE);
        course->courseState.argsPtr = &course->stateInfo;
        course->courseState.exitFlag = 0;
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_EVENT_INTRO);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_EndEventIntro(PokeathlonCourseData *course) {
    course->event->exit(course, 0);
    GF_ASSERT(course->work == NULL);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_START_ROUND);
    return FALSE;
}

// Sets up the event of the current round.
BOOL PokeathlonCourse_State_StartRound(PokeathlonCourseData *course) {
    u8 event = course->roundEvents[course->round];
    course->startSpriteCount = 0;
    course->recordScore = POKEATHLON_NO_RECORD;
    course->timeUpSeconds = 0;
    course->finishCallback = NULL;
    PokeathlonCourse_ResetDataCopyArea(course);
    course->event = gPokeathlonCourseEvents[event];
    course->eventInitState = 0;
    PokeathlonCourse_InitStateInfo(gPokeathlonCourseEventSteps[event], &course->eventStateInfo);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_ROUND_START);
    return FALSE;
}

BOOL PokeathlonCourse_State_WaitRoundStart(PokeathlonCourseData *course) {
    if (PokeathlonCourse_RunSubStateLoop(course)) {
        PokeathlonCoursePacket *packets = (PokeathlonCoursePacket *)PokeathlonCourse_GetDataCopyArea(course);
        packets[0].isHostPacket = FALSE;
        packets[1].isHostPacket = TRUE;
        PokeathlonCourseLink_SetCheckSize(PokeathlonCourse_GetSystem(course), TRUE);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_ROUND_START);
        if (course->round == course->rounds - 1) {
            Sound_SetScene(SOUND_SCENE_NONE);
            Sound_SetSceneAndPlayBGM(24, SEQ_GS_PT_GAMEF, 0);
        } else {
            Sound_SetScene(SOUND_SCENE_NONE);
            Sound_SetSceneAndPlayBGM(24, SEQ_GS_PT_GAME, 0);
        }
        Sound_SetPlayerPause(PLAYER_BGM, TRUE);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_EVENT_DATA);
        GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendEventData(PokeathlonCourseData *course) {
    if (course->eventData.pending) {
        if (!PokeathlonCourse_GetNetId(course)) {
            if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_EVENT_DATA, course->eventData.toSend, course->eventData.size, course->link)) {
                PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
            }
        } else {
            PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
        }
    } else {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_EVENT);
    }
    return FALSE;
}

// Runs the event's state functions; the host sends its packet every frame, the others theirs.
BOOL PokeathlonCourse_State_RunEvent(PokeathlonCourseData *course) {
    if (!course->eventStateInfo.ptr) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_NEXT_ROUND);
        return FALSE;
    }
    if (course->courseState.argsPtr == &course->stateInfo) {
        course->courseState.argsPtr = &course->eventStateInfo;
        course->courseState.exitFlag = 0;
    }
    if (((PokeathlonCourseStepFunc *)course->eventStateInfo.ptr)[course->eventStateInfo.stateIndex](course, &course->eventStateInfo.stateArgsBase)) {
        PokeathlonCourse_SetEventDrawEnabled(course, FALSE);
        course->courseState.argsPtr = &course->stateInfo;
        course->courseState.exitFlag = 0;
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_EVENT_END);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RESET_DATA_COPY_AREA);
    } else if (!PokeathlonCourse_GetNetId(course)) {
        u8 *dest;
        u8 *src;
        u32 size;
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[1], PokeathlonCourseCmd_PacketSize(), course->link);
        dest = PokeathlonCourse_ToBytes(&course->packets[2]);
        src = PokeathlonCourse_ToBytes(&course->packets[0]);
        size = sizeof(PokeathlonCoursePacket);
        do {
            *dest++ = *src++;
        } while (--size);
    } else {
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[0], PokeathlonCourseCmd_PacketSize(), course->link);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_ResetDataCopyArea(PokeathlonCourseData *course) {
    PokeathlonCourse_ResetDataCopyArea(course);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_EVENT_RESULT);
    return FALSE;
}

BOOL PokeathlonCourse_State_SendEventResult(PokeathlonCourseData *course) {
    BOOL done;
    if (course->event->sendsOwnResult) {
        PokeathlonCoursePoint *point = (PokeathlonCoursePoint *)PokeathlonCourse_ToBytes(&course->packets[0]);
        int netId = PokeathlonCourse_GetNetId(course);
        point->x = course->eventResults[netId].score;
        point->y = course->eventResults[netId].unk2;
        done = PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_EVENT_RESULT, &course->packets[0], PokeathlonCourseCmd_PacketSize(), course->link);
        if (done && !PokeathlonCourse_GetNetId(course)) {
            int size = PokeathlonCourse_GetEventResultSize(course);
            int i = PokeathlonCourse_GetParticipantCount(course);
            for (; i < POKEATHLON_PARTICIPANTS; i++) {
                memcpy(PokeathlonCourse_ToBytes(&course->packets[1]) + i * size, &course->eventResults[i], size);
            }
        }
    } else if (!PokeathlonCourse_GetNetId(course)) {
        done = PokeathlonCourse_SendEventResults(course);
    } else {
        done = TRUE;
    }
    if (done) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendEventResults(PokeathlonCourseData *course) {
    u8 *dataCopy = PokeathlonCourse_GetDataCopyArea(course);
    int size = PokeathlonCourseCmd_PacketSize();
    PokeathlonCourseLink *link = PokeathlonCourse_GetSystem(course);
    if (PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_EVENT_RESULTS, dataCopy + POKEATHLON_COURSE_DATA_FRAME_OUT, size, link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

// Takes over the event results the host sent and stores the round's points.
BOOL PokeathlonCourse_State_EndRound(PokeathlonCourseData *course) {
    u16 *src = (void *)PokeathlonCourse_ToBytes(&course->packets[6]);
    u16 *dest = course->receivedResults;
    u32 count = NELEMS(course->receivedResults);
    do {
        *dest++ = *src++;
    } while (--count != 0);
    if (course->event->onResults != NULL) {
        course->event->onResults(course, 0);
    }
    PokeathlonCourse_StoreRoundResults(course, (u8)course->round);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_EXIT_EVENT);
    return FALSE;
}

BOOL PokeathlonCourse_State_ExitEvent(PokeathlonCourseData *course) {
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));
    course->event->exit(course, 0);
    GF_ASSERT(course->work == NULL);
    if ((s32)course->round < course->rounds) {
        if (course->event->onResults != NULL) {
            PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_START_RESULTS);
        } else {
            PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_NEXT_ROUND);
        }
    } else {
        course->round++;
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_MON_COUNTERS);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_NextRound(PokeathlonCourseData *course) {
    course->round++;
    if ((s32)course->round >= course->rounds) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_MON_COUNTERS);
    } else {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_START_EVENT_INTRO);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_StartResults(PokeathlonCourseData *course) {
    course->event = &gPokeathlonCourseEvent_ResultsAnnouncement;
    course->eventInitState = 0;
    PokeathlonCourse_InitStateInfo(gPokeathlonResultsAnnouncementSteps, &course->eventStateInfo);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_RESULTS_START);
    return FALSE;
}

BOOL PokeathlonCourse_State_WaitResultsStart(PokeathlonCourseData *course) {
    if (PokeathlonCourse_RunSubStateLoop(course)) {
        PokeathlonCoursePacket *packets = (PokeathlonCoursePacket *)PokeathlonCourse_GetDataCopyArea(course);
        packets[0].isHostPacket = FALSE;
        packets[1].isHostPacket = TRUE;
        PokeathlonCourseLink_SetCheckSize(PokeathlonCourse_GetSystem(course), TRUE);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_RESULTS);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_RESULTS);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_RunResults(PokeathlonCourseData *course) {
    PokeathlonCourseStepFunc *steps;
    if (course->eventStateInfo.ptr == NULL) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_RESULTS);
        return FALSE;
    }
    if (course->courseState.argsPtr == &course->stateInfo) {
        course->courseState.argsPtr = &course->eventStateInfo;
        course->courseState.exitFlag = 0;
    }
    steps = course->eventStateInfo.ptr;
    if (steps[course->eventStateInfo.stateIndex](course, &course->eventStateInfo.stateArgsBase)) {
        PokeathlonCourse_SetEventDrawEnabled(course, FALSE);
        course->courseState.argsPtr = &course->stateInfo;
        course->courseState.exitFlag = 0;
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_END_RESULTS);
    } else if (!PokeathlonCourse_GetNetId(course)) {
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[1], PokeathlonCourseCmd_PacketSize(), course->link);
        u8 *dest = PokeathlonCourse_ToBytes(&course->packets[2]);
        u8 *src = PokeathlonCourse_ToBytes(&course->packets[0]);
        u32 size = sizeof(PokeathlonCoursePacket);
        do {
            *dest++ = *src++;
        } while (--size != 0);
    } else {
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[0], PokeathlonCourseCmd_PacketSize(), course->link);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_EndResults(PokeathlonCourseData *course) {
    course->event->exit(course, 0);
    GF_ASSERT(course->work == NULL);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_NEXT_ROUND);
    return FALSE;
}

BOOL PokeathlonCourse_State_StartClosing(PokeathlonCourseData *course) {
    PokeathlonCourse_ResetDataCopyArea(course);
    course->event = &gPokeathlonCourseEvent_Closing;
    course->eventInitState = 0;
    PokeathlonCourse_InitStateInfo(gPokeathlonCourseClosingSteps, &course->eventStateInfo);
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_CLOSING_START);
    return FALSE;
}

BOOL PokeathlonCourse_State_WaitClosingStart(PokeathlonCourseData *course) {
    if (PokeathlonCourse_RunSubStateLoop(course)) {
        PokeathlonCoursePacket *packets = (PokeathlonCoursePacket *)PokeathlonCourse_GetDataCopyArea(course);
        packets[0].isHostPacket = FALSE;
        packets[1].isHostPacket = TRUE;
        PokeathlonCourseLink_SetCheckSize(PokeathlonCourse_GetSystem(course), TRUE);
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_CLOSING);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_RUN_CLOSING);
        Sound_SetScene(SOUND_SCENE_NONE);
        Sound_SetSceneAndPlayBGM(25, SEQ_GS_PT_END, 0);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_RunClosing(PokeathlonCourseData *course) {
    PokeathlonCourseStepFunc *steps;
    if (course->eventStateInfo.ptr == NULL) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_CREATE_JUICE_RECORDS);
        return FALSE;
    }
    if (course->courseState.argsPtr == &course->stateInfo) {
        course->courseState.argsPtr = &course->eventStateInfo;
        course->courseState.exitFlag = 0;
    }
    steps = course->eventStateInfo.ptr;
    if (steps[course->eventStateInfo.stateIndex](course, &course->eventStateInfo.stateArgsBase)) {
        PokeathlonCourse_SetEventDrawEnabled(course, FALSE);
        course->courseState.argsPtr = &course->stateInfo;
        course->courseState.exitFlag = 0;
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_CREATE_JUICE_RECORDS);
    } else if (!PokeathlonCourse_GetNetId(course)) {
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[1], PokeathlonCourseCmd_PacketSize(), course->link);
        u8 *dest = PokeathlonCourse_ToBytes(&course->packets[2]);
        u8 *src = PokeathlonCourse_ToBytes(&course->packets[0]);
        u32 size = sizeof(PokeathlonCoursePacket);
        do {
            *dest++ = *src++;
        } while (--size != 0);
    } else {
        PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_PACKET, &course->packets[0], PokeathlonCourseCmd_PacketSize(), course->link);
    }
    return FALSE;
}

// Course over: creates the Apricorn juice record of the course (juiceRecord) and the buffer for the records of
// every player (playerJuiceRecords).
BOOL PokeathlonCourse_State_CreateJuiceRecords(PokeathlonCourseData *course) {
    SaveApricornBox *apricornBox;
    PlayerProfile *profile;
    PokeathlonStatistics *record;
    u32 size;
    course->event->exit(course, 0);
    GF_ASSERT(course->work == NULL);
    apricornBox = Save_ApricornBox_Get(course->args->saveData);
    profile = Save_PlayerData_GetProfile(course->args->saveData);
    record = PokeathlonSave_GetStatistics(Save_Pokeathlon_Get(course->args->saveData));
    size = ApricornJuiceRecord_sizeof() * 4;
    course->playerJuiceRecords = Heap_AllocAtEnd(course->heapId, size);
    memset(course->playerJuiceRecords, 0, size);
    course->juiceRecord = ApricornRecord_New(apricornBox, profile, record->fanCount, course->heapId);
    if (course->args->mode == POKEATHLON_COURSE_MODE_LINK) {
        PokeathlonCourse_SetStateTransitionType(course, POKEATHLON_COURSE_SYNC_JUICE_RECORDS);
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_SEND_JUICE_RECORD);
    } else {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_EXIT);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendMonCounters(PokeathlonCourseData *course) {
    PokeathlonCourse_GetNetId(course);
    if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_MON_COUNTERS, course->localCounters, PokeathlonCourseCmd_MonCountersSize(), course->link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendResults(PokeathlonCourseData *course) {
    u32 *results = PokeathlonCourse_GetFieldData_AtIndex(course, 0);
    int size = PokeathlonCourseCmd_ResultsSize();
    PokeathlonCourseLink *link = PokeathlonCourse_GetSystem(course);
    if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_RESULTS, results, size, link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_SendJuiceRecord(PokeathlonCourseData *course) {
    u32 size = ApricornJuiceRecord_sizeof();
    if (PokeathlonCourseLink_SendLargeCommand(POKEATHLON_COURSE_CMD_JUICE_RECORD, course->juiceRecord, size, course->link)) {
        PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_WAIT_FOR_COMMAND);
    }
    return FALSE;
}

BOOL PokeathlonCourse_State_StoreJuiceRecords(PokeathlonCourseData *course) {
    SaveApricornBox *apricornBox = Save_ApricornBox_Get(course->args->saveData);
    u32 count = PokeathlonCourse_GetParticipantCount(course);
    u32 netId = Comm_GetLocalNetId();
    ApricornBox_StoreJuiceRecords(apricornBox, course->playerJuiceRecords, count, netId);
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));
    PokeathlonCourse_SetNextState(course, POKEATHLON_COURSE_STATE_EXIT);
    return FALSE;
}

BOOL PokeathlonCourse_State_Exit(PokeathlonCourseData *course) {
    GF_ASSERT(GF_heap_c_dummy_return_true(HEAP_ID_POKEATHLON));
    if (!course->args->shouldFreeHeap) {
        PokeathlonCourse_SaveResults(course);
    }
    return TRUE;
}

BOOL PokeathlonCourse_State_WaitForCommand(void) {
    return FALSE;
}

void PokeathlonCourse_VBlankCallback(void *bgConfig) {
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(bgConfig);
    GF_RunVramTransferTasks();
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

// Host: sends every player's event result to the others.
static BOOL PokeathlonCourse_SendEventResults(PokeathlonCourseData *course) {
    u8 *dataCopy = PokeathlonCourse_GetDataCopyArea(course);
    int i;
    u32 size;
    int packetSize;
    PokeathlonCourseLink *link;

    if (PokeathlonCourse_GetNetId(course) != 0) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        size = PokeathlonCourse_GetEventResultSize(course);
        memcpy(PokeathlonCourse_ToBytes(dataCopy + POKEATHLON_COURSE_DATA_FRAME_OUT) + i * size, &course->eventResults[i], size);
    }
    packetSize = PokeathlonCourseCmd_PacketSize();
    link = PokeathlonCourse_GetSystem(course);
    return PokeathlonCourseLink_SendCommand(POKEATHLON_COURSE_CMD_EVENT_RESULTS, dataCopy + POKEATHLON_COURSE_DATA_FRAME_OUT, packetSize, link);
}

// Stores the points and scores of the round from the score list, and whether the player won it or came last.
static void PokeathlonCourse_StoreRoundResults(PokeathlonCourseData *course, int round) {
    u8 netId = PokeathlonCourse_GetNetId(course);
    u8 i;
    PokeathlonCourseScore *entry = NULL;
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourseScore *score = PokeathlonCourseScoreList_GetEntry(course->scores, i);
        course->results.eventPoints[i][round] = score->points;
        course->results.eventScores[i][round] = score->score;
    }
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        entry = PokeathlonCourseScoreList_GetRanked(course->scores, i);
        if (entry->participant == netId) {
            break;
        }
    }
    if (i == POKEATHLON_PARTICIPANTS) {
        GF_ASSERT(FALSE);
        return;
    }
    if (entry->rank == 0) {
        course->results.wonRound[round] = TRUE;
        course->results.lastInRound[round] = FALSE;
        return;
    }
    course->results.wonRound[round] = FALSE;
    {
        PokeathlonCourseScore *last = PokeathlonCourseScoreList_GetRanked(course->scores, POKEATHLON_PARTICIPANTS - 1);
        u8 rank = last->rank;
        if (rank == entry->rank) {
            course->results.lastInRound[round] = TRUE;
        } else {
            course->results.lastInRound[round] = FALSE;
        }
    }
}

// Saves the results of the course: athlete points, event and course records, medals, statistics.
static void PokeathlonCourse_SaveResults(PokeathlonCourseData *course) {
    PokeathlonSave *pokeathlon = Save_Pokeathlon_Get(course->args->saveData);
    PokeathlonCourseResults *results = PokeathlonCourse_GetFieldData(course);
    SaveVarsFlags *varsFlags = Save_VarsFlags_Get(course->args->saveData);
    u16 points;
    void *records;

    if (results->wonCourse) {
        PokeathlonCourse_SetCourseMedals(course);
        if (!Save_VarsFlags_CheckFlagInArray(varsFlags, FLAG_UNK_0F0) && PokeathlonCourse_HasAllMedalsOfAMon(course)) {
            Save_VarsFlags_SetFlagInArray(varsFlags, FLAG_UNK_0F0);
        }
    }
    points = results->totalPoints;
    if (course->args->course == POKEATHLON_COURSE_LINK_RANDOM) {
        points *= 2;
    }
    PokeathlonSave_AddAthletePoints(pokeathlon, points);
    if (course->args->mode == POKEATHLON_COURSE_MODE_LINK) {
        records = PokeathlonSave_GetRecordsLink2(pokeathlon);
        PokeathlonCourse_SaveLinkEventRecords(course, records);
    } else {
        records = PokeathlonSave_GetRecordsSolo(pokeathlon);
        PokeathlonCourse_SaveSoloEventBests(course, records, PokeathlonSave_GetSoloEventBestPoints(pokeathlon));
        if (results->wonCourse) {
            PokeathlonCourse_SaveCourseRecord(course, PokeathlonSave_dummy2(pokeathlon));
            if (!Save_VarsFlags_CheckFlagInArray(varsFlags, FLAG_UNK_0EF) && PokeathlonCourse_HasAllCourseRecords(PokeathlonSave_dummy2(pokeathlon))) {
                Save_VarsFlags_SetFlagInArray(varsFlags, FLAG_UNK_0EF);
            }
        }
        PokeathlonCourse_SaveSoloEventRecords(course, (PokeathlonCourseEventRecord *)PokeathlonSave_GetRecordsSolo2(pokeathlon));
    }
    PokeathlonCourse_SaveStatistics(course, PokeathlonSave_GetStatistics2(pokeathlon));
    if (course->args->mode == POKEATHLON_COURSE_MODE_SOLO && !Save_VarsFlags_CheckFlagInArray(varsFlags, FLAG_UNK_0F1) && PokeathlonCourse_BeatsAllEventTargets(course)) {
        Save_VarsFlags_SetFlagInArray(varsFlags, FLAG_UNK_0F1);
    }
    course->args->totalPoints = results->totalPoints;
    course->args->points = points;
    course->args->rank = results->rank;
}

// Saves the course's best total (after a win) with the round points and the three Pokemon.
static void PokeathlonCourse_SaveCourseRecord(PokeathlonCourseData *course, PokeathlonSave *pokeathlon) {
    u8 courseId = course->args->course;
    PokeathlonCourseBestRecord *record = (PokeathlonCourseBestRecord *)pokeathlon + courseId;
    u16 total = course->results.totalPoints;
    int i;
    PokeathlonCourseMon *mon;

    if (total <= record->totalPoints) {
        return;
    }
    record->totalPoints = total;
    if (record->totalPoints > POKEATHLON_POINTS_MAX) {
        record->totalPoints = POKEATHLON_POINTS_MAX;
    }
    for (i = 0; i < POKEATHLON_SOLO_ROUNDS; i++) {
        record->roundPoints[i] = course->results.eventPoints[0][i];
        if (record->roundPoints[i] > POKEATHLON_POINTS_MAX) {
            record->roundPoints[i] = POKEATHLON_POINTS_MAX;
        }
    }
    mon = PokeathlonCourse_GetParticipantMons(course, PokeathlonCourse_GetNetId(course));
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        record->mons[i].species = mon[i].species;
        record->mons[i].form = mon[i].form;
        record->mons[i].gender = mon[i].gender;
        record->mons[i].isShiny = mon[i].isShiny;
        record->mons[i].personality = mon[i].personality;
    }
}

// Solo: counts the plays of each event and adds the player's result to the event's top 5.
static void PokeathlonCourse_SaveSoloEventRecords(PokeathlonCourseData *course, PokeathlonCourseEventRecord *records) {
    PokeathlonCourseRankEntry entry;
    PokeathlonCourseRankEntry top[POKEATHLON_RECORD_RANKS];
    for (u8 i = 0; i < POKEATHLON_SOLO_ROUNDS; i++) {
        u8 event = course->roundEvents[i];
        PokeathlonCourseEventRecord *record = &records[event];
        if (record->timesPlayed < POKEATHLON_STATISTIC_MAX) {
            record->timesPlayed++;
        }
        int order = gPokeathlonEventScoreOrders[event];
        for (u8 j = 0; j < POKEATHLON_RECORD_RANKS; j++) {
            top[j].score = record->top[j].score;
            for (u8 k = 0; k < POKEATHLON_TEAM_SIZE; k++) {
                top[j].mons[k] = record->top[j].team.mons[k];
            }
        }
        entry.score = course->results.eventScores[(u8)PokeathlonCourse_GetNetId(course)][i];
        u8 netId = PokeathlonCourse_GetNetId(course);
        PokeathlonCourseMon *mons = course->participants[netId].mons;
        for (u8 j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            entry.mons[j] = (mons[j].form << 10) + mons[j].species;
        }
        PokeathlonCourse_InsertRankEntry(order, &entry, top);
        PokeathlonCourse_CopySoloRanking(course, record, top);
    }
}

static inline void CopyRankEntryTrainer(PokeathlonCourseRankEntry *dest, PokeathlonCourseLinkEventRecord *record, u8 j) {
    u8 k;
    dest->trainerId = record->trainers[j].trainerId;
    for (k = 0; k < PLAYER_NAME_LENGTH + 1; k++) {
        dest->name[k] = record->trainers[j].name[k];
    }
    dest->language = record->trainers[j].language;
}

// Link: counts the plays of each event and adds every player's result (with their name) to the event's top 5.
static void PokeathlonCourse_SaveLinkEventRecords(PokeathlonCourseData *course, PokeathlonCourseLinkEventRecord *records) {
    u8 i, j, k, n;
    u8 event;
    u32 order;
    PokeathlonCourseLinkEventRecord *record;
    PokeathlonCourseRankEntry top[POKEATHLON_RECORD_RANKS], entry;
    s32 firstNetId = (u8)PokeathlonCourse_GetNetId(course);
    for (i = 0; i < POKEATHLON_LINK_ROUNDS; i++) {
        event = course->roundEvents[i];
        record = &records[event];
        if (record->timesPlayed < POKEATHLON_STATISTIC_MAX) {
            record->timesPlayed++;
        }
        order = gPokeathlonEventScoreOrders[event];
        for (j = 0; j < POKEATHLON_RECORD_RANKS; j++) {
            top[j].score = record->top[j].score;
            for (k = 0; k < POKEATHLON_TEAM_SIZE; k++) {
                top[j].mons[k] = record->top[j].team.mons[k];
            }
            CopyRankEntryTrainer(&top[j], record, j);
        }
        for (n = 0; n < POKEATHLON_PARTICIPANTS; n++) {
            u8 netId = (firstNetId + n) % POKEATHLON_PARTICIPANTS;
            PokeathlonCourseMon *mons;
            PlayerProfile *profile;
            entry.score = course->results.eventScores[netId][i];
            mons = course->participants[netId].mons;
            for (k = 0; k < POKEATHLON_TEAM_SIZE; k++) {
                entry.mons[k] = (mons[k].form << 10) + mons[k].species;
            }
            profile = PokeathlonCourse_GetPlayerProfileFromData(course, netId);
            entry.trainerId = PlayerProfile_GetTrainerID(profile);
            {
                const u16 *name = PlayerProfile_GetNamePtr(profile);
                for (k = 0; k < PLAYER_NAME_LENGTH + 1; k++) {
                    entry.name[k] = name[k];
                }
            }
            entry.language = PlayerProfile_GetLanguage(profile);
            PokeathlonCourse_InsertRankEntry(order, &entry, top);
        }
        PokeathlonCourse_CopyLinkRanking(course, record, top);
    }
}

// Solo: keeps the player's points of each event whose result beats the event's record (bests[event]).
static void PokeathlonCourse_SaveSoloEventBests(PokeathlonCourseData *course, Pokeathlon_RecordsSolo *records, u16 *bests) {
    u8 i;
    u8 event;

    for (i = 0; i < POKEATHLON_SOLO_ROUNDS; i++) {
        event = course->roundEvents[i];
        if (PokeathlonCourse_BeatsRecord(records[event].entries[0].score, course->results.eventScores[0][i], gPokeathlonEventScoreOrders[event])) {
            bests[event] = course->results.eventPoints[0][i];
        }
    }
}

// Inserts entry into the sorted top 5 if it beats the last one.
static void PokeathlonCourse_InsertRankEntry(u32 order, PokeathlonCourseRankEntry *entry, PokeathlonCourseRankEntry *top) {
    int i;
    PokeathlonCourseRankEntry *slot;
    PokeathlonCourseRankEntry temp;
    if (PokeathlonCourse_BeatsRecord(top[POKEATHLON_RECORD_RANKS - 1].score, entry->score, order)) {
        top[POKEATHLON_RECORD_RANKS - 1] = *entry;
        for (i = POKEATHLON_RECORD_RANKS - 1, slot = &top[POKEATHLON_RECORD_RANKS - 1]; i > 0; i--, slot--) {
            if (!PokeathlonCourse_BeatsRecord(slot[-1].score, slot->score, order)) {
                return;
            }
            temp = slot[-1];
            slot[-1] = *slot;
            *slot = temp;
        }
    }
}

static void PokeathlonCourse_CopySoloRanking(PokeathlonCourseData *course, PokeathlonCourseEventRecord *record, PokeathlonCourseRankEntry *top) {
    int i;
    int j;
    PokeathlonCourse_GetNetId(course);
    for (i = 0; i < POKEATHLON_RECORD_RANKS; i++) {
        record->top[i].score = top[i].score;
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            record->top[i].team.mons[j] = top[i].mons[j];
        }
    }
}

static void PokeathlonCourse_CopyLinkRanking(PokeathlonCourseData *course, PokeathlonCourseLinkEventRecord *record, PokeathlonCourseRankEntry *top) {
    int i = 0;
    int j;
    for (; i < POKEATHLON_RECORD_RANKS; i++) {
        record->top[i].score = top[i].score;
        for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
            record->top[i].team.mons[j] = top[i].mons[j];
        }
        record->trainers[i].trainerId = top[i].trainerId;
        {
            int k = 0;
            for (; k < PLAYER_NAME_LENGTH + 1; k++) {
                record->trainers[i].name[k] = top[i].name[k];
            }
        }
        record->trainers[i].language = top[i].language;
    }
}

// Whether score beats record (POKEATHLON_NO_RECORD: no record yet) in the event's order.
static BOOL PokeathlonCourse_BeatsRecord(int record, int score, u32 order) {
    if (record == POKEATHLON_NO_RECORD) {
        return TRUE;
    }
    return PokeathlonCourse_BeatsRecordInOrder(record, score, order);
}

// Order 0: higher scores are better, order 1: lower ones (times); POKEATHLON_NO_RECORD is no record.
static BOOL PokeathlonCourse_BeatsRecordInOrder(int record, int score, u32 order) {
    BOOL better = FALSE;
    if (order == 0) {
        if (record == POKEATHLON_NO_RECORD) {
            better = TRUE;
        } else if (record < score) {
            better = TRUE;
        }
    } else if (order == 1) {
        if (record == POKEATHLON_NO_RECORD) {
            better = TRUE;
        } else if (record > score) {
            better = TRUE;
        }
    } else {
        GF_ASSERT(FALSE);
    }
    return better;
}

static inline void AddToStatistic(u32 amount, u32 *counter) {
    PokeathlonCourse_AddCapped(amount, POKEATHLON_STATISTIC_MAX, (PokeathlonStatistics *)counter);
}

static inline void AddCountersToStatistics(const u32 *counters, PokeathlonStatistics *statistics) {
    AddToStatistic(counters[0], &statistics->monFailures);
    AddToStatistic(counters[1], &statistics->monJumps);
    AddToStatistic(counters[2], &statistics->monPointsEarned);
    AddToStatistic(counters[3], &statistics->monTackles);
    AddToStatistic(counters[4], &statistics->monFalls);
    AddToStatistic(counters[5], &statistics->monDashes);
    AddToStatistic(counters[6], &statistics->monSwitches);
    AddToStatistic(counters[7], &statistics->monSelfImpedes);
}

// Adds the course to the saved statistics (courses played / won, rounds won, the Pokemon's counters).
static void PokeathlonCourse_SaveStatistics(PokeathlonCourseData *course, PokeathlonStatistics *statistics) {
    u32 netId;
    PokeathlonCourseResults *results = &course->results;
    u8 i;
    u8 j;
    u32 *counters;
    netId = (u8)PokeathlonCourse_GetNetId(course);
    if (course->args->mode == POKEATHLON_COURSE_MODE_LINK) {
        AddToStatistic(1, &statistics->linkCoursesJoined);
        if (results->wonCourse) {
            AddToStatistic(1, &statistics->linkCourseFirstPlaces);
            PokeathlonCourse_SaveFriendshipStatues(course);
        } else if (results->lastInCourse) {
            AddToStatistic(1, &statistics->linkCourseLastPlaces);
        }
    } else {
        AddToStatistic(1, &statistics->coursesJoined);
        if (results->wonCourse) {
            AddToStatistic(1, &statistics->courseFirstPlaces);
            PokeathlonCourse_SaveFriendshipStatues(course);
        } else if (results->lastInCourse) {
            AddToStatistic(1, &statistics->courseLastPlaces);
        }
    }
    for (i = 0; i < course->rounds; i++) {
        if (results->wonRound[i]) {
            AddToStatistic(1, &statistics->eventFirstPlaces[(u8)course->roundEvents[i]]);
        } else if (results->lastInRound[i]) {
            AddToStatistic(1, &statistics->eventLastPlaces);
        }
    }
    for (j = 0; j < POKEATHLON_TEAM_SIZE; j++) {
        counters = results->counters[netId][j];
        AddCountersToStatistics(counters, statistics);
    }
    AddToStatistic(results->bonuses, &statistics->bonusesEarned);
    AddToStatistic(results->instructions, &statistics->monInstructions);
}

// The player's three Pokemon become the statues of the Friendship Room.
static void PokeathlonCourse_SaveFriendshipStatues(PokeathlonCourseData *course) {
    u8 i;
    PokeathlonSave_FriendshipRecords *records = Save_Pokeathlon_FriendshipRecords_Get(course->args->saveData);
    u8 netId = PokeathlonCourse_GetNetId(course);
    PokeathlonCourseMon *mons = course->participants[netId].mons;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        records->friendshipRoomStatues[i].species = mons[i].species;
        records->friendshipRoomStatues[i].form = mons[i].form;
        records->friendshipRoomStatues[i].gender = mons[i].gender;
    }
}

void PokeathlonCourse_AddCapped(s32 frameCount, u32 maxValue, PokeathlonStatistics *result) {
    if (result->playTime + frameCount > maxValue) {
        result->playTime = maxValue;
    } else {
        result->playTime += frameCount;
    }
}

// Gives the player's Pokemon the medal of the course.
static void PokeathlonCourse_SetCourseMedals(PokeathlonCourseData *course) {
    switch (course->args->course) {
    case POKEATHLON_COURSE_SPEED:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_SPEED);
        break;
    case POKEATHLON_COURSE_POWER:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_POWER);
        break;
    case POKEATHLON_COURSE_SKILL:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_SKILL);
        break;
    case POKEATHLON_COURSE_STAMINA:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_STAMINA);
        break;
    case POKEATHLON_COURSE_JUMP:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_JUMP);
        break;
    case POKEATHLON_COURSE_LINK_SPEED_JUMP:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_SPEED | POKEATHLON_MEDAL_JUMP);
        break;
    case POKEATHLON_COURSE_LINK_SKILL_JUMP:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_SKILL | POKEATHLON_MEDAL_JUMP);
        break;
    case POKEATHLON_COURSE_LINK_POWER_SKILL:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_POWER | POKEATHLON_MEDAL_SKILL);
        break;
    case POKEATHLON_COURSE_LINK_POWER_STAMINA:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_POWER | POKEATHLON_MEDAL_STAMINA);
        break;
    case POKEATHLON_COURSE_LINK_SPEED_STAMINA:
        PokeathlonCourse_SetMonMedals(course, POKEATHLON_MEDAL_SPEED | POKEATHLON_MEDAL_STAMINA);
        break;
    }
}

static void PokeathlonCourse_SetMonMedals(PokeathlonCourseData *course, u32 medals) {
    PokeathlonSave *pokeathlon = Save_Pokeathlon_Get(course->args->saveData);
    u8 i;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        PokeathlonSave_AddMonMedals(pokeathlon, medals, course->localParticipant.mons[i].species);
    }
}

// Whether every one of the first 5 courses has a saved record.
static BOOL PokeathlonCourse_HasAllCourseRecords(PokeathlonSave *pokeathlon) {
    PokeathlonCourseBestRecord *records = (PokeathlonCourseBestRecord *)pokeathlon;
    u8 i;
    for (i = 0; i < POKEATHLON_SOLO_COURSES; i++) {
        if (records[i].totalPoints == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

// Whether one of the player's Pokemon has all 5 medals.
static BOOL PokeathlonCourse_HasAllMedalsOfAMon(PokeathlonCourseData *course) {
    PokeathlonSave *pokeathlon = Save_Pokeathlon_Get(course->args->saveData);
    u8 i;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        u32 index = course->localParticipant.mons[i].species - 1;
        u8 *medals = PokeathlonSave_GetMonMedals(pokeathlon);
        if (medals[index] == POKEATHLON_MEDALS_ALL) {
            return TRUE;
        }
    }
    return FALSE;
}

// Whether the solo record of every event beats the event's target.
static BOOL PokeathlonCourse_BeatsAllEventTargets(PokeathlonCourseData *course) {
    u8 i;
    Pokeathlon_RecordsSolo *records = PokeathlonSave_GetRecordsSolo2(Save_Pokeathlon_Get(course->args->saveData));
    for (i = 0; i < POKEATHLON_EVENT_COUNT; i++) {
        u16 record = records[i].entries[0].score;
        if (record == POKEATHLON_NO_RECORD) {
            return FALSE;
        }
        if (!PokeathlonCourse_BeatsRecordInOrder(gPokeathlonEventTargetScores[i], record, gPokeathlonEventScoreOrders[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

// The events of the course's rounds (course 10 picks one of 10 sets at random).
static void PokeathlonCourse_ChooseEvents(PokeathlonCourseArgs *args, u32 rounds, u8 *eventIds) {
    u8 courseId;
    BOOL valid = FALSE;
    eventIds[0] = 10;
    courseId = args->course;
    if (args->mode == POKEATHLON_COURSE_MODE_LINK) {
        switch (courseId) {
        case POKEATHLON_COURSE_LINK_SPEED_JUMP:
        case POKEATHLON_COURSE_LINK_SKILL_JUMP:
        case POKEATHLON_COURSE_LINK_POWER_SKILL:
        case POKEATHLON_COURSE_LINK_POWER_STAMINA:
        case POKEATHLON_COURSE_LINK_SPEED_STAMINA:
        case POKEATHLON_COURSE_LINK_RANDOM:
            valid = TRUE;
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
    } else {
        switch (courseId) {
        case POKEATHLON_COURSE_SPEED:
        case POKEATHLON_COURSE_POWER:
        case POKEATHLON_COURSE_SKILL:
        case POKEATHLON_COURSE_STAMINA:
        case POKEATHLON_COURSE_JUMP:
            valid = TRUE;
            break;
        default:
            GF_ASSERT(FALSE);
            break;
        }
    }
    if (valid) {
        u8 i;
        if (courseId == POKEATHLON_COURSE_LINK_RANDOM) {
            u8 set = LCRandom() % POKEATHLON_RANDOM_EVENT_SETS;
            for (i = 0; i < rounds; i++) {
                eventIds[i] = gPokeathlonCourse10EventSets[set][i];
            }
        } else {
            for (i = 0; i < rounds; i++) {
                eventIds[i] = gPokeathlonCourseEventIds[courseId][i];
            }
        }
    }
}

// Keeps a marker over its Pokemon, shown while the Pokemon is.
static void PokeathlonCourse_MarkerTask(SysTask *task, void *data) {
    PokeathlonCourseMarker *marker = data;
    s32 x;
    s32 y;
    VecFx32 position;
    PokeathlonCourseMonObject_GetPosition(marker->object, &x, &y);
    Sprite_SetDrawFlag(marker->sprite, TRUE);
    position.z = 0;
    position.x = x << FX32_SHIFT;
    position.y = y << FX32_SHIFT;
    Sprite_SetMatrix(marker->sprite, &position);
    if (PokeathlonCourseObject_IsDrawn(marker->object)) {
        Sprite_SetDrawFlag(marker->sprite, TRUE);
    } else {
        Sprite_SetDrawFlag(marker->sprite, FALSE);
    }
}

// Adds to a counter of a participant's Pokemon (counter 0: the course's own count). On the host the counters
// of every participant are kept; the others keep only their own, which they send at the end.
void PokeathlonCourse_AddMonCounter(PokeathlonCourseData *course, u8 participant, u8 mon, enum PokeathlonMonCounter counter, int amount) {
    if (counter == POKEATHLON_COUNTER_INSTRUCTIONS) {
        GF_ASSERT(participant == PokeathlonCourse_GetNetId(course));
        GF_ASSERT(amount == 1);
        if (course->results.instructions < POKEATHLON_MON_COUNTER_MAX) {
            course->results.instructions++;
        }
    } else {
        GF_ASSERT(mon < POKEATHLON_TEAM_SIZE);
        if (!course->event->sendsOwnResult) {
            GF_ASSERT(PokeathlonCourse_GetNetId(course) == 0);
            PokeathlonCourse_AddToCounter(counter, (u8)amount, course->results.counters[participant][mon]);
        } else if (PokeathlonCourse_GetNetId(course) == 0) {
            if (participant >= PokeathlonCourse_GetParticipantCount(course)) {
                PokeathlonCourse_AddToCounter(counter, (u8)amount, course->results.counters[participant][mon]);
            } else {
                GF_ASSERT(participant == PokeathlonCourse_GetNetId(course));
                PokeathlonCourse_AddToCounter(counter, (u8)amount, course->localCounters[mon]);
            }
        } else {
            GF_ASSERT(participant == PokeathlonCourse_GetNetId(course));
            PokeathlonCourse_AddToCounter(counter, (u8)amount, course->localCounters[mon]);
        }
    }
}

void PokeathlonCourse_SetRecordScore(PokeathlonCourseData *course, u16 score) {
    course->recordScore = score;
}

void PokeathlonCourse_SetFinishCallback(PokeathlonCourseData *course, PokeathlonCourseFinishFunc callback) {
    GF_ASSERT(course->finishCallback == NULL);
    course->finishCallback = callback;
}

static void PokeathlonCourse_AddToCounter(u32 counter, u32 amount, u32 *counters) {
    u32 *value;
    switch (counter) {
    case POKEATHLON_COUNTER_FAILURES:
        value = counters;
        break;
    case POKEATHLON_COUNTER_JUMPS:
        value = counters + 1;
        break;
    case POKEATHLON_COUNTER_POINTS:
        value = counters + 2;
        break;
    case POKEATHLON_COUNTER_TACKLES:
        value = counters + 3;
        break;
    case POKEATHLON_COUNTER_FALLS:
        value = counters + 4;
        break;
    case POKEATHLON_COUNTER_DASHES:
        value = counters + 5;
        break;
    case POKEATHLON_COUNTER_SWITCHES:
        value = counters + 6;
        break;
    case POKEATHLON_COUNTER_SELF_IMPEDES:
        value = counters + 7;
        break;
    default:
        GF_ASSERT(FALSE);
        return;
    }
    *value += amount;
    if (*value > POKEATHLON_MON_COUNTER_MAX) {
        *value = POKEATHLON_MON_COUNTER_MAX;
    }
}

// Whether the event result (recordScore) beats the saved record of the event.
static BOOL PokeathlonCourse_IsNewRecord(PokeathlonCourseData *course) {
    PokeathlonSave *pokeathlon = Save_Pokeathlon_Get(course->args->saveData);
    u32 event;
    PokeathlonEventRecordEntry *record;
    u16 value;
    if (course->recordScore == POKEATHLON_NO_RECORD) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    event = PokeathlonCourse_GetCurrentEvent(course);
    if (course->args->mode == POKEATHLON_COURSE_MODE_LINK) {
        record = PokeathlonSave_GetRecordsLink2(pokeathlon)[event].entries;
    } else {
        record = PokeathlonSave_GetRecordsSolo2(pokeathlon)[event].entries;
    }
    value = record->score;
    if (value == POKEATHLON_NO_RECORD) {
        return TRUE;
    }
    if (gPokeathlonEventScoreOrders[event] == 0) {
        if (value < course->recordScore) {
            return TRUE;
        }
    } else if (value > course->recordScore) {
        return TRUE;
    }
    return FALSE;
}

u16 PokeathlonCourse_GetNpcTeamSpriteId(u32 npcTeam) {
    if (npcTeam != 0 && npcTeam <= POKEATHLON_NPC_TEAMS) {
        return gPokeathlonNpcTeamSpriteIds[(u8)(npcTeam - 1)];
    }
    GF_ASSERT(FALSE);
    return 0;
}

u8 PokeathlonCourse_GetNpcTeamMsgId(PokeathlonCourseData *course, u32 npcTeam) {
    PokeathlonCourseNpcTeam team;
    NARC *narc;
    if (npcTeam != 0 && npcTeam <= POKEATHLON_NPC_TEAMS) {
        narc = NARC_New(NARC_a_2_5_8, PokeathlonCourse_GetHeapID(course));
        NARC_ReadWholeMember(narc, npcTeam - 1, &team);
        NARC_Delete(narc);
        return team.msgId;
    }
    GF_ASSERT(FALSE);
    return 0;
}

// Fills the last count participant slots with NPC teams (NARC a/2/5/8, names from msg 310).
void PokeathlonCourse_SetupNpcParticipants(PokeathlonCourseData *course, int count) {
    PokeathlonCoursePerformance performance;
    u8 npcTeams[POKEATHLON_PARTICIPANTS - 1];
    PokeathlonCourseNpcTeam team;
    String *speciesName;
    int j;
    int k;
    MsgData *msgData;
    NARC *performanceNarc;
    NARC *teamNarc;
    s32 i;
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0310_bin, PokeathlonCourse_GetHeapID(course));
    i = POKEATHLON_PARTICIPANTS - count;
    PokeathlonCourse_ChooseNpcTeams(count, course->args->course, course->args->isSupreme, npcTeams);
    performanceNarc = NARC_New(NARC_poketool_personal_performance, PokeathlonCourse_GetHeapID(course));
    teamNarc = NARC_New(NARC_a_2_5_8, PokeathlonCourse_GetHeapID(course));
    for (j = 0; i < POKEATHLON_PARTICIPANTS; i++, j++) {
        PokeathlonCourseParticipant *participant = PokeathlonCourse_GetParticipantData(course, i);
        String *name;
        participant->npcTeam = npcTeams[j];
        GF_ASSERT(participant->npcTeam != 0);
        NARC_ReadWholeMember(teamNarc, participant->npcTeam - 1, &team);
        name = NewString_ReadMsgData(msgData, team.nameId);
        Save_Profile_PlayerName_Set(PokeathlonCourse_GetPlayerProfileFromData(course, i), String_cstr(name));
        String_Delete(name);
        for (k = 0; k < POKEATHLON_TEAM_SIZE; k++) {
            u8 gender;
            participant->mons[k].species = team.species[k];
            participant->mons[k].form = 0;
            participant->mons[k].isShiny = FALSE;
            participant->mons[k].personality = 0;
            switch ((u8)GetMonBaseStat(participant->mons[k].species, BASE_GENDER_RATIO)) {
            case MON_RATIO_MALE:
                gender = MON_MALE;
                break;
            case MON_RATIO_FEMALE:
                gender = MON_FEMALE;
                break;
            case MON_RATIO_UNKNOWN:
                gender = MON_GENDERLESS;
                break;
            default:
                gender = MON_MALE;
                break;
            }
            participant->mons[k].gender = gender;
            NARC_ReadWholeMember(performanceNarc, PokeathlonCourse_GetPerformanceFileId(participant->mons[k].species, 0), &performance);
            participant->mons[k].stats[0] = performance.stats[0];
            participant->mons[k].stats[1] = performance.stats[1];
            participant->mons[k].stats[2] = performance.stats[2];
            participant->mons[k].stats[3] = performance.stats[3];
            participant->mons[k].stats[4] = performance.stats[4];
            speciesName = GetSpeciesName(team.species[k], PokeathlonCourse_GetHeapID(course));
            CopyU16StringArrayN(participant->mons[k].nickname, String_cstr(speciesName), POKEMON_NAME_LENGTH + 1);
            String_Delete(speciesName);
        }
    }
    NARC_Delete(teamNarc);
    NARC_Delete(performanceNarc);
    DestroyMsgData(msgData);
}

// Picks count different NPC teams: 5 per course (courses 0..9) or any of 25 (course 10); hard ones are 50 later.
static void PokeathlonCourse_ChooseNpcTeams(u32 count, u8 courseId, u32 hard, u8 *npcTeams) {
    u8 coursePool[POKEATHLON_NPC_TEAMS_PER_COURSE];
    u8 linkPool[POKEATHLON_NPC_TEAMS_LINK];
    u8 i;
    for (i = 0; i < POKEATHLON_PARTICIPANTS - 1; i++) {
        npcTeams[i] = 0;
    }
    if (courseId == POKEATHLON_COURSE_LINK_RANDOM) {
        u8 remaining = POKEATHLON_NPC_TEAMS_LINK;
        for (i = 0; i < POKEATHLON_NPC_TEAMS_LINK; i++) {
            linkPool[i] = i;
        }
        for (i = 0; i < count; i++) {
            u8 at = LCRandom() % remaining;
            npcTeams[i] = linkPool[at];
            npcTeams[i] += POKEATHLON_NPC_TEAMS_LINK_START;
            remaining--;
            linkPool[at] = linkPool[remaining];
        }
    } else {
        u8 remaining = POKEATHLON_NPC_TEAMS_PER_COURSE;
        for (i = 0; i < POKEATHLON_NPC_TEAMS_PER_COURSE; i++) {
            coursePool[i] = i;
        }
        for (i = 0; i < count; i++) {
            u8 at = LCRandom() % remaining;
            npcTeams[i] = coursePool[at];
            npcTeams[i] += courseId * POKEATHLON_NPC_TEAMS_PER_COURSE;
            remaining--;
            coursePool[at] = coursePool[remaining];
        }
    }
    if (hard) {
        for (i = 0; i < count; i++) {
            npcTeams[i] += POKEATHLON_NPC_TEAMS_HARD_START;
        }
    }
    for (i = 0; i < count; i++) {
        npcTeams[i]++;
    }
}

void *PokeathlonCourse_GetJuiceRecord(PokeathlonCourseData *course, u32 index) {
    u32 size;
    GF_ASSERT(index < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(course->playerJuiceRecords != NULL);
    size = ApricornJuiceRecord_sizeof();
    return (u8 *)course->playerJuiceRecords + size * index;
}

// Whether (x, y) lies within range of (targetX, targetY); the distance goes to *distance.
BOOL PokeathlonCourse_IsInRange(int x, int y, int targetX, int targetY, int range, int *distance) {
    VecFx32 position;
    VecFx32 target;
    position.x = x << FX32_SHIFT;
    position.y = y << FX32_SHIFT;
    position.z = 0;
    target.x = targetX << FX32_SHIFT;
    target.y = targetY << FX32_SHIFT;
    target.z = 0;
    VecFx32 delta;
    VEC_Subtract(&position, &target, &delta);
    {
        fx32 magnitude = VEC_Mag(&delta);
        *distance = magnitude;
        if (magnitude < (range << FX32_SHIFT)) {
            return TRUE;
        }
        return FALSE;
    }
}

// Creates the link of the course: the wireless command table (link mode) or a local command queue.
PokeathlonCourseLink *PokeathlonCourseLink_New(const void *commands, int count, PokeathlonCourseData *data, BOOL isLink, enum HeapID heapId) {
    PokeathlonCourseLink *link = Heap_Alloc(heapId, sizeof(PokeathlonCourseLink));
    link->isLink = isLink;
    link->checkSize = FALSE;
    link->queue = NULL;
    if (isLink == TRUE) {
        Comm_RegisterCommandTable(commands, count, data);
    } else {
        link->queue = PokeathlonCourseCmdQueue_New(commands, count, data, heapId);
    }
    return link;
}

void PokeathlonCourseLink_SetCheckSize(PokeathlonCourseLink *link, u16 checkSize) {
    link->checkSize = checkSize;
}

BOOL PokeathlonCourseLink_SendCommand(int command, void *data, int size, PokeathlonCourseLink *linkArg) {
    PokeathlonCourseLink *link = linkArg;
    GF_ASSERT(!link->checkSize || size <= POKEATHLON_COURSE_CMD_INLINE_SIZE);
    if (link->isLink == 1) {
        return Comm_SendCommand(command, data, size);
    } else {
        // BUG: nothing is returned here, although the callers use the result.
        PokeathlonCourseCmdQueue_Add(link->queue, command, data, size);
    }
}

static BOOL PokeathlonCourseLink_SendLargeCommand(int cmd, void *data, int size, PokeathlonCourseLink *link) {
    if (link->isLink == 1) {
        return Comm_SendCommandNoCopy(cmd, data, size);
    } else {
        // BUG: nothing is returned here, although the callers use the result.
        PokeathlonCourseCmdQueue_AddLarge(link->queue, cmd, data, size);
    }
}

void PokeathlonCourseLink_Free(PokeathlonCourseLink *link) {
    if (!link->isLink) {
        PokeathlonCourseCmdQueue_Free(link->queue);
    }
    Heap_Free(link);
}

int PokeathlonCourseLink_GetNetId(PokeathlonCourseLink *link) {
    if (link->isLink == 1) {
        return Comm_GetLocalNetId();
    }
    return 0;
}

static PokeathlonCourseCmdQueue *PokeathlonCourseCmdQueue_New(const PokeathlonCourseCmd *cmds, int cmdCount, PokeathlonCourseData *context, enum HeapID heapId) {
    PokeathlonCourseCmdQueue *queue = Heap_Alloc(heapId, sizeof(PokeathlonCourseCmdQueue));
    memset(queue, 0, sizeof(PokeathlonCourseCmdQueue));
    queue->cmds = cmds;
    queue->cmdCount = cmdCount;
    queue->context = context;
    queue->task = SysTask_CreateOnVWaitQueue(PokeathlonCourseCmdQueue_Task, queue, 5000);
    return queue;
}

// Runs the queued commands (in VBlank, as received link commands would be).
static void PokeathlonCourseCmdQueue_Task(SysTask *task, void *data) {
    PokeathlonCourseCmdQueue *queue = data;
    int i;
    for (i = 0; i < POKEATHLON_COURSE_CMD_SLOTS; i++) {
        PokeathlonCourseCmdSlot *slot = &queue->slots[i];
        if (slot->active == 1) {
            if (slot->size <= POKEATHLON_COURSE_CMD_INLINE_SIZE) {
                queue->cmds[slot->cmd].func(0, slot->size, slot->data, queue->context);
            } else {
                queue->cmds[slot->cmd].func(0, slot->size, slot->buffer, queue->context);
            }
            memset(slot, 0, sizeof(PokeathlonCourseCmdSlot));
        }
    }
}

static void PokeathlonCourseCmdQueue_Free(PokeathlonCourseCmdQueue *queue) {
    SysTask_Destroy(queue->task);
    Heap_Free(queue);
}

// Queues a command whose data (at most POKEATHLON_COURSE_CMD_INLINE_SIZE bytes) is copied into the slot.
static void PokeathlonCourseCmdQueue_Add(PokeathlonCourseCmdQueue *queue, u32 cmd, void *data, s32 size) {
    int i;
    PokeathlonCourseCmdSlot *slot = NULL;
    for (i = 0; i < POKEATHLON_COURSE_CMD_SLOTS; i++) {
        if (!queue->slots[i].active) {
            slot = &queue->slots[i];
            break;
        }
    }
    GF_ASSERT(slot != NULL);
    cmd -= POKEATHLON_COURSE_CMD_FIRST;
    if (queue->cmds[cmd].getSize != NULL) {
        u32 expected = queue->cmds[cmd].getSize();
        GF_ASSERT(expected == size);
    }
    GF_ASSERT(size <= POKEATHLON_COURSE_CMD_INLINE_SIZE);
    slot->cmd = cmd;
    if (size > 0) {
        memcpy(slot->data, data, size);
    }
    slot->size = size;
    slot->active = TRUE;
}

// Queues a command whose data goes to the command's buffer (or is used in place if it has none).
static void PokeathlonCourseCmdQueue_AddLarge(PokeathlonCourseCmdQueue *queue, u32 cmd, void *data, s32 size) {
    int i;
    PokeathlonCourseCmdSlot *slot = NULL;
    u32 expected;
    for (i = 0; i < POKEATHLON_COURSE_CMD_SLOTS; i++) {
        if (!queue->slots[i].active) {
            slot = &queue->slots[i];
            break;
        }
    }
    GF_ASSERT(slot != NULL);
    cmd -= POKEATHLON_COURSE_CMD_FIRST;
    expected = queue->cmds[cmd].getSize();
    GF_ASSERT(expected == 0xFFFF || expected == size);
    if (queue->cmds[cmd].getBuffer != NULL) {
        void *buffer = queue->cmds[cmd].getBuffer(0, queue->context, size);
        if (size > 0) {
            memcpy(buffer, data, size);
        }
        slot->buffer = buffer;
    } else {
        slot->buffer = data;
    }
    slot->cmd = cmd;
    slot->size = size;
    slot->active = TRUE;
}

u8 *PokeathlonCourse_ToBytes(void *ptr) {
    return ptr;
}

const void *PokeathlonCourseCmd_GetTable(void) {
    return gPokeathlonCourseCmds;
}

int PokeathlonCourseCmd_GetCount(void) {
    return NELEMS(gPokeathlonCourseCmds);
}

// Allocates the Pokemon sprite manager (PokeathlonCourseMonGfx_InitManager sets it up).
PokeathlonCourseMonGfxManager *PokeathlonCourseMonGfx_AllocManager(enum HeapID heapId) {
    PokeathlonCourseMonGfxManager *manager = Heap_Alloc(heapId, sizeof(PokeathlonCourseMonGfxManager));
    manager->heapId = heapId;
    return manager;
}
