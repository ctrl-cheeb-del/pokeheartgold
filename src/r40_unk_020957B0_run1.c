#include "r40_unk_020957B0_private.h"

int sub_02095BF0(GridCursor *cursor, GridPosition *position, const u8 *dimensions, s8 dx, s8 dy) {
    s8 x;
    s8 y;
    int result = 0;
    u8 width = dimensions[0];
    u8 height = dimensions[1];

    if (dx != 0) {
        x = position->x + dx;
        y = ((s8 *)position)[FS_OVERLAY_ID(field)];
        if (x < 0) {
            result = FS_OVERLAY_ID(field);
        } else if (x >= width) {
            result = 2;
        } else if ((u8)(x + y * width) >= dimensions[2]) {
            result = 2;
        }
        if (result != 0) {
            goto done;
        }
        position->x = x;
        position->index = x + y * width;
    }

    if (dy != 0) {
        x = position->x;
        y = position->y + dy;
        if (y < 0) {
            result = 3;
        } else if (y >= height) {
            result = 4;
        } else if ((u8)(x + y * width) >= dimensions[2]) {
            result = 4;
        }
        if (result != 0) {
            goto done;
        }
        position->y = y;
        position->index = x + y * width;
    }
    return 0;

done:
    return result;
}
