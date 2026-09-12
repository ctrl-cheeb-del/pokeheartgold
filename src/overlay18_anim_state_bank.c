#include "overlay18_anim_state_bank_private.h"

BOOL ov18_021F51CC(void *p);
BOOL ov18_021F5238(void *p);
BOOL ov18_021F52A4(void *p);
BOOL ov18_021F5310(void *p);
BOOL ov18_021F537C(void *p);
BOOL ov18_021F53E8(void *p);
BOOL ov18_021F5454(void *p);
void ov18_021F54C0(void *p, s16 a1, s16 a2);
void ov18_021F555C(void *p);
BOOL ov18_021F55D8(void *p);
BOOL ov18_021F5638(void *p);
BOOL ov18_021F56DC(void *p);
BOOL ov18_021F57B4(void *p);
BOOL ov18_021F588C(void *p);
BOOL ov18_021F5964(void *p);
BOOL ov18_021F5A3C(void *p);
BOOL ov18_021F5B14(void *p);
BOOL ov18_021F5BEC(void *p);
BOOL ov18_021F5CC4(void *p);



BOOL ov18_021F51CC(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x100, -32, -224);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5238(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x120, -32, -256);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F52A4(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x140, -32, -288);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5310(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x160, -32, -320);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F537C(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x180, -32, -352);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F53E8(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x1C0, -64, -320);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5454(void *p) {
    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5198(p, 0x200, -64, -384);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        ov18_021F5000(R22_ROOT(p), ManagedSprite_GetRotation(R22_SPRITE(p)));
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_S32(p, 0xC) == R22_S32(p, 0x14)) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

void ov18_021F54C0(void *p, s16 a1, s16 a2) {
    Position18 a;
    Position18 b;

    R22_S16(p, 0x18) = a1;
    R22_S16(p, 0x1A) = a2;
    ov18_021F12C8(R22_ROOT(p), 2, &a.x, &a.y, 1);
    ov18_021F12C8(R22_ROOT(p), 4, &b.x, &b.y, 1);
    if (a.y < b.y) {
        R22_U16(p, 0x1C) = 2;
        R22_U16(p, 0x1E) = 8;
        ov18_021F11C0(R22_ROOT(p), 3, 1);
        ov18_021F1294(R22_ROOT(p), 3, a.x, a.y + 192, 2);
    } else {
        R22_U16(p, 0x1C) = 4;
        R22_U16(p, 0x1E) = 9;
        ov18_021F11C0(R22_ROOT(p), 5, 1);
        ov18_021F1294(R22_ROOT(p), 5, b.x, b.y + 192, 2);
    }
}

void ov18_021F555C(void *p) {
    Position18 pos;

    ov18_021F12C8(R22_ROOT(p), R22_U16(p, 0x1C), &pos.x, &pos.y, 1);
    pos.y = pos.y + R22_S16(p, 0x18);
    ov18_021F1294(R22_ROOT(p), R22_U16(p, 0x1C), pos.x, pos.y, 1);
    ov18_021F12C8(R22_ROOT(p), R22_U16(p, 0x1C) + 1, &pos.x, &pos.y, 2);
    pos.y = pos.y + R22_S16(p, 0x18);
    ov18_021F1294(R22_ROOT(p), R22_U16(p, 0x1C) + 1, pos.x, pos.y, 2);
    R22_S16(p, 0x18) = R22_S16(p, 0x18) + R22_S16(p, 0x1A);
}

BOOL ov18_021F55D8(void *p) {
    Position18 a;
    Position18 b;

    ov18_021F555C(p);
    ov18_021F12C8(R22_ROOT(p), R22_U16(p, 0x1C), &a.x, &a.y, 1);
    ov18_021F12C8(R22_ROOT(p), R22_U16(p, 0x1E), &b.x, &b.y, 1);
    if (a.y >= b.y - 16) {
        ov18_021F1294(R22_ROOT(p), R22_U16(p, 0x1C), b.x, b.y - 16, 1);
        return FALSE;
    }
    return TRUE;
}

BOOL ov18_021F5638(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EB);
        ov18_021F5180(p, 0x300, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            return FALSE;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            return FALSE;
        }
    }
    return TRUE;
}

BOOL ov18_021F56DC(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EC);
        ov18_021F5180(p, 0x300, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -4, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F57B4(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EC);
        ov18_021F5180(p, 0x400, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -8, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F588C(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EC);
        ov18_021F5180(p, 0x400, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -12, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5964(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8ED);
        ov18_021F5180(p, 0x500, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -14, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5A3C(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8ED);
        ov18_021F5180(p, 0x500, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -18, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5B14(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8ED);
        ov18_021F5180(p, 0x600, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -21, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5BEC(void *p) {
    u32 rotation;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8ED);
        ov18_021F5180(p, 0x700, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -24, 1);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov18_021F5CC4(void *p) {
    u32 rotation;
    Position18 pos;

    switch (R22_U8(p, 0xB)) {
    case 0:
        PlaySE(0x8EE);
        ov18_021F5180(p, 0x800, 0);
        R22_U8(p, 0xB)++;
    case 1:
        ManagedSprite_OffsetAffineZRotation(R22_SPRITE(p), R22_S32(p, 0xC));
        rotation = ManagedSprite_GetRotation(R22_SPRITE(p));
        ov18_021F5000(R22_ROOT(p), rotation);
        R22_S32(p, 0xC) += R22_S32(p, 0x10);
        if (R22_U8(p, 0xA) == 0) {
            if (rotation > 0xF600) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xF600);
            ov18_021F5000(R22_ROOT(p), 0xF600);
            R22_U8(p, 0xB)++;
        } else {
            if (rotation < 0xA00) {
                break;
            }
            ManagedSprite_SetAffineZRotation(R22_SPRITE(p), 0xA00);
            ov18_021F5000(R22_ROOT(p), 0xA00);
            R22_U8(p, 0xB)++;
        }
    case 2:
        ov18_021F54C0(p, -24, 0);
        R22_U8(p, 0xB)++;
    case 3:
        if (ov18_021F55D8(p) == 0) {
            return FALSE;
        }
        ov18_021F12C8(R22_ROOT(p), R22_U16(p, 0x1C), &pos.x, &pos.y, 1);
        if (pos.y <= -256) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}
