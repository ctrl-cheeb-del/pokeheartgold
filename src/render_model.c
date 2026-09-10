#include "global.h"

#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "sys_task_api.h"
#include "unk_02069660.h"
typedef struct RenderModel {
    u32 loaded;
    NNSG3dResFileHeader *file;
    NNSG3dResMdlSet *set;
    NNSG3dResMdl *model;
    NNSG3dResTex *texture;
} RenderModel;
void sub_02069660(RenderModel *model);
void sub_02069670(RenderModel *model, NNSG3dResFileHeader *file, u32 index);
void sub_020696C4(RenderModel *model, int index, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd);
void sub_020696E8(RenderModel *model);
void sub_02069700(SysTask *task, void *data);
void sub_02069714(RenderModel *model);
void sub_02069734(RenderModel *model);
void sub_02069744(RenderModel *model);
void sub_02069784(UnkOv01_021FFECC_sub *data);
void sub_02069660(RenderModel *model) {
    u32 count = sizeof(*model);
    u8 *bytes = (u8 *)model;
    do {
        *bytes++ = 0;
    } while (--count);
}
void sub_02069670(RenderModel *model, NNSG3dResFileHeader *file, u32 index) {
    sub_02069660(model);
    model->file = file;
    model->loaded = FALSE;
    model->set = NNS_G3dGetMdlSet(file);
    model->model = NNS_G3dGetMdlByIdx(model->set, index);
    model->texture = NNS_G3dGetTex(file);
}
void sub_020696C4(RenderModel *model, int index, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd) {
    void *file = GfGfxLoader_LoadFromOpenNarc(narc, fileId, FALSE, heapID, atEnd);
    sub_02069670(model, file, index);
}
void sub_020696E8(RenderModel *model) {
    GF3dRender_AllocAndLoadTexResources(model->texture);
    NNS_G3dBindMdlSet(model->set, model->texture);
    model->loaded = TRUE;
}
void sub_02069700(SysTask *task, void *data) {
    sub_020696E8(data);
    SysTask_Destroy(task);
}
void sub_02069714(RenderModel *model) {
    SysTask *task = SysTask_CreateOnVBlankQueue(sub_02069700, model, 0xFFFF);
    GF_ASSERT(task != NULL);
}
void sub_02069734(RenderModel *model) {
    if (model->file) {
        Heap_Free(model->file);
    }
}
void sub_02069744(RenderModel *model) {
    if (model->texture) {
        NNSG3dTexKey key, key4x4;
        NNS_G3dTexReleaseTexKey(model->texture, &key, &key4x4);
        NNS_GfdFreeTexVram(key);
        NNS_GfdFreeTexVram(key4x4);
        NNS_GfdFreePlttVram(NNS_G3dPlttReleasePlttKey(model->texture));
        model->texture = NULL;
    }
}
void sub_02069784(UnkOv01_021FFECC_sub *data) {
    RenderModel *model = (RenderModel *)data;
    sub_02069744(model);
    sub_02069734(model);
    sub_02069660(model);
}
