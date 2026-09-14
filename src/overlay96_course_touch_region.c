#include "global.h"

#include "overlay96_course_touch_region_private.h"

typedef struct Ov96R93Point {
    fx32 x;
    fx32 y;
    fx32 z;
} Ov96R93Point;

extern const s16 ov96_0221CDD8[][2];

BOOL ov96_0220A910(Ov96R93State *state) {
    Ov96R93Point points[4];
    u32 touchX;
    u32 touchY;
    s16 center[2];
    fx32 fixedX;
    fx32 fixedY;
    int i;
    fx32 edge1;
    fx32 edge2;
    float converted;

    if (state == NULL) {
        GF_AssertFail();
    }
    if (state->mode == 1) {
        return 0;
    }
    if (state->active == 0) {
        GF_AssertFail();
    }
    ov96_0220B148(PTR((u8 *)state + (state->active << 2), 0x150), &center[1], &center[0]);
    System_GetTouchNewCoords(&touchX, &touchY);
    if (touchY >= center[0] - 18 && touchY <= center[0] + 12) {
        if (touchX != 0) {
            converted = (float)(touchX << 12) + 0.5f;
        } else {
            converted = (float)(touchX << 12) - 0.5f;
        }
        fixedX = (s32)converted;
        if (touchY != 0) {
            converted = (float)(touchY << 12) + 0.5f;
        } else {
            converted = (float)(touchY << 12) - 0.5f;
        }
        fixedY = (s32)converted;
        for (i = 0; i < 4; i++) {
            if (center[1] + ov96_0221CDD8[i][0] > 0) {
                converted = (float)((center[1] + ov96_0221CDD8[i][0]) << 12) + 0.5f;
            } else {
                converted = (float)((center[1] + ov96_0221CDD8[i][0]) << 12) - 0.5f;
            }
            points[i].x = (s32)converted;
            if (center[0] + ov96_0221CDD8[i][1] > 0) {
                converted = (float)((center[0] + ov96_0221CDD8[i][1]) << 12) + 0.5f;
            } else {
                converted = (float)((center[0] + ov96_0221CDD8[i][1]) << 12) - 0.5f;
            }
            points[i].y = (s32)converted;
        }
        edge1 = FX_Div(FX_Mul(points[1].y - points[0].y, fixedX - points[0].x), points[1].x - points[0].x);
        edge1 += points[0].y;
        edge2 = FX_Div(FX_Mul(points[3].y - points[2].y, fixedX - points[2].x), points[3].x - points[2].x);
        edge2 += points[2].y;
        if ((fixedX >= points[1].x && fixedX <= points[2].x) || (fixedY >= edge1 && fixedX >= points[0].x && fixedX <= points[1].x) || (fixedY <= edge2 && fixedX >= points[2].x && fixedX <= points[3].x)) {
            return TRUE;
        }
    }
    return FALSE;
}
