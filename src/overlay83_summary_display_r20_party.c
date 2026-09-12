#include "overlay83_summary_display_r20_private.h"

void ov83_02241B30(u8 *work) {
    int count = ov80_02237B24(work[9], 1);
    int i = 0;
    u8 *walker;

    if (count > 0) {
        walker = work;
        do {
            void *mon = Party_GetMonByIndex(*(void **)(work + 0x7A4), i);
            u32 a = GetMonData(mon, 0xA3, NULL);
            u32 b = GetMonData(mon, 0xA4, NULL);
            u32 value = ov80_0222A43C((u16)a, (u16)b);

            if (*(Ov83SpriteWrap **)(walker + 0x73C) != NULL) {
                ov83_02247600(*(Ov83SpriteWrap **)(walker + 0x73C), value);
                if (i != ov83_02247768(work[0x14], work[0xD]) || work[0xD] >= work[0x15]) {
                    ov83_0224760C(*(Ov83SpriteWrap **)(walker + 0x73C), 0);
                } else {
                    ov83_0224760C(*(Ov83SpriteWrap **)(walker + 0x73C), 1);
                }
            }
            i++;
            walker += 4;
        } while (i < count);
    }
}
