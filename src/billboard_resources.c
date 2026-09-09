#include "global.h"

#include "billboard_internal.h"
#include "gf_3d_render.h"
#include "heap.h"
#include "unk_02023694.h"

extern BillboardListManager _021D2208;

void sub_02023694(Billboard *billboard);
void sub_020236BC(BillboardObject *object);
void *sub_0202068C(int count, enum HeapID heapId);
void sub_020206C8(void *arg);
Billboard *sub_020237EC(BillboardCreateParams *params);
BOOL sub_02023874(Billboard *billboard);
BOOL sub_020238BC(Billboard *billboard);
BOOL sub_020238F8(Billboard *billboard);
Billboard *sub_0202391C(void);
void sub_02023950(Billboard *billboard);
void sub_02023FC0(BillboardObject *object);
void sub_02023FEC(BillboardObject *object);
void sub_02024248(Billboard *billboard);
void sub_020242E4(BillboardObject *root, BillboardObject *object);
void sub_020243FC(BillboardObject *object);
void sub_0202441C(BillboardObject *object);
void sub_020239D0(BillboardObject *object, BillboardResource *resource);
void sub_02023A20(BillboardObject *object, BillboardResource *resource);
void sub_02023AA0(NNSG3dResTex *texture, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey);
void sub_02023B38(NNSG3dResTex *texture, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey);
void sub_02023B4C(NNSG3dResTex *texture, NNSG3dResMdlSet *modelSet, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey);
void sub_02023B70(NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey);
BOOL sub_02023BA4(NNSG3dResTex *a, NNSG3dResTex *b);
void sub_02023C04(Billboard *billboard, BillboardObject *object);
void sub_02023C20(BillboardObject *object, BillboardResource *resource);
void sub_02023C9C(Billboard *billboard, BillboardObject *object, BillboardResource *resource);
void sub_02023CF0(BillboardObject *object, BillboardResource *resource);
void sub_02023D24(BillboardObject *object, BillboardResource *resource);
NNSG3dResMdlSet *sub_02024328(BillboardResource *resource, NNSG3dResMdl **model, NNSG3dResTex **texture);
void *sub_02024374(BillboardResource *resource);
void *sub_020206E0(void *ctx, BillboardResourceData *resourceData, void *resourceHeader, NNSG3dTexKey texKey, NNSG3dPlttKey paletteKey, u32 unkB8);
void sub_02020738(void *arg);
BillboardObject *sub_02023D44(BillboardObjectCreateParams *params);
BOOL sub_02023DA4(BillboardObject *object);
BillboardObject *sub_02024280(Billboard *billboard);
void sub_020242AC(Billboard *billboard, BillboardObject *object);
void sub_02024308(BillboardObject *object);
void sub_02024380(BillboardObject *object, u32 resourceIndex);

Billboard *sub_020237EC(BillboardCreateParams *params) {
    Billboard *billboard = sub_0202391C();
    if (billboard == NULL) {
        GF_ASSERT(FALSE);
        return NULL;
    }
    billboard->initialized = TRUE;
    billboard->draw = TRUE;
    billboard->objects = Heap_Alloc(params->heapId, params->count * sizeof(BillboardObject));
    billboard->objectCount = params->count;
    sub_020236BC(&billboard->root);
    billboard->root.next = &billboard->root;
    billboard->root.prev = &billboard->root;
    billboard->unk_D0 = Heap_Alloc(params->heapId, params->count * sizeof(u32));
    sub_02024248(billboard);
    billboard->allocator = Heap_Alloc(params->heapId, sizeof(NNSFndAllocator));
    HeapExp_FndInitAllocator(billboard->allocator, params->heapId, 4);
    billboard->unk_DC = sub_0202068C(params->count, params->heapId);
    return billboard;
}

BOOL sub_02023874(Billboard *billboard) {
    if (billboard == NULL) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    if (billboard->initialized != FALSE) {
        sub_020238BC(billboard);
        Heap_Free(billboard->objects);
        Heap_Free(billboard->unk_D0);
        Heap_Free(billboard->allocator);
        sub_020206C8(billboard->unk_DC);
        sub_02023694(billboard);
    }
    return TRUE;
}

BOOL sub_020238BC(Billboard *billboard) {
    BillboardObject *object;
    BillboardObject *next;
    if (billboard == NULL) {
        GF_ASSERT(billboard != NULL);
        return FALSE;
    }
    if (billboard->initialized != FALSE) {
        object = billboard->root.next;
        while (object != &billboard->root) {
            next = object->next;
            sub_02023DA4(object);
            object = next;
        }
    }
    return TRUE;
}

BOOL sub_020238F8(Billboard *billboard) {
    GF_ASSERT(billboard != NULL);
    if (billboard->state == 0) {
        return FALSE;
    }
    return TRUE;
}

void sub_02023910(void *arg0) {
    Billboard *billboard = arg0;
    if (billboard->state == 2) {
        billboard->state = 0;
    }
}

Billboard *sub_0202391C(void) {
    int i;
    for (i = 0; i < _021D2208.count; i++) {
        if (!_021D2208.list[i].initialized) {
            return &_021D2208.list[i];
        }
    }
    return NULL;
}

void sub_02023950(Billboard *billboard) {
    MtxFx33 identity;
    BillboardObject *object;
    GF_ASSERT(billboard != NULL);
    MTX_Identity33(&identity);
    object = billboard->root.next;
    while (object != &billboard->root) {
        if (object->visible == TRUE) {
            if (object->callback != NULL) {
                object->callback(object, object->callbackArg);
            }
            sub_020243FC(object);
            if (object->type == 3) {
                sub_02023FEC(object);
            } else if (object->type == 2) {
                sub_02023FC0(object);
            }
            GF3dRender_DrawModel(&object->renderObj, &object->position, object->rotation != NULL ? object->rotation : &identity, &object->scale);
            sub_0202441C(object);
        }
        object = object->next;
    }
}

void sub_020239D0(BillboardObject *object, BillboardResource *resource) {
    Billboard *billboard = object->owner;
    sub_02023C04(billboard, object);
    sub_02023C20(object, resource);
    sub_02023C9C(billboard, object, resource);
    if (object->type == 1) {
        sub_020242E4(&billboard->root, object);
    }
    object->type = 2;
    object->unk_2C = resource->resourceId;
    object->unk_B6 = 0;
    object->unk_B8 = 0;
}

void sub_02023A20(BillboardObject *object, BillboardResource *resource) {
    Billboard *billboard = object->owner;
    sub_02023C04(billboard, object);
    if (object->type == 2) {
        sub_02023B70(&object->texKey, &object->tex4x4Key, &object->paletteKey);
    }
    object->texKey = resource->texKey;
    object->tex4x4Key = resource->tex4x4Key;
    object->paletteKey = resource->paletteKey;
    sub_02023CF0(object, resource);
    sub_02023D24(object, resource);
    if (object->type == 1) {
        sub_020242E4(&billboard->root, object);
    }
    object->type = 3;
    object->unk_2C = resource->resourceId;
    object->unk_B6 = 0;
    object->unk_B8 = 0;
}

void sub_02023AA0(NNSG3dResTex *texture, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey) {
    u32 texSize = NNS_G3dTexGetRequiredSize(texture);
    u32 tex4x4Size = NNS_G3dTex4x4GetRequiredSize(texture);
    u32 paletteSize = NNS_G3dPlttGetRequiredSize(texture);
    if (texSize != 0) {
        *texKey = NNS_GfdDefaultFuncAllocTexVram(texSize, FALSE, 0);
        GF_ASSERT(*texKey != 0);
    } else {
        *texKey = 0;
    }
    if (tex4x4Size != 0) {
        *tex4x4Key = NNS_GfdDefaultFuncAllocTexVram(tex4x4Size, TRUE, 0);
        GF_ASSERT(*tex4x4Key != 0);
    } else {
        *tex4x4Key = 0;
    }
    if (paletteSize != 0) {
        *paletteKey = NNS_GfdDefaultFuncAllocPlttVram(paletteSize, *(u16 *)((u8 *)texture + 0x20) & 0x8000, 0);
        GF_ASSERT(*paletteKey != 0);
    } else {
        *paletteKey = 0;
    }
}

void sub_02023B38(NNSG3dResTex *texture, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey) {
    NNS_G3dTexReleaseTexKey(texture, texKey, tex4x4Key);
    *paletteKey = NNS_G3dPlttReleasePlttKey(texture);
}

void sub_02023B4C(NNSG3dResTex *texture, NNSG3dResMdlSet *modelSet, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey) {
    NNS_G3dTexSetTexKey(texture, *texKey, *tex4x4Key);
    NNS_G3dPlttSetPlttKey(texture, *paletteKey);
    NNS_G3dBindMdlSet(modelSet, texture);
}

void sub_02023B70(NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key, NNSG3dPlttKey *paletteKey) {
    if (*texKey != 0) {
        NNS_GfdDefaultFuncFreeTexVram(*texKey);
    }
    if (*tex4x4Key != 0) {
        NNS_GfdDefaultFuncFreeTexVram(*tex4x4Key);
    }
    if (*paletteKey != 0) {
        NNS_GfdDefaultFuncFreePlttVram(*paletteKey);
    }
}

BOOL sub_02023BA4(NNSG3dResTex *a, NNSG3dResTex *b) {
    u32 aTex, a4x4, aPltt;
    u32 bTex, b4x4, bPltt;
    if (a == NULL || b == NULL) {
        return FALSE;
    }
    aTex = NNS_G3dTexGetRequiredSize(a);
    a4x4 = NNS_G3dTex4x4GetRequiredSize(a);
    aPltt = NNS_G3dPlttGetRequiredSize(a);
    bTex = NNS_G3dTexGetRequiredSize(b);
    b4x4 = NNS_G3dTex4x4GetRequiredSize(b);
    bPltt = NNS_G3dPlttGetRequiredSize(b);
    if (aTex != bTex || a4x4 != b4x4 || aPltt != bPltt) {
        return FALSE;
    }
    return TRUE;
}

void sub_02023C04(Billboard *billboard, BillboardObject *object) {
    if (object->unk_B0 != NULL) {
        sub_02020738(object->unk_B0);
        object->unk_B0 = NULL;
    }
}

void sub_02023C20(BillboardObject *object, BillboardResource *resource) {
    NNSG3dResTex *oldTexture = object->texture;
    BOOL same;
    object->modelSet = sub_02024328(resource, &object->model, &object->texture);
    NNS_G3dRenderObjInit(&object->renderObj, object->model);
    if (object->type != 3) {
        same = sub_02023BA4(oldTexture, object->texture);
    } else {
        same = FALSE;
    }
    if (!same) {
        if (object->type == 2) {
            sub_02023B70(&object->texKey, &object->tex4x4Key, &object->paletteKey);
        }
        sub_02023AA0(object->texture, &object->texKey, &object->tex4x4Key, &object->paletteKey);
    }
}

void sub_02023C9C(Billboard *billboard, BillboardObject *object, BillboardResource *resource) {
    register BillboardResource *res = resource;
    register BillboardObject *obj = object;
    register Billboard *parent = billboard;
    obj->resourceHeader = sub_02024374(res);
    obj->resourceData = res->data;
    obj->unk_B0 = sub_020206E0(parent->unk_DC, &obj->resourceData, obj->resourceHeader, obj->texKey, obj->paletteKey, obj->unk_B8);
}

void sub_02023CF0(BillboardObject *object, BillboardResource *resource) {
    object->modelSet = sub_02024328(resource, &object->model, &object->texture);
    NNS_G3dRenderObjInit(&object->renderObj, object->model);
    object->resourceHeader = sub_02024374(resource);
}

void sub_02023D24(BillboardObject *object, BillboardResource *resource) {
    object->resourceData = resource->data;
    object->unk_B0 = NULL;
}

BillboardObject *sub_02023D44(BillboardObjectCreateParams *params) {
    Billboard *billboard = params->billboard;
    BillboardObject *object;
    if (billboard == NULL) {
        return NULL;
    }
    object = sub_02024280(billboard);
    if (object == NULL) {
        return NULL;
    }
    object->owner = billboard;
    object->position = params->position;
    object->scale = params->scale;
    object->unk_B6 = 0;
    object->visible = TRUE;
    object->type = 1;
    sub_02024380(object, params->resourceIndex);
    return object;
}

BOOL sub_02023DA4(BillboardObject *object) {
    Billboard *billboard;
    GF_ASSERT(object != NULL);
    GF_ASSERT(object->type != 1);
    billboard = object->owner;
    if (object->type == 0) {
        return FALSE;
    }
    sub_02024308(object);
    if (object->type == 2) {
        sub_02023B70(&object->texKey, &object->tex4x4Key, &object->paletteKey);
    }
    sub_02023C04(billboard, object);
    sub_020242AC(billboard, object);
    billboard->state = 1;
    return TRUE;
}
