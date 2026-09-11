#ifndef OVERLAY_56_RESIDUAL_2_PRIVATE_H
#define OVERLAY_56_RESIDUAL_2_PRIVATE_H
#include "global.h"

#include "pokemon_icon_idx.h"
#include "sprite_system.h"
#include "unk_0200B150.h"

typedef struct Ov56WorkResidual {
    enum HeapID heapId;
    u8 raw_004[8];
    u8 mode;
    u8 raw_00D[0x0F];
    u8 *records;
    u8 raw_020[0x90];
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    ManagedSprite *sprites[3];
} Ov56WorkResidual;

typedef union Ov56ResourceId {
    u16 raw;
    struct {
        u16 id : 12;
        u16 palette : 4;
    };
} Ov56ResourceId;

typedef struct Ov56Record {
    u8 raw_00[0x18];
    Ov56ResourceId resource;
} Ov56Record;

extern void sub_0203A964(void);
extern void GF_CreateVramTransferManager(u32 capacity, enum HeapID heapId);
extern const OamManagerParam ov56_021E6E38;
extern const OamCharTransferParam ov56_021E6DF4;
extern const SpriteResourceCountsListUnion ov56_021E6E08;

void ov56_021E6BB4(Ov56WorkResidual *work);
#endif
