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
void Field3dModelAnimation_LoadFromFilesystem(Field3DModelAnimation *anim, Field3dModel *model, NarcId narcId, s32 fileId, enum HeapID heapID, NNSFndAllocator *alloc);
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
void ov01_021FC030(Field3DModelAnimation *anim, Field3dModel *model, void *fileData, NNSFndAllocator *alloc);

void Field3dModel_LoadFromFilesystem(Field3dModel *model, NarcId narcId, s32 fileId, enum HeapID heapID) {
    model->dataRaw = GfGfxLoader_LoadFromNarc(narcId, fileId, FALSE, heapID, FALSE);
    model->modelSet = NNS_G3dGetMdlSet(model->dataRaw);
    model->model = NNS_G3dGetMdlByIdx(model->modelSet, 0);
    model->texture = NNS_G3dGetTex(model->dataRaw);
    if (model->texture != NULL) {
        SysTask_CreateOnVWaitQueue(ov01_021FBD8C, model, 1024);
    }
}

void ov01_021FBD38(Field3dModel *model, void *data) {
    model->dataRaw = data;
    model->modelSet = NNS_G3dGetMdlSet(data);
    model->model = NNS_G3dGetMdlByIdx(model->modelSet, 0);
    model->texture = NNS_G3dGetTex(model->dataRaw);
    if (model->texture != NULL) {
        SysTask_CreateOnVWaitQueue(ov01_021FBD8C, model, 1024);
    }
}

void ov01_021FBD8C(SysTask *task, void *data) {
    Field3dModel *model = data;
    GF3dRender_AllocAndLoadTexResources(model->texture);
    GF3dRender_BindModelSet(model->dataRaw, model->texture);
    SysTask_Destroy(task);
}

void Field3dModel_Unload(Field3dModel *model) {
    NNSG3dTexKey texKey;
    NNSG3dTexKey tex4x4Key;

    if (model->texture != NULL) {
        NNS_G3dTexReleaseTexKey(model->texture, &texKey, &tex4x4Key);
        NNS_GfdDefaultFuncFreeTexVram(texKey);
        NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
        NNS_GfdDefaultFuncFreePlttVram(NNS_G3dPlttReleasePlttKey(model->texture));
    }
    if (model->dataRaw != NULL) {
        Heap_Free(model->dataRaw);
    }
    memset(model, 0, sizeof(Field3dModel));
}

void ov01_021FBDFC(Field3dModel *model) {
    NNSG3dTexKey texKey;
    NNSG3dTexKey tex4x4Key;

    if (model->texture != NULL) {
        NNS_G3dTexReleaseTexKey(model->texture, &texKey, &tex4x4Key);
        NNS_GfdDefaultFuncFreeTexVram(texKey);
        NNS_GfdDefaultFuncFreeTexVram(tex4x4Key);
        NNS_GfdDefaultFuncFreePlttVram(NNS_G3dPlttReleasePlttKey(model->texture));
    }
    memset(model, 0, sizeof(Field3dModel));
}

void Field3dModelAnimation_LoadFromFilesystem(Field3DModelAnimation *anim, Field3dModel *model, NarcId narcId, s32 fileId, enum HeapID heapID, NNSFndAllocator *alloc) {
    ov01_021FC030(anim, model, GfGfxLoader_LoadFromNarc(narcId, fileId, FALSE, heapID, FALSE), alloc);
    anim->shouldRetainData = FALSE;
}

void ov01_021FBE70(Field3DModelAnimation *anim, Field3dModel *model, void *animRaw, NNSFndAllocator *alloc) {
    ov01_021FC030(anim, model, animRaw, alloc);
    anim->shouldRetainData = TRUE;
}

void Field3dModelAnimation_Unload(Field3DModelAnimation *anim, NNSFndAllocator *alloc) {
    if (anim->fileDataRaw != NULL) {
        NNS_G3dFreeAnmObj(alloc, anim->animObj);
        if (!anim->shouldRetainData) {
            Heap_Free(anim->fileDataRaw);
        }
    }
    memset(anim, 0, sizeof(Field3DModelAnimation));
}
