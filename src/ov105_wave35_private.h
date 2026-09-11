#ifndef OV105_PRIVATE_H
#define OV105_PRIVATE_H

#include "global.h"

#include "camera.h"
#include "filesystem.h"
#include "gf_3d_render.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "overlay_manager.h"
#include "screen_fade.h"
#include "system.h"

typedef struct Ov105ModelSet {
    NNSG3dRenderObj renderObj;
    NNSG3dResMdl *resMdl;
    NNSG3dResFileHeader *fileHeader;
    void *anmData[4];
    NNSG3dAnmObj *anmObj[4];
} Ov105ModelSet;

typedef struct Ov105App {
    Camera *camera;
    Ov105ModelSet models[1];
    NNSFndAllocator allocator;
    VecFx32 target;
    u8 unk9C;
    u8 unk9D;
    u8 unk9E;
    u8 unk9F;
    u8 unkA0;
    u8 unkA1;
    u8 unkA2;
    u8 unkA3;
    const u32 *seTable;
} Ov105App;

typedef struct Ov105SceneConfig {
    VecFx16 lightVecs[4];
    GXRgb lightColors[4];
    GXRgb diffuse;
    GXRgb ambient;
    GXRgb specular;
    GXRgb emission;
    u32 unk28;
    u32 unk2C;
    u32 polyAttr0;
    u32 polyAttr1;
    u32 polyAttr2;
    u32 polyAttr3;
    u32 polyAttr4;
    u32 polyAttr5;
} Ov105SceneConfig;

typedef struct Ov105Args {
    u8 unk0;
    u8 unk1;
    Ov105SceneConfig *config;
} Ov105Args;

typedef struct Ov105NarcFiles {
    u32 modelFile;
    u16 animFiles[4];
} Ov105NarcFiles;

typedef struct Ov105AnmObjRaw {
    fx32 frame;
    u32 unk4;
    const struct Ov105AnmRes *res;
} Ov105AnmObjRaw;

struct Ov105AnmRes {
    u32 unk0;
    u16 numFrames;
};

void Thunk_G3X_Reset(void);
void RequestSwap3DBuffers(BOOL sortMode, BOOL bufferMode);
void G3X_SetEdgeColorTable(const GXRgb *table);
void GfGfx_DisableEngineBPlanes(void);
void PlaySE(u16 seq);
void sub_020880CC(int a0, enum HeapID heapID);

BOOL ov105_021E5900(OverlayManager *man);
BOOL ov105_021E59DC(OverlayManager *man, u32 *state);
BOOL ov105_021E5B14(OverlayManager *man);
void ov105_021E5B68(void);
void ov105_021E5BCC(Ov105App *app);
void ov105_021E5C84(void);
void ov105_021E5CA4(Ov105App *app);

#endif
