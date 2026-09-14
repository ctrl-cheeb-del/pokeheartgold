#include "overlay02_parallel_starter_anim_r23_private.h"

void ov02_0224ADF0(void *arg0) {
    VecFx32 position = ov02_02253354;
    VecFx32 scale = ov02_0225336C;
    VecFx32 matrix;
    VecFx32 secondScale;
    void *work = sub_02068D74(PTR_AT(arg0, 0x1ec));
    Sprite *sprite;

    U8_AT(work, 0) = 2;
    U8_AT(work, 1) = 0;
    U8_AT(work, 2) = 1;
    S32_AT(work, 4) = 0;
    position.x += S32_AT(arg0, 0x2ec);
    position.y += S32_AT(arg0, 0x2f4);
    *(VecFx32 *)((u8 *)work + 8) = position;
    S32_AT(work, 0x14) = 0;
    S32_AT(work, 0x18) = 0;
    S32_AT(work, 0x1c) = 0;
    S32_AT(work, 0x38) = 0x13b000;
    *(VecFx32 *)((u8 *)work + 0x2c) = scale;
    S32_AT(work, 0x50) = 0x100;
    S32_AT(work, 0x40) = 0xe1000;
    S32_AT(work, 0x48) = 0xc0000;
    S32_AT(work, 0x4c) = 0x20000;
    S32_AT(work, 0x14) = GF_CosDeg(0x13b) * (S32_AT(work, 0x48) / FX32_ONE);
    S32_AT(work, 0x18) = GF_SinDeg((u16)(S32_AT(work, 0x40) / FX32_ONE)) * (S32_AT(work, 0x48) / FX32_ONE);
    position.x = S32_AT(work, 8) + S32_AT(work, 0x14);
    position.y = S32_AT(work, 0xc) + S32_AT(work, 0x18);
    Sprite_SetMatrix(PTR_AT(work, 0x58), &position);
    Sprite_SetAffineScale(PTR_AT(work, 0x58), &scale);
    Sprite_SetAffineZRotation(PTR_AT(work, 0x58), GF_DegreeToSinCosIdx((u16)(S32_AT(work, 0x38) / FX32_ONE)));
    Sprite_SetDrawFlag(PTR_AT(work, 0x58), TRUE);
    PTR_AT(work, 0x60) = ov02_0224B298(PTR_AT(arg0, 0x1e0), PTR_AT(arg0, 0x1e4));
    S32_AT(arg0, 0x1c) = 1;
    PTR_AT(work, 0x64) = ov01_021FCD2C(PTR_AT(arg0, 0x60), 4);
    ov01_021FCD8C(PTR_AT(work, 0x64), 1, (fx32)0xfff88000, 0xc);
    {
        int *values = (int *)&matrix;
        values[0] = 0;
        values[1] = 0;
        values[2] = 0;
    }
    secondScale = ov02_02253378;
    sprite = *(Sprite **)((u8 *)PTR_AT(work, 0x5c) + 0x1e4);
    Sprite_SetAffineOverwriteMode(sprite, 2);
    Sprite_SetAffineMatrix(sprite, &matrix);
    Sprite_SetAffineScale(sprite, &secondScale);
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx(0));
}

int ov02_0224AF70(void *work) {
    Sprite *sprite = PTR_AT(work, 0x58);
    VecFx32 matrix;
    VecFx32 scale;

    S32_AT(work, 0x48) -= S32_AT(work, 0x4c);
    if (S32_AT(work, 0x48) < 0) {
        S32_AT(work, 0x48) = 0;
    }
    if (S32_AT(work, 0x4c) > 0x800) {
        S32_AT(work, 0x4c) -= 0x1800;
    }
    if (S32_AT(work, 0x4c) < 0x1000) {
        S32_AT(work, 0x4c) = 0x1000;
    }
    S32_AT(work, 0x14) = GF_CosDeg(0x13b) * (S32_AT(work, 0x48) / FX32_ONE);
    S32_AT(work, 0x18) = GF_SinDeg((u16)(S32_AT(work, 0x40) / FX32_ONE)) * (S32_AT(work, 0x48) / FX32_ONE);
    if (S32_AT(work, 0x40) / FX32_ONE < 0x10e) {
        S32_AT(work, 0x40) += 0x4000;
    }
    S32_AT(work, 0x2c) += S32_AT(work, 0x50);
    if (S32_AT(work, 0x2c) > 0x1800) {
        S32_AT(work, 0x2c) = 0x1800;
    }
    S32_AT(work, 0x30) += S32_AT(work, 0x50);
    if (S32_AT(work, 0x30) > 0x1800) {
        S32_AT(work, 0x30) = 0x1800;
    }
    Sprite_SetAffineScale(sprite, (VecFx32 *)((u8 *)work + 0x2c));
    S32_AT(work, 0x38) += 0x8000;
    if (S32_AT(work, 0x38) / FX32_ONE > 0x168) {
        S32_AT(work, 0x38) = 0x168000;
    }
    Sprite_SetAffineZRotation(sprite, GF_DegreeToSinCosIdx((u16)(S32_AT(work, 0x38) / FX32_ONE)));
    matrix.x = S32_AT(work, 8) + S32_AT(work, 0x14);
    matrix.y = S32_AT(work, 0xc) + S32_AT(work, 0x18);
    Sprite_SetMatrix(sprite, &matrix);
    if (S32_AT(work, 0x48) == 0) {
        S32_AT(work, 4) = 0;
        U8_AT(work, 1)
        ++;
    } else {
        S32_AT(work, 4)
        ++;
    }
    if (S32_AT(work, 4) == 0xc) {
        ov02_0224B2CC(PTR_AT(work, 0x60));
    }
    sprite = *(Sprite **)((u8 *)PTR_AT(work, 0x5c) + 0x1e4);
    scale = *Sprite_GetScalePtr(sprite);
    scale.x += 0x80;
    if (scale.x > 0x1400) {
        scale.x = 0x1400;
    }
    scale.y += 0x80;
    if (scale.y > 0x1400) {
        scale.y = 0x1400;
    }
    Sprite_SetAffineScale(sprite, &scale);
    return 0;
}

int ov02_0224B0E0(void *work) {
    Sprite *sprite = *(Sprite **)((u8 *)PTR_AT(work, 0x5c) + 0x1e4);
    s32 y;

    Sprite_SetAnimCtrlSeq(sprite, 3);
    Sprite_SetDrawFlag(sprite, TRUE);
    ov02_0224B6B0(PTR_AT(work, 0x5c), 1);
    sub_0205F484(*(void **)((u8 *)PTR_AT(work, 0x5c) + 0x208));
    y = Sprite_GetMatrixPtr(sprite)->y;
    S32_AT(work, 0x54) = y - Sprite_GetMatrixPtr(PTR_AT(work, 0x58))->y;
    ov02_0224B2C0(PTR_AT(work, 0x60));
    ov01_021FCD8C(PTR_AT(work, 0x64), 2, 0, 0xc);
    S32_AT(work, 0x50) = 0x100;
    S32_AT(work, 0x40) = 0x80000;
    S32_AT(work, 0x48) = 0;
    S32_AT(work, 0x4c) = 0x800;
    U8_AT(work, 2) = 3;
    U8_AT(work, 1)
    ++;
    return 1;
}

int ov02_0224B158(void *work) {
    Sprite *sprite = PTR_AT(work, 0x58);
    Sprite *other;
    VecFx32 *scalePtr;
    VecFx32 matrix;
    VecFx32 otherMatrix;
    VecFx32 scale;

    S32_AT(work, 0x48) += S32_AT(work, 0x4c);
    S32_AT(work, 0x4c) += 0x1000;
    if (S32_AT(work, 0x4c) > 0x10000) {
        S32_AT(work, 0x4c) = 0x10000;
    }
    S32_AT(work, 0x14) = GF_CosDeg((u16)(S32_AT(work, 0x40) / FX32_ONE)) * (S32_AT(work, 0x48) / FX32_ONE);
    S32_AT(work, 0x18) = GF_SinDeg(0x80) * (S32_AT(work, 0x48) / FX32_ONE);
    if (S32_AT(work, 0x40) < 0x87000) {
        S32_AT(work, 0x40) += 0x1000;
    }
    S32_AT(work, 0x2c) += S32_AT(work, 0x50);
    if (S32_AT(work, 0x2c) > 0x2000) {
        S32_AT(work, 0x2c) = 0x2000;
    }
    S32_AT(work, 0x30) += S32_AT(work, 0x50);
    if (S32_AT(work, 0x30) > 0x2000) {
        S32_AT(work, 0x30) = 0x2000;
    }
    matrix.x = S32_AT(work, 8) + S32_AT(work, 0x14);
    matrix.y = S32_AT(work, 0xc) + S32_AT(work, 0x18);
    if (matrix.y / FX32_ONE >= 0xe6) {
        U8_AT(work, 2) = 2;
        U8_AT(work, 1)
        ++;
    }
    other = *(Sprite **)((u8 *)PTR_AT(work, 0x5c) + 0x1e4);
    scalePtr = Sprite_GetScalePtr(other);
    otherMatrix = matrix;
    scale = *scalePtr;
    S32_AT(work, 0x54) -= FX32_ONE;
    otherMatrix.y += S32_AT(work, 0x54);
    Sprite_SetMatrix(other, &otherMatrix);
    scale.x += 0x100;
    if (scale.x > 0x2000) {
        scale.x = 0x2000;
    }
    scale.y += 0x100;
    if (scale.y > 0x2000) {
        scale.y = 0x2000;
    }
    Sprite_SetAffineScale(other, &scale);
    Sprite_SetAffineScale(sprite, (VecFx32 *)((u8 *)work + 0x2c));
    Sprite_SetMatrix(sprite, &matrix);
    return 0;
}
