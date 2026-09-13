#include "r40_overlay_96_residual_54_residual_3_private.h"

void ov96_021F2B24(void *course, u32 *table, u32 a2, u32 a3, void *dest) {
    u8 *entry = ov96_021E60D8(course, a2, a3);

    U16_AT(dest, 0x8a) = table[entry[0]];
    U16_AT(dest, 0x8c) = *(u32 *)((u8 *)table + entry[3] * 4 + 0x14);
    U16_AT(dest, 0x8e) = *(u32 *)((u8 *)table + entry[3] * 4 + 0x14);
    U8_AT(dest, 0x89) = *(u32 *)((u8 *)table + entry[1] * 4 + 0x28);
}

void ov96_021F2B68(Ov96R54TaskWork *work, u16 value1, u16 value2, void *course) {
    work->value1C = value1;
    work->value1E = value2;
    work->state0 = 0;
    work->task4 = SysTask_CreateOnMainQueue((void (*)(void *, void *))ov96_021F2BB4, work, 0);
    work->taskC = SysTask_CreateOnMainQueue((void (*)(void *, void *))ov96_021F2C04, work, 1);
    work->course30 = course;
    *(volatile u32 *)0x04000018 = 2 << 22;
    work->task8 = SysTask_CreateOnMainQueue((void (*)(void *, void *))ov96_021F2CD0, work, 2);
}

void ov96_021F2BB4(void *task, Ov96R54TaskWork *work) {
    switch (work->state0) {
    case 0:
        if (work->task8 == NULL) {
            work->task10 = SysTask_CreateOnMainQueue(ov96_021F2D68, work, 3);
            work->state0++;
        }
        break;
    case 1:
        if (work->task10 == NULL) {
            u8 *state;
            work->task4 = NULL;
            work->state0 = 0;
            state = ov96_021E8A20(PokeathlonCourse_GetDataCopyArea(work->course30));
            state[8] = 1;
            SysTask_Destroy(task);
        }
        break;
    }
}

void ov96_021F2C04(void *task, Ov96R54TaskWork *work) {
    u16 value;

    switch (work->state1) {
    case 0:
        work->timer18++;
        if (work->timer18 <= 5) {
            value = (u8)work->timer18 * 12 / 5;
            G2x_SetBlendAlpha_(0x04000050, 0, 1, 12 - value, value + 4);
        } else {
            work->state1++;
        }
        break;
    case 1:
        ov96_021F31F0(work->data20, (u8)work->value1E);
        ov96_021F3298(work->data20, (u8)work->value1C);
        work->timer18 = 0;
        work->state1++;
        PlaySE(0x89f);
        break;
    case 2:
        work->timer18++;
        if (work->timer18 <= 5) {
            value = (u8)work->timer18 * 12 / 5;
            G2x_SetBlendAlpha_(0x04000050, 0, 1, value, 16 - value);
        } else {
            work->taskC = NULL;
            work->timer18 = 0;
            work->state1 = 0;
            SysTask_Destroy(task);
        }
        break;
    }
}

void ov96_021F2CD0(void *task, Ov96R54TaskWork *work) {
    s32 value;

    switch (work->state2) {
    case 0:
        work->timer1A++;
        value = (work->timer1A << 7) / 5;
        *(volatile u32 *)0x04000018 = ((0x80 - value) << 16) & 0x01ff0000;
        if (work->timer1A >= 5) {
            work->timer1A = 0;
            work->state2++;
        }
        break;
    case 1:
        work->timer1A++;
        if (work->timer1A >= 20) {
            work->timer1A = 0;
            work->state2++;
        }
        break;
    case 2:
        work->timer1A++;
        value = -(work->timer1A << 7) / 5;
        *(volatile u32 *)0x04000018 = (value << 16) & 0x01ff0000;
        if (work->timer1A >= 5) {
            work->timer1A = 0;
            work->task8 = NULL;
            work->state2 = 0;
            SysTask_Destroy(task);
        }
        break;
    }
}
