#ifndef OV48_RESIDUAL24_PRIVATE_H
#define OV48_RESIDUAL24_PRIVATE_H

#include "global.h"

typedef struct Ov48R24LoadDesc {
    u16 screenMembers[2];
    u16 screenCount;
    u16 paletteMember;
    u16 paletteCount;
    u16 paletteIndex;
} Ov48R24LoadDesc;

typedef struct Ov48R24Animation {
    u16 frame;
    u16 duration;
    u8 enabled[3];
    u8 pad07;
    void *screenRaw[4];
    u16 screenCount;
    u16 displayedScreen;
    void *paletteRaw;
    void *paletteData;
    u8 paletteCount;
    u8 displayedPalette;
    u8 paletteIndex;
    u8 pad27;
} Ov48R24Animation;

void ov48_0225A868(u8 *work, u32 windowIndex, u32 row, void *source);
void ov48_0225A894(Ov48R24Animation *out, u8 *work, const Ov48R24LoadDesc *desc, u16 duration, u32 heapId);
void ov48_0225A928(Ov48R24Animation *anim);
void ov48_0225AA38(Ov48R24Animation *anim, u32 index, u8 enabled);

#endif
