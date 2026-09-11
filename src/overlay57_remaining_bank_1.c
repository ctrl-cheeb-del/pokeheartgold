#include "overlay57_remaining_bank_internal.h"
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov57_0223B78C(Work *w) {
    int i;
    for (i = 0; i < 0x51; i++) {
        w->qty[i] = SealCaseInventory_GetSealQuantity(w->seals, i);
    }
}

void ov57_0223B7A8(Work *w) {
    int i;
    for (i = 0; i < 0x51; i++) {
        SealCaseInventory_SetSealQuantity(w->seals, i, w->qty[i]);
    }
}
