#include "overlay102_easy_chat_input_r4_private.h"

int ov102_021E80BC(void *work) {
    int choice = ov102_021E7F6C(work);
    switch (choice) {
    case 0:
    case 1:
        PlaySE(0x5dc);
        U16(work, 0x4c) = choice + 1;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        return ov102_021E7D30(work, U16(work, 0x4c));
    case 2:
    case 3:
        U16(work, 0x4c) = 0;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        if (choice == 2) {
            ov102_021E79A0((u8 *)work + 0x64, (u8 *)work + 8);
        } else {
            ov102_021E7968((u8 *)work + 0x64, (u8 *)work + 8);
        }
        return ov102_021E7D30(work, 4);
    case 4:
    case 5:
        U16(work, 0x4c) = 0;
        U16(work, 0x4e) = choice - 4;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        return ov102_021E7D30(work, 0);
    case 6:
        U16(work, 0x4c) = 0;
        ov102_021E940C(PTR(work, 0x14), 0xf);
        break;
    }
    return 1;
}

int ov102_021E8178(void *work, void *state) {
    switch (U32(state, 0)) {
    case 0:
        U8(work, 0x6a) = ov102_021EA238(PTR(work, 0x14));
        U32(state, 0) = 1;
    case 1:
        if (U32(work, 0x74) == 0) {
            U32(state, 0) = ov102_021E7DBC(work);
        } else {
            U32(state, 0) = ov102_021E80BC(work);
        }
        break;
    case 2:
        if (ov102_021E947C(PTR(work, 0x14), 3) != 0) {
            U32(state, 0) = 0;
        }
        break;
    case 3:
        U32(state, 0) = 5;
        ov102_021E8D50(work, ov102_021E8D94);
        break;
    case 4:
        U32(state, 0) = 5;
        ov102_021E8D50(work, ov102_021E8E84);
        break;
    case 5:
        U32(state, 0) = 1;
        break;
    case 6:
        if (ov102_021E9464(PTR(work, 0x14)) != 0) {
            ov102_021E7A4C(work, ov102_021E8240);
        }
        break;
    }
    return 0;
}

int ov102_021E821C(void *work, void *state) {
    if (U32(state, 0) <= 1 && ov102_021E7A58(work, state) != 0) {
        return 0;
    }
    return ov102_021E8178(work, state);
}

int ov102_021E8240(void *work, void *state) {
    switch (U32(state, 0)) {
    case 0:
        if (ov102_021E947C(PTR(work, 0x14), 0x12) != 0) {
            ov102_021E8580(work, state);
        }
        break;
    case 1:
        if (ov102_021E9464(PTR(work, 0x14)) != 0) {
            ov102_021E7A4C(work, PTR(work, 0x24));
        }
        break;
    case 2:
        if (ov102_021E947C(PTR(work, 0x14), 0x1b) != 0) {
            U32(state, 0) = 0;
        }
        break;
    }
    return 0;
}

void ov102_021E8294(void *work, void *state) {
    u16 buttons;
    int mode = U32(work, 0x38);
    if ((mode == 0 && U8(work, 0x6b) != 0) || (mode == 1 && U8(work, 0x6b) != 1) || (U16(work, 0x30) & 4)) {
        PlaySE(0x5e4);
        U32(work, 0x38) = 4;
        U8(work, 0x6b) ^= 1;
        U16(work, 0x50) = 0;
        ov102_021E940C(PTR(work, 0x14), 0x1b);
        U32(state, 0) = 2;
        return;
    }
    buttons = U16(work, 0x30);
    if (buttons & 2) {
        PlaySE(0x5dc);
        ov102_021E940C(PTR(work, 0x14), 0xa);
        PTR(work, 0x24) = ov102_021E7AA4;
        U32(state, 0) = 1;
        return;
    }
    if (buttons & 1) {
        u16 selection = U16(work, 0x50);
        if (selection == 0xfe) {
            PlaySE(0x5dc);
            ov102_021E940C(PTR(work, 0x14), 0xa);
            PTR(work, 0x24) = ov102_021E7AA4;
            U32(state, 0) = 1;
            return;
        }
        if (ov102_021E85A8(PTR(work, 0x18), U8(work, 0x6b), selection) != 0) {
            PlaySE(0x5dc);
            ov102_021E874C((u8 *)work + 0x54, work);
            PTR(work, 0x24) = ov102_021E87B4;
            ov102_021E940C(PTR(work, 0x14), 0xb);
            U32(state, 0) = 1;
            return;
        }
        PlaySE(0x5f2);
        return;
    }
    if (ov102_021E85E8(work) != 0) {
        PlaySE(0x5dc);
        ov102_021E940C(PTR(work, 0x14), 0x11);
    }
}

int ov102_021E839C(void *work) {
    int result = TouchscreenHitbox_FindRectAtTouchNew(ov102_021EC600);
    if (result == -1) {
        return 0;
    }
    switch (result) {
    case 0:
        return 1;
    case 1:
        if (U8(work, 0x6b) == 0) {
            return 0;
        }
        break;
    case 2:
        if (U8(work, 0x6b) == 1) {
            return 0;
        }
        break;
    }
    return 2;
}
