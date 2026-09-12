#include "overlay96_grid_logic_r56_private.h"

void ov96_021F380C(u8 count, Ov96R17Node **nodes) {
    u8 i;

    for (i = 0; i < count; i++) {
        Ov96R17Node *node = nodes[i];
        if (node->active != NULL) {
            node->x = node->cell * 32 + 16 + LCRandom() % 32;
            node = nodes[i];
            node->y = node->row * 32 + 16 + LCRandom() % 32;
            node = nodes[i];
            node->score = node->cell + node->row * 7;
        } else {
            node->x = -1;
            nodes[i]->y = -1;
            nodes[i]->score = -1;
        }
    }
}

void ov96_021F3888(void *work, u8 count, Ov96R17Circle *circles, void *record, Ov96R17Node **nodes) {
    u8 i;

    for (i = 0; i < count; i++) {
        if (nodes[i]->active == NULL) {
            nodes[i]->result = -100;
        } else {
            s32 changed;
            nodes[i]->result = ov96_021F3930(work, circles, nodes[i]->score, record, nodes[i]->x, nodes[i]->y, &changed);
            if (changed != 0) {
                ov96_021F3AD8(work, circles, (u8)nodes[i]->score, &nodes[i]->x, &nodes[i]->y);
            }
        }
    }
}

s32 ov96_021F38FC(s32 x, s32 y) {
    s32 cx = (x - 16) / 32;
    s32 cy = (y - 16) / 32;
    s32 result;

    if (cx < 0 || cy < 0) {
        return -1;
    }
    result = cy * 7 + cx;
    if (result > 34) {
        result = -1;
    }
    return result;
}
