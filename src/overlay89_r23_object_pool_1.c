#include "overlay89_r23_object_pool.h"

void ov89_0225AC24(u8 *work, Ov89Arg *arg, int slot) {
    if (arg->packed.bits.low == 0 || arg->packed.bits.mid == 1) {
        ov89_0225A988(work, arg->object);
    }
    ov89_0225AF7C(work, arg->packed.bits.high);
    ov89_0225AC10((u8 *)arg);
    *(u32 *)(work + 0xB4 + slot * 4) = 0;
}

void ov89_0225AC68(void *unused, int y, int x, s32 *outY, s32 *outX) {
    int i;
    (void)unused;
    i = y / 16;
    if ((u32)i >= 17) {
        i = 16;
    }
    *outY = ov89_0225CD6C[i];
    if ((u32)i < 16) {
        *outY += ((ov89_0225CD6C[i + 1] - ov89_0225CD6C[i]) / 16) * (y % 16);
    }
    i = x / 16;
    if ((u32)i >= 11) {
        i = 10;
    }
    *outX = ov89_0225CCE4[i];
    if ((u32)i < 10) {
        *outX += ((ov89_0225CCE4[i + 1] - ov89_0225CCE4[i]) / 16) * (x % 16);
    }
}

int ov89_0225AD00(u8 *work) {
    int i = 1;
    int one = 1;
    u32 value = *(u32 *)(work + 0x534);
    do {
        u32 mask = one << i;
        if (!(value & mask)) {
            *(u32 *)(work + 0x534) |= mask;
            return i;
        }
        i++;
    } while (i < 32);
    {
        int j = 0;
        if (i < 63) {
            int one2 = 1;
            u32 value2 = *(u32 *)(work + 0x538);
            do {
                u32 mask = one2 << j;
                if (!(value2 & mask)) {
                    *(u32 *)(work + 0x538) |= mask;
                    return i;
                }
                i++;
                j++;
            } while (i < 63);
        }
    }
    return 0xFF;
}

void ov89_0225AD64(u8 *work, int id) {
    int one = 1;
    if (id == 0xFF) {
        return;
    }
    if (id < 32) {
        u32 mask = one << id;
        *(u32 *)(work + 0x534) = (-1 ^ mask) & *(u32 *)(work + 0x534);
    } else {
        u32 mask = one << (id - 32);
        *(u32 *)(work + 0x538) = (-1 ^ mask) & *(u32 *)(work + 0x538);
    }
}
