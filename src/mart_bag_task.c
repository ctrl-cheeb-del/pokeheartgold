#include "mart_bag_task.h"

#include "global.h"

#include "field/fieldmap.h"

#include "bag_view.h"
#include "heap.h"
#include "overlay_03.h"
#include "task.h"

static BOOL MartBag_WaitBagViewExit(FieldSystem *fieldSystem, MartData *martData);
static void MartBag_ReturnToMart(TaskManager *taskManager);

BOOL Task_MartBag(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    MartData *martData = TaskManager_GetEnvironment(taskManager);
    switch (martData->state) {
    case 24:
        martData->state = MartBag_WaitBagViewExit(fieldSystem, martData);
        break;
    case 25:
        MartBag_ReturnToMart(taskManager);
        break;
    }
    return FALSE;
}

static BOOL MartBag_WaitBagViewExit(FieldSystem *fieldSystem, MartData *martData) {
    if (FieldSystem_ApplicationIsRunning(fieldSystem)) {
        return 24;
    }
    if (martData->result != NULL) {
        martData->result[1] = BagView_GetSellCount(martData->bagView);
    }
    Heap_Free(martData->bagView);
    FieldSystem_LoadFieldOverlay(fieldSystem);
    return 25;
}

static void MartBag_ReturnToMart(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    MartData *martData = TaskManager_GetEnvironment(taskManager);
    if (FieldSystem_IsOverworldRestored(fieldSystem)) {
        FieldMap_FadeScreen(1);
        TaskManager_Jump(taskManager, Task_Mart, martData);
        martData->state = 26;
    }
}
