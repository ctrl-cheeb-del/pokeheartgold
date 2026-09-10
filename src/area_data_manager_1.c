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

void ov01_021FB878(void *data, AreaDataTexBlockHeader *tex) {
    Heap_Realloc(data, (u32)tex + tex->endOffset - (u32)data);
}

AreaDataManager *AreaDataManager_Alloc(u8 areaDataBank) {
    AreaDataManager *areaDataManager = Heap_Alloc(HEAP_ID_FIELD1, sizeof(AreaDataManager));
    areaDataManager->loadCtx = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(AreaDataLoadContext));
    areaDataManager->loadCtx->areaDataBank = areaDataBank;
    areaDataManager->loadCtx->unk4 = 0;
    ReadWholeNarcMemberByIdPair(&areaDataManager->header, (NarcId)0x2a, areaDataBank);
    if (areaDataManager->header.buildModelKind != 0) {
        areaDataManager->mapPropNarc = NARC_New((NarcId)0x6b, HEAP_ID_FIELD1);
        areaDataManager->loadCtx->narc = NARC_New((NarcId)0x28, HEAP_ID_FIELD1);
    } else {
        areaDataManager->mapPropNarc = NARC_New((NarcId)0x6c, HEAP_ID_FIELD1);
        areaDataManager->loadCtx->narc = NARC_New((NarcId)0x94, HEAP_ID_FIELD1);
    }
    return areaDataManager;
}

NARC *ov01_021FB904(AreaDataManager *areaDataManager) {
    return areaDataManager->mapPropNarc;
}

NNSG3dResFileHeader **ov01_021FB90C(u32 fileId, AreaDataManager *areaDataManager) {
    GF_ASSERT(areaDataManager != NULL);
    if (areaDataManager->mapPropModels[fileId] == NULL) {
        GF_ASSERT(areaDataManager->mapPropModels[0] != NULL);
        return &areaDataManager->mapPropModels[0];
    }
    return &areaDataManager->mapPropModels[fileId];
}

NNSG3dResFileHeader **AreaDataManager_GetMapPropModelFile(AreaDataManager *areaDataManager) {
    GF_ASSERT(areaDataManager != NULL);
    return &areaDataManager->mapPropModels[0];
}

void AreaDataManager_Free(AreaDataManager **areaDataManager) {
    int i;

    NARC_Delete((*areaDataManager)->mapPropNarc);
    if ((*areaDataManager)->unk8AC != NULL) {
        ov01_021EA7E0((*areaDataManager)->unk8AC);
    }
    for (i = 0; i < AREA_DATA_MAX_MAP_PROPS; i++) {
        if ((*areaDataManager)->mapPropModels[i] != NULL) {
            Heap_Free((*areaDataManager)->mapPropModels[i]);
        }
    }
    Heap_Free((*areaDataManager)->mapPropIdList);
    Heap_Free((*areaDataManager)->mapPropTexFile);
    (*areaDataManager)->mapPropTexFile = NULL;
    Heap_Free((*areaDataManager)->mapTexFile);
    (*areaDataManager)->mapTexFile = NULL;
    Heap_Free(*areaDataManager);
    *areaDataManager = NULL;
}

NNSG3dResTex *AreaDataManager_GetMapTexture(AreaDataManager *areaDataManager) {
    GF_ASSERT(areaDataManager != NULL);
    return areaDataManager->mapPropTex;
}

NNSG3dResTex *ov01_021FB9E0(AreaDataManager *areaDataManager) {
    GF_ASSERT(areaDataManager != NULL);
    return areaDataManager->mapTex;
}

AreaDataManager_Sub8AC *ov01_021FB9F4(AreaDataManager *areaDataManager) {
    return areaDataManager->unk8AC;
}

BOOL ov01_021FBA00(AreaDataManager *areaDataManager) {
    if (areaDataManager->header.lightKind != 0) {
        return TRUE;
    }
    return FALSE;
}

u32 AreaDataManager_GetAreaLightArchiveID(AreaDataManager *areaDataManager) {
    switch (areaDataManager->header.lightKind) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    }
    return 0;
}
