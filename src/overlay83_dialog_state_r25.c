#include "global.h"

extern int ov83_022450A8(u8 *work, int a, int b);
extern void ov83_02245ACC(u8 *work, int index, int mode);
extern void ov83_0224563C(u8 *work, int index);
extern int ov83_0224776C(u8 a, u8 b);
extern int ov83_02244E24(u8 *work, int value, u8 mode);
extern int ov83_02244F60(u8 *work, int value, u8 mode);
extern void ov83_02245094(u8 *work);
extern void sub_02037BEC(void);
extern void sub_02037AC0(int);
extern int sub_02037B38(int);
extern void sub_020379A0(int);

int ov83_02243C88(u8 *work);
int ov83_02243D7C(u8 *work);

int ov83_02243C88(u8 *work) {
    switch (work[8]) {
    case 0:
        work[0xF] = (work[0xF] & ~0xF8) | 8;
        if (ov83_022450A8(work, 0x15, work[0xD]) == 1) {
            work[0x10] = 0;
            work[8]++;
        }
        break;
    case 1:
        if (work[0x11] != 0xFF) {
            u8 mode;
            u8 index;
            work[0x17] = 0;
            mode = work[0x13];
            index = work[0x11];
            if (mode == 5) {
                ov83_02245ACC(work, index, 5);
            } else {
                ov83_0224563C(work, index);
            }
            work[8]++;
        }
        break;
    case 2: {
        int value = ov83_0224776C(work[0x15], work[0x11]);
        if (ov83_02244E24(work, value, work[0x13]) == 1) {
            work[0x16] = 30;
            work[8]++;
        }
        break;
    }
    case 3:
        work[0x16]--;
        if (work[0x16] == 0) {
            sub_02037BEC();
            sub_02037AC0(0x85);
            work[8]++;
        }
        break;
    case 4:
        if (sub_02037B38(0x85) == 1) {
            work[8]++;
        }
        break;
    case 5: {
        int value = ov83_0224776C(work[0x15], work[0x11]);
        if (ov83_02244F60(work, value, work[0x13]) == 1) {
            sub_02037BEC();
            sub_020379A0(0x6B);
            work[0x11] = 0xFF;
            work[0x5B6] = 0;
            return 1;
        }
        break;
    }
    }
    return 0;
}

int ov83_02243D7C(u8 *work) {
    switch (work[8]) {
    case 0:
        if (ov83_022450A8(work, 0x17, 0) == 1) {
            work[0x16] = 30;
            work[8]++;
        }
        break;
    case 1:
        if (work[0x16] != 0) {
            work[0x16]--;
        }
        if (work[0x16] == 0) {
            sub_02037BEC();
            sub_02037AC0(0x86);
            work[8]++;
        }
        break;
    case 2:
        if (sub_02037B38(0x86) == 1) {
            sub_02037BEC();
            ov83_02245094(work + 0xC0);
            return 1;
        }
        break;
    }
    return 0;
}
