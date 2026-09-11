#ifndef TO40_OVERLAY_05_RESIDUAL_11_PRIVATE_H
#define TO40_OVERLAY_05_RESIDUAL_11_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "unk_02014DA0.h"

typedef struct Ov05WorkResidual {
    u8 raw_00[0xC];
    BgConfig *bgConfig;
} Ov05WorkResidual;
extern NNSGfdTexKey (*NNS_GfdDefaultFuncAllocTexVram)(u32, BOOL, u32);
extern NNSGfdPlttKey (*NNS_GfdDefaultFuncAllocPlttVram)(u32, BOOL, u32);
extern void GF_AssertFail(void);
extern const GraphicsModes ov05_0221EA88;
extern const BgTemplate ov05_0221EB8C;
extern const BgTemplate ov05_0221EB38;
extern const BgTemplate ov05_0221EBC4;
u32 ov05_0221DB4C(u32 size, BOOL is4x4);
u32 ov05_0221DB70(u32 size, BOOL is4x4);
void ov05_0221DB94(Ov05WorkResidual *work);
#endif
