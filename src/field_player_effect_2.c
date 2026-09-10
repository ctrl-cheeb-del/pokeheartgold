#include "field_player_effect_internal.h"

void sub_0205AEA0(u8 *slots, int index, u8 value) {
    slots[index * 24] = value;
}

void sub_0205AEA8(Manager *manager, void *fieldSystem, MapObjectManager *objectManager, void *palPad) {
    int i;
    u8 *cursor = (u8 *)manager;
    (void)objectManager;

    for (i = 0; i < 10; i++) {
        SlotCursor *slot = (SlotCursor *)cursor;
        u8 *record = sub_0205A1F4(fieldSystem, i);
        u8 *recordId;
        u8 *profile;
        if (record != NULL) {
            recordId = record + 0x50;
            profile = recordId + 0x10;
        } else {
            recordId = NULL;
            profile = NULL;
        }

        switch (slot->state) {
        case 0:
            if (record != NULL) {
                slot->sprite = PlayerProfile_GetAvatar((PlayerProfile *)profile);
                slot->effect = PalPad_PlayerIdIsFriendOrMutual(palPad, PlayerProfile_GetTrainerID((PlayerProfile *)profile));
                slot->unkC = *(void **)recordId;
                if (sub_0205AD9C(manager, i, record, palPad)) {
                    slot->unk0 = 2;
                } else {
                    slot->unk0 = 1;
                }
            }
            break;
        case 2:
            if (record == NULL) {
                sub_0205AEA0((u8 *)manager->slots, i, 3);
            } else if (*(void **)recordId != slot->unkC) {
                sub_0205AEA0((u8 *)manager->slots, i, 3);
            }
            if (sub_0205AD9C(manager, i, record, palPad) && slot->pad15[0] == 1) {
                slot->unk0 = 3;
            }
            break;
        case 4:
            slot->unk0 = 0;
            break;
        }
        cursor += 24;
    }
}
