#include "field_texture_manager_internal.h"

void FieldTextureManager_Free(FieldTextureManagerPrivate *manager) {
    s32 i;
    FieldTextureSlotPrivate *slot;
    if (manager == NULL || manager->busy != 0) {
        return;
    }
    i = 0;
    slot = manager->slots;
    while (i < 16) {
        if (slot->animation != NULL && slot->record != NULL) {
            u8 *entry = (u8 *)slot->record + slot->frame * 2;
            if (entry[0x11] <= slot->timer) {
                slot->timer = 1;
                slot->frame++;
                entry = (u8 *)slot->record + slot->frame * 2;
                if (entry[0x10] == 0xff) {
                    slot->frame = 0;
                }
                entry = (u8 *)slot->record + slot->frame * 2;
                GF_CreateNewVramTransferTask(0, slot->textureData, sub_02020838(slot->texture, entry[0x10]), slot->paletteData);
            } else {
                slot->timer++;
            }
        }
        i++;
        slot++;
    }
}
