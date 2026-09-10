#ifndef PRIVATE_OVERLAY_01_021FCE98_H
#define PRIVATE_OVERLAY_01_021FCE98_H

// THUMB comes from the SOURCE: global.h -> nitro/code16.h -> #pragma thumb on
#include <string.h>

#include "global.h"

#include "field/overlay_01_021FB878.h"

#include "field_move_environment.h"
#include "field_system.h"
#include "follow_mon.h"
#include "heap.h"
#include "map_object.h"
#include "overlay_01.h"
#include "overlay_01_022053EC.h"
#include "overlay_02.h"
#include "player_avatar.h"
#include "task.h"

// Still assembly-only (asm/include/*.inc only); no tracked prototype exists.
extern u32 ov01_022062CC(FieldSystem *fieldSystem);

// 0xc bytes: the task env that replaces FieldMoveData in state 0
// (Heap_AllocAtEnd(HEAP_ID_FIELD2, 0xc); partySlot carried over to +0x8).
typedef struct SweetScentFieldEnv {
    void *effect;    // 0x00 -- ov02_02249458 handle
    void *honeyWork; // 0x04 -- GetHoneySweetScentWorkSize() block
    u32 partySlot;   // 0x08 -- copied from FieldMoveData::partySlot
} SweetScentFieldEnv;

// 0xd4 bytes: Heap_AllocAtEnd(HEAP_ID_FIELD1, 0xd4) in ov01_021FCFEC.
typedef struct SweetScentAnimWork {
    NNSFndAllocator allocator;      // 0x00
    Field3dModel model;             // 0x10
    Field3DModelAnimation anims[3]; // 0x20, 0x34, 0x48
    Field3dObject object;           // 0x5c
} SweetScentAnimWork;               // 0xd4

#endif // PRIVATE_OVERLAY_01_021FCE98_H
