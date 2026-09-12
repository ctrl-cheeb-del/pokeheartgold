#include "overlay40_party_sprites_r30_private.h"

void ov40_022373E4(Ov40PartySpriteWork *work, int draw) {
    Ov40PartySpriteData *data = *(Ov40PartySpriteData **)(work->raw + 0x860);
    int i;

    for (i = 0; i < 30; i++) {
        if (data->species[i] != 0) {
            ManagedSprite_SetDrawFlag(data->sprites[i], draw);
        }
    }
}

void ov40_02237410(Ov40PartySpriteWork *work) {
    Ov40PartySpriteData *data = *(Ov40PartySpriteData **)(work->raw + 0x860);
    int i;

    SpriteManager_UnloadPlttObjById(*(void **)(work->raw + 0x1c), 100000);
    SpriteManager_UnloadCellObjById(*(void **)(work->raw + 0x1c), 100000);
    SpriteManager_UnloadAnimObjById(*(void **)(work->raw + 0x1c), 100000);
    for (i = 0; i < 30; i++) {
        if (data->species[i] != 0 && data->sprites[i] != NULL) {
            SpriteManager_UnloadCharObjById(*(void **)(work->raw + 0x1c), 100000 + i);
            Sprite_DeleteAndFreeResources(data->sprites[i]);
            data->sprites[i] = NULL;
        }
    }
}
