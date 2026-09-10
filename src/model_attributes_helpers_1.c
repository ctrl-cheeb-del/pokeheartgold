#include "model_attributes_internal.h"

ModelAttributes *ModelAttributes_Init(void) {
    ModelAttributes *attributes = Heap_Alloc(4, sizeof(ModelAttributes));
    MIi_CpuClear32(0, (u32 *)attributes, sizeof(ModelAttributes));
    return attributes;
}

void ModelAttributes_Free(ModelAttributes **attributes) {
    Heap_FreeExplicit(4, *attributes);
    *attributes = NULL;
}

void ModelAttributes_ApplyGlobal(ModelAttributes *a, s32 mask) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (mask & (1 << i)) {
            NNS_G3dGlbLightVector((GXLightId)i, a->lightVector[i][0], a->lightVector[i][1], a->lightVector[i][2]);
        }
        if (mask & (1 << (i + 4))) {
            NNS_G3dGlbLightColor((GXLightId)i, a->lightColor[i]);
        }
    }
    if (mask & 0x300) {
        NNS_G3dGlbMaterialColorDiffAmb(a->diffuse, a->ambient, a->diffuseAmbientFlags);
    }
    if (mask & 0xc00) {
        NNS_G3dGlbMaterialColorSpecEmi(a->specular, a->emission, a->specularEmissionFlags);
    }
    if (mask >= 0x1000) {
        NNS_G3dGlbPolygonAttr(a->lightEnableFlags, (GXPolygonMode)a->polygonMode, (GXCull)a->cullMode, a->polygonId, a->alpha, a->miscFlags);
    }
}

void ov01_021EA9B0(ModelAttributes *a, void *model, u32 mask) {
    if (mask & 0x100) {
        NNS_G3dMdlSetMdlDiffAll(model, a->diffuse);
    }
    if (mask & 0x200) {
        NNS_G3dMdlSetMdlAmbAll(model, a->ambient);
    }
    if (mask & 0x400) {
        NNS_G3dMdlSetMdlSpecAll(model, a->specular);
    }
    if (mask & 0x800) {
        NNS_G3dMdlSetMdlEmiAll(model, a->emission);
    }
    if (mask & 0x1000) {
        NNS_G3dMdlSetMdlLightEnableFlagAll(model, a->lightEnableFlags);
    }
    if (mask & 0x2000) {
        NNS_G3dMdlSetMdlPolygonModeAll(model, a->polygonMode);
    }
    if (mask & 0x4000) {
        NNS_G3dMdlSetMdlCullModeAll(model, a->cullMode);
    }
    if (mask & 0x8000) {
        NNS_G3dMdlSetMdlPolygonIDAll(model, a->polygonId);
    }
    if (mask & 0x10000) {
        NNS_G3dMdlSetMdlAlphaAll(model, a->alpha);
    }
    if (mask & 0x20000) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(model, a->miscFlags & 0x8000);
    }
    if (mask & 0x40000) {
        NNS_G3dMdlSetMdlDepthTestCondAll(model, a->miscFlags & 0x4000);
    }
    if (mask & 0x80000) {
        NNS_G3dMdlSetMdl1DotAll(model, a->miscFlags & 0x2000);
    }
    if (mask & 0x100000) {
        NNS_G3dMdlSetMdlFarClipAll(model, a->miscFlags & 0x1000);
    }
    if (mask & 0x200000) {
        NNS_G3dMdlSetMdlXLDepthUpdateAll(model, a->miscFlags & 0x800);
    }
}

void ov01_021EAAB8(ModelAttributes *a, u32 light, s16 x, s16 y, s16 z) {
    a->lightVector[light][0] = x;
    a->lightVector[light][1] = y;
    a->lightVector[light][2] = z;
    NNS_G3dGlbLightVector((GXLightId)light, a->lightVector[light][0], a->lightVector[light][1], a->lightVector[light][2]);
}

void ov01_021EAAE0(ModelAttributes *a, u32 light, u16 color) {
    a->lightColor[light] = color;
    NNS_G3dGlbLightColor((GXLightId)light, a->lightColor[light]);
}

void ov01_021EAAF4(ModelAttributes *a, u16 value, u32 flags, BOOL apply) {
    a->diffuse = value;
    a->diffuseAmbientFlags = flags;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x100);
    }
}

void ov01_021EAB08(ModelAttributes *a, u16 value, BOOL apply) {
    a->ambient = value;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x200);
    }
}

void ov01_021EAB1C(ModelAttributes *a, u16 value, u32 flags, BOOL apply) {
    a->specular = value;
    a->specularEmissionFlags = flags;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x400);
    }
}

void ov01_021EAB30(ModelAttributes *a, u16 value, BOOL apply) {
    a->emission = value;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x800);
    }
}

void ModelAttributes_SetPolygonMode(ModelAttributes *a, u32 value, BOOL apply) {
    a->polygonMode = value;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x2000);
    }
}

void ModelAttributes_SetCullMode(ModelAttributes *a, u32 value, BOOL apply) {
    a->cullMode = value;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x4000);
    }
}

void ModelAttributes_SetAlpha(ModelAttributes *a, u32 value, BOOL apply) {
    a->alpha = value;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x10000);
    }
}

void ModelAttributes_SetMiscAttrEnabled(ModelAttributes *a, u32 bit, BOOL enabled, BOOL apply) {
    if (enabled == 1) {
        if (a->miscFlags & bit) {
            return;
        }
    } else {
        if (!(a->miscFlags & bit)) {
            return;
        }
    }
    a->miscFlags ^= bit;
    if (apply == 1) {
        ModelAttributes_ApplyGlobal(a, 0x1000);
    }
}
