#include "to45_overlay41_r50_r4_geometry_private.h"

void ov41_02249BAC(Ov41R50Object *object, s32 *out0, s32 *out1, s32 *out2, s32 *out3) {
    u8 values[4];

    if (object->mode < 3) {
        ov41_02246020(object->data, out0, out2);
        *out1 = *out0;
        *out3 = *out2;
    } else {
        ov41_02249888(object->data, values);
        *out0 = values[0];
        *out1 = values[1];
        *out2 = values[2];
        *out3 = values[3];
    }
}

void ov41_02249BE8(Ov41R50Node *head, s32 delta0, s32 delta1) {
    Ov41R50Node *node = head->next;

    while (node != head) {
        s32 value0;
        s32 value1;

        ov41_02249B44(node, &value0, &value1);
        value0 += delta0;
        value1 += delta1;
        ov41_02249AF4(node, value0, value1);
        node = node->next;
    }
}

void ov41_02249C20(Ov41R50Node *node, s32 *out0, s32 *out1, s32 *out2, s32 *out3) {
    s32 a0;
    s32 a1;
    s32 b0;
    s32 b1;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;

    ov41_02249B94(node, &a0, &a1);
    ov41_02249B44(node, &b0, &b1);
    ov41_02249BAC((Ov41R50Object *)node, &c0, &c2, &c1, &c3);
    *out0 = b1 + c1;
    *out1 = b1 + a1 - c3;
    *out2 = b0 + c0;
    *out3 = b0 + a0 - c2;
}

void ov41_02249C7C(Ov41R50Destination *destination, const Ov41R50Source *source) {
    destination->unk00 = source->unk00;
    destination->unk0C = source->unk14 / 8;
    destination->unk10 = source->unk18 / 8;
    destination->unk1C = source->unk1C;
    destination->unk20 = source->unk24;
    destination->unk24 = source->unk20;
    destination->unk28 = source->unk28;
    destination->unk04 = source->unk04;
    destination->unk08 = source->unk10;
    ov41_02249E60(source, &destination->unk14, &destination->unk18);
}
