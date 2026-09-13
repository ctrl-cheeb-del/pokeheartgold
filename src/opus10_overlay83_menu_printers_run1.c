#include "list_menu_items.h"
#include "overlay83_sol_partial_internal.h"

typedef struct Ov83MenuRect {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 f;
} Ov83MenuRect;

typedef struct Ov83MenuTemplate {
    Ov83MenuRect rect;
    ListMenuItem *items;
    MsgData *msgData;
    u8 count;
} Ov83MenuTemplate;

typedef struct Ov83MenuEntry {
    u32 threshold;
    int msgId;
    int kind;
} Ov83MenuEntry;

typedef struct Ov83MenuMsgPair {
    int msgId;
    int value;
} Ov83MenuMsgPair;

extern void *ov83_02247CCC(void *a, void *tmpl, int c, int d, u8 e);
extern int ov83_0223FC48(void *p, void *w, int msg, int x, int y, int speed, u8 fg, u8 sh, u8 bg, u8 font);
extern u8 ov83_0224777C(void *save, int mode, int index);
extern int ov80_02237B24(int value, int mode);

extern const u16 _02247D0C[];
extern const u16 ov83_02247D1E[];
extern const Ov83MenuMsgPair ov83_02247D6C[];
extern const Ov83MenuEntry ov83_02247EB0[];
extern const Ov83MenuEntry ov83_02247F4C[];
extern const u8 ov83_02248008[];

void ov83_02242AEC(void *p, int count, int c, int d, u8 e);
void ov83_02242BAC(void *p);
void ov83_02242BF0(void *p);
void ov83_02242CAC(void *p);
void ov83_02242D5C(void *p);
void ov83_02242DAC(void *p);
void ov83_02242DFC(void *p);
void ov83_02242E88(void *p);

void ov83_02242AEC(void *p, int count, int c, int d, u8 e) {
    Ov83MenuRect rect;
    Ov83MenuTemplate tmpl;
    u16 y, x;
    int n;

    ov83_02247988(&y, &x);
    rect = *(const Ov83MenuRect *)&_02247D0C[15];
    rect.d = y;
    rect.e = y + x - 0x1B;
    rect.f = x;
    tmpl.rect = rect;
    tmpl.items = *(ListMenuItem **)((u8 *)p + 0x844);
    tmpl.msgData = *(MsgData **)((u8 *)p + 0x4C);
    tmpl.count = count;
    *(void **)((u8 *)p + 0x840) = ov83_02247CCC(*(void **)((u8 *)p + 0x83C), &tmpl.rect, c, d, e);
    ((u8 *)p)[0xE] |= 0x10;
    n = ov80_02237B24(((u8 *)p)[9], 1);
    ov83_0224773C((Ov83SpriteWrap **)((u8 *)p + 0x73C), n, 1);
    ov83_0224773C((Ov83SpriteWrap **)((u8 *)p + 0x74C), n, 1);
}

void ov83_02242BAC(void *p) {
    u32 i;

    *(ListMenuItem **)((u8 *)p + 0x844) = ListMenuItems_New(3, HEAP_ID_107);
    for (i = 0; i < 3; i++) {
        ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247D6C[i].msgId, ov83_02247D6C[i].value);
    }
    ov83_02242AEC(p, 3, 0x11, 8, 0xD);
}

void ov83_02242BF0(void *p) {
    u8 count;
    u8 n;
    u8 i;

    *(ListMenuItem **)((u8 *)p + 0x844) = ListMenuItems_New(5, HEAP_ID_107);
    n = ov83_0224777C(*(void **)((u8 *)p + 0x50C), ((u8 *)p)[9], 0);
    count = 0;
    for (i = 0; i < 5; i++) {
        switch (ov83_02247F4C[i].kind) {
        case 1:
        case 2:
        case 3:
            if (n >= ov83_02247F4C[i].threshold) {
                ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247F4C[i].msgId, ov83_02247F4C[i].kind);
                count++;
            }
            break;
        case 4:
            if (n != 3) {
                ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247F4C[i].msgId, ov83_02247F4C[i].kind);
                count++;
            }
            break;
        default:
            ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247F4C[i].msgId, ov83_02247F4C[i].kind);
            count++;
            break;
        }
    }
    ov83_02242AEC(p, count, 0x11, ov83_02248008[count], 0xD);
}

void ov83_02242CAC(void *p) {
    u8 count;
    u8 n;
    u8 i;

    *(ListMenuItem **)((u8 *)p + 0x844) = ListMenuItems_New(4, HEAP_ID_107);
    n = ov83_0224777C(*(void **)((u8 *)p + 0x50C), ((u8 *)p)[9], 1);
    count = 0;
    for (i = 0; i < 4; i++) {
        switch (ov83_02247EB0[i].kind) {
        case 6:
        case 7:
            if (n >= ov83_02247EB0[i].threshold) {
                ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247EB0[i].msgId, ov83_02247EB0[i].kind);
                count++;
            }
            break;
        case 8:
            if (n != 3) {
                ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247EB0[i].msgId, ov83_02247EB0[i].kind);
                count++;
            }
            break;
        default:
            ListMenuItems_AppendFromMsgData(*(ListMenuItem **)((u8 *)p + 0x844), *(MsgData **)((u8 *)p + 0x20), ov83_02247EB0[i].msgId, ov83_02247EB0[i].kind);
            count++;
            break;
        }
    }
    ov83_02242AEC(p, count, 0x11, ov83_02248008[count], 0xD);
}

void ov83_02242D5C(void *p) {
    int n = ov80_02237B24(((u8 *)p)[9], 1);
    ov83_0224773C((Ov83SpriteWrap **)((u8 *)p + 0x73C), n, 0);
    ov83_0224773C((Ov83SpriteWrap **)((u8 *)p + 0x74C), n, 0);
    ov83_02247CE8(*(void **)((u8 *)p + 0x840));
    ListMenuItems_Delete(*(ListMenuItem **)((u8 *)p + 0x844));
    ((u8 *)p)[0xE] &= ~0x10;
}

void ov83_02242DAC(void *p) {
    u8 cursor = ((u8 *)*(void **)((u8 *)p + 0x840))[0x24];

    if (*(u32 *)((u8 *)p + 0x848) != cursor) {
        ov83_0223FC48(p, (u8 *)p + 0xB0, ov83_02247D1E[cursor], 1, 1, 0xFF, 1, 2, 0xF, 1);
        *(u32 *)((u8 *)p + 0x848) = ((u8 *)*(void **)((u8 *)p + 0x840))[0x24];
    }
}

void ov83_02242DFC(void *p) {
    u8 cursor = ((u8 *)*(void **)((u8 *)p + 0x840))[0x24];
    u8 n;
    int msg;

    if (*(u32 *)((u8 *)p + 0x848) != cursor) {
        switch ((u32)(*(ListMenuItem **)((u8 *)p + 0x844))[cursor].value) {
        case 4:
            n = ov83_0224777C(*(void **)((u8 *)p + 0x50C), ((u8 *)p)[9], 0);
            if (n == 3) {
                msg = 0x1B;
            } else if (n == 1) {
                msg = 0x19;
            } else {
                msg = 0x1A;
            }
            break;
        case (u32)LIST_CANCEL:
            msg = 0x1C;
            break;
        default:
            msg = 0x18;
            break;
        }
        ov83_0223FC48(p, (u8 *)p + 0xB0, msg, 1, 1, 0xFF, 1, 2, 0xF, 1);
        *(u32 *)((u8 *)p + 0x848) = ((u8 *)*(void **)((u8 *)p + 0x840))[0x24];
    }
}

void ov83_02242E88(void *p) {
    u8 cursor = ((u8 *)*(void **)((u8 *)p + 0x840))[0x24];
    u8 n;
    int msg;

    if (*(u32 *)((u8 *)p + 0x848) != cursor) {
        switch ((*(ListMenuItem **)((u8 *)p + 0x844))[cursor].value) {
        case 6:
            msg = 0x30;
            break;
        case 7:
            msg = 0x31;
            break;
        case 8:
            n = ov83_0224777C(*(void **)((u8 *)p + 0x50C), ((u8 *)p)[9], 1);
            if (n == 3) {
                msg = 0x34;
            } else if (n == 1) {
                msg = 0x32;
            } else {
                msg = 0x33;
            }
            break;
        default:
            msg = 0x35;
            break;
        }
        ov83_0223FC48(p, (u8 *)p + 0xB0, msg, 1, 1, 0xFF, 1, 2, 0xF, 1);
        *(u32 *)((u8 *)p + 0x848) = ((u8 *)*(void **)((u8 *)p + 0x840))[0x24];
    }
}
