#include "to45_overlay108_r5_private.h"

u32 ov108_021E62B4(SafariAreaCustomizer *s) {
    u32 buttons = gSystem.buttons;
    u8 old;
    u8 column;
    u8 row;

    if (buttons & 2) {
        PlaySE(0x5DC);
        s->unk0C = 6;
        return 4;
    }
    if (buttons & 1) {
        if (s->unk184DF >= 6) {
            PlaySE(0x5DC);
            s->unk0C = 6;
            return 4;
        }
        PlaySE(0x5DC);
        ov108_021E6A58(s);
        return 1;
    }
    if (!(buttons & 0xF0)) {
        return 0;
    }

    old = s->unk184DF;
    column = old % 3;
    row = old / 3;
    if (row < 2) {
        if (buttons & 0x10) {
            column = (column + 1) % 3;
        } else if (buttons & 0x20) {
            column = (column + 2) % 3;
        }
    }
    if (buttons & 0x40) {
        row = (row + 2) % 3;
    } else if (buttons & 0x80) {
        row = (row + 1) % 3;
    }
    s->unk184DF = column + row * 3;
    if (row < 2 || (gSystem.buttons & 0xC0)) {
        PlaySE(0x5E5);
    }
    ov108_021E78F4(s, 0, s->unk184DF);
    ov108_021E7CD8(s, s->unk184DF);
    return 0;
}

u32 ov108_021E63B8(SafariAreaCustomizer *s) {
    s32 result = TouchscreenHitbox_FindRectAtTouchNew(ov108_021EA760);

    if (result == -1) {
        return 0;
    }
    if (result == 6) {
        u16 value = 0xFFFE;
        if (!DoesPixelAtScreenXYMatchPtrVal(s->bgConfig, 3, gSystem.touchX, gSystem.touchY, &value)) {
            return 0;
        }
        PlaySE(0x5DC);
        s->unk0C = 6;
        return 4;
    }
    s->unk184DF = result;
    s->unk184E0 = 0;
    ov108_021E78F4(s, 0, s->unk184DF);
    ov108_021E7CD8(s, s->unk184DF);
    PlaySE(0x5DC);
    ov108_021E6A58(s);
    return 1;
}

u32 ov108_021E6450(SafariAreaCustomizer *s) {
    u8 areaId;

    PlaySE(0x5DC);
    if (s->unk184E3 != 0) {
        ov108_021E6B00(s);
        return 1;
    }
    areaId = s->unk184E0 + s->unk184DE * 6;
    s->unk184E8 = 1;
    SafariZone_InitAreaInSet(s->areas, s->unk184DF, areaId);
    ov108_021E7BB4(s, s->unk184DF, s->areas[s->unk184DF][0]);
    ov108_021E79A8(s, 1, 0, 0);
    return 2;
}

u32 ov108_021E64C0(SafariAreaCustomizer *s) {
    u8 old = s->unk184E0;
    u32 buttons = gSystem.buttons;
    u8 column;
    u8 row;
    u32 changed;

    if (buttons & 2) {
        PlaySE(0x5DC);
        return 2;
    }
    if (buttons & 1) {
        if (old >= 6) {
            PlaySE(0x5DC);
            return 2;
        }
        if (old + s->unk184DE * 6 == s->areas[s->unk184DF][0]) {
            return 0;
        }
        return ov108_021E6450(s);
    }
    if (!(buttons & 0xF0)) {
        return 0;
    }

    column = old % 3;
    row = old / 3;
    changed = 0;
    if ((buttons & 0x10) && row < 2) {
        if (column == 2) {
            if (row == 0) {
                row ^= 1;
                column = (column + 1) % 3;
            } else if (row < 2 && s->unk184DE < 1) {
                changed = 1;
                s->unk184E2 &= ~2;
                row ^= changed;
                column = (column + 1) % 3;
            }
        } else {
            column = (column + 1) % 3;
        }
    } else if ((buttons & 0x20) && row < 2) {
        if (column == 0) {
            if (row == 1) {
                row ^= 1;
                column = (column + 2) % 3;
            } else if (row < 2 && s->unk184DE != 0) {
                changed = 1;
                s->unk184E2 |= 2;
                row ^= changed;
                column = (column + 2) % 3;
            }
        } else {
            column = (column + 2) % 3;
        }
    } else if (buttons & 0x40) {
        row = (row + 2) % 3;
    } else if (buttons & 0x80) {
        row = (row + 1) % 3;
    }
    s->unk184E0 = column + row * 3;
    ov108_021E78F4(s, 1, s->unk184E0);
    if (changed != 0) {
        PlaySE(0x5E1);
        ov108_021E78C0(s, 1, 0, 0);
        return 3;
    }
    if (old != s->unk184E0) {
        PlaySE(0x5E5);
    }
    ov108_021E7EB0(s);
    return 0;
}

u32 ov108_021E66AC(SafariAreaCustomizer *s) {
    s32 result = TouchscreenHitbox_FindRectAtTouchNew(ov108_021EA7D0);

    if (result == -1) {
        return 0;
    }
    switch (result) {
    case 6: {
        u16 value = 0xFFFE;
        if (!DoesPixelAtScreenXYMatchPtrVal(s->bgConfig, 3, gSystem.touchX, gSystem.touchY, &value)) {
            return 0;
        }
        s->unk184E0 = 6;
        PlaySE(0x5DC);
        return 2;
    }
    case 7:
        if (s->unk184DE == 0) {
            return 0;
        }
        s->unk184E2 |= 2;
        s->unk184E0 = 5;
        ov108_021E78C0(s, 1, 0, 0);
        Sprite_SetAnimActiveFlag(s->sprites[4], TRUE);
        Sprite_ResetAnimCtrlState(s->sprites[4]);
        PlaySE(0x5E1);
        return 3;
    case 8:
        if (s->unk184DE == 1) {
            return 0;
        }
        s->unk184E2 &= ~2;
        s->unk184E0 = 0;
        ov108_021E78C0(s, 1, 0, 0);
        Sprite_SetAnimActiveFlag(s->sprites[5], TRUE);
        Sprite_ResetAnimCtrlState(s->sprites[5]);
        PlaySE(0x5E1);
        return 3;
    default:
        s->unk184E0 = result;
        ov108_021E78F4(s, 1, s->unk184E0);
        ov108_021E7EB0(s);
        if (s->unk184E0 + s->unk184DE * 6 == s->areas[s->unk184DF][0]) {
            return 0;
        }
        return ov108_021E6450(s);
    }
}
