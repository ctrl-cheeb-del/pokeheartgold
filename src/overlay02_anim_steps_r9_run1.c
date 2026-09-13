#include "overlay02_anim_steps_r9_private.h"

int ov02_022495E8(void *p) {
    VecFx32 v1;
    VecFx32 v2;
    if (U32(p, 0x214) == 0) {
        return 0;
    }
    v1 = ov02_02253408;
    v2 = ov02_02253384;
    PTR(p, 0x1e4) = ov02_0224A418(p, &v1);
    PTR(p, 0x1e8) = ov02_0224A9B8(p, &v2);
    ov02_0224A9D8(p, 1);
    ov02_02249D40(p);
    U32(p, 0x10) = 1;
    U32(p, 0)
    ++;
    return 1;
}

int ov02_02249658(void *p) {
    ov02_0224B72C(p);
    U32(p, 0x2c) = 0;
    S32(p, 0x54) = -0x40000;
    S32(p, 0x44) = 0xfe000;
    S32(p, 0x48) = 0xff000;
    S32(p, 0x4c) = 0x5f000;
    S32(p, 0x50) = 0x61000;
    U32(p, 0x2c) = 1;
    U32(p, 0)
    ++;
    return 0;
}

int ov02_02249690(void *p) {
    U32(p, 0x2c) = 0;
    S32(p, 0x44) += S32(p, 0x54);
    if (S32(p, 0x44) <= 0) {
        S32(p, 0x44) = 0;
        S32(p, 0x54) = 0x2000;
        U32(p, 0)
        ++;
    }
    ov02_0224A69C(p, U32(p, 0x44), U32(p, 0x4c), U32(p, 0x48), U32(p, 0x50));
    U32(p, 0x2c) = 1;
    return 0;
}

int ov02_022496D0(void *p) {
    U32(p, 0x2c) = 0;
    S32(p, 0x4c) -= S32(p, 0x54);
    S32(p, 0x50) += S32(p, 0x54);
    S32(p, 0x54) += 0x2000;
    if (S32(p, 0x54) > 0x20000) {
        S32(p, 0x54) = 0x20000;
    }
    if (S32(p, 0x4c) < 0x38000) {
        S32(p, 0x4c) = 0x38000;
    }
    if (S32(p, 0x50) > 0x88000) {
        S32(p, 0x50) = 0x88000;
    }
    ov02_0224A69C(p, U32(p, 0x44), U32(p, 0x4c), U32(p, 0x48), U32(p, 0x50));
    U32(p, 0x2c) = 1;
    if (S32(p, 0x4c) == 0x38000 && S32(p, 0x50) == 0x88000) {
        ov02_0224A450(PTR(p, 0x1e4));
        U32(p, 0)
        ++;
    }
    return 0;
}

int ov02_02249754(void *p) {
    if (++S32(p, 8) >= 0xf) {
        S32(p, 8) = 0;
        S32(p, 0x58) = -0x40000;
        U32(p, 0)
        ++;
    }
    return 0;
}

int ov02_02249774(void *p) {
    VecFx32 v;
    v = *(VecFx32 *)Sprite_GetMatrixPtr(PTR(p, 0x1e8));
    v.x += S32(p, 0x58);
    if (v.x <= 0xa0000) {
        v.x = 0xc0000;
        U32(p, 0)
        ++;
    }
    Sprite_SetMatrix(PTR(p, 0x1e8), &v);
    return 0;
}

int ov02_022497C0(void *p) {
    VecFx32 v;
    S32(p, 0x58) /= 2;
    if (S32(p, 0x58) > -0x2000) {
        S32(p, 0x58) = -0x2000;
        U32(p, 0)
        ++;
        PlayCry(GetMonData(PTR(p, 0x5c), 5, NULL), GetMonData(PTR(p, 0x5c), 0x70, NULL));
    }
    v = *(VecFx32 *)Sprite_GetMatrixPtr(PTR(p, 0x1e8));
    v.x += S32(p, 0x58);
    Sprite_SetMatrix(PTR(p, 0x1e8), &v);
    return 0;
}

int ov02_02249838(void *p) {
    if (++S32(p, 8) >= 8) {
        S32(p, 8) = 0;
        S32(p, 0x58) = -0x1000;
        U32(p, 0)
        ++;
    }
    return 0;
}

int ov02_02249858(void *p) {
    VecFx32 v;
    S32(p, 0x58) *= 2;
    if (S32(p, 0x58) < -0x40000) {
        S32(p, 0x58) = -0x40000;
    }
    v = *(VecFx32 *)Sprite_GetMatrixPtr(PTR(p, 0x1e8));
    v.x += S32(p, 0x58);
    Sprite_SetMatrix(PTR(p, 0x1e8), &v);
    if (v.x <= -0x28000) {
        S32(p, 0x54) = 0x1000;
        U32(p, 0)
        ++;
    }
    return 0;
}

int ov02_022498BC(void *p) {
    U32(p, 0x2c) = 0;
    S32(p, 0x4c) += S32(p, 0x54);
    S32(p, 0x50) -= S32(p, 0x54);
    S32(p, 0x54) += 0x4000;
    if (S32(p, 0x54) > 0x10000) {
        S32(p, 0x54) = 0x10000;
    }
    if (S32(p, 0x4c) >= 0x5f000) {
        S32(p, 0x4c) = 0x5f000;
    }
    if (S32(p, 0x50) <= 0x61000) {
        S32(p, 0x50) = 0x61000;
    }
    ov02_0224A69C(p, U32(p, 0x44), U32(p, 0x4c), U32(p, 0x48), U32(p, 0x50));
    U32(p, 0x2c) = 1;
    if (S32(p, 0x4c) == 0x5f000 && S32(p, 0x50) == 0x61000) {
        ov02_0224B768(p);
        U32(p, 0x34) = 0x11;
        U32(p, 0)
        ++;
    }
    return 0;
}
