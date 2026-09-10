#include "field_effect_ground_marker_internal.h"

Ov01_02203A18_Work *ov01_02203A18(FieldEffectManager *a0);
void ov01_02203A38(Ov01_02203A18_Work *work);
BOOL ov01_02203A48(LocalMapObject *mapObject, int a1);
void ov01_02203AB4(FieldSystem *fieldSystem, LocalMapObject *mapObject, int a2);
BOOL ov01_02203AD8(TaskManager *taskManager);
void ov01_02203B28(Ov01_02203A18_Work *work);
void ov01_02203B70(Ov01_02203A18_Work *work);
void *ov01_02203B98(FieldSystem *fieldSystem, const VecFx32 *position);
BOOL ov01_02203BB4(void *a0, Ov01_02203A18_Inst *inst);
void ov01_02203CA0(void *a0, Ov01_02203A18_Inst *inst);
void ov01_02203CB8(void *a0, Ov01_02203A18_Inst *inst);
void ov01_02203DC0(void *a0, Ov01_02203A18_Inst *inst);
BOOL ov01_02203DF8(Ov01_02203A18_TexAnim *anim);

static const UnkOv01_02209280 ov01_02209518 = {
    0x68,
    (UnkOv01_02209280_Cb1)ov01_02203BB4,
    (UnkOv01_02209280_Cb1)ov01_02203CA0,
    (UnkOv01_02209280_Cb2)ov01_02203CB8,
    (UnkOv01_02209280_Cb2)ov01_02203DC0,
};

static const u32 ov01_0220952C[6] = { 0, 1, 0, 0, 0, 2 };

static const Ov01_02203A18_FileIds ov01_02209544[14] = {
    { 0x2, 0x96 },
    { 0x3, 0x97 },
    { 0x4, 0x98 },
    { 0x5, 0x99 },
    { 0x6, 0x9A },
    { 0x7, 0x9B },
    { 0x8, 0x9C },
    { 0x9, 0x9D },
    { 0xA, 0x9E },
    { 0xB, 0x9F },
    { 0xC, 0xA0 },
    { 0xD, 0xA1 },
    { 0xE, 0xA2 },
    { 0xF, 0xA3 },
};

Ov01_02203A18_Work *ov01_02203A18(FieldEffectManager *a0) {
    Ov01_02203A18_Work *work = (Ov01_02203A18_Work *)ov01_021F1430(a0, sizeof(Ov01_02203A18_Work), 0, 0);
    work->unk0 = a0;
    work->unk4 = FALSE;
    ov01_02203B28(work);
    return work;
}

void ov01_02203A38(Ov01_02203A18_Work *work) {
    ov01_02203B70(work);
    ov01_021F1448(work);
}

BOOL ov01_02203A48(LocalMapObject *mapObject, int a1) {
    Ov01_02203A18_Args args;
    VecFx32 position;
    VecFx32 facing;

    FieldSystem *fieldSystem = ov01_021F146C(mapObject);
    args.unk0 = fieldSystem;
    Ov01_02203A18_Work *work = (Ov01_02203A18_Work *)ov01_021F1450(fieldSystem, 0x12);
    args.unk4 = work;
    args.unk8 = mapObject;
    if (work->unk4) {
        return FALSE;
    }
    work->unk4 = TRUE;
    MapObject_CopyPositionVector(mapObject, &position);
    MapObject_CopyFacingVector(mapObject, &facing);
    facing.y = 0;
    VEC_Add(&position, &facing, &position);
    int priority = MapObject_GetPriority(mapObject) + 1;
    ov01_021F1620(fieldSystem, &ov01_02209518, &position, a1, (UnkOv01_021FFF5C *)&args, priority);
}

void ov01_02203AB4(FieldSystem *fieldSystem, LocalMapObject *mapObject, int a2) {
    Ov01_02203A18_TaskEnv *env = (Ov01_02203A18_TaskEnv *)Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(Ov01_02203A18_TaskEnv));
    env->unk0 = a2;
    env->unk4 = mapObject;
    TaskManager_Call(fieldSystem->taskman, ov01_02203AD8, env);
}

BOOL ov01_02203AD8(TaskManager *taskManager) {
    u32 *state = TaskManager_GetStatePtr(taskManager);
    Ov01_02203A18_TaskEnv *env = (Ov01_02203A18_TaskEnv *)TaskManager_GetEnvironment(taskManager);
    switch (*state) {
    case 0:
        ov01_02203A48(env->unk4, env->unk0);
        (*state)++;
        break;
    case 1: {
        Ov01_02203A18_Work *work = (Ov01_02203A18_Work *)ov01_021F1450(ov01_021F146C(env->unk4), 0x12);
        if (!work->unk4) {
            Heap_Free(env);
            return TRUE;
        }
        break;
    }
    }
    return FALSE;
}

void ov01_02203B28(Ov01_02203A18_Work *work) {
    ov01_021F18D4(work->unk0, 0xc, 0x82);
    ov01_021F1908(work->unk0, 0xc, 0x8c);
    ov01_021F1930(work->unk0, 0xd, 0x1c, TRUE);
    ov01_021F1758(work->unk0, 0xe, 0xc, 0xc, 0xd, 0, ov01_0220952C);
}

void ov01_02203B70(Ov01_02203A18_Work *work) {
    ov01_021F18FC(work->unk0, 0xc);
    ov01_021F1924(work->unk0, 0xc);
    ov01_021F1970(work->unk0, 0xd);
    ov01_021F18C8(work->unk0, 0xe);
}

void *ov01_02203B98(FieldSystem *fieldSystem, const VecFx32 *position) {
    void *ret = ov01_021F1740(fieldSystem, 0xe, position);
    NNS_G3dMdlSetMdlFogEnableFlagAll(sub_02023F90(ret), FALSE);
    return ret;
}

BOOL ov01_02203BB4(void *a0, Ov01_02203A18_Inst *inst) {
    VecFx32 position;

    inst->unk30 = *(Ov01_02203A18_Args *)sub_02068D98(a0);
    inst->unk8 = MapObject_GetID(inst->unk30.unk8);
    inst->unkC = MapObject_GetMapID(inst->unk30.unk8);
    inst->unk28 = FX32_CONST(6);
    u32 idx = (u32)sub_02068D90(a0);
    inst->unk40.unk18 = ov01_021F14B4(inst->unk30.unk0, ov01_02209544[idx].unk0, 1);
    inst->unk40.unk14 = ov01_021F14B4(inst->unk30.unk0, ov01_02209544[idx].unk4, 1);
    sub_02026E18(inst->unk40.unk14, &inst->unk40);
    inst->unk40.unk10 = NNS_G3dGetTex((const NNSG3dResFileHeader *)inst->unk40.unk18);
    inst->unk40.unk24 = 0;
    inst->unk40.unk26 = 0;
    NNSG3dResTex *tex = ov01_021F1AD4(inst->unk30.unk0, 0xd);
    inst->unk40.unk20 = sub_020209AC(tex, 0);
    inst->unk40.unk1C = sub_02020910(tex, 0);
    GF_CreateNewVramTransferTask((NNS_GFD_DST_TYPE)0, inst->unk40.unk1C, sub_02020838(inst->unk40.unk10, 0), inst->unk40.unk20);
    u32 plttAddr = NNS_GfdGetTexKeyAddr(tex->plttInfo.vramKey);
    GF_CreateNewVramTransferTask((NNS_GFD_DST_TYPE)1, plttAddr, sub_02020888(inst->unk40.unk10, 0), 0x20);
    sub_02068DB8(a0, &position);
    inst->unk3C = ov01_02203B98(inst->unk30.unk0, &position);
    sub_02023EA4(inst->unk3C, 0);
    PlaySE(SEQ_SE_DP_DECIDE);
    return TRUE;
}

void ov01_02203CA0(void *a0, Ov01_02203A18_Inst *inst) {
    sub_02023DA4(inst->unk3C);
    Heap_Free(inst->unk40.unk14);
    Heap_Free(inst->unk40.unk18);
}

void ov01_02203CB8(void *a0, Ov01_02203A18_Inst *inst) {
    VecFx32 result;
    VecFx32 position;
    VecFx32 facing;
    VecFx32 v1;
    VecFx32 v0;

    LocalMapObject *mapObject = inst->unk30.unk8;
    if (!sub_0205F0A8(mapObject, inst->unk8, inst->unkC)) {
        GF_AssertFail();
    }
    MapObject_CopyPositionVector(mapObject, &position);
    MapObject_CopyFacingVector(mapObject, &facing);
    sub_0205F990(mapObject, &v1);
    sub_0205F9B0(mapObject, &v0);
    result.x = v0.x + (v1.x + (position.x + facing.x));
    result.y = v0.y + (position.y + v1.y);
    result.z = v0.z + (v1.z + (position.z + facing.z));
    result.y += 0x20000;
    result.z += FX32_ONE;
    switch (inst->unk0) {
    case 0:
        sub_02023EA4(inst->unk3C, 1);
        inst->unk18.y += inst->unk28;
        if (inst->unk18.y > 0) {
            inst->unk28 -= FX32_CONST(2);
        } else {
            inst->unk18.y = 0;
            inst->unk28 = 0;
            inst->unk0++;
        }
        break;
    case 1:
        if (ov01_02203DF8(&inst->unk40)) {
            inst->unk0++;
        }
        break;
    case 2:
        if (++inst->unk4 >= 2) {
            inst->unk0++;
            inst->unk4 = 0;
            inst->unk14 = 1;
        }
        break;
    case 3:
        inst->unk30.unk4->unk4 = FALSE;
        ov01_021F1640((int)a0);
        return;
    }
    sub_02068DA8(a0, &result);
}

void ov01_02203DC0(void *a0, Ov01_02203A18_Inst *inst) {
    VecFx32 position;

    if (inst->unk10 != 1) {
        sub_02068DB8(a0, &position);
        position.x += inst->unk18.x;
        position.y += inst->unk18.y;
        position.z += inst->unk18.z;
        sub_02023E50(inst->unk3C, &position);
    }
}

BOOL ov01_02203DF8(Ov01_02203A18_TexAnim *anim) {
    anim->unk24++;
    if (anim->unk24 >= anim->unk0[anim->unk26]) {
        anim->unk26++;
        anim->unk24 = 0;
        if (anim->unk26 >= anim->unkC) {
            return TRUE;
        }
        GF_CreateNewVramTransferTask((NNS_GFD_DST_TYPE)0, anim->unk1C, sub_02020838(anim->unk10, anim->unk4[anim->unk26]), anim->unk20);
    }
    return FALSE;
}
