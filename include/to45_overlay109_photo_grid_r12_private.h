#ifndef TO45_OVERLAY109_PHOTO_GRID_R12_PRIVATE_H
#define TO45_OVERLAY109_PHOTO_GRID_R12_PRIVATE_H

#include "overlay109_sol_partial_internal.h"

extern const u8 ov109_021E7890[];

void ov109_021E7114(PhotoAlbumApp *app, int index, u8 bgId, u8 destX, u8 destY);
void ov109_021E7178(PhotoAlbumApp *app, Photo *entry, u8 bgId, u8 x, u8 y);
void ov109_021E71BC(PhotoAlbumApp *app, int oldIndex, int newIndex);

#endif
