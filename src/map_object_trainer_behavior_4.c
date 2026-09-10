#include "map_object_trainer_behavior_internal.h"

void GetEngagingTrainerParams(EngageParams *out, LMO *obj, int x, int z) {
    out->x = x;
    out->z = z;
    out->scriptId = MapObject_GetScriptID(obj);
    out->trainerNum = ScriptNumToTrainerNum((u16)out->scriptId);
    out->isDouble = TrainerNumIsDouble((u16)out->trainerNum);
    out->obj = obj;
}

int sub_02064298(LMO *obj) {
    int type = MapObject_GetType(obj);
    switch (type) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        type = 1;
        break;
    }
    return type;
}
