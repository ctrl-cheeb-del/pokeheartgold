#include "r40_overlay_40_tail_r21_private.h"

void ov40_0222BD04(void *p) {
    volatile u32 *base = (volatile u32 *)0x027E0000;
    GF_RunVramTransferTasks();
    PaletteData_PushTransparentBuffers(PTR(p, 0x28));
    DoScheduledBgGpuUpdates(PTR(p, 0x24));
    base[0x3FF8 / 4] |= 1;
}

int ov40_0222BD30(void *p, void *state) {
    int result;
    switch (U32(state, 0)) {
    case 0:
        result = ov40_022450F0[U32(p, 4)](p);
        ov40_0222BF64(p, 1, result, state);
        if (result == 0) {
            break;
        }
        if (U32(p, 0x44) == 1) {
            ov40_0222BF80(p, 0);
        } else {
            ov40_0222BF80(p, 1);
        }
        break;
    case 1:
        result = ov40_02245108[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 2:
        result = ov40_02245140[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 3:
        result = ov40_02245168[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 4:
        result = ov40_02245220[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 5:
        result = ov40_02245238[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 6:
        result = ov40_0224533C[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 7:
        result = ov40_02245368[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 8:
    case 9:
        result = ov40_02245470[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 10:
    case 11:
        result = ov40_022455F4[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 12:
        result = ov40_022455F4[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 13:
        result = ov40_02245B98[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 14:
        result = ov40_02245B44[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 15:
        result = ov40_02245B30[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 16:
        ov40_0222BF64(p, 0xFF, 1, state);
        break;
    case 17:
        result = ov40_02245CA8[U32(p, 4)](p);
        ov40_0222BF64(p, 0x10, result, state);
        break;
    case 18:
        ov40_02230D20(p);
        break;
    default:
        return 1;
    }
    Thunk_G3X_Reset();
    PokepicManager_DrawAll(PTR(p, 0x64));
    RequestSwap3DBuffers(1, 0);
    ov40_0223D5E8(p);
    return 0;
}
