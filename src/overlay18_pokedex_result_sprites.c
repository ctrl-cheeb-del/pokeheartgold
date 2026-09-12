#include "overlay18_pokedex_result_helpers_private.h"

void ov18_021F6178(void *work, int value) {
    u32 i;

    for (i = 0; i < 6; i++) {
        ov18_021F121C(work, i + 0xe, 0, value, 0);
    }
}

void ov18_021F619C(void *work, int index, int count, int sprite) {
    if (index == 0) {
        ov18_021F118C(work, sprite, 7);
    } else {
        ov18_021F118C(work, sprite, 5);
    }
    if (index == count - 1) {
        ov18_021F118C(work, sprite + 1, 10);
    } else {
        ov18_021F118C(work, sprite + 1, 8);
    }
}

void ov18_021F61DC(void *work, int sprite, int value, const u16 *table, u32 count) {
    ov18_021F118C(work, sprite, ov18_021F61F8(work, value, table, count));
}

int ov18_021F61F8(void *unused, int value, const u16 *table, u32 count) {
    u32 i = 0;

    if (count > i) {
        do {
            u16 threshold = *table;
            if (value <= threshold) {
                break;
            }
            i++;
            table++;
        } while (i < count);
    }
    return i + 0xe;
}
