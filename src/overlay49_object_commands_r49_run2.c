#include "overlay49_object_commands_r49_private.h"

BOOL ov49_0225E9D0(void *p, s32 x, s32 y) {
    s16 yy = (s16)(y * 16);
    Ov49Vec2s pos = ov49_0225D1EC(p);

    return pos.x == (s16)(x * 16) && pos.y == yy;
}
