#ifndef OV01_021FB04C_POKEHEARTGOLD_FIELD_RESOURCE_STREAM_H
#define OV01_021FB04C_POKEHEARTGOLD_FIELD_RESOURCE_STREAM_H

#include "global.h"

#include "constants/heap.h"

#include "assert.h"
#include "filesystem.h"
#include "heap.h"
#include "sys_task.h"

// Not present in a tracked header reachable from here; declared in
// include/field_fishing_internal.h with these exact signatures.
SysTask *SysTask_CreateOnMainQueue(SysTaskFunc func, void *data, u32 priority);
void SysTask_Destroy(SysTask *task);

// Element counts read out of the NARC header (0x18 bytes, 6 x u32).
typedef struct Ov01FB04C_Counts {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
} Ov01FB04C_Counts;

// Carved-out sub-buffers of one flat allocation (0x20 bytes).
typedef struct Ov01FB04C_Buffers {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0C;
    void *unk10;
    void *unk14;
    BOOL unk18;
    u32 unk1C;
} Ov01FB04C_Buffers;

// SysTask work block (0x88 bytes).
typedef struct Ov01FB04C_Work {
    u8 unk00[0x48];
    u32 unk48;
    Ov01FB04C_Counts counts;
    u32 unk64;
    u8 state;
    u8 *unk6C;
    Ov01FB04C_Buffers *unk70;
    u32 unk74;
    void **unk78;
    NARC *unk7C;
    u32 unk80;
    void **unk84;
} Ov01FB04C_Work;

#endif
