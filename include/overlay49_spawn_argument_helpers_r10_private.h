#ifndef TO47_OVERLAY49_R10_PRIVATE_H
#define TO47_OVERLAY49_R10_PRIVATE_H

#include "global.h"

typedef struct UnkStruct_ov42_022280A8 UnkStruct_ov42_022280A8;

typedef struct UnkStruct_ov42_02228110 {
    u32 unk0;
} UnkStruct_ov42_02228110;

typedef struct UnkStruct_ov44_02232914 {
    s16 unk0;
    s16 unk2;
} UnkStruct_ov44_02232914;

typedef struct UnkStruct_ov42_02228CDC {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} UnkStruct_ov42_02228CDC;

typedef struct Ov49R10Context {
    UnkStruct_ov42_022280A8 *unk0;
    void *unk4;
    u8 pad08[0xC];
    void *unk14;
    u8 pad18[0xC];
    void *unk24;
} Ov49R10Context;

typedef struct Ov49R10Config {
    u8 id;
    u8 unk1;
    u16 unk2;
    u8 unk4;
    u8 pad5[3];
} Ov49R10Config;

typedef struct Ov49R10Local {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
} Ov49R10Local;

typedef struct Ov49R10Object {
    void *unk0;
    void *unk4;
} Ov49R10Object;

extern const Ov49R10Config ov49_02269678[];
extern BOOL ov49_022589D8(void *, u8, u16 *, u16 *, u32);
extern Ov49R10Object *ov49_022593C0(Ov49R10Context *);
extern void *ov45_0223070C(void *);
extern void ov49_02258EEC(Ov49R10Context *, Ov49R10Object *, u32);
extern u32 ov49_02258C1C(void *, void *);
extern u32 ov49_022589B8(void *, u16, u16);
extern UnkStruct_ov42_02228110 *ov42_022280B8(UnkStruct_ov42_022280A8 *, void *);
extern UnkStruct_ov44_02232914 ov42_022282DC(UnkStruct_ov42_02228110 *);
extern UnkStruct_ov44_02232914 ov42_02228270(UnkStruct_ov44_02232914, s32);

void ov49_022591D8(Ov49R10Context *);
void ov49_0225927C(void *, u16, u8, u8);
u8 ov49_02259294(const u8 *, u32);
BOOL ov49_022592A8(Ov49R10Context *, UnkStruct_ov42_02228110 **, s32, u16);

#endif
