#include "overlay_80_02236B78_opus_partial_internal.h"

int ov80_02236DD4(int a0) {
    switch (a0) {
    case 0:
    case 1:
        return 3;
    case 2:
    case 3:
        return 2;
    }
    return 0;
}

int ov80_02236DF8(int a0, int a1) {
    switch (a0) {
    case 0:
    case 1:
        return 3;
    case 2:
    case 3:
        if (a1 == 0) {
            return 2;
        }
        return 4;
    }
    return 0;
}

void ov80_02236E24(int a0, int a1, u16 *a2, void *a3, u8 *a4, int a5, u16 a6, const u16 *a7) {
    const Ov80LevelRange *entry = ov80_02236C78(a0, a1);
    if (a7 == NULL) {
        ov80_02236C9C(NULL, NULL, 0, 6, a2, 11, entry, a6, a4);
    } else {
        ov80_02236C9C(a7, a7, 6, 6, a2, 11, entry, a6, a4);
    }
    ov80_0222A52C(a3, a2, a4, NULL, a5, 6, 11, 0xCD);
}
