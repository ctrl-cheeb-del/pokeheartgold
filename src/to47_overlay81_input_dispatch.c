#include "to47_overlay81_input_dispatch_private.h"

extern u16 ov81_0224345C[];
extern u16 ov81_0224345E[];
extern u16 ov81_02243464[];
extern u16 ov81_02243466[];
extern u16 ov81_02243470[];
extern u16 ov81_02243472[];
extern u16 ov81_02243490[];
extern u16 ov81_02243492[];

void ov81_02241238(int value, int unused, Ov81InputRecord *input, void *work) {
#pragma unused(unused)
    U8_AT(work, 0x462)
    ++;
    if (value != sub_0203769C()) {
        U16_AT(work, 0x458) = (u8)input->unk2;
        if (sub_0203769C() == 0) {
            if (((u32)U8_AT(work, 0x13) << 28) >> 31 == 1) {
                U16_AT(work, 0x458) = 0;
                return;
            }
            if (U16_AT(work, 0x458) == 1) {
                U16_AT(work, 0x3C8) = (u8)input->unk4;
                U16_AT(work, 0x3CA) = (u8)input->unk6;
            }
        } else if (U16_AT(work, 0x458) == 1) {
            U8_AT(work, 0x13) &= ~8;
            U16_AT(work, 0x3C8) = (u8)input->unk4;
            U16_AT(work, 0x3CA) = (u8)input->unk6;
        }
    }
}

void ov81_022412C4(void *work, int index) {
    u16 x;
    u16 y;

    if (ov81_02240F08(work, 0) == 1) {
        x = ov81_02243490[index * 2];
        y = ov81_02243492[index * 2];
    } else if (ov80_02237254(U8_AT(work, 9)) == 0) {
        x = ov81_02243464[index * 2];
        y = ov81_02243466[index * 2];
    } else if (U8_AT(work, 0x12) == 2) {
        x = ov81_0224345C[index * 2];
        y = ov81_0224345E[index * 2];
    } else {
        x = ov81_02243470[index * 2];
        y = ov81_02243472[index * 2];
    }
    ov81_02242E50((u8 *)work + 0x1C4, x, y, 0x64);
}

void ov81_02241340(void *work, int value) {
    ov81_02242CBC((u8 *)work + 0x1C4, 1, value, 2, 10, 0x80, 0x7C);
}

void ov81_02241364(void *work) {
    if (PTR_AT(work, 0x380) != NULL) {
        ov81_02242D74(PTR_AT(work, 0x380));
        PTR_AT(work, 0x380) = NULL;
    }
    if (PTR_AT(work, 0x384) != NULL) {
        ov81_02242D74(PTR_AT(work, 0x384));
        PTR_AT(work, 0x384) = NULL;
    }
}

void ov81_02241398(void *work) {
    SetBgPriority(1, 1);
    BG_ClearCharDataRange(1, 0x20, 0, 0x64);
    BgClearTilemapBufferAndCommit(PTR_AT(work, 0x4C), 1);
    ov81_02242FDC(PTR_AT(work, 0x4C), (u8 *)work + 0x50);
    if (U32_AT(work, 0x47C) == 2) {
        ov81_022430E8((u8 *)work + 0x70);
    }
    GfGfx_EngineATogglePlanes(2, 1);
}
