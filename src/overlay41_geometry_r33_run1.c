#include "overlay41_geometry_r33_private.h"

void ov41_022482B8(void *work, int *outX, int *outY) {
    void *node = PTR_AT(work, 0x1C);
    int maxX = 0;
    int maxY = 0;

    work = (u8 *)work + 0x14;
    while (node != work) {
        int x;
        int y;
        ov41_02248400(node, &x, &y);
        if ((x < 0 ? -x : x) > (maxX < 0 ? -maxX : maxX)) {
            maxX = x;
        }
        if ((y < 0 ? -y : y) > (maxY < 0 ? -maxY : maxY)) {
            maxY = y;
        }
        node = PTR_AT(node, 8);
    }
    *outX = maxX;
    *outY = maxY;
}
