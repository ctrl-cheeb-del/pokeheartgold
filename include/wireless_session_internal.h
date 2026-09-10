#ifndef POKEHEARTGOLD_WIRELESS_SESSION_INTERNAL_H
#define POKEHEARTGOLD_WIRELESS_SESSION_INTERNAL_H
#include "global.h"

typedef void (*W6_WMCallbackFunc)(void *arg);

typedef struct W6_WMMeasureChannelCallback {
    u16 apiid;        // +0x00
    u16 errcode;      // +0x02
    u16 wlCmdID;      // +0x04
    u16 wlResult;     // +0x06
    u16 channel;      // +0x08
    u16 ccaBusyRatio; // +0x0A
} W6_WMMeasureChannelCallback;

typedef struct W6_WmWork {
    u32 unk_0000;
    u16 unk_0004;
    u8 pad_0006[0x1304 - 0x0006];
    u32 unk_1304;
    u32 unk_1308;
    u8 pad_130C[0x1310 - 0x130C];
    u32 unk_1310;
    u8 pad_1314[0x1318 - 0x1314];
    u32 unk_1318;
    u32 unk_131C;
    u8 pad_1320[0x132C - 0x1320];
    u16 unk_132C;
    u16 unk_132E;
    u32 unk_1330;
    u8 unk_1334;
    u8 unk_1335;
    u8 pad_1336[0x1338 - 0x1336];
    u32 unk_1338;
    u16 unk_133C;
    u16 unk_133E;
    u16 unk_1340;
    u8 unk_1342;
} W6_WmWork;

typedef struct W6_UnkStruct_021D4124 {
    u32 unk_00;
    W6_WmWork *unk_04;
} W6_UnkStruct_021D4124;

extern W6_UnkStruct_021D4124 _021D4124;

int WM_GetAllowedChannel(void);
int WM_MeasureChannel(W6_WMCallbackFunc callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);

void sub_02032844(u32 a0);
void sub_02032858(u32 a0);
void sub_02039AD8(u32 a0);
u32 sub_020335D4(u32 a0);

BOOL sub_020332C0(void);
u16 sub_0203335C(u16 channel);
void sub_020333D8(void *arg);
int sub_02033454(W6_WMCallbackFunc callback, u16 channel);
u16 sub_02033468(void);
s16 sub_02033494(u16 bitmap);
BOOL sub_02033528(void *buf, u32 a1);

BOOL sub_020332C0(void);
u16 sub_0203335C(u16 channel);
void sub_020333D8(void *arg);
int sub_02033454(W6_WMCallbackFunc callback, u16 channel);
u16 sub_02033468(void);
s16 sub_02033494(u16 bitmap);
BOOL sub_02033528(void *buf, u32 a1);

#endif
