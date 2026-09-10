#include "screen_fade_update_internal.h"

BOOL DoFadeUpdateFrame(FadeUpdate *state, void *mainWork, void *subWork) {
    switch (state->mode) {
    case 0:
        FadeWork_UpdateFrame(&state->mainActive, mainWork);
        FadeWork_UpdateFrame(&state->subActive, subWork);
        break;
    case 1:
        if (state->mainActive != 0) {
            FadeWork_UpdateFrame(&state->mainActive, mainWork);
        } else {
            FadeWork_UpdateFrame(&state->subActive, subWork);
        }
        break;
    case 2:
        if (state->subActive != 0) {
            FadeWork_UpdateFrame(&state->subActive, subWork);
        } else {
            FadeWork_UpdateFrame(&state->mainActive, mainWork);
        }
        break;
    }
    if (state->mainActive == 0 && state->subActive == 0) {
        return TRUE;
    }
    return FALSE;
}

void FadeWork_UpdateFrame(u32 *active, void *work) {
    if (*active != 0 && CallFadeFunc(work) == TRUE) {
        *active = 0;
    }
}

BOOL CallFadeFunc(void *work) {
    return sFadeFuncPtrs[*(u32 *)work](work);
}

void sub_0200FE14(int mode, u32 *dst) {
    switch (mode) {
    case 0:
        sub_0200FE78(dst, 0, 1, 1);
        break;
    case 1:
        sub_0200FE78(dst, 1, 1, 1);
        break;
    case 2:
        sub_0200FE78(dst, 2, 1, 1);
        break;
    case 3:
        sub_0200FE78(dst, 1, 1, 0);
        break;
    case 4:
        sub_0200FE78(dst, 2, 0, 1);
        break;
    }
}

void sub_0200FE78(u32 *dst, u32 a1, u32 a2, u32 a3) {
    dst[0] = a1;
    dst[1] = a2;
    dst[2] = a3;
    dst[3] = a2;
    dst[4] = a3;
}

void sub_0200FE84(FadeParam *dst, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u16 color) {
    dst->unk00 = a1;
    dst->unk04 = a2;
    dst->unk08 = a3;
    dst->unk0C = a4;
    dst->unk14 = a5;
    dst->screen = a6;
    dst->unk18 = a7;
    dst->unk1C = a8;
    dst->unk20 = a9;
    dst->color = color;
}

void sub_0200FEB0(FadeBlankPair *data) {
    int i;
    for (i = 0; i < 2; i++) {
        data->values[i] = 0;
        data->funcs[i] = sub_02010014;
        data->active[i] = 0;
    }
}

void sub_0200FECC(FadeBlankPair *data) {
    int i;
    for (i = 0; i < 2; i++) {
        data->funcs[i](data->values[i]);
    }
}
