#include "overlay49_object_controls_r7_private.h"
void ov49_02258E60(R7Holder *p, s32 value) {
    if (p->unk0 == NULL) {
        GF_AssertFail();
    }
    ov42_02228188(p->unk0, value);
}
void ov49_02258E7C(void *ctx, R7Holder *p, s32 a2, s32 a3) {
    if (ov42_02228188(p->unk0, 5) != 0) {
        GF_AssertFail();
    }
    ov49_0225927C(ctx, a2, a3, ov42_02228188(p->unk0, 4));
}
void ov49_02258EAC(R7Holder *dst, R7Holder *src, u16 value, u8 kind) {
    UnkStruct_ov42_02228EB0 data;
    data.unk0 = ov42_022282DC(src->unk0);
    data.unk4 = value;
    data.unk6 = kind;
    data.unk7 = ov42_02228188(src->unk0, 4);
    ov42_02228068((UnkStruct_ov42_022280A8 *)dst->unk0, &data);
}
