#include "to42_overlay15_r16_private.h"

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FCD80(void *work) {
    if (!TextPrinterCheckActive(U8(work, 0x616))) {
        if (U16(work, 0x682) > 99) {
            U16(work, 0x682) = 99;
        }
        ov15_021FD574(work, 4, 0, 0);
        ov15_02200300(work, 2, U16(work, 0x682));
        ov15_021FF7FC(work);
        ov15_021FF29C(work, 1);
        ov15_022004DC(work, 1);
        ov15_021FFFDC(work, 0);
        return 18;
    }
    return 17;
}
