#ifndef PRIVATE_UNK_020932E0_RESIDUAL_7_H
#define PRIVATE_UNK_020932E0_RESIDUAL_7_H

#include "unk020932e0_opus_partial_internal.h"

typedef struct UnkEntryData_020932E0 {
    u32 species;      // 0x00
    u32 unk_04;       // 0x04
    u16 isEgg;        // 0x08
    u16 form;         // 0x0A
    u16 heldItem;     // 0x0C
    u16 unk_0E;       // 0x0E
    u8 filler_10[0x20];
} UnkEntryData_020932E0; // 0x30

typedef struct UnkEntryFull_020932E0 {
    Sprite *sprite;              // 0x00
    UnkEntryData_020932E0 data;  // 0x04
} UnkEntryFull_020932E0;         // 0x34

typedef int (*UnkFetch_020932E0)(void *, u32, int, UnkEntryData_020932E0 *);

typedef struct UnkState_020932E0 {
    BgConfig *bgConfig;                  // 0x0000
    enum HeapID heapId;                  // 0x0004
    YesNoPrompt *yesNoPrompt;            // 0x0008
    u8 filler_0C[1];                     // 0x000C
    u8 count;                            // 0x000D
    u8 unk_0E;                           // 0x000E
    u8 unk_0F;                           // 0x000F
    u8 unk_10;                           // 0x0010
    u8 unk_11;                           // 0x0011
    u8 unk_12;                           // 0x0012
    u8 unk_13;                           // 0x0013
    u32 state;                           // 0x0014
    SpriteList *spriteList;              // 0x0018
    u8 filler_1C[0x198 - 0x1C];          // 0x001C
    UnkEntryFull_020932E0 entriesB[30];  // 0x0198
    u8 filler_7B0[0x7E8 - 0x7B0];        // 0x07B0
    UnkEntryFull_020932E0 entries[3];    // 0x07E8
    u8 filler_884[0x8D4 - 0x884];        // 0x0884
    UnkGfxBuf_02094758 gfxBufs[30];      // 0x08D4
    void *unk_463C;                      // 0x463C
    Party *party;                        // 0x4640
    UnkCallback_020932E0 callback;       // 0x4644
    UnkFetch_020932E0 fetch;             // 0x4648
    u8 filler_464C[0x46D0 - 0x464C];     // 0x464C
    void *unk_46D0;                      // 0x46D0
    void *unk_46D4;                      // 0x46D4
    u8 filler_46D8[0x46E8 - 0x46D8];     // 0x46D8
} UnkState_020932E0;                     // 0x46E8

#endif
