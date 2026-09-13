#include "global.h"

#include "heap.h"
#include "unk_020379A0.h"

extern BOOL ov83_02241368(u8 *p, int a, int b);
extern void ov83_02241BC4(u8 *p, int index, int kind);
extern void ov83_022418E8(u8 *p, int index, int kind);
extern BOOL ov83_02240FAC(u8 *p, int a, int b);
extern u8 ov83_0224776C(u8 subtrahend, u8 value);
extern void ov83_02241354(void *window);
extern void ov83_02240290(u8 *p);
extern void ov83_022477EC(int index, int value, u32 *word);

int ov83_0223EEA0(u8 *p);
int ov83_0223EFA4(u8 *p);

int ov83_0223EEA0(u8 *p) {
    switch (p[8]) {
    case 0:
        p[0xE] &= ~0x60;
        ov83_022477EC(2, 0, (u32 *)(p + 0x868));
        if (ov83_02241368(p, 0xB, p[0xD]) == TRUE) {
            p[0xE] &= ~2;
            p[8]++;
        }
        break;
    case 1:
        if (p[0x12] != 0xFF) {
            u8 kind;
            p[0xF] = 0;
            kind = p[0x13];
            if (kind == 4 || kind == 8) {
                ov83_02241BC4(p, p[0x12], kind);
            } else {
                ov83_022418E8(p, p[0x12], kind);
            }
            p[8]++;
        }
        break;
    case 2:
        if (ov83_02240FAC(p, ov83_0224776C(p[0x15], p[0x12]), p[0x13]) == TRUE) {
            p[0xB] = 30;
            p[8]++;
        }
        break;
    case 3:
        p[0xB]--;
        if (p[0xB] == 0) {
            sub_02037BEC();
            sub_02037AC0(0x82);
            p[8]++;
        }
        break;
    case 4:
        if (sub_02037B38(0x82) == TRUE) {
            sub_02037BEC();
            sub_020379A0(HEAP_ID_107);
            p[0x12] = 0xFF;
            if (((u32)p[0xE] << 25 >> 30) == 0) {
                ov83_02241354(p + 0xB0);
                ov83_02240290(p);
            }
            p[0x7FE] = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

int ov83_0223EFA4(u8 *p) {
    switch (p[8]) {
    case 0:
        if (ov83_02241368(p, 0xD, 0) == TRUE) {
            p[0xB] = 30;
            p[8]++;
        }
        break;
    case 1:
        if (p[0xB] != 0) {
            p[0xB]--;
        }
        if (p[0xB] == 0) {
            sub_02037BEC();
            sub_02037AC0(0x83);
            p[8]++;
        }
        break;
    case 2:
        if (sub_02037B38(0x83) == TRUE) {
            sub_02037BEC();
            ov83_02241354(p + 0xB0);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
