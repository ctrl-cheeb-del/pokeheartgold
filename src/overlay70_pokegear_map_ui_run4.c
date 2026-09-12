#include "overlay70_pokegear_map_ui_private.h"

#define OV70_STATE (*(u32 *)_02246800)
#define OV70_ERR   (*(s32 *)(_02246800 + 4))

#define OV70_FAIL()    \
    OV70_STATE = 0x18; \
    OV70_ERR = -13;    \
    ov38_0221BFEC()

void ov70_02237F64(void *a);
void ov70_02237FB4(void);
void ov70_02238008(void *b);
void ov70_02238058(void *b);
void ov70_022380A8(void);
void ov70_022380EC(void);
void ov70_02238130(void *src, int n, void *c);
void ov70_022381A4(void *src, void *c);
void ov70_02238208(void *a, void *b, void *c);
void ov70_0223826C(void);
int ov70_022385C0(void *ovy, u32 *state);
int ov70_022386F4(void *ovy);
void ov70_022387AC(u8 *work);
void ov70_022387F8(void);
void ov70_02238818(u8 *work, void *ovy);

void ov70_022382C0(void) {
    ov38_0221BE84();
    if (ov70_02238360(ov70_02246358, ov70_02246814, 0, ov70_0224693C, 2)) {
        OV70_STATE = 0x14;
    } else {
        OV70_FAIL();
    }
}

void ov70_02238304(void *a, void *b) {
    OS_GetMacAddress((u8 *)a + 0x1c);
    memcpy(ov70_02246814, a, 0x64);
    *(void **)(ov70_02246900 + 0x40) = b;
    ov38_0221BE84();
    if (ov70_02238360(ov70_022463A4, ov70_02246814, 0x64, *(void **)(ov70_02246900 + 0x40), 8)) {
        OV70_STATE = 0x16;
    } else {
        OV70_FAIL();
    }
}

int ov70_02238360(void *a, void *b, int c, void *d, int e) {
    int r = ov38_0221BEA8(a, *(void **)(_02246800 + 8), b, c, d, e);
    switch (r) {
    case 0:
        return 1;
    case 1:
        break;
    case 2:
        break;
    }
    return 0;
}

int ov70_02238398(int x) {
    int r;

    switch (x) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
    case 14:
    case 20:
    case 21:
    case 22:
    case 23:
    case 32:
        r = -13;
        break;
    case 2:
    case 8:
    case 25:
        r = -13;
        break;
    case 11:
        r = -15;
        break;
    case 12:
    case 13:
        r = -15;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 26:
    case 27:
    case 28:
    case 29:
    case 31:
        r = -2;
        break;
    case 15:
    case 30:
        r = -2;
        break;
    default:
        r = -13;
        break;
    }
    if (r != -13) {
        if (WCM_GetPhase() != 9) {
            r = -14;
        }
        ov00_021EC210();
    }
    return r;
}

int ov70_02238430(void *ovy, u32 *state) {
    Ov70Modes modes;
    u8 *work;

    switch (*state) {
    case 0:
        Main_SetVBlankIntrCB(NULL, NULL);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(u32 *)0x04000000 &= 0xFFFFE0FF;
        *(u32 *)0x04001000 &= 0xFFFFE0FF;
        ov70_02238880();
        Heap_Create(3, 0x3d, 0x70000);
        LoadDwcOverlay();
        LoadOVY38();
        sub_02039FD8(0x3d);
        work = OverlayManager_CreateAndGetData(ovy, 0x1608, 0x3d);
        memset(work, 0, 0x1608);
        *(void **)(work + 4) = BgConfig_Alloc(0x3d);
        *(void **)(ov70_02246944 + 4) = work;
        modes = ov70_022451F8;
        SetBothScreensModesAndDisable(&modes);
        FontID_Alloc(4, 0x3d);
        *(void **)(work + 0xb9c) = MessageFormat_New_Custom(0xb, 0x40, 0x3d);
        *(void **)(work + 0xba0) = NewMsgDataFromNarc(0, 0x1b, 0x307, 0x3d);
        *(void **)(work + 0xba8) = NewMsgDataFromNarc(0, 0x1b, 0x30a, 0x3d);
        *(void **)(work + 0xbac) = NewMsgDataFromNarc(0, 0x1b, 0x320, 0x3d);
        *(void **)(work + 0xba4) = NewMsgDataFromNarc(0, 0x1b, 0xed, 0x3d);
        *(void **)(work + 0xbb0) = NewMsgDataFromNarc(0, 0x1b, 0x31e, 0x3d);
        SetKeyRepeatTimers(4, 8);
        ov70_02238818(work, ovy);
        ov70_02238E70(work);
        Sound_SetSceneAndPlayBGM(0xb, 0x47d, 1);
        *(void **)(work + 0x4c) = Heap_Alloc(0x3d, 0x20020);
        *(void **)(work + 0x50) = NNS_FndCreateExpHeapEx(
            (void *)(((u32) * (u8 **)(work + 0x4c) + 0x1f) & ~0x1f), 0x20000, 0);
        *state = 1;
        break;
    case 1:
        sub_02034D8C();
        TextFlags_SetCanTouchSpeedUpPrint(1);
        *state = 0;
        return 1;
    }
    return 0;
}
