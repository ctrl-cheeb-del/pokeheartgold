#include "field_follow_shadow_internal.h"

void ov01_021FD8E8(LocalMapObject *object, int a1) {
    FieldEffectRendererArgs args;
    VecFx32 pos;
    FieldSystem *fieldSystem = ov01_021F146C(object);
    args.unk0 = (u32)fieldSystem;
    args.unk4 = (FieldSystem *)ov01_021F1450(fieldSystem, 0);
    args.unk8 = object;
    MapObject_CopyPositionVector(object, &pos);
    ov01_021F1620(fieldSystem, &ov01_02208EDC, &pos, a1, (UnkOv01_021FFF5C *)&args, MapObject_GetPriorityPlusValue(object, 2));
}

void ov01_021FD92C(void *a0, FollowShadowWork *work) {
    VecFx32 pos;
    LocalMapObject *object = work->unk1C;
    if (!sub_0205F0F8(object, work->unk0, work->unk4, work->unk8)) {
        ov01_021F1640((int)a0);
        return;
    }
    work->unkC = 0;
    if (MapObject_TestFlagsBits(object, (MapObjectFlagBits)0x00100200) == TRUE) {
        work->unkC = 1;
        return;
    }
    MapObject_CopyPositionVector(object, &pos);
    sub_02068DA8(a0, &pos);
}
