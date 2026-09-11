#ifndef OVERLAY_104_PRIVATE_H
#define OVERLAY_104_PRIVATE_H

#include "global.h"

#include "camera.h"
#include "filesystem.h"
#include "gf_3d_render.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "overlay_manager.h"
#include "screen_fade.h"
#include "sound_02004A44.h"
#include "system.h"
#include "unk_02005D10.h"
#include "unk_02026E30.h"
#include "unk_0208805C.h"

#define HEAPID(n) ((enum HeapID)(n))

typedef struct Ov104AnmHeader {
    u32 unk00;
    u16 numFrames;
} Ov104AnmHeader;

typedef struct Ov104AnmObj {
    fx32 frame;
    u32 unk04;
    const Ov104AnmHeader *anm;
} Ov104AnmObj;

typedef struct Ov104Model {
    NNSG3dRenderObj obj;
    NNSG3dResMdl *mdl;
    NNSG3dResFileHeader *file;
    void *anmFile[2];
    void *anmObj[2];
} Ov104Model;

typedef struct Ov104Work {
    Camera *camera;
    Ov104Model models[3];
    NNSFndAllocator allocator;
    VecFx32 target;
    u8 unk164;
    u8 unk165;
    u8 unk166;
    u8 unk167;
    u8 step;
    u8 counter;
    const u32 *seTable;
} Ov104Work;

typedef struct Ov104Lighting {
    VecFx16 lightVec[4];
    GXRgb lightColor[4];
    GXRgb diffuse;
    GXRgb ambient;
    GXRgb specular;
    GXRgb emission;
    BOOL diffAmbFlag;
    BOOL specEmiFlag;
    u32 polygonAttr[6];
} Ov104Lighting;

typedef struct Ov104Args {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    const Ov104Lighting *lighting;
} Ov104Args;

typedef struct Ov104ModelIds {
    u32 modelFileId;
    u16 anmFileIds[2];
} Ov104ModelIds;

#endif
