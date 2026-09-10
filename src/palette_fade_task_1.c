#include "palette_fade_task_internal.h"

PaletteFadeTask *sub_020163E0(void *paletteData, u32 buffer, u32 palette) {
    void *task = CreateSysTaskAndEnvironment(sub_020164D0, sizeof(PaletteFadeTask), 0);
    PaletteFadeTask *state = SysTask_GetData(task);
    u16 *source;

    if (paletteData != NULL) {
        if (buffer == 0) {
            source = PaletteData_GetUnfadedBuf(paletteData, 0);
            state->apply = sub_020165D4;
        } else {
            source = PaletteData_GetUnfadedBuf(paletteData, 1);
            state->apply = sub_020165F0;
        }
    } else {
        if (buffer == 0) {
            source = GetMainBgPlttAddr();
            state->apply = sub_020165A4;
        } else {
            source = GetSubBgPlttAddr();
            state->apply = sub_020165BC;
        }
    }
    MIi_CpuCopy16(source + palette * 16, state->source, 0x20);
    MIi_CpuCopy16(source + palette * 16, state->current, 0x20);
    state->task = task;
    state->paletteData = paletteData;
    state->buffer = buffer;
    state->palette = palette;
    state->state = 1;
    state->timer = 0;
    return state;
}

void sub_0201649C(PaletteFadeTask *state, u32 command) {
    switch (command) {
    case 0:
        state->state = 0;
        break;
    case 1:
        state->state = 2;
        break;
    case 2:
        state->state = 3;
        break;
    }
}

void sub_020164C4(PaletteFadeTask *state) {
    DestroySysTaskAndEnvironment(state->task);
}

void sub_020164D0(void *task, void *data) {
    PaletteFadeTask *state = data;
    switch (state->state) {
    case 0:
        state->timer = 0;
        state->state = 1;
        break;
    case 1:
        if (sub_02016548(state) == TRUE) {
            state->apply(state, state->current);
        }
        state->timer++;
        if (state->timer == 0x20) {
            state->timer = 0;
        }
        break;
    case 2:
        break;
    case 3:
        state->apply(state, state->source);
        DestroySysTaskAndEnvironment(task);
        break;
    }
}

BOOL sub_02016548(PaletteFadeTask *state) {
    u32 i;
    if (state->timer == 0) {
        for (i = 0; i < 16; i++) {
            if ((1 << i) & 0x7800) {
                state->current[i] = state->source[i];
            }
        }
        return TRUE;
    }
    if (state->timer == 24) {
        for (i = 0; i < 16; i++) {
            if ((1 << i) & 0x7800) {
                state->current[i] = state->source[15];
            }
        }
        return TRUE;
    }
    return FALSE;
}

void sub_020165A4(PaletteFadeTask *state, const u16 *source) {
    BG_LoadPlttData(0, source, 0x20, ((u32)state->palette << 21) >> 16);
}

void sub_020165BC(PaletteFadeTask *state, const u16 *source) {
    BG_LoadPlttData(4, source, 0x20, ((u32)state->palette << 21) >> 16);
}

void sub_020165D4(PaletteFadeTask *state, const u16 *source) {
    PaletteData_LoadPalette(state->paletteData, source, 0, ((u32)state->palette << 20) >> 16, 0x20);
}

void sub_020165F0(PaletteFadeTask *state, const u16 *source) {
    PaletteData_LoadPalette(state->paletteData, source, 1, ((u32)state->palette << 20) >> 16, 0x20);
}
