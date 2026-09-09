#ifndef POKEHEARTGOLD_BILLBOARD_INTERNAL_H
#define POKEHEARTGOLD_BILLBOARD_INTERNAL_H

#include "global.h"

#include "gf_3d_render.h"
#include "heap.h"

typedef struct Billboard Billboard;
typedef struct BillboardObject BillboardObject;
typedef void (*BillboardCallback)(BillboardObject *, void *);
typedef struct BillboardResourceData {
    u32 words[4];
} BillboardResourceData;

struct BillboardObject {
    VecFx32 position;
    VecFx32 scale;
    MtxFx33 *rotation;
    void *callbackArg;
    BillboardCallback callback;
    u8 visible;
    u8 padding_25[3];
    Billboard *owner;
    u32 unk_2C;
    NNSG3dRenderObj renderObj;
    NNSG3dResMdlSet *modelSet;
    NNSG3dResMdl *model;
    NNSG3dResTex *texture;
    void *resourceHeader;
    NNSG3dTexKey texKey;
    NNSG3dTexKey tex4x4Key;
    NNSG3dPlttKey paletteKey;
    BillboardResourceData resourceData;
    void *unk_B0;
    u8 type;
    u8 padding_B5;
    u16 unk_B6;
    u32 unk_B8;
    BillboardObject *next;
    BillboardObject *prev;
};

struct Billboard {
    u8 initialized;
    u8 draw;
    u8 padding_02;
    u8 state;
    BillboardObject *objects;
    int objectCount;
    BillboardObject root;
    u32 *unk_D0;
    u32 unk_D4;
    NNSFndAllocator *allocator;
    void *unk_DC;
};

typedef struct BillboardListManager {
    Billboard *list;
    int count;
} BillboardListManager;

typedef struct BillboardCreateParams {
    int count;
    enum HeapID heapId;
} BillboardCreateParams;

typedef struct BillboardResource {
    u8 padding_00[8];
    u32 resourceId;
    BillboardResourceData data;
    NNSG3dTexKey texKey;
    NNSG3dTexKey tex4x4Key;
    NNSG3dPlttKey paletteKey;
} BillboardResource;

typedef struct BillboardObjectCreateParams {
    Billboard *billboard;
    u32 resourceIndex;
    VecFx32 position;
    VecFx32 scale;
} BillboardObjectCreateParams;

#endif
