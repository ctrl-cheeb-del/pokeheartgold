#ifndef OV85_R14_PRIVATE_H
#define OV85_R14_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "camera.h"
#include "gf_3d_vramman.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "palette.h"
#include "sprite.h"

#include <nnsys/g2d/load/g2d_NCG_load.h>
#include <nnsys/g2d/load/g2d_NCL_load.h>
#include <nnsys/g2d/load/g2d_NSC_load.h>
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/util.h>

typedef struct ArcScene {
    u8 pad_000[0xD84];
    BgConfig *unk_D84;
    NNSG2dScreenData *unk_D88;
    NNSG2dCharacterData *unk_D8C;
    NNSG2dPaletteData *unk_D90;
    u8 pad_D94[0x04];
    void *unk_D98;
    PaletteData *unk_D9C;
    GXRgb unk_DA0[8];
} ArcScene;

extern const GraphicsModes ov85_021EA538;
extern const BgTemplate ov85_021EA60C;
extern const BgTemplate ov85_021EA628;
extern const BgTemplate ov85_021EA644;
extern const BgTemplate ov85_021EA660;
extern const BgTemplate ov85_021EA67C;
extern const u32 ov85_021EA700[];

extern void Thunk_G3X_Reset(void);
extern void RequestSwap3DBuffers(u32 a0, u32 a1);
extern void SpriteSystem_DrawSprites(void *spriteSystem);
extern void *ov85_021E8588(ArcScene *work, u32 a1, u32 a2);
extern void ov85_021E7628(ArcScene *work);
extern void ov85_021E782C(ArcScene *work);

#endif // OV85_R14_PRIVATE_H
