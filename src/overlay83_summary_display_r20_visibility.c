#include "overlay83_summary_display_r20_private.h"

void ov83_02242844(u8 *work, int value) {
    if (value == 1) {
        u32 i = 0x12;
        void *window = work + 0x170;

        for (; i <= 0x2F; i++, window = (u8 *)window + 0x10) {
            ScheduleWindowCopyToVram(window);
        }
        ov83_0224755C(*(Ov83SpriteWrap **)(work + 0x780), 1);
    } else {
        void *window;
        u32 i;

        i = 0x12;
        window = work + 0x170;
        for (; i <= 0x2F; i++, window = (u8 *)window + 0x10) {
            ClearWindowTilemapAndScheduleTransfer(window);
        }
        ov83_0224755C(*(Ov83SpriteWrap **)(work + 0x780), 0);
    }
}
