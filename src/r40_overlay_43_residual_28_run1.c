#include "r40_overlay_43_residual_28_private.h"

void ov43_0222DDA0(void *p, void *context) {
    void *template = ov43_0222EF20;
    int i = 0;
    void *window = ADD(p, 0x118);

    for (; i < 8; i++) {
        AddWindow(PTRAT(context, 0), window, template);
        FillWindowPixelBuffer(window, 0);
        template = ADD(template, 8);
        window = ADD(window, 0x10);
    }
}

void ov43_0222DDD0(void *p) {
    int i = 0;
    void *window;

    window = ADD(p, 0x118);
    for (; i < 8; i++) {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        window = ADD(window, 0x10);
    }
}

void ov43_0222DDF0(Ov43WindowState *state, u32 unused, const u16 *values, void *owner) {
    int i;

    state->value0 = values[0];
    state->value2 = values[1];
    state->value4 = values[2];
    state->owner = owner;
    for (i = 0; i < 8; i++) {
        state->first[i] = 0;
        state->second[i] = 0;
    }
}
