#include "r40_overlay_39_thumb_residual_22_private.h"
#include "system.h"

extern BOOL System_GetTouchNew(void);
extern void sub_0200E5D4(void *window, BOOL copyToVram);
extern BOOL ov39_02228B74(int a0, int a1);
extern void sub_0203946C(void);
extern void sub_0203A914(void);
extern void ov39_02228AA8(void *app);
extern void BeginNormalPaletteFade(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void ov39_02228B04(void *app, void *window, int message, u32 a3, u32 color);
extern void ov39_02228B6C(void *app, int a1, int a2);
extern BOOL ov39_02228A70(u32 printerId);
extern void ov00_021EC8D8(void);

BOOL ov39_02228EC8(Ov39Residual22App *app) {
    if ((gSystem.newKeys & 1) || (gSystem.newKeys & 2) || System_GetTouchNew() == TRUE) {
        sub_0200E5D4(app->unk64, FALSE);
        app->unk94 = 0;
        if (ov39_02228B74(-app->unk18, app->unk1C) == TRUE) {
            app->unk08 = 0;
        } else {
            app->unk08 = 8;
        }
    }
    return FALSE;
}

BOOL ov39_02228F18(Ov39Residual22App *app) {
    if (app->unk08 != 9) {
        sub_0203946C();
    }
    sub_0203A914();
    ov39_02228AA8(app);
    BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x7C);
    app->unk08 = 0;
    return TRUE;
}

BOOL ov39_02228F54(Ov39Residual22App *app) {
    int message = 0;

    switch (app->unk10 + 15) {
    case 16:
        message = 0x96;
        break;
    case 14:
    case 17:
        message = 0x97;
        break;
    case 1:
    case 13:
        message = 0x9C;
        break;
    case 0:
    case 3:
    case 10:
    case 12:
        message = 0x9B;
        break;
    }
    ov39_02228B04(app, app->unk24, message, app->unk90, 0xF0F);
    ov39_02228B6C(app, 0xC, 0xB);
    return FALSE;
}

BOOL ov39_02228FC8(Ov39Residual22App *app) {
    switch (app->unk94) {
    case 0:
        ov39_02228B04(app, app->unk24, 0xBA, app->unk90, 0xF0F);
        app->unk94++;
        break;
    case 1:
        if (ov39_02228A70(app->unk40) == FALSE) {
            sub_0203946C();
            ov00_021EC8D8();
            app->unk94++;
        }
        break;
    case 2:
        ov39_02228B04(app, app->unk24, 0xBB, app->unk90, 0xF0F);
        app->unk94++;
        break;
    case 3:
        if (ov39_02228A70(app->unk40) == FALSE) {
            app->unk94++;
        }
        break;
    default:
        app->unk98++;
        if (app->unk98 > 30) {
            app->unk08 = 8;
        }
        break;
    }
    return FALSE;
}
