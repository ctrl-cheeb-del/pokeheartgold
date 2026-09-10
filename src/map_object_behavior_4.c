#include "map_object_behavior_internal.h"

u32 MapObject_GetTrainerNum(LocalMapObject *object) {
    return ScriptNumToTrainerNum((u16)MapObject_GetScriptID(object));
}
