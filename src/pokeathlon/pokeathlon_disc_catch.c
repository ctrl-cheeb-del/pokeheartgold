#include "pokeathlon/pokeathlon_disc_catch.h"

#include "global.h"

#include "constants/sndseq.h"

#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0309.h"
#include "pokeathlon/pokeathlon_course_internal.h"
#include "pokeathlon/pokeathlon_course_objects.h"
#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_disc_catch_play.h"
#include "pokeathlon/pokeathlon_event_points.h"

#include "assert.h"
#include "bg_window.h"
#include "filesystem.h"
#include "font.h"
#include "geometry_math.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "pm_string.h"
#include "screen_fade.h"
#include "sound_playback.h"
#include "sprite_resource_header.h"
#include "sprite_system.h"
#include "system.h"
#include "text.h"
#include "wireless_status_icon.h"

enum {
    DISC_CATCH_STATE_INTRO,
    DISC_CATCH_STATE_PLAY,
    DISC_CATCH_STATE_FINISH,
};

enum PokeathlonDiscCatchInitState {
    DISC_CATCH_INIT_CREATE,
    DISC_CATCH_INIT_LOAD_BGS,
    DISC_CATCH_INIT_WAIT_MONS,
    DISC_CATCH_INIT_START,
};

s32 _s32_div_f(s32 dividend, s32 divisor);

void MATH_QSort(void *head, u32 num, u32 size, s32 (*compare)(const void *, const void *), void *work);

// A Pokemon sprite and the y its draw order goes by.
typedef struct PokeathlonDiscCatchDrawOrder {
    u8 y;
    PokeathlonCourseMonObject *monPic;
} PokeathlonDiscCatchDrawOrder;

static void PokeathlonDiscCatch_SetVramBanks(void);
static int PokeathlonDiscCatch_GetJumpOffset(PokeathlonDiscCatchStats *stats, int frame, f32 *scale);
static void PokeathlonDiscCatch_SlowDown(VecFx32 *velocity, fx32 stepX, fx32 stepY);
static void PokeathlonDiscCatch_PrintScore(PokeathlonCourseData *course, int score);
static void PokeathlonDiscCatch_InitSpriteSystem(PokeathlonDiscCatch *work);
static void PokeathlonDiscCatch_FreeSpriteSystem(PokeathlonDiscCatch *work);
static void PokeathlonDiscCatch_LoadSpriteResources(PokeathlonDiscCatch *work);
static void PokeathlonDiscCatch_InitBgs(PokeathlonDiscCatch *work);
static void PokeathlonDiscCatch_FreeBgs(PokeathlonDiscCatch *work);
static void PokeathlonDiscCatch_LoadBgGraphics(PokeathlonDiscCatch *work);
static void PokeathlonDiscCatch_AnimateBg(u8 *timer, BgConfig *bgConfig, enum HeapID heapId);
static void PokeathlonDiscCatch_UpdateHost(PokeathlonCourseData *course);

static void PokeathlonDiscCatch_ShakeTask(SysTask *task, void *data) {
    PokeathlonDiscCatchShake *shake = data;
    int sign, offset;
    if (shake->flip == 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    offset = shake->distance * sign;
    ScheduleSetBgPosText(shake->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, offset + 8);
    ScheduleSetBgPosText(shake->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, offset);
    G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(shake->spriteSystem), 0, -offset << FX32_SHIFT);
    if (shake->frames % 2 == 1) {
        shake->distance--;
    }
    shake->flip ^= 1;
    shake->frames--;
    if (shake->frames <= 0) {
        ScheduleSetBgPosText(shake->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_SET_Y, 8);
        ScheduleSetBgPosText(shake->bgConfig, GF_BG_LYR_MAIN_0, BG_POS_OP_SET_Y, 0);
        G2dRenderer_SetMainSurfaceCoords(SpriteSystem_GetRenderer(shake->spriteSystem), 0, 0);
        shake->task = NULL;
        SysTask_Destroy(task);
    }
}

static BOOL PokeathlonDiscCatchShake_IsDone(PokeathlonDiscCatchShake *shake) {
    GF_ASSERT(shake != NULL);
    return shake->task == NULL;
}

static void PokeathlonDiscCatchShake_Init(PokeathlonDiscCatchShake *shake, BgConfig *bgConfig, SpriteSystem *spriteSystem) {
    shake->bgConfig = bgConfig;
    shake->spriteSystem = spriteSystem;
}

static void PokeathlonDiscCatchShake_Start(PokeathlonDiscCatchShake *shake, u8 distance, u8 frames) {
    GF_ASSERT(shake->bgConfig != NULL);
    GF_ASSERT(shake->spriteSystem != NULL);
    if (shake->task != NULL) {
        SysTask_Destroy(shake->task);
    }
    shake->flip = 0;
    shake->distance = distance;
    shake->frames = frames;
    shake->task = SysTask_CreateOnMainQueue(PokeathlonDiscCatch_ShakeTask, shake, 2);
}

// Squashes the Pokemon for two frames and stretches it back.
static void PokeathlonDiscCatch_SquashTask(SysTask *task, void *data) {
    PokeathlonDiscCatchSquash *squash = data;
    switch (squash->state) {
    case 0:
        squash->scale = 1.0 - (double)squash->frames * 0.3;
        if (squash->frames > 1) {
            squash->frames = 0;
            squash->state++;
            return;
        }
        PokeathlonCourseObject_SetScale(squash->monPic, 1.0f, squash->scale);
        squash->frames++;
        return;
    case 1:
        squash->scale = 1.0 + (double)squash->frames * 0.3;
        if (squash->frames > 1) {
            squash->task = NULL;
            PokeathlonCourseObject_SetScale(squash->monPic, 1.0f, 1.0f);
            SysTask_Destroy(task);
            return;
        }
        PokeathlonCourseObject_SetScale(squash->monPic, 1.0f, squash->scale);
        squash->frames++;
        return;
    default:
        GF_ASSERT(FALSE);
        return;
    }
}

static void PokeathlonDiscCatch_StartSquash(PokeathlonDiscCatchSquash *squash, PokeathlonCourseMonObject *monPic) {
    if (squash->task != NULL) {
        SysTask_Destroy(squash->task);
    }
    squash->monPic = monPic;
    squash->frames = 0;
    squash->state = 0;
    squash->task = SysTask_CreateOnMainQueue(PokeathlonDiscCatch_SquashTask, squash, 0);
}

// Scales the Pokemon about its middle while it falls off the field, about its feet otherwise.
void PokeathlonDiscCatch_SetMonScaleCenter(PokeathlonCourseMonObject *monPic, int falling) {
    PokeathlonCourseMonGfx *mon = PokeathlonCourseMonObject_GetGfx(monPic);
    int height = PokeathlonCourseMonGfx_GetTopRow(mon);
    int size;
    VecFx32 center = { 0, 0, 0 };
    if (PokeathlonCourseMonGfx_GetInfo(mon)->isLarge) {
        size = 64;
        PokeathlonCourseMonObject_SetAffineOverwriteMode(monPic, NNS_G2D_RND_AFFINE_OVERWRITE_NORMAL);
    } else {
        size = 32;
        PokeathlonCourseMonObject_SetAffineOverwriteMode(monPic, NNS_G2D_RND_AFFINE_OVERWRITE_DOUBLE);
    }
    if (falling) {
        center.x = (size / 2) << FX32_SHIFT;
        center.y = (height + (size - height) / 2) << FX32_SHIFT;
    } else {
        center.x = (size / 2) << FX32_SHIFT;
        center.y = (size - 1) << FX32_SHIFT;
    }
    PokeathlonCourseMonObject_SetAffineMatrix(monPic, &center);
}

BOOL PokeathlonDiscCatchMon_IsTouching(PokeathlonDiscCatchMon *mon, PokeathlonDiscCatchMon *other) {
    VecFx32 distance, center, otherCenter;
    int radius, otherRadius;
    fx32 sum;
    PokeathlonCourseObject_GetCollisionCircle(mon->monPic, mon->position.x, mon->position.y, &center.x, &center.y, &radius);
    PokeathlonCourseObject_GetCollisionCircle(other->monPic, other->position.x, other->position.y, &otherCenter.x, &otherCenter.y, &otherRadius);
    sum = (radius + otherRadius) << FX32_SHIFT;
    center.z = 0;
    otherCenter.z = 0;
    VEC_Subtract(&center, &otherCenter, &distance);
    if (VEC_Mag(&distance) <= sum) {
        return TRUE;
    }
    return FALSE;
}

void PokeathlonDiscCatchMon_Jump(PokeathlonDiscCatchMon *mon) {
    if (PokeathlonDiscCatch_GetStats(mon->course, mon->participant, mon->member)->jump) {
        PokeathlonCourse_AddMonCounter(mon->course, mon->participant, mon->member, POKEATHLON_COUNTER_JUMPS, 1);
        mon->jumpTimer = PokeathlonDiscCatchStats_GetJumpDuration(mon->stats);
        mon->state = DISC_CATCH_MON_JUMPING;
    }
    mon->jumpSignal = 10;
}

BOOL PokeathlonDiscCatchMon_IsInPlay(PokeathlonDiscCatchMon *mon) {
    u32 state;
    BOOL result;
    GF_ASSERT(mon != NULL);
    state = mon->state;
    result = TRUE;
    if (state != DISC_CATCH_MON_ON_FIELD && state != DISC_CATCH_MON_JUMPING) {
        result = FALSE;
    }
    return result;
}

void PokeathlonDiscCatchMon_SetTarget(PokeathlonDiscCatchMon *mon, const s16 *position) {
    mon->target.x = position[0] << FX32_SHIFT;
    mon->target.y = position[1] << FX32_SHIFT;
    mon->dragged = TRUE;
}

// 4: right, 2: down, 3: left, 1: up
int PokeathlonDiscCatch_GetFacing(const VecFx32 *direction) {
    VecFx32 reference = gPokeathlonDiscCatchFacingReference;
    VecFx32 vec = { 0 };
    u16 angle;
    vec.x = direction->y;
    vec.z = direction->x;
    vec.y = 0;
    angle = CalcAngleBetweenVecs(&reference, &vec);
    if (angle <= 0x2000 || angle >= 0xE000) {
        return 4;
    }
    if (angle > 0x2000 && angle < 0x6000) {
        return 2;
    }
    if (angle >= 0x6000 && angle <= 0xA000) {
        return 3;
    }
    return 1;
}

// Walks towards the target; while knocked back the velocity runs down first.
#pragma opt_propagation off

static void PokeathlonDiscCatchMon_Move(PokeathlonDiscCatchMon *mon, PokeathlonCourseData *course) {
    VecFx32 delta, normal, step, zero2, zero1, deceleration, push, zero3;
    fx32 distance;
    if (!mon->state) {
        return;
    }
    VEC_Subtract(&mon->target, &mon->position, &delta);
    distance = VEC_Mag(&delta);
    mon->moving = distance > 0;
    if (mon->knockedBack) {
        {
            int zero = 0;
            VecFx32 *p = &zero1;
            p->x = zero;
            VecFx32 *q = &zero2;
            p->y = zero;
            q->x = zero;
            p->z = zero;
            q->y = zero;
            q->z = zero;
        }
        VEC_Normalize(&mon->velocity, &zero2);
        VEC_MultAdd(FX32_CONST(0.8), &zero2, &zero1, &deceleration);
        deceleration.x = deceleration.x < 0 ? -deceleration.x : deceleration.x;
        deceleration.y = deceleration.y < 0 ? -deceleration.y : deceleration.y;
        if (mon->dragged) {
            int scale = mon->stats->power / 100;
            VEC_Normalize(&delta, &normal);
            VEC_MultAdd(scale, &mon->direction, &zero1, &push);
            deceleration.x += push.x < 0 ? -push.x : push.x;
            deceleration.y += push.y < 0 ? -push.y : push.y;
        }
        PokeathlonDiscCatch_SlowDown(&mon->velocity, deceleration.x, deceleration.y);
        VEC_Add(&mon->position, &mon->velocity, &mon->position);
        mon->target = mon->position;
        if (mon->velocity.x || mon->velocity.y) {
            return;
        }
        mon->knockedBack = FALSE;
    }
    if (mon->moving) {
        VEC_Normalize(&delta, &normal);
        if (!mon->knockedBack) {
            mon->facing = PokeathlonDiscCatch_GetFacing(&normal);
        }
        int speed = mon->stats->speed;
        if (distance <= speed) {
            step = delta;
        } else {
            VecFx32 *z = &zero3;
            z->x = 0;
            z->y = 0;
            z->z = 0;
            VEC_MultAdd(speed, &normal, &zero3, &step);
        }
        VEC_Add(&mon->position, &step, &mon->position);
        mon->direction = normal;
    }
}

#pragma opt_propagation reset

BOOL PokeathlonDiscCatchMon_IsOffField(PokeathlonDiscCatchMon *mon, fx32 x, fx32 y) {
    s32 fieldX;
    s32 fieldY;
    PokeathlonCourseObject_CenterToGround(mon->monPic, x >> FX32_SHIFT, y >> FX32_SHIFT, &fieldX, &fieldY);
    if (fieldX <= 0 || fieldY <= 0 || fieldX >= 255 || fieldY >= 255) {
        return TRUE;
    }
    if (fieldX < 8 || fieldX >= 248 || fieldY < 8 || fieldY >= 180) {
        return TRUE;
    }
    return FALSE;
}

static void PokeathlonDiscCatchMon_Respawn(PokeathlonDiscCatchMon *mon) {
    u8 index;
    int member;
    int participant;
    s32 x;
    s32 y;
    VecFx32 zero;

    index = mon->index;
    member = index % POKEATHLON_TEAM_SIZE;
    participant = index / POKEATHLON_TEAM_SIZE;
    PokeathlonCourseObject_GroundToCenter(mon->monPic, gPokeathlonDiscCatchMonStartPositions[participant][member][0], gPokeathlonDiscCatchMonStartPositions[participant][member][1], &x, &y);
    mon->position.x = x << FX32_SHIFT;
    mon->position.y = y << FX32_SHIFT;
    mon->target.x = x << FX32_SHIFT;
    mon->target.y = y << FX32_SHIFT;
    zero = (VecFx32) { 0, 0, 0 };
    mon->velocity = zero;
    mon->facing = 2;
    mon->knockedBack = FALSE;
}

void PokeathlonDiscCatchMon_Update(PokeathlonDiscCatchMon *mon, PokeathlonCourseData *course) {
    switch (mon->state) {
    case DISC_CATCH_MON_RESPAWNED:
        mon->state = DISC_CATCH_MON_ON_FIELD;
        break;
    case DISC_CATCH_MON_FALLEN:
        mon->respawnWait--;
        if (mon->respawnWait == 0) {
            PokeathlonDiscCatchMon_Respawn(mon);
            mon->state = DISC_CATCH_MON_RESPAWNED;
        }
        break;
    case DISC_CATCH_MON_ON_FIELD:
        PokeathlonDiscCatchMon_Move(mon, course);
        if (PokeathlonDiscCatchMon_IsOffField(mon, mon->position.x, mon->position.y)) {
            PokeathlonCourse_AddMonCounter(mon->course, mon->participant, mon->member, POKEATHLON_COUNTER_FAILURES, 1);
            PokeathlonCourse_AddMonCounter(mon->course, mon->participant, mon->member, POKEATHLON_COUNTER_FALLS, 1);
            if (mon->draggedOff) {
                PokeathlonCourse_AddMonCounter(mon->course, mon->participant, mon->member, POKEATHLON_COUNTER_SELF_IMPEDES, 1);
            }
            mon->draggedOff = FALSE;
            mon->respawnWait = 90;
            mon->state = DISC_CATCH_MON_FALLEN;
        }
        break;
    case DISC_CATCH_MON_JUMPING:
        mon->jumpTimer--;
        if (mon->jumpTimer == 0) {
            mon->state = DISC_CATCH_MON_ON_FIELD;
        }
        PokeathlonDiscCatchMon_Move(mon, course);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

// Of a team's three Pokemon, the nearest one the touch at (x, y) hits; POKEATHLON_NO_MON if none.
int PokeathlonDiscCatch_FindTouchedMon(PokeathlonDiscCatchMon *mons, s16 x, s16 y) {
    VecFx32 distances;
    fx32 min;
    int best;
    int i;

    best = POKEATHLON_NO_MON;
    distances = gPokeathlonDiscCatchTouchDistances;
    min = 1 << 20;
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (PokeathlonCourseObject_IsInTouchRange(mons->monPic, mons->position.x, mons->position.y, x, y)) {
            VecFx32 delta = { 0, 0, 0 };
            fx32 difference;
            difference = (x << FX32_SHIFT) - mons->position.x;
            if (difference < 0) {
                difference = -difference;
            }
            delta.x = difference;
            difference = (y << FX32_SHIFT) - mons->position.y;
            if (difference < 0) {
                difference = -difference;
            }
            delta.y = difference;
            ((fx32 *)&distances)[i] = VEC_Mag(&delta);
        }
        mons++;
    }
    for (i = 0; i < POKEATHLON_TEAM_SIZE; i++) {
        if (((fx32 *)&distances)[i] < min) {
            min = ((fx32 *)&distances)[i];
            best = i;
        }
    }
    return (s8)best;
}

// mode 0: on the top screen, 1: on the touch screen, 2: both.
static void PokeathlonDiscCatch_ShowDisc(PokeathlonDiscCatchDiscSprites *sprites, u32 mode, BOOL draw) {
    BOOL hidden;
    switch (mode) {
    case 0:
        ManagedSprite_SetDrawFlag(sprites->disc[0], draw);
        hidden = !draw;
        ManagedSprite_SetDrawFlag(sprites->disc[1], hidden);
        ManagedSprite_SetDrawFlag(sprites->shadow[0], draw);
        ManagedSprite_SetDrawFlag(sprites->shadow[1], hidden);
        break;
    case 1:
        hidden = !draw;
        ManagedSprite_SetDrawFlag(sprites->disc[0], hidden);
        ManagedSprite_SetDrawFlag(sprites->disc[1], draw);
        ManagedSprite_SetDrawFlag(sprites->shadow[0], hidden);
        ManagedSprite_SetDrawFlag(sprites->shadow[1], draw);
        break;
    case 2:
        ManagedSprite_SetDrawFlag(sprites->disc[0], draw);
        ManagedSprite_SetDrawFlag(sprites->disc[1], draw);
        ManagedSprite_SetDrawFlag(sprites->shadow[0], draw);
        ManagedSprite_SetDrawFlag(sprites->shadow[1], draw);
        break;
    }
}

static void PokeathlonDiscCatch_ScaleDisc(PokeathlonDiscCatchDiscSprites *sprites, f32 scale) {
    ManagedSprite_SetAffineScale(sprites->disc[0], scale, scale);
    ManagedSprite_SetAffineScale(sprites->disc[1], scale, scale);
}

static void PokeathlonDiscCatch_ShowPoints(PokeathlonDiscCatchDiscSprites *sprites, int state, s16 x, s16 y) {
    int anim = state - DISC_CATCH_DISC_CAUGHT_1;
    GF_ASSERT(anim < 4);
    ManagedSprite_SetPositionXYWithSubscreenOffset(sprites->points, x, y, FX32_CONST(480));
    ManagedSprite_SetPositionXYWithSubscreenOffset(sprites->sparkle, x, y, FX32_CONST(480));
    ManagedSprite_SetAnim(sprites->points, anim);
    ManagedSprite_ResetSpriteAnimCtrlState(sprites->sparkle);
    ManagedSprite_SetDrawFlag(sprites->points, TRUE);
    ManagedSprite_SetDrawFlag(sprites->sparkle, TRUE);
}

static void PokeathlonDiscCatch_PlayCatchSound(u32 state) {
    s16 pitch;
    switch (state) {
    case DISC_CATCH_DISC_CAUGHT_1:
        pitch = 0;
        break;
    case DISC_CATCH_DISC_CAUGHT_2:
        pitch = 128;
        break;
    case DISC_CATCH_DISC_CAUGHT_3:
        pitch = 0;
        break;
    case DISC_CATCH_DISC_CAUGHT_5:
        pitch = 192;
        break;
    default:
        // BUG: pitch is left unset here.
        GF_ASSERT(FALSE);
        break;
    }
    PlaySE_SetPitch(SEQ_SE_GS_POINT1, pitch);
}

// Shows the discs of the frame packet.
void PokeathlonDiscCatch_UpdateDiscSprites(PokeathlonDiscCatchSprites *sprites, PokeathlonDiscCatchDiscPacket *discs, PokeathlonCourseData *course) {
    u8 myId = PokeathlonCourse_GetNetId(course);
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    PokeathlonDiscCatchDiscSprites *disc;
    int i;
    s16 y, screenY;
    int screen;
    s16 x;

    for (i = 0, disc = sprites->discs; i < DISC_CATCH_DISCS; i++, disc++, discs++) {
        y = discs->progress * 8 / 2;
        if (discs->state == DISC_CATCH_DISC_LANDED) {
            y += 480;
        }
        screenY = y;
        if (y >= 288) {
            screen = 1;
        } else {
            screen = 0;
        }
        if (screen) {
            screenY -= 288;
        }
        x = PokeathlonDiscCatch_GetDiscX(y, discs->path);
        if (discs->state == DISC_CATCH_DISC_NONE) {
            PokeathlonDiscCatch_ShowDisc(disc, 2, FALSE);
            ManagedSprite_SetDrawFlag(disc->points, FALSE);
            ManagedSprite_SetDrawFlag(disc->sparkle, FALSE);
        } else if (discs->state >= DISC_CATCH_DISC_CAUGHT_1 && disc->shownState < DISC_CATCH_DISC_CAUGHT_1) {
            PokeathlonDiscCatch_ShowDisc(disc, 2, FALSE);
            PokeathlonDiscCatch_ShowPoints(disc, discs->state, x, screenY - 40);
            if (discs->owner == myId) {
                PokeathlonDiscCatchShake_Start(&work->shake, 4, 4);
                PokeathlonDiscCatch_PlayCatchSound(discs->state);
            } else {
                ManagedSprite_SetDrawFlag(disc->points, FALSE);
            }
            PlaySE(SEQ_SE_GS_W280);
        } else if (discs->state == DISC_CATCH_DISC_FLYING) {
            PokeathlonDiscCatch_ShowDisc(disc, screen, TRUE);
            ManagedSprite_SetDrawFlag(disc->points, FALSE);
            ManagedSprite_SetDrawFlag(disc->sparkle, FALSE);
        }
        if (disc->shownState == DISC_CATCH_DISC_NONE && discs->state == DISC_CATCH_DISC_FLYING) {
            disc->angle = 0;
            PokeathlonDiscCatch_ScaleDisc(disc, 1.2f);
            PlaySE(SEQ_SE_GS_W030);
        }
        if (discs->state == DISC_CATCH_DISC_FLYING || discs->state == DISC_CATCH_DISC_LANDED) {
            if (screen && x > 16) {
                ManagedSprite_SetAnimNoRestart(disc->shadow[screen], 1);
            }
            {
                f32 scale = 1.2f + (GF_SinDeg(disc->angle) / 18) / 4096.0f;
                disc->angle += 10;
                PokeathlonDiscCatch_ScaleDisc(disc, scale);
            }
            ManagedSprite_SetPositionXYWithSubscreenOffset(disc->disc[screen], x, screenY - 40, FX32_CONST(480));
            ManagedSprite_SetPositionXYWithSubscreenOffset(disc->shadow[screen], x, screenY, FX32_CONST(480));
        }
        disc->shownState = discs->state;
    }
}

// The lower Pokemon is drawn in front.
static s32 PokeathlonDiscCatch_CompareDrawOrder(const void *a, const void *b) {
    const PokeathlonDiscCatchDrawOrder *orderA = a;
    const PokeathlonDiscCatchDrawOrder *orderB = b;

    if (orderA->y == orderB->y) {
        return 0;
    }
    if (orderA->y < orderB->y) {
        return 1;
    }
    return -1;
}

// Shows the Pokemon of the frame packet: positions, facings, jumps and falls, and the draw order.
void PokeathlonDiscCatch_UpdateMonSprites(PokeathlonDiscCatchSprites *sprites, PokeathlonDiscCatchFrame *frame, PokeathlonCourseData *course) {
    PokeathlonDiscCatchDrawOrder order[POKEATHLON_MONS] = { 0 };
    s32 x;
    s32 y;
    s32 fieldX;
    s32 fieldY;
    f32 scale;
    PokeathlonDiscCatch *work;
    PokeathlonDiscCatchMonSprites *mon;
    u8 fallen;
    PokeathlonDiscCatchDrawOrder *entry;
    PokeathlonCourseMonObject *monPic;
    u8 monY;
    int i;
    int shift;

    work = PokeathlonCourse_GetWork(course);
    mon = sprites->mons;
    i = 0;
    entry = order;
    shift = 0;
    for (; i < POKEATHLON_MONS; i++) {
        monPic = PokeathlonCourseMonObjects_Get(work->monPics, i);
        GF_ASSERT(mon != NULL);
        GF_ASSERT(monPic != NULL);
        monY = frame->monY[i];
        PokeathlonCourseObject_GroundToCenter(monPic, frame->monX[i], monY, &x, &y);
        entry->y = monY;
        entry->monPic = monPic;
        fallen = (frame->fallen >> i) & 1;
        if (fallen == 1 && mon->fallen == 0) {
            PokeathlonDiscCatch_SetMonScaleCenter(monPic, TRUE);
            mon->falling = TRUE;
            mon->fallFrames = 6;
            mon->fallScale = FX32_ONE;
            PlaySE(SEQ_SE_GS_PUSH02);
        } else if (fallen == 0 && mon->fallen == 1) {
            ManagedSprite_SetPositionXYWithSubscreenOffset(mon->splash, x, y, FX32_CONST(480));
            ManagedSprite_SetDrawFlag(mon->splash, TRUE);
            ManagedSprite_ResetSpriteAnimCtrlState(mon->splash);
            PokeathlonDiscCatch_SetMonScaleCenter(monPic, FALSE);
            PokeathlonCourseObject_SetScale(monPic, 1.0f, 1.0f);
            PokeathlonCourseMonObject_SetDrawFlag(monPic, TRUE);
            mon->falling = FALSE;
            PlaySE(SEQ_SE_GS_BOWA2);
        }
        mon->fallen = fallen;
        if (mon->falling) {
            mon->fallFrames--;
            if (mon->fallFrames == 0) {
                PokeathlonCourseMonObject_SetDrawFlag(monPic, FALSE);
            } else {
                f32 fallScale;
                mon->fallScale -= FX32_CONST(0.1);
                fallScale = mon->fallScale / 4096.0f;
                PokeathlonCourseObject_SetScale(monPic, fallScale, fallScale);
                PokeathlonCourseObject_CenterToGround(monPic, frame->monX[i], frame->monY[i], &fieldX, &fieldY);
                if (fieldY >= 180) {
                    u32 sink = (6 - mon->fallFrames) * 4;
                    u32 sinkY = monY;
                    sinkY += sink;
                    PokeathlonCourseObject_SetCenterPosition(monPic, x, sinkY, TRUE);
                }
            }
        } else {
            u8 facing = (frame->facings >> shift) & 3;
            PokeathlonCourseObject_SetCenterPosition(monPic, x, y, TRUE);
            PokeathlonCourseMonObject_SetAnimState(monPic, facing + 1);
            if ((frame->jumped >> i) & 1) {
                PokeathlonDiscCatchStats *stats;
                int participant;
                participant = i / POKEATHLON_TEAM_SIZE;
                stats = PokeathlonDiscCatch_GetStats(course, (u8)participant, (u8)(i % POKEATHLON_TEAM_SIZE));
                if (participant == PokeathlonCourse_GetNetId(course) && mon->jumping == 0 && mon->squashed == 0) {
                    if (stats->jump == 0) {
                        PlaySE(SEQ_SE_DP_BOX03);
                    } else {
                        PlaySE(SEQ_SE_GS_UFO_JUMP);
                    }
                }
                if (stats->jump == 0) {
                    PokeathlonDiscCatch_StartSquash(&mon->squash, monPic);
                    mon->squashed = TRUE;
                } else {
                    mon->jumping = TRUE;
                }
            } else {
                mon->squashed = FALSE;
            }
            if (mon->jumping) {
                PokeathlonDiscCatchStats *stats;
                u32 frames;
                stats = PokeathlonDiscCatch_GetStats(course, (u8)(i / POKEATHLON_TEAM_SIZE), (u8)(i % POKEATHLON_TEAM_SIZE));
                PokeathlonCourseObject_SetCenterPosition(monPic, x, y + PokeathlonDiscCatch_GetJumpOffset(stats, mon->jumpFrame, &scale), FALSE);
                PokeathlonCourseObject_SetScale(monPic, scale, scale);
                frames = PokeathlonDiscCatchStats_GetJumpDuration(stats);
                mon->jumpFrame++;
                if (mon->jumpFrame > frames) {
                    mon->jumping = FALSE;
                    mon->jumpFrame = 0;
                    PokeathlonCourseObject_SetCenterPosition(monPic, x, y, FALSE);
                    PokeathlonCourseObject_SetScale(monPic, 1.0f, 1.0f);
                }
            }
        }
        entry++;
        shift += 2;
        mon++;
    }
    MATH_QSort(order, POKEATHLON_MONS, sizeof(PokeathlonDiscCatchDrawOrder), PokeathlonDiscCatch_CompareDrawOrder, NULL);
    shift = 0;
    entry = order;
    for (; shift < POKEATHLON_MONS; shift++) {
        GF_ASSERT(entry->monPic != NULL);
        PokeathlonCourseMonObject_SetDrawPriority(entry->monPic, shift + 7);
        entry++;
    }
}

enum PokeathlonDiscCatchIntroState {
    DISC_CATCH_INTRO_FADE_IN,
    DISC_CATCH_INTRO_WAIT_FADE_IN,
    DISC_CATCH_INTRO_COUNTDOWN,
};

// Event state 0: fades in, then waits for the course to start the event.
BOOL PokeathlonDiscCatch_Intro(PokeathlonCourseData *course, u8 *state) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    PokeathlonDiscCatch_AnimateBg(&work->bgFrameTimer, work->bgConfig, work->heapId);
    switch (*state) {
    case DISC_CATCH_INTRO_FADE_IN:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, RGB_WHITE, 6, 1, work->heapId);
        (*state)++;
    case DISC_CATCH_INTRO_WAIT_FADE_IN:
        if (IsPaletteFadeFinished()) {
            (*state)++;
        }
        break;
    case DISC_CATCH_INTRO_COUNTDOWN:
        if (PokeathlonCourse_RunStartCountdown(course)) {
            PokeathlonCourse_SetNextState(course, DISC_CATCH_STATE_PLAY);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

// The time is up: stops the sprites and reports the own score.
void PokeathlonDiscCatch_EndGame(PokeathlonCourseData *course) {
    u8 score;
    PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
    score = PokeathlonDiscCatchScoreboard_GetOwnScore(((PokeathlonDiscCatch *)PokeathlonCourse_GetWork(course))->scoreboard);
    PokeathlonCourse_SetRecordScore(course, score);
    PokeathlonDiscCatch_PrintScore(course, score);
}

enum PokeathlonDiscCatchPlayState {
    DISC_CATCH_PLAY_RUN,
    DISC_CATCH_PLAY_FINISH,
};

// Event state 1: runs the game until the host reports the end and the shake is over.
BOOL PokeathlonDiscCatch_Play(PokeathlonCourseData *course, u8 *state) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    PokeathlonDiscCatch_AnimateBg(&work->bgFrameTimer, work->bgConfig, work->heapId);
    switch (*state) {
    case DISC_CATCH_PLAY_RUN:
        PokeathlonDiscCatch_UpdateHost(course);
        if (PokeathlonDiscCatch_UpdateFrame(course)) {
            (*state)++;
        }
        break;
    case DISC_CATCH_PLAY_FINISH: {
        PokeathlonDiscCatchFrame *frame;
        PokeathlonDiscCatch_UpdateHost(course);
        frame = (PokeathlonDiscCatchFrame *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_IN);
        PokeathlonDiscCatchScoreboard_SetOwnScore(work->scoreboard, (u8)frame->scoreParticipant, frame->score);
        if (PokeathlonCourse_RunFinish(course)) {
            if (PokeathlonDiscCatchShake_IsDone(&work->shake)) {
                BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, RGB_BLACK, 6, 1, work->heapId);
                PokeathlonCourse_SetNextState(course, DISC_CATCH_STATE_FINISH);
            }
        }
        break;
    }
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

// Event state 2: after the fade the host records the teams' scores.
BOOL PokeathlonDiscCatch_Finish(PokeathlonCourseData *course, u8 *state) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    if (*state == 0) {
        if (IsPaletteFadeFinished()) {
            BOOL isGuest = PokeathlonCourse_GetNetId(course);
            work = PokeathlonCourse_GetWork(course);
            if (!isGuest) {
                int i;
                for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
                    PokeathlonCourse_SetEventScore(course, (u8)i, work->field.teams[i].result.score);
                }
            }
            return TRUE;
        }
    } else {
        GF_ASSERT(FALSE);
    }
    return FALSE;
}

BOOL PokeathlonDiscCatch_Init(PokeathlonCourseData *course) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    switch (PokeathlonCourse_GetEventInitState(course)) {
    case DISC_CATCH_INIT_CREATE:
        Heap_Create(HEAP_ID_POKEATHLON, HEAP_ID_142, 0x60000);
        Main_SetVBlankIntrCB(NULL, NULL);
        Main_SetHBlankIntrCB(NULL, NULL);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
        reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
        PokeathlonDiscCatch_SetVramBanks();
        gSystem.screensFlipped = TRUE;
        GfGfx_SwapDisplay();
        work = PokeathlonCourse_AllocWork(course, sizeof(PokeathlonDiscCatch));
        MI_CpuFill8(work, 0, sizeof(PokeathlonDiscCatch));
        work->heapId = HEAP_ID_142;
        work->course = course;
        work->timer = 1800;
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case DISC_CATCH_INIT_LOAD_BGS:
        work->bgConfig = BgConfig_Alloc(work->heapId);
        PokeathlonCourse_SetHudPlanes(course, GX_PLANEMASK_BG2);
        PokeathlonDiscCatch_InitBgs(work);
        PokeathlonDiscCatch_LoadBgGraphics(work);
        PokeathlonDiscCatch_AddScoreWindow(work);
        WirelessStatusIcon_CreateOnScreenIfConnected(2);
        PokeathlonDiscCatch_InitSpriteSystem(work);
        PokeathlonDiscCatch_CreateMonPics(work);
        PokeathlonCourse_AdvanceEventInitState(course);
        break;
    case DISC_CATCH_INIT_WAIT_MONS:
        if (PokeathlonCourseMonObjects_IsLoaded(work->monPics)) {
            PokeathlonDiscCatch_LoadSpriteResources(work);
            Sprite_SetDrawPriority(*PokeathlonCourse_CreateHudSprites(course, 0, work->monPicResources, SpriteManager_GetSpriteList(work->spriteManager)), 0);
            PokeathlonCourse_AdvanceEventInitState(course);
        }
        break;
    case DISC_CATCH_INIT_START: {
        u8 participant = PokeathlonCourse_GetNetId(course);
        work->scoreboard = PokeathlonDiscCatchScoreboard_New(work->spriteSystem, work->spriteManager, work->bgConfig, work->msgData, work->messageFormat, participant, work->heapId, course);
        PokeathlonDiscCatchSprites_Init(&work->sprites, work->spriteSystem, work->spriteManager, work->scoreboard);
        work->cpu = PokeathlonDiscCatchCpu_New(course, work->heapId);
        PokeathlonCourse_InitMarkers(course);
        PokeathlonDiscCatchShake_Init(&work->shake, work->bgConfig, work->spriteSystem);
        PokeathlonCourse_SetVBlankIntrCB(work->bgConfig);
        PokeathlonCourse_SetEventDrawEnabled(course, TRUE);
        PokeathlonDiscCatch_InitMons(work);
        if (PokeathlonCourse_GetNetId(course) == 0) {
            PokeathlonDiscCatchFrame *frame = (PokeathlonDiscCatchFrame *)PokeathlonCourse_ToBytes(PokeathlonCourse_GetDataCopyArea(course) + POKEATHLON_COURSE_DATA_FRAME_OUT);
            frame->seconds = (work->timer + 30) / 30;
            PokeathlonDiscCatch_WriteFramePacket(&work->field, course);
        }
        PokeathlonDiscCatchDiscs_Init(&work->discs, work->field.teams);
        GfGfx_EngineATogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        GfGfx_EngineBTogglePlanes(GX_PLANEMASK_OBJ, GF_PLANE_TOGGLE_ON);
        return TRUE;
    }
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return FALSE;
}

BOOL PokeathlonDiscCatch_Draw(PokeathlonCourseData *course) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    GF_ASSERT(work != NULL);
    SpriteSystem_DrawSprites(work->spriteManager);
    return TRUE;
}

BOOL PokeathlonDiscCatch_ShowResults(PokeathlonCourseData *course) {
    PokeathlonCourseScoreList *graphics = PokeathlonCourse_GetGraphicsSystem(course);
    int i;
    PokeathlonCourseScoreList_Init(graphics);
    for (i = 0; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonCourse_AddScoreEntry(course, graphics, i, PokeathlonCourse_GetReceivedScore(course, (u8)i), 0, 3, msg_0309_00295);
    }
    PokeathlonCourseScoreList_Rank(graphics, 1);
    PokeathlonEvent_CalcPoints(graphics, 4);
    PokeathlonCourseScoreList_AddPointsToTotals(graphics);
    PokeathlonCourseScoreList_SaveEventPoints(graphics, 4);
    return TRUE;
}

// Frees everything Init created.
BOOL PokeathlonDiscCatch_Exit(PokeathlonCourseData *course) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    PokeathlonCourse_FreeMarkers(course);
    PokeathlonDiscCatchCpu_Delete(work->cpu);
    PokeathlonDiscCatchScoreboard_Delete(work->scoreboard);
    PokeathlonDiscCatchSprites_Delete(&work->sprites);
    PokeathlonDiscCatch_FreeSpriteSystem(work);
    PokeathlonDiscCatch_FreeBgs(work);
    WirelessStatusIcon_Destroy();
    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    PokeathlonCourse_FreeWork(course);
    gSystem.screensFlipped = FALSE;
    GfGfx_SwapDisplay();
    Heap_Destroy(HEAP_ID_142);
    return TRUE;
}

// x of a disc on its path: a slant by the path (0..14, 7 straight down) plus a wave.
s16 PokeathlonDiscCatch_GetDiscX(int progress, int path) {
    s16 x = _s32_div_f(38 * (progress * (path - 7)), 1000) + 128;
    return x + ((GF_SinDeg(progress << 1) << 6) >> 16);
}

BOOL PokeathlonDiscCatch_IsMonInPlay(PokeathlonDiscCatch *work, u32 participant, u32 member) {
    u32 state;
    BOOL result;
    GF_ASSERT(work != NULL);
    GF_ASSERT(participant < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(member < POKEATHLON_TEAM_SIZE);
    result = TRUE;
    state = work->field.teams[participant].mons[member].state;
    if (state != DISC_CATCH_MON_ON_FIELD && state != DISC_CATCH_MON_JUMPING) {
        result = FALSE;
    }
    return result;
}

PokeathlonDiscCatchDisc *PokeathlonDiscCatch_GetDisc(PokeathlonDiscCatch *work, u32 index) {
    GF_ASSERT(work != NULL);
    GF_ASSERT(index < DISC_CATCH_DISCS);
    return &work->discs.discs[index];
}

void PokeathlonDiscCatch_GetMonPosition(PokeathlonDiscCatch *work, u32 participant, u32 member, s16 *position, s32 *radius) {
    PokeathlonDiscCatchMon *mon;
    GF_ASSERT(work != NULL);
    GF_ASSERT(participant < POKEATHLON_PARTICIPANTS);
    GF_ASSERT(member < POKEATHLON_TEAM_SIZE);
    mon = &work->field.teams[participant].mons[member];
    position[0] = mon->position.x >> FX32_SHIFT;
    position[1] = mon->position.y >> FX32_SHIFT;
    *radius = PokeathlonCourseObject_GetCollisionRadius(mon->monPic);
}

// How many teams have more points than the participant's.
u8 PokeathlonDiscCatch_CountTeamsAhead(PokeathlonCourseData *course, u32 participant) {
    u8 count = 0;
    PokeathlonDiscCatch *work;
    int i;
    u16 score;
    GF_ASSERT(course != NULL);
    work = PokeathlonCourse_GetWork(course);
    GF_ASSERT(work != NULL);
    i = 0;
    score = work->field.teams[participant].result.score;
    for (; i < POKEATHLON_PARTICIPANTS; i++) {
        u16 other = work->field.teams[i].result.score;
        if (i != participant && score < other) {
            count++;
        }
    }
    return count;
}

void PokeathlonDiscCatch_SetMonTarget(PokeathlonDiscCatch *work, const s16 *position, u32 participant, u32 member) {
    PokeathlonDiscCatchMon_SetTarget(&work->field.teams[participant].mons[member], position);
}

void PokeathlonDiscCatch_MakeMonJump(PokeathlonDiscCatch *work, u32 participant, u32 member) {
    PokeathlonDiscCatchMon_Jump(&work->field.teams[participant].mons[member]);
}

u8 PokeathlonDiscCatch_GetTeamScore(PokeathlonDiscCatch *work, int participant) {
    return work->field.teams[participant].result.score;
}

static void PokeathlonDiscCatch_SetVramBanks(void) {
    GraphicsBanks banks = gPokeathlonDiscCatchGraphicsBanks;
    GfGfx_SetBanks(&banks);
}

static int PokeathlonDiscCatch_Square(int value) {
    return value * value;
}

// Moves the value towards 0 by step.
static void PokeathlonDiscCatch_Approach0(fx32 *value, fx32 step) {
    if (*value != 0) {
        fx32 magnitude = *value < 0 ? -*value : *value;
        if (magnitude < step) {
            *value = 0;
            return;
        }
        *value -= (*value > 0 ? 1 : -1) * step;
    }
}

// The height of a jumping Pokemon at the frame and its scale.
static int PokeathlonDiscCatch_GetJumpOffset(PokeathlonDiscCatchStats *stats, int frame, f32 *scale) {
    fx32 offset = 0;
    f32 result = 1.0f;
    int half, curve;
    f32 height;
    int fxHeight;
    GF_ASSERT(stats != NULL);
    half = stats->jumpFrames;
    curve = PokeathlonDiscCatch_Square(frame - half) - PokeathlonDiscCatch_Square(half);
    if (curve != 0) {
        if (stats->jumpHeight != 0) {
            height = 0.5f + (stats->jumpHeight << FX32_SHIFT);
        } else {
            height = (stats->jumpHeight << FX32_SHIFT) - 0.5f;
        }
        fxHeight = height;
        if (fxHeight != 0) {
            offset = (fxHeight / 10) * curve;
            if (offset <= FX32_CONST(-24)) {
                offset = FX32_CONST(-24);
            }
            result = result - ((offset - FX32_CONST(4)) / 100) / 4096.0f;
        }
    }
    *scale = result;
    return offset >> FX32_SHIFT;
}

static void PokeathlonDiscCatch_SlowDown(VecFx32 *velocity, fx32 stepX, fx32 stepY) {
    PokeathlonDiscCatch_Approach0(&velocity->x, stepX);
    PokeathlonDiscCatch_Approach0(&velocity->y, stepY);
}

void PokeathlonDiscCatch_ClampVelocity(VecFx32 *velocity, fx32 limit) {
    fx32 negLimit = -limit;

    if (velocity->x > 0) {
        if (velocity->x > limit) {
            velocity->x = limit;
        }
    } else if (velocity->x < negLimit) {
        velocity->x = negLimit;
    }

    if (velocity->y > 0) {
        if (velocity->y > limit) {
            velocity->y = limit;
        }
    } else if (velocity->y < negLimit) {
        velocity->y = negLimit;
    }
}

static void PokeathlonDiscCatch_PrintScore(PokeathlonCourseData *course, int score) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    MessageFormat *messageFormat = work->messageFormat;
    MsgData *msgData = work->msgData;
    String *string;
    FillWindowPixelBuffer(&work->window, 0);
    BufferIntegerAsString(messageFormat, 0, score, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(messageFormat, msgData, msg_0309_00160, work->heapId);
    AddTextPrinterParameterizedWithColor(&work->window, 4, string, 0, 0, TEXT_SPEED_NOTRANSFER, MAKE_TEXT_COLOR(15, 14, 0), NULL);
    String_Delete(string);
    CopyWindowToVram(&work->window);
}

static void PokeathlonDiscCatch_InitSpriteSystem(PokeathlonDiscCatch *work) {
    SpriteResourceCountsListUnion counts = gPokeathlonDiscCatchSpriteResourceCounts;
    OamManagerParam oamParam = gPokeathlonDiscCatchOamManagerParam;
    OamCharTransferParam transferParam = gPokeathlonDiscCatchOamCharTransferParam;
    transferParam.maxTasks = 128;
    work->spriteSystem = SpriteSystem_Alloc(work->heapId);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    SpriteSystem_Init(work->spriteSystem, &oamParam, &transferParam, 32);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 128);
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &counts);
    G2dRenderer_SetSubSurfaceCoords(SpriteSystem_GetRenderer(work->spriteSystem), 0, FX32_CONST(480));
    work->monPicResources = PokeathlonCourseSprites_CreateResources(work->heapId, 2727, NNS_G2D_VRAM_TYPE_2DMAIN);
}

static void PokeathlonDiscCatch_FreeSpriteSystem(PokeathlonDiscCatch *work) {
    PokeathlonCourseMonObjects_Free(work->monPics);
    PokeathlonCourseSprites_FreeResources(work->monPicResources);
    SpriteSystem_FreeResourcesAndManager(work->spriteSystem, work->spriteManager);
    SpriteSystem_Free(work->spriteSystem);
}

// Stops all animations (the time is up).
void PokeathlonDiscCatch_StopAnims(PokeathlonDiscCatch *work) {
    int i;
    int j;
    PokeathlonDiscCatchDiscSprites *disc;
    BOOL animate0;
    BOOL animate1;

    PokeathlonCourseObjects_PauseAnims(work->monPics, TRUE);
    PokeathlonDiscCatchScoreboard_Pause(work->scoreboard);

    for (i = 0; i < POKEATHLON_MONS; i++) {
        ManagedSprite_SetAnimateFlag(work->sprites.mons[i].splash, FALSE);
    }

    i = 0;
    animate0 = FALSE;
    animate1 = FALSE;
    disc = work->sprites.discs;
    for (; i < DISC_CATCH_DISCS; disc++, i++) {
        ManagedSprite **sprites = disc->disc;

        for (j = 0; j < 2; j++) {
            ManagedSprite_SetAnimateFlag(sprites[j], animate0);
            ManagedSprite_SetAnimateFlag(sprites[j + 2], animate1);
        }
    }
}

#pragma opt_propagation off

static void PokeathlonDiscCatch_LoadSpriteResources(PokeathlonDiscCatch *work) {
    SpriteSystem *spriteSystem = work->spriteSystem;
    SpriteManager *spriteManager = work->spriteManager;
    NNS_G2D_VRAM_TYPE vram;

    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 22, TRUE, vram, 10000);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 19, FALSE, 2, vram, 10000);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 21, TRUE, 10000);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 20, TRUE, 10000);
    vram = NNS_G2D_VRAM_TYPE_2DSUB;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 26, TRUE, vram, 10001);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 23, FALSE, 4, vram, 10001);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 25, TRUE, 10001);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 24, TRUE, 10001);
    vram = NNS_G2D_VRAM_TYPE_2DMAIN;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 18, TRUE, vram, 10002);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 15, FALSE, 1, vram, 10002);
    vram = NNS_G2D_VRAM_TYPE_2DSUB;
    SpriteSystem_LoadCharResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 18, TRUE, vram, 10003);
    SpriteSystem_LoadPlttResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 15, FALSE, 1, vram, 10003);
    SpriteSystem_LoadCellResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 17, TRUE, 10002);
    SpriteSystem_LoadAnimResObj(spriteSystem, spriteManager, NARC_a_2_3_5, 16, TRUE, 10002);
}

#pragma opt_propagation reset

// A disc sprite (the top screen's template, or the touch screen's for onTouchScreen).
ManagedSprite *PokeathlonDiscCatch_NewDiscSprite(SpriteSystem *spriteSystem, SpriteManager *spriteManager, u16 x, u16 y, u16 anim, u16 priority, BOOL onTouchScreen) {
    ManagedSpriteTemplate topTemplate = gPokeathlonDiscCatchDiscTopSpriteTemplate;
    ManagedSpriteTemplate touchTemplate = gPokeathlonDiscCatchDiscTouchSpriteTemplate;
    ManagedSpriteTemplate *template = onTouchScreen ? &touchTemplate : &topTemplate;
    ManagedSprite *sprite;
    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    template->x = x;
    template->y = y;
    template->animation = anim;
    template->drawPriority = priority;
    sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, template, FX32_CONST(480));
    ManagedSprite_SetAffineOverwriteMode(sprite, NNS_G2D_RND_AFFINE_OVERWRITE_DOUBLE);
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    ManagedSprite_SetDrawFlag(sprite, FALSE);
    return sprite;
}

ManagedSprite *PokeathlonDiscCatch_NewEffectSprite(SpriteSystem *spriteSystem, SpriteManager *spriteManager, u16 x, u16 y, u16 anim, u16 priority) {
    ManagedSpriteTemplate template = gPokeathlonDiscCatchEffectSpriteTemplate;
    ManagedSprite *sprite;
    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    template.x = x;
    template.y = y;
    template.animation = anim;
    template.drawPriority = priority;
    sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, FX32_CONST(480));
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    ManagedSprite_SetDrawFlag(sprite, FALSE);
    return sprite;
}

static void PokeathlonDiscCatch_InitBgs(PokeathlonDiscCatch *work) {
    BgConfig *bgConfig = work->bgConfig;
    enum HeapID heapId = work->heapId;
    GraphicsModes modes = gPokeathlonDiscCatchGraphicsModes;
    int i;

    SetBothScreensModesAndDisable(&modes);

    PokeathlonDiscCatchBgTemplates templates = gPokeathlonDiscCatchBgTemplates;
    for (i = 0; i < 7; i++) {
        InitBgFromTemplate(bgConfig, gPokeathlonDiscCatchBgLayers[i], &templates.templates[i], GF_BG_TYPE_TEXT);
        BgClearTilemapBufferAndCommit(bgConfig, gPokeathlonDiscCatchBgLayers[i]);
        BG_ClearCharDataRange(gPokeathlonDiscCatchBgLayers[i], 0x20, 0, heapId);
    }
    work->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, NARC_msg_msg_0309_bin, work->heapId);
    work->messageFormat = MessageFormat_New(work->heapId);
    FontID_Alloc(4, work->heapId);
    GfGfx_EngineATogglePlanes(GX_PLANEMASK_BG2, GF_PLANE_TOGGLE_OFF);
}

static void PokeathlonDiscCatch_FreeBgs(PokeathlonDiscCatch *work) {
    int i;

    RemoveWindow(&work->window);
    MessageFormat_Delete(work->messageFormat);
    DestroyMsgData(work->msgData);
    for (i = 0; i < 7; i++) {
        FreeBgTilemapBuffer(work->bgConfig, gPokeathlonDiscCatchBgLayers[i]);
    }
    FontID_Release(4);
    Heap_Free(work->bgConfig);
}

static void PokeathlonDiscCatch_LoadBgGraphics(PokeathlonDiscCatch *work) {
    GfGfxLoader_LoadCharData(NARC_a_2_3_5, 4, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_5, 2, work->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_5, 5, work->bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_5, 1, work->bgConfig, GF_BG_LYR_MAIN_1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_3_5, 0, GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_0_OFFSET, 0, work->heapId);
    ScheduleSetBgPosText(work->bgConfig, GF_BG_LYR_MAIN_1, BG_POS_OP_ADD_Y, 8);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, work->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_5, 4, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_5, 11, work->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadCharData(NARC_a_2_3_5, 11, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_5, 5, work->bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_5, 12, work->bgConfig, GF_BG_LYR_SUB_1, 0, 0, TRUE, work->heapId);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_5, 13, work->bgConfig, GF_BG_LYR_SUB_2, 0, 0, TRUE, work->heapId);
    GfGfxLoader_GXLoadPal(NARC_a_2_3_5, 3, GF_PAL_LOCATION_SUB_BG, GF_PAL_SLOT_0_OFFSET, 0, work->heapId);
}

// The water of both screens' background: the next of 6 tilemaps every 4 frames.
static void PokeathlonDiscCatch_AnimateBg(u8 *timer, BgConfig *bgConfig, enum HeapID heapId) {
    GF_ASSERT(timer != NULL);
    GF_ASSERT(bgConfig != NULL);

    timer[0]++;
    if (timer[0] >= 4) {
        GfGfxLoader_LoadScrnData(NARC_a_2_3_5, timer[1] + 5, bgConfig, GF_BG_LYR_MAIN_0, 0, 0, TRUE, heapId);
        GfGfxLoader_LoadScrnData(NARC_a_2_3_5, timer[1] + 5, bgConfig, GF_BG_LYR_SUB_0, 0, 0, TRUE, heapId);
        timer[1] = (timer[1] + 1) % 6;
        timer[0] = 0;
    }
}

// Host: counts the time down, takes in the participants' touches, runs the field and writes the frame packet.
static void PokeathlonDiscCatch_UpdateHost(PokeathlonCourseData *course) {
    PokeathlonDiscCatch *work = PokeathlonCourse_GetWork(course);
    u8 *area = PokeathlonCourse_GetDataCopyArea(course);
    int seconds, i;
    PokeathlonDiscCatchFrame *frame;
    u8 *input;
    PokeathlonDiscCatchTeam *team;

    if (PokeathlonCourse_GetNetId(course)) {
        return;
    }
    seconds = 0;
    frame = (PokeathlonDiscCatchFrame *)PokeathlonCourse_ToBytes(area + POKEATHLON_COURSE_DATA_FRAME_OUT);
    if (frame->finished) {
        PokeathlonDiscCatch_WriteFramePacket(&work->field, course);
        return;
    }
    if (work->timer > 0) {
        work->timer--;
        seconds = (work->timer + 30) / 30;
        frame->seconds = seconds;
    }
    {
        PokeathlonDiscCatchFrame *dest = (PokeathlonDiscCatchFrame *)PokeathlonCourse_ToBytes(area + POKEATHLON_COURSE_DATA_INPUTS);
        PokeathlonDiscCatchFrame *src = (PokeathlonDiscCatchFrame *)PokeathlonCourse_ToBytes(area);
        *dest = *src;
    }
    i = 0;
    input = area + POKEATHLON_COURSE_DATA_INPUTS;
    team = work->field.teams;
    for (; i < POKEATHLON_PARTICIPANTS; i++) {
        PokeathlonDiscCatchFrame *touch = (PokeathlonDiscCatchFrame *)PokeathlonCourse_ToBytes(input);
        if (touch->touching) {
            if (team->touchNew && team->touching) {
                team->touchNew = FALSE;
            } else if (!team->touchNew && !team->touching) {
                team->touchNew = TRUE;
                team->touching = TRUE;
            }
            team->touchX = touch->touchX;
            team->touchY = touch->touchY;
            team->touchFrames++;
        } else {
            team->lastTouchFrames = team->touchFrames;
            team->touchFrames = 0;
            team->touchNew = FALSE;
            team->touching = FALSE;
        }
        input += POKEATHLON_COURSE_DATA_SLOT_SIZE;
        team++;
    }
    PokeathlonDiscCatchCpu_Update(work->cpu);
    PokeathlonDiscCatchDiscs_Update(&work->discs, area, seconds);
    PokeathlonDiscCatch_UpdateField(work->field.teams, course);
    if (work->timer <= 0) {
        frame->finished = TRUE;
    }
    PokeathlonDiscCatch_WriteFramePacket(&work->field, course);
}
