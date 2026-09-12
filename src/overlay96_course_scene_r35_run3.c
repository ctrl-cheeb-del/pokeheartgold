#include "overlay96_course_scene_r35_private.h"

u32 ov96_021EC1B0(void *course, u8 *state) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);

    ov96_021ED0C8(PTR_AT(work, 0x90));
    switch (*state) {
    case 0:
        BeginNormalPaletteFade((enum FadeMode)0, (enum FadeType)0, (enum FadeType)0, 0x7FFF, 0x1E, 1, (enum HeapID)PokeathlonCourse_GetHeapID(course));
        GF_SndStartFadeOutBGM(0, 0x1E);
        (*state)++;
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            return 1;
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return 0;
}

void ov96_021EC218(SysTask *task, void *data) {
    Ov96CourseSceneCryTask *work = data;
    void *sprite = work->sprite;

    switch (work->state) {
    case 0:
        ov96_021EAC0C(sprite, 2);
        ov96_021EAC5C(sprite, 0x10);
        work->state++;
        break;
    case 1:
        if (work->timer++ > 0x3C) {
            work->state++;
        }
        break;
    case 2:
        if (!ov96_021EAD78(sprite) && !IsCryFinished()) {
            ov96_021EAC0C(sprite, 1);
            ov96_021EAC5C(sprite, 0);
            *work->active = 0;
            Heap_Free(work);
            SysTask_Destroy(task);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void ov96_021EC298(void *work, u8 index) {
    Ov96CourseSceneCryTask *taskWork = Heap_AllocAtEnd((enum HeapID) * (u32 *)work, sizeof(Ov96CourseSceneCryTask));

    MI_CpuFill8(taskWork, 0, sizeof(Ov96CourseSceneCryTask));
    PTR_AT(work, 0x88) = taskWork;
    taskWork->sprite = ov96_021EAA04(PTR_AT(work, 0x14), index);
    U32_AT(work, 0x98) = 1;
    taskWork->active = (u32 *)((u8 *)work + 0x98);
    PTR_AT(work, 8) = SysTask_CreateOnMainQueue(ov96_021EC218, taskWork, 1);
}
