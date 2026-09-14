#include "global.h"

#include "nnsys/g3d/binres/res_struct_accessor.h"
#include "nnsys/g3d/binres/res_struct_accessor_anm.h"
#include "nnsys/g3d/kernel.h"
#include "nnsys/g3d/mem.h"
#include "nnsys/g3d/model_inline.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_3d_render.h"
#include "heap.h"

typedef struct BagModelR22 {
    NNSG3dRenderObj render;
    void *model;
    void *modelData;
    void *animData1[8];
    void *animData2[8];
    void *extraAnimData;
    NNSG3dAnmObj *anim1[8];
    NNSG3dAnmObj *anim2[8];
    NNSG3dAnmObj *extraAnim;
    u32 current;
} BagModelR22;

typedef struct BagWorkR22 {
    BgConfig *bgConfig;
    Window windows[11];
    Window listWindows[24];
} BagWorkR22;

void ov15_021FDD70(void *work);
void ov15_021FDF20(void *work);
void ov15_021FDF88(void *work);
void ov15_021FE020(BagWorkR22 *work);

void ov15_021FDD70(void *work) {
    NARC *narc = NARC_New((NarcId)0xF, (enum HeapID)6);
    BagModelR22 *model;
    NNSG3dResTex *tex;
    void *anm1;
    void *anm2;
    u32 animMember1;
    u32 animMember2;
    u32 extraMember;
    u32 modelMember;
    u32 i;

    HeapExp_FndInitAllocator((NNSFndAllocator *)((u8 *)work + 0x808), (enum HeapID)6, 4);
    model = (BagModelR22 *)((u8 *)work + 0x81C);
    if (*(u8 *)((u8 *)work + 0x615) == 0) {
        animMember1 = 0x39;
        animMember2 = 0x41;
        modelMember = 0x37;
        extraMember = 0x49;
    } else {
        animMember1 = 0x4C;
        animMember2 = 0x54;
        modelMember = 0x4A;
        extraMember = 0x5C;
    }
    model->modelData = NARC_AllocAndReadWholeMember(narc, modelMember, (enum HeapID)6);
    GF3dRender_InitObjFromHeader(&model->render, (NNSG3dResMdl **)&model->model, (NNSG3dResFileHeader **)&model->modelData);
    tex = NNS_G3dGetTex(model->modelData);
    NNSi_G3dModifyMatFlag(model->model, TRUE, NNS_G3D_MATFLAG_DIFFUSE);
    NNSi_G3dModifyMatFlag(model->model, TRUE, NNS_G3D_MATFLAG_AMBIENT);
    NNSi_G3dModifyMatFlag(model->model, TRUE, NNS_G3D_MATFLAG_SPECULAR);
    NNSi_G3dModifyMatFlag(model->model, TRUE, NNS_G3D_MATFLAG_EMISSION);
    NNSi_G3dModifyPolygonAttrMask(model->model, TRUE, 0x3F000000);
    for (i = 0; i < 8; i++) {
        model->animData1[i] = NARC_AllocAndReadWholeMember(narc, animMember1 + i, (enum HeapID)6);
        anm1 = NNS_G3dGetAnmByIdx(model->animData1[i], 0);
        model->anim1[i] = NNS_G3dAllocAnmObj((NNSFndAllocator *)((u8 *)work + 0x808), anm1, model->model);
        NNS_G3dAnmObjInit(model->anim1[i], anm1, model->model, tex);
        model->animData2[i] = NARC_AllocAndReadWholeMember(narc, animMember2 + i, (enum HeapID)6);
        anm2 = NNS_G3dGetAnmByIdx(model->animData2[i], 0);
        model->anim2[i] = NNS_G3dAllocAnmObj((NNSFndAllocator *)((u8 *)work + 0x808), anm2, model->model);
        NNS_G3dAnmObjInit(model->anim2[i], anm2, model->model, tex);
    }
    model->extraAnimData = NARC_AllocAndReadWholeMember(narc, extraMember, (enum HeapID)6);
    anm1 = NNS_G3dGetAnmByIdx(model->extraAnimData, 0);
    model->extraAnim = NNS_G3dAllocAnmObj((NNSFndAllocator *)((u8 *)work + 0x808), anm1, model->model);
    NNS_G3dAnmObjInit(model->extraAnim, anm1, model->model, tex);
    model->current = *((u8 *)(*(void **)((u8 *)work + 0x234)) + 0x64);
    NNS_G3dRenderObjAddAnmObj(&model->render, model->anim1[model->current]);
    NNS_G3dRenderObjAddAnmObj(&model->render, model->anim2[model->current]);
    NNS_G3dRenderObjAddAnmObj(&model->render, model->extraAnim);
    NARC_Delete(narc);
}

void ov15_021FDF20(void *work) {
    BagModelR22 *model = (BagModelR22 *)((u8 *)work + 0x81C);
    u32 i;

    for (i = 0; i < 8; i++) {
        NNS_G3dFreeAnmObj((NNSFndAllocator *)((u8 *)work + 0x808), model->anim1[i]);
        NNS_G3dFreeAnmObj((NNSFndAllocator *)((u8 *)work + 0x808), model->anim2[i]);
        Heap_Free(model->animData1[i]);
        Heap_Free(model->animData2[i]);
    }
    NNS_G3dFreeAnmObj((NNSFndAllocator *)((u8 *)work + 0x808), model->extraAnim);
    Heap_Free(model->extraAnimData);
    Heap_Free(model->modelData);
}

void ov15_021FDF88(void *work) {
    BagModelR22 *model = (BagModelR22 *)((u8 *)work + 0x81C);

    NNS_G3dRenderObjRemoveAnmObj(&model->render, model->anim2[model->current]);
    NNS_G3dRenderObjRemoveAnmObj(&model->render, model->anim1[model->current]);
    model->current = *((u8 *)(*(void **)((u8 *)work + 0x234)) + 0x64);
    model->anim1[model->current]->frame = 0;
    model->anim2[model->current]->frame = 0;
    model->extraAnim->frame = 0;
    NNS_G3dRenderObjAddAnmObj(&model->render, model->anim1[model->current]);
    NNS_G3dRenderObjAddAnmObj(&model->render, model->anim2[model->current]);
}

void ov15_021FE020(BagWorkR22 *work) {
    int i;

    AddWindowParameterized(work->bgConfig, &work->windows[0], 1, 0, 0x12, 0x20, 6, 4, 1);
    AddWindowParameterized(work->bgConfig, &work->windows[1], 1, 0, 0xD, 0x20, 4, 4, 0xC1);
    AddWindowParameterized(work->bgConfig, &work->windows[2], 4, 2, 1, 0x1B, 2, 0xB, 1);
    AddWindowParameterized(work->bgConfig, &work->windows[3], 4, 2, 1, 0x1B, 4, 0xB, 0x53);
    AddWindowParameterized(work->bgConfig, &work->windows[4], 1, 0x13, 0xD, 0xC, 4, 4, 0xDB);
    AddWindowParameterized(work->bgConfig, &work->windows[5], 1, 1, 0xC, 0xB, 4, 4, 0x12B);
    AddWindowParameterized(work->bgConfig, &work->windows[6], 4, 0xA, 0x15, 7, 2, 0xB, 0x37);
    FillWindowPixelBuffer(&work->windows[6], 0);
    AddWindowParameterized(work->bgConfig, &work->windows[7], 4, 0x18, 0x15, 7, 2, 0xB, 0x45);
    FillWindowPixelBuffer(&work->windows[7], 0);

    for (i = 0; i < 24; i++) {
        work->listWindows[i].bgConfig = NULL;
    }
}
