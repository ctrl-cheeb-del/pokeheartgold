#include "global.h"

typedef struct Ov86Args {
    void *saveData;
    u8 unk4;
    u8 unk5;
    u16 unk6;
} Ov86Args;

typedef struct Ov86App {
    void *man;         // 0x000
    u8 state;          // 0x004
    u8 unk5;           // 0x005
    u8 unk6;           // 0x006
    u8 unk7;           // 0x007
    u16 unk8;          // 0x008
    u16 unkA;          // 0x00A
    void *bgConfig;    // 0x00C
    u8 windows[0x200]; // 0x010
    void *msgData;     // 0x210
    void *msgFmt;      // 0x214
    void *str;         // 0x218
    void *plttData;    // 0x21C
    void *options;     // 0x220
    void *saveData;    // 0x224
    void *frontier;    // 0x228
    u8 unk22C[4];      // 0x22C
    void *spriteMan;   // 0x230
    void *sprites[2];  // 0x234
    u8 unk23C[0x158];  // 0x23C
} Ov86App;             // size 0x394

extern const u8 _021E7E98[];

typedef void (*Ov86IntrCB)(void *);

typedef struct Ov86System {
    u8 pad[0x48];
    int newKeys;
} Ov86System;

extern Ov86System gSystem;

extern void Main_SetVBlankIntrCB(Ov86IntrCB cb, void *arg);
extern BOOL Main_SetHBlankIntrCB(Ov86IntrCB cb, void *arg);

extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void Heap_Create(int parent, int child, u32 size);
extern void Heap_Destroy(u32 heapId);
extern void *OverlayManager_CreateAndGetData(void *man, u32 size, u32 heapId);
extern void *OverlayManager_GetArgs(void *man);
extern void *OverlayManager_GetData(void *man);
extern void OverlayManager_FreeData(void *man);
extern void *BgConfig_Alloc(u32 heapId);
extern void *Save_Frontier_GetStatic(void *saveData);
extern void *Save_PlayerData_GetOptionsAddr(void *saveData);
extern void FontID_Alloc(u32 fontId, u32 heapId);
extern void FontID_Release(u32 fontId);
extern void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
extern void *MessageFormat_New(u32 heapId);
extern void MessageFormat_Delete(void *fmt);
extern void *String_New(u32 size, u32 heapId);
extern void String_Delete(void *str);
extern void DestroyMsgData(void *msgData);
extern void LoadFontPal0(u32 location, u32 offset, u32 heapId);
extern void LoadFontPal1(u32 location, u32 offset, u32 heapId);
extern void BeginNormalPaletteFade(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heapId);
extern BOOL IsPaletteFadeFinished(void);
extern void PaletteData_FreeBuffers(void *plttData, u32 which);
extern void PaletteData_Free(void *plttData);
extern void PaletteData_PushTransparentBuffers(void *plttData);
extern void DoScheduledBgGpuUpdates(void *bgConfig);
extern void SpriteSystem_TransferOam(void);
extern void SpriteSystem_DrawSprites(void *spriteMan);
extern BOOL TouchscreenHitbox_TouchNewIsIn(const void *hitbox);
extern void PlaySE(u32 seq);

extern void ov86_021E5E0C(Ov86App *app);
extern void ov86_021E5E54(void *bgConfig);
extern void ov86_021E5E90(Ov86App *app, int *state, u32 next);
extern u32 ov86_021E5E98(u32 kind);
extern void ov86_021E60B8(Ov86App *app);
extern void ov86_021E6E30(Ov86App *app);
extern void ov86_021E6E98(Ov86App *app);
extern void ov86_021E6FF4(Ov86App *app);
extern void ov86_021E703C(Ov86App *app);
extern void ov86_021E71C0(Ov86App *app);
extern BOOL ov86_021E71FC(Ov86App *app);
extern void ov86_021E720C(Ov86App *app);
extern void ov86_021E7258(Ov86App *app, u32 a1);
extern u8 ov86_021E7094(Ov86App *app);
extern u8 ov86_021E7710(Ov86App *app);
extern u8 ov86_021E7984(Ov86App *app);
extern u8 ov86_021E7B54(Ov86App *app);
extern void ov86_021E7DF8(void *bgConfig, void *windows, u32 kind);
extern void ov86_021E7E40(void *windows, u32 kind);
extern void ov86_021E7E68(void *bgConfig, void *window);
extern void ov86_021E7E90(void *window);

BOOL ov86_021E5900(void *man, int *state);
BOOL ov86_021E5A40(void *man, int *state);
BOOL ov86_021E5AA4(void *man, int *state);
BOOL ov86_021E5B38(Ov86App *app);
BOOL ov86_021E5BA0(Ov86App *app);
BOOL ov86_021E5C94(Ov86App *app);
void ov86_021E5CDC(void *cbArg);

BOOL ov86_021E5900(void *man, int *state) {
    Ov86App *app;
    Ov86Args *args;

    Main_SetVBlankIntrCB(NULL, NULL);
    Main_SetHBlankIntrCB(NULL, NULL);
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    reg_GX_POWCNT &= 0xFFFF7FFF;
    Heap_Create(3, 0x79, 0x30000);
    app = OverlayManager_CreateAndGetData(man, sizeof(Ov86App), 0x79);
    memset(app, 0, sizeof(Ov86App));
    app->man = man;
    app->bgConfig = BgConfig_Alloc(0x79);
    args = OverlayManager_GetArgs(man);
    app->saveData = args->saveData;
    app->frontier = Save_Frontier_GetStatic(app->saveData);
    app->unk6 = args->unk4;
    app->unk7 = args->unk5;
    app->unk8 = args->unk6;
    app->options = Save_PlayerData_GetOptionsAddr(app->saveData);
    FontID_Alloc(4, 0x79);
    ov86_021E5E0C(app);
    app->msgData = NewMsgDataFromNarc(1, 0x1B, 0x13, 0x79);
    app->msgFmt = MessageFormat_New(0x79);
    app->str = String_New(0x320, 0x79);
    LoadFontPal0(0, 0x1A0, 0x79);
    LoadFontPal1(0, 0x180, 0x79);
    ov86_021E7DF8(app->bgConfig, app->windows, ov86_021E5E98(app->unk7));
    ov86_021E7E68(app->bgConfig, app->unk23C);
    ov86_021E6E30(app);
    ov86_021E6E98(app);
    Main_SetVBlankIntrCB(ov86_021E5CDC, app);
    *state = 0;
    return TRUE;
}

BOOL ov86_021E5A40(void *man, int *state) {
    Ov86App *app = OverlayManager_GetData(man);

    switch (*state) {
    case 0:
        if (ov86_021E5B38(app) == TRUE) {
            ov86_021E5E90(app, state, 1);
        }
        break;
    case 1:
        if (ov86_021E5BA0(app) == TRUE) {
            ov86_021E5E90(app, state, 2);
        }
        break;
    case 2:
        if (ov86_021E5C94(app) == TRUE) {
            return TRUE;
        }
        break;
    }
    ov86_021E703C(app);
    SpriteSystem_DrawSprites(app->spriteMan);
    return FALSE;
}

BOOL ov86_021E5AA4(void *man, int *state) {
#pragma unused(state)
    Ov86App *app = OverlayManager_GetData(man);

    ov86_021E6FF4(app);
    PaletteData_FreeBuffers(app->plttData, 2);
    PaletteData_FreeBuffers(app->plttData, 0);
    PaletteData_Free(app->plttData);
    app->plttData = NULL;
    DestroyMsgData(app->msgData);
    MessageFormat_Delete(app->msgFmt);
    String_Delete(app->str);
    ov86_021E7E90(app->unk23C);
    ov86_021E7E40(app->windows, ov86_021E5E98(app->unk7));
    ov86_021E5E54(app->bgConfig);
    FontID_Release(4);
    OverlayManager_FreeData(man);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(0x79);
    return TRUE;
}

BOOL ov86_021E5B38(Ov86App *app) {
    switch (app->state) {
    case 0:
        if (ov86_021E71FC(app) == TRUE) {
            ov86_021E720C(app);
        } else {
            ov86_021E60B8(app);
        }
        app->state++;
        break;
    case 1:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 3, 0x79);
        app->state++;
        break;
    case 2:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov86_021E5BA0(Ov86App *app) {
    switch (app->state) {
    case 0:
        if (ov86_021E71FC(app) == TRUE) {
            app->state = 3;
        } else {
            app->state = 1;
        }
        break;
    case 1:
        if (TouchscreenHitbox_TouchNewIsIn(_021E7E98) == TRUE || (gSystem.newKeys & 3)) {
            PlaySE(0x5DD);
            ov86_021E71C0(app);
            app->unk5 = 10;
            app->state = 9;
        }
        break;
    case 2:
        ov86_021E7258(app, 1);
        app->state = 3;
        break;
    case 3:
        app->state = ov86_021E7710(app);
        break;
    case 4:
        ov86_021E7258(app, 2);
        app->state = 5;
        break;
    case 5:
        app->state = ov86_021E7984(app);
        break;
    case 6:
        app->state = ov86_021E7B54(app);
        break;
    case 7:
        ov86_021E7258(app, 0);
        app->state = 8;
        break;
    case 8:
        if (TouchscreenHitbox_TouchNewIsIn(_021E7E98) == TRUE || (gSystem.newKeys & 3)) {
            PlaySE(0x5DD);
            ov86_021E71C0(app);
            app->unk5 = 4;
            app->state = 9;
        }
        break;
    case 9:
        if (ov86_021E7094(app) == 0) {
            app->state = app->unk5;
        }
        break;
    case 10:
        return TRUE;
    }
    return FALSE;
}

BOOL ov86_021E5C94(Ov86App *app) {
    switch (app->state) {
    case 0:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x79);
        app->state++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void ov86_021E5CDC(void *cbArg) {
    Ov86App *app = cbArg;

    if (app->plttData != NULL) {
        PaletteData_PushTransparentBuffers(app->plttData);
    }
    DoScheduledBgGpuUpdates(app->bgConfig);
    SpriteSystem_TransferOam();
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}
