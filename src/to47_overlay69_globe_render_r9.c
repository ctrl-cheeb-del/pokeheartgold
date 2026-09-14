#include "global.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov69Angle;

typedef struct {
    u8 unk_00[0x54];
} Ov69GlobeModel;

typedef struct {
    u8 pad_0000[0xC2C4];
    Ov69Angle angle;
    u8 pad_C2D0[0x18];
    u16 unk_C2E8;
    u8 pad_C2EA[0x1A];
    u16 mode;
    u8 pad_C306[2];
    u32 heldKeys;
    u8 pad_C30C[0xC];
    s32 unk_C318;
    s32 unk_C31C;
} Ov69Ctrl;

typedef struct {
    u8 pad_0000[0xC084];
    u8 obj1[0x5C];
    Ov69GlobeModel models[4];
    u8 obj2[0x7C];
    VecFx32 translation;
    VecFx32 scale;
    Ov69Angle angle;
    VecFx32 scale2;
    u8 pad_C2DC[0x1C];
    u32 state;
} Ov69Draw;

typedef struct {
    u8 pad_0000[0xC2D0];
    s32 unk_C2D0;
    s32 unk_C2D4;
    u8 pad_C2D8[4];
    void *camera;
    u8 pad_C2E0[8];
    u16 unk_C2E8;
} Ov69Zoom;

extern const MtxFx33 ov69_021E7728;
extern const MtxFx33 ov69_021E774C;
extern const MtxFx33 ov69_021E7794;

extern fx32 Camera_GetDistance(void *camera);
extern void Camera_SetDistance(fx32 distance, void *camera);
extern void Camera_PushLookAtToNNSGlb(void);
extern void Thunk_G3X_Reset(void);
extern void RequestSwap3DBuffers(u32 sortMode, u32 bufferMode);
extern void GF3dRender_DrawModel(void *obj, const VecFx32 *translation, const MtxFx33 *rotation, const VecFx32 *scale);

extern void ov69_021E70A8(MtxFx33 *dst, const Ov69Angle *ang);

int ov69_021E7198(u8 *work, u32 newKeys, u32 repeatKeys);
int ov69_021E737C(u8 *work);
void ov69_021E7408(u8 *work);



int ov69_021E7198(u8 *work, u32 newKeys, u32 repeatKeys) {
    Ov69Ctrl *p = (Ov69Ctrl *)work;
    int moved = 0;
    u16 stepY;
    u16 stepX;
    s16 angX = (s16)p->angle.x;
    s16 angY = (s16)p->angle.y;

    if ((newKeys & 1) || (p->heldKeys & 1)) {
        if (p->mode == 1) {
            if (p->unk_C2E8 == 0) {
                p->unk_C2E8 = 1;
            } else {
                p->unk_C2E8 = 0;
            }
        }
        return 1;
    }

    if (p->unk_C2E8 == 0) {
        if (p->unk_C318 != 0 || p->unk_C31C != 0) {
            stepY = (u16)(p->unk_C318 * 85);
            stepX = (u16)(p->unk_C31C * 85);
        } else {
            stepX = stepY = 0x200;
        }
    } else {
        if (p->unk_C318 != 0 || p->unk_C31C != 0) {
            stepY = (u16)(p->unk_C318 * 10);
            stepX = (u16)(p->unk_C31C * 10);
        } else {
            stepX = stepY = 32;
        }
    }

    if ((repeatKeys & 0x20) || (p->heldKeys & 0x20)) {
        if (p->mode == 1) {
            p->angle.y += stepY;
        } else if (angY < -10208) {
            p->angle.y += stepY;
        }
        moved = 1;
    }

    if ((repeatKeys & 0x10) || (p->heldKeys & 0x10)) {
        if (p->mode == 1) {
            p->angle.y -= stepY;
        } else if (angY > -13184) {
            p->angle.y -= stepY;
        }
        moved = 1;
    }

    if ((repeatKeys & 0x40) || (p->heldKeys & 0x40)) {
        if (p->mode == 1) {
            if (angX + stepX < 0x3E00) {
                p->angle.x += stepX;
            } else {
                p->angle.x = 0x3E00;
            }
        } else if (angX < 0x2020) {
            p->angle.x += stepX;
        }
        moved = 1;
    }

    if ((repeatKeys & 0x80) || (p->heldKeys & 0x80)) {
        if (p->mode == 1) {
            if (angX - stepX > -15872) {
                p->angle.x -= stepX;
            } else {
                p->angle.x = -15872;
            }
        } else if (angX > 0x1300) {
            p->angle.x -= stepX;
        }
        moved = 1;
    }

    return moved;
}

int ov69_021E737C(u8 *work) {
    Ov69Zoom *p = (Ov69Zoom *)work;
    fx32 dist = Camera_GetDistance(p->camera);
    int ret = 0;

    switch (p->unk_C2E8) {
    case 1:
        if (dist > 0x58000) {
            dist -= 0x8000;
            p->unk_C2D0 -= 128;
            p->unk_C2D4 = p->unk_C2D0;
        } else {
            dist = 0x50000;
            ret = 1;
        }
        break;
    case 0:
        if (dist < 0x120000) {
            dist += 0x8000;
            p->unk_C2D0 += 128;
            p->unk_C2D4 = p->unk_C2D0;
        } else {
            dist = 0x128000;
            ret = 1;
        }
        break;
    }

    Camera_SetDistance(dist, p->camera);
    return ret;
}

void ov69_021E7408(u8 *work) {
    Ov69Draw *p = (Ov69Draw *)work;
    MtxFx33 mtx = ov69_021E7728;

    switch (p->state) {
    case 0:
        break;
    case 2:
        Thunk_G3X_Reset();
        RequestSwap3DBuffers(0, 1);
        p->state = 0;
        break;
    case 1: {
        MtxFx33 mtx2;
        MtxFx33 mtx3;
        u32 i;

        Thunk_G3X_Reset();
        Camera_PushLookAtToNNSGlb();
        ov69_021E70A8(&mtx, (const Ov69Angle *)(&p->angle));
        GF3dRender_DrawModel(p->obj1, &p->translation, &mtx, &p->scale);
        mtx2 = ov69_021E7794;
        GF3dRender_DrawModel(p->obj2, &p->translation, &mtx2, &p->scale2);
        mtx3 = ov69_021E774C;
        for (i = 0; i < U32(work, 12); i++) {
            MTX_Concat33((const MtxFx33 *)(work + 20 + i * 48), &mtx, &mtx3);
            if (U16(work + i * 48, 0x38) != 0) {
                GF3dRender_DrawModel(&p->models[U16(work + i * 48, 0x38)], &p->translation, &mtx3, &p->scale2);
            }
        }
        RequestSwap3DBuffers(0, 1);
        break;
    }
    }
}
