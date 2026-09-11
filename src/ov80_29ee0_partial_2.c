#include "ov80_29ee0_partial_internal.h"

void ov80_0222A334(void *save, void *mon) {
    void *profile = Save_PlayerData_GetProfile(save);
    u32 oldOt = GetMonData(mon, 7, NULL);
    void *msgData;
    void *string;
    int mapSec;

    sub_0207217C(mon, Save_PlayerData_GetProfile(save), 4, 0, 0, 11);
    mapSec = MapHeader_GetMapSec(0x113);
    MonSetTrainerMemo(mon, profile, 0, mapSec, 11);
    msgData = NewMsgDataFromNarc(0, 0x1B, 0xC1, 11);
    string = NewString_ReadMsgData(msgData, 0);
    SetMonData(mon, 0x91, string);
    SetMonData(mon, 7, &oldOt);
    String_Delete(string);
    DestroyMsgData(msgData);
}

void ov80_0222A3BC(void *save, void *party, void *mon) {
    ov80_0222A334(save, mon);
    Party_AddMon(party, mon);
}

void ov80_0222A3D4(void *sprite, int animation) {
    if (animation != Sprite_GetAnimationNumber(sprite)) {
        Sprite_SetAnimationFrame(sprite, 0);
        Sprite_SetAnimCtrlSeq(sprite, animation);
        Sprite_UpdateAnim(sprite, FX32_ONE);
    }
}

void ov80_0222A400(void *sprite, int x, int y, int adjust) {
    VecFx32 position;
    position.x = x << FX32_SHIFT;
    position.y = y << FX32_SHIFT;
    position.z = 0;
    if (adjust == 1) {
        if (Sprite_GetAnimationFrame(sprite) == 0) {
            position.y = (y - 3) << FX32_SHIFT;
        } else {
            position.y = (y + 1) << FX32_SHIFT;
        }
    }
    Sprite_SetMatrix(sprite, &position);
}

int ov80_0222A43C(int hp, int maxHp) {
    switch (CalculateHpBarColor(hp, maxHp, 0x30)) {
    case 4:
        return 1;
    case 3:
        return 2;
    case 2:
        return 3;
    case 1:
        return 4;
    default:
        return 1;
    }
}

void ov80_0222A474(TrainerRecord *record, int trainerId, int heapId, int memberId) {
    Heap_Free(ov80_02229F04(record, trainerId, heapId, memberId));
}

void ov80_0222A480(void *dest, TrainerRecord *source, int count, int slot) {
    TrainerRecord *record = source;
    u8 *work = dest;
    int stride;
    u8 *nameDest;
    u16 *nameSource;
    *(u32 *)(work + 0x18 + slot * 4) = record->id;
    stride = slot;
    stride *= 0x34;
    (work + stride)[0x29] = record->species;
    nameDest = work;
    nameDest += 0x3C;
    nameSource = (u16 *)record;
    nameDest += stride;
    nameSource += 4;
    CopyU16StringArray((u16 *)nameDest, nameSource);
    *(u16 *)(work + stride + 0x4C) = record->values20[0];
    *(u16 *)(work + stride + 0x4E) = record->values20[1];
    *(u16 *)(work + stride + 0x50) = record->values20[2];
    *(u16 *)(work + stride + 0x52) = record->values20[3];
    *(u16 *)(work + stride + 0x54) = record->values20[4];
    *(u16 *)(work + stride + 0x56) = record->values20[5];
    *(u16 *)(work + stride + 0x58) = record->values20[6];
    *(u16 *)(work + stride + 0x5A) = record->values20[7];
}
