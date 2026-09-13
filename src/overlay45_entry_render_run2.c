#include "overlay45_entry_render_private.h"

void ov45_02230D20(Overlay45RenderEntry *entry) {
    if (entry->timer == 0) {
        ov42_02228188(entry->ctx, 6);
        sub_02023EE0(entry->sprite, ov45_022309C4(1, ov42_02228188(entry->ctx, 6)));
        sub_02023F40(entry->sprite, 0x4000);
        entry->timer++;
    }
}

void ov45_02230D5C(Overlay45RenderEntry *entry) {
    if (entry->timer == 0) {
        sub_02023EE0(entry->sprite, ov45_022309C4(1, ov42_02228188(entry->ctx, 6)));
        sub_02023F40(entry->sprite, 0x4000);
    } else if (entry->timer == 4) {
        sub_02023EE0(entry->sprite, ov45_022309C4(1, ov42_02228188(entry->ctx, 6)));
        sub_02023F40(entry->sprite, 0xC000);
    }
    entry->timer = (entry->timer + 1) % 8;
}

BOOL ov45_02230DC4(u32 value) {
    switch (value) {
    case 2:
    case 3:
    case 5:
    case 6:
    case 10:
    case 11:
        return TRUE;
    default:
        return FALSE;
    }
}

void ov45_02230DF4(Overlay45RenderEntry *entry) {
    if (ov45_02230AA4(entry)) {
        if (ov45_02230E78(entry->sprite) == 0) {
            entry->type = 1;
        } else {
            entry->type = 0;
        }
        ov45_02230E28(entry);
    }
}

void ov45_02230E28(Overlay45RenderEntry *entry) {
    if (entry->type == 0 && entry->top == 1) {
        sub_02023EA4(entry->sprite, TRUE);
        sub_020182A0(entry->render, TRUE);
    } else {
        sub_02023EA4(entry->sprite, FALSE);
        sub_020182A0(entry->render, FALSE);
    }
}

void ov45_02230E64(void *sprite, Overlay45RenderEntry *entry) {
    void *model = sub_02023FDC(sprite);
    NNS_G3dMdlSetMdlLightEnableFlagAll(model, entry->lightFlags);
}
