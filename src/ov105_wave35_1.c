#include "ov105_wave35_private.h"
extern const MtxFx33 ov105_021E5E08;
extern const VecFx32 ov105_021E5DD4;

BOOL ov105_021E59DC(OverlayManager *man, u32 *state) {
    u8 i;
    Ov105ModelSet *ms;
    Ov105App *app;
    Ov105AnmObjRaw *anm;
    fx32 frame;
    BOOL done;
    MtxFx33 rotation;
    VecFx32 scale;

    app = OverlayManager_GetData(man);
    done = FALSE;
    ms = &app->models[app->unk9F];
    switch (*state) {
    case 0:
        anm = (Ov105AnmObjRaw *)ms->anmObj[0];
        if (anm->frame + FX32_ONE == anm->res->numFrames * FX32_ONE) {
            sub_020880CC(1, (enum HeapID)0x97);
            (*state)++;
        }
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            app->unk9F++;
            app->unkA0++;
            if (app->unkA0 >= 1) {
                done = TRUE;
            } else {
                ov105_021E5BCC(app);
                sub_020880CC(done, (enum HeapID)0x97);
                *state = done;
            }
        }
        break;
    }
    app->unkA1++;
    if (app->unkA1 == 30) {
        PlaySE((u16)app->seTable[app->unk9F]);
    }
    for (i = 0; i < 4; i++) {
        anm = (Ov105AnmObjRaw *)ms->anmObj[i];
        frame = anm->frame + FX32_ONE;
        if (frame < anm->res->numFrames * FX32_ONE) {
            anm->frame = frame;
        }
    }
    rotation = ov105_021E5E08;
    scale = ov105_021E5DD4;
    {
        VecFx32 translation = { 0, 0, 0 };
        Thunk_G3X_Reset();
        Camera_PushLookAtToNNSGlb();
        GF3dRender_DrawModel(&ms->renderObj, &translation, &rotation, &scale);
        RequestSwap3DBuffers(TRUE, TRUE);
    }
    return done;
}
