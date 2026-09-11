#include "global.h"
extern void *ov14_021F6628(void *);
extern void ov14_021F6638(void *);
extern void ov14_021F4FBC(void *, void *, int, int, int, int, int, int, int);
extern void ScheduleWindowCopyToVram(void *);
extern void DestroyMsgData(void *);
void ov14_021F6698(void *, int, int);
extern void ov14_021F6698(void *, int, int);
extern void BufferItemName(void *, int, int);
void ov14_021F66E8(void *, int, int);
void ov14_021F6704(void *, int, int);
void ov14_021F6724(void *, int);
void ov14_021F6730(void *, int);
void ov14_021F673C(void *, int, int);
void ov14_021F675C(void *, int);
void ov14_021F6768(void *, int, int);
void ov14_021F67A4(void *, int);

void ov14_021F6698(void *p, int msgno, int window) {
    void *msg = ov14_021F6628(p);
    int off = window << 4;
    ov14_021F6638((u8 *)*(void **)((u8 *)p + 0x34) + 0x30 + off);
    ov14_021F4FBC(*(void **)((u8 *)p + 0x34), msg, window, msgno, 0, 0, 1, 0x1020f, 0);
    ScheduleWindowCopyToVram((u8 *)*(void **)((u8 *)p + 0x34) + 0x30 + off);
    DestroyMsgData(msg);
}

void ov14_021F66E8(void *p, int x, int kind) {
    if (kind == 1) {
        ov14_021F6698(p, 11, x);
    } else {
        ov14_021F6698(p, 12, x);
    }
}

void ov14_021F6704(void *p, int item, int x) {
    void *q = *(void **)((u8 *)p + 0x34);
    BufferItemName(*(void **)((u8 *)q + 0x24), 0, item);
    ov14_021F6698(p, 23, x);
}

void ov14_021F6724(void *p, int x) {
    ov14_021F6698(p, 24, x);
}

void ov14_021F6730(void *p, int x) {
    ov14_021F6698(p, 54, x);
}

void ov14_021F673C(void *p, int item, int x) {
    void *q = *(void **)((u8 *)p + 0x34);
    BufferItemName(*(void **)((u8 *)q + 0x24), 0, item);
    ov14_021F6698(p, 15, x);
}

void ov14_021F675C(void *p, int x) {
    ov14_021F6698(p, 14, x);
}

void ov14_021F6768(void *p, int item, int x) {
    if (item == 0) {
        BufferItemName(*(void **)((u8 *)*(void **)((u8 *)p + 0x34) + 0x24), 0, 0x70);
        ov14_021F6698(p, 55, x);
    } else {
        BufferItemName(*(void **)((u8 *)*(void **)((u8 *)p + 0x34) + 0x24), 0, item);
        ov14_021F6698(p, 16, x);
    }
}

void ov14_021F67A4(void *p, int x) {
    ov14_021F6698(p, 35, x);
}
