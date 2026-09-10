#include "screen_window_effect_internal.h"

void sub_02013364(s32 a, s32 b, s32 c, s32 d, BOOL high, BOOL screen) {
    if (high == 0) {
        if (screen == 0) {
            u32 first = (a << 8 & 0xFF00) | ((u32)c << 24 >> 24);
            u32 second = (b << 8 & 0xFF00) | ((u32)d << 24 >> 24);
            *(volatile u16 *)0x04000040 = first;
            *(volatile u16 *)0x04000044 = second;
        } else {
            u32 first = (a << 8 & 0xFF00) | ((u32)c << 24 >> 24);
            u32 second = (b << 8 & 0xFF00) | ((u32)d << 24 >> 24);
            *(volatile u16 *)0x04001040 = first;
            *(volatile u16 *)0x04001044 = second;
        }
    } else {
        if (screen == 0) {
            u32 first = (a << 8 & 0xFF00) | ((u32)c << 24 >> 24);
            u32 second = (b << 8 & 0xFF00) | ((u32)d << 24 >> 24);
            *(volatile u16 *)0x04000042 = first;
            *(volatile u16 *)0x04000046 = second;
        } else {
            u32 first = (a << 8 & 0xFF00) | ((u32)c << 24 >> 24);
            u32 second = (b << 8 & 0xFF00) | ((u32)d << 24 >> 24);
            *(volatile u16 *)0x04001042 = first;
            *(volatile u16 *)0x04001046 = second;
        }
    }
}

void sub_02013424(Pair8 *base, s32 value, s32 slot) {
    Pair8 *args = &base[slot];
    args->a = value;
    args->b = slot;
    SysTask_CreateOnVWaitQueue(sub_020134BC, args, 1);
}

void sub_02013440(void *base, s32 a, s32 b, s32 slot, s32 group) {
    Quad16 *args = (Quad16 *)((u8 *)base + 0x10 + group * 0x20 + slot * 0x10);
    args->a = a;
    args->b = b;
    args->c = slot;
    args->d = group;
    SysTask_CreateOnVWaitQueue(sub_020134D0, args, 1);
}

void sub_02013468(void *base, s32 a, s32 b, s32 slot) {
    Triple12 *args = (Triple12 *)((u8 *)base + 0x68 + slot * 12);
    args->a = a;
    args->b = b;
    args->c = slot;
    SysTask_CreateOnVWaitQueue(sub_020134EC, args, 1);
}

void sub_02013488(void *base, s32 a, s32 b, s32 c, s32 d, s32 slot, s32 group) {
    Window16 *args = (Window16 *)((u8 *)base + 0x80 + group * 0x20 + slot * 0x10);
    args->a = a;
    args->b = b;
    args->c = c;
    args->d = d;
    args->e = slot;
    args->f = group;
    SysTask_CreateOnVWaitQueue(sub_02013504, args, 1);
}

void sub_020134BC(SysTask *task, void *data) {
    Pair8 *args = data;
    sub_020131F4(args->a, args->b);
    SysTask_Destroy(task);
}

void sub_020134D0(SysTask *task, void *data) {
    Quad16 *args = data;
    sub_02013220(args->a, args->b, args->c, args->d);
    SysTask_Destroy(task);
}

void sub_020134EC(SysTask *task, void *data) {
    Triple12 *args = data;
    sub_020132A8(args->a, args->b, args->c);
    SysTask_Destroy(task);
}

void sub_02013504(SysTask *task, void *data) {
    Window16 *args = data;
    sub_02013364(args->a, args->b, args->c, args->d, args->e, args->f);
    SysTask_Destroy(task);
}
