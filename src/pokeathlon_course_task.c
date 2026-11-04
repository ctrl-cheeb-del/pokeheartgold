#include "pokeathlon_course_task.h"

#include "global.h"

#include "field_system.h"
#include "heap.h"
#include "launch_application.h"
#include "task.h"

enum {
    COURSE_TASK_STATE_LAUNCH_APP,
    COURSE_TASK_STATE_WAIT_APP,
    COURSE_TASK_STATE_WAIT_FIELD,
    COURSE_TASK_STATE_FINISH,
};

typedef struct PokeathlonCourseTaskEnv {
    u32 state;
    PokeathlonCourseArgs *args;
    u32 mode;
    u16 course;
    u16 isSupreme;
    u16 *shouldFreeHeapOut;
    u16 *totalPointsOut;
    u16 *pointsOut;
    u16 *rankOut;
} PokeathlonCourseTaskEnv;

static BOOL Task_PokeathlonCourse(TaskManager *taskman);

void CallTask_PokeathlonCourse(FieldSystem *fieldSystem, u8 mode, u8 isSupreme, u8 course, u16 *shouldFreeHeapOut, u16 *totalPointsOut, u16 *pointsOut, u16 *rankOut) {
    PokeathlonCourseTaskEnv *work = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(PokeathlonCourseTaskEnv));
    work->state = COURSE_TASK_STATE_LAUNCH_APP;
    work->mode = mode;
    work->isSupreme = isSupreme;
    work->course = course;
    work->shouldFreeHeapOut = shouldFreeHeapOut;
    work->totalPointsOut = totalPointsOut;
    work->pointsOut = pointsOut;
    work->rankOut = rankOut;
    TaskManager_Call(fieldSystem->taskman, Task_PokeathlonCourse, work);
}

static BOOL Task_PokeathlonCourse(TaskManager *taskman) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskman);
    PokeathlonCourseTaskEnv *work = TaskManager_GetEnvironment(taskman);
    switch (work->state) {
    case COURSE_TASK_STATE_LAUNCH_APP:
        work->args = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(PokeathlonCourseArgs));
        work->args->mode = (work->mode != 0);
        work->args->saveData = FieldSystem_GetSaveData(fieldSystem);
        work->args->course = work->course;
        work->args->isSupreme = work->isSupreme;
        PokeathlonCourse_LaunchApp(fieldSystem, work->args);
        FieldSystem_ResumeProcesses();
        work->state = COURSE_TASK_STATE_WAIT_APP;
        break;
    case COURSE_TASK_STATE_WAIT_APP:
        if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
            break;
        }
        work->state = COURSE_TASK_STATE_WAIT_FIELD;
        FieldSystem_LoadFieldOverlay(fieldSystem);
        break;
    case COURSE_TASK_STATE_WAIT_FIELD:
        if (!FieldSystem_IsOverworldRestored(fieldSystem)) {
            break;
        }
        work->state = COURSE_TASK_STATE_FINISH;
        break;
    case COURSE_TASK_STATE_FINISH:
        *work->shouldFreeHeapOut = work->args->shouldFreeHeap;
        *work->totalPointsOut = work->args->totalPoints;
        *work->pointsOut = work->args->points;
        *work->rankOut = work->args->rank;
        Heap_Free(work->args);
        Heap_Free(work);
        return TRUE;
    }
    return FALSE;
}
