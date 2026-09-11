#ifndef PRIVATE_OVERLAY_80_02237A70_H
#define PRIVATE_OVERLAY_80_02237A70_H

#include "global.h"

extern const u16 ov80_0223D4D4[];
extern const u16 ov80_0223D4D6[];
extern const u16 ov80_0223D4D8[];
extern const u16 ov80_0223D4DA[];

u16 LCRandom(void);
void GF_AssertFail(void);
int Party_GetCount(void *);
void *Party_GetMonByIndex(void *, int);
u32 GetMonData(void *, int, void *);
void SetMonData(void *, int, void *);
void *Save_PlayerData_GetProfile(void *);
void sub_0207217C(void *, void *, int, int, int, int);
BOOL Party_AddMon(void *, void *);
void SaveArray_Party_Init(void *);
void *AllocMonZeroed(int);
void Heap_Free(void *);
void ov80_0222A140(void *, void *, int);
void LoadRectToBgTilemapRect(void *, u8, void *, int, int, int, int);
void ScheduleBgTilemapBufferTransfer(void *, u8);
int sub_0205C1F0(int);
int sub_0205C218(int);
int sub_0205C268(int);
void sub_02031248(void *, int, int, int);
int FrontierSave_GetStat(void *, int, int);
void sub_02031108(void *, int, int, int);
void sub_02031228(void *, int, int, int);

int ov80_02237A70(int, u32, int);
void ov80_02237ADC(int, int, u16 *, int);
int ov80_02237B24(int, int);
int ov80_02237B58(int, int);
int ov80_02237D5C(int);
int ov80_02237D88(void *);
BOOL ov80_02237D8C(int);
void ov80_02237D9C(void *);
void ov80_02237DF4(void *, void *);
void ov80_02237E18(void *, void *, void *);
void ov80_02237E30(void *);
int ov80_02237E88(void *);
u16 ov80_02237ED8(void *);
void ov80_02237EFC(void *, void *, int);
void ov80_02237F3C(u16 *, int);
int ov80_02237F9C(int);
void ov80_02237FA4(void *, int, int);

#endif
