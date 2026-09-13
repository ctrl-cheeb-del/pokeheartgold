#include "global.h"

#include "r40_overlay_103_residual_15_private.h"

void ov103_021EDE7C(R40Ov103Work15 *work) {
    if (work->flag21_7 == 0) {
        ov103_021EE8A8(work, 3);
    } else {
        ov103_021EE8A8(work, 4);
    }
    ov103_021EDA70(work, 1, 0x18);
}

void ov103_021EDEA8(R40Ov103Work15 *work) {
    u32 i;
    const u8 *tpl;
    u32 offset;
    GfGfx_EngineATogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(0x10, 1);
    ov103_021EE13C(work->ctx);
    ov103_021EDF88(work->ctx);
    ov103_021EE2E0(work->ctx);
    ov103_021EE160(work->ctx);
    i = 0;
    tpl = ov103_021EED58;
    offset = i;
    for (; i < 7; i++, tpl += 0x34, offset += 4) {
        *(void **)(work->ctx + 0x258 + offset) = ov103_021EE048(work->ctx, tpl);
    }
    if (*(u16 *)(work->ctx + 0x2E0) <= 10) {
        ov103_021EE0CC(work->ctx, 0, 0);
        ov103_021EE0CC(work->ctx, 1, 0);
    } else if (work->flag1c == 0) {
        ov103_021EE0CC(work->ctx, 0, 0);
    } else {
        ov103_021EE0CC(work->ctx, 1, 0);
    }
    ov103_021EE0CC(work->ctx, 4, 0);
    ov103_021EE0CC(work->ctx, 5, 0);
    ov103_021EE0CC(work->ctx, 6, 0);
}
