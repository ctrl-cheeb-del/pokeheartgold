#include "overlay_56_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    u32 v[10];
} BanksConfig;
typedef struct {
    u32 v[4];
} ScreenModes;
typedef struct {
    u32 v[35];
} BgTemplates;
typedef struct {
    u8 padding[0x3ff8];
    volatile u32 irqCheck;
} DtcmLayout;
typedef struct {
    void *bgConfig;
    u32 zero;
    u32 tile;
    u32 palette;
    u8 x;
    u8 y;
    u8 touchMode : 4;
    u8 bgId : 4;
    u8 padding;
} PromptTemplate;
extern const BanksConfig ov56_021E6E58;
extern const u8 ov56_021E6E20[];
extern int (*const ov56_021E6DE4[])(void *);
extern const ScreenModes _021E6DD4;
extern const BgTemplates ov56_021E6E80;

int ov56_021E5C20(OverlayManager *mgr) {
    u8 *data;
    u8 value;
    Heap_Create(3, 0x29, 0x20000);
    data = OverlayManager_CreateAndGetData(mgr, 0xc4, 0x29);
    memset(data, 0, 0xc4);
    U32(data, 0) = 0x29;
    PTR(data, 0x1c) = OverlayManager_GetArgs(mgr);
    U8(data, 0xc) = U16(PTR(data, 0x1c), 0);
    U8(data, 0xd) = U8(data, 0xc);
    U8(data, 0x11) = U8(PTR(data, 0x1c), 2);
    U8(data, 0x12) = U8(PTR(data, 0x1c), 3);
    value = U8(data, 0x11);
    U8(data, 0x16) = value;
    U8(data, 0x17) = value;
    U16(PTR(data, 0x1c), 0) = 0xffff;
    U8(data, 0x10) = Options_GetTextFrameDelay(PTR(PTR(data, 0x1c), 4));
    U8(data, 0xb) = Options_GetFrame(PTR(PTR(data, 0x1c), 4));
    TextFlags_SetCanABSpeedUpPrint(1);
    U8(data, 0xa) = MenuInputStateMgr_GetState(PTR(PTR(data, 0x1c), 8));
    return 1;
}

int ov56_021E5C9C(OverlayManager *mgr) {
    return ov56_021E6228(OverlayManager_GetData(mgr)) != 0;
}

int ov56_021E5CB4(OverlayManager *mgr) {
    u8 *p = OverlayManager_GetData(mgr);
    u32 heap;
    TextFlags_SetCanABSpeedUpPrint(0);
    heap = U32(p, 0);
    MenuInputStateMgr_SetState(PTR(PTR(p, 0x1c), 8), U8(p, 0xa));
    OverlayManager_FreeData(mgr);
    Heap_Destroy(heap);
    return 1;
}

int ov56_021E5CE0(void *data) {
    int i;
    for (i = 0; i < 3; i++) {
        if (MailMsg_IsInit((u8 *)PTR(data, 0x1c) + 0x1e + i * 8)) {
            return 0;
        }
    }
    return 1;
}

void ov56_021E5D08(void *data) {
    PaletteData_BlendPalette(PTR(data, 0x30), 0, (u16)(U8(data, 0x17) + 0x22), 1, 0, 0x7fff);
    U8(data, 0x15) = 0;
    U8(data, 0x14) = 0;
}

int ov56_021E5D34(void *data) {
    ov56_021E5D08(data);
    return 0;
}

int ov56_021E5D40(void) {
    return 0;
}

int ov56_021E5D44(void *data) {
    int (*callback)(void *);
    if (U8(data, 0xa) == 1) {
        if (System_GetTouchHeld()) {
            return 0;
        }
        if (U32(gSystem, 0x44)) {
            callback = (int (*)(void *))PTR(data, 0x34);
            if (callback != 0) {
                callback(data);
            }
            U8(data, 0xa) = 0;
            return 1;
        }
    } else {
        if (U32(gSystem, 0x44)) {
            return 0;
        }
        if (System_GetTouchHeld()) {
            callback = (int (*)(void *))PTR(data, 0x38);
            if (callback != 0) {
                callback(data);
            }
            U8(data, 0xa) = 1;
            return 0;
        }
    }
    return 0;
}

int ov56_021E5DA4(void *data) {
    if (U32(gSystem, 0x48)) {
        U8(data, 0xa) = 0;
    } else if (System_GetTouchHeld()) {
        U8(data, 0xa) = 1;
    } else {
        return 0;
    }
    PlaySE(0x5e3);
    return 1;
}

int ov56_021E5DDC(void *data) {
    u32 keys = U32(gSystem, 0x48);
    int changed = 0;
    if (keys & 1) {
        if (U8(data, 0x11) == 3) {
            if (U8(data, 0x12) == 0) {
                if (ov56_021E5CE0(data)) {
                    PlaySE(0x5dd);
                    U8(data, 0xc) = 2;
                    return 0;
                }
                U16(PTR(data, 0x1c), 0) = 3;
                PlaySE(0x5e3);
                U8(PTR(data, 0x1c), 2) = 0;
                U8(PTR(data, 0x1c), 3) = 0;
                return 1;
            }
            PlaySE(0x5dd);
            U8(data, 0xc) = 3;
            return 0;
        }
        U8(PTR(data, 0x1c), 2) = U8(data, 0x11);
        U16(PTR(data, 0x1c), 0) = U8(PTR(data, 0x1c), 2);
        U8(PTR(data, 0x1c), 3) = U8(data, 0x12);
        PlaySE(0x5dd);
        return 1;
    }
    if (keys & 2) {
        PlaySE(0x5dd);
        U8(data, 0xc) = 3;
        return 0;
    }
    if (keys & 8) {
        U8(data, 0x11) = 3;
        U8(data, 0x12) = 0;
        changed = 1;
    } else if (keys & 0x80) {
        U8(data, 0x11) = (U8(data, 0x11) + 1) % 4;
        changed = 1;
    } else if (keys & 0x40) {
        U8(data, 0x11) = (U8(data, 0x11) + 3) % 4;
        changed = 1;
    } else if (keys & 0x30) {
        if (U8(data, 0x11) == 3) {
            U8(data, 0x12) ^= 1;
            changed = 1;
        }
    } else {
        return 0;
    }
    if (!changed) {
        return 0;
    }
    PlaySE(0x5dc);
    if (U8(data, 0x11) == 3) {
        U8(data, 0x16) = U8(data, 0x11) + U8(data, 0x12);
    } else {
        U8(data, 0x16) = U8(data, 0x11);
    }
    return 0;
}

int ov56_021E5EFC(void *data) {
    int hit;
    u16 pixel;
    hit = TouchscreenHitbox_FindRectAtTouchNew(ov56_021E6E20);
    if (hit == -1) {
        return 0;
    }
    pixel = 1;
    if (DoesPixelAtScreenXYMatchPtrVal(PTR(data, 0x18), 2, U16(gSystem, 0x60), U16(gSystem, 0x62), &pixel) == 1) {
        return 0;
    }
    if (hit == 3) {
        PlaySE(0x5dd);
        U8(data, 0xc) = 3;
        return 0;
    }
    if (hit < 3) {
        U8(PTR(data, 0x1c), 2) = hit;
        U16(PTR(data, 0x1c), 0) = U8(PTR(data, 0x1c), 2);
        U8(PTR(data, 0x1c), 3) = U8(data, 0x12);
        PlaySE(0x5dd);
        return 1;
    }
    if (ov56_021E5CE0(data)) {
        PlaySE(0x5dd);
        U8(data, 0xc) = 2;
        return 0;
    }
    U16(PTR(data, 0x1c), 0) = 3;
    PlaySE(0x5e3);
    U8(PTR(data, 0x1c), 2) = 0;
    U8(PTR(data, 0x1c), 3) = 0;
    return 1;
}

int ov56_021E5FB4(void *data) {
    if (ov56_021E5D44(data)) {
        return 0;
    }
    if (U8(data, 0xa) == 0) {
        return ov56_021E5DDC(data);
    }
    return ov56_021E5EFC(data);
}

int ov56_021E5FDC(void *data) {
    int done = 0;
    void *string = 0;
    switch (U16(data, 8)) {
    case 0:
        DrawFrameAndWindow2((u8 *)data + 0x9c, 1, 10, 6);
        FillWindowPixelBuffer((u8 *)data + 0x9c, 0xff);
        string = String_New(0x4c, U32(data, 0));
        ReadMsgDataIntoString(PTR(data, 0x20), 2, string);
        AddTextPrinterParameterizedWithColor((u8 *)data + 0x9c, 1, string, 0, 0, 0, 0x1020f, 0);
        String_Delete(string);
        break;
    case 1:
        if (U32(gSystem, 0x48) & 3) {
            done = 1;
            U8(data, 0xa) = 0;
        } else if (System_GetTouchNew()) {
            done = 1;
            U8(data, 0xa) = 1;
            ov56_021E5D08(data);
        }
        if (!done) {
            return 0;
        }
        ClearFrameAndWindow2((u8 *)data + 0x9c, 1);
        ClearWindowTilemapAndCopyToVram((u8 *)data + 0x9c);
        U16(data, 8) = 0;
        U8(data, 0xc) = U8(data, 0xd);
        return 0;
    }
    U16(data, 8)
    ++;
    return 0;
}

void ov56_021E609C(void *data) {
    PromptTemplate template;
    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = PTR(data, 0x18);
    template.zero = 0;
    template.tile = 0x1bb;
    template.palette = 3;
    template.x = 0x18;
    template.y = 0xa;
    template.touchMode = U8(data, 0xa);
    template.bgId = 0;
    YesNoPrompt_InitFromTemplateWithPalette(PTR(data, 0xac), &template, PTR(data, 0x30));
}

int ov56_021E60F4(void *data) {
    int result;
    int touch;
    result = YesNoPrompt_HandleInput(PTR(data, 0xac));
    switch (result) {
    case 1:
        result = 1;
        break;
    case 2:
        result = 0;
        break;
    default:
        return -1;
    }
    touch = YesNoPrompt_IsInTouchMode(PTR(data, 0xac));
    if (touch != U8(data, 0xa)) {
        if (U8(data, 0xa) == 0) {
            ((int (*)(void *))PTR(data, 0x34))(data);
        } else {
            ((int (*)(void *))PTR(data, 0x38))(data);
        }
        U8(data, 0xa) = touch;
    }
    YesNoPrompt_Reset(PTR(data, 0xac));
    return result;
}

int ov56_021E614C(void *data) {
    void *string;
    int answer;
    switch (U16(data, 8)) {
    case 0:
        U8(data, 0x13) = 1;
        DrawFrameAndWindow2((u8 *)data + 0x9c, 1, 10, 6);
        FillWindowPixelBuffer((u8 *)data + 0x9c, 0xff);
        string = String_New(0x4c, U32(data, 0));
        ReadMsgDataIntoString(PTR(data, 0x20), 3, string);
        U8(data, 0xf) = AddTextPrinterParameterizedWithColor((u8 *)data + 0x9c, 1, string, 0, 0, U8(data, 0x10), 0x1020f, 0);
        String_Delete(string);
        ov56_021E5D08(data);
        U8(data, 0x17) = U8(data, 0x16);
        break;
    case 1:
        if (TextPrinterCheckActive(U8(data, 0xf))) {
            return 0;
        }
        ov56_021E609C(data);
        break;
    case 2:
        answer = ov56_021E60F4(data);
        if (answer < 0) {
            return 0;
        }
        ClearFrameAndWindow2((u8 *)data + 0x9c, 1);
        ClearWindowTilemapAndCopyToVram((u8 *)data + 0x9c);
        U16(data, 8) = 0;
        if (answer != 0) {
            U16(PTR(data, 0x1c), 0) = 0xffff;
            return 1;
        }
        U8(data, 0xc) = U8(data, 0xd);
        U8(data, 0x13) = 0;
        return 0;
    }
    U16(data, 8)
    ++;
    return 0;
}

int ov56_021E6228(void *data) {
    switch (U32(data, 4)) {
    case 0:
        Main_SetVBlankIntrCB(0, 0);
        HBlankInterruptDisable();
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(volatile u32 *)0x04000000 &= 0xffffe0ff;
        *(volatile u32 *)0x04001000 &= 0xffffe0ff;
        sub_0200FBF4(0, 0);
        sub_0200FBF4(1, 0);
        ResetVisibleHardwareWindows(0);
        ResetVisibleHardwareWindows(1);
        break;
    case 1:
        if (!ov56_021E647C(data)) {
            return 0;
        }
        Main_SetVBlankIntrCB(ov56_021E63C0, data);
        GfGfx_EngineATogglePlanes(0x10, 1);
        SetMasterBrightnessNeutral(0);
        G2x_SetBlendAlpha_(0x04000050, 4, 8, 0x1c, 4);
        PaletteData_BeginPaletteFade(PTR(data, 0x30), 5, 0xffff, -1, 0x10, 0, 0);
        break;
    case 2:
        if (PTR(data, 0xb4) != 0) {
            SpriteSystem_DrawSprites(PTR(data, 0xb4));
        }
        if (PaletteData_GetSelectedBuffersBitmask(PTR(data, 0x30)) != 0) {
            return 0;
        }
        break;
    case 3:
        if (PTR(data, 0xb4) != 0) {
            SpriteSystem_DrawSprites(PTR(data, 0xb4));
        }
        if (!ov56_021E6DE4[U8(data, 0xc)](data)) {
            return 0;
        }
        PaletteData_BeginPaletteFade(PTR(data, 0x30), 5, 0xffff, -1, 0, 0x10, 0);
        break;
    case 4:
        if (PaletteData_GetSelectedBuffersBitmask(PTR(data, 0x30)) != 0) {
            if (PTR(data, 0xb4) != 0) {
                SpriteSystem_DrawSprites(PTR(data, 0xb4));
            }
            return 0;
        }
        sub_0200FBF4(0, 0);
        sub_0200FBF4(1, 0);
        Main_SetVBlankIntrCB(0, 0);
        GfGfx_DisableEngineAPlanes();
        GfGfx_DisableEngineBPlanes();
        *(volatile u32 *)0x04000000 &= 0xffffe0ff;
        *(volatile u32 *)0x04001000 &= 0xffffe0ff;
        break;
    case 5:
        if (ov56_021E64C8(data)) {
            return 1;
        }
        return 0;
    }
    U32(data, 4)
    ++;
    return 0;
}

void ov56_021E63C0(void *data) {
    if (PTR(data, 0x30) != 0) {
        PaletteData_PushTransparentBuffers(PTR(data, 0x30));
    }
    if (PTR(data, 0xb0) != 0) {
        SpriteSystem_TransferOam(PTR(data, 0xb0));
    }
    NNS_GfdDoVramTransfer();
    DoScheduledBgGpuUpdates(PTR(data, 0x18));
    *(u32 *)((u8 *)OS_IRQTable + 0x3ff8) |= 1;
}

void ov56_021E63FC(void *task, void *data) {
    u8 old;
    if (PTR(data, 0x30) == 0) {
        SysTask_Destroy(task);
        return;
    }
    if (U8(data, 0x13) != 0) {
        return;
    }
    if (U8(data, 0xa) == 1) {
        return;
    }
    if (U8(data, 0x17) != U8(data, 0x16)) {
        ov56_021E5D08(data);
        U8(data, 0x17) = U8(data, 0x16);
    }
    PaletteData_BlendPalette(PTR(data, 0x30), 0, (u16)(U8(data, 0x16) + 0x22), 1, U8(data, 0x14), 0x7fff);
    old = U8(data, 0x14);
    if (U8(data, 0x15)) {
        U8(data, 0x14) = old - 1;
        if (old == 1) {
            U8(data, 0x15) ^= 1;
            return;
        }
    } else {
        U8(data, 0x14) = old + 1;
        if (old == 0xc) {
            U8(data, 0x15) ^= 1;
        }
    }
}

int ov56_021E647C(void *data) {
    switch (U16(data, 8)) {
    case 0:
        ov56_021E6514(data);
        break;
    case 1:
        ov56_021E6650(data);
        break;
    case 2:
        ov56_021E696C(data);
        ov56_021E6AA4(data);
        break;
    case 3:
        ov56_021E6BB4(data);
        U16(data, 8) = 0;
        return 1;
    }
    U16(data, 8)
    ++;
    return 0;
}

int ov56_021E64C8(void *data) {
    void *window;
    ov56_021E6D90(data);
    window = (u8 *)data + 0x24;
    if (window != 0) {
        DestroyMsgData(PTR(data, 0x20));
    }
    ov56_021E6A7C(data);
    ov56_021E692C(data);
    ov56_021E660C(data);
    return 1;
}

void ov56_021E64F4(void) {
    BanksConfig cfg = ov56_021E6E58;
    GfGfx_SetBanks(&cfg);
}

void ov56_021E6514(void *data) {
    ScreenModes modes;
    BgTemplates templates;
    ov56_021E64F4();
    PTR(data, 0x18) = BgConfig_Alloc(U32(data, 0));
    modes = _021E6DD4;
    SetBothScreensModesAndDisable(&modes);
    *(volatile u16 *)0x04000304 &= ~0x8000;
    templates = ov56_021E6E80;
    InitBgFromTemplate(PTR(data, 0x18), 0, &templates.v[0], 0);
    InitBgFromTemplate(PTR(data, 0x18), 1, &templates.v[7], 0);
    InitBgFromTemplate(PTR(data, 0x18), 2, &templates.v[14], 0);
    InitBgFromTemplate(PTR(data, 0x18), 3, &templates.v[21], 0);
    InitBgFromTemplate(PTR(data, 0x18), 4, &templates.v[28], 0);
    BgClearTilemapBufferAndCommit(PTR(data, 0x18), 0);
    BgClearTilemapBufferAndCommit(PTR(data, 0x18), 1);
    BgClearTilemapBufferAndCommit(PTR(data, 0x18), 2);
    BgClearTilemapBufferAndCommit(PTR(data, 0x18), 3);
    BgClearTilemapBufferAndCommit(PTR(data, 0x18), 4);
    BG_ClearCharDataRange(0, 0x20, 0, U32(data, 0));
    BG_ClearCharDataRange(1, 0x20, 0, U32(data, 0));
    BG_ClearCharDataRange(2, 0x20, 0, U32(data, 0));
    BG_ClearCharDataRange(3, 0x20, 0, U32(data, 0));
    BG_ClearCharDataRange(4, 0x20, 0, U32(data, 0));
}

void ov56_021E660C(void *data) {
    FreeBgTilemapBuffer(PTR(data, 0x18), 4);
    FreeBgTilemapBuffer(PTR(data, 0x18), 3);
    FreeBgTilemapBuffer(PTR(data, 0x18), 2);
    FreeBgTilemapBuffer(PTR(data, 0x18), 1);
    FreeBgTilemapBuffer(PTR(data, 0x18), 0);
    *(volatile u16 *)0x04000304 |= 0x8000;
    Heap_Free(PTR(data, 0x18));
}
