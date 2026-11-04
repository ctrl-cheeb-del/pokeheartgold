#include "pokeathlon/pokeathlon_ring_drop.h"

#include "global.h"

#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_event_points.h"
#include "pokeathlon/pokeathlon_ring_drop_cpu.h"

#include "assert.h"
#include "bg_window.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "screen_fade.h"
#include "sys_task_api.h"
#include "system.h"
#include "touchscreen.h"
#include "wireless_status_icon.h"

enum {
    RING_DROP_STATE_FADE_IN,
    RING_DROP_STATE_PLAY,
    RING_DROP_STATE_FINISH,
};

enum PokeathlonRingDropStartState {
    RING_DROP_START_FADE_IN,
    RING_DROP_START_WAIT_FADE_IN,
    RING_DROP_START_COUNTDOWN,
};

enum PokeathlonRingDropPlayState {
    RING_DROP_PLAY_RUN,
    RING_DROP_PLAY_FINISH,
};

enum PokeathlonRingDropInitState {
    RING_DROP_INIT_CREATE,
    RING_DROP_INIT_LOAD_BGS,
    RING_DROP_INIT_WAIT_MONS,
    RING_DROP_INIT_CREATE_UI,
    RING_DROP_INIT_START,
};

static void PokeathlonRingDrop_SetGfxBanks(void);
static void PokeathlonRingDrop_Update(PokeathlonCourseData *course);
static BOOL PokeathlonRingDrop_ReadInput(PokeathlonCourseData *course);

static BOOL PokeathlonScreenShake_IsDone(PokeathlonScreenShake *shake) {
    GF_ASSERT(shake != NULL);
    return shake->task == NULL;
}

static void PokeathlonScreenShake_Init(PokeathlonScreenShake *shake, BgConfig *bgConfig, SpriteSystem *spriteSystem) {
    shake->bgConfig = bgConfig;
    shake->spriteSystem = spriteSystem;
}

void PokeathlonScreenShake_Start(PokeathlonScreenShake *shake, int magnitude, int duration) {
    GF_ASSERT(shake->bgConfig != NULL);
    GF_ASSERT(shake->spriteSystem != NULL);
    if (shake->task != NULL) {
        SysTask_Destroy(shake->task);
    }
    shake->direction = 0;
    shake->frame = 0;
    shake->duration = duration;
    shake->offset = magnitude << FX32_SHIFT;
    shake->magnitude = magnitude;
    shake->step = FX_Div(magnitude << FX32_SHIFT, duration << FX32_SHIFT);
    shake->task = SysTask_CreateOnMainQueue(PokeathlonScreenShake_Task, shake, 2);
}

BOOL PokeathlonRingDrop_IsOnSwitchButton(int x, int y) {
    return x >= 104 && x < 160 && y >= 0 && y < 32;
}

BOOL PokeathlonRingDrop_IsWithinDistance(VecFx32 *a, VecFx32 *b, fx32 distance) {
    VecFx32 delta;

    VEC_Subtract(b, a, &delta);
    if (VEC_Mag(&delta) <= distance) {
        return TRUE;
    }
    return FALSE;
}

static void PokeathlonRingDrop_Decay(fx32 *value, fx32 amount) {
    if (*value != 0) {
        if ((*value < 0 ? -*value : *value) < amount) {
            *value = 0;
            return;
        }
        *value -= amount * (*value > 0 ? 1 : -1);
    }
}

void PokeathlonRingDrop_DecayVelocity(VecFx32 *velocity, fx32 amountX, fx32 amountY) {
    PokeathlonRingDrop_Decay(&velocity->x, amountX);
    PokeathlonRingDrop_Decay(&velocity->y, amountY);
}

void PokeathlonRingDrop_ClampVelocity(VecFx32 *velocity, fx32 limit) {
    fx32 min = -limit;

    if (velocity->x > 0) {
        if (velocity->x > limit) {
            velocity->x = limit;
        }
    } else if (velocity->x < min) {
        velocity->x = min;
    }
    if (velocity->y > 0) {
        if (velocity->y > limit) {
            velocity->y = limit;
        }
    } else if (velocity->y < min) {
        velocity->y = min;
    }
}

BOOL PokeathlonRingDrop_State_FadeIn(PokeathlonCourseData *course, u8 *state) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case RING_DROP_START_FADE_IN:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 6, 1, ringDrop->heapId);
        (*state)++;
    case RING_DROP_START_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case RING_DROP_START_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            PokeathlonCourse_SetNextState(course, RING_DROP_STATE_PLAY);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

BOOL PokeathlonRingDrop_State_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);

    switch (*state) {
    case RING_DROP_PLAY_RUN:
        PokeathlonRingDrop_Update(course);
        if (PokeathlonRingDrop_ReadInput(course)) {
            (*state)++;
        }
        break;
    case RING_DROP_PLAY_FINISH:
        PokeathlonRingDrop_Update(course);
        if (PokeathlonCourse_RunFinish(course) && PokeathlonScreenShake_IsDone(&ringDrop->shake)) {
            BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, ringDrop->heapId);
            PokeathlonCourse_SetNextState(course, RING_DROP_STATE_FINISH);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

BOOL PokeathlonRingDrop_State_Finish(PokeathlonCourseData *course, u8 *state) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);

    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            if (!PokeathlonCourse_GetNetId(course)) {
                int i;
                for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                    PokeathlonCourse_SetEventScore(course, (u8)i, ringDrop->players[i].mon.flags.bits.score);
                }
            }
            return TRUE;
        }
    } else {
        GF_ASSERT(FALSE);
    }
    return FALSE;
}

BOOL PokeathlonRingDrop_Init(PokeathlonCourseData *course) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);

    switch (PokeathlonCourse_GetEventInitState(course)) {
    case RING_DROP_INIT_CREATE:
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_145, 0x60000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
        PokeathlonRingDrop_SetGfxBanks();
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        ringDrop = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonRingDrop));
        MI_CpuFill8(ringDrop, 0, sizeof(PokeathlonRingDrop));
        ringDrop->heapId = HEAP_ID_145;
        ringDrop->timer = RING_DROP_FRAMES;
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RING_DROP_INIT_LOAD_BGS:
        ringDrop->bgConfig = BgConfig_Alloc(ringDrop->heapId);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG3);
        PokeathlonRingDrop_InitBgs(ringDrop);
        PokeathlonRingDrop_LoadBgGraphics(ringDrop);
        PokeathlonRingDrop_AddScoreWindow(ringDrop);
        PokeathlonRingDrop_InitSprites(ringDrop);
        PokeathlonRingDrop_CreateMonObjects(ringDrop, course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case RING_DROP_INIT_WAIT_MONS:
        if (PokeathlonCourseMonObjects_IsLoaded(ringDrop->monObjects)) {
            PokeathlonRingDrop_LoadSpriteResources(ringDrop);
            Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSprites(course, 0, ringDrop->resources, SpriteManager_GetSpriteList(ringDrop->spriteManager)), 0);
            PokeathlonCourse_AdvanceEventInitState(course);
        }
        break;
    case RING_DROP_INIT_CREATE_UI: {
        u8 participant = PokeathlonCourse_GetNetId(course);
        ringDrop->cpu = PokeathlonRingDropCpu_New(course, ringDrop->heapId);
        ringDrop->ui = PokeathlonRingDropUi_New(ringDrop->spriteSystem, ringDrop->spriteManager, ringDrop->resources, ringDrop->bgConfig, ringDrop->msgData, ringDrop->msgFormat, participant, ringDrop->heapId, course);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    }
    case RING_DROP_INIT_START:
        PokeathlonRingDrop_InitMons(ringDrop, course);
        PokeathlonRingDropUi_Init(ringDrop->ui);
        PokeathlonRingDropDisplay_Init(&ringDrop->display, ringDrop->spriteSystem, ringDrop->spriteManager, ringDrop->ui, ringDrop->monObjects, ringDrop->heapId);
        PokeathlonCourse_SetVBlankIntrCB(ringDrop->bgConfig);
        PokeathlonScreenShake_Init(&ringDrop->shake, ringDrop->bgConfig, ringDrop->spriteSystem);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonRingDropFramePacket *packet = (PokeathlonRingDropFramePacket *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT);
            packet->timer = ringDrop->timer;
            PokeathlonRingDrop_BuildFramePacket(ringDrop->contacts, course);
        }
        WirelessStatusIcon_CreateOnScreenIfConnected(2);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        return TRUE;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

BOOL PokeathlonRingDrop_Draw(PokeathlonCourseData *course) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);

    GF_ASSERT(ringDrop != NULL);
    SpriteSystem_DrawSprites(ringDrop->spriteManager);
    return TRUE;
}

BOOL PokeathlonRingDrop_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *gfx = PokeathlonCourse_GetGraphicsSystem(course);
    int i;

    PokeathlonCourseScoreList_Init(gfx);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, gfx, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00298);
    }
    PokeathlonCourseScoreList_Rank(gfx, 1);
    PokeathlonEvent_CalcPoints(gfx, 7);
    PokeathlonCourseScoreList_AddPointsToTotals(gfx);
    PokeathlonCourseScoreList_SaveEventPoints(gfx, 7);
    return TRUE;
}

BOOL PokeathlonRingDrop_Exit(PokeathlonCourseData *course) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);

    PokeathlonRingDropCpu_Free(ringDrop->cpu);
    PokeathlonRingDropUi_Free(ringDrop->ui);
    PokeathlonRingDropDisplay_Free(&ringDrop->display);
    PokeathlonRingDrop_FreeMonObjects(ringDrop);
    PokeathlonRingDrop_FreeSprites(ringDrop);
    PokeathlonRingDrop_FreeBgs(ringDrop);
    WirelessStatusIcon_Destroy();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    Heap_Destroy(HEAP_ID_145);
    return TRUE;
}

s32 PokeathlonRingDrop_GetMonState(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    return ringDrop->players[participant].mon.state;
}

VecFx32 *PokeathlonRingDrop_GetMonPosition(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMon *mon = &ringDrop->players[participant].mon;
    return &mon->position;
}

void PokeathlonRingDrop_GetMonScreenPosition(PokeathlonCourseData *course, u8 participant, VecFx32 *out) {
    int x, y;
    PokeathlonRingDropMon *mon = &((PokeathlonRingDrop *)PokeathlonCourse_GetWork(course))->players[participant].mon;

    PokeathlonCourseObject_CenterToGround(mon->member->object, mon->position.x >> FX32_SHIFT, mon->position.y >> FX32_SHIFT, &x, &y);
    out->x = x << FX32_SHIFT;
    out->y = y << FX32_SHIFT;
}

u32 PokeathlonRingDrop_GetMonDirection(PokeathlonCourseData *course, u8 participant) {
    return ((PokeathlonRingDrop *)PokeathlonCourse_GetWork(course))->players[participant].mon.flags.bits.direction;
}

u8 PokeathlonRingDrop_GetMonStamina(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMember *member = ringDrop->players[participant].mon.member;
    return member->stamina >> FX32_SHIFT;
}

u8 PokeathlonRingDrop_GetMonStaminaPercent(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMember *member = ringDrop->players[participant].mon.member;
    return (FX_Div(member->stamina, member->params->stamina) * 100) >> FX32_SHIFT;
}

BOOL PokeathlonRingDrop_IsMonSwitching(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    return ringDrop->players[participant].mon.flags.bits.switching;
}

BOOL PokeathlonRingDrop_IsMonPushed(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    return ringDrop->players[participant].mon.flags.bits.pushed;
}

BOOL PokeathlonRingDrop_CanMonAct(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    return PokeathlonRingDropMon_CanAct(&ringDrop->players[participant].mon);
}

void PokeathlonRingDrop_SetMonTarget(PokeathlonCourseData *course, u8 participant, const s16 *target) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMonFlags *flags = &ringDrop->players[participant].mon.flags;

    GF_ASSERT(flags->bits.exhausted == 0);
    flags->bits.hasTarget = TRUE;
    ringDrop->players[participant].mon.targetX = target[0];
    ringDrop->players[participant].mon.targetY = target[1];
}

void PokeathlonRingDrop_RequestJump(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMonFlags *flags = &ringDrop->players[participant].mon.flags;

    GF_ASSERT(flags->bits.exhausted == 0);
    GF_ASSERT(flags->bits.switching == 0);
    flags->bits.jumpRequested = TRUE;
}

void PokeathlonRingDrop_StartMonSwitch(PokeathlonCourseData *course, u8 participant) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMon_StartSwitch(&ringDrop->players[participant].mon);
}

void PokeathlonRingDrop_SetMonDestination(PokeathlonCourseData *course, u8 participant, const s16 *position) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    PokeathlonRingDropMon_SetDestination(&ringDrop->players[participant].mon, position);
}

int PokeathlonRingDrop_GetDirection(const VecFx32 *vec) {
    return PokeathlonRingDrop_VecToDirection(vec);
}

static void PokeathlonRingDrop_SetGfxBanks(void) {
    GraphicsBanks banks = gPokeathlonRingDropGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

// Every participant: the host first runs the ring on all inputs and sends the frame, then the
// frame received is shown.
static void PokeathlonRingDrop_Update(PokeathlonCourseData *course) {
    int i;
    PokeathlonRingDrop *ringDrop;
    PokeathlonRingDropFramePacket *packet;
    u8 *data;
    PokeathlonRingDropPlayer *player;

    ringDrop = PokeathlonCourse_GetWork(course);
    data = PokeathlonCourse_GetDataCopyArea(course);
    packet = (PokeathlonRingDropFramePacket *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_FRAME_OUT);
    if (PokeathlonCourse_GetNetId(course) == 0) {
        if (packet->finished) {
            PokeathlonRingDrop_BuildFramePacket(ringDrop->contacts, course);
            return;
        }
        if (ringDrop->timer > 0) {
            ringDrop->timer--;
            packet->timer = ringDrop->timer;
        }
        *(PokeathlonRingDropInput *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_INPUTS) = *(PokeathlonRingDropInput *)PokeathlonCourse_ToBytes(data);
        i = 0;
        data += POKEATHLON_COURSE_DATA_INPUTS;
        player = ringDrop->players;
        for (; i < POKEATHLON_PARTICIPANTS; player++, data += POKEATHLON_COURSE_DATA_SLOT_SIZE, i++) {
            PokeathlonRingDropInput *input = (PokeathlonRingDropInput *)PokeathlonCourse_ToBytes(data);
            PokeathlonRingDropTouch *touch = &player->touch;
            PokeathlonRingDropMon *mon = &player->mon;
            if (input->touching) {
                if (touch->started && touch->touching) {
                    touch->started = FALSE;
                } else if (!touch->started && !touch->touching) {
                    touch->started = TRUE;
                    touch->touching = TRUE;
                    player->touchStartX = input->x;
                    player->touchStartY = input->y;
                }
                player->touchX = input->x;
                player->touchY = input->y;
                touch->frames++;
            } else if (touch->touching) {
                touch->lastFrames = touch->frames;
                touch->frames = 0;
                touch->started = FALSE;
                touch->touching = FALSE;
            }
            PokeathlonRingDropMon_UpdateStatus(mon, touch, PokeathlonRingDrop_IsOnSwitchButton(player->touchX, player->touchY));
            if (mon->flags.bits.switching) {
                if (mon->flags.bits.switchState == RING_DROP_SWITCH_OUT && input->switchState == RING_DROP_SWITCH_OUT) {
                    PokeathlonRingDropMon_NextMember(mon);
                    PokeathlonRingDropMon_ResetToStart(mon);
                    mon->flags.bits.switchState = RING_DROP_SWITCH_IN;
                } else if (mon->flags.bits.switchState == RING_DROP_SWITCH_IN && input->switchState == RING_DROP_SWITCH_IN) {
                    mon->flags.bits.switching = FALSE;
                    mon->flags.bits.switchState = RING_DROP_SWITCH_NONE;
                    PokeathlonRingDropMon_SetState(mon, RING_DROP_MON_RETURN);
                }
            }
        }
        PokeathlonRingDropCpu_Update(ringDrop->cpu);
        PokeathlonRingDrop_UpdateMons(ringDrop->players, course);
        if (packet->timer == 0) {
            packet->finished = TRUE;
        }
        PokeathlonRingDrop_BuildFramePacket(ringDrop->contacts, course);
    }
    PokeathlonRingDropDisplay_Update(&ringDrop->display, course);
}

// Callback when the course ends: reports the own score.
static void PokeathlonRingDrop_OnFinish(PokeathlonCourseData *course) {
    u8 score;

    PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    score = PokeathlonRingDropUi_GetScore(((PokeathlonRingDrop *)PokeathlonCourse_GetWork(course))->ui);
    PokeathlonCourse_SetRecordScore(course, score);
    PokeathlonRingDrop_PrintScore(course, score);
}

// Every participant: reads the touch screen into the own input; TRUE once the host reports the
// time is up.

static BOOL PokeathlonRingDrop_ReadInput(PokeathlonCourseData *course) {
    PokeathlonRingDrop *ringDrop = PokeathlonCourse_GetWork(course);
    u8 *data = PokeathlonCourse_GetDataCopyArea(course);
    PokeathlonRingDropInput *input = (PokeathlonRingDropInput *)PokeathlonCourse_ToBytes(data);
    PokeathlonRingDropFramePacket *packet = (PokeathlonRingDropFramePacket *)PokeathlonCourse_ToBytes(data + POKEATHLON_COURSE_DATA_FRAME_IN);

    if (packet->finished == TRUE) {
        PokeathlonRingDropDisplay_StopAnimations(&ringDrop->display);
        PokeathlonCourseObjects_PauseAnims(ringDrop->monObjects, TRUE);
        PokeathlonRingDropUi_StopAnimations(ringDrop->ui);
        PokeathlonCourse_SetFinishCallback(course, PokeathlonRingDrop_OnFinish);
        return TRUE;
    }
    if (System_GetTouchNew()) {
        PokeathlonCourse_AddMonCounter(course, PokeathlonCourse_GetNetId(course), 3, POKEATHLON_COUNTER_INSTRUCTIONS, 1);
    }
    if (System_GetTouchHeld()) {
        input->x = gSystem.touchX;
        input->y = gSystem.touchY;
        input->touching = TRUE;
    } else {
        input->touching = FALSE;
    }
    return FALSE;
}
