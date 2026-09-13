#ifndef POKEHEARTGOLD_TO45_OVERLAY49_MESSAGE_DESCRIPTOR_R65_INTERNAL_H
#define POKEHEARTGOLD_TO45_OVERLAY49_MESSAGE_DESCRIPTOR_R65_INTERNAL_H

#include "global.h"

typedef struct Ov49MessageDescriptor {
    void *message;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 count;
    u16 capacity;
    u8 filler14[0xC];
} Ov49MessageDescriptor;

typedef struct Ov49MessageWork {
    Ov49MessageDescriptor descriptor;
    u32 requestedCount;
} Ov49MessageWork;

typedef struct Ov49TargetDescriptor {
    u8 filler00[0x44];
    u16 count;
    u16 selection;
    void *target;
} Ov49TargetDescriptor;

void ov49_0225A10C(void *, u32);
void ov49_0225A120(void *, u32, u32);
void ov49_0225A134(void *);
void ov49_0225A144(void *, void *, u32);
void *ov49_0225A154(void *);
u32 ov49_0225A164(void *, u32);
void *ov49_0225A30C(void *, u32, u32);
void ov49_0225A37C(void *, u32, u32);
void ov49_0225A38C(void *, u32, u32);

#endif
