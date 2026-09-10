#include "field_model_transform_internal.h"

BOOL sub_02036438(int slot) {
    int bad;
    int stride;
    int count;
    int i;
    int entryOffset;
    int rowOffset;
    int slotOffset;
    bad = 0;
    stride = sub_0203772C((u16)sub_0203993C());
    count = sub_02033FC4((u16)sub_0203993C()) + 1;
    i = bad;
    if (count > 0) {
        entryOffset = i;
        rowOffset = entryOffset;
        slotOffset = slot * 0xC0;
        do {
            u8 *ctx = *(u8 **)(_021D4140 + 8);
            sub_02033C28(ctx + 0x4B0 + entryOffset);
            if (sub_020373B4((u16)i)) {
                ctx = *(u8 **)(_021D4140 + 8);
                ctx[0x80 + slotOffset + rowOffset] = 14;
            } else {
                ctx = *(u8 **)(_021D4140 + 8);
                bad++;
                ctx[0x80 + slotOffset + rowOffset] = 0xFF;
                goto update;
            }
            ctx = *(u8 **)(_021D4140 + 8);
            sub_02033B4C(ctx + 0x4B0 + entryOffset, ctx + 0x80 + slotOffset + rowOffset, stride);
            ctx = *(u8 **)(_021D4140 + 8);
            if (ctx[0x80 + slotOffset + rowOffset] == 14) {
                bad++;
            }
update:
            entryOffset += 12;
            rowOffset += stride;
            i++;
        } while (i < count);
    }
    if (bad == count) {
        return FALSE;
    }
    return TRUE;
}
