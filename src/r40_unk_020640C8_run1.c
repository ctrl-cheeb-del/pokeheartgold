#include "r40_unk_020640C8_private.h"

BOOL CheckSeenByNpcTrainers(FSYS *fsys, MOM *manager, PAV *avatar, LMO *exclude, EngageParams *out) {
    int x;
    int index = 0;
    int direction;
    LMO *object = NULL;

    if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, 1) != NULL) {
        do {
            if (exclude == NULL || exclude != object) {
                x = sub_020642C4(object, avatar, &direction);
                if (x != -1) {
                    if (!TrainerFlagCheck(((FsysPriv *)fsys)->unkC, (u16)MapObject_GetTrainerNum(object))) {
                        GetEngagingTrainerParams(out, object, x, direction);
                        return TRUE;
                    }
                }
            }
        } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &object, &index, 1) != NULL);
    }
    return FALSE;
}
