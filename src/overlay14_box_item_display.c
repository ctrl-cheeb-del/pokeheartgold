#include "overlay14_box_item_display_private.h"

void ov14_021E7470(void *p, void *mon) {
    u32 base = ov14_021F5404(p, mon);
    u32 i;

    for (i = 0; i < 4; i++) {
        sub_02019A60(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0x10, (u8 *)PTR_AT(p, 0x34) + 0x30 + (base + i) * 0x10);
    }
    ov14_021E88A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F36DC(p, mon, 2);
    ov14_021F2A18(PTR_AT(p, 0x34), (U16_AT(PTR_AT(p, 0x34), 0x88d0) ^ 1) + 2, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88d0) + 2, 0);
    ov14_021F3D70(PTR_AT(p, 0x34), mon);
    ov14_021F5368(p, mon);
    ov14_021E895C(p, U16_AT(mon, 0x10));
}

void ov14_021E74F0(void *p, void *mon) {
    u32 base;

    if (U16_AT(mon, 6) != 0) {
        base = ov14_021F5564(p, U16_AT(mon, 6));
        sub_02019A60(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0x10, (u8 *)PTR_AT(p, 0x34) + 0x30 + base * 0x10);
        sub_02019A60(PTR_AT(PTR_AT(p, 0x34), 0x2f0), 0x10, (u8 *)PTR_AT(p, 0x34) + 0x30 + (base + 1) * 0x10);
        ov14_021F38B0(PTR_AT(p, 0x34), U16_AT(mon, 6));
    }
    ov14_021E8944(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    ov14_021F36DC(p, mon, 2);
    ov14_021F2A18(PTR_AT(p, 0x34), (U16_AT(PTR_AT(p, 0x34), 0x88d0) ^ 1) + 2, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88d0) + 2, 0);
    ov14_021F3D70(PTR_AT(p, 0x34), mon);
    ov14_021F5368(p, mon);
    ov14_021E895C(p, U16_AT(mon, 0x10));
}

BOOL ov14_021E7588(void *p, u32 index) {
    void *view;
    u32 lock;
    void *boxMon = ov14_021E60C0(p, U8_AT(p, 0x1f), index);

    if (boxMon != NULL) {
        lock = AcquireBoxMonLock(boxMon);
        view = ov14_021E7358(boxMon);
        if (view != NULL) {
            if (U32_AT(PTR_AT(p, 0), 8) == 3) {
                ov14_021E74F0(p, view);
            } else {
                ov14_021E7470(p, view);
            }
            ov14_021E7468(view);
        } else {
            ov14_021E765C(p);
            ReleaseBoxMonLock(boxMon, lock);
            return FALSE;
        }
        ReleaseBoxMonLock(boxMon, lock);
    } else {
        ov14_021E765C(p);
        return FALSE;
    }
    return TRUE;
}

void ov14_021E75F4(void *p, u32 index) {
    void *boxMon = ov14_021E60C0(p, U8_AT(p, 0x1f), index);
    u32 lock = AcquireBoxMonLock(boxMon);
    void *view = ov14_021E7358(boxMon);

    ov14_021F36DC(p, view, 2);
    ov14_021F2A18(PTR_AT(p, 0x34), (U16_AT(PTR_AT(p, 0x34), 0x88d0) ^ 1) + 2, 1);
    ov14_021F2A18(PTR_AT(p, 0x34), U16_AT(PTR_AT(p, 0x34), 0x88d0) + 2, 0);
    ov14_021F3D70(PTR_AT(p, 0x34), view);
    ov14_021F5368(p, view);
    ov14_021E7468(view);
    ReleaseBoxMonLock(boxMon, lock);
}

void ov14_021E765C(void *p) {
    ov14_021F2A18(PTR_AT(p, 0x34), 2, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 3, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xd, 0);
    ov14_021F2A18(PTR_AT(p, 0x34), 0xe, 0);
    ov14_021F53C0(PTR_AT(p, 0x34));
    ov14_021E895C(p, 0);
    if (U32_AT(PTR_AT(p, 0), 8) == 3) {
        ov14_021E8944(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    } else {
        ov14_021E88A4(PTR_AT(PTR_AT(p, 0x34), 0x2f0));
    }
}
