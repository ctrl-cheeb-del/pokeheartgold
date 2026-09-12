#include "overlay109_photo_tilemap_update_private.h"

void ov109_021E70C4(PhotoAlbumApp *app, int bgId, int mask, int idx) {
    if (mask & 1) {
        ov109_021E7030(app, bgId, idx, 0);
        ov109_021E6FD4(app, bgId, 1, idx);
    }
    if (mask & 2) {
        ov109_021E7030(app, bgId, idx, 2);
        ov109_021E6FD4(app, bgId, 2, idx);
    }
    ScheduleBgTilemapBufferTransfer(app->bgConfig, (u8)bgId);
}
