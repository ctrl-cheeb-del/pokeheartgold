#include "overlay102_easy_chat_input_r4_private.h"

int ov102_021E7BF8(void *work) {
    int result;
    if (U32(work, 4) == 0) {
        result = ov102_021E7BD8(work);
    } else {
        result = ov102_021E7BE8(work);
    }
    switch (result) {
    case 0:
        U16(work, 0x4c) = 1;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        return ov102_021E7AB8(work, 1);
    case 1:
        U16(work, 0x4c) = 2;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        return ov102_021E7AB8(work, 2);
    case 2:
    case 3:
        U16(work, 0x50) = 0;
        U16(work, 0x4e) = result - 2;
        U16(work, 0x4c) = 0;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        return ov102_021E7AB8(work, 0);
    }
    return 0;
}

int ov102_021E7C84(void *work, void *state) {
    switch (U32(state, 0)) {
    case 0:
        if (ov102_021E9464(PTR(work, 0x14)) != 0) {
            if (U32(work, 0x74) == 0) {
                U32(state, 0) = ov102_021E7B18(work);
            } else {
                U32(state, 0) = ov102_021E7BF8(work);
            }
        }
        break;
    case 1:
        U32(state, 0) = 3;
        ov102_021E8D50(work, ov102_021E8D94);
        break;
    case 2:
        U32(state, 0) = 3;
        ov102_021E8D50(work, ov102_021E8E84);
        break;
    case 3:
        U32(state, 0) = 0;
        break;
    case 4:
        if (ov102_021E9464(PTR(work, 0x14)) != 0) {
            ov102_021E7A4C(work, ov102_021E8240);
        }
        break;
    }
    return 0;
}

int ov102_021E7D0C(void *work, void *state) {
    if (U32(state, 0) == 0 && ov102_021E7A58(work, state) != 0) {
        return 0;
    }
    return ov102_021E7C84(work, state);
}

int ov102_021E7D30(void *work, int choice) {
    switch (choice) {
    case 2:
        PlaySE(0x5dc);
        return 4;
    case 1:
        PlaySE(0x5dc);
        return 3;
    case 0:
        if (ov102_021EA238(PTR(work, 0x14)) == 0) {
            return 1;
        }
        PlaySE(0x5dc);
        U16(work, 0x50) = 0;
        ov102_021E940C(PTR(work, 0x14), 9);
        return 6;
    case 3:
        PlaySE(0x5dc);
        ov102_021E940C(PTR(work, 0x14), 0xf);
        break;
    case 4:
        PlaySE(0x5dc);
        U16(work, 0x4e) = 0;
        ov102_021E940C(PTR(work, 0x14), 3);
        return 2;
    }
    return 1;
}
