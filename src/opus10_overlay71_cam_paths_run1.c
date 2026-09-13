#include "opus10_overlay71_cam_paths_private.h"

extern void *Heap_Alloc(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
typedef void (*Ov71TaskFunc)(void *, void *);
extern void *SysTask_CreateOnMainQueue(Ov71TaskFunc func, void *data, u32 priority);
extern void SysTask_SetFunc(void *task, Ov71TaskFunc func);
extern void SysTask_Destroy(void *task);
extern int _s32_div_f(int lhs, int rhs);

fx32 GF_SinDegNoWrap(u16 deg);
fx32 GF_CosDegNoWrap(u16 deg);

void ov71_022476B4(Ov71Cam *cam, Ov71Vec3 *dst);
void ov71_022476C4(Ov71Cam *cam, const Ov71Vec3 *src);
void ov71_022476D4(Ov71Cam *cam, Ov71S16Vec3 *dst);
void ov71_022476EC(Ov71Cam *cam, const Ov71S16Vec3 *src);
void ov71_02247704(Ov71Cam *cam, void *value);
void ov71_02247708(Ov71Cam *cam, u32 value);
BOOL ov71_02247738(Ov71Cam *cam);

void ov71_02248E30(Ov71Cam *cam, s32 from, s32 to, s32 frames);
void ov71_02248E78(void *task, Ov71Zoom *w);
void ov71_02248EB4(Ov71Orbiter *s);
void ov71_02248F8C(Ov71Orbit *w, s32 target, s32 frames);
void ov71_02248FC8(Ov71Orbit *w, s32 a1, s32 a2, s32 frames);
void ov71_02249004(Ov71Orbit *w, s32 idx, s32 target, s32 frames);
void ov71_0224903C(Ov71Orbit *w);
void ov71_02249184(void *task, Ov71Orbit *w);
void ov71_02249208(void *task, Ov71Orbit *w);

void ov71_02248E30(Ov71Cam *cam, s32 from, s32 to, s32 frames) {
    Ov71Zoom *w = (Ov71Zoom *)Heap_Alloc(0x39, sizeof(Ov71Zoom));
    if (w != NULL) {
        w->unk_00 = from << 12;
        w->unk_08 = to << 12;
        w->unk_04 = _s32_div_f(w->unk_08 - w->unk_00, frames);
        w->unk_0C = frames;
        w->unk_10 = cam;
        ov71_02247708(cam, from);
        SysTask_CreateOnMainQueue((Ov71TaskFunc)ov71_02248E78, w, 0);
    }
}

void ov71_02248E78(void *task, Ov71Zoom *w) {
    w->unk_0C--;
    if (w->unk_0C > 0) {
        w->unk_00 += w->unk_04;
        ov71_02247708(w->unk_10, w->unk_00 >> 12);
        return;
    }
    ov71_02247708(w->unk_10, w->unk_08 >> 12);
    Heap_Free(w);
    SysTask_Destroy(task);
}

void ov71_02248EB4(Ov71Orbiter *s) {
    Ov71Orbit *w = &s->unk_DC;
    int i;
    ov71_022476B4(s->unk_D8, &w->unk_08);
    ov71_022476D4(s->unk_D8, &w->unk_20);
    w->unk_14 = w->unk_08;
    w->unk_04 = s->unk_D4;
    w->unk_00 = s->unk_D8;
    w->unk_28 = w->unk_08.y;
    w->unk_2C = _s32_div_f(-0x8000 - w->unk_08.y, 30);
    w->unk_80 = 30;
    w->unk_38 = 0;
    w->unk_3C = 0;
    w->unk_40 = 0;
    w->unk_44 = 0;
    w->unk_54 = 0;
    w->unk_56 = 0x4000;
    w->unk_5A = 0;
    w->unk_7C = 0;
    for (i = 0; i < 3; i++) {
        w->unk_5C[i].unk_00 = 0;
        w->unk_5C[i].unk_02 = 0;
        w->unk_5C[i].unk_04 = 0;
        w->unk_5C[i].unk_06 = 0;
    }
    w->unk_78 = 0;
    ov71_02248F8C(w, 0xD00, 30);
    ov71_02248FC8(w, 0x29000, 0x14000, 30);
    SysTask_CreateOnMainQueue((Ov71TaskFunc)ov71_02249184, w, 0);
}

void ov71_02248F8C(Ov71Orbit *w, s32 target, s32 frames) {
    if (frames != 0) {
        w->unk_5A = (s16)_s32_div_f(target - w->unk_56, frames);
        w->unk_56 = (s16)(w->unk_56 + w->unk_5A);
    } else {
        w->unk_56 = (s16)target;
    }
    w->unk_58 = (s16)target;
    w->unk_74 = frames;
}

void ov71_02248FC8(Ov71Orbit *w, s32 a1, s32 a2, s32 frames) {
    if (frames != 0) {
        w->unk_40 = _s32_div_f(a1 - w->unk_38, frames);
        w->unk_44 = _s32_div_f(a2 - w->unk_3C, frames);
        w->unk_38 += w->unk_40;
        w->unk_3C += w->unk_44;
        w->unk_48 = a1;
        w->unk_4C = a2;
    }
    w->unk_50 = frames;
}

void ov71_02249004(Ov71Orbit *w, s32 idx, s32 target, s32 frames) {
    if (frames != 0) {
        w->unk_5C[idx].unk_02 = (s16)_s32_div_f(target - w->unk_5C[idx].unk_00, frames);
    }
    w->unk_5C[idx].unk_04 = (s16)target;
    w->unk_5C[idx].unk_06 = (u16)frames;
}

void ov71_0224903C(Ov71Orbit *w) {
    s64 product;
    s32 radius;
    s32 angle;
    int i;

    if (w->unk_74 != 0) {
        w->unk_74--;
        if (w->unk_74 != 0) {
            w->unk_56 = (s16)(w->unk_56 + w->unk_5A);
        } else {
            w->unk_56 = w->unk_58;
        }
    }
    w->unk_54 = (s16)(w->unk_54 + w->unk_56);
    angle = _s32_div_f((u16)w->unk_54, 182);
    if (angle >= 360) {
        angle -= 360;
    }
    if (w->unk_50 != 0) {
        w->unk_38 += w->unk_40;
        w->unk_3C += w->unk_44;
        w->unk_50--;
        if (w->unk_50 == 0) {
            w->unk_38 = w->unk_48;
            w->unk_3C = w->unk_4C;
        }
    }
    radius = w->unk_38;
    product = GF_CosDegNoWrap(angle);
    product *= radius;
    w->unk_14.x = w->unk_08.x + (s32)((product + 0x800) >> 12);
    radius = w->unk_3C;
    product = GF_SinDegNoWrap(angle);
    product *= radius;
    w->unk_14.z = w->unk_08.z + (s32)((product + 0x800) >> 12);
    w->unk_20.y = (s16)(w->unk_20.y + w->unk_56);
    for (i = 0; i < 3; i++) {
        if (w->unk_5C[i].unk_06 != 0) {
            w->unk_5C[i].unk_06--;
            if (w->unk_5C[i].unk_06 == 0) {
                w->unk_5C[i].unk_00 = w->unk_5C[i].unk_04;
            } else {
                w->unk_5C[i].unk_00 = (s16)(w->unk_5C[i].unk_00 + w->unk_5C[i].unk_02);
            }
        }
    }
    w->unk_20.x = (s16)(w->unk_20.x + w->unk_5C[0].unk_00);
    w->unk_20.y = (s16)(w->unk_20.y + w->unk_5C[1].unk_00);
    w->unk_20.z = (s16)(w->unk_20.z + w->unk_5C[2].unk_00);
}

void ov71_02249184(void *task, Ov71Orbit *w) {
    if (w->unk_80 != 0) {
        w->unk_28 += w->unk_2C;
        w->unk_14.y = w->unk_28;
        w->unk_80--;
        if (w->unk_80 <= 0) {
            w->unk_30 = 0x200;
            w->unk_2C = 0;
            ov71_02248FC8(w, 0x4000, 0x4000, 60);
            ov71_02249004(w, 0, -0x800, 30);
            w->unk_7C = 1;
            SysTask_SetFunc(task, (Ov71TaskFunc)ov71_02249208);
        }
    }
    ov71_0224903C(w);
    ov71_022476C4(w->unk_00, &w->unk_14);
    ov71_022476EC(w->unk_00, &w->unk_20);
}

void ov71_02249208(void *task, Ov71Orbit *w) {
#pragma unused(task)
    if (w->unk_78 == 0) {
        w->unk_2C += w->unk_30;
        w->unk_28 += w->unk_2C;
        w->unk_14.y = w->unk_28;
        ov71_0224903C(w);
        ov71_022476C4(w->unk_00, &w->unk_14);
        ov71_022476EC(w->unk_00, &w->unk_20);
        if (!ov71_02247738(w->unk_00)) {
            ov71_02247704(w->unk_00, NULL);
            w->unk_78 = 1;
        }
    }
}
