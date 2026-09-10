#include "field_effect_model_bank_internal.h"

UnkOv01_021FE200 *ov01_021FE200(void *a0);
void ov01_021FE220(UnkOv01_021FE200 *a0);
void ov01_021FE230(UnkOv01_021FE200 *a0);
void ov01_021FE2B8(UnkOv01_021FE200 *a0);
NNSG3dRenderObj *ov01_021FE2DC(UnkOv01_021FE200 *a0, u32 a1, u32 a2, u32 a3);
UnkOv01_021FFECC_sub *ov01_021FE35C(UnkOv01_021FE200 *a0, u32 a1, u32 a2, u32 a3);
BOOL ov01_021FE3C4(LocalMapObject *a0);
BOOL ov01_021FE3D0(LocalMapObject *a0);
BOOL ov01_021FE3DC(LocalMapObject *a0);
BOOL ov01_021FE3E8(LocalMapObject *a0);
BOOL ov01_021FE3F4(LocalMapObject *a0);
BOOL ov01_021FE3F8(LocalMapObject *a0, u32 a1);
BOOL ov01_021FE4FC(void *a0, UnkOv01_021FE200_Work *a1);
void ov01_021FE524(void *a0, UnkOv01_021FE200_Work *a1);
void ov01_021FE528(void *a0, UnkOv01_021FE200_Work *a1);
void ov01_021FE558(void *a0, UnkOv01_021FE200_Work *a1);

static const UnkOv01_021FE200_Callbacks ov01_02208FE0 = {
    sizeof(UnkOv01_021FE200_Work),
    ov01_021FE4FC,
    ov01_021FE524,
    ov01_021FE528,
    ov01_021FE558,
};

static const u32 ov01_02208FF4[OV01_021FE200_COUNT] = {
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E,
    0x5F,
    0x60,
    0x61,
    0x62,
    0x63,
};

static const u32 ov01_0220901C[OV01_021FE200_COUNT] = {
    0x4A,
    0x4B,
    0x4C,
    0x4D,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
};

static const u32 ov01_02209044[4][4] = {
    { 4, 4, 7, 6 },
    { 4, 4, 9, 8 },
    { 8, 6, 5, 5 },
    { 9, 7, 5, 5 },
};

UnkOv01_021FE200 *ov01_021FE200(void *a0) {
    UnkOv01_021FE200 *ptr = (UnkOv01_021FE200 *)ov01_021F1430(a0, sizeof(UnkOv01_021FE200), 0, 0);
    ptr->unk0 = a0;
    ov01_021FE230(ptr);
    return ptr;
}

void ov01_021FE220(UnkOv01_021FE200 *a0) {
    ov01_021FE2B8(a0);
    ov01_021F1448(a0);
}

void ov01_021FE230(UnkOv01_021FE200 *a0) {
    u32 i;

    for (i = 0; i < OV01_021FE200_COUNT; i++) {
        ov01_021F19F4(a0->unk0, &a0->unk4[i], 0, ov01_0220901C[i], 0);
        sub_02069978(&a0->unk194[i], &a0->unk4[i]);
        ov01_021F19F4(a0->unk0, &a0->unkCC[i], 0, ov01_02208FF4[i], 0);
        sub_02069978(&a0->unk4DC[i], &a0->unkCC[i]);
    }
}

void ov01_021FE2B8(UnkOv01_021FE200 *a0) {
    int i;

    for (i = 0; i < OV01_021FE200_COUNT; i++) {
        sub_02069784(&a0->unk4[i]);
        sub_02069784(&a0->unkCC[i]);
    }
}

NNSG3dRenderObj *ov01_021FE2DC(UnkOv01_021FE200 *a0, u32 a1, u32 a2, u32 a3) {
    NNSG3dRenderObj *ret = NULL;

    switch (a1) {
    case 0:
        ret = &a0->unk194[a2];
        break;
    case 1:
        ret = &a0->unk194[ov01_02209044[a3][a2]];
        break;
    case 2:
    case 4:
        ret = &a0->unk4DC[a2];
        break;
    case 3:
        ret = &a0->unk4DC[ov01_02209044[a3][a2]];
        break;
    }

    if (ret == NULL) {
        GF_AssertFail();
    }
    return ret;
}

UnkOv01_021FFECC_sub *ov01_021FE35C(UnkOv01_021FE200 *a0, u32 a1, u32 a2, u32 a3) {
    UnkOv01_021FFECC_sub *ret = NULL;

    switch (a1) {
    case 0:
        ret = &a0->unk4[a2];
        break;
    case 1:
        ret = &a0->unk4[ov01_02209044[a3][a2]];
        break;
    case 2:
    case 4:
        ret = &a0->unkCC[a2];
        break;
    case 3:
        ret = &a0->unkCC[ov01_02209044[a3][a2]];
        break;
    }

    if (ret == NULL) {
        GF_AssertFail();
    }
    return ret;
}

BOOL ov01_021FE3C4(LocalMapObject *a0) {
    return ov01_021FE3F8(a0, 0);
}

BOOL ov01_021FE3D0(LocalMapObject *a0) {
    return ov01_021FE3F8(a0, 1);
}

BOOL ov01_021FE3DC(LocalMapObject *a0) {
    return ov01_021FE3F8(a0, 2);
}

BOOL ov01_021FE3E8(LocalMapObject *a0) {
    return ov01_021FE3F8(a0, 4);
}

BOOL ov01_021FE3F4(LocalMapObject *a0) {
    return FALSE;
}

BOOL ov01_021FE3F8(LocalMapObject *a0, u32 a1) {
    VecFx32 position;
    UnkOv01_021FE200_Args args;
    int x;
    int z;
    fx32 y;
    u32 direction;
    u32 prevDirection;
    u32 priority;
    FieldSystem *fieldSystem;
    UnkOv01_021FE200 *manager;

    x = MapObject_GetPreviousXCoord(a0);
    z = MapObject_GetPreviousZCoord(a0);
    y = MapObject_GetPositionVectorYCoord(a0);
    direction = MapObject_GetFacingDirection(a0);
    prevDirection = MapObject_GetPreviousFacingDirection(a0);
    priority = MapObject_GetPriorityPlusValue(a0, 2);
    fieldSystem = ov01_021F146C(a0);
    manager = (UnkOv01_021FE200 *)ov01_021F1450(fieldSystem, 2);
    if (MapObject_TestFlagsBits(a0, MAPOBJECTFLAG_VISIBLE) == TRUE) {
        return FALSE;
    }

    args.unk0 = a1;
    args.unk8 = ov01_021FE2DC(manager, a1, direction, prevDirection);
    args.unk4 = ov01_021FE35C(manager, a1, direction, prevDirection);
    sub_020611C8(x, z, &position);
    position.y = y;

    switch (a1) {
    case 0:
    case 1:
    case 4:
    case 5:
        position.y = y - 0x8000;
        if (a1 == 2 || a1 == 3) {
            position.z = position.z - 0x2000;
        } else {
            position.z = position.z + 0x1000;
        }
        break;
    case 2:
    case 3:
        position.y = y - 0xA000;
        if (a1 == 2 || a1 == 3) {
            position.z = position.z - 0x2000;
        } else {
            position.z = position.z + 0x2000;
        }
        break;
    }

    ov01_021F1620(fieldSystem, (const UnkOv01_02209280 *)&ov01_02208FE0, &position, 0, (UnkOv01_021FFF5C *)&args, priority);
}

BOOL ov01_021FE4FC(void *a0, UnkOv01_021FE200_Work *a1) {
    UnkOv01_021FE200_Mdl *mdl;

    a1->unk10 = sub_02068D90(a0);
    mdl = (UnkOv01_021FE200_Mdl *)sub_02068D98(a0);
    a1->unk18 = mdl->unk8;
    a1->unk14 = mdl->unk4;
    a1->unkC = 0x1F;
    a1->unk10 = mdl->unk0;
    return TRUE;
}

void ov01_021FE524(void *a0, UnkOv01_021FE200_Work *a1) {
}

void ov01_021FE528(void *a0, UnkOv01_021FE200_Work *a1) {
    switch (a1->unk0) {
    case 0:
        a1->unk4++;
        if (a1->unk4 >= 16) {
            a1->unk0++;
        }
        break;
    case 1:
        a1->unkC -= 2;
        if (a1->unkC < 0) {
            ov01_021F1640((int)a0);
        }
        break;
    }
}

void ov01_021FE558(void *a0, UnkOv01_021FE200_Work *a1) {
    VecFx32 position;

    if (a1->unk8 == 0) {
        sub_02068DB8(a0, &position);
        NNSi_G3dModifyPolygonAttrMask(a1->unk14->unkC, TRUE, 0x1F << 16);
        NNS_G3dMdlSetMdlAlphaAll(a1->unk14->unkC, a1->unkC);
        sub_020699BC(a1->unk18, &position);
    }
}
