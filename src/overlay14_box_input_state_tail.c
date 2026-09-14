#include "overlay14_box_input_state_tail_private.h"

u32 ov14_021ECDA8(void *p) {
    void *work = PTR_AT(PTR_AT(p, 0x34), 0xc);
    s32 selected = U32_AT(work, 0xe8);
    u32 current = U32_AT(work, 0xec);
    u32 high;

    PlaySE(0x5ea);
    ov14_021E637C(p);
    high = selected & 0x80;
    if (high == 0) {
        ov14_021E6548(p, U32_AT(work, 0xe4), U32_AT(work, 0xe8));
    }
    ov14_021F08F0(p);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
    if (U8_AT(p, 0x24) != 0) {
        ov14_021F57B8(p);
    }
    if (ov14_021E6070(p, U8_AT(p, 0x21), 0xac, 0) == 0) {
        ov14_021E765C(p);
        goto done;
    }
    if (selected != 0xff) {
        if (high == 0) {
            goto done;
        }
        ov14_021E7588(p, U8_AT(p, 0x21));
        goto done;
    } else {
        selected = U8_AT(p, 0x21);
        if ((u32)selected >= 0x1e) {
            if (current != selected) {
                selected -= 0x1e;
                void *mon = Party_GetMonByIndex(PTR_AT(p, 8), selected);
                if (ItemIdIsMail((u16)GetMonData(mon, 6, 0)) == 1) {
                    PlaySE(0x5f3);
                    ov14_021F685C(p, 0, 6, 0x25);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
                if (GetMonData(mon, 0xa2, 0) != 0) {
                    PlaySE(0x5f3);
                    ov14_021F685C(p, 0, 5, 0x25);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
                if (ov14_021E6480(p, selected) == 0) {
                    PlaySE(0x5f3);
                    ov14_021F67B0(p, 6, 0x25);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
            }
        }
    }
    if (current != 0xff && (current & 0x80) != 0) {
        u32 next = (current ^ 0x80) + (U8_AT(p, 0x25) / 6) * 6;
        if (U8_AT(p, 0x1f) != next) {
            s32 index = U8_AT(p, 0x21);
            if ((u32)index < 0x1e) {
                ov14_021F685C(p, 0, 4, 0x25);
            } else if (ov14_021E6480(p, index - 0x1e) == 1) {
                ov14_021F685C(p, 0, 4, 0x25);
            } else {
                ov14_021F67B0(p, 6, 0x25);
            }
            PlaySE(0x5f3);
            U32_AT(p, 0x30) = 0x2c;
            return 6;
        }
    }
done:
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 1);
    return 0x29;
}

u32 ov14_021ECF58(void *p) {
    void *work = PTR_AT(PTR_AT(p, 0x34), 0xc);
    s32 selected = U32_AT(work, 0xe8);
    u32 input;
    s32 index;

    PlaySE(0x5ea);
    ov14_021E637C(p);
    if ((selected & 0x80) == 0) {
        ov14_021E6548(p, U32_AT(work, 0xe4), U32_AT(work, 0xe8));
    }
    ov14_021F08F0(p);
    if (U8_AT(p, 0x24) != 0) {
        ov14_021F57B8(p);
    }
    input = GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c));
    if (U32_AT(PTR_AT(p, 0x34), 0x88cc) == 0 && selected == 0xff) {
        index = U8_AT(p, 0x21);
        if (input != index) {
            if ((u32)index >= 0x1e) {
                index -= 0x1e;
                void *mon = Party_GetMonByIndex(PTR_AT(p, 8), index);
                if (ItemIdIsMail((u16)GetMonData(mon, 6, 0)) == 1) {
                    PlaySE(0x5f3);
                    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
                    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
                    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
                    ov14_021F685C(p, 0, 6, 0x25);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
                if (GetMonData(mon, 0xa2, 0) != 0) {
                    PlaySE(0x5f3);
                    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
                    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
                    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
                    ov14_021F685C(p, 0, 5, 0x25);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
                if (ov14_021E6480(p, index) == 0) {
                    PlaySE(0x5f3);
                    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
                    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
                    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
                    ov14_021F67B0(p, 6, 0x25);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
            }
            if (input >= 0x25 && input <= 0x2a) {
                u32 next = (input - 0x25) + (U8_AT(p, 0x25) / 6) * 6;
                if (U8_AT(p, 0x1f) != next) {
                    index = U8_AT(p, 0x21);
                    if ((u32)index < 0x1e) {
                        ov14_021F685C(p, 0, 4, 0x25);
                    } else if (ov14_021E6480(p, index - 0x1e) == 1) {
                        ov14_021F685C(p, 0, 4, 0x25);
                    } else {
                        ov14_021F67B0(p, 6, 0x25);
                    }
                    PlaySE(0x5f3);
                    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c), U8_AT(p, 0x21));
                    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2c), 0);
                    ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
                    U32_AT(p, 0x30) = 0x2c;
                    return 6;
                }
            }
            if (U8_AT(p, 0x2a) == 0) {
                ov14_021E7588(p, GridInputHandler_GetNextInput(PTR_AT(PTR_AT(p, 0x34), 0x2c)));
            }
        }
    }
    if (U8_AT(p, 0x2a) != 0) {
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
        ov14_021E76B8(p);
        return ov14_021F0CD8(p);
    }
    if (input >= 0x25 && input <= 0x2a) {
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 0xe);
    } else {
        ov14_021F29E4(PTR_AT(p, 0x34), 9, 8);
    }
    return 0x29;
}
