#include "global.h"

#include "math_util.h"
#include "sprite.h"

extern void ov01_021FCD8C(void *, int, fx32, int);
extern BOOL ov01_021FCD6C(void *);
extern void ov02_0224B314(void *);
extern void ov02_02249444(void *, BOOL);
extern void *sub_02068D74(void *);
extern void *ov02_0224B298(void *, void *);
extern void *ov01_021FCD2C(void *, int);
extern void ov02_022493FC(void);

extern const VecFx32 ov02_0225339C;
extern const VecFx32 ov02_022533CC;
extern const VecFx32 ov02_022533A8;
extern const VecFx32 ov02_022533D8;
extern const VecFx32 ov02_022533B4;

void ov02_02248E20(void *arg0);
int ov02_02248F88(void *work);
BOOL ov02_02249088(void *work);
int ov02_022490BC(void *work);
int ov02_022491A8(void *work);
int ov02_022491CC(void *work);
int ov02_02249290(void *work);
int ov02_0224939C(void *work);

void ov02_02248E20(void *arg0) {
    VecFx32 position = ov02_0225339C;
    VecFx32 scale = ov02_022533CC;
    VecFx32 matrix;
    VecFx32 secondScale;
    void *work = sub_02068D74(arg0);
    Sprite *sprite;

    ((u8 *)work)[0] = 1;
    ((u8 *)work)[2] = 0;
    ((u8 *)work)[1] = 0;
    *(int *)((u8 *)work + 4) = 0;
    *(VecFx32 *)((u8 *)work + 8) = position;
    *(int *)((u8 *)work + 0x14) = 0;
    *(int *)((u8 *)work + 0x18) = 0;
    *(int *)((u8 *)work + 0x1c) = 0;
    *(int *)((u8 *)work + 0x38) = 0x15e000;
    *(VecFx32 *)((u8 *)work + 0x2c) = scale;
    *(int *)((u8 *)work + 0x50) = 0x400;
    *(int *)((u8 *)work + 0x40) = 0x2d000;
    *(int *)((u8 *)work + 0x48) = 0xc0000;
    *(int *)((u8 *)work + 0x4c) = 0x20000;
    *(int *)((u8 *)work + 0x14) = GF_CosDeg(0x2d) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    *(int *)((u8 *)work + 0x18) = GF_SinDeg((u16)(*(int *)((u8 *)work + 0x40) / 0x1000)) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    position.x = *(int *)((u8 *)work + 8) + *(int *)((u8 *)work + 0x14);
    position.y = *(int *)((u8 *)work + 0xc) + *(int *)((u8 *)work + 0x18);
    Sprite_SetMatrix(*(Sprite **)((u8 *)work + 0x68), &position);
    Sprite_SetAffineScale(*(Sprite **)((u8 *)work + 0x68), &scale);
    Sprite_SetAffineZRotation(*(Sprite **)((u8 *)work + 0x68), GF_DegreeToSinCosIdx((u16)(*(int *)((u8 *)work + 0x38) / 0x1000)));
    Sprite_SetDrawPriority(*(Sprite **)((u8 *)work + 0x68), 0x84);
    Sprite_SetDrawFlag(*(Sprite **)((u8 *)work + 0x68), TRUE);
    *(void **)((u8 *)work + 0x6c) = ov02_0224B298(*(void **)((u8 *)work + 0x58), *(void **)((u8 *)work + 0x60));
    *(void **)((u8 *)work + 0x70) = ov01_021FCD2C(*(void **)((u8 *)work + 0x5c), 4);
    ov01_021FCD8C(*(void **)((u8 *)work + 0x70), 1, (fx32)0xfff88000, 0xc);
    {
        int *values = (int *)&matrix;
        values[0] = 0;
        values[1] = 0;
        values[2] = 0;
    }
    secondScale = ov02_022533A8;
    sprite = *(Sprite **)((u8 *)work + 0x60);
    Sprite_SetAffineOverwriteMode(sprite, 2);
    Sprite_SetAffineMatrix(sprite, &matrix);
    Sprite_SetAffineScale(sprite, &secondScale);
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx(0));
    Sprite_SetAnimCtrlSeq(sprite, 2);
    ov02_022493FC();
}

int ov02_02248F88(void *work) {
    Sprite *spriteA = *(Sprite **)((u8 *)work + 0x68);
    Sprite *spriteB = *(Sprite **)((u8 *)work + 0x60);
    VecFx32 mtx;
    *(int *)((u8 *)work + 0x48) -= *(int *)((u8 *)work + 0x4c);
    if (*(int *)((u8 *)work + 0x48) < 0) {
        *(int *)((u8 *)work + 0x48) = 0;
    }
    if (*(int *)((u8 *)work + 0x4c) > 0x800) {
        *(int *)((u8 *)work + 0x4c) -= 0x1c00;
    }
    if (*(int *)((u8 *)work + 0x4c) < 0x1000) {
        *(int *)((u8 *)work + 0x4c) = 0x1000;
    }
    *(int *)((u8 *)work + 0x14) = GF_CosDeg(0x2d) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    *(int *)((u8 *)work + 0x18) = GF_SinDeg((u16)(*(int *)((u8 *)work + 0x40) / 0x1000)) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    if (*(int *)((u8 *)work + 0x40) / 0x1000 < 0x5a) {
        *(int *)((u8 *)work + 0x40) += 0x4000;
    }
    *(int *)((u8 *)work + 0x2c) -= *(int *)((u8 *)work + 0x50);
    if (*(int *)((u8 *)work + 0x2c) < 0x1000) {
        *(int *)((u8 *)work + 0x2c) = 0x1000;
    }
    *(int *)((u8 *)work + 0x30) -= *(int *)((u8 *)work + 0x50);
    if (*(int *)((u8 *)work + 0x30) < 0x1000) {
        *(int *)((u8 *)work + 0x30) = 0x1000;
    }
    Sprite_SetAffineScale(spriteA, (VecFx32 *)((u8 *)work + 0x2c));
    Sprite_SetAffineScale(spriteB, (VecFx32 *)((u8 *)work + 0x2c));
    mtx.x = *(int *)((u8 *)work + 8) + *(int *)((u8 *)work + 0x14);
    mtx.y = *(int *)((u8 *)work + 0xc) + *(int *)((u8 *)work + 0x18);
    Sprite_SetMatrix(spriteA, &mtx);
    mtx.y -= 0x12000;
    Sprite_SetMatrix(spriteB, &mtx);
    if (*(int *)((u8 *)work + 0x48) == 0) {
        *(int *)((u8 *)work + 4) = 0;
        (*(u8 *)((u8 *)work + 1))++;
    } else {
        (*(int *)((u8 *)work + 4))++;
    }
    return 0;
}

BOOL ov02_02249088(void *work) {
    ov02_0224B314(*(void **)((u8 *)work + 0x6c));
    ov01_021FCD8C(*(void **)((u8 *)work + 0x70), 2, 0, 0xc);
    *(u32 *)((u8 *)work + 0x50) = 0x400;
    *(u32 *)((u8 *)work + 0x40) = 0x80000;
    *(u32 *)((u8 *)work + 0x48) = 0;
    *(u32 *)((u8 *)work + 0x4c) = 0x1800;
    ((u8 *)work)[1]++;
    return TRUE;
}

int ov02_022490BC(void *work) {
    Sprite *sprite = *(Sprite **)((u8 *)work + 0x68);
    VecFx32 mtx;
    *(int *)((u8 *)work + 0x48) += *(int *)((u8 *)work + 0x4c);
    *(int *)((u8 *)work + 0x4c) += 0x1000;
    if (*(int *)((u8 *)work + 0x4c) > 0x10000) {
        *(int *)((u8 *)work + 0x4c) = 0x10000;
    }
    *(int *)((u8 *)work + 0x14) = GF_CosDeg((u16)(*(int *)((u8 *)work + 0x40) / 0x1000)) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    *(int *)((u8 *)work + 0x18) = GF_SinDeg(0x80) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    if (*(int *)((u8 *)work + 0x40) < 0xa0000) {
        *(int *)((u8 *)work + 0x40) += 0x1000;
    }
    *(int *)((u8 *)work + 0x38) += 0x2000;
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx((u16)(*(int *)((u8 *)work + 0x38) / 0x1000)));
    *(int *)((u8 *)work + 0x2c) += *(int *)((u8 *)work + 0x50);
    if (*(int *)((u8 *)work + 0x2c) > 0x1000) {
        *(int *)((u8 *)work + 0x2c) = 0x1000;
    }
    *(int *)((u8 *)work + 0x30) += *(int *)((u8 *)work + 0x50);
    if (*(int *)((u8 *)work + 0x30) > 0x1000) {
        *(int *)((u8 *)work + 0x30) = 0x1000;
    }
    Sprite_SetAffineScale(sprite, (VecFx32 *)((u8 *)work + 0x2c));
    mtx.x = *(int *)((u8 *)work + 8) + *(int *)((u8 *)work + 0x14);
    mtx.y = *(int *)((u8 *)work + 0xc) - *(int *)((u8 *)work + 0x18);
    Sprite_SetMatrix(sprite, &mtx);
    if (mtx.y / 0x1000 <= -0x10) {
        ((u8 *)work)[1]++;
    }
    return 0;
}

int ov02_022491A8(void *work) {
    Sprite_SetDrawFlag(*(Sprite **)((u8 *)work + 0x68), FALSE);
    Sprite_SetAnimCtrlSeq(*(Sprite **)((u8 *)work + 0x60), 1);
    *(int *)((u8 *)work + 4) = 0;
    ((u8 *)work)[1]++;
    return 1;
}

int ov02_022491CC(void *work) {
    VecFx32 local1;
    VecFx32 local2;
    if (++*(int *)((u8 *)work + 4) < 0x14) {
        return 0;
    }
    local1 = ov02_022533D8;
    local2 = ov02_022533B4;
    *(int *)((u8 *)work + 4) = 0;
    *(VecFx32 *)((u8 *)work + 8) = local1;
    *(int *)((u8 *)work + 0x14) = 0;
    *(int *)((u8 *)work + 0x18) = 0;
    *(int *)((u8 *)work + 0x1c) = 0;
    *(int *)((u8 *)work + 0x38) = 0;
    *(VecFx32 *)((u8 *)work + 0x2c) = local2;
    *(int *)((u8 *)work + 0x50) = 0x200;
    *(int *)((u8 *)work + 0x40) = 0x13B000;
    *(int *)((u8 *)work + 0x48) = 0x80000;
    *(int *)((u8 *)work + 0x4c) = 0x2000;
    Sprite_SetMatrix(*(Sprite **)((u8 *)work + 0x68), &local1);
    Sprite_SetAffineScale(*(Sprite **)((u8 *)work + 0x68), &local2);
    Sprite_SetAffineZRotation(*(Sprite **)((u8 *)work + 0x68), GF_DegreeToSinCosIdx((u16)(*(int *)((u8 *)work + 0x38) / 0x1000)));
    Sprite_SetDrawFlag(*(Sprite **)((u8 *)work + 0x68), 1);
    Sprite_SetAnimCtrlSeq(*(Sprite **)((u8 *)work + 0x60), 6);
    Sprite_SetAnimActiveFlag(*(Sprite **)((u8 *)work + 0x60), 1);
    ((u8 *)work)[1]++;
    return 1;
}

int ov02_02249290(void *work) {
    Sprite *sprite = *(Sprite **)((u8 *)work + 0x68);
    VecFx32 mtx;
    *(int *)((u8 *)work + 0x48) -= *(int *)((u8 *)work + 0x4c);
    if (*(int *)((u8 *)work + 0x4c) < 0x10000) {
        *(int *)((u8 *)work + 0x4c) += 0x2000;
    }
    if (*(int *)((u8 *)work + 0x48) < 0) {
        *(int *)((u8 *)work + 0x48) = 0;
    }
    *(int *)((u8 *)work + 0x14) = GF_CosDeg(0x13B) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    *(int *)((u8 *)work + 0x18) = GF_SinDeg((u16)(*(int *)((u8 *)work + 0x40) / 0x1000)) * (*(int *)((u8 *)work + 0x48) / 0x1000);
    if (*(int *)((u8 *)work + 0x40) / 0x1000 < 0xb4) {
        *(int *)((u8 *)work + 0x40) -= 0x4000;
    }
    *(int *)((u8 *)work + 0x2c) -= *(int *)((u8 *)work + 0x50);
    if (*(int *)((u8 *)work + 0x2c) < 0x400) {
        *(int *)((u8 *)work + 0x2c) = 0x400;
    }
    *(int *)((u8 *)work + 0x30) -= *(int *)((u8 *)work + 0x50);
    if (*(int *)((u8 *)work + 0x30) < 0x400) {
        *(int *)((u8 *)work + 0x30) = 0x400;
    }
    Sprite_SetAffineScale(sprite, (VecFx32 *)((u8 *)work + 0x2c));
    *(int *)((u8 *)work + 0x38) += 0x6000;
    if (*(int *)((u8 *)work + 0x38) / 0x1000 > 0x3c) {
        *(int *)((u8 *)work + 0x38) = 0x3c000;
    }
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx((u16)(*(int *)((u8 *)work + 0x38) / 0x1000)));
    mtx.x = *(int *)((u8 *)work + 8) + *(int *)((u8 *)work + 0x14);
    mtx.y = *(int *)((u8 *)work + 0xc) + *(int *)((u8 *)work + 0x18);
    Sprite_SetMatrix(sprite, &mtx);
    if (*(int *)((u8 *)work + 0x48) <= 0) {
        Sprite_SetDrawFlag(sprite, FALSE);
        ((u8 *)work)[1]++;
    }
    return 0;
}

int ov02_0224939C(void *work) {
    if (++*(int *)((u8 *)work + 4) == 8) {
        Sprite_SetAnimCtrlSeq(*(Sprite **)((u8 *)work + 0x60), 1);
        ov02_02249444(*(void **)((u8 *)work + 0x5c), FALSE);
    }
    if (*(int *)((u8 *)work + 4) == 0xa) {
        Sprite_SetDrawFlag(*(Sprite **)((u8 *)work + 0x60), FALSE);
    }
    if (*(int *)((u8 *)work + 4) > 0xf && ov01_021FCD6C(*(void **)((u8 *)work + 0x70)) == 1) {
        *(int *)((u8 *)work + 4) = 0;
        ((u8 *)work)[1]++;
        ((u8 *)work)[2] = 2;
    }
    return 0;
}
