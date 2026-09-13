#include "global.h"

#include "r40_overlay_103_residual_11_private.h"
#define PTR(c, o) (*(void **)((c) + (o)))

u32 ov103_021ED7E4(R40Ov103Work11 *work) {
    u32 input = TouchscreenListMenu_HandleInput(PTR(work->ctx, 0x244));
    switch (input) {
    case 0:
        ov103_021ECFFC(work);
        ov103_021EE888(work);
        ov103_021EE0CC(work->ctx, 2, 1);
        ov103_021EE60C(work->ctx);
        ov103_021EE374(work->ctx);
        ov103_021EDBB0(work);
        return 15;
    case 1:
        ov103_021ECFFC(work);
        ov103_021EE8A8(work, 0);
        return ov103_021EDA70(work, 0, 17);
    case 2: {
        u32 item;
        ov103_021ECFFC(work);
        item = MailToItemId(Mail_GetType(PTR(work->ctx + work->selected * 4, 0x27C)));
        ov103_021EDC68(work, 14, item, 0);
        work->field18 = 0;
        work->field28 = 6;
        return ov103_021EDA40(work, 1);
    }
    case 3:
    case -2:
        ov103_021ECFFC(work);
        ov103_021EE888(work);
        sub_0201980C(PTR(work->ctx, 4), 10);
        ov103_021EDB60(work->ctx, 0);
        ov103_021EE0CC(work->ctx, 2, 1);
        return 9;
    case -1:
    default:
        return 14;
    }
}
