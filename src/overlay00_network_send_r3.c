#include "global.h"

typedef struct Ov00R3State {
    u8 pad_0000[0xF10];
    void *dwc;
    u8 pad_0F14[0xFA4 - 0xF14];
    void (*recvLocal)(u32, void *, u16);
    void (*recvOnline)(u32, void *, u16);
    u8 pad_0FAC[0x1070 - 0xFAC];
    s32 state;
    u32 unk_1074;
    s32 busy;
    s32 playerCount;
    u32 unk_1080;
    void *unk_1084;
    u8 pad_1088[8];
    void *unk_1090;
    s32 unk_1094;
    s32 unk_1098;
    void *unk_109C;
    u8 pad_10A0[8];
    u32 unk_10A8;
    u8 pad_10AC[0x10D4 - 0x10AC];
    u16 localId;
    u8 pad_10D6[6];
    u8 packetByte;
    u8 pad_10DD[9];
    u8 dirtyCleared;
} Ov00R3State;

extern Ov00R3State *_0221A680;

int ov00_021EE490(void);
int ov00_021E6790(void);
u32 ov00_021EE4FC(void);
u32 ov00_021F9750(u32, void *, u32);
void ov00_021EE278(void);
int DWC_CheckDirtyFlag(void *);
void DWC_ClearDirtyFlag(void *);
int ov00_021EDE74(int, void *, void *, void *, int, void *, int);
void ov00_021EFF04(void *, int);
void sub_02039AD8(int);
void ov00_021E6274(void);
void ov00_021E6298(void);
void ov00_021E629C(void);
void ov00_021E62D4(void);
void ov00_021F1284(void);
int sub_0203993C(void);
int sub_02034084(void);
void ov00_021E69A8(void *);
int ov00_021E6690(void);
int ov00_021E6850(void);
void ov00_021E5E34(void);

int ov00_021E5F84(void *src, int size);
int ov00_021E602C(void *src, int size);
int ov00_021E60E8(void *src, int size);
void ov00_021E6240(void);
void ov00_021E61A8(int mode, int unused, int arg);
int ov00_021E5E54(int flag);

int ov00_021E5F84(void *src, int size) {
    if (size >= 0x100) {
        return 0;
    }
    if (ov00_021EE490() == 0) {
        if (_0221A680->recvLocal != NULL) {
            _0221A680->recvLocal(0, src, (u16)size);
        }
        return 1;
    }
    if (_0221A680->busy != 0 || ov00_021E6790() == 0) {
        return 0;
    }
    *(u32 *)_0221A680 = 1 | ((u32)_0221A680->localId << 8);
    _0221A680->packetByte++;
    ((u8 *)_0221A680)[2] = _0221A680->packetByte;
    MI_CpuCopy8(src, (u8 *)_0221A680 + 4, size);
    _0221A680->busy = 1;
    ov00_021F9750(1, _0221A680, size + 4);
    return 1;
}

int ov00_021E602C(void *src, int size) {
    if (size >= 0x100) {
        return 0;
    }
    if (ov00_021EE490() != 0) {
        return 0;
    }
    if (_0221A680->busy != 0 || ov00_021E6790() == 0) {
        return 0;
    }
    *(u32 *)_0221A680 = 1 | ((u32)_0221A680->localId << 8);
    _0221A680->packetByte++;
    ((u8 *)_0221A680)[2] = _0221A680->packetByte;
    MI_CpuCopy8(src, (u8 *)_0221A680 + 4, size);
    _0221A680->busy = 1;
    if (ov00_021F9750(ov00_021EE4FC(), _0221A680, size + 4) == 0) {
        _0221A680->busy = 0;
        return 0;
    }
    if (_0221A680->recvOnline != NULL) {
        _0221A680->recvOnline(0, src, (u16)size);
    }
    return 1;
}

int ov00_021E60E8(void *src, int size) {
    u16 id;
    if (size >= 0x100) {
        return 0;
    }
    if (_0221A680->busy != 0 || ov00_021E6790() == 0) {
        return 0;
    }
    *(u32 *)_0221A680 = 1 | ((u32)_0221A680->localId << 8);
    _0221A680->packetByte++;
    ((u8 *)_0221A680)[2] = _0221A680->packetByte;
    MI_CpuCopy8(src, (u8 *)_0221A680 + 4, size);
    _0221A680->busy = 1;
    id = ov00_021EE4FC();
    if (ov00_021F9750(id, _0221A680, size + 4) != id) {
        _0221A680->busy = 0;
        return 0;
    }
    if (_0221A680->recvOnline != NULL) {
        _0221A680->recvOnline(ov00_021EE490(), src, (u16)size);
    }
    return 1;
}

void ov00_021E61A8(int mode, int unused, int arg) {
    if (DWC_CheckDirtyFlag(_0221A680->dwc)) {
        DWC_ClearDirtyFlag(_0221A680->dwc);
        _0221A680->dirtyCleared = 1;
    }
    if (mode == 0) {
        if (ov00_021EDE74(0, ov00_021E6274, _0221A680->dwc, ov00_021E6298, arg, ov00_021E629C, arg) == 0) {
            sub_02039AD8(1);
            return;
        }
        ov00_021EFF04(ov00_021E62D4, 0);
        return;
    }
    _0221A680->state = 0xC;
}

void ov00_021E6240(void) {
    if (_0221A680->unk_10A8 != 0) {
        ov00_021EE278();
        _0221A680->unk_1098 = -1;
        _0221A680->state = 0x12;
    }
}
