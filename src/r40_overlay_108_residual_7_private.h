#ifndef OV108_RESIDUAL7_R40_PRIVATE_H
#define OV108_RESIDUAL7_R40_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "unk_0208805C.h"

typedef struct SafariAreaCustomizer {
    enum HeapID heapId;
    u8 pad004[0x340 - 4];
    BgConfig *bgConfig;
    u8 pad344[0x4CC - 0x344];
    void *screenAllocation2;
    void *screenAllocation1;
    NNSG2dScreenData *screenData2;
    NNSG2dScreenData *screenData1;
    u8 pad4DC[0x184E3 - 0x4DC];
    u8 unk184E3;
} SafariAreaCustomizer;

void G2x_SetBlendAlpha_(u32 address, int plane1, int plane2, int eva, int evb);
void ov108_021E7ADC(SafariAreaCustomizer *work);
void ov108_021E7BB4(SafariAreaCustomizer *work, u32 index, int member);
void ov108_021E6C48(void);
typedef struct Ov108BgTemplates {
    BgTemplate items[8];
} Ov108BgTemplates;
extern const GraphicsModes ov108_021EA738;
extern const Ov108BgTemplates ov108_021EA898;

void ov108_021E6C68(SafariAreaCustomizer *work);
void ov108_021E6D24(SafariAreaCustomizer *work);
void ov108_021E6D80(SafariAreaCustomizer *work);

#endif
