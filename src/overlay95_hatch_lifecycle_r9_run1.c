#include "overlay95_hatch_lifecycle_r9_private.h"

BOOL ov95_021E6838(void *work) {
    switch (U32_AT(work, 0x68)) {
    case 0:
        if (ov95_021E5EDC(PTR_AT(work, 0x44)) != 1) {
            ManagedSprite_SetAnimationFrame(PTR_AT(work, 0x74), 1);
            U32_AT(work, 0x68)
            ++;
        }
        break;
    case 1:
        if (ov95_021E6150(work, 0) == 2) {
            PlaySE(0x714);
            ManagedSprite_SetAnimationFrame(PTR_AT(work, 0x74), 2);
            U32_AT(work, 0x68)
            ++;
            U32_AT(work, 0x64) = 0;
        }
        break;
    default:
        if (ov95_021E6150(work, 0) == 2) {
            ManagedSprite_SetAnimationFrame(PTR_AT(work, 0x74), 2);
            U32_AT(work, 0x68) = 0;
            U32_AT(work, 0x64) = 0;
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL ov95_021E68A8(void *work) {
    switch (U32_AT(work, 0x68)) {
    case 0:
        U32_AT(work, 0x68)
        ++;
        break;
    case 1: {
        u32 status = ov95_021E6150(work, 1);
        if (status == 1) {
            PlaySE(0x714);
            ManagedSprite_SetAnimationFrame(PTR_AT(work, 0x74), 3);
            ov95_021E5EC0(PTR_AT(work, 0x44), 0);
        }
        if (status == 2) {
            U32_AT(work, 0x64) = 0;
            U32_AT(work, 0x68)
            ++;
        }
        break;
    }
    default:
        U32_AT(work, 0x68) = 0;
        U32_AT(work, 0x64) = 0;
        return FALSE;
    }
    return TRUE;
}

BOOL ov95_021E6900(void *work) {
    switch (U32_AT(work, 0x68)) {
    case 0:
        if (ov95_021E5EDC(PTR_AT(work, 0x44)) != 1) {
            U32_AT(work, 0x68)
            ++;
        }
        break;
    case 1: {
        u32 status = ov95_021E6150(work, 2);
        if (status == 1) {
            PlaySE(0x714);
            ManagedSprite_SetAnimationFrame(PTR_AT(work, 0x74), 4);
            ov95_021E5EC0(PTR_AT(work, 0x44), 1);
        }
        if (status == 2) {
            U32_AT(work, 0x64) = 0;
            U32_AT(work, 0x68)
            ++;
        }
        break;
    }
    default:
        U32_AT(work, 0x68) = 0;
        U32_AT(work, 0x64) = 0;
        return FALSE;
    }
    return TRUE;
}
