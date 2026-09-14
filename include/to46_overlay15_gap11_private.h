#ifndef TO46_OVERLAY15_GAP11_PRIVATE_H
#define TO46_OVERLAY15_GAP11_PRIVATE_H

#include "global.h"

#include "constants/heap.h"

#include "gf_gfx_loader.h"
#include "item.h"
#include "move.h"
#include "sprite_system.h"
#include "unk_02077678.h"

typedef struct BagWorkRaw {
    u8 raw[0x900];
} BagWorkRaw;

extern int sub_0207769C(u32);
extern int sub_02077800(u32);
extern u32 sub_02077818(u32);
extern NarcId sub_02077830(void);
extern const SpriteResourceCountsListUnion ov15_022009BC;
extern const OamManagerParam ov15_022009F4;
extern const OamCharTransferParam ov15_022009A8;
extern const ManagedSpriteTemplate ov15_02200B0C[];
extern void ov15_02200458(BagWorkRaw *, BOOL);
void ov15_021FF97C(BagWorkRaw *, u16, BOOL);
void ov15_021FFA40(BagWorkRaw *);
void ov15_021FFAD0(BagWorkRaw *);
void ov15_021FFDD8(BagWorkRaw *);

#endif
