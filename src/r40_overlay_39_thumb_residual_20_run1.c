#include "r40_overlay_39_thumb_residual_20_private.h"

extern BOOL ov39_02228A70(u32 printerId);
extern void ov39_02228A8C(void *app);
extern void ov39_02228AA8(void *app);
extern void ov39_02228B04(void *app, void *window, int message, u32 a3, u32 color);
extern void *ov39_02228AC0(void *bgConfig, u32 heapId);
extern int YesNoPrompt_HandleInput(void *prompt);
extern void YesNoPrompt_Destroy(void *prompt);
extern void sub_02039418(void *saveData);
extern void Sys_SetSleepDisableFlag(u32 flag);
extern void sub_0203A880(void);
extern void ov00_021EC3F0(void *p, u32 a1, u32 a2, u32 a3);
extern void ov00_021EC454(u32 value);
extern void ov00_021EC4A4(void);
extern void ov00_021EC60C(void);
extern int ov00_021EC5B4(void);
extern int ov00_021EC724(void);
extern int ov00_021EC11C(u32 *a, u32 *b);
extern void ov00_021EC210(void);
extern void ov00_021EC8D8(void);
extern void ov00_021EC0FC(void *out);
extern void ov00_021EC9E0(void *out);

BOOL ov39_02228BAC(Ov39Residual20App *app) {
    int result;

    if (ov39_02228A70(app->unk40) == TRUE) {
        return FALSE;
    }
    switch (app->unk94) {
    case 0:
        app->unk94++;
        break;
    case 1:
        ov39_02228B04(app, app->unk2C, 0x11, app->unk90, 0xF0F);
        app->unk94++;
        break;
    case 2:
        app->unk84 = ov39_02228AC0(app->unk04, 0x234);
        app->unk94++;
        break;
    case 3:
        result = YesNoPrompt_HandleInput(app->unk84);
        if (result == 1) {
            YesNoPrompt_Destroy(app->unk84);
            app->unk94++;
        } else if (result == 2) {
            YesNoPrompt_Destroy(app->unk84);
            app->unk08 = 8;
        }
        break;
    case 4:
        app->unk08 = 1;
        break;
    }
    return FALSE;
}

BOOL ov39_02228C78(Ov39Residual20App *app) {
    switch (app->unk94) {
    case 0:
        sub_02039418(((void **)*(void **)app->unk00)[1]);
        Sys_SetSleepDisableFlag(4);
        sub_0203A880();
        ov39_02228B04(app, app->unk28, 1, app->unk90, 0xF0F);
        ov39_02228A8C(app);
        app->unk94++;
        break;
    case 1:
        if (ov39_02228A70(app->unk40) == FALSE) {
            app->unk94++;
        }
        break;
    case 2:
        ov00_021EC3F0((u8 *)app->unk00 + 0x14, 2, 1, 0x14);
        ov00_021EC454(2);
        ov00_021EC4A4();
        app->unk08 = 2;
        break;
    }
    return FALSE;
}

BOOL ov39_02228D0C(Ov39Residual20App *app) {
    u8 work[0x48];

    ov00_021EC60C();
    if (ov00_021EC5B4() != 0) {
        switch (ov00_021EC724()) {
        case 7:
            app->unk14 = ov00_021EC11C((u32 *)(work + 8), (u32 *)(work + 4));
            app->unk18 = *(u32 *)(work + 8);
            app->unk1C = *(u32 *)(work + 4);
            ov00_021EC210();
            ov00_021EC8D8();
            ov39_02228AA8(app);
            app->unk08 = 6;
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 8:
        default:
            ov00_021EC0FC(work);
            ov39_02228AA8(app);
            app->unk08 = 10;
            app->unk10 = -2;
            break;
        case 4:
            ov00_021EC9E0(work + 0xC);
            app->unk08 = 3;
            break;
        }
    }
    return FALSE;
}
