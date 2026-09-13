#ifndef OV68_RESIDUAL15_R40_PRIVATE_H
#define OV68_RESIDUAL15_R40_PRIVATE_H

#include "global.h"

#include "overlay_manager.h"
#include "unk_02019BA4.h"
#include "unk_02088288.h"

typedef struct MoveRelearnerArgs {
    void *unk00;
    u8 pad04[4];
    void *unk08;
    u8 pad0C[8];
    u16 unk14;
    u16 unk16;
    u8 pad18[3];
    u8 unk1B;
} MoveRelearnerArgs;

typedef struct MoveRelearner {
    MoveRelearnerArgs *args;
    u8 pad004[0x170 - 4];
    PokemonSummaryArgs summary;
    OverlayManager *summaryManager;
    u32 state;
    u8 pad1B4[0x1C8 - 0x1B4];
    GridInputHandler *gridInput;
} MoveRelearner;

void ov68_021E5B14(MoveRelearner *work);
u16 ov68_021E6BEC(MoveRelearner *work);
void ov68_021E5A58(MoveRelearner *work);
void ov68_021E7A18(MoveRelearner *work, u32 value);
void ov68_021E73A4(MoveRelearner *work, u32 value, u32 mode);
void ov68_021E7898(MoveRelearner *work, u32 value);
void ov68_021E7910(MoveRelearner *work);

extern const u8 _021E7BE8[2];
extern const TouchscreenHitbox ov68_021E7CF0[];
extern const DpadMenuBox ov68_021E7D64[];
extern const GridCallbacks ov68_021E7C08;

u32 ov68_021E74D8(MoveRelearner *work);
u32 ov68_021E7568(MoveRelearner *work);
void ov68_021E75C0(MoveRelearner *work);

#endif
