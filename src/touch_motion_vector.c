#include "touch_motion_vector_internal.h"

BOOL sub_020872DC(s16 x, s16 y, float fx, float fy, float *outX, float *outY, float speed, s16 minDist) {
    Vec2f v;
    Vec2f d;
    Vec2f o;
    float s;
    float dist;

    o.x = 0.0f;
    o.y = 0.0f;
    d.x = (float)x - fx;
    d.y = (float)y - fy;
    v.x = 0.0f;
    v.y = 0.0f;

    s = d.x * d.x + d.y * d.y;
    dist = (float)FX_Sqrt((fx32)(s > 0.0f ? 0.5f + 4096.0f * s : 4096.0f * s - 0.5f)) / 4096.0f;
    if (dist < speed || (float)minDist > dist || dist == 0.0f) {
        return FALSE;
    }
    v.x = d.x * speed / dist;
    v.y = d.y * speed / dist;
    *outX = v.x + o.x;
    *outY = v.y + o.y;
    return TRUE;
}
