#include "field_overlay_effects_internal.h"

void *ov01_021EFE30(void *p) {
    return *(void **)((u8 *)p + 0x18);
}

void ov01_021EFE34(Interp *p, s32 start, s32 end, s32 duration) {
    p->value = start;
    p->start = start;
    p->delta = end - start;
    p->duration = duration;
    p->frame = 0;
}

BOOL ov01_021EFE44(Interp *p) {
    s32 value = p->delta * p->frame / p->duration;
    s32 frame;
    s32 duration;
    value += p->start;
    p->value = value;
    frame = p->frame;
    duration = *(volatile s32 *)&p->duration;
    frame++;
    if (frame <= duration) {
        p->frame = frame;
        return FALSE;
    }
    p->frame = duration;
    return TRUE;
}

void ov01_021EFE70(Interp *p, s32 start, s32 end, s32 duration) {
    p->value = start;
    p->start = start;
    p->delta = end - start;
    p->duration = duration;
    p->frame = 0;
}

BOOL ov01_021EFE80(Interp *p) {
    s64 product = (s64)p->delta * (p->frame << 12);
    s32 frame;
    s32 duration;
    s32 value = FX_Div((s32)((product + 0x800) >> 12), p->duration << 12);
    value += p->start;
    p->value = value;
    frame = p->frame;
    duration = *(volatile s32 *)&p->duration;
    frame++;
    if (frame <= duration) {
        p->frame = frame;
        return FALSE;
    }
    p->frame = duration;
    return TRUE;
}
