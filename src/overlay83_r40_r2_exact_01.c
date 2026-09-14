#include "overlay83_r40_r2_private.h"
void ov83_02246CC0(void *p) {
    int message;
    if (U32_AT(p, 0x600) != U8_AT(PTR_AT(p, 0x5F8), 0x24)) {
        switch (((Ov83MenuEntry *)PTR_AT(p, 0x5FC))[U8_AT(PTR_AT(p, 0x5F8), 0x24)].message) {
        case 0:
            message = 12;
            break;
        case 1:
            message = 13;
            break;
        case 2:
            message = 14;
            break;
        case -2:
            message = 15;
            break;
        }
        ov83_022447E0(p, (u8 *)p + 0xC0, message, 1, 1, 0xFF, 1, 2, 15, 1);
        U32_AT(p, 0x600) = U8_AT(PTR_AT(p, 0x5F8), 0x24);
    }
}

void ov83_02246D40(void *p) {
    int message;
    int variant;
    if (U32_AT(p, 0x600) != U8_AT(PTR_AT(p, 0x5F8), 0x24)) {
        variant = ov83_0224777C(PTR_AT(p, 0x2BC), U8_AT(p, 9), 2) == 1 ? 0 : 1;
        switch (((Ov83MenuEntry *)PTR_AT(p, 0x5FC))[U8_AT(PTR_AT(p, 0x5F8), 0x24)].message) {
        case 3:
            message = ov83_02248024[variant];
            break;
        case 4:
            message = ov83_02248028[variant];
            break;
        case 5:
            message = ov83_0224802C[variant];
            break;
        case -2:
            message = ov83_02248030[variant];
            break;
        }
        ov83_022447E0(p, (u8 *)p + 0xC0, message, 1, 1, 0xFF, 1, 2, 15, 1);
        U32_AT(p, 0x600) = U8_AT(PTR_AT(p, 0x5F8), 0x24);
    }
}
