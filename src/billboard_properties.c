#include "global.h"

#include "billboard_internal.h"
#include "unk_02023694.h"

void sub_02023E04(BillboardResource *, void *, u32, u32, BillboardResourceData *, u32, u32, u32);
void sub_02023E2C(BillboardResource *, void *, u32, u32, BillboardResourceData *);
void sub_02023E50(BillboardObject *, VecFx32 *);
VecFx32 *sub_02023E68(BillboardObject *);
void sub_02023E78(BillboardObject *, VecFx32 *);
VecFx32 *sub_02023E94(BillboardObject *);
u32 sub_02023EB8(BillboardObject *);
void sub_02023EC8(BillboardObject *, u32);
void sub_02023EE0(BillboardObject *, u32);
u32 sub_02023EF4(BillboardObject *);
void sub_02023F04(BillboardObject *, fx32);
void sub_02023F1C(BillboardObject *, fx32);
fx32 sub_02023F30(BillboardObject *);
void sub_02023F40(BillboardObject *, fx32);
fx32 sub_02023F70(BillboardObject *);
NNSG3dResMdl *sub_02023F90(void *);
NNSG3dTexKey sub_02023FA0(BillboardObject *);
NNSG3dPlttKey sub_02023FB0(BillboardObject *);
void sub_02023FC0(BillboardObject *);
NNSG3dResMdl *sub_02023FDC(BillboardObject *);
void sub_02023FE4(BillboardObject *, BillboardCallback, void *);
void sub_02023FEC(BillboardObject *);
void sub_02024380(BillboardObject *, u32);
void sub_020243A4(BillboardObject *, fx32);
fx32 sub_02024394(BillboardObject *, u32);
void sub_02020764(void *, fx32);
u32 sub_02026DE0(BillboardResourceData *, u32);
void sub_0202403C(NNSG3dResMdl *, void *, u8);
void sub_02024140(NNSG3dResMdl *, void *, u8);
void sub_020240C4(void *, void *, u32);
void sub_020241CC(void *, void *, u32);
void sub_020236BC(BillboardObject *);
void sub_020239D0(BillboardObject *, BillboardResource *);
void sub_02023A20(BillboardObject *, BillboardResource *);
void sub_02023B38(NNSG3dResTex *, NNSG3dTexKey *, NNSG3dTexKey *, NNSG3dPlttKey *);
void sub_02023B4C(NNSG3dResTex *, NNSG3dResMdlSet *, NNSG3dTexKey *, NNSG3dTexKey *, NNSG3dPlttKey *);
void sub_02024248(Billboard *);
BillboardObject *sub_02024280(Billboard *);
BOOL sub_020242AC(Billboard *, BillboardObject *);
void sub_020242E4(BillboardObject *, BillboardObject *);
void sub_02024308(BillboardObject *);
NNSG3dResMdlSet *sub_02024328(BillboardResource *, NNSG3dResMdl **, NNSG3dResTex **);
void *sub_02024374(BillboardResource *);
void *sub_0202443C(BillboardResource *, u32);
void *sub_02024454(void *, u32);
BOOL sub_020243C4(void *, fx32 *, fx32);
void NNS_G3dReleaseMdlSet(NNSG3dResMdlSet *);
void sub_020243FC(BillboardObject *);
void sub_0202441C(BillboardObject *);

static inline u8 *Billboard_GetIndexedData(u8 *base, u32 index) {
    u32 *entry;
    if (base != NULL) {
        entry = NNS_G3dGetResDataByIdx((NNSG3dResDict *)(base + 4), index);
        if (entry != NULL) {
            return base + *entry;
        }
    }
    return NULL;
}

void sub_02023E04(BillboardResource *resource, void *file0, u32 resourceId, u32 file1, BillboardResourceData *data, u32 texKey, u32 tex4x4Key, u32 paletteKey) {
    *(void **)&resource->padding_00[0] = file0;
    *(u32 *)&resource->padding_00[4] = resourceId;
    resource->resourceId = file1;
    resource->data = *data;
    resource->texKey = texKey;
    resource->tex4x4Key = tex4x4Key;
    resource->paletteKey = paletteKey;
}

void sub_02023E2C(BillboardResource *resource, void *file0, u32 resourceId, u32 file1, BillboardResourceData *data) {
    *(void **)&resource->padding_00[0] = file0;
    *(u32 *)&resource->padding_00[4] = resourceId;
    resource->resourceId = file1;
    resource->data = *data;
    resource->texKey = 0;
    resource->tex4x4Key = 0;
    resource->paletteKey = 0;
}

void sub_02023E50(BillboardObject *object, VecFx32 *position) {
    GF_ASSERT(object != NULL);
    object->position = *position;
}

VecFx32 *sub_02023E68(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return &object->position;
}

void sub_02023E78(BillboardObject *object, VecFx32 *scale) {
    GF_ASSERT(object != NULL);
    object->scale = *scale;
}

VecFx32 *sub_02023E94(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return &object->scale;
}

void sub_02023EA4(Sprite *sprite, int draw) {
    BillboardObject *object = (BillboardObject *)sprite;
    GF_ASSERT(object != NULL);
    object->visible = draw;
}

u32 sub_02023EB8(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return object->visible;
}

void sub_02023EC8(BillboardObject *object, u32 resourceIndex) {
    GF_ASSERT(object != NULL);
    sub_02024380(object, resourceIndex);
}

void sub_02023EE0(BillboardObject *object, u32 frame) {
    GF_ASSERT(object != NULL);
    object->unk_B6 = frame;
}

u32 sub_02023EF4(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return object->unk_B6;
}

void sub_02023F04(BillboardObject *object, fx32 delta) {
    GF_ASSERT(object != NULL);
    sub_020243A4(object, delta);
}

void sub_02023F1C(BillboardObject *object, fx32 frame) {
    GF_ASSERT(object != NULL);
    object->unk_B8 = frame;
}

fx32 sub_02023F30(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return object->unk_B8;
}

void sub_02023F40(BillboardObject *object, fx32 delta) {
    GF_ASSERT(object != NULL);
    object->unk_B8 = sub_02024394(object, object->unk_B6);
    object->unk_B8 += delta;
}

fx32 sub_02023F70(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return object->unk_B8 - sub_02024394(object, object->unk_B6);
}

NNSG3dResMdl *sub_02023F90(void *arg) {
    BillboardObject *object = arg;
    GF_ASSERT(object != NULL);
    return object->model;
}

NNSG3dTexKey sub_02023FA0(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return object->texKey;
}

NNSG3dPlttKey sub_02023FB0(BillboardObject *object) {
    GF_ASSERT(object != NULL);
    return object->paletteKey;
}

void sub_02023FC0(BillboardObject *object) {
    if (object->type == 2) {
        sub_02020764(object->unk_B0, object->unk_B8);
    }
}

NNSG3dResMdl *sub_02023FDC(BillboardObject *object) {
    return object->model;
}

void sub_02023FE4(BillboardObject *object, BillboardCallback callback, void *callbackArg) {
    object->callbackArg = callbackArg;
    object->callback = callback;
}

void sub_02023FEC(BillboardObject *object) {
    volatile u8 data[4];
    u32 value = sub_02026DE0(&object->resourceData, (object->unk_B8 << 4) >> 16);
    data[0] = value;
    data[1] = value >> 8;
    data[2] = data[0];
    data[3] = data[1];
    sub_0202403C(object->model, object->resourceHeader, data[2]);
    sub_02024140(object->model, object->resourceHeader, data[3]);
}

void sub_0202403C(NNSG3dResMdl *model, void *resourceHeader, u8 index) {
    register u8 *materialBlock;
    NNSG3dResDict *materialDict;
    u32 *entry;
    u16 value;
    int i;
    void *materialData;

    if (model != NULL && model->ofsMat != 0) {
        materialBlock = (u8 *)model + model->ofsMat;
    } else {
        materialBlock = NULL;
    }
    materialDict = (NNSG3dResDict *)(materialBlock + *(u16 *)materialBlock);
    if (resourceHeader != NULL) {
        entry = NNS_G3dGetResDataByIdx((NNSG3dResDict *)((u8 *)resourceHeader + 0x3C), index);
    } else {
        entry = NULL;
    }
    value = *entry;
    for (i = 0; i < materialDict->numEntry; i++) {
        materialData = NNS_G3dGetResDataByIdx(materialDict, i);
        if (*((u8 *)materialData + 3) & 1) {
            sub_020240C4(materialBlock, materialData, value);
        }
    }
}

void sub_020240C4(void *materialBlock, void *materialData, u32 value) {
    u8 *material;
    u8 *base = materialBlock;
    int i;
    u8 *indices = base + *(u16 *)materialData;
    for (i = 0; i < *((u8 *)materialData + 2); i++) {
        material = Billboard_GetIndexedData(base, indices[i]);
        GF_ASSERT((u16) * (u32 *)(material + 0x14) + value <= 0xFFFF);
        *(u32 *)(material + 0x14) += value;
    }
}

void sub_02024140(NNSG3dResMdl *model, void *resourceHeader, u8 index) {
    u32 value;
    u8 *materialBlock;
    NNSG3dResDict *shapeDict;
    u8 *subDict;
    u16 *entry;
    u32 i;
    void *shapeData;

    if (model != NULL && model->ofsMat != 0) {
        materialBlock = (u8 *)model + model->ofsMat;
    } else {
        materialBlock = NULL;
    }
    shapeDict = (NNSG3dResDict *)(materialBlock + *((u16 *)materialBlock + 1));
    if (resourceHeader != NULL && *(u16 *)((u8 *)resourceHeader + 0x34) != 0) {
        subDict = (u8 *)resourceHeader + *(u16 *)((u8 *)resourceHeader + 0x34);
        entry = NNS_G3dGetResDataByIdx((NNSG3dResDict *)subDict, index);
    } else {
        entry = NULL;
    }
    value = entry[0];
    if (!(entry[1] & 1)) {
        value >>= 1;
    }
    for (i = 0; i < shapeDict->numEntry; i++) {
        shapeData = NNS_G3dGetResDataByIdx(shapeDict, i);
        if (*((u8 *)shapeData + 3) & 1) {
            sub_020241CC(materialBlock, shapeData, value);
        }
    }
}

void sub_020241CC(void *materialBlock, void *shapeData, u32 value) {
    u8 *indices = (u8 *)materialBlock + *(u16 *)shapeData;
    u32 i;
    u8 *shape;
    for (i = 0; i < *((u8 *)shapeData + 2); i++) {
        shape = Billboard_GetIndexedData(materialBlock, indices[i]);
        GF_ASSERT((*(u16 *)(shape + 0x1C) & 0x1FFF) + value <= 0x1FFF);
        *(u16 *)(shape + 0x1C) += value;
    }
}

void sub_02024248(Billboard *billboard) {
    int i;
    for (i = 0; i < billboard->objectCount; i++) {
        sub_020236BC(&billboard->objects[i]);
        billboard->unk_D0[i] = (u32)&billboard->objects[i];
    }
    billboard->unk_D4 = 0;
}

BillboardObject *sub_02024280(Billboard *billboard) {
    BillboardObject *object;
    if ((int)billboard->unk_D4 >= billboard->objectCount) {
        return NULL;
    }
    object = (BillboardObject *)billboard->unk_D0[billboard->unk_D4];
    billboard->unk_D4++;
    return object;
}

BOOL sub_020242AC(Billboard *billboard, BillboardObject *object) {
    if ((int)billboard->unk_D4 <= 0) {
        return FALSE;
    }
    sub_020236BC(object);
    billboard->unk_D4--;
    billboard->unk_D0[billboard->unk_D4] = (u32)object;
    return TRUE;
}

void sub_020242E4(BillboardObject *root, BillboardObject *object) {
    object->prev = root->prev;
    root->prev->next = object;
    object->next = root;
    root->prev = object;
}

void sub_02024308(BillboardObject *object) {
    object->prev->next = object->next;
    object->next->prev = object->prev;
}

NNSG3dResMdlSet *sub_02024328(BillboardResource *resource, NNSG3dResMdl **model, NNSG3dResTex **texture) {
    void *file = sub_0202443C(resource, 0);
    NNSG3dResMdlSet *modelSet = NNS_G3dGetMdlSet(file);
    *model = NNS_G3dGetMdlByIdx(modelSet, 0);
    if (texture != NULL) {
        *texture = NNS_G3dGetTex(file);
    }
    return modelSet;
}

void *sub_02024374(BillboardResource *resource) {
    return sub_0202443C(resource, 1);
}

void sub_02024380(BillboardObject *object, u32 resourceIndex) {
    BillboardResource *resource = (BillboardResource *)resourceIndex;
    if (resource->texKey == 0) {
        sub_020239D0(object, resource);
    } else {
        sub_02023A20(object, resource);
    }
}

fx32 sub_02024394(BillboardObject *object, u32 index) {
    u32 *entry = sub_02024454((void *)object->unk_2C, index);
    return *entry << FX32_SHIFT;
}

void sub_020243A4(BillboardObject *object, fx32 delta) {
    void *entry = sub_02024454((void *)object->unk_2C, object->unk_B6);
    sub_020243C4(entry, &object->unk_B8, delta);
}

BOOL sub_020243C4(void *entry, fx32 *value, fx32 delta) {
    BOOL wrapped = FALSE;
    fx32 start = *(s32 *)entry << FX32_SHIFT;
    fx32 current = *value;
    fx32 end;
    if (start > current || (end = *((s32 *)entry + 1) << FX32_SHIFT) < current) {
        *value = start;
    } else if (end < current + delta) {
        if (*((s32 *)entry + 2) == 0) {
            *value = start;
        } else {
            wrapped = TRUE;
            *value = end;
        }
    } else {
        *value = current + delta;
    }
    return wrapped;
}

void sub_020243FC(BillboardObject *object) {
    sub_02023B4C(object->texture, object->modelSet, &object->texKey, &object->tex4x4Key, &object->paletteKey);
}

void sub_0202441C(BillboardObject *object) {
    NNSG3dTexKey tex4x4Key;
    NNSG3dTexKey texKey;
    NNSG3dPlttKey paletteKey;
    NNS_G3dReleaseMdlSet(object->modelSet);
    sub_02023B38(object->texture, &texKey, &tex4x4Key, &paletteKey);
}

void *sub_0202443C(BillboardResource *resource, u32 which) {
    switch (which) {
    case 0:
        return *(void **)&resource->padding_00[0];
    case 1:
        return *(void **)&resource->padding_00[4];
    default:
        return NULL;
    }
}

void *sub_02024454(void *base, u32 index) {
    return (u8 *)base + index * 12;
}
