#include "global.h"

typedef u8 Ov41WorkR11;
typedef struct Ov41ScaleR11 {
    fx32 x;
    fx32 y;
    fx32 z;
} Ov41ScaleR11;

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern void NNS_G2dSetupSoftwareSpriteCamera(void);
extern void ov41_02246830(Ov41WorkR11 *);
extern void PokepicManager_DrawAll(void *);
extern void *NARC_New(int, int);
extern void ov41_02246A94(Ov41WorkR11 *);
extern void *BgConfig_Alloc(int);
extern void ov41_022468FC(Ov41WorkR11 *);

void ov41_022465D8(Ov41WorkR11 *work, int x, int y, u16 angle, const Ov41ScaleR11 *scale);
void ov41_02246670(Ov41WorkR11 *work);

static inline void Ov41_G3Scale(fx32 x, fx32 y, fx32 z) {
    reg_G3_MTX_SCALE = x;
    reg_G3_MTX_SCALE = y;
    reg_G3_MTX_SCALE = z;
}

void ov41_022465D8(Ov41WorkR11 *work, int x, int y, u16 angle, const Ov41ScaleR11 *scale) {
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_PUSH = 0;
    NNS_G2dSetupSoftwareSpriteCamera();
    G3_Translate(x << FX32_SHIFT, y << FX32_SHIFT, 0);
    G3_RotZ(FX_SinIdx(angle), FX_CosIdx(angle));
    Ov41_G3Scale(scale->x, scale->y, scale->z);
    G3_Translate(-x << FX32_SHIFT, -y << FX32_SHIFT, 0);
    reg_G3_MTX_PUSH = 0;
    if (PTR(work, 0x1c) != NULL) {
        ov41_02246830(work);
    }
    if (PTR(work, 0x2c) != NULL) {
        PokepicManager_DrawAll(PTR(work, 0x20));
    }
    reg_G3_MTX_POP = 1;
    reg_G3_MTX_POP = 1;
}

void ov41_02246670(Ov41WorkR11 *work) {
    PTR(work, 0x180) = NARC_New(0x1a, 0xe);
    ov41_02246A94(work);
    PTR(work, 0x40) = BgConfig_Alloc(0xe);
    ov41_022468FC(work);
}
