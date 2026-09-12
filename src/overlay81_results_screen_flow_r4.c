#include "overlay81_results_screen_r4_private.h"

int ov81_02240008(void *work) {
    switch (OV81_R4_U8(work, 8)) {
    case 0:
        if (ov81_02240FA4(work, 10, (void *)(((u32)OV81_R4_U8(work, 0x13) << 28) >> 31)) == 1) {
            OV81_R4_U8(work, 8)
            ++;
        }
        break;
    case 1:
        if (OV81_R4_U8(work, 0x462) >= 2) {
            OV81_R4_U8(work, 0x462) = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

int ov81_02240048(void *work) {
    switch (OV81_R4_U8(work, 8)) {
    case 0:
        OV81_R4_U8(work, 0x10) = ov81_0224086C(work, 15);
        sub_02037BEC();
        sub_02037AC0(0xA5);
        OV81_R4_U8(work, 8)
        ++;
        break;
    case 1:
        if (sub_02037B38(0xA5) == 1) {
            sub_02037BEC();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

int ov81_02240088(void *work) {
    switch (OV81_R4_U8(work, 8)) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 100);
        OV81_R4_U8(work, 8)
        ++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

int ov81_022400D0(void *work) {
    switch (OV81_R4_U8(work, 8)) {
    case 0:
        if (OV81_R4_PTR(work, 0x37C) != NULL) {
            Delete2dMenu(OV81_R4_PTR(work, 0x17C), 0);
            ov81_022413E0(OV81_R4_PTR(work, 0x174));
            ov81_02242FC8(OV81_R4_PTR(work, 0x37C));
            OV81_R4_PTR(work, 0x37C) = NULL;
        }
        ov80_0222A7CC(OV81_R4_PTR(work, 0x20), 0);
        ov81_022408B8(work, 1, Mon_GetBoxMon(Party_GetMonByIndex(OV81_R4_PTR(work, 0x3C0), *(u16 *)((u8 *)work + 0x3C8) + 2)));
        ov81_022408B8(work, 2, Mon_GetBoxMon(Party_GetMonByIndex(OV81_R4_PTR(work, 0x3C4), *(u16 *)((u8 *)work + 0x3CA))));
        ov81_02243028((u8 *)work + 0xC0, Options_GetFrame(OV81_R4_PTR(work, 0x1B8)));
        OV81_R4_U8(work, 0x10) = ov81_0224080C(work, (u8 *)work + 0xC0, 0x10, 1, 1, Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(OV81_R4_PTR(work, 0x1BC))), 1, 2, 15, 1);
        ScheduleWindowCopyToVram((u8 *)work + 0xC0);
        OV81_R4_U8(work, 0x19) = 0x50;
        OV81_R4_U8(work, 8)
        ++;
        break;
    case 1:
        if (TextPrinterCheckActive(OV81_R4_U8(work, 0x10)) == 0) {
            OV81_R4_U8(work, 0x19) = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void ov81_022401C8(void *work) {
    if (*(u32 *)((u8 *)work + 4) == 0) {
        PokepicManager_HandleLoadImgAndOrPltt(OV81_R4_PTR(work, 0x1A8));
        if (OV81_R4_PTR(work, 0x1A0) != NULL) {
            PaletteData_PushTransparentBuffers(OV81_R4_PTR(work, 0x1A0));
        }
        DoScheduledBgGpuUpdates(OV81_R4_PTR(work, 0x4C));
        GF_RunVramTransferTasks();
        OamManager_ApplyAndResetBuffers();
        {
            vu32 *base = (vu32 *)0x027E0000;
            base[0x3FF8 / 4] |= 1;
        }
    }
}

void ov81_02240210(void) {
    Ov81R4Banks banks = ov81_0224356C;
    GfGfx_SetBanks(&banks);
}
