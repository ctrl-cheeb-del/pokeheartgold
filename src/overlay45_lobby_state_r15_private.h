#ifndef OVERLAY45_LOBBY_STATE_R15_PRIVATE_H
#define OVERLAY45_LOBBY_STATE_R15_PRIVATE_H

#include "global.h"

typedef struct Ov45State {
    u8 data[0x600];
} Ov45State;

typedef struct Ov45Copy20 {
    u32 v[5];
} Ov45Copy20;

typedef struct Ov45Copy148 {
    u32 v[0x25];
} Ov45Copy148;

typedef struct Ov45Flags {
    u8 pad[0x3a4];
    u8 flag[8];
} Ov45Flags;

extern int ov45_0222AFF8();
extern void ov45_0222BDCC();
extern void ov45_0222BD94();
extern void *Save_GameStats_Get();
extern void GameStats_Inc();
extern void GF_AssertFail(void);
extern int ov45_0222A394();
extern int ov45_0222A330();
extern int ov45_0222A3A0();
extern int ov45_0222C900();
extern int ov45_0222A53C();
extern int ov45_0222AB28();
extern void *ov45_0222CB40();
extern void *ov45_0222CB3C();
extern void *Save_PlayerData_GetProfile();
extern void *sub_02078DD8();
extern void sub_02078E28();
extern int ov45_0222E9E0();
extern int ov45_0222EC68();
extern int ov45_0222B020();
extern void ov45_0222BD5C();
extern int ov45_0222D8D4();
extern int ov45_0222EAD4();
extern void ov45_0222D8F0();
extern void ov45_0222C944();
extern void ov45_0222BDE8();
extern void ov45_0222BDB0();
extern int ov45_0222CBD0();
extern void ov45_0222BA3C();
extern void ov45_0222C9A0();
extern int ov45_0222A920();
extern int ov45_0222AADC();
extern int ov45_0222AAC8();
extern void ov45_0222C8C8();
extern int ov45_0222BADC();
extern void ov45_0222BB00();
extern void ov45_0222BAC4();
extern int ov45_0222CC50();
extern int ov45_0222CC7C();
extern void ov45_0222E9F8();
extern void ov45_0222EC10();
extern int ov45_0222AA84();
extern int ov45_0222AAA8();
extern void ov45_0222D638();
extern void *ov45_0222EA2C();
extern int ov45_0222EDC4();
extern int ov45_0222EDF0();
extern int ov45_0222E96C();
extern u32 ov45_0222AD4C();
extern u16 SaveArray_CalcCRC16();
extern void MI_CpuCopy8();

void ov45_0222B0BC(Ov45State *);
void ov45_0222B0D8(Ov45State *, int);
void ov45_0222B0E8(Ov45State *, int);
void IncrementGameStat47(void **);
void IncrementGameStat119(void **);
void ov45_0222B118(Ov45State *, int);
int ov45_0222B134(Ov45State *);
int ov45_0222B1B4(Ov45State *);
void *ov45_0222B1DC(Ov45State *);
void *ov45_0222B1EC(Ov45State *);
void ov45_0222B1FC(Ov45State *, const Ov45Copy20 *);
BOOL ov45_0222B21C(Ov45State *, Ov45Copy20 *);
void ov45_0222B244(Ov45State *);
void ov45_0222B270(Ov45State *);
BOOL ov45_0222B28C(const u16 *, u32);
void ov45_0222B470(int, Ov45State *);
void ov45_0222B530(int, void *, Ov45State *);
void ov45_0222B75C(const u8 *, int, Ov45State *);
void ov45_0222B79C(u8 *, u8 *);
void ov45_0222B840(Ov45State *);
void ov45_0222BA3C(Ov45State *);
void ov45_0222BAC4(u8 *, void *);
BOOL ov45_0222BADC(u8 *, void *);
void ov45_0222BB00(u8 *, const u8 *, u32);

#endif // OVERLAY45_LOBBY_STATE_R15_PRIVATE_H
