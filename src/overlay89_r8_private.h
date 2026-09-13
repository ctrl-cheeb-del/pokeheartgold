#ifndef OVERLAY89_RESIDUAL_8_PRIVATE_H
#define OVERLAY89_RESIDUAL_8_PRIVATE_H

#include "global.h"

#include "gf_3d_render.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "screen_fade_update_internal.h"

typedef struct Ov89ModelResource {
    NNSG3dResFileHeader *file;
    NNSG3dResMdlSet *set;
    NNSG3dResMdl *model;
    NNSG3dResTex *texture;
} Ov89ModelResource;

typedef struct ModelInstance {
    NNSG3dRenderObj render;
    VecFx32 position;
    VecFx32 scale;
    BOOL visible;
    u16 rotation[3];
} ModelInstance;

typedef struct Ov89Object {
    u16 unk00;
    u16 id;
    u8 unk04[4];
    u8 kind;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
    Ov89ModelResource resource;
    ModelInstance instance;
    u8 unk94[0x1AC];
    u32 packed;
} Ov89Object;

typedef struct Ov89Work {
    u8 unk00[0xB4];
    Ov89Object *objects[128];
    u8 unk2B4[0x200];
    NNSG3dResTex *textures[32];
    u8 unk534[0x208];
    u8 active;
    u8 value;
    u8 unk73E[2];
    u8 brightnessActive;
    u8 level;
    s16 brightness;
} Ov89Work;

typedef struct Ov89Dispatch {
    BOOL (*update)(Ov89Work *, Ov89Object *);
    void (*tick)(Ov89Work *, Ov89Object *);
    BOOL (*interact)(Ov89Work *, Ov89Object *, Ov89Object *);
} Ov89Dispatch;

extern const Ov89Dispatch ov89_0225CDB0[];
void sub_020181EC(ModelInstance *);
Ov89Object *ov89_0225A7BC(void *, Ov89Work *, const Ov89Object *, int, void *, int);
BOOL ov89_0225A49C(void *, Ov89Work *, const Ov89Object *, int, void *, int);
void ov89_0225A5A4(Ov89Work *);
void ov89_0225A760(Ov89Work *, int);
BOOL ov89_0225A958(Ov89Work *, NNSG3dResTex *);
void ov89_0225A988(Ov89Work *, NNSG3dResTex *);
BOOL ov89_0225A9B4(NNSG3dResTex *);

#endif
