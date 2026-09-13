#include "r40_unk_02033668_private.h"

BOOL sub_02033668(int mode, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5) {
    int value;
    if (sub_020340C4(sub_0203993C())) {
        WM_SetLifeTime(sub_02033664, 0xFFFF, 100, 5, 100);
    }
    *(u32 *)(_021D4124.work + 0x1308) = 0x1C0;
    *(u32 *)(_021D4124.work + 0x1304) = 0xE0;
    *(u32 *)(_021D4124.work + 0x1314) = mode;
    sub_02032844(3);
    *(u16 *)(_021D4124.work + 0xC) = a1;
    *(u16 *)(_021D4124.work + 0x32) = a2;
    *(u16 *)(_021D4124.work + 0x18) = a4;
    switch (mode) {
    case 0:
        *(u16 *)(_021D4124.work + 0x34) = 0xC0;
        if (a3 >= 5) {
            *(u16 *)(_021D4124.work + 0x36) = 0xC;
        } else {
            *(u16 *)(_021D4124.work + 0x36) = 0x26;
        }
        break;
    case 4:
        *(u16 *)(_021D4124.work + 0x34) = 0x64;
        *(u16 *)(_021D4124.work + 0x36) = 0xC;
        break;
    }
    *(u16 *)(_021D4124.work + 0x10) = a3;
    value = 0;
    *(u16 *)(_021D4124.work + 0x16) = value;
    *(u16 *)(_021D4124.work + 0x12) = value;
    *(u16 *)(_021D4124.work + 0xE) = a5;
    if (mode == 2) {
        value = 1;
    }
    *(u16 *)(_021D4124.work + 0x14) = value;
    if (mode == 0 || mode == 2 || mode == 4) {
        return sub_02032874();
    }
    return FALSE;
}

BOOL sub_0203373C(int mode, const void *data) {
    if (sub_020340C4(sub_0203993C())) {
        WM_SetLifeTime(sub_02033664, 0xFFFF, 100, 5, 100);
    }
    *(u32 *)(_021D4124.work + 0x1308) = 0x200;
    *(u32 *)(_021D4124.work + 0x1304) = 0x40;
    *(u32 *)(_021D4124.work + 0x1314) = mode;
    sub_02032844(3);
    if (mode == 1 || mode == 3 || mode == 5) {
        MI_CpuCopy8(data, _021D4124.work + 0x1220, 0xC0);
        DC_FlushRange(_021D4124.work + 0x1220, 0xC0);
        DC_WaitWriteBufferEmpty();
        return sub_02032E9C();
    }
    return FALSE;
}
