#include "overlay92_motion_solver_r15_private.h"

extern void ov92_02263108(float *dst, const float *a, const float *b);
extern void ov92_022632E8(void *a, const void *b);
extern void ov92_022630F8(void *a, const void *b);
extern void ov92_02263824(const void *a, void *b);
extern float _f_lltof(s64 value);

int ov92_02260628(void *arg) {
    Ov92R15Work *work = arg;
    float x = work->x;
    Vec4f vector;
    float y = work->y;
    float magnitude;
    float scaled;
    fx32 angle;

    work->x = x - work->deltaX;
    work->y = work->y - work->deltaY;
    work->counter--;

    magnitude = x * x + y * y;
    if (magnitude > 0.0f) {
        scaled = 4096.0f * magnitude + 0.5f;
    } else {
        scaled = 4096.0f * magnitude - 0.5f;
    }
    angle = FX_Sqrt((fx32)scaled);
    magnitude = (float)angle / 4096.0f;
    if (magnitude != 0.0) {
        s64 sinValue = FX_SinFx64c(angle);
        s64 cosValue = FX_CosFx64c(angle);
        float ratio = _f_lltof(sinValue) / 4294967296.0f;
        float cosine = _f_lltof(cosValue) / 4294967296.0f;
        ratio /= magnitude;
        vector.v[0] = cosine;
        vector.v[1] = y * ratio;
        vector.v[2] = x * ratio;
        vector.v[3] = 0.0f;
        ov92_02263108(PTR_AT(arg, 0x190), vector.v, PTR_AT(arg, 0x1a0));
        ov92_022632E8(PTR_AT(arg, 0x150), PTR_AT(arg, 0x190));
        ov92_022630F8(PTR_AT(arg, 0x1a0), PTR_AT(arg, 0x190));
        ov92_02263824(PTR_AT(arg, 0x150), PTR_AT(arg, 0x1b0));
        return 1;
    }
    return 0;
}
