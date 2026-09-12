#include "overlay57_capsule_main_r9_private.h"

BOOL ov57_0223A504(void *w) {
    switch (U32(w, 0x3fc)) {
    case 0:
        ov57_0223BC4C(w, PTR(w, 0x3ec));
        ov57_02239728((u8 *)w + 0xec, 0, 9, 1);
        U32(w, 0x3fc)
        ++;
        break;
    case 1:
        ov57_0223B12C();
        if ((U32(gSystem, 0x48) & 0xcf3) || System_GetTouchNew()) {
            U32(w, 0x3fc)
            ++;
        }
        break;
    case 2:
        ov57_0223B828(w, 0, 0xff, 0);
        sub_0200E5D4((u8 *)w + 0xec, 1);
        ClearWindowTilemapAndScheduleTransfer((u8 *)w + 0xec);
        ov57_0223866C(w, 1);
        ov57_02239728((u8 *)w + 0x11c, 3, 7, 0);
        break;
    }
    ov57_02238FC4(w);
    ov57_02239558(w);
    return TRUE;
}
