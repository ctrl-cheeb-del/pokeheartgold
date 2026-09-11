#include "field_task_launch_internal.h"
#include "heap.h"

void sub_02059D44(FieldSystem *fieldSystem) {
    int i;
    u32 localPlayer = sub_0203769C();
    int group = sub_02057ADC();
    int position = sub_02057B14(localPlayer);

    for (i = 0; i < sub_02037454(); i++) {
        if (i != localPlayer && group == sub_02057A34(i) && position == sub_02057A88(i)) {
            TrainerCardTaskEnv *env = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(TrainerCardTaskEnv));
            env->player = i;
            env->state = 0;
            FieldSystem_CreateTask(fieldSystem, sub_02059B64, env);
            sub_0203E2F4();
            return;
        }
    }
}
