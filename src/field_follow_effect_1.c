#include "field_follow_effect_internal.h"

void *ov01_022031C0(void *arg) {
    u8 *p = ov01_021F1430((u32)arg, 0x140, 0, 0);
    *(void **)p = arg;
    HeapExp_FndInitAllocator(p + 4, 4, 0x20);
    ov01_022031F8(p);
    return p;
}

void ov01_022031E8(void *p) {
    ov01_02203270(p);
    ov01_021F1448(p);
}

void ov01_022031F8(void *v) {
    u8 *p = v;
    *(void **)(p + 0x14) = ov01_021F14B4(*(void **)p, 0x81, 0);
    ov01_021FBD38(p + 0x1c, *(void **)(p + 0x14));
    Field3dObject_InitFromModel(p + 0x3c, p + 0x1c);
    *(void **)(p + 0x18) = ov01_021F14B4(*(void **)p, 0x68, 0);
    ov01_021FBD38(p + 0x2c, *(void **)(p + 0x18));
    Field3dObject_InitFromModel(p + 0xb4, p + 0x2c);
    Field3dModelAnimation_LoadFromFilesystem(p + 0x12c, p + 0x2c, 0x67, 0xa4, 4, p + 4);
    Field3dObject_AddAnimation(p + 0xb4, p + 0x12c);
}

void ov01_02203270(void *v) {
    u8 *p = v;
    ov01_021FBDFC(p + 0x1c);
    ov01_021F1448(*(void **)(p + 0x14));
    ov01_021FBDFC(p + 0x2c);
    ov01_021F1448(*(void **)(p + 0x18));
    Field3dModelAnimation_Unload(p + 0x12c, p + 4);
}

void ov01_0220329C(void *mapObj, u32 variant) {
    SpawnArgs a;
    s32 priority;
    void *ctx = ov01_021F146C(mapObj);
    MapObject_CopyPositionVector(mapObj, &a.pos);
    a.pos.z += 6 << 12;
    a.h0 = 0;
    a.h1 = 0;
    a.byte = -1;
    a.ctx = ctx;
    a.a = ov01_021F1468(ctx);
    a.b = ov01_021F1450(ctx, 0x11);
    a.mapObj = mapObj;
    MapObject_CopyPositionVector(mapObj, &a.mapPos);
    priority = MapObject_GetPriorityPlusValue(mapObj, 2);
    if (variant == 0) {
        ov01_021F1620(ctx, ov01_022094DC, &a.mapPos, 1, &a, priority);
        return;
    }
    if (variant == 1) {
        ov01_021F1620(ctx, ov01_022094F0, &a.mapPos, 1, &a, priority);
        return;
    }
    if (variant == 2) {
        ov01_021F1620(ctx, ov01_02209504, &a.mapPos, 1, &a, priority);
        return;
    }
    ov01_021F1620(ctx, ov01_022094C8, &a.mapPos, 1, &a, priority);
}

BOOL ov01_0220335C(void *task, void *v) {
    u8 *p = v;
    Vec3 pos;
    Copy36 *src = sub_02068D98(task);
    *(u32 *)p = 0;
    *(Copy36 *)(p + 0x18) = *src;
    *(u32 *)(p + 4) = MapObject_GetSpriteID(*(void **)(p + 0x30));
    *(u32 *)(p + 8) = MapObject_GetID(*(void **)(p + 0x30));
    *(u32 *)(p + 0xc) = MapObject_GetMapID(*(void **)(p + 0x30));
    pos = *(Vec3 *)(p + 0x18);
    *(u32 *)(p + 0x14) = sub_0206121C(*(void **)(p + 0x24), &pos);
    sub_02068DA8(task, &pos);
    Field3dObject_SetPos(*(u8 **)(p + 0x2c) + 0x3c, &pos);
    Field3dObject_SetPos(*(u8 **)(p + 0x2c) + 0xb4, &pos);
    Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0xb4, FALSE);
    return TRUE;
}

void ov01_022033E0(void) {
}

void ov01_022033E4(void *task, void *v) {
    u8 *p = v;
    void *mapObj = *(void **)(p + 0x30);
    Vec3 pos, temp;
    if (!sub_0205F0F8(mapObj, *(u32 *)(p + 4), *(u32 *)(p + 8), *(u32 *)(p + 0xc))) {
        ov01_021F1640(task);
        return;
    }
    if (*(u32 *)(p + 0x14) == 0) {
        sub_02068DB8(task, &pos);
        temp = *(Vec3 *)(p + 0x18);
        *(u32 *)(p + 0x14) = sub_0206121C(*(void **)(p + 0x24), &temp);
        if (*(u32 *)(p + 0x14) == 1) {
            pos.y = temp.y;
            sub_02068DA8(task, &pos);
        }
    }
    switch (*(u32 *)p) {
    case 0:
        if (++*(s32 *)(p + 0x10) >= 2) {
            *(u32 *)p = 1;
        }
        break;
    case 1:
        Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0x3c, FALSE);
        Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0xb4, TRUE);
        sub_02069DC8(mapObj, 0);
        sub_0205F484(mapObj);
        Field3dModelAnimation_FrameSet(*(u8 **)(p + 0x2c) + 0x12c, 0);
        *(u32 *)p = 2;
    case 2:
        if (Field3dModelAnimation_FrameAdvanceAndCheck(*(u8 **)(p + 0x2c) + 0x12c, 1 << 12)) {
            ov01_021F1640(task);
        }
        break;
    }
}

void ov01_022034B8(void *task, void *v) {
    u8 pos[12];
    u8 *p = v;
    if (!sub_0205F0F8(*(void **)(p + 0x30), *(u32 *)(p + 4), *(u32 *)(p + 8), *(u32 *)(p + 0xc))) {
        ov01_021F1640(task);
        return;
    }
    sub_02068DB8(task, pos);
    Field3dObject_Draw(*(u8 **)(p + 0x2c) + 0x3c);
    Field3dObject_Draw(*(u8 **)(p + 0x2c) + 0xb4);
}

void ov01_022034F8(void *task, void *v) {
    u8 *p = v;
    Vec3 pos, temp;
    if (!sub_0205F0F8(*(void **)(p + 0x30), *(u32 *)(p + 4), *(u32 *)(p + 8), *(u32 *)(p + 0xc))) {
        ov01_021F1640(task);
        return;
    }
    if (*(u32 *)(p + 0x14) == 0) {
        sub_02068DB8(task, &pos);
        temp = *(Vec3 *)(p + 0x18);
        *(u32 *)(p + 0x14) = sub_0206121C(*(void **)(p + 0x24), &temp);
        if (*(u32 *)(p + 0x14) == 1) {
            pos.y = temp.y;
            sub_02068DA8(task, &pos);
        }
    }
    switch (*(u32 *)p) {
    case 0:
        Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0x3c, FALSE);
        Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0xb4, TRUE);
        Field3dModelAnimation_FrameSet(*(u8 **)(p + 0x2c) + 0x12c, 0);
        *(u32 *)p = 1;
    case 1:
        if (Field3dModelAnimation_FrameAdvanceAndCheck(*(u8 **)(p + 0x2c) + 0x12c, 1 << 12)) {
            ov01_021F1640(task);
        }
        break;
    }
}

void ov01_022035A4(void *task, void *v) {
    u8 pos[12];
    u8 *p = v;
    if (!sub_0205F0F8(*(void **)(p + 0x30), *(u32 *)(p + 4), *(u32 *)(p + 8), *(u32 *)(p + 0xc))) {
        ov01_021F1640(task);
        return;
    }
    sub_02068DB8(task, pos);
    Field3dObject_Draw(*(u8 **)(p + 0x2c) + 0xb4);
}

BOOL ov01_022035DC(void *task, void *v) {
    u8 *p = v;
    Vec3 pos;
    Copy36 *src = sub_02068D98(task);
    *(u32 *)p = 0;
    *(Copy36 *)(p + 0x18) = *src;
    *(u32 *)(p + 4) = MapObject_GetSpriteID(*(void **)(p + 0x30));
    *(u32 *)(p + 8) = MapObject_GetID(*(void **)(p + 0x30));
    *(u32 *)(p + 0xc) = MapObject_GetMapID(*(void **)(p + 0x30));
    pos = *(Vec3 *)(p + 0x18);
    *(u32 *)(p + 0x14) = sub_0206121C(*(void **)(p + 0x24), &pos);
    sub_02068DA8(task, &pos);
    Field3dObject_SetPos(*(u8 **)(p + 0x2c) + 0x3c, &pos);
    Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0x3c, FALSE);
    return TRUE;
}
