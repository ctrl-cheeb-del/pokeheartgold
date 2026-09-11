#ifndef POKEHEARTGOLD_UNK_02012A90_PRIVATE_H
#define POKEHEARTGOLD_UNK_02012A90_PRIVATE_H

#include "global.h"

typedef struct UnkStruct_02012ACC {
    u8 unk0;
    u8 unk1;
    u16 unk2;
} UnkStruct_02012ACC;

typedef struct UnkStruct_02012A90 {
    u8 unk0[0x30C];
    UnkStruct_02012ACC *unk30C;
    s32 unk310;
    s32 unk314;
    s32 unk318;
} UnkStruct_02012A90;

typedef struct UnkStruct_02012B1C_1 {
    u8 unk0[8];
    u8 unk8;
    u8 unk9[2];
    u8 unkB;
    u8 unkC[8];
    s32 unk14;
} UnkStruct_02012B1C_1;

typedef struct UnkStruct_02012BE8 {
    u8 unk0[0x4C];
    u8 unk4C[0x334];
    UnkStruct_02012B1C_1 *unk380;
    u8 unk384;
    u8 unk385;
    u8 unk386;
    u8 unk387;
} UnkStruct_02012BE8;

typedef struct UnkStruct_02012B1C_0 {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u32 unk10;
    UnkStruct_02012BE8 *unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
} UnkStruct_02012B1C_0;

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void GF_AssertFail(void);

void sub_02010F34(u32 param0, u32 param1, u32 param2);
void sub_02011068(u32 param0, s32 param1, u32 param2, u8 param3);
void sub_020117A0(void *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5);
BOOL sub_020117FC(void *param0);
void sub_02012940(void *param0, void *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7);
BOOL sub_02012A2C(void *param0);

void sub_02012A90(UnkStruct_02012A90 *param0);
void sub_02012ACC(const UnkStruct_02012ACC *param0, u8 *param1, s32 param2, s32 param3);
void sub_02012B1C(UnkStruct_02012B1C_0 *param0, UnkStruct_02012B1C_1 *param1);
BOOL sub_02012B80(UnkStruct_02012B1C_0 *param0);
void sub_02012BE8(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7);
BOOL sub_02012C68(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_0 *param1);
void sub_02012CDC(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7);
BOOL sub_02012D4C(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_0 *param1);

/* Generated integration prototypes. */
void sub_02012A90(UnkStruct_02012A90 *param0);
void sub_02012ACC(const UnkStruct_02012ACC *param0, u8 *param1, s32 param2, s32 param3);
void sub_02012B1C(UnkStruct_02012B1C_0 *param0, UnkStruct_02012B1C_1 *param1);
BOOL sub_02012B80(UnkStruct_02012B1C_0 *param0);
void sub_02012BE8(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7);
BOOL sub_02012C68(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_0 *param1);
void sub_02012CDC(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_1 *param1, s32 param2, s32 param3, u32 param4, u32 param5, u32 param6, u32 param7);
BOOL sub_02012D4C(UnkStruct_02012BE8 *param0, UnkStruct_02012B1C_0 *param1);
#endif
