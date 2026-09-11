#include "unk020127b8_sol_partial_internal.h"

BOOL sub_02012A2C(u8 *work) {
    (*(s32 *)(work + 0x320))++;
    if (*(s32 *)(work + 0x320) >= *(s32 *)(work + 0x31c)) {
        *(s32 *)(work + 0x320) = 0;
        if (*(s32 *)(work + 0x318) + 1 <= *(s32 *)(work + 0x314)) {
            (*(s32 *)(work + 0x318))++;
            sub_02012A90(work);
            sub_020110C4(work);
        } else {
            sub_020110F4(*(void **)(work + 0x330), work, *(u32 *)(work + 0x328));
            return TRUE;
        }
    }
    return FALSE;
}
