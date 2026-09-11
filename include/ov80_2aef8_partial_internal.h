#ifndef PRIVATE_OV80_0222AEF8_H
#define PRIVATE_OV80_0222AEF8_H
#include "global.h"
u32 sub_0203769C(void);
BOOL sub_02037030(u32 command, void *data, u32 size);
void *Save_PlayerData_GetProfile(void *save);
void sub_02030FA0(void *save);
void *SaveArray_Party_Get(void *save);
u32 SizeOfStructPokemon(void);
void *Party_GetMonByIndex(void *party, s32 slot);
void MI_CpuCopy8(const void *src, void *dst, u32 size);
BOOL sub_02036FD8(u32 command, void *data, u32 size);
void sub_02030E08(void *save);
void *Save_Frontier_GetStatic(void *save);
u32 sub_0205C1F0(u32 value);
u32 sub_0205C268(u32 value);
u32 FrontierSave_GetStat(void *frontier, u32 a1, u32 a2);
s32 ov80_02237B24(u32 value, u32 mode);
s32 BattleArcade_GetMonCount(u32 value, u32 mode);
void *AllocMonZeroed(u32 heapId);
void Party_AddMon(void *party, void *mon);
void Party_SwapSlots(void *party, s32 a, s32 b);
void Heap_Free(void *ptr);
#endif
