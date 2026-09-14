#include "to45_overlay109_photo_grid_r12_private.h"

void ov109_021E71BC(PhotoAlbumApp *app, int oldIndex, int newIndex) {
    int page;
    u8 packed;

    page = oldIndex / 12;
    if (page == app->curPage) {
        packed = ov109_021E7890[oldIndex % 12];
        ov109_021E7178(app, NULL, 3, packed % 4, packed >> 2);
    }
    page = newIndex / 12;
    if (page == app->curPage) {
        packed = ov109_021E7890[newIndex % 12];
        ov109_021E7178(app, NULL, 3, packed % 4, packed >> 2);
    }
    ScheduleBgTilemapBufferTransfer(app->bgConfig, 3);
}
