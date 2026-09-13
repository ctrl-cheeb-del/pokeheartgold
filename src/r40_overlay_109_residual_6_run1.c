#include "global.h"

#include "r40_overlay_109_residual_6_private.h"

int ov109_021E61DC(R40PhotoApp6 *app) {
    switch (app->subState) {
    case 0:
        if (app->counter++ < 15) {
            return 0;
        }
        ov109_021E70C4(app, 3, 3, app->curPage);
        ov109_021E73F8(app, 3, 0, app->unk22);
        app->counter = 0;
        app->subState++;
        break;
    case 1:
        if (app->counter++ < 30) {
            return 0;
        }
        if (TextPrinterCheckActive(app->printerId)) {
            return 0;
        }
        app->counter = 0;
        app->subState++;
        break;
    default:
        app->flag = 0;
        PlaySE(0x5DC);
        ov109_021E7474(app, app->cursorX, app->cursorY, 1);
        ov109_021E73F8(app, 0, 0, 0);
        ScheduleBgTilemapBufferTransfer(app->bgConfig, 3);
        app->counter = 0;
        app->subState = 0;
        return 1;
    }
    return 0;
}

int ov109_021E628C(R40PhotoApp6 *app, u32 input) {
    u8 slot;
    switch (input) {
    case 12:
        PlaySE(0x5DC);
        ov109_021E7248(app, 0);
        ov109_021E74D4(app, 0);
        ov109_021E77D4(app);
        ov109_021E73F8(app, 0, 0, 0);
        app->flag = 0;
        return 1;
    case 13:
        if (app->curPage == 0) {
            return 5;
        }
        ov109_021E7584(app, 2);
        PlaySE(0x920);
        return 2;
    case 14:
        if (app->curPage == app->numPages - 1) {
            return 5;
        }
        ov109_021E7584(app, 3);
        PlaySE(0x920);
        return 3;
    default:
        slot = _021E7884[input] + app->curPage * 12;
        if (slot >= app->numPhotos) {
            return 5;
        }
        PlaySE(0x5DC);
        ov109_021E74D4(app, 0);
        ov109_021E7248(app, 0);
        if (slot != app->slotIdx) {
            ov109_021E5DB8(app, app->slotIdx, slot);
            ov109_021E71BC(app, app->slotIdx, slot);
            ov109_021E7474(app, app->cursorX, app->cursorY, 0);
            app->counter = 0;
            return 6;
        }
        app->flag = 0;
        ov109_021E73F8(app, 0, 0, 0);
        return 1;
    }
}
