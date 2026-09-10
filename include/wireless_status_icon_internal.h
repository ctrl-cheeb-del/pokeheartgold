#ifndef POKEHEARTGOLD_WIRELESS_STATUS_ICON_INTERNAL_H
#define POKEHEARTGOLD_WIRELESS_STATUS_ICON_INTERNAL_H
extern const char _0210F930[];
extern const char _0210F940[];
extern const char _0210F954[];
extern const char _0210F964[];
#include "global.h"

#include "assert.h"
#include "heap.h"
#include "sys_task_api.h"
#include "system.h"
#include "unk_02035900.h"
#include "unk_02037C94.h"

typedef struct UnkOamRegs {
    u32 unk00;
    u16 unk04;
} UnkOamRegs;

typedef struct UnkStruct_0203A3B0 {
    u32 unk00;
    s32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    void *unk14;
    SysTask *unk18;
    UnkOamRegs *unk1C;
    u8 unk20;
    u8 unk21;
    u8 unk22;
} UnkStruct_0203A3B0;

int sub_02034DCC(void);

UnkStruct_0203A3B0 *sub_0203A3B0(int a0, enum HeapID heapId, int a2, int a3, int a4, void *a5, int a6, int a7);
void sub_0203A42C(SysTask *task, void *data);
void sub_0203A438(UnkStruct_0203A3B0 *p, s32 a1);
void sub_0203A444(UnkStruct_0203A3B0 *p);
void sub_0203A478(UnkStruct_0203A3B0 *p, int a1, enum HeapID a2);
void *sub_0203A4AC(enum HeapID heapId);
void sub_0203A4D4(int engine, int a1, u32 plttBase, enum HeapID heapId);
NNSG2dCharacterData *sub_0203A534(int a0, u32 bank, u32 sz, void *buf);
void sub_0203A59C(int engine, int a1, enum HeapID heapId);
void sub_0203A700(UnkStruct_0203A3B0 *p);
void sub_0203A86C(void);
void sub_0203A880(void);
void sub_0203A8A8(int a0);
void sub_0203A8CC(int a0, int a1, int a2, int a3, u32 a4);
void sub_0203A914(void);
void sub_0203A930(s32 a0);
void sub_0203A948(int a0, enum HeapID a1);
void sub_0203A964(void);
void sub_0203A994(int a0);
void sub_0203A9C8(void);

extern const u8 _020F6A9C[];
extern const u8 _020F6AA4[];
extern const u8 _020F6AAC[];
extern const u8 _020F6AB4[];
extern const u8 _020F6ABC[];

extern const u8 *_0210F91C[];

extern UnkStruct_0203A3B0 *_021D4154;

#endif
