#include "overlay40_pc_display_r4_private.h"

void ov40_0222CA8C(void *p) {
    int i;
    int j;
    int offset = 0x6F8;
    u8 *row;
    u8 *item;

    row = p;
    for (i = 0; i < 6; i++, row += 0x30) {
        j = 0;
        item = row;
        while (j < 2) {
            Sprite_DeleteAndFreeResources(PTR(item, offset));
            j++;
            item += 4;
        }
    }
}

void ov40_0222CABC(void *p) {
    int i;
    u8 *row = p;

    for (i = 0; i < 6; i++, row += 0x30) {
        SysTask_Destroy(PTR(row, 0x700));
    }
}
