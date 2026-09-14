#ifndef POKEHEARTGOLD_TO45_OVERLAY45_MODEL_POOL_R41_PRIVATE_H
#define POKEHEARTGOLD_TO45_OVERLAY45_MODEL_POOL_R41_PRIVATE_H

#include "global.h"

typedef struct Ov45R41ModelResource {
    u8 raw[0x10];
} Ov45R41ModelResource;

typedef struct Ov45R41ModelInstance {
    u8 raw[0x90];
} Ov45R41ModelInstance;

typedef struct Ov45R41Entry {
    u32 unk_00;
    void *unk_04;
    u8 padding_08[0x88];
} Ov45R41Entry;

typedef struct Ov45R41Pool {
    u8 padding_00[0x10];
    Ov45R41Entry *entries;
    u32 count;
} Ov45R41Pool;

void sub_020181B0(Ov45R41ModelInstance *instance, Ov45R41ModelResource *resource);
void ov45_02230A5C(Ov45R41ModelResource *resource, Ov45R41ModelInstance *instance);
Ov45R41Entry *ov45_02230A6C(Ov45R41Pool *pool);
BOOL ov45_02230AA4(Ov45R41Entry *entry);
void ov45_02230AB4(Ov45R41Entry *entry);

#endif
