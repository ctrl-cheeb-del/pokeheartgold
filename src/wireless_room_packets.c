#include "wireless_room_packets_internal.h"

void *sub_0208F814(void *arg) {
    return sub_0203410C(_021054B4, 0x6e, arg);
}

void sub_0208F828(void *a, void *b, void *data, Work *work) {
    if (sub_0203769C() != 0) {
        int offset = U8(data, 0x3ec) * 0x3e8;
        if (offset > 0x3840) {
            MIi_CpuCopyFast((const u32 *)data, (u32 *)(&work->raw[0x43d0] + offset), 0x190);
        } else {
            MIi_CpuCopyFast((const u32 *)data, (u32 *)(&work->raw[0x43d0] + offset), 0x3e8);
        }
        MIi_CpuCopyFast((const u32 *)&work->raw[0x43d0], (u32 *)PTR(work, 0x2d4), 0x3840);
        CopyWindowToVram(&work->raw[0x2c8]);
    } else {
        WorkProgress *progress = (WorkProgress *)work;
        if (progress->progress * 0x3e8 < 0x3840) {
            progress->progress++;
            sub_0208FAF8(work, U32(work, 0x43cc));
        } else {
            sub_02037108(0x7c, 0, 0);
        }
    }
}

void sub_0208F8BC(int index, void *unused, const u8 *src, Work *work) {
    if (index != 0) {
        work = (Work *)((u8 *)work + index * 10);
        *(TenBytes *)&work->raw[0x93bd] = *(const TenBytes *)src;
    }
}

void sub_0208F8E4(int index, void *unused, const u8 *src, Work *work) {
    if (work != 0 && index == 0) {
        int row = 0;
        do {
            *(TenBytes *)&work->raw[0x4382] = *(const TenBytes *)src;
            row++;
            src += 10;
            work = (Work *)((u8 *)work + 10);
        } while (row < 5);
    }
}

void sub_0208F918(void *a, void *b, void *c, Work *work) {
    ov37_021E6FC8(work, 3, 0);
    MIi_CpuClearFast(0, (u32 *)&work->raw[0x43d0], 0x3840);
    if (sub_0203769C() == 0) {
        U32(work, 0x318) = sub_02037454();
        U32(work, 0x31c) = sub_02033250();
        U32(work, 0x93f4) = 1;
    }
}

void sub_0208F960(int id, void *unused, const FourBytes *packet, Work *work) {
    FourBytes local;
    if (id != 0) {
        if (sub_0203769C() != 0) {
            return;
        }
        local = *packet;
        local.data[0] = id;
        local.data[1] = U32(work, 0x318);
        switch (packet->data[2]) {
        case 0:
            if (sub_02037454() != U32(work, 0x318) || ov37_021E75E0() != U32(work, 0x318) || MATH_CountPopulation(sub_02033250()) != U32(work, 0x318)) {
                local.data[3] = 0;
            } else {
                U32(work, 0x93b4) |= 1 << id;
                local.data[3] = 1;
                sub_02038C1C(sub_02037454());
            }
            break;
        case 1:
            break;
        }
        sub_02037108(0x7e, &local, 4);
    } else {
        int sender;
        switch (packet->data[2]) {
        case 0:
            sender = packet->data[0];
            if (sender != sub_0203769C()) {
                return;
            }
            if (packet->data[3] == 0) {
                ov37_021E6FC8(work, 9, sender);
            } else {
                U16(work, 0x93b8) = packet->data[1];
                ov37_021E6FC8(work, 8, packet->data[0]);
            }
            break;
        case 1:
            ov37_021E6FC8(work, 0x15, packet->data[0]);
            break;
        default:
            return;
        }
    }
}

void sub_0208FA50(void) {
}

void sub_0208FA54(void *a, void *b, const u8 *data, Work *work) {
    ov37_021E6FC8(work, 1, data[0]);
    if (sub_0203769C() == 0 && U32(work, 0x300) == 1) {
        U32(work, 0x43cc) = 0;
        sub_0208FAF8(work, U32(work, 0x43cc));
    }
}

void sub_0208FA88(void) {
}
void sub_0208FA8C(void) {
}

void sub_0208FA90(void *a, void *b, void *c, Work *work) {
    if (sub_0203769C() != 0) {
        ov37_021E6FC8(work, 15, 0);
    }
}

void sub_0208FAA8(int value, void *b, void *c, Work *work) {
    u8 packet;
    if (sub_0203769C() != 0) {
        GF_AssertFail();
    }
    if (sub_0203769C() == 0) {
        if (U32(work, 0x93fc) != 0) {
            packet = value;
            sub_02037108(0x7b, &packet, 1);
        } else {
            U32(work, 0x93fc) = 1;
        }
    }
    sub_020398D4(0, 1);
}

void sub_0208FAEC(void *a, void *b, void *c, Work *work) {
    U32(work, 0x93f4) = 1;
}

void sub_0208FAF8(Work *work, int index) {
    MIi_CpuCopyFast((const u32 *)((u8 *)PTR(work, 0x2d4) + index * 0x3e8), (u32 *)&work->raw[0x7c10], 0x3e8);
    {
        int i;
        u32 checksum;
        u32 *p;
        checksum = 0;
        i = checksum;
        p = (u32 *)&work->raw[0x7c10];
        do {
            checksum ^= *p;
            p++;
            i++;
        } while (i < 0xfa);
        U32(work, 0x7ff8) = checksum;
    }
    U8(work, 0x7ffc) = index;
    sub_02037088(0x76, &work->raw[0x7c10], 0x3f0);
}

void *sub_0208FB4C(int index, void *base) {
    return (u8 *)base + 0x8000 + index * 0x3f0;
}

int sub_0208FB5C(void) {
    return 4;
}
int sub_0208FB60(void) {
    return 4;
}
