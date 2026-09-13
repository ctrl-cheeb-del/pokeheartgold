#include "r40_overlay_43_residual_2_private.h"
#define PTR(p, o)   ((u8 *)(p) + (o))
#define LOADP(p, o) (*(void **)((u8 *)(p) + (o)))

void ov43_0222A154(void *p, int arg) {
    ov43_0222A48C(PTR(p, 4), PTR(p, 0x214), arg);
    ov43_0222B0A0(PTR(p, 0x280), PTR(p, 0x214), PTR(p, 4), arg);
    ov43_0222B944(PTR(p, 0x2C0), PTR(p, 0x214), PTR(p, 4), arg);
    ov43_0222CD3C(PTR(p, 0x3C0), PTR(p, 0x214), PTR(p, 4), arg);
    ov43_0222CE48(PTR(p, 0x3CC), PTR(p, 0x214), PTR(p, 4), arg);
    ov43_0222D584(PTR(p, 0x408), PTR(p, 0x214), PTR(p, 4), arg);
    Main_SetVBlankIntrCB(ov43_0222A148, p);
    HBlankInterruptDisable();
}

void ov43_0222A1DC(void *p) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    ov43_0222B1D8(PTR(p, 0x280), PTR(p, 0x214), PTR(p, 4));
    ov43_0222BAB8(PTR(p, 0x2C0), PTR(p, 0x214), PTR(p, 4));
    ov43_0222CD40(PTR(p, 0x3C0), PTR(p, 0x214), PTR(p, 4));
    ov43_0222D008(PTR(p, 0x3CC), PTR(p, 0x214), PTR(p, 4));
    ov43_0222D610(PTR(p, 0x408), PTR(p, 0x214), PTR(p, 4));
    ov43_0222A520(PTR(p, 4));
}

void ov43_0222A24C(void *bg, void *win, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7, u16 a8, u8 fill) {
    InitWindow(win);
    AddWindowParameterized(bg, win, a2, a3, a4, a5, a6, a7, a8);
    FillWindowPixelBuffer(win, fill);
}

void ov43_0222A290(void *p, void *args, int heap) {
    LOADP(p, 4) = LOADP(args, 0);
    LOADP(p, 0x58) = String_New(0x80, heap);
    LOADP(p, 0x5C) = String_New(0x80, heap);
    *(u32 *)p = MenuInputStateMgr_GetState(LOADP(args, 4));
    void *opt = Save_PlayerData_GetOptionsAddr(LOADP(p, 4));
    *(u8 *)PTR(p, 0xC) = Options_GetTextFrameDelay(opt);
    *(u8 *)PTR(p, 0xD) = Options_GetFrame(opt);
    *(u8 *)PTR(p, 0xE) = Options_GetButtonMode(opt) == 1 ? 0 : 1;
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
}
