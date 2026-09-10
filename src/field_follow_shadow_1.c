#include "field_follow_shadow_internal.h"

FollowShadow *ov01_021FD41C(FieldSystem *fieldSystem) {
    FollowShadow *work = (FollowShadow *)ov01_021F1430(fieldSystem, sizeof(FollowShadow), 0, 0);
    work->unk20 = fieldSystem;
    ov01_021FD5CC(work);
    ov01_021FD458(work);
    return work;
}

void ov01_021FD440(FollowShadow *work) {
    ov01_021FD47C(work);
    ov01_021FD60C(work);
    ov01_021F1448(work);
}
