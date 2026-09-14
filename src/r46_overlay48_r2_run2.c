#include "r46_overlay48_r2_private.h"

u32 ov48_022591D8(void *work) {
    VecFx32 center;
    VecFx32 point;
    s32 yMax;
    s32 wrappedMin;
    s32 wrappedMax;
    u32 count;
    u32 bestIndex;
    s32 xMin;
    s32 xMax;
    u32 i;
    u32 kind;
    s32 yMin;
    s32 range;
    u32 distance;
    u32 bestDistance;

    count = ov48_02259BBC(ADD(work, 0x224));
    ov48_022598CC(ADD(work, 0x178), &center);

    xMin = (s16)(center.x - 0x80);
    xMax = (s16)(center.x + 0x80);
    yMin = (s16)(center.y - 0x80);
    yMax = (s16)(center.y + 0x80);

    range = yMax - yMin;
    if (range < 0) {
        range = -range;
    }
    if (range > 0x100) {
        yMin = (s16)center.y;
        yMax = yMin;
        if (yMin > 0) {
            wrappedMin = yMin - 0x10000;
            wrappedMax = wrappedMin;
        } else {
            wrappedMin = yMin + 0x10000;
            wrappedMax = wrappedMin;
        }
        yMax += 0x80;
        wrappedMin -= 0x80;
        wrappedMax += 0x80;
        yMin -= 0x80;
    } else {
        wrappedMin = yMin;
        wrappedMax = yMax;
    }

    bestDistance = 0x100;
    bestIndex = count;
    for (i = 0; i < count; i++) {
        ov48_02259B3C(ADD(work, 0x224), &point, i);
        kind = ov48_02259B68(ADD(work, 0x224), i);
        if (point.x > xMin && point.x < xMax && ((point.y > yMin && point.y < yMax) || (point.y > wrappedMin && point.y < wrappedMax)) && kind != 3) {
            ov48_02258F0C(&center);
            ov48_02258F0C(&point);
            distance = ov48_022592E0(&center, &point);
            if (distance < bestDistance) {
                bestDistance = distance;
                bestIndex = i;
            }
        }
    }
    return bestIndex;
}
