#include "overlay_01_022031C0_internal.h"

void ov01_02203654(void *task, void *v) {
    u8 *p = v;
    void *owner = *(void **)(p + 0x30);
    Vec3 pos, temp, scale;
    void *mapObj, *model;
    u32 a, b, dir;
    if (!sub_0205F0F8(owner, *(u32 *)(p + 4), *(u32 *)(p + 8), *(u32 *)(p + 0xc))) {
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
        mapObj = FollowMon_GetMapObject(*(void **)(p + 0x24));
        model = ov01_021F771C(*(void **)((u8 *)*(void **)(p + 0x24) + 0x3c));
        a = sub_02023FB0(model);
        b = sub_02023FB0(model);
        GF_CreateNewVramTransferTask(1, (u16)b << 3, ov01_02209B18, ((a & 0xFFFF0000) >> 16) << 3);
        if (ov01_022055DC(mapObj)) {
            dir = (u8)MapObject_GetFacingDirection(mapObj);
            MapObject_CopyPositionVector(mapObj, (Vec3 *)(p + 0x48));
            ov01_022039BC(dir, p + 0x48, (void **)(p + 0x3c));
            *(s32 *)(p + 0x40) = **(s32 **)(p + 0x3c);
            *(s32 *)(p + 0x44) = ov01_022039E0(dir);
        } else {
            *(void **)(p + 0x3c) = NULL;
        }
        ++*(u32 *)p;
    case 1:
        scale = ov01_022094BC;
        ++*(s32 *)(p + 0x10);
        scale.x = (1 << 12) / *(s32 *)(p + 0x10);
        scale.y = (1 << 12) / *(s32 *)(p + 0x10);
        sub_02023E78(ov01_021F771C(*(void **)((u8 *)*(void **)(p + 0x24) + 0x3c)), &scale);
        if (*(s32 **)(p + 0x3c)) {
            mapObj = FollowMon_GetMapObject(*(void **)(p + 0x24));
            {
                s32 count = *(s32 *)(p + 0x10);
                s32 delta = *(s32 *)(p + 0x44);
                **(s32 **)(p + 0x3c) = ((count * (delta << 12)) / 4) + *(s32 *)(p + 0x40);
            }
            MapObject_SetPositionVector(mapObj, (Vec3 *)(p + 0x48));
        }
        if (*(s32 *)(p + 0x10) >= 4) {
            ++*(u32 *)p;
            Field3dObject_SetActiveFlag(*(u8 **)(p + 0x2c) + 0x3c, TRUE);
            MapObject_SetVisible(owner, TRUE);
            *(u32 *)(p + 0x10) = 0;
            return;
        }
        break;
    case 2:
        if (++*(s32 *)(p + 0x10) >= 4) {
            ov01_021F1640(task);
        }
        break;
    }
}
