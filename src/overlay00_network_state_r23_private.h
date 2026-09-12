#ifndef OVERLAY00_NETWORK_STATE_R23_PRIVATE_H
#define OVERLAY00_NETWORK_STATE_R23_PRIVATE_H
#include <nnsys/fnd/expheap.h>

#include "global.h"
typedef struct Ov00R6State {
    u8 pad_0000[0xF94];
    NNSFndHeapHandle heap0;
    u32 fallbackEnabled;
    NNSFndHeapHandle heap1;
    void (*allocFail)(int, u32);
    void (*recvLocal)(u32, void *, u16);
    void (*recvOnline)(u32, void *, u16);
    void (*disconnectCb)(int, u32);
    u32 disconnectArg;
    u8 pad_0FB4[0x1070 - 0xFB4];
    s32 state;
    u32 unk_1074;
    s32 busy;
    s32 playerCount;
    u32 unk_1080;
    u32 unk_1084;
    u32 unk_1088;
    u32 unk_108C;
    void *session;
    u32 unk_1094;
    u32 unk_1098;
    u32 unk_109C;
    u32 unk_10A0;
    u32 unk_10A4;
    u32 receivePending;
    s32 timer[8];
    u32 unk_10CC;
    u32 modeFlag;
    u16 localId;
    u8 pad_10D6[7];
    u8 packetByte;
    u8 forceResult;
    u8 pad_10DF[6];
    u8 unk_10E5;
} Ov00R6State;
extern Ov00R6State *_0221A680;
u32 ov00_021EE4FC(void);
int ov00_021EE490(void);
int ov00_021EE530(u8);
int ov00_021F9580(u8);
int sub_0203993C(void);
int sub_02034084(void);
void sub_02039AD8(int);
int NNS_FndGetGroupIDForMBlockExpHeap(void *);
void ov00_021F9750(u32, void *, u32);
int ov00_021EE448(void);
int ov00_021E77A4(void);
void ov00_021E6A4C(void);
void ov00_021E644C(u32);
void ov00_021E6484(u32, const u8 *, u32);
void ov00_021E6554(int, int, int, int);
void *ov00_021E65D4(int, u32, int);
void ov00_021E6638(int, void *, u32);
int ov00_021E6790(void);
int ov00_021E67E0(int);
int ov00_021E6964(void);
void ov00_021EC11C(u32 *, u32 *);
void ov00_021EC210(void);
void ov00_021ED9B4(void);
void ov00_021EC8D8(void);
void ov00_021E62D8(void);
#endif
