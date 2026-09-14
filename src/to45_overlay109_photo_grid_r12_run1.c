#include "to45_overlay109_photo_grid_r12_private.h"

void ov109_021E7114(PhotoAlbumApp *app, int index, u8 bgId, u8 destX, u8 destY) {
    PhotoTiles *tiles;
    int rem;
    int quot;

    tiles = app->unk_B4;
    rem = index % 6;
    quot = index / 6;
    CopyToBgTilemapRect(app->bgConfig, bgId, destX, destY, 5, 5, tiles->data, (u8)(rem * 5), (u8)(quot * 5), (u8)(tiles->unk_00 >> 3), (u8)(tiles->unk_02 >> 3));
}
