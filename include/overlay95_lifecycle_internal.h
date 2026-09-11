#ifndef TO40_OVERLAY_95_OVERLAY95_LIFECYCLE_INTERNAL_H
#define TO40_OVERLAY_95_OVERLAY95_LIFECYCLE_INTERNAL_H
#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"
void *GF_3DVramMan_Create(int, int, int, int, int, void (*)(void));
void ov95_021E5974(void);
void ov95_021E5954(void);
void ov95_021E59F8(void);
void ov95_021E5A38(void *);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(u32, BOOL, u32);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(u32, BOOL, u32);
void GF_AssertFail(void);
void sub_02014DA0(void);
void GfGfx_DisableEngineAPlanes(void);
extern const GraphicsBanks ov95_021E75B4;
extern const GraphicsModes ov95_021E7538;
typedef struct Ov95BgTemplates {
    BgTemplate item[3];
} Ov95BgTemplates;
extern const Ov95BgTemplates ov95_021E767C;
#endif
