#include "overlay104_scene_internal.h"

BOOL ov104_021E5900(OverlayManager *man, int *state);
BOOL ov104_021E59E4(OverlayManager *man, int *state);
BOOL ov104_021E5B14(OverlayManager *man, int *state);
void ov104_021E5B88(void);
void ov104_021E5BEC(Ov104Work *work);
void ov104_021E5CA8(void);
void ov104_021E5CC8(Ov104Work *work);
BOOL ov104_021E5E78(Ov104Model *model, int idx);
void ov104_021E5EB0(int idx, enum HeapID heapId);

static const u32 sSeTableA[3] = { 0x6D5, 0x6F3, 0x6F1 };
static const VecFx32 sModelScale = { FX32_ONE, FX32_ONE, FX32_ONE };
static const u32 sSeTableB[3] = { 0x6D6, 0x6F2, 0x6F0 };
static const GXRgb sEdgeColors[8] = { 0x0000, 0x1084, 0x1084, 0x1084, 0x1084, 0x1084, 0x1084, 0x1084 };
static const u16 sClipPlanes[2][3][2] = {
    { { 0x0096, 0x06A4 }, { 0x0096, 0x0384 }, { 0x0096, 0x0384 } },
    { { 0x0096, 0x06A4 }, { 0x0096, 0x0384 }, { 0x0096, 0x0384 } },
};
static const MtxFx33 sIdentityRot = {
    {
     FX32_ONE,
     0,
     0,
     0,
     FX32_ONE,
     0,
     0,
     0,
     FX32_ONE,
     }
};
static const GraphicsBanks sBanks = {
    (GXVRamBG)0x04,
    (GXVRamBGExtPltt)0x00,
    (GXVRamSubBG)0x80,
    (GXVRamSubBGExtPltt)0x00,
    (GXVRamOBJ)0x20,
    (GXVRamOBJExtPltt)0x00,
    (GXVRamSubOBJ)0x100,
    (GXVRamSubOBJExtPltt)0x00,
    (GXVRamTex)0x03,
    (GXVRamTexPltt)0x10,
};
static const VecFx32 sCameraOffsets[2][3] = {
    { { 0x00065CA8, 0x0003C3AA, -0x00080AA2 },  { 0x00018000, 0x00039F71, -0x00051BCB }, { 0x00000000, 0x00013885, -0x0001C7CD } },
    { { -0x0005AA89, 0x0003C3AA, -0x00078FF3 }, { 0x00018000, 0x00039F71, -0x00051BCB }, { 0x00000000, 0x00013885, -0x0001C7CD } },
};
static const CameraParam sCameraParams[2][3] = {
    { { 0x001B8152, { 0xFAA2, 0xCAE0, 0x0000, 0x0000 }, 0x00, 0x08C1, 0x00 },
     { 0x0029AEC1, { 0xDC22, 0x0000, 0x0000, 0x0000 }, 0x00, 0x05C1, 0x00 },
     { 0x00299EC1, { 0xE002, 0x0000, 0x0000, 0x0000 }, 0x00, 0x06C1, 0x00 } },
    { { 0x001B8152, { 0xFAA2, 0x33E0, 0x0000, 0x0000 }, 0x00, 0x08C1, 0x00 },
     { 0x0029AEC1, { 0xDC22, 0x0000, 0x0000, 0x0000 }, 0x00, 0x05C1, 0x00 },
     { 0x00299EC1, { 0xE002, 0x0000, 0x0000, 0x0000 }, 0x00, 0x06C1, 0x00 } },
};

static Ov104ModelIds sModelIds_A[3] = {
    { 0x09, { 0x0A, 0x0B } },
    { 0x15, { 0x16, 0x17 } },
    { 0x1B, { 0x1C, 0x1D } }
};
static Ov104ModelIds sModelIds_B[3] = {
    { 0x24, { 0x25, 0x26 } },
    { 0x30, { 0x31, 0x32 } },
    { 0x39, { 0x3A, 0x3B } }
};
static Ov104ModelIds sModelIds_C[3] = {
    { 0x1E, { 0x1F, 0x20 } },
    { 0x2A, { 0x2B, 0x2C } },
    { 0x36, { 0x37, 0x38 } }
};
static Ov104ModelIds sModelIds_D[3] = {
    { 0x21, { 0x22, 0x23 } },
    { 0x2D, { 0x2E, 0x2F } },
    { 0x36, { 0x37, 0x38 } }
};
static Ov104ModelIds sModelIds_E[3] = {
    { 0x00, { 0x01, 0x02 } },
    { 0x0C, { 0x0D, 0x0E } },
    { 0x18, { 0x19, 0x1A } }
};
static Ov104ModelIds sModelIds_F[3] = {
    { 0x06, { 0x07, 0x08 } },
    { 0x12, { 0x13, 0x14 } },
    { 0x1B, { 0x1C, 0x1D } }
};
static Ov104ModelIds sModelIds_G[3] = {
    { 0x27, { 0x28, 0x29 } },
    { 0x33, { 0x34, 0x35 } },
    { 0x39, { 0x3A, 0x3B } }
};
static Ov104ModelIds sModelIds_H[3] = {
    { 0x03, { 0x04, 0x05 } },
    { 0x0F, { 0x10, 0x11 } },
    { 0x18, { 0x19, 0x1A } }
};

BOOL ov104_021E5900(OverlayManager *man, int *state) {
    Ov104Work *work;
    u8 i;
    Ov104Args *args;

    Heap_Create(HEAPID(3), HEAPID(0x95), 0x31000);
    work = OverlayManager_CreateAndGetData(man, sizeof(Ov104Work), HEAPID(0x95));
    memset(work, 0, sizeof(Ov104Work));
    args = OverlayManager_GetArgs(man);
    work->unk164 = args->unk0;
    work->unk165 = args->unk1;
    work->unk166 = args->unk2;
    work->unk167 = 0;
    work->camera = Camera_New(HEAPID(0x95));
    ov104_021E5B88();
    ov104_021E5CC8(work);
    ov104_021E5BEC(work);
    for (i = 0; i < 4; i++) {
        NNS_G3dGlbLightVector((GXLightId)i, args->lighting->lightVec[i].x, args->lighting->lightVec[i].y, args->lighting->lightVec[i].z);
        NNS_G3dGlbLightColor((GXLightId)i, args->lighting->lightColor[i]);
    }
    NNS_G3dGlbMaterialColorDiffAmb(args->lighting->diffuse, args->lighting->ambient, args->lighting->diffAmbFlag);
    NNS_G3dGlbMaterialColorSpecEmi(args->lighting->specular, args->lighting->emission, args->lighting->specEmiFlag);
    NNS_G3dGlbPolygonAttr(args->lighting->polygonAttr[0], (GXPolygonMode)args->lighting->polygonAttr[1], (GXCull)args->lighting->polygonAttr[2], args->lighting->polygonAttr[3], args->lighting->polygonAttr[4], args->lighting->polygonAttr[5]);
    BeginNormalPaletteFade(FADE_MAIN_ONLY, FADE_TYPE_BRIGHTNESS_IN, FADE_TYPE_BRIGHTNESS_IN, 0, 6, 1, HEAPID(0x95));
    return TRUE;
}

BOOL ov104_021E59E4(OverlayManager *man, int *state) {
    Ov104Model *model;
    Ov104Work *work;
    BOOL ret;
    u8 i;
    MtxFx33 rot;
    VecFx32 scale;

    work = OverlayManager_GetData(man);
    model = &work->models[work->step];
    ret = FALSE;
    switch (*state) {
    case 0:
        if (ov104_021E5E78(model, work->step)) {
            ov104_021E5EB0(work->step, HEAPID(0x95));
            (*state)++;
        }
        break;
    case 1:
        if (IsPaletteFadeFinished()) {
            work->step++;
            work->counter++;
            if (work->counter >= 3) {
                ret = TRUE;
            } else {
                ov104_021E5BEC(work);
                sub_020880CC(0, HEAPID(0x95));
                *state = 0;
            }
        }
        break;
    }
    if (((Ov104AnmObj *)model->anmObj[0])->frame == 0) {
        PlaySE((u16)work->seTable[work->step]);
        if (work->step == 2) {
            Sound_SetSceneAndPlayBGM(0x44, 0x447, 1);
        }
    }
    for (i = 0; i < 2; i++) {
        Ov104AnmObj *anmObj = model->anmObj[i];
        if (anmObj->frame + FX32_ONE < anmObj->anm->numFrames * FX32_ONE) {
            anmObj->frame = anmObj->frame + FX32_ONE;
        }
    }
    rot = sIdentityRot;
    scale = sModelScale;
    {
        VecFx32 pos = { 0, 0, 0 };
        Thunk_G3X_Reset();
        Camera_PushLookAtToNNSGlb();
        GF3dRender_DrawModel(&model->obj, &pos, &rot, &scale);
    }
    RequestSwap3DBuffers((GXSortMode)1, (GXBufferMode)1);
    return ret;
}

BOOL ov104_021E5B14(OverlayManager *man, int *state) {
    Ov104Work *work;
    Ov104Model *model;
    u8 i;
    u8 j;

    work = OverlayManager_GetData(man);
    for (i = 0; i < 3; i++) {
        model = &work->models[i];
        for (j = 0; j < 2; j++) {
            NNS_G3dFreeAnmObj(&work->allocator, model->anmObj[j]);
            Heap_Free(model->anmFile[j]);
        }
        Heap_Free(model->file);
    }
    Camera_Delete(work->camera);
    OverlayManager_FreeData(man);
    GF3dRender_DeleteSimpleManager();
    Heap_Destroy(HEAPID(0x95));
    return TRUE;
}

void ov104_021E5B88(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    ov104_021E5CA8();
    GF3dRender_InitSimpleManager(HEAPID(0x95));
    reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~0x3000) | 0x20);
    G3X_SetEdgeColorTable(sEdgeColors);
    GfGfx_SwapDisplay();
}

void ov104_021E5BEC(Ov104Work *work) {
    VecFx32 target = { 0, 0, 0 };
    u8 step;
    u8 scene;

    work->target = target;
    step = work->step;
    scene = work->unk164;
    Camera_Init_FromTargetDistanceAndAngle(&work->target, sCameraParams[scene][step].distance, &sCameraParams[scene][step].angle, sCameraParams[scene][step].perspective, sCameraParams[scene][step].perspectiveType, TRUE, work->camera);
    Camera_OffsetLookAtPosAndTarget(&sCameraOffsets[work->unk164][step], work->camera);
    Camera_SetPerspectiveClippingPlane(sClipPlanes[work->unk164][step][0] << FX32_SHIFT, sClipPlanes[work->unk164][step][1] << FX32_SHIFT, work->camera);
    Camera_SetStaticPtr(work->camera);
}

void ov104_021E5CA8(void) {
    GraphicsBanks banks = sBanks;
    GfGfx_SetBanks(&banks);
}

void ov104_021E5CC8(Ov104Work *work) {
    u8 i;
    u8 j;
    Ov104ModelIds *ids;
    void *tex;
    Ov104Model *model;
    Ov104ModelIds *entry;
    NARC *narc;

    narc = NARC_New((NarcId)0xEB, HEAPID(0x95));
    HeapExp_FndInitAllocator(&work->allocator, HEAPID(0x95), 4);
    if (work->unk164 == 0) {
        if (work->unk166 == 0) {
            if (work->unk165 == 0) {
                ids = sModelIds_E;
            } else {
                ids = sModelIds_H;
            }
        } else {
            if (work->unk165 == 0) {
                ids = sModelIds_F;
            } else {
                ids = sModelIds_A;
            }
        }
        work->seTable = sSeTableA;
    } else {
        if (work->unk166 == 0) {
            if (work->unk165 == 0) {
                ids = sModelIds_C;
            } else {
                ids = sModelIds_D;
            }
        } else {
            if (work->unk165 == 0) {
                ids = sModelIds_B;
            } else {
                ids = sModelIds_G;
            }
        }
        work->seTable = sSeTableB;
    }
    for (i = 0; i < 3; i++) {
        model = &work->models[i];
        entry = &ids[i];
        model->file = NARC_AllocAndReadWholeMember(narc, ids[i].modelFileId, HEAPID(0x95));
        GF3dRender_InitObjFromHeader(&model->obj, &model->mdl, &model->file);
        tex = NNS_G3dGetTex(work->models[i].file);
        if (i == 2) {
            NNSi_G3dModifyMatFlag(model->mdl, FALSE, (NNSG3dMatFlag)0x40);
            NNSi_G3dModifyMatFlag(model->mdl, FALSE, (NNSG3dMatFlag)0x80);
            NNSi_G3dModifyMatFlag(model->mdl, FALSE, (NNSG3dMatFlag)0x200);
            NNSi_G3dModifyMatFlag(model->mdl, FALSE, (NNSG3dMatFlag)0x400);
        }
        for (j = 0; j < 2; j++) {
            void *anm;
            model->anmFile[j] = NARC_AllocAndReadWholeMember(narc, entry->anmFileIds[j], HEAPID(0x95));
            anm = NNS_G3dGetAnmByIdx(model->anmFile[j], 0);
            model->anmObj[j] = NNS_G3dAllocAnmObj(&work->allocator, anm, model->mdl);
            NNS_G3dAnmObjInit(model->anmObj[j], anm, model->mdl, tex);
            NNS_G3dRenderObjAddAnmObj(&model->obj, model->anmObj[j]);
        }
    }
    NARC_Delete(narc);
}

BOOL ov104_021E5E78(Ov104Model *model, int idx) {
    if (idx + 1 >= 3) {
        if (((Ov104AnmObj *)model->anmObj[0])->frame + FX32_ONE == 205 * FX32_ONE) {
            return TRUE;
        }
    } else {
        if (((Ov104AnmObj *)model->anmObj[0])->frame + FX32_ONE == ((Ov104AnmObj *)model->anmObj[0])->anm->numFrames * FX32_ONE) {
            return TRUE;
        }
    }
    return FALSE;
}

void ov104_021E5EB0(int idx, enum HeapID heapId) {
    if (idx + 1 >= 3) {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_BRIGHTNESS_OUT, FADE_TYPE_BRIGHTNESS_OUT, 0, 6, 1, heapId);
    } else {
        BeginNormalPaletteFade(FADE_BOTH_SCREENS, FADE_TYPE_UNK_8, FADE_TYPE_BRIGHTNESS_OUT, 0, 6, 1, heapId);
    }
}
