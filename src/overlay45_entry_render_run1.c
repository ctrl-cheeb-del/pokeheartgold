#include "overlay45_entry_render_private.h"

void ov45_02230B64(Overlay45RenderEntry *entry) {
    u32 index = ov42_02228188(entry->ctx, 6);
    u32 animation = ov45_022309C4(1, index);
    sub_02023EE0(entry->sprite, animation);
    sub_02023F40(entry->sprite, 0);
}

void ov45_02230B8C(Overlay45RenderEntry *entry) {
    u32 index = ov42_02228188(entry->ctx, 6);
    u32 animation = ov45_022309C4(1, index);
    u16 x = ov42_02228188(entry->ctx, 9);
    u16 y = ov42_02228188(entry->ctx, 8);
    s32 offset = ov45_022309D0(x, y, 8);
    sub_02023EE0(entry->sprite, animation);
    if (entry->lastAnim == animation) {
        sub_02023F40(entry->sprite, 0);
        sub_02023F04(entry->sprite, offset + entry->baseOffset);
    } else {
        sub_02023F40(entry->sprite, 0);
        sub_02023F04(entry->sprite, offset);
    }
}

void ov45_02230BFC(Overlay45RenderEntry *entry) {
    u16 value = ov42_02228188(entry->ctx, 8);
    if (value < 4) {
        sub_02023F40(entry->sprite, 0x4000);
        return;
    }
    sub_02023EE0(entry->sprite, ov45_022309C4(1, ov42_02228188(entry->ctx, 6)));
    sub_02023F40(entry->sprite, 0);
}

void ov45_02230C40(Overlay45RenderEntry *entry) {
    u32 index = ov42_02228188(entry->ctx, 6);
    u32 animation = ov45_022309C4(0, index);
    u16 x = ov42_02228188(entry->ctx, 9);
    u16 y = ov42_02228188(entry->ctx, 8);
    s32 offset = ov45_022309D0(x, y, 4);
    sub_02023EE0(entry->sprite, animation);
    if (entry->lastAnim == animation) {
        sub_02023F40(entry->sprite, 0);
        sub_02023F04(entry->sprite, offset + entry->baseOffset);
    } else {
        sub_02023F40(entry->sprite, 0);
        sub_02023F04(entry->sprite, offset);
    }
}

void ov45_02230CB0(Overlay45RenderEntry *entry) {
    if (entry->state == 0 && entry->active == 1) {
        ov45_02254F1C[entry->handler](entry);
    }
}
