#include "field_warp_entrance_effect_internal.h"

Ov01_02200858_Work *ov01_02200858(FieldEffectManager *a0);
void ov01_02200874(Ov01_02200858_Work *work);
void ov01_02200884(Ov01_02200858_Work *work);
void ov01_022008A8(Ov01_02200858_Work *work);
void ov01_022008B4(PlayerAvatar *a0);
BOOL ov01_02200900(void *a0, Ov01_02200858_Inst *inst);
void ov01_02200938(void *a0, Ov01_02200858_Inst *inst);
void ov01_0220093C(void *a0, Ov01_02200858_Inst *inst);
void ov01_02200A08(void *a0, Ov01_02200858_Inst *inst);
int ov01_02200AB0(u8 tile);

extern const UnkOv01_02209280 ov01_02209340;

Ov01_02200858_Work *ov01_02200858(FieldEffectManager *a0) {
    Ov01_02200858_Work *work = (Ov01_02200858_Work *)ov01_021F1430(a0, sizeof(Ov01_02200858_Work), 0, 0);
    work->unk0 = a0;
    ov01_02200884(work);
    return work;
}

void ov01_02200874(Ov01_02200858_Work *work) {
    ov01_022008A8(work);
    ov01_021F1448(work);
}

void ov01_02200884(Ov01_02200858_Work *work) {
    ov01_021F19F4(work->unk0, &work->unk4, 0, 0x55, 0);
    sub_02069978(&work->unk18, &work->unk4);
}

void ov01_022008A8(Ov01_02200858_Work *work) {
    sub_02069784(&work->unk4);
}

void ov01_022008B4(PlayerAvatar *a0) {
    Ov01_02200858_Args args;
    VecFx32 position = { 0, 0, 0 };

    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(a0);
    FieldSystem *fieldSystem = ov01_021F146C(mapObject);
    args.unk0 = fieldSystem;
    args.unk4 = (Ov01_02200858_Work *)ov01_021F1450(fieldSystem, 3);
    args.unk8 = a0;
    ov01_021F1620(fieldSystem, &ov01_02209340, &position, 0, (UnkOv01_021FFF5C *)&args, MapObject_GetPriorityPlusValue(mapObject, 2));
}

BOOL ov01_02200900(void *a0, Ov01_02200858_Inst *inst) {
    Ov01_02200858_Args *args = (Ov01_02200858_Args *)sub_02068D98(a0);
    inst->unk24 = *args;
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(args->unk8);
    inst->unk4 = -1;
    inst->unk14 = MapObject_GetID(mapObject);
    inst->unk18 = MapObject_GetMapID(mapObject);
    return TRUE;
}

void ov01_02200938(void *a0, Ov01_02200858_Inst *inst) {
}

void ov01_0220093C(void *a0, Ov01_02200858_Inst *inst) {
    VecFx32 objPos;
    VecFx32 position;

    PlayerAvatar *avatar = inst->unk24.unk8;
    LocalMapObject *mapObject = PlayerAvatar_GetMapObject(avatar);
    if (!sub_0205F0A8(mapObject, inst->unk14, inst->unk18)) {
        ov01_021F1640((int)a0);
        return;
    }
    int prevDir = inst->unk4;
    inst->unk8 = sub_0205F504(mapObject);
    inst->unk4 = ov01_02200AB0(inst->unk8);
    inst->unk0 = 0;
    if (inst->unk4 == -1 || inst->unk4 != (int)PlayerAvatar_GetFacingDirection(avatar)) {
        inst->unk1C = 0;
        inst->unk20 = 0;
        inst->unk0 = 1;
        return;
    }
    if (prevDir != inst->unk4) {
        inst->unk1C = 0;
        inst->unk20 = 0;
    }
    int x = MapObject_GetXCoord(mapObject);
    int dx = GetDeltaXByFacingDirection(inst->unk4);
    int z = MapObject_GetZCoord(mapObject);
    int dy = GetDeltaYByFacingDirection(inst->unk4);
    sub_020611C8(x + dx, z + dy, &position);
    MapObject_CopyPositionVector(mapObject, &objPos);
    position.y = objPos.y;
    sub_02068DA8(a0, &position);
    inst->unk1C++;
    if (inst->unk1C > 15) {
        inst->unk1C = 0;
        inst->unk20 = (inst->unk20 + 1) % 2;
    }
}
