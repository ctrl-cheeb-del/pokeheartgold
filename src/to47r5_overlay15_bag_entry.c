#include "global.h"

#include "overlay_15.h"
#include "system.h"

extern void *memset(void *, int, u32);

extern void HBlankInterruptDisable(void);
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void *BgConfig_Alloc(u32);
extern u32 PlayerProfile_GetTrainerGender(void *);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern BOOL IsPaletteFadeFinished(void);
extern void SetKeyRepeatTimers(int, int);
extern void TextFlags_SetCanTouchSpeedUpPrint(BOOL);
extern void ToggleBgLayer(u32, u32);
extern void Sound_SetSceneAndPlayBGM(int, int, int);
extern void SpriteSystem_DrawSprites(void *);
extern void sub_020210BC(void);
extern void sub_02021148(int);
extern void sub_0203A964(void);
extern void sub_020880CC(u32, u32);

extern void BagApp_GetSaveStructPtrs(void *);
extern void ov15_021F9984(void);
extern void ov15_021F995C(void *);
extern void ov15_021F99A4(void *);
extern void ov15_021F9AE4(void *);
extern void ov15_021F9CBC(void *);
extern void ov15_021F9D28(void *);
extern void ov15_021F9DB4(void *);
extern void ov15_021F9F08(void *);
extern void ov15_021FA008(void *);
extern void ov15_021FA044(s16 *, u16 *, u32);
extern void ov15_021FA070(s16 *, u16 *, u32, u32);
extern u32 ov15_021FA074(void *);
extern void ov15_021FA170(void *);
extern s32 ov15_021FA1BC(void *);
extern s32 ov15_021FA4F8(void *);
extern s32 ov15_021FA578(void *, s32);
extern void ov15_021FA620(void *);
extern s32 ov15_021FA93C(void *);
extern s32 ov15_021FAE48(void *);
extern s32 ov15_021FAFFC(void *);
extern s32 ov15_021FB060(void *);
extern s32 ov15_021FB5AC(void *);
extern s32 ov15_021FB604(void *);
extern s32 ov15_021FB654(void *);
extern s32 ov15_021FB700(void *);
extern s32 ov15_021FB820(void *);
extern s32 ov15_021FBD50(void *);
extern s32 ov15_021FBF98(void *);
extern s32 ov15_021FBFC0(void *);
extern s32 ov15_021FBFF8(void *);
extern s32 ov15_021FC01C(void *);
extern s32 ov15_021FC140(void *);
extern s32 ov15_021FC164(void *);
extern s32 ov15_021FC2E0(void *);
extern s32 ov15_021FC41C(void *);
extern s32 ov15_021FC784(void *);
extern s32 ov15_021FC7EC(void *);
extern s32 ov15_021FCB64(void *);
extern s32 ov15_021FCD80(void *);
extern s32 ov15_021FCDE4(void *);
extern s32 ov15_021FCFC8(void *);
extern s32 ov15_021FD058(void *);
extern s32 ov15_021FD0E8(void *);
extern s32 ov15_021FD10C(void *);
extern s32 ov15_021FD24C(void *);
extern s32 ov15_021FD2FC(void *);
extern s32 ov15_021FD3AC(void *);
extern void ov15_021FD404(void *, u32, u32);
extern void ov15_021FD574(void *, u32, u32, u32);
extern s32 ov15_021FD850(void *);
extern void ov15_021FD93C(void *);
extern void ov15_021FDC88(void *);
extern void ov15_021FE020(void *);
extern void ov15_021FE4C8(void *);
extern void ov15_021FE528(void *);
extern void ov15_021FE874(void *);
extern void ov15_021FEA5C(void *);
extern void ov15_021FF1E0(void *);
extern void ov15_021FF29C(void *, u32);
extern void ov15_021FF364(void *, s32, s32, u32);
extern void ov15_021FF6BC(void *, u32, s32, u32);
extern void ov15_021FF850(void *);
extern void ov15_021FF8D4(void *);
extern void ov15_021FFECC(void *, u32);
extern void ov15_02200030(void *, u32);
extern void ov15_02200140(void *, void *, u32, u32);

#define ARGS (*(u8 **)(work + 0x234))
#define SEL  (ARGS[0x64])



BOOL Bag_Init(OverlayManager *man, int *state) {
    u8 *work;

#pragma unused(state)

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    Heap_Create(HEAP_ID_3, HEAP_ID_6, 0x42000);
    work = OverlayManager_CreateAndGetData(man, 0x94C, HEAP_ID_6);
    memset(work, 0, 0x94C);
    *(void **)(work + 0x234) = OverlayManager_GetArgs(man);
    BagApp_GetSaveStructPtrs(work);
    *(void **)work = BgConfig_Alloc(HEAP_ID_6);
    work[0x615] = PlayerProfile_GetTrainerGender(*(void **)(work + 0x23C));
    BeginNormalPaletteFade(2, 3, 3, 0, 6, 1, HEAP_ID_6);
    SetKeyRepeatTimers(3, 8);
    ov15_021F9DB4(work);
    ov15_021F9CBC(work);
    ov15_021FA008(work);
    ov15_021F9D28(work);
    ov15_021FA620(work);
    ov15_021F9984();
    ov15_021F99A4(*(void **)work);
    ov15_021F9AE4(work);
    sub_020210BC();
    sub_02021148(4);
    ov15_021FE020(work);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    ov15_021FE4C8(work);
    ov15_021FE528(work);
    ov15_021FEA5C(work);
    ov15_021FE874(work);
    ov15_021F9F08(work);
    ov15_021FF29C(work, 0);
    ov15_021FA044((s16 *)(ARGS + 10 + 12 * SEL), (u16 *)(ARGS + 8 + 12 * SEL), *(ARGS + 12 * SEL + 13));
    ov15_021FA070((s16 *)(ARGS + 10 + 12 * SEL), (u16 *)(ARGS + 8 + 12 * SEL), *(ARGS + 12 * SEL + 13), HEAP_ID_6);
    ov15_021FF850(work);
    ov15_021FD574(work, 0, ov15_021FA074(work), 0);
    ov15_021FF364(work, *(s16 *)(ARGS + 12 * SEL + 10), -1, 0);
    ov15_02200030(work, ARGS[0x64]);
    ov15_021FD404(work, 1, ARGS[0x64]);
    ov15_021FF6BC(work, *(ARGS + 12 * SEL + 13), *(s16 *)(ARGS + 12 * SEL + 10), 0);
    ov15_02200140(work, ARGS + 4 + 12 * SEL, ov15_021FA074(work), 1);
    *(u32 *)(work + 0x644) = *(u16 *)(ARGS + 12 * SEL + 8) + 8;
    ov15_021FFECC(work, *(u32 *)(work + 0x644));
    ov15_021FA170(work);
    if (ARGS[0x65] == 4 || ARGS[0x65] == 5) {
        ov15_021FF1E0(work);
    }
    ov15_021FD93C(work);
    Main_SetVBlankIntrCB(ov15_021F995C, work);
    Sound_SetSceneAndPlayBGM(0x33, 0, 0);
    sub_0203A964();
    reg_GX_POWCNT |= 0x8000;
    ToggleBgLayer(4, 1);
    return TRUE;
}

BOOL Bag_Main(OverlayManager *man, int *state) {
    u8 *work;

    work = OverlayManager_GetData(man);
    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished() == TRUE) {
            switch (ARGS[0x65]) {
            case 2:
                *state = 16;
                break;
            case 1:
                *state = 14;
                break;
            case 3:
                *state = 26;
                break;
            default:
                *state = 1;
                break;
            }
        }
        break;
    case 1:
        *state = ov15_021FA1BC(work);
        break;
    case 2:
        if (ov15_021FA93C(work) == TRUE) {
            if (ARGS[0x65] == 2) {
                *state = 16;
            } else if (ARGS[0x65] == 1) {
                *state = 14;
            } else if (ARGS[0x65] == 3) {
                *state = 26;
            } else {
                *state = 1;
            }
        }
        break;
    case 3:
        *state = ov15_021FAE48(work);
        break;
    case 4:
        *state = ov15_021FB5AC(work);
        break;
    case 5:
        *state = ov15_021FBD50(work);
        break;
    case 6:
        *state = ov15_021FBF98(work);
        break;
    case 7:
        *state = ov15_021FBFC0(work);
        break;
    case 8:
        *state = ov15_021FBFF8(work);
        break;
    case 9:
        *state = ov15_021FC01C(work);
        break;
    case 10:
        *state = ov15_021FC140(work);
        break;
    case 11:
        *state = ov15_021FC164(work);
        break;
    case 12:
        *state = ov15_021FB700(work);
        break;
    case 13:
        *state = ov15_021FB820(work);
        break;
    case 14:
        *state = ov15_021FC41C(work);
        break;
    case 15:
        *state = ov15_021FC784(work);
        break;
    case 16:
        *state = ov15_021FC7EC(work);
        break;
    case 17:
        *state = ov15_021FCD80(work);
        break;
    case 18:
        *state = ov15_021FCDE4(work);
        break;
    case 19:
        *state = ov15_021FCFC8(work);
        break;
    case 20:
        *state = ov15_021FD058(work);
        break;
    case 21:
        *state = ov15_021FD0E8(work);
        break;
    case 22:
        *state = ov15_021FD10C(work);
        break;
    case 23:
        *state = ov15_021FD24C(work);
        break;
    case 24:
        *state = ov15_021FD2FC(work);
        break;
    case 26:
        *state = ov15_021FD3AC(work);
        break;
    case 25:
        *state = ov15_021FC2E0(work);
        break;
    case 27:
        *state = ov15_021FA4F8(work);
        break;
    case 28:
        *state = ov15_021FB604(work);
        break;
    case 29:
        *state = ov15_021FB654(work);
        break;
    case 30:
        *state = ov15_021FA578(work, 1);
        break;
    case 31:
        *state = ov15_021FA578(work, -1);
        break;
    case 32:
        *state = ov15_021FB060(work);
        break;
    case 33:
        *state = ov15_021FAFFC(work);
        break;
    case 34:
        *state = ov15_021FCB64(work);
        break;
    case 35:
        *state = ov15_021FD850(work);
        break;
    case 36:
        sub_020880CC(1, HEAP_ID_6);
        *state = 37;
        break;
    case 37:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    ov15_021FF8D4(work);
    SpriteSystem_DrawSprites(*(void **)(work + 0x24C));
    ov15_021FDC88(work);
    return FALSE;
}
