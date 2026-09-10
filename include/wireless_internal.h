#ifndef POKEHEARTGOLD_WIRELESS_INTERNAL_H
#define POKEHEARTGOLD_WIRELESS_INTERNAL_H
#include <stddef.h>

#include "global.h"
typedef struct WirelessWork {
    void *context;
    u16 contextValue;
    u16 unk006;
    u32 userValue;
    u8 pad00C[0x34];
    u8 wmSystem[0x12C4];
    u32 mpRecvSize;
    u32 mpSendSize;
    u16 channel;
    u16 connectPending;
    u32 state;
    u32 wmState;
    void *portCallback;
    u32 unk131C;
    void *parentCallback;
    u32 unk1324;
    void *childCallback;
    u16 connectedBitmap;
    u16 activeBitmap;
    u32 error;
    u8 maxMachines;
    u8 connectBlocked;
    u8 pad1336[2];
    u32 random;
    u16 selectedChannel;
    u16 bestMeasure;
    u16 measuredBitmap;
    u8 flag1342;
    u8 flag1343;
    u8 entryComplete;
    u8 retryCount;
    u8 pad1346[0x3A];
} WirelessWork;
typedef struct WirelessGlobal {
    void *unk0;
    WirelessWork *work;
} WirelessGlobal;
extern WirelessGlobal _021D4124;
typedef char WirelessWorkSizeCheck[sizeof(WirelessWork) == 0x1380 ? 1 : -1];
typedef char WirelessStateOffsetCheck[offsetof(WirelessWork, state) == 0x1310 ? 1 : -1];
typedef char WirelessTailOffsetCheck[offsetof(WirelessWork, retryCount) == 0x1345 ? 1 : -1];
#endif
