#include "ov72_wave41_private.h"
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

int ov72_02237D88(int x) {
    int ret;
    switch (x) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
    case 14:
    case 20:
    case 21:
    case 22:
    case 23:
    case 32:
        ret = ~4;
        break;
    case 2:
    case 8:
    case 25:
        ret = ~4;
        break;
    case 11:
        ret = ~6;
        break;
    case 12:
    case 13:
        ret = ~6;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 26:
    case 27:
    case 28:
    case 29:
    case 31:
        ret = ~1;
        break;
    case 15:
    case 30:
        ret = ~1;
        break;
    default:
        ret = ~4;
        break;
    }
    if (ret != ~4) {
        if (WCM_GetPhase() != 9) {
            ret = ~5;
        }
        ov00_021EC210();
    }
    return ret;
}
