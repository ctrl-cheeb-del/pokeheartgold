#include "to47_overlay49_position_adjust_r52_private.h"

void ov49_0225EE4C(void *context, int kind)
{
    Ov49PositionR52 position;

    GF_ASSERT(kind == 0x5c || kind == 0x5d);
    position = ov49_0225D1EC(context);
    position.x += ov49_02269A74[kind - 0x5c];
    position.y -= 10;
    ov49_0225D1C4(context, position);
}
