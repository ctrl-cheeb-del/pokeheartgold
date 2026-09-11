#include "area_light_tasks_internal.h"
#include "field_bgm.h"
#include "field_warp_tasks.h"
#include "heap.h"
#include "screen_fade.h"
#include "sound.h"
#include "sound_02004A44.h"
#include "unk_02005D10.h"
#include "unk_02055418.h"

void sub_020979A8(FieldSystem *fieldSystem, u8 param1, u8 param2, u32 mapId, u32 x, u32 y) {
    AreaLightTaskEnv *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(AreaLightTaskEnv));

    env->param1 = param1;
    env->param2 = param2;
    env->mapId = mapId;
    env->x = x;
    env->y = y;
    LoadAreaOrDungeonLightTxt(0, &env->light);
    env->state = 0;
    TaskManager_Call(fieldSystem->taskman, sub_02097AA0, env);
}

void sub_020979EC(FieldSystem *fieldSystem, u8 param, void *destination) {
    NightTaskEnv *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(NightTaskEnv));

    env->destination = destination;
    env->param = param;
    switch (Field_GetTimeOfDay(fieldSystem)) {
    case RTC_TIMEOFDAY_MORN:
    case RTC_TIMEOFDAY_DAY:
        env->night = FALSE;
        break;
    case RTC_TIMEOFDAY_EVE:
    case RTC_TIMEOFDAY_NITE:
    case RTC_TIMEOFDAY_LATE:
        env->night = TRUE;
        break;
    default:
        GF_ASSERT(FALSE);
        env->night = FALSE;
        break;
    }
    TaskManager_Call(fieldSystem->taskman, sub_02097A48, env);
}

BOOL sub_02097A48(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    NightTaskEnv *env = TaskManager_GetEnvironment(taskManager);
    u32 *state = TaskManager_GetStatePtr(taskManager);

    switch (*state) {
    case 0:
        sub_0203FC90(fieldSystem, env);
        break;
    case 1:
        if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
            return FALSE;
        }
        break;
    case 2:
        Heap_Free(env);
        return TRUE;
    }
    (*state)++;
    return FALSE;
}

BOOL sub_02097AA0(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    AreaLightTaskEnv *env = TaskManager_GetEnvironment(taskManager);

    switch (env->state) {
    case 0:
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, 0, 6, 1, HEAP_ID_FIELD2);
        GF_SndStartFadeOutBGM(0, 6);
        env->state = 1;
        break;
    case 1:
        if (!IsPaletteFadeFinished() || GF_SndGetFadeTimer() != 0) {
            return FALSE;
        }
        StopBGM(GF_GetCurrentPlayingBGM(), 0);
        CallTask_LeaveOverworld(taskManager);
        env->state = 2;
        break;
    case 2:
        sub_020979EC(fieldSystem, env->param1, &env->light);
        env->state = 3;
        break;
    case 3:
        sub_020537F0(taskManager, env->mapId, -1, env->x, env->y, env->param2);
        env->state = 4;
        break;
    case 4:
        FieldBGM_PlayForMapHeader(fieldSystem, env->mapId, FALSE);
        sub_02055408(taskManager);
        env->state = 5;
        break;
    case 5:
        Heap_Free(env);
        return TRUE;
    }
    return FALSE;
}
