#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov90Work19 {
    u16 timer;
    u16 heapId;
    u8 state;
    u8 pad_005;
    u8 done;
    u8 mode;
    u8 result;
    u8 changed;
    u8 pad_00A[0x14 - 0xA];
    u8 count;
    u8 selected;
    u8 flag16;
    u8 flag17;
    u32 *selection;
    u32 values[4];
    u8 inactive[4];
    u8 pad_030[0x3C - 0x30];
    void *players[4];
    u8 pad_04C[0x650 - 0x4C];
    u16 phase;
    u16 delay;
} Ov90Work19;

extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void GF_AssertFail(void);
extern BOOL IsPaletteFadeFinished(void);
extern void ScheduleSetBgPosText(void *, int, int, int);
extern void ov00_021E6A4C(void);
extern void sub_02037AC0(int);
extern BOOL sub_02037B38(int);
extern void ov90_02259170(void *);
extern void ov90_02259200(void *, void *);
extern void ov90_0225926C(void *, int);
extern void ov90_02259464(void *, void *, int, int);
extern void ov90_022594FC(void *, int);
extern BOOL ov90_02259538(void *, int);
extern void ov90_0225A088(void *, void *, u16);
extern void ov90_0225A108(void *);
extern u32 ov90_0225A28C(u32);
extern void ov90_0225B274(void *);
extern void ov90_0225B2A8(void *);
extern BOOL ov90_0225B38C(void *, void *, void *, int, u16);
extern u8 ov90_0225B538(void *);
extern void ov90_0225B7FC(void *, int, int);
extern BOOL ov90_0225B8F0(void *);
extern BOOL ov90_0225B978(void *);
extern void ov90_0225B9A8(void *);
extern int ov90_0225BA14(void *);
extern void ov90_0225BA38(void *);

void ov90_0225A980(void *, void *);

void ov90_0225A980(void *task, void *work) {
    Ov90Work19 *w = work;

    switch (w->state) {
    case 0: {
        int i;
        int value;
        U32_AT(w, 0x64C) = U32_AT(PTR_AT(w, 0x18), 0);
        if (w->flag17 == 1) {
            w->changed = 0;
        } else {
            value = ov90_0225BA14(w);
            i = w->selected;
            if (w->inactive[i] == 0 && w->values[i] > (u32)value) {
                U32_AT(PTR_AT(w, 0x18), 0) = ov90_0225A28C(U32_AT(PTR_AT(w, 0x18), 0));
                w->changed = 1;
            } else {
                w->changed = 0;
            }
            if (w->selected == 0) {
                ov90_0225BA38(w);
            }
        }
        BeginNormalPaletteFade(3, 1, 1, 0xFFFF, 6, 1, U16_AT(w, 2));
        w->state++;
        break;
    }
    case 1:
        if (IsPaletteFadeFinished()) {
            w->state++;
        }
        break;
    case 2:
        ov90_02259464((u8 *)w + 0x68, (u8 *)w + 0x58, 1, 0);
        w->state++;
        break;
    case 3:
        if (ov90_02259538((u8 *)w + 0x68, 0)) {
            w->timer = 0x40;
            w->state++;
        }
        break;
    case 4: {
        int i;
        u32 value;
        BOOL flag;
        if (w->timer == 0) {
            break;
        }
        w->timer--;
        if (w->timer != 0) {
            break;
        }
        flag = TRUE;
        ov90_022594FC((u8 *)w + 0x68, 0);
        ov90_0225A088((u8 *)w + 0x33C, (u8 *)w + 0x4C, w->heapId);
        value = ov90_0225BA14(w);
        for (i = 0; i < w->count; i++) {
            if (w->values[i] > value) {
                flag = 0;
            }
        }
        if (flag == 1) {
            w->delay = 0x10;
            w->state = 0x16;
        } else {
            w->state++;
            w->phase = 4;
        }
        break;
    }
    case 5: {
        int i;
        BOOL flag = FALSE;
        do {
            w->phase--;
            for (i = 0; i < w->count; i++) {
                if (w->phase == w->inactive[i]) {
                    flag = 1;
                }
            }
        } while (flag == 0);
        switch (w->phase) {
        case 2:
        case 3:
            w->delay = 0x10;
            break;
        case 0:
        case 1:
            w->delay = 0x20;
            break;
        default:
            GF_AssertFail();
            break;
        }
        ov90_0225B8F0(w);
        w->state++;
        break;
    }
    case 6: {
        int i;
        BOOL flag;
        w->delay--;
        ov90_0225B8F0(w);
        if (w->delay == 0) {
            for (i = 0; i < w->count; i++) {
                flag = 0;
                if (w->phase == w->inactive[i]) {
                    flag = 1;
                } else if (w->phase == 1 && w->inactive[i] == 0) {
                    flag = 1;
                }
                if (flag) {
                    ov90_0225B7FC(w, i, w->inactive[i]);
                }
            }
            if (w->phase > 1) {
                w->state = 5;
            } else {
                w->state++;
            }
        }
        break;
    }
    case 7:
        if (ov90_0225B8F0(w)) {
            w->state++;
        }
        break;
    case 8:
        w->state++;
        ov90_0225B274(w);
        w->timer = 0x1E;
        break;
    case 9:
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            w->state = 10;
            w->timer = 0;
        }
        break;
    case 10: {
        int i;
        int value;
        i = w->selected;
        if (w->inactive[i] == 0) {
            value = 0x11;
        } else {
            value = 0x12;
        }
        ov90_02259200((u8 *)w + 0x58, w->players[i]);
        ov90_02259464((u8 *)w + 0x68, (u8 *)w + 0x58, value, 0);
        w->state++;
        break;
    }
    case 11:
        if (ov90_02259538((u8 *)w + 0x68, 0) && ov90_0225B978(w) == 1) {
            if (w->flag17 == 1) {
                w->timer = 0x66;
                w->state = 14;
            } else {
                w->timer = 0x66;
                w->state++;
            }
        }
        break;
    case 12: {
        int i;
        int value;
        if (w->timer != 0) {
            w->timer--;
            break;
        }
        if (w->changed != 0) {
            ov90_0225926C((u8 *)w + 0x58, U32_AT(PTR_AT(w, 0x18), 0));
            if (U32_AT(w, 0x64C) == U32_AT(PTR_AT(w, 0x18), 0)) {
                value = 0x13;
            } else {
                value = 2;
            }
        } else {
            value = 9;
        }
        i = w->selected;
        ov90_02259200((u8 *)w + 0x58, w->players[i]);
        ov90_02259464((u8 *)w + 0x68, (u8 *)w + 0x58, value, 0);
        w->state = 13;
        break;
    }
    case 13:
        if (ov90_02259538((u8 *)w + 0x68, 0)) {
            w->timer = 0x66;
            w->state++;
        }
        break;
    case 14:
        if (w->timer == 0) {
            break;
        }
        w->timer--;
        if (w->timer != 0) {
            break;
        }
        ov90_022594FC((u8 *)w + 0x68, 0);
        w->timer = 0x1E;
        w->state++;
        break;
    case 15:
        if (w->timer != 0) {
            w->timer--;
            break;
        }
        sub_02037AC0(0x82);
        if (w->flag16 != 0) {
            ov00_021E6A4C();
        }
        w->state++;
        break;
    case 16:
        if (sub_02037B38(0x82)) {
            if (w->flag17 != 0) {
                w->state = 0x13;
            } else {
                w->state++;
            }
        }
        break;
    case 17:
        BeginNormalPaletteFade(3, 0, 0, 0, 6, 1, w->heapId);
        w->state++;
        break;
    case 18:
        if (IsPaletteFadeFinished()) {
            w->state = 0x15;
        }
        break;
    case 19:
        ov90_0225B9A8(w);
        w->state++;
        break;
    case 20:
        if (ov90_0225B38C((u8 *)w + 0x1E8, (u8 *)w + 0x68, (u8 *)w + 0x58, w->mode, w->heapId)) {
            w->result = ov90_0225B538((u8 *)w + 0x1E8);
            w->state++;
        }
        break;
    case 21:
        ov90_0225A108((u8 *)w + 0x33C);
        w->done = 1;
        break;
    case 22:
        w->delay--;
        if (w->delay == 0) {
            w->state++;
        }
        break;
    case 23: {
        int i;
        for (i = 0; i < w->count; i++) {
            w->inactive[i] = w->count - 1;
            ov90_0225B7FC(w, i, w->inactive[i]);
        }
        w->state = 7;
        break;
    }
    default:
        break;
    }
    ov90_0225B2A8(w);
    ov90_02259170((u8 *)w + 0xA0);
    ScheduleSetBgPosText(PTR_AT(w, 0x4C), 3, 4, 2);
    ScheduleSetBgPosText(PTR_AT(w, 0x4C), 5, 4, 2);
}
