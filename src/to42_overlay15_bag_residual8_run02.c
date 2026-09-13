#include "to42_overlay15_bag_residual8_private.h"

int ov15_021FADE8(void *work, int value) {
    int result = -1;
    switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        if (ov15_021FA074(work) > value) {
            result = U32_AT(work, 0x66c);
            PlaySE(0x5dc);
        } else {
            PlaySE(0x5f3);
        }
        break;
    case 6:
        result = 14;
        break;
    case 7:
        result = 15;
        break;
    case 8:
        result = -2;
        break;
    }
    return result;
}
