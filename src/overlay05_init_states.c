#include "overlay05_init_states_internal.h"

int ov05_0221BD28(Ov05Work *work) {
    *(volatile u16 *)0x04000050 = 0;
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    *(volatile u16 *)0x04000304 |= 0x8000;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    ov05_0221BB00();
    OV05_PTR(work, 0xC) = BgConfig_Alloc(OV05_U32(OV05_PTR(work, 0), 0x24));
    OV05_PTR(work, 8) = PaletteData_Init(OV05_U32(OV05_PTR(work, 0), 0x24));
    PaletteData_AllocBuffers(OV05_PTR(work, 8), 0, 0x200, OV05_U32(OV05_PTR(work, 0), 0x24));
    BG_SetMaskColor(4, 0);
    OV05_U8(work, 0xB82) = 0;
    OV05_U8(work, 0xB81) = 8;
    OV05_U8(work, 0xB80) = 0;
    switch (OV05_U8(OV05_PTR(work, 0), 0x28)) {
    case 0:
        OV05_PTR(work, 4) = (void *)ov05_0221EAC0;
        break;
    case 1:
        OV05_PTR(work, 4) = (void *)ov05_0221EA98;
        break;
    case 2:
        if (OV05_U8(OV05_PTR(work, 0), 0x2A) == 3) {
            OV05_PTR(work, 4) = (void *)ov05_0221EC28;
        } else {
            OV05_PTR(work, 4) = (void *)ov05_0221EC98;
        }
        break;
    }
    return 1;
}

int ov05_0221BE04(Ov05Work *work) {
    switch (OV05_U8(work, 0xB82)) {
    case 0:
        ov05_0221DB94(work);
        ov05_0221DC60(work);
        break;
    case 1:
        ov05_0221E07C(work);
        ov05_0221E274(work);
        break;
    case 2:
        OV05_U8(work, 0xB82) = 0;
        OV05_U8(work, 0xB81) = 0x20;
        ov05_0221DD08(work);
        ov05_0221E5E4(work);
        ov05_0221E944(work);
        ov05_0221DE38(work);
        sub_0203A880();
        sub_020880CC(0, OV05_U32(OV05_PTR(work, 0), 0x24));
        Main_SetVBlankIntrCB((void (*)(void *))ov05_0221CE88, work);
        return 1;
    }
    OV05_U8(work, 0xB82)
    ++;
    return 0;
}

int ov05_0221BE80(Ov05Work *work) {
    switch (OV05_U8(work, 0xB82)) {
    case 0:
        ov05_0221CEB8(work, 1, 0);
        ov05_0221D094(work);
        ov05_0221D228();
        break;
    case 1:
        ov05_0221D6C4(work, 0, 0);
        ov05_0221D240(work);
        sub_0203A880();
        ov05_0221D9F0(work);
        break;
    case 2:
        sub_020880CC(0, OV05_U32(OV05_PTR(work, 0), 0x24));
        Main_SetVBlankIntrCB((void (*)(void *))ov05_0221CE88, work);
        OV05_U8(work, 0xB82) = 0;
        OV05_U8(work, 0xB7C) = 8;
        OV05_U8(work, 0xB7D) = 4;
        OV05_U32(work, 0xB74) = 0x10;
        return 1;
    }
    OV05_U8(work, 0xB82)
    ++;
    return 0;
}

int ov05_0221BF08(Ov05Work *work) {
    u32 value;
    int i;

    switch (OV05_U8(work, 0xB82)) {
    case 0:
        ov05_0221CEB8(work, 0, 1);
        ov05_0221D094(work);
        ov05_0221D140(work);
        ov05_0221D228();
        sub_0202FD28(OV05_PTR(OV05_PTR(OV05_PTR(work, 0), 0), 0x1C0), OV05_U32(OV05_PTR(work, 0), 0x24), &value, 0);
        OV05_U32(work, 0xBCC) = value;
        OV05_U32(work, 0xBD0) = 0;
        for (i = 0; i < 8; i++) {
            void *profile = (void *)sub_02034818(i);
            if (profile != NULL && PlayerProfile_GetVersion(profile) == 0) {
                OV05_U32(work, 0xBD0) = 1;
                break;
            }
        }
        break;
    case 1:
        ov05_0221D6C4(work, -32, -16);
        ov05_0221D7AC(work);
        sub_0203A880();
        break;
    case 2:
        sub_020880CC(0, OV05_U32(OV05_PTR(work, 0), 0x24));
        Main_SetVBlankIntrCB((void (*)(void *))ov05_0221CE88, work);
        OV05_U8(work, 0xB82) = 0;
        OV05_U8(work, 0xB7C) = 4;
        OV05_U8(work, 0xB7D) = 2;
        OV05_U32(work, 0xB74) = 0xC;
        OV05_PTR(work, 0xBAC) = NewMsgDataFromNarc(0, 0x1B, 0x27E, OV05_U32(OV05_PTR(work, 0), 0x24));
        OV05_PTR(work, 0xBB0) = MessageFormat_New(OV05_U32(OV05_PTR(work, 0), 0x24));
        OV05_PTR(work, 0xBB4) = String_New(0x140, OV05_U32(OV05_PTR(work, 0), 0x24));
        OV05_U32(work, 0xBBC) = 1;
        return 1;
    }
    OV05_U8(work, 0xB82)
    ++;
    return 0;
}
