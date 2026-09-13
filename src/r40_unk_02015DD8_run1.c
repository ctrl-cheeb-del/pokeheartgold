#include "r40_unk_02015DD8_private.h"

ImageHandle *sub_02016118(GraphicsManager *manager) {
    int i;

    for (i = 0; i < manager->objectCount; i++) {
        if (manager->images[i].key == 0) {
            return &manager->images[i];
        }
    }
    return NULL;
}

PaletteHandle *sub_02016144(GraphicsManager *manager) {
    int i;

    for (i = 0; i < manager->objectCount; i++) {
        if (manager->palettes[i].key == 0) {
            return &manager->palettes[i];
        }
    }
    return NULL;
}
