#include "overlay102_easy_chat_input_r4_private.h"

int ov102_021E8458(void *work) {
    int result;
    int hit = TouchscreenHitbox_FindRectAtTouchNew(ov102_021EC5E0);
    result = -1;
    if (hit != result) {
        result = ov102_021EC5A0((s16)(U16(gSystem, 0x60) - 0x14), (s16)(U16(gSystem, 0x62) - 0x40));
    }
    return result;
}

void ov102_021E848C(void *work, void *state) {
    int input = ov102_021E839C(work);
    switch (input) {
    case 1:
        PlaySE(0x5dc);
        ov102_021E940C(PTR(work, 0x14), 0xa);
        PTR(work, 0x24) = ov102_021E7AA4;
        U32(state, 0) = 1;
        return;
    case 2:
        PlaySE(0x5e4);
        U8(work, 0x6b) ^= 1;
        U16(work, 0x50) = 0;
        ov102_021E940C(PTR(work, 0x14), 0x1b);
        U32(state, 0) = 2;
        return;
    }
    if (U8(work, 0x6b) == 0) {
        input = ov102_021E83E4(work);
        if (input < 0) {
            return;
        }
        if (ov102_021E85A8(PTR(work, 0x18), U8(work, 0x6b), (u16)input) == 0) {
            PlaySE(0x5f2);
            return;
        }
        U16(work, 0x50) = input;
    } else {
        input = ov102_021E8458(work);
        if (input < 0) {
            return;
        }
        if (ov102_021E85A8(PTR(work, 0x18), U8(work, 0x6b), (u16)input) == 0) {
            PlaySE(0x5f2);
            return;
        }
        U16(work, 0x50) = input;
    }
    PlaySE(0x5dc);
    ov102_021E874C((u8 *)work + 0x54, work);
    PTR(work, 0x24) = ov102_021E87B4;
    ov102_021E940C(PTR(work, 0x14), 0xb);
    U32(state, 0) = 1;
}
