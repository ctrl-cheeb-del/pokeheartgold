#include "overlay14_input_dispatch_r22_private.h"

u32 ov14_021EB7B0(void *work)
{
    PlaySE(0x5ea);
    ov14_021E637C(work);
    ov14_021F08F0(work);
    GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), 0x24);
    GridInputHandler_SetButtonInputMode(PTR_AT(PTR_AT(work, 0x34), 0x2c), 1);
    return 0xc;
}

void ov14_021EB7E4(void *work)
{
    u32 msg;
    u8 *field;

    ov14_021F6688(PTR_AT(work, 0x34), 0x25);
    switch (U32_AT(PTR_AT(work, 0), 8)) {
    case 1:
        ov14_021F5EE4(work, ov14_021F7D2C, 4);
        ov14_021F685C(work, U8_AT(work, 0x21), 1, 0x27);
        msg = 0x5a;
        break;
    case 0:
        ov14_021F5EE4(work, ov14_021F7D1C, 4);
        ov14_021F685C(work, U8_AT(work, 0x21), 1, 0x27);
        msg = 0x72;
        break;
    case 2:
    default:
        ov14_021F5EE4(work, ov14_021F7D3C, 5);
        msg = U8_AT(work, 0x21) < 0x1e ? 0x4d : 0x4e;
        break;
    }
    field = (u8 *)PTR_AT(work, 0x34) + 0x44e;
    if (((u32)(*field << 24) >> 31) == 1) {
        *field &= ~0x80;
        if (U8_AT(work, 0x21) >= 0x1e) {
            ov14_021F3488(work, 2, 0);
        } else {
            ov14_021F43F4(PTR_AT(work, 0x34), 1);
            ov14_021F3488(work, 1, 0);
        }
    }
    ov14_021E8434(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
    ov14_021F0234(work, ov14_021E9434, msg);
}

void ov14_021EB8C0(void *work)
{
    u32 msg;

    ov14_021E7588(work, U8_AT(work, 0x21));
    if (U8_AT(work, 0x26) == 0) {
        if (U32_AT(PTR_AT(work, 0), 8) == 1) {
            ov14_021F5EE4(work, ov14_021F7D2C, 4);
        } else if (U32_AT(PTR_AT(work, 0), 8) == 0) {
            ov14_021F43F4(PTR_AT(work, 0x34), 0);
            ov14_021F3488(work, 1, 1);
            ov14_021F5EE4(work, ov14_021F7D1C, 4);
        } else {
            if (U8_AT(work, 0x21) >= 0x1e) {
                ov14_021F3488(work, 1, 1);
                if (U8_AT(work, 0x24) != 0) {
                    ov14_021E8664(work);
                }
            } else if (U8_AT(work, 0x24) != 0) {
                ov14_021E8664(work);
            }
            ov14_021F5EE4(work, ov14_021F7D3C, 5);
            ov14_021E87F4(work);
        }
        ov14_021E83C4(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
        if (U8_AT(work, 0x21) < 0x1e) {
            if (U32_AT(PTR_AT(work, 0), 8) == 1) {
                ov14_021F685C(work, U8_AT(work, 0x21), 1, 0x27);
                msg = 0x51;
            } else {
                msg = 0xc;
            }
        } else if (U32_AT(PTR_AT(work, 0), 8) == 0) {
            ov14_021F0BF4(work);
            ov14_021F685C(work, U8_AT(work, 0x21), 1, 0x27);
            msg = 0x5b;
        } else {
            ov14_021F0B70(work);
            ov14_021F43F4(PTR_AT(work, 0x34), 0);
            ov14_021F6AC0(work, 5, 9);
            msg = 0x24;
        }
        ov14_021F3F6C(work);
        if (U32_AT(PTR_AT(work, 0), 8) != 3) {
            ov14_021E8874(PTR_AT(work, 0x34));
        }
    } else {
        ov14_021F0BB4(work);
        ov14_021E8610(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
        ov14_021F4720(work);
        ov14_021F4848(work);
        ov14_021F48B4(work);
        ov14_021F57B8(work);
        ov14_021E86E0(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
        while (ov14_021E9554(work) != 0) {
        }
        if (U8_AT(work, 0x27) == 0) {
            ov14_021F6AC0(work, 4, U8_AT(work, 0x21));
        } else {
            ov14_021F6AC0(work, 4, U8_AT(work, 0x28));
            U8_AT(PTR_AT(work, 0x34), 0x44b) = 1;
            ov14_021EA1F0(work);
        }
        U32_AT(PTR_AT(work, 0x34), 0x43c) = U8_AT(work, 0x25) % 6 + 0x25;
        if (U32_AT(PTR_AT(work, 0), 8) == 3) {
            ov14_021F3488(work, 0x81, 1);
            ov14_021F3488(work, 0x82, 1);
            msg = 0x82;
        } else if (U8_AT(work, 0x27) == 0) {
            msg = 0x29;
        } else {
            msg = 0x73;
        }
        if (U32_AT(PTR_AT(work, 0), 8) != 3 && U8_AT(work, 0x27) != 0) {
            ov14_021E8874(PTR_AT(work, 0x34));
        }
        if (U8_AT(work, 0x29) == 1) {
            ov14_021F43F4(PTR_AT(work, 0x34), 0);
        }
        U8_AT(work, 0x26) = 0;
        U8_AT(work, 0x28) = 0;
        U8_AT(work, 0x27) = 0;
    }
    ov14_021F01D8(work, msg);
}

void ov14_021EBAEC(void *work)
{
    ov14_021F6AC0(work, 9, 10);
    U32_AT(PTR_AT(work, 0x34), 0x43c) = U8_AT(work, 0x25) % 6;
    ov14_021E8740(work);
    ov14_021F6844(work, 0, 0x27);
    if (U32_AT(PTR_AT(work, 0), 8) == 3) {
        ov14_021F3488(work, 0x81, 1);
    }
    ov14_021F01D8(work, 0x3d);
}

void ov14_021EBB3C(void *work)
{
    u32 msg;
    u32 special;
    void *entry;
    u8 *row;
    u8 pos[2];

    if (U8_AT(work, 0x21) >= 0x1e) {
        ov14_021F0B70(work);
        ov14_021F43F4(PTR_AT(work, 0x34), 0);
        ov14_021F3488(work, 1, 1);
    }
    if (U32_AT(PTR_AT(work, 0), 8) != 3) {
        ov14_021F3F6C(work);
    }
    if ((u32)(U32_AT(PTR_AT(work, 0), 8) - 2) <= 1) {
        ov14_021E87F4(work);
        ov14_021E82FC(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
    }
    if (U16_AT(work, 0x1c) == 0) {
        if (U32_AT(PTR_AT(work, 0), 8) == 3) {
            ov14_021F5FBC(work, 0);
            if (U8_AT(work, 0x21) < 0x1e) {
                ov14_021F3488(work, 0x81, 1);
                msg = 0x75;
            } else {
                ov14_021F3488(work, 0x82, 1);
                ov14_021F6AC0(work, 7, 8);
                msg = 0x8b;
            }
        } else {
            ov14_021F5EE4(work, ov14_021F7D3C, 5);
            if (U8_AT(work, 0x21) < 0x1e) {
                msg = 0xc;
            } else {
                ov14_021F6AC0(work, 5, 10);
                msg = 0x24;
            }
        }
        ov14_021E83C4(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
    } else {
        special = 0;
        if (U16_AT(work, 0x1c) == 0x70 &&
            ov14_021E6070(work, U8_AT(work, 0x21), 5, 0) != 0x1e7) {
            special = 1;
        } else {
            entry = ov14_021E60C0(work, U8_AT(work, 0x1f), U8_AT(work, 0x21));
            ov14_021E6094(work, U8_AT(work, 0x21), 6, (u8 *)work + 0x1c);
            if (ov14_021E64D0(entry) == 1) {
                row = (u8 *)PTR_AT(work, 0x34) + U8_AT(work, 0x21);
                ov14_021F2ED0(work, U8_AT(work, 0x1f), U8_AT(work, 0x21),
                    U8_AT(row, 0x4094));
            }
            Bag_TakeItem(PTR_AT(work, 0xc), U16_AT(work, 0x1c), 1, 10);
        }
        if (U8_AT(work, 0x21) >= 0x1e) {
            if (U32_AT(PTR_AT(work, 0), 8) == 3) {
                ov14_021F6AC0(work, 7, U8_AT(work, 0x21) - 0x1e);
            } else {
                ov14_021F6AC0(work, 5, 10);
            }
        } else if (U32_AT(PTR_AT(work, 0), 8) == 3) {
            GridInputHandler_SetNextInput(PTR_AT(PTR_AT(work, 0x34), 0x2c), U8_AT(work, 0x21));
            DpadMenuBox_GetPosition(
                GridInputHandler_GetDpadBox(PTR_AT(PTR_AT(work, 0x34), 0x2c), U8_AT(work, 0x21)),
                &pos[1], &pos[0]);
            ManagedSprite_SetPositionXY(PTR_AT(PTR_AT(work, 0x34), 0x320), pos[1], pos[0]);
        }
        ov14_021F2A18(PTR_AT(work, 0x34), 9, 0);
        if (U32_AT(PTR_AT(work, 0), 8) == 3) {
            if (special == 0) {
                U16_AT(PTR_AT(work, 0x34), 0x88c8) = U16_AT(work, 0x1c);
                ov14_021F3844(PTR_AT(work, 0x34), U16_AT(PTR_AT(work, 0x34), 0x88c8));
                ov14_021F2A18(PTR_AT(work, 0x34), 0xb, 1);
                if (U8_AT(work, 0x21) >= 0x1e) {
                    ov14_021F3488(work, 0x82, 1);
                    ov14_021F396C(PTR_AT(work, 0x34), U8_AT(work, 0x21), 1);
                } else {
                    ov14_021F3488(work, 0x81, 1);
                    ov14_021F396C(PTR_AT(work, 0x34), U8_AT(work, 0x21), 0);
                }
                ov14_021F39D0(PTR_AT(work, 0x34));
                ov14_021F3B3C(PTR_AT(work, 0x34));
            } else {
                U16_AT(work, 0x1c) = 0;
                if (U8_AT(work, 0x21) >= 0x1e) {
                    ov14_021F3488(work, 0x82, 1);
                } else {
                    ov14_021F3488(work, 0x81, 1);
                }
            }
            msg = 0x7d;
        } else {
            if (special == 1) {
                U16_AT(work, 0x1c) = 0;
            }
            msg = 0x12;
        }
    }
    ov14_021E7588(work, U8_AT(work, 0x21));
    if (U32_AT(PTR_AT(work, 0), 8) != 3) {
        ov14_021E8874(PTR_AT(work, 0x34));
    } else if (U16_AT(work, 0x1c) != 0) {
        ov14_021E892C(PTR_AT(PTR_AT(work, 0x34), 0x2f0));
    }
    ov14_021F01D8(work, msg);
}
