#include "overlay92_teardown_r2_private.h"

void ov92_0225D1FC(void *state) {
    u8 *resource;
    int i;
    u32 offset;

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GF_DestroyVramTransferManager();
    sub_02021238();
    SetLCRNGSeed(U32AT(state, 0x80));
    ov92_0225E03C(PAT(state, 4));
    ov92_0225DEF0(PAT(state, 4));
    ov92_0225DF40(PAT(state, 4));
    ov92_0225E918(PAT(state, 4));
    ov92_0225E9A8(PAT(state, 4));
    ov92_0225DA2C((u8 *)PAT(state, 4) + 0x114);
    ov92_0225DA2C((u8 *)PAT(state, 4) + 0x320);
    ov92_0225DA2C((u8 *)PAT(state, 4) + 0x52c);
    ov92_0225DA2C((u8 *)PAT(state, 4) + 0x738);
    ov92_0225DA2C((u8 *)PAT(state, 4) + 0x944);
    sub_020180F8((u8 *)PAT(state, 4) + 0x3a8, (u8 *)state + 0x6c);
    sub_020180F8((u8 *)PAT(state, 4) + 0x3bc, (u8 *)state + 0x6c);
    sub_020180F8((u8 *)PAT(state, 4) + 0x3d0, (u8 *)state + 0x6c);
    sub_020180F8((u8 *)PAT(state, 4) + 0x5b4, (u8 *)state + 0x6c);
    sub_020180F8((u8 *)PAT(state, 4) + 0x7c0, (u8 *)state + 0x6c);

    i = 0;
    resource = state;
    offset = i;
    resource += 0x6c;
    for (; i < 8; i++) {
        ov92_0225DA2C((u8 *)PAT(state, 4) + 0xb50 + offset);
        sub_020180F8((u8 *)PAT(state, 4) + 0xbd8 + offset, resource);
        sub_020180F8((u8 *)PAT(state, 4) + 0xbec + offset, resource);
        offset += 0x20c;
    }

    ov90_02258C38(PAT(state, 0x84));
    ov92_0225D49C(state);
    if (ov92_0225D8C4(state) == 1) {
        ov92_0225EB68(PAT(state, 0));
    }
    ov92_0225ED60(PAT(state, 4));
    PAT(state, 0) = NULL;
    PAT(state, 4) = NULL;
}
