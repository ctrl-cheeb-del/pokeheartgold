#include "global.h"

#define F32_AT(p, o) (*(float *)((u8 *)(p) + (o)))
#define S32_AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) ((void *)((u8 *)(p) + (o)))

typedef struct Vec4f {
    float v[4];
} Vec4f;

extern void ov92_02263108(float *, const float *, const float *);
extern void ov92_022632E8(void *, const void *);
extern void ov92_022630F8(void *, const void *);
extern void ov92_02263824(const void *, void *);
extern void *ov92_0226325C(void *);
extern void ov92_022632B4(void *, const void *, void *);
extern float _f_lltof(s64);
extern fx32 FX_Sqrt(fx32);
extern fx64c FX_SinFx64c(fx32);
extern fx64c FX_CosFx64c(fx32);

int ov92_02260428(void *, s32, s32, s32, s32, float, int);

int ov92_02260428(void *arg, s32 x, s32 y, s32 targetX, s32 targetY, float scale, int saveVelocity) {
    u8 *work = arg;
    float dx = (float)((double)(x - targetX) * 0.0051953125 * (double)scale);
    float dy = (float)((double)(y - targetY) * 0.005208333333333333 * (double)scale);
    float magnitude;
    float scaled;
    fx32 angle;
    Vec4f vector;
    void *matrix;
    Vec4f old;

    if (saveVelocity != 0) {
        F32_AT(work, 0x1fc) = dx;
        F32_AT(work, 0x200) = dy;
        S32_AT(work, 0x1f8) = 8;
        F32_AT(work, 0x204) = F32_AT(work, 0x1fc) / (float)S32_AT(work, 0x1f8);
        F32_AT(work, 0x208) = F32_AT(work, 0x200) / (float)S32_AT(work, 0x1f8);
    }

    magnitude = dx * dx + dy * dy;
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
        vector.v[1] = dy * ratio;
        vector.v[2] = dx * ratio;
        vector.v[3] = 0.0f;
        ov92_02263108(PTR_AT(work, 0x190), vector.v, PTR_AT(work, 0x1a0));
        ov92_022632E8(PTR_AT(work, 0x150), PTR_AT(work, 0x190));
        ov92_022630F8(PTR_AT(work, 0x1a0), PTR_AT(work, 0x190));
        ov92_02263824(PTR_AT(work, 0x150), PTR_AT(work, 0x1b0));
        matrix = ov92_0226325C(PTR_AT(work, 0x190));
        old = *(Vec4f *)PTR_AT(work, 0x190);
        ov92_022632B4(PTR_AT(work, 0x190), old.v, matrix);
        return 1;
    }
    return 0;
}
