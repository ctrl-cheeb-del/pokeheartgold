#include "to45_overlay01_r4_private.h"
void ov01_021F54AC(int a0, int a1, u8 map0, u8 map1, u8 direction, MapLoadManager *mapLoadManager) {
    u8 slot;

    if (mapLoadManager->unk64.unk08 == 1) {
        GF_AssertFail();
    }
    if (ov01_021F5BBC(direction, mapLoadManager, &slot) == 1) {
        ov01_021F474C(mapLoadManager, slot);
        if (mapLoadManager->unkA0 >= 2) {
            mapLoadManager->unk64.unk08 = 1;
            mapLoadManager->unk64.unk10 = a0;
            mapLoadManager->unk64.unk14 = a1;
            mapLoadManager->unk7C = map0;
            mapLoadManager->unk7D = map1;
            mapLoadManager->unk64.unk00 = mapLoadManager->maps[map0];
            mapLoadManager->unk64.unk04 = mapLoadManager->maps[map1];
            mapLoadManager->unk64.unk0C = direction;
            mapLoadManager->maps[map0]->unk860 = a0;
            mapLoadManager->maps[map1]->unk860 = a1;
            return;
        }
        ov01_021F5038(mapLoadManager, a0, a1, map0, map1, mapLoadManager->unkA1, direction);
    } else if (ov01_021F5038(mapLoadManager, a0, a1, map0, map1, mapLoadManager->unkA1, direction) != 1) {
        GF_AssertFail();
    }
}

void ov01_021F5568(int idx, MapLoadManager *mapLoadManager);
void ov01_021F5568(int idx, MapLoadManager *mapLoadManager) {
    mapLoadManager->maps[idx]->unk864 = 0;
    ov01_021FB2F4(mapLoadManager->maps[idx]->unk85C);
    MapPropManager_Reset(mapLoadManager->maps[idx]->unk868);
    mapLoadManager->maps[idx]->unk860 = -1;
    MIi_CpuClearFast(-1, (u32 *)mapLoadManager->maps[idx], 0x800);
    MIi_CpuClear32(0, (u32 *)&mapLoadManager->maps[idx]->unk86C, 0x204);
    mapLoadManager->unk80[idx] = 1;
    if (ov01_02204698(mapLoadManager->unkF8) != 0) {
        ov01_02204688(mapLoadManager->unkF8, (NNSG3dRenderObj *)((u8 *)mapLoadManager->maps[idx] + 0x800));
    }
    *(u32 *)((u8 *)mapLoadManager->maps[idx] + 0x808) = 0;
}
