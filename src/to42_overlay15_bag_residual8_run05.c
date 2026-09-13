#include "to42_overlay15_bag_residual8_private.h"

void ov15_021FB380(void *work, const u8 *choices) {
    U32_AT(work, 0x66c) = 0;
    ov15_021FFECC(work, ov15_02201468[U32_AT(work, 0x66c)]);
    ov15_0220023C(work, choices);
    ov15_021FF758((u8 *)work + 0x184, (u8 *)work + 0x300, choices[0]);
    ov15_021FF758((u8 *)work + 0x194, (u8 *)work + 0x300, choices[1]);
    ov15_021FF758((u8 *)work + 0x1a4, (u8 *)work + 0x300, choices[2]);
    ov15_021FF758((u8 *)work + 0x1b4, (u8 *)work + 0x300, choices[3]);
}
