#include "overlay108_safari_decor_r2_private.h"

BOOL ov108_021E929C(void *p) {
    switch (U32(p, 8)) {
    case 0:
        ov108_021E9850(p);
        ov108_021E9A60(p);
        ov108_021E9C14(p);
        ov108_021E9C3C(p);
        ov108_021E9D30(p);
        ov108_021E9E10(p);
        ov108_021E9EB8(p);
        break;
    case 1:
        ov108_021EA50C(p);
        Main_SetVBlankIntrCB(ov108_021E979C, p);
        sub_020210BC();
        sub_02021148(4);
        U32(p, 8) = 0;
        return TRUE;
    }
    U32(p, 8)
    ++;
    return FALSE;
}

BOOL ov108_021E9304(void *p) {
    switch (U32(p, 8)) {
    case 0:
        Main_SetVBlankIntrCB(0, 0);
        HBlankInterruptDisable();
        ov108_021E9F04(p);
        ov108_021E9E80(p);
        ov108_021E9DE0(p);
        ov108_021E9CD0(p);
        ov108_021E9C2C(p);
        ov108_021E9BD4(p);
        ov108_021E9A08(p);
        break;
    case 2:
        sub_02021238();
        *(volatile u32 *)0x04000000 &= 0xffffe0ff;
        *(volatile u32 *)0x04001000 &= 0xffffe0ff;
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        U32(p, 8) = 0;
        return TRUE;
    }
    U32(p, 8)
    ++;
    return FALSE;
}

int ov108_021E9388(void *p) {
    u32 x = 0;
    int r = ov108_021E96FC(p, &x);
    if (x == 0) {
        r = ov108_021E95AC(p);
    }
    return r;
}

int ov108_021E93A8(void *p) {
    int done = 0;
    if (System_GetTouchNew()) {
        done = 1;
        U32(p, 0x10) = 1;
    } else {
        u32 keys = U32(gSystem, 0x48);
        if (keys & 0xcf3) {
            U32(p, 0x10) = 0;
        }
        keys = U32(gSystem, 0x48);
        if (keys & 3) {
            done = 1;
        }
    }
    if (done) {
        PlaySE(0x5e5);
        ClearFrameAndWindow2((u8 *)p + 0x464, 1);
        ClearWindowTilemapAndScheduleTransfer((u8 *)p + 0x464);
        return 0;
    }
    return 2;
}
