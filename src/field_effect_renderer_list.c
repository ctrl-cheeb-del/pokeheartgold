#include "field_effect_renderer_list_internal.h"

FieldEffectRendererList *ov01_021FD1B8(void *a0);
void ov01_021FD1CC(FieldEffectRendererList *list);
void ov01_021FD1E8(FieldEffectRenderer *renderer, u32 id, int modelId, void *a3);
void ov01_021FD20C(FieldEffectRenderer *renderer);
void ov01_021FD21C(FieldEffectRendererList *list);
FieldEffectRenderer *ov01_021FD244(FieldEffectRendererList *list, u32 id);
void ov01_021FD258(FieldSystem *fieldSystem, u32 count);
void ov01_021FD290(FieldSystem *fieldSystem, u32 id, int modelId);
NNSG3dRenderObj *ov01_021FD2CC(FieldSystem *fieldSystem, u32 id);
void ov01_021FD2EC(LocalMapObject *mapObject, VecFx32 *a1);
BOOL ov01_021FD328(void *a0, FieldEffectRendererWork *work);
void ov01_021FD378(void *a0, FieldEffectRendererWork *work);
void ov01_021FD37C(void *a0, FieldEffectRendererWork *work);
void ov01_021FD3E0(void *a0, FieldEffectRendererWork *work);

static const UnkOv01_02209280 ov01_02208E1C = {
    0x28,
    (UnkOv01_02209280_Cb1)ov01_021FD328,
    (UnkOv01_02209280_Cb1)ov01_021FD378,
    (UnkOv01_02209280_Cb2)ov01_021FD37C,
    (UnkOv01_02209280_Cb2)ov01_021FD3E0,
};

static const FieldEffectRendererInit ov01_02208E30[12] = {
    { 0xB7,  0x54 },
    { 0x100, 0x6B },
    { 0x101, 0x6C },
    { 0xFD,  0x6D },
    { 0xFB,  0x6E },
    { 0xFC,  0x6F },
    { 0xFE,  0x70 },
    { 0xFF,  0x71 },
    { 0x120, 0x72 },
    { 0x123, 0x74 },
    { 0x124, 0x73 },
    { 0x121, 0x75 },
};

FieldEffectRendererList *ov01_021FD1B8(void *a0) {
    FieldEffectRendererList *list = (FieldEffectRendererList *)ov01_021F1430(a0, sizeof(FieldEffectRendererList), 0, 0);
    list->unk0 = a0;
    return list;
}

void ov01_021FD1CC(FieldEffectRendererList *list) {
    ov01_021FD21C(list);
    if (list->renderers != NULL) {
        ov01_021F1448(list->renderers);
    }
    ov01_021F1448(list);
}

void ov01_021FD1E8(FieldEffectRenderer *renderer, u32 id, int modelId, void *a3) {
    renderer->unk0 = id;
    ov01_021F19F4(a3, &renderer->unk4, 0, modelId, 0);
    sub_02069978(&renderer->unk18, &renderer->unk4);
}

void ov01_021FD20C(FieldEffectRenderer *renderer) {
    renderer->unk0 = FIELD_EFFECT_RENDERER_SLOT_EMPTY;
    sub_02069784(&renderer->unk4);
}

void ov01_021FD21C(FieldEffectRendererList *list) {
    u32 count = list->count;
    u32 i = 0;
    FieldEffectRenderer *renderer = list->renderers;
    for (; i < count; i++) {
        if (renderer->unk0 != FIELD_EFFECT_RENDERER_SLOT_EMPTY) {
            ov01_021FD20C(renderer);
        }
        renderer++;
    }
}

FieldEffectRenderer *ov01_021FD244(FieldEffectRendererList *list, u32 id) {
    u32 count = list->count;
    FieldEffectRenderer *renderer = list->renderers;
    do {
        if (renderer->unk0 == id) {
            return renderer;
        }
        renderer++;
    } while (--count != 0);
    return NULL;
}

void ov01_021FD258(FieldSystem *fieldSystem, u32 count) {
    FieldEffectRendererList *list = (FieldEffectRendererList *)ov01_021F1450(fieldSystem, 0x14);
    if (count == 0) {
        GF_AssertFail();
    }
    list->count = count;
    FieldEffectRenderer *renderer = (FieldEffectRenderer *)ov01_021F1430(fieldSystem, count * sizeof(FieldEffectRenderer), 0, 0);
    list->renderers = renderer;
    do {
        renderer->unk0 = FIELD_EFFECT_RENDERER_SLOT_EMPTY;
        renderer++;
    } while (--count != 0);
}

void ov01_021FD290(FieldSystem *fieldSystem, u32 id, int modelId) {
    FieldEffectRendererList *list = (FieldEffectRendererList *)ov01_021F1450(fieldSystem, 0x14);
    if (ov01_021FD244(list, id) == NULL) {
        FieldEffectRenderer *renderer = ov01_021FD244(list, FIELD_EFFECT_RENDERER_SLOT_EMPTY);
        if (renderer == NULL) {
            GF_AssertFail();
            return;
        }
        ov01_021FD1E8(renderer, id, modelId, fieldSystem);
    }
}

NNSG3dRenderObj *ov01_021FD2CC(FieldSystem *fieldSystem, u32 id) {
    FieldEffectRendererList *list = (FieldEffectRendererList *)ov01_021F1450(fieldSystem, 0x14);
    FieldEffectRenderer *renderer = ov01_021FD244(list, id);
    if (renderer == NULL) {
        GF_AssertFail();
    }
    return &renderer->unk18;
}

void ov01_021FD2EC(LocalMapObject *mapObject, VecFx32 *a1) {
    FieldEffectRendererArgs args;

    FieldSystem *fieldSystem = ov01_021F146C(mapObject);
    args.unk0 = MapObject_GetSpriteID(mapObject);
    args.unk4 = fieldSystem;
    args.unk8 = mapObject;
    u32 priority = MapObject_GetPriorityPlusValue(mapObject, 2);
    ov01_021F1620(fieldSystem, &ov01_02208E1C, a1, 0, (UnkOv01_021FFF5C *)&args, priority);
}

BOOL ov01_021FD328(void *a0, FieldEffectRendererWork *work) {
    FieldEffectRendererArgs *args = (FieldEffectRendererArgs *)sub_02068D98(a0);
    work->unk1C = *args;
    work->unk4 = MapObject_GetID(work->unk1C.unk8);
    work->unk18 = ov01_021FD2CC(work->unk1C.unk4, work->unk1C.unk0);
    work->unk8 = MapObject_CheckFlag25(work->unk1C.unk8) == TRUE ? sub_0205F544(work->unk1C.unk8) : MapObject_GetMapID(work->unk1C.unk8);
    sub_02068DB8(a0, &work->unkC);
    return TRUE;
}

void ov01_021FD378(void *a0, FieldEffectRendererWork *work) {
}

void ov01_021FD37C(void *a0, FieldEffectRendererWork *work) {
    VecFx32 position;
    VecFx32 facing;

    LocalMapObject *mapObject = work->unk1C.unk8;
    if (!sub_0205F0A8(mapObject, work->unk4, work->unk8)) {
        ov01_021F1640((int)a0);
        return;
    }
    MapObject_CopyPositionVector(mapObject, &position);
    MapObject_CopyFacingVector(mapObject, &facing);
    position.x += facing.x + work->unkC.x;
    position.y += facing.y + work->unkC.y;
    position.z += facing.z + work->unkC.z;
    sub_02068DA8(a0, &position);
}

void ov01_021FD3E0(void *a0, FieldEffectRendererWork *work) {
    VecFx32 position;

    sub_02068DB8(a0, &position);
    sub_020699BC((int)work->unk18, &position);
}

void FieldEffect_InitRenderObject(FieldEffectManager *fieldEffectManager) {
    const FieldEffectRendererInit *init = ov01_02208E30;
    u32 i = 12;
    ov01_021FD258((FieldSystem *)fieldEffectManager, i);
    do {
        ov01_021FD290((FieldSystem *)fieldEffectManager, init->unk0, init->unk4);
        init++;
    } while (--i != 0);
}
