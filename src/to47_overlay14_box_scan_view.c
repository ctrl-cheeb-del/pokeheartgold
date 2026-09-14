#include "global.h"

#include "constants/pokemon.h"

#include "to47_overlay14_box_scan_view_private.h"

u32 ov14_021E7278(void *p) {
    void *r;
    u16 idx;
    u32 count;
    void *boxmon;
    u32 i;
    s32 bit;
    u32 boxId;
    u32 slot;

    r = PTR_AT(PTR_AT(p, 0x34), 0x88DC);
    idx = U16_AT(r, 4);
    if (idx == 0x222) {
        return 0;
    }
    count = 0;
    do {
        if (idx < 0x21C) {
            boxId = idx / 30;
            slot = idx % 30;
            if (boxId == U8_AT(p, 0x1F) && slot == U8_AT(p, 0x21)) {
                boxmon = NULL;
            } else {
                boxmon = ov14_021E60C0(p, boxId, slot);
            }
        } else {
            slot = idx - 0x21C;
            if (slot == U8_AT(p, 0x21) - 30) {
                boxmon = NULL;
            } else {
                boxmon = ov14_021E60C0(p, 0xFF, slot);
            }
        }
        if (boxmon != NULL && GetBoxMonData(boxmon, 0xAC, NULL) != 0) {
            for (i = 0; i < 4; i++) {
                bit = ov14_021E71C8((u16)GetBoxMonData(boxmon, i + 0x36, NULL));
                if (bit != -1) {
                    U8_AT(r, 6) &= 0xFF ^ (1 << bit);
                }
            }
        }
        U16_AT(r, 4)
        ++;
        idx = U16_AT(r, 4);
        if (idx == 0x222) {
            return 0;
        }
        count++;
    } while (count < 15);
    return 1;
}

Ov14BoxView *ov14_021E7358(void *boxMon) {
    Ov14BoxView *view;
    u32 i;

    if (GetBoxMonData(boxMon, 0xAC, NULL) != 0) {
        view = Heap_Alloc(0xA, sizeof(Ov14BoxView));
        view->boxMon = boxMon;
        view->species = GetBoxMonData(boxMon, 5, NULL);
        view->field6 = GetBoxMonData(boxMon, 6, NULL);
        view->field8 = GetBoxMonData(boxMon, 0, NULL);
        view->fieldC = GetBoxMonData(boxMon, 0xB1, NULL);
        view->fieldD = GetBoxMonData(boxMon, 0xB2, NULL);
        view->fieldE = GetBoxMonData(boxMon, 0xA, NULL);
        view->nature = GetBoxMonNature(boxMon);
        view->field10 = GetBoxMonData(boxMon, 0xB, NULL);
        view->field12 = GetBoxMonData(boxMon, 0xA1, NULL);
        view->field12Bit = GetBoxMonData(boxMon, 0x4C, NULL);
        view->gender = GetBoxMonGender(boxMon);
        if (view->species != 0x1D && view->species != 0x20 && view->field12Bit == 0) {
            view->showGender = 1;
        } else {
            view->showGender = 0;
        }
        for (i = 0; i < 4; i++) {
            view->moves[i] = GetBoxMonData(boxMon, 0x36 + i, NULL);
        }
    } else {
        view = NULL;
    }
    return view;
}
