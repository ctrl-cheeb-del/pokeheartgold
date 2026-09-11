#ifndef SOL40_UNK_02092B04_PRIVATE_H
#define SOL40_UNK_02092B04_PRIVATE_H
#include "global.h"
#include "task.h"
#include "bag_view.h"
#include "heap.h"
#include "field/fieldmap.h"
#include "overlay_03.h"
#include "unk_02092B04.h"
typedef struct MartReturnEnv {
    u8 pad00[4];
    BagView *bagView;
    u8 pad08[0x26A];
    u8 state;
    u8 pad273[0x2D];
    u16 *result;
} MartReturnEnv;
BOOL sub_02092B40(FieldSystem *fieldSystem, MartReturnEnv *env);
void sub_02092B7C(TaskManager *taskManager);
#endif
