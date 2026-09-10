#include "link_synchronization_internal.h"

void sub_020379A0(enum HeapID heap) {
    int i;
    if (_021D414C == NULL) {
        _021D414C = Heap_Alloc(heap, sizeof(LinkSync));
        MI_CpuFill8(_021D414C, 0, sizeof(LinkSync));
    }
    for (i = 0; i < 8; i++) {
        _021D414C->states[i] = 255;
    }
    _021D414C->completed = 255;
    _021D414C->requested = 255;
    _021D414C->pending = 0;
    _021D414C->resend = 0;
}

void sub_020379F8(void) {
    Heap_Free(_021D414C);
    _021D414C = NULL;
}

BOOL sub_02037A10(void) {
    return _021D414C != NULL;
}

void sub_02037A24(int sender, int unused, u8 *data) {
    u8 state = data[0];
    u8 packet[2];
    int i;
    if (sub_0203769C() != 0) {
        return;
    }
    packet[0] = sender;
    packet[1] = state;
    sub_02037184(18, packet);
    _021D414C->states[sender] = state;
    for (i = 0; i < 8; i++) {
        if (sub_020373B4((u16)i) && state != _021D414C->states[i]) {
            return;
        }
    }
    if (sub_02037184(17, &state) == 0) {
        _021D414C->resend = 1;
    }
}

void sub_02037A98(int sender, int unused, u8 *data) {
    _021D414C->states[data[0]] = data[1];
}

void sub_02037AAC(int sender, int unused, u8 *data) {
    _021D414C->completed = data[0];
}

void sub_02037AC0(u8 state) {
    _021D414C->requested = state;
    _021D414C->pending = 1;
}

void sub_02037ADC(void) {
    if (_021D414C) {
        if (_021D414C->pending && sub_020376E0(16, &_021D414C->requested)) {
            _021D414C->pending = 0;
        }
        if (_021D414C->resend && sub_02037184(17, _021D414C->states)) {
            _021D414C->resend = 0;
        }
    }
}

BOOL sub_02037B38(u8 state) {
    if (_021D414C == NULL) {
        return TRUE;
    }
    if (_021D414C->completed == state) {
        return TRUE;
    }
    return FALSE;
}

u8 sub_02037B5C(int index) {
    return _021D414C->states[index];
}

void sub_02037B6C(int sender, int unused, u8 *data) {
    _021D414C->values[sender][0] = data[0];
    _021D414C->values[sender][1] = data[1];
}

u32 sub_02037B88(void) {
    return 2;
}

void sub_02037B8C(u32 key, u8 value) {
    u8 packet[2];
    packet[0] = key;
    packet[1] = value;
    sub_020376E0(19, packet);
}

s32 sub_02037BA0(s32 sender, s32 key) {
    if (_021D414C == NULL) {
        return -1;
    }
    if (_021D414C->values[sender][0] == key) {
        return _021D414C->values[sender][1];
    }
    return -1;
}

void sub_02037BC8(void) {
    int i;
    for (i = 0; i < 8; i++) {
        MI_CpuFill8(_021D414C->values[i], 0, 2);
    }
}

void sub_02037BEC(void) {
    int i;
    for (i = 0; i < 8; i++) {
        _021D414C->received[i] = 0;
    }
}

u32 sub_02037C0C(u32 index, s16 *data) {
    if (_021D414C) {
        MI_CpuCopy8(data, &_021D414C->packets[index], 0x46);
        sub_020376E0(20, &_021D414C->packets[index]);
        return TRUE;
    }
    return FALSE;
}

u16 *sub_02037C44(s32 index) {
    if (_021D414C->received[index]) {
        return (u16 *)&_021D414C->packets[index];
    }
    return NULL;
}

void sub_02037C68(int sender, int unused, void *data) {
    _021D414C->received[sender] = 1;
    MI_CpuCopy8(data, &_021D414C->packets[sender], 0x46);
}
