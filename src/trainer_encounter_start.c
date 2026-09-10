#include "trainer_encounter_start_internal.h"

BOOL TryGetSeenByNpcTrainers(FSYS *fsys, BOOL doublesEligible) {
    EngageParams first;
    EngageParams second;
    EngageParams partner;
    FsysPriv *priv = (FsysPriv *)fsys;
    PAV *avatar = priv->unk40;
    MOM *manager = priv->unk3C;

    if (!CheckSeenByNpcTrainers(fsys, manager, avatar, NULL, &first)) {
        return FALSE;
    }
    if (first.isDouble == 0) {
        StartMapSceneScript(fsys, std_trainer_approach, first.obj);
        if (!doublesEligible || !CheckSeenByNpcTrainers(fsys, manager, avatar, first.obj, &second)) {
            FieldSystem_SetEngagedTrainer(fsys, first.obj, first.x, first.z, first.scriptId, first.trainerNum, 0, 0);
            return TRUE;
        }
        FieldSystem_SetEngagedTrainer(fsys, first.obj, first.x, first.z, first.scriptId, first.trainerNum, 2, 0);
        FieldSystem_SetEngagedTrainer(fsys, second.obj, second.x, second.z, second.scriptId, second.trainerNum, 2, 1);
        return TRUE;
    }
    if (first.isDouble == 1) {
        if (!doublesEligible) {
            return FALSE;
        }
        GetEngagingTrainerParams(&partner, (LMO *)sub_02064520(fsys, manager, first.obj, first.trainerNum), first.x, first.z);
        StartMapSceneScript(fsys, std_trainer_approach, first.obj);
        FieldSystem_SetEngagedTrainer(fsys, first.obj, first.x, first.z, first.scriptId, first.trainerNum, 1, 0);
        FieldSystem_SetEngagedTrainer(fsys, partner.obj, partner.x, partner.z, partner.scriptId, partner.trainerNum, 1, 1);
        return TRUE;
    }
    GF_AssertFail();
    return FALSE;
}
