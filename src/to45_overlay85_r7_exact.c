#include "to45_overlay85_r7_private.h"

#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define S32_AT(p, n) (*(s32 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S16_AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

int ov85_021E60F0(Ov85R7Work *work) {
    if (U32_AT(work, 0x3c) == 1) {
        S32_AT(work, 0x110) = U16_AT(work, 0x5e) << 12;
        S32_AT(work, 0x11c) = S16_AT(work, 0x5c) << 12;
        U32_AT(work, 8) = U16_AT(work, 0x5a);
    }
    if (ov85_021E8570(work) == TRUE && ov85_021E8150(work) == FALSE) {
        U32_AT(work, 0) = 29;
        return TRUE;
    }
    if (U32_AT(work, 0x34) != 0 && ov85_021E8150(work) == FALSE) {
        ov85_021E8128(work);
    }
    if (ov85_021E834C(work) == 0 && ov85_021E750C(work) == TRUE) {
        if (ov85_021E8150(work) == FALSE) {
            ov85_021E8128(work);
            U32_AT(work, 0x38) = TRUE;
        }
        ov85_021E8358(work);
    }
    if (U32_AT(work, 0x38) != 0) {
        void *sub = PTR_AT(work, 0xcc);
        if (sub_02096D4C(PTR_AT(sub, 0x30), 10, (u8 *)work + 0x38, 1) == TRUE) {
            U32_AT(work, 0x38) = FALSE;
        }
    }
    if (ov85_021E8144(work) == TRUE) {
        ov85_021E7644((u8 *)work + 0xd4, S32_AT(work, 0x11c) * 2);
    } else {
        ov85_021E8558(work, S32_AT(work, 0x11c));
    }
    return FALSE;
}

int ov85_021E61C8(Ov85R7Work *work) {
    ov85_021E84EC(work, 0);
    PTR_AT(work, 0x28) = ov85_021E7958(work);
    if (S32_AT(PTR_AT(work, 0x28), 0xc) == sub_0203769C()) {
        U32_AT(work, 0) = 30;
    } else {
        U32_AT(work, 0) = 31;
    }
    PlaySE(0x5f1);
    return TRUE;
}

int ov85_021E61FC(Ov85R7Work *work) {
    ov85_021E8558(work, 0x4000);
    PTR_AT(work, 0x28) = ov85_021E7958(work);
    if (S32_AT(PTR_AT(work, 0x28), 0xc) != sub_0203769C()) {
        U32_AT(work, 0) = 31;
    }
    return FALSE;
}
