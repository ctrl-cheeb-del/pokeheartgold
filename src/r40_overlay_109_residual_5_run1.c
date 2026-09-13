#include "global.h"

#include "r40_overlay_109_residual_5_private.h"

int ov109_021E6058(R40PhotoAlbumApp *app) {
    u32 keys;
    u8 hit;
    if (app->nextMenuState == 1 && (gSystem.newKeys & 0xF3)) {
        ov109_021E75B4(app);
    }
    keys = gSystem.newKeys;
    if (keys & PAD_BUTTON_A) {
        hit = app->cursorX;
        if (app->cursorY >= 3) {
            hit = 12;
        } else {
            hit += app->cursorY * 4;
        }
        return ov109_021E5F40(app, hit);
    }
    if (keys & PAD_BUTTON_B) {
        return ov109_021E5F40(app, 12);
    }
    if (keys & PAD_KEY_LEFT) {
        hit = app->cursorX;
        if (app->cursorY >= 3) {
            hit = 12;
        } else {
            hit += app->cursorY * 4;
        }
        if (hit == 12) {
            return 1;
        }
        if (app->cursorX != 0) {
            PlaySE(0x5DC);
            app->cursorX--;
            ov109_021E7474(app, app->cursorX, app->cursorY, 1);
        } else if (app->curPage != 0) {
            return ov109_021E5F40(app, 13);
        }
    } else if (keys & PAD_KEY_RIGHT) {
        hit = app->cursorX;
        if (app->cursorY >= 3) {
            hit = 12;
        } else {
            hit += app->cursorY * 4;
        }
        if (hit == 12) {
            return 1;
        }
        if (app->cursorX < 3) {
            PlaySE(0x5DC);
            app->cursorX++;
            ov109_021E7474(app, app->cursorX, app->cursorY, 1);
        } else if (app->curPage < app->numPages - 1) {
            return ov109_021E5F40(app, 14);
        }
    } else if (keys & PAD_KEY_UP) {
        if (app->cursorY == 4 && app->cursorX < 3) {
            app->cursorX = 3;
        }
        PlaySE(0x5DC);
        app->cursorY = (app->cursorY + 3) % 4;
        ov109_021E7474(app, app->cursorX, app->cursorY, 1);
    } else if (keys & PAD_KEY_DOWN) {
        PlaySE(0x5DC);
        app->cursorY = (app->cursorY + 1) % 4;
        ov109_021E7474(app, app->cursorX, app->cursorY, 1);
    }
    return 1;
}
