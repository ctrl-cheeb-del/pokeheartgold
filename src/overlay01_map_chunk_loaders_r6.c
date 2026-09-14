#include "overlay01_map_chunk_loaders_r6_private.h"

void ov01_021F4D10(int index, void *a1, void *a2, int width, int height, MapLoadManager *manager, MapLoadChunkSet *set) {
    MapLoadIds ids;
    int result = ov01_021F4A50(&ids, manager, a2, set->chunks[index], set->extra[index], width * height, 1);
    if (result != 0xFFFF) {
        ov01_021F4AAC(manager, set->chunks[index]);
        ov01_021F4AE4(manager, set->chunks[index], ids.unk00);
        MapPropManager_LoadFromNARC(manager->narc, ids.unk0C, set->chunks[index]->unk868, manager->unkF4);
        ov01_021F4BE8(manager, set->chunks[index], &ids, a1, set, result, 1);
    }
}

void ov01_021F4D88(int index, void *a1, void *a2, int width, int height, MapLoadManager *manager, MapLoadChunkSet *set) {
    u8 buffer[0x800];
    MapLoadIds ids;
    int result = ov01_021F4A50(&ids, manager, a2, set->chunks[index], set->extra[index], width * height, 0);
    if (result != 0xFFFF) {
        ov01_021F4AAC(manager, set->chunks[index]);
        NARC_ReadFile(manager->narc, 0x800, buffer);
        MapPropManager_LoadFromNARC(manager->narc, ids.unk0C, set->chunks[index]->unk868, manager->unkF4);
        ov01_021F4BE8(manager, set->chunks[index], &ids, a1, set, result, 0);
    }
}

void ov01_021F4E1C(int index, void *a1, void *a2, int width, int height, MapLoadManager *manager, MapLoadChunkSet *set) {
    MapLoadIds ids;
    int result = ov01_021F4A50(&ids, manager, a2, set->chunks[index], set->extra[index], width * height, 1);
    if (result != 0xFFFF) {
        ov01_021F4AAC(manager, set->chunks[index]);
        ov01_021F4AE4(manager, set->chunks[index], ids.unk00);
        ov01_021F4B1C(manager, set->chunks[index], &ids, set->extra[index]);
        ov01_021F4BE8(manager, set->chunks[index], &ids, a1, set, result, 1);
    }
}
