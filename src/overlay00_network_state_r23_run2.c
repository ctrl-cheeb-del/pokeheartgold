#include "overlay00_network_state_r23_private.h"

void ov00_021E6554(int mode, int unused1, int unused2, int callbackArg) {
    _0221A680->busy = 0;
    _0221A680->unk_10CC = 0;
    _0221A680->unk_10A0 = 0;
    if (mode == 0 && _0221A680->unk_10E5 == 1 && ov00_021EE448() == 1) {
        if (_0221A680->state != 6) {
            _0221A680->state = 0x10;
        }
        if (_0221A680->session != NULL) {
            ov00_021E6A4C();
        }
    }
    if (_0221A680->disconnectCb != NULL) {
        _0221A680->disconnectCb(callbackArg, _0221A680->disconnectArg);
    }
}

void *ov00_021E65D4(int unused, u32 size, int group) {
    OSIntrMode intr = OS_DisableInterrupts();
    void *result = NNS_FndAllocFromExpHeapEx(_0221A680->heap0, size, group);
    if (result == NULL && _0221A680->fallbackEnabled != 0) {
        result = NNS_FndAllocFromExpHeapEx(_0221A680->heap1, size, group);
    }
    if (result == NULL) {
        sub_02039AD8(1);
        OS_RestoreInterrupts(intr);
        return NULL;
    }
    OS_RestoreInterrupts(intr);
    return result;
}

void ov00_021E6638(int unused, void *ptr, u32 size) {
    if (ptr != NULL) {
        OSIntrMode intr = OS_DisableInterrupts();
        if (NNS_FndGetGroupIDForMBlockExpHeap(ptr) == 0x10) {
            if (_0221A680->fallbackEnabled == 0) {
                sub_02039AD8(1);
                return;
            }
            NNS_FndFreeToExpHeap(_0221A680->heap1, ptr);
        } else {
            NNS_FndFreeToExpHeap(_0221A680->heap0, ptr);
        }
        OS_RestoreInterrupts(intr);
    }
}
