#ifndef PRIVATE_MODEL_ATTRIBUTES_H
#define PRIVATE_MODEL_ATTRIBUTES_H
#include "global.h"

typedef struct {
    s16 lightVector[4][3];
    u16 lightColor[4];
    u16 diffuse;
    u16 ambient;
    u16 specular;
    u16 emission;
    u32 diffuseAmbientFlags;
    u32 specularEmissionFlags;
    u32 lightEnableFlags;
    u32 polygonMode;
    u32 cullMode;
    u32 polygonId;
    u32 alpha;
    u32 miscFlags;
} ModelAttributes;

void *Heap_Alloc(u32, u32);
void Heap_FreeExplicit(u32, void *);
void NNS_G3dMdlSetMdlDiffAll(void *, u32);
void NNS_G3dMdlSetMdlAmbAll(void *, u32);
void NNS_G3dMdlSetMdlSpecAll(void *, u32);
void NNS_G3dMdlSetMdlEmiAll(void *, u32);
void NNS_G3dMdlSetMdlLightEnableFlagAll(void *, u32);
void NNS_G3dMdlSetMdlPolygonModeAll(void *, u32);
void NNS_G3dMdlSetMdlCullModeAll(void *, u32);
void NNS_G3dMdlSetMdlPolygonIDAll(void *, u32);
void NNS_G3dMdlSetMdlAlphaAll(void *, u32);
void NNS_G3dMdlSetMdlDepthTestCondAll(void *, u32);
void NNS_G3dMdlSetMdl1DotAll(void *, u32);
void NNS_G3dMdlSetMdlFarClipAll(void *, u32);
void NNS_G3dMdlSetMdlXLDepthUpdateAll(void *, u32);

ModelAttributes *ModelAttributes_Init(void);
void ModelAttributes_Free(ModelAttributes **);
void ModelAttributes_ApplyGlobal(ModelAttributes *, s32);
void ov01_021EA9B0(ModelAttributes *, void *, u32);
void ov01_021EAAB8(ModelAttributes *, u32, s16, s16, s16);
void ov01_021EAAE0(ModelAttributes *, u32, u16);
void ov01_021EAAF4(ModelAttributes *, u16, u32, BOOL);
void ov01_021EAB08(ModelAttributes *, u16, BOOL);
void ov01_021EAB1C(ModelAttributes *, u16, u32, BOOL);
void ov01_021EAB30(ModelAttributes *, u16, BOOL);
void ModelAttributes_SetPolygonMode(ModelAttributes *, u32, BOOL);
void ModelAttributes_SetCullMode(ModelAttributes *, u32, BOOL);
void ModelAttributes_SetAlpha(ModelAttributes *, u32, BOOL);
void ModelAttributes_SetMiscAttrEnabled(ModelAttributes *, u32, BOOL, BOOL);
#endif
