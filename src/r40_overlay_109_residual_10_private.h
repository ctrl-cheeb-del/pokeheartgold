#ifndef OV109_RESIDUAL_10_PRIVATE_H
#define OV109_RESIDUAL_10_PRIVATE_H
#include "overlay109_photo_tilemap_update_private.h"
#include "vram_transfer_manager.h"
extern const OamManagerParam ov109_021E79D0;
extern const OamCharTransferParam ov109_021E78C8;
extern const ResdatIdList ov109_021E78A8;
void thunk_ClearMainOAM(int);
void thunk_ClearSubOAM(int);
void ov109_021E6DE4(PhotoAlbumApp *);
#endif
