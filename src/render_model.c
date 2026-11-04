#include "render_model.h"

#include <string.h>

#include "global.h"

#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "sys_task_api.h"

static void RenderModel_Clear(RenderModel *model);
static void RenderModel_InitFromFile(RenderModel *model, NNSG3dResFileHeader *file, u32 index);
static void RenderModel_BindTextures(RenderModel *model);
static void RenderModel_BindTexturesTask(SysTask *task, void *data);
static void RenderModel_FreeFile(RenderModel *model);
static void RenderModel_ReleaseTextures(RenderModel *model);

static void RenderModel_Clear(RenderModel *model) {
    memset(model, 0, sizeof(*model));
}

static void RenderModel_InitFromFile(RenderModel *model, NNSG3dResFileHeader *file, u32 index) {
    RenderModel_Clear(model);
    model->file = file;
    model->loaded = FALSE;
    model->set = NNS_G3dGetMdlSet(file);
    model->model = NNS_G3dGetMdlByIdx(model->set, index);
    model->texture = NNS_G3dGetTex(file);
}

void RenderModel_LoadFromNarc(RenderModel *model, int index, NARC *narc, int fileId, enum HeapID heapID, BOOL atEnd) {
    void *file = GfGfxLoader_LoadFromOpenNarc(narc, fileId, FALSE, heapID, atEnd);
    RenderModel_InitFromFile(model, file, index);
}

static void RenderModel_BindTextures(RenderModel *model) {
    GF3dRender_AllocAndLoadTexResources(model->texture);
    NNS_G3dBindMdlSet(model->set, model->texture);
    model->loaded = TRUE;
}

static void RenderModel_BindTexturesTask(SysTask *task, void *data) {
    RenderModel_BindTextures(data);
    SysTask_Destroy(task);
}

void RenderModel_BindTexturesOnVBlank(RenderModel *model) {
    SysTask *task = SysTask_CreateOnVBlankQueue(RenderModel_BindTexturesTask, model, 0xFFFF);
    GF_ASSERT(task != NULL);
}

static void RenderModel_FreeFile(RenderModel *model) {
    if (model->file) {
        Heap_Free(model->file);
    }
}

static void RenderModel_ReleaseTextures(RenderModel *model) {
    if (model->texture) {
        NNSG3dTexKey key, key4x4;
        NNS_G3dTexReleaseTexKey(model->texture, &key, &key4x4);
        NNS_GfdFreeTexVram(key);
        NNS_GfdFreeTexVram(key4x4);
        NNS_GfdFreePlttVram(NNS_G3dPlttReleasePlttKey(model->texture));
        model->texture = NULL;
    }
}

void RenderModel_Free(RenderModel *model) {
    RenderModel_ReleaseTextures(model);
    RenderModel_FreeFile(model);
    RenderModel_Clear(model);
}
