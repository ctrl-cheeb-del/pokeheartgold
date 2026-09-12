#include "overlay49_object_controls_r7_private.h"
void ov49_02258DB4(R7Holder *p, UnkStruct_ov44_02232914 pos) {
    if (p->unk0 == NULL) {
        GF_AssertFail();
    }
    ov42_0222839C(p->unk0, pos);
    ov42_022283AC(p->unk0, pos);
    ov42_022281F8(p->unk0, 5, 0);
}
void ov49_02258E04(R7Holder *p, UnkStruct_ov44_02232914 pos, s32 value) {
    ov49_02258DB4(p, pos);
    ov42_022281F8(p->unk0, 6, value);
}
