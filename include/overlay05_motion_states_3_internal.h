#ifndef TO45_SOL_R5_OVERLAY_05_RESIDUAL_3_PRIVATE_H
#define TO45_SOL_R5_OVERLAY_05_RESIDUAL_3_PRIVATE_H

#include "global.h"

typedef void BgConfig;

typedef struct Ov05RootR3 {
    u8 pad00[0x24];
    u32 heapId;
    u8 direction;
} Ov05RootR3;

typedef struct Ov05WorkR3 {
    Ov05RootR3 *root;
    u8 pad004[8];
    BgConfig *bgConfig;
    u8 pad010[0xb64];
    s32 step;
    s16 x;
    s16 y;
    s8 rangeX;
    s8 rangeY;
    u8 padB7E;
    u8 state;
    u8 padB80[2];
    u8 frame;
} Ov05WorkR3;

int ov05_0221DAE0(Ov05WorkR3 *work);
void ov05_0221D3AC(Ov05WorkR3 *work, int index, s16 x, s16 y);
void ov05_0221D664(Ov05WorkR3 *work, int index, s16 x, s16 y);
int ov05_0221C050(Ov05WorkR3 *work);
int ov05_0221C21C(Ov05WorkR3 *work);
int ov05_0221C430(Ov05WorkR3 *work);
int Bg_GetXpos(BgConfig *bgConfig, int bgId);
void ScheduleSetBgPosText(BgConfig *bgConfig, int bgId, int op, int value);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
int IsPaletteFadeFinished(void);
void PlaySE(int seqNo);
u32 LCRandom(void);

#endif
