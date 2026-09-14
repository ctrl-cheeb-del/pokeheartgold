#include "to45_overlay01_r4_private.h"

BOOL ov01_021F5038(MapLoadManager *mapLoadManager, int a1, int a2, u8 map0, u8 map1, u8 slot, u8 direction) {
    if (mapLoadManager->slots[slot].unk2C != 0) {
        GF_AssertFail();
    }
    mapLoadManager->slots[slot].unk2C = 1;
    *((u8 *)&mapLoadManager->slots[slot] + 0x30) = direction;
    mapLoadManager->slots[slot].unk1C = (void *)a1;
    mapLoadManager->slots[slot].unk20 = (void *)a2;
    mapLoadManager->slots[slot].unk24 = map0;
    mapLoadManager->slots[slot].unk25 = map1;
    mapLoadManager->slots[slot].unk04 = mapLoadManager->maps[map0];
    mapLoadManager->slots[slot].unk08 = mapLoadManager->maps[map1];
    mapLoadManager->slots[slot].unk26 = 0;
    mapLoadManager->slots[slot].unk28 = 0;
    if (mapLoadManager->unkA0 == 0) {
        mapLoadManager->unkB4 = 0;
    }
    mapLoadManager->maps[map0]->unk860 = a1;
    mapLoadManager->maps[map1]->unk860 = a2;
    mapLoadManager->unkA0++;
    mapLoadManager->unkA1 = (mapLoadManager->unkA1 + 1) % 2;
    return TRUE;
}
