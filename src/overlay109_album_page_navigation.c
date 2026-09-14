#include "constants/sndseq.h"
#define ov109_021E63E8 ov109_021E63E8_decl
#include "overlay109_sol_partial_internal.h"
#undef ov109_021E63E8
#include "system.h"

extern const fx32 ov109_021E78DC[];
extern void PlaySE(u16 seqId);

int ov109_021E628C(PhotoAlbumApp *app, u8 hit);
void ov109_021E7474(PhotoAlbumApp *app, u8 x, u8 y, int draw);
void ov109_021E74D4(PhotoAlbumApp *app, int draw);
void ov109_021E68B8(PhotoAlbumApp *app, int on);
void ov109_021E691C(PhotoAlbumApp *app, fx32 v);
void ov109_021E6F7C(PhotoAlbumApp *app, int a, int b);
void ov109_021E70C4(PhotoAlbumApp *app, int a, int b, u8 c);
void ov109_021E7524(PhotoAlbumApp *app);
int ov109_021E656C(PhotoAlbumApp *app);
int ov109_021E66C4(PhotoAlbumApp *app);
int ov109_021E63E8(PhotoAlbumApp *app);

int ov109_021E63E8(PhotoAlbumApp *app) {
    u8 hit;

    if (app->nextMenuState == 1 && (gSystem.newKeys & 0xF3)) {
        ov109_021E75B4(app);
    }

    if (gSystem.newKeys & PAD_BUTTON_A) {
        hit = app->cursorX;
        if (app->cursorY >= 3) {
            hit = 12;
        } else {
            hit += app->cursorY * 4;
        }
        return ov109_021E628C(app, hit);
    }
    if (gSystem.newKeys & PAD_BUTTON_B) {
        return ov109_021E628C(app, 12);
    }
    if (gSystem.newKeys & PAD_KEY_LEFT) {
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
            PlaySE(SEQ_SE_DP_SELECT);
            app->cursorX--;
            ov109_021E7474(app, app->cursorX, app->cursorY, 1);
        } else if (app->curPage != 0) {
            app->cursorX = (app->cursorX + 3) % 4;
            return ov109_021E628C(app, 13);
        }
    } else if (gSystem.newKeys & PAD_KEY_RIGHT) {
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
            PlaySE(SEQ_SE_DP_SELECT);
            app->cursorX++;
            ov109_021E7474(app, app->cursorX, app->cursorY, 1);
        } else if (app->curPage < app->numPages - 1) {
            app->cursorX = (app->cursorX + 1) % 4;
            return ov109_021E628C(app, 14);
        }
    } else if (gSystem.newKeys & PAD_KEY_UP) {
        if (app->cursorY == 4 && app->cursorX < 3) {
            app->cursorX = 3;
        }
        PlaySE(SEQ_SE_DP_SELECT);
        app->cursorY = (app->cursorY + 3) % 4;
        ov109_021E7474(app, app->cursorX, app->cursorY, 1);
    } else if (gSystem.newKeys & PAD_KEY_DOWN) {
        PlaySE(SEQ_SE_DP_SELECT);
        app->cursorY = (app->cursorY + 1) % 4;
        ov109_021E7474(app, app->cursorX, app->cursorY, 1);
    }
    return 5;
}

typedef struct PhaseByte {
    u8 low : 4;
    u8 phase : 4;
} PhaseByte;

#define PHASE(app) (((PhaseByte *)((u8 *)(app) + 0x18))->phase)

int ov109_021E656C(PhotoAlbumApp *app) {
    switch (app->subState) {
    case 0:
        ov109_021E7474(app, app->cursorX, app->cursorY, 0);
        ov109_021E74D4(app, 0);
        ov109_021E68B8(app, 1);
        ov109_021E691C(app, FX32_ONE);
        ov109_021E6F7C(app, 1, 1);
        ov109_021E70C4(app, 2, 1, app->curPage);
        ov109_021E70C4(app, 3, 1, app->curPage - 1);
        PHASE(app) = 0;
        app->subState++;
        break;
    case 1:
        PHASE(app)
        ++;
        ov109_021E691C(app, ov109_021E78DC[PHASE(app)]);
        if (PHASE(app) >= 4) {
            ov109_021E6F7C(app, 2, 1);
            ov109_021E70C4(app, 2, 2, app->curPage - 1);
            app->subState++;
        }
        break;
    case 2:
        PHASE(app) = PHASE(app) - 1;
        ov109_021E691C(app, ov109_021E78DC[PHASE(app)]);
        if (PHASE(app) == 0) {
            ov109_021E70C4(app, 3, 2, app->curPage - 1);
            ov109_021E68B8(app, 0);
            ov109_021E691C(app, FX32_ONE);
            app->curPage--;
            ov109_021E7474(app, app->cursorX, app->cursorY, 1);
            ov109_021E7524(app);
            if (app->unk_20 == 1) {
                ov109_021E74D4(app, 1);
            }
            app->subState = 0;
            return 1;
        }
        break;
    }
    return 0;
}

int ov109_021E66C4(PhotoAlbumApp *app) {
    switch (app->subState) {
    case 0:
        ov109_021E7474(app, app->cursorX, app->cursorY, 0);
        ov109_021E74D4(app, 0);
        ov109_021E68B8(app, 1);
        ov109_021E691C(app, FX32_ONE);
        ov109_021E6F7C(app, 2, 1);
        ov109_021E70C4(app, 2, 2, app->curPage);
        ov109_021E70C4(app, 3, 2, app->curPage + 1);
        PHASE(app) = 0;
        app->subState++;
        break;
    case 1:
        PHASE(app)
        ++;
        ov109_021E691C(app, ov109_021E78DC[PHASE(app)]);
        if (PHASE(app) >= 4) {
            ov109_021E6F7C(app, 1, 1);
            ov109_021E70C4(app, 2, 1, app->curPage + 1);
            app->subState++;
        }
        break;
    case 2:
        PHASE(app) = PHASE(app) - 1;
        ov109_021E691C(app, ov109_021E78DC[PHASE(app)]);
        if (PHASE(app) == 0) {
            ov109_021E70C4(app, 3, 1, app->curPage + 1);
            ov109_021E68B8(app, 0);
            ov109_021E691C(app, FX32_ONE);
            app->curPage++;
            ov109_021E7474(app, app->cursorX, app->cursorY, 1);
            ov109_021E7524(app);
            if (app->unk_20 == 1) {
                ov109_021E74D4(app, 1);
            }
            app->subState = 0;
            return 1;
        }
        break;
    }
    return 0;
}
