#include "to45_overlay47_lifecycle_private.h"

BOOL ov47_02258800(OverlayManager *manager) {
    void *data;
    Ov47Args *args;

    args = OverlayManager_GetArgs(manager);

    Heap_Create(3, 0x81, 5 << 16);
    data = OverlayManager_CreateAndGetData(manager, 0x28C, 0x81);
    memset(data, 0, 0x28C);
    ov47_02258A1C(data, args->save, 0x81);
    ov47_02258C70((u8 *)data + 0x144, args->context, 0x81);
    ov47_02259228((u8 *)data + 0x268, data, args->save, 0x81);
    if (args->mode >= 2) {
        GF_AssertFail();
    }
    ov47_02259FB0[args->mode]((u8 *)data + 0x178, (u8 *)data + 0x144, data, args, 0x81);
    Main_SetVBlankIntrCB(ov47_02258A14, data);
    HBlankInterruptDisable();
    return TRUE;
}

BOOL ov47_02258898(OverlayManager *manager, int *step) {
    void *data = OverlayManager_GetData(manager);
    Ov47Args *args = OverlayManager_GetArgs(manager);

    switch (*step) {
    case 0:
        BeginNormalPaletteFade(0, 1, 1, 0, 6, 1, 0x81);
        ov45_0222A520(args->context, 1);
        (*step)++;
        break;
    case 1:
        if (IsPaletteFadeFinished() == TRUE) {
            (*step)++;
        }
        break;
    case 2:
        if (IsPaletteFadeFinished() == TRUE) {
            if (ov45_0222A330(args->context) == TRUE) {
                ov45_0222A4A8(args->context);
                (*step)++;
                break;
            }
            if (ov45_0222D844() == TRUE) {
                (*step)++;
                break;
            }
        }
        if (ov47_02259FA8[args->mode]((u8 *)data + 0x178, (u8 *)data + 0x144, data, (u8 *)data + 0x268, args, 0x81) == TRUE) {
            (*step)++;
        }
        break;
    case 3:
        BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x81);
        (*step)++;
        break;
    case 4:
        if (IsPaletteFadeFinished() == TRUE) {
            ov47_022593A0((u8 *)data + 0x268);
            return TRUE;
        }
        break;
    }
    ov47_02258A80(data);
    return FALSE;
}

BOOL ov47_022589A8(OverlayManager *manager) {
    void *data = OverlayManager_GetData(manager);
    Ov47Args *args = OverlayManager_GetArgs(manager);

    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    _02259FA0[args->mode]((u8 *)data + 0x178, (u8 *)data + 0x144, data);
    ov47_02259278((u8 *)data + 0x268, 0x81);
    ov47_02258CC0((u8 *)data + 0x144);
    ov47_02258A60(data);
    OverlayManager_FreeData(manager);
    Heap_Destroy(0x81);
    sub_0200616C(0);
    return TRUE;
}
