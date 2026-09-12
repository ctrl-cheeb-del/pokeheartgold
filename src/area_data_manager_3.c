#include <nitro/fx/fx_trig.h>
#include <nnsys/g3d.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/binres/res_struct_accessor_inline.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/gfd.h>
#include <nnsys/gfd/VramManager/gfd_PlttVramMan_Types.h>
#include <string.h>

#include "field/overlay_01_021FB878.h"

#include "area_data_manager_internal.h"
#include "assert.h"
#include "sys_task.h"

typedef struct FieldAnmRes {
    u32 unk0;
    u16 numFrames;
    u16 unk6;
} FieldAnmRes;

void ov01_021FB878(void *data, AreaDataTexBlockHeader *tex);
AreaDataManager *AreaDataManager_Alloc(u8 areaDataBank);
NARC *ov01_021FB904(AreaDataManager *areaDataManager);
NNSG3dResFileHeader **ov01_021FB90C(u32 fileId, AreaDataManager *areaDataManager);
NNSG3dResFileHeader **AreaDataManager_GetMapPropModelFile(AreaDataManager *areaDataManager);
void AreaDataManager_Free(AreaDataManager **areaDataManager);
NNSG3dResTex *AreaDataManager_GetMapTexture(AreaDataManager *areaDataManager);
NNSG3dResTex *ov01_021FB9E0(AreaDataManager *areaDataManager);
AreaDataManager_Sub8AC *ov01_021FB9F4(AreaDataManager *areaDataManager);
BOOL ov01_021FBA00(AreaDataManager *areaDataManager);
u32 AreaDataManager_GetAreaLightArchiveID(AreaDataManager *areaDataManager);
void AreaDataManager_Load(AreaDataManager *areaDataManager, void *unkC0, MapPropAnimationManager *mapPropAnimationManager, void *unkCC, void *unk104);
void Field3dModel_LoadFromFilesystem(Field3dModel *model, NarcId narcId, s32 fileId, enum HeapID heapID);
void ov01_021FBD38(Field3dModel *model, void *data);
void ov01_021FBD8C(SysTask *task, void *data);
void Field3dModel_Unload(Field3dModel *model);
void ov01_021FBDFC(Field3dModel *model);
void Field3dModelAnimation_LoadFromFilesystem(Field3DModelAnimation *anim, const Field3dModel *model, NarcId narcId, s32 fileId, enum HeapID heapID, NNSFndAllocator *alloc);
void ov01_021FBE70(Field3DModelAnimation *anim, Field3dModel *model, void *animRaw, NNSFndAllocator *alloc);
void Field3dModelAnimation_Unload(Field3DModelAnimation *anim, NNSFndAllocator *alloc);
BOOL Field3dModelAnimation_FrameAdvanceAndLoop(Field3DModelAnimation *anim, fx32 delta);
BOOL Field3dModelAnimation_FrameAdvanceAndCheck(Field3DModelAnimation *anim, fx32 delta);
void Field3dModelAnimation_FrameSet(Field3DModelAnimation *anim, fx32 frame);
fx32 ov01_021FBF28(Field3DModelAnimation *anim);
void Field3dObject_InitFromModel(Field3dObject *object, Field3dModel *model);
void Field3dObject_AddAnimation(Field3dObject *object, Field3DModelAnimation *anim);
void Field3dObject_RemoveAnimation(Field3dObject *object, Field3DModelAnimation *anim);
void Field3dObject_Draw(Field3dObject *object);
void Field3dObject_SetActiveFlag(Field3dObject *object, BOOL active);
BOOL Field3dObject_GetActiveFlag(Field3dObject *object);
void Field3dObject_SetPosEx(Field3dObject *object, fx32 x, fx32 y, fx32 z);
void Field3dObject_SetPos(Field3dObject *object, const VecFx32 *pos);
void Field3dObject_SetXRotation(Field3dObject *object, u16 angle, int axis);
void ov01_021FC030(Field3DModelAnimation *anim, const Field3dModel *model, void *fileData, NNSFndAllocator *alloc);

BOOL Field3dModelAnimation_FrameAdvanceAndCheck(Field3DModelAnimation *anim, fx32 delta) {
    fx32 numFrames = ((const FieldAnmRes *)anim->animObj->resAnm)->numFrames << FX32_SHIFT;
    BOOL ret = FALSE;
    if (delta > 0) {
        if (anim->frame + delta < numFrames) {
            anim->frame = anim->frame + delta;
        } else {
            anim->frame = numFrames;
            ret = TRUE;
        }
    } else {
        if (anim->frame + delta >= 0) {
            anim->frame = anim->frame + delta;
        } else {
            anim->frame = 0;
            ret = TRUE;
        }
    }
    anim->animObj->frame = anim->frame;
    return ret;
}

void Field3dModelAnimation_FrameSet(Field3DModelAnimation *anim, fx32 frame) {
    anim->frame = frame;
    anim->animObj->frame = frame;
}

fx32 ov01_021FBF28(Field3DModelAnimation *anim) {
    return anim->frame;
}

void Field3dObject_InitFromModel(Field3dObject *object, Field3dModel *model) {
    memset(object, 0, sizeof(Field3dObject));
    NNS_G3dRenderObjInit(&object->renderObj, model->model);
    object->active = TRUE;
    object->scale.x = FX32_ONE;
    object->scale.y = FX32_ONE;
    object->scale.z = FX32_ONE;
}

void Field3dObject_AddAnimation(Field3dObject *object, Field3DModelAnimation *anim) {
    NNS_G3dRenderObjAddAnmObj(&object->renderObj, anim->animObj);
}

void Field3dObject_RemoveAnimation(Field3dObject *object, Field3DModelAnimation *anim) {
    NNS_G3dRenderObjRemoveAnmObj(&object->renderObj, anim->animObj);
}

void Field3dObject_Draw(Field3dObject *object) {
    MtxFx33 rot;
    MtxFx33 tmp;

    if (object->active) {
        MTX_Identity33_(&rot);
        MTX_RotX33_(&tmp, FX_SinIdx(object->rotation[0]), FX_CosIdx(object->rotation[0]));
        MTX_Concat33(&tmp, &rot, &rot);
        MTX_RotZ33_(&tmp, FX_SinIdx(object->rotation[2]), FX_CosIdx(object->rotation[2]));
        MTX_Concat33(&tmp, &rot, &rot);
        MTX_RotY33_(&tmp, FX_SinIdx(object->rotation[1]), FX_CosIdx(object->rotation[1]));
        MTX_Concat33(&tmp, &rot, &rot);
        GF3dRender_DrawModel(&object->renderObj, &object->matrix, &rot, &object->scale);
    }
}

void Field3dObject_SetActiveFlag(Field3dObject *object, BOOL active) {
    object->active = active;
}

BOOL Field3dObject_GetActiveFlag(Field3dObject *object) {
    return object->active;
}

void Field3dObject_SetPosEx(Field3dObject *object, fx32 x, fx32 y, fx32 z) {
    object->matrix.x = x;
    object->matrix.y = y;
    object->matrix.z = z;
}

void Field3dObject_SetPos(Field3dObject *object, const VecFx32 *pos) {
    object->matrix = *pos;
}

void Field3dObject_SetXRotation(Field3dObject *object, u16 angle, int axis) {
    object->rotation[axis] = angle;
}

void ov01_021FC030(Field3DModelAnimation *anim, const Field3dModel *model, void *fileData, NNSFndAllocator *alloc) {
    anim->fileDataRaw = fileData;
    anim->animRaw = NNS_G3dGetAnmByIdx(fileData, 0);
    anim->animObj = NNS_G3dAllocAnmObj(alloc, anim->animRaw, model->model);
    NNS_G3dAnmObjInit(anim->animObj, anim->animRaw, model->model, model->texture);
}
