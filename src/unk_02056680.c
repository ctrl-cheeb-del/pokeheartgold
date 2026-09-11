#include "unk_02056680_internal.h"

BOOL sub_02056680(TaskManager *taskManager) {
    u8 *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    TransitionEnv *env = TaskManager_GetEnvironment(taskManager);
    switch (env->state) {
    case 0: {
        int x;
        env->work = ov01_021E90C0();
        x = PlayerAvatar_GetXCoord(*(void **)(fieldSystem + 0x40));
        ov01_021E90DC(x, PlayerAvatar_GetZCoord(*(void **)(fieldSystem + 0x40)), env->work);
        env->state++;
        break;
    }
    case 1: {
        TransitionWork *work = env->work;
        int direction = PlayerAvatar_GetFacingDirection(*(PlayerAvatar **)(fieldSystem + 0x40));
        if (ov01_021E971C(fieldSystem, work, direction)) {
            ov01_021E90D4(env->work);
            env->state++;
        }
        break;
    }
    case 2:
        return TRUE;
    }
    return FALSE;
}
