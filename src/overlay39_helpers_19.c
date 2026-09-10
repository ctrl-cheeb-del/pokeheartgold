#include "overlay39_helpers_internal.h"

BOOL ov39_02228A70(u32 printerId) {
    if (printerId == 0xFF || !TextPrinterCheckActive((u8)printerId)) {
        return FALSE;
    }
    return TRUE;
}

void ov39_02228A8C(Ov39App *app) {
    if (app->unk88 == NULL) {
        app->unk88 = WaitingIcon_New((u8 *)app + 0x44, 1);
    }
}

void ov39_02228AA8(Ov39App *app) {
    if (app->unk88 != NULL) {
        sub_0200F450(app->unk88);
        app->unk88 = NULL;
    }
}
