#include "global.h"

void sub_020196E8(void *arg0, int arg1, int arg2, int arg3);
void sub_020198FC(void *arg0, int arg1, int arg2, int arg3, int arg4);
void ov14_021F5C84(void *arg0, int arg1);
void ov14_021E81B4(void *arg0);
void ov14_021E81D8(void *arg0);
void ov14_021E81FC(void *arg0);

void ov14_021E81B4(void *arg0) {
    sub_020196E8(arg0, 13, 0, -7);
    sub_020198FC(arg0, 13, 0, 1, 7);
}

void ov14_021E81D8(void *arg0) {
    sub_020196E8(arg0, 13, 0, 0);
    sub_020198FC(arg0, 13, 0, -1, 7);
}

void ov14_021E81FC(void *arg0) {
    ov14_021F5C84(arg0, 0);
    sub_020196E8(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x34) + 0x2F0), 8, 0, 21);
}
