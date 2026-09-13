#include "r40_overlay_73_residual_9_residual_4_private.h"

void ov73_021E705C(void *p, int state, int player) {
    switch (state) {
    case 2:
        ov73_021E761C(p);
        break;
    case 13:
        ov73_021E6830(p);
        break;
    case 25:
        if (!ov73_021E75FC(U32(p, 0x4C))) {
            RemoveTextPrinter((u8)U32(p, 0x4C));
        }
        ov73_021E71E4(p, 1, 2);
        ScheduleBgTilemapBufferTransfer(PTR(p, 0), 1);
        ov73_021E756C(p, 12, 0);
        ov73_021E6830(p);
        break;
    case 19:
        if (U8(p, 0x4A28) == 1) {
            return;
        }
        BufferPlayersName(PTR(p, 0x24), 0, sub_02034818(player));
        if (player == sub_0203769C()) {
            return;
        }
        ov73_021E6830(p);
        if (sub_0203769C() == 0) {
            U32(p, 0x4A24) &= player ^ 0xFFFF;
        }
        break;
    case 7:
    case 8:
        break;
    default:
        return;
    }
    U32(p, 0x318) = state;
}

void ov73_021E7120(void *p, int state, int player) {
    if (U32(p, 0x318) == 3) {
        switch (state) {
        case 1: {
            u32 one;
            BufferPlayersName(PTR(p, 0x24), 0, sub_02034818(player));
            ov73_021E781C(p, 1);
            U32(p, 0x318) = state;
            U32(p, 0x4A1C) = sub_02037454();
            U32(p, 0x4A24) = 0;
            if (sub_0203769C() == 0) {
                one = 1;
                sub_02037030(0x75, &one, one);
            }
            return;
        }
        case 19:
            BufferPlayersName(PTR(p, 0x24), 0, sub_02034818(player));
            if (player == sub_0203769C()) {
                return;
            }
            if (sub_0203769C() == 0) {
                U32(p, 0x4A24) &= player ^ 0xFFFF;
            }
            U32(p, 0x318) = state;
            return;
        default:
            GF_AssertFail();
            return;
        }
    }
    if (state == 1) {
        U32(p, 0x4A24) = 0;
        U32(p, 0x4A1C) = sub_02037454();
    }
}

void ov73_021E71E4(void *p, int index, int value) {
    u8 *q = PTR(p, 0x30C);
    CopyToBgTilemapRect(PTR(p, 0), 1, _021EA51C[index], 0x14, 8, 4, q + 0xC, 0, ((u32)value << 26) >> 24, ((u32)U16(q, 0) << 21) >> 24, ((u32)U16(q, 2) << 21) >> 24);
}
