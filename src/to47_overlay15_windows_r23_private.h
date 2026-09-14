#ifndef TO47_OVERLAY15_WINDOWS_R23_PRIVATE_H
#define TO47_OVERLAY15_WINDOWS_R23_PRIVATE_H

#include "global.h"
#include "bg_window.h"
#include "msgdata.h"

typedef struct Ov15WindowConfigR23 {
    u32 x;
    u32 y;
    u32 baseTile;
} Ov15WindowConfigR23;

typedef struct Ov15PositionR23 {
    u32 x;
    u32 y;
} Ov15PositionR23;

typedef struct Ov15BagWorkR23 {
    BgConfig *bgConfig;
    u8 pad_004[0xB0];
    Window windows[24];
    u8 pad_234[0x3C0];
    String *strings[8];
} Ov15BagWorkR23;

extern const Ov15WindowConfigR23 ov15_02200908[];
extern const Ov15PositionR23 ov15_022008E8[];
extern const Ov15PositionR23 ov15_022008D0[];

void ov15_021FE17C(Ov15BagWorkR23 *work);
void ov15_021FE1D0(Ov15BagWorkR23 *work);
void ov15_021FE204(Ov15BagWorkR23 *work);
void ov15_021FE3E0(Ov15BagWorkR23 *work);
void ov15_021FE4C8(Ov15BagWorkR23 *work);

#endif
