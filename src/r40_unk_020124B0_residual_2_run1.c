#include "r40_unk_020124B0_residual_2_private.h"

void sub_0201268C(FadeEffect *effect, const FadeParam *param, u32 unk2, u32 unk3, u32 unk4, u32 unk5, u32 unk6, u32 heapId) {
    effect->start = param->start;
    effect->current = param->start;
    effect->delta = param->end - param->start;
    sub_02010E64(effect, 2, unk4, heapId);
    effect->duration = unk2;
    effect->frame = 0;
    effect->delay = unk3;
    effect->counter = 0;
    effect->callbackArg = unk5;
    effect->unk34 = unk6;
    effect->heapId = heapId;
    effect->color = param->color;
    sub_020127B8(effect);
    SysTask_CreateOnVWaitQueue(sub_02010F00, effect, 0x3FF);
    sub_02010EE0(effect, 0);
    sub_02010EE0(effect, 1);
    sub_02010F84(unk5, param->unk04, param->unk05, 0, unk4, 0, 0, 0xFF, 0xC0, effect->color);
    sub_02010F84(unk5, param->unk04, param->unk05, 1, unk4, 0, 0, 0xFF, 0xC0, effect->color);
    sub_02011068(unk5, 3, unk4, effect->color);
    sub_0200FF88(effect->unk34, effect, sub_02010C38, unk4, heapId);
}
