#include "to47_overlay71_trade_sequence_tail_r2_private.h"

BOOL TradeSequence_Main(OverlayManager *manager, int *state) {
    u8 *data = OverlayManager_GetData(manager);

    if (*(u32 *)(data + 4) < 7) {
        if (*(u32 *)(*(u8 **)data + 0x10) & ov71_0224BBF8[*(u32 *)(data + 4) * 4]) {
            if (*(void **)(data + 0x154) == NULL) {
                *(void **)(data + 0x154) = ov71_0224BBEC[*(u32 *)(data + 4) * 4](data);
            }
            if (ov71_0224BBF0[*(u32 *)(data + 4) * 4](*(void **)(data + 0x154), state)) {
                ov71_0224BBF4[*(u32 *)(data + 4) * 4](*(void **)(data + 0x154));
                *(void **)(data + 0x154) = NULL;
                (*(u32 *)(data + 4))++;
                *state = 0;
            }
        } else {
            *(u32 *)(data + 4) = *(u32 *)(data + 4) + 1;
            *state = 0;
        }
        ov71_022473F0();
        return FALSE;
    }
    return TRUE;
}

void ov71_02246C48(void *unused, void *data) {
    vu32 *base = (vu32 *)0x027E0000;

    SpriteList_RenderAndAnimateSprites(*(SpriteList **)((u8 *)data + 0x18));
    OamManager_ApplyAndResetBuffers();
    base[0x3FF8 / sizeof(u32)] |= 1;
}

Ov71Sys *ov71_02246C6C(u32 *a0, void *a1) {
    NNSG2dPaletteData *plttData;
    void *pltt;
    int i;
    Ov71Sys *sys = Heap_Alloc(HEAP_ID_56, sizeof(Ov71Sys));

    *a0 = 0;
    if (sys != NULL) {
        pltt = GfGfxLoader_GetPlttData(NARC_a_0_8_9, 6, &plttData, HEAP_ID_56);
        if (pltt != NULL) {
            MI_CpuClear16(sys, 0x60);
            Heap_Free(pltt);
        }
        sys->unk_0EC = 0;
        sys->unk_0E8 = 0;
        sys->unk_0F0 = 0;
        sys->unk_0F4 = 0;
        sys->unk_0E4 = a0;
        sys->unk_0F8 = 0;
        sys->unk_0FC = a1;
        for (i = 0; i < 8; i++) {
            sys->tasks[i] = NULL;
        }
        G2x_SetBlendAlpha_(0x04000050, 4, 0xC, 0x10, 8);
        G2x_SetBlendAlpha_(0x04001050, 4, 0xC, 0x10, 8);
        sys->unk_0C0 = SysTask_CreateOnVWaitQueue(ov71_02246D9C, sys, 0x14);
        if (sys->unk_0C0 != NULL) {
            *sys->unk_0E4 = 1;
        }
    }
    return sys;
}
