#include "to45_overlay_70_r8_private.h"

void ov70_0223BD90(R14Work *w, int value) {
    switch (value) {
    case 0:
        U32(w, 0x2c) = 3;
        PlaySE(0x5dc);
        break;
    case 1:
        if (*(s16 *)(w + 0xb8a) != 0) {
            u32 stat = GetMonBaseStat(*(s16 *)(w + 0xb8a), 0x12);
            U32(P(w, 0x11c4), 0x20) = stat;
            if (ov70_0223EDE4(w + 0xb8a, U32(P(w, 0x11c4), 0x20))) {
                PlaySE(0x5dc);
                break;
            }
        }
        U32(w, 0x2c) = 6;
        PlaySE(0x5dc);
        break;
    case 2:
        U32(w, 0x2c) = 9;
        PlaySE(0x5dc);
        break;
    case 3:
        U32(w, 0x2c) = 0xc;
        PlaySE(0x5dc);
        break;
    case 4:
        if (U32(w, 0x128) != 0) {
            U32(w, 0x2c) = 0x1d;
            BeginNormalPaletteFade(0, 0, 0, 0, 0x10, 1, 0x3d);
            PlaySE(0x5dc);
        }
        break;
    case 5:
        U32(w, 0x2c) = 0xf;
        break;
    case 6:
        ov70_0223CAC4(w, 0xf, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 0x17);
        PlaySE(0x5dc);
        break;
    }
}

int ov70_0223BE84(R14Work *w) {
    int result = ov70_0223BD80();

    if (result != -1) {
        ov70_0223C420(w, result);
        ov70_0223BD90(w, result);
    } else {
        ov70_0223C304(w);
        if (gSystem.newKeys & 1) {
            ov70_0223BD90(w, (int)ov70_0223C2EC(w));
        } else if (gSystem.newKeys & 2) {
            ov70_0223CAC4(w, 0xf, 1, 0, 0xf0f);
            ov70_02238D84(w, 0x15, 0x17);
            PlaySE(0x5dc);
        }
    }
    return 3;
}

int ov70_0223BF00(R14Work *w) {
    if (*(s16 *)(w + 0xb8a) == 0) {
        ov70_0223CAC4(w, 0xc, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 1);
        PlaySE(0x5f3);
    } else if (ov70_0223CC68(w + 0xb8a, w + 0xb90, U32(w, 0x12cc), U32(w, 0xb98))) {
        ov70_0223CAC4(w, 0x21, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 1);
        PlaySE(0x5f3);
    } else {
        PlaySE(0x5fe);
        ov70_0223CAC4(w, 0xd, 1, 0, 0xf0f);
        ov70_02238D84(w, 0x15, 0x10);
        ov70_02241234(w);
    }
    return 3;
}

int ov70_0223BFA8(void *arg, int which) {
    RTCDate saved;
    RTCDate current;
    RTCTime time;
    u32 packed;
    s32 delta;

    if (which == 1) {
        packed = sub_0202DB90(**(void ***)arg);
    } else {
        packed = sub_0202DB80(**(void ***)arg);
    }
    saved.year = (packed >> 24) & 0xff;
    saved.month = (packed >> 16) & 0xff;
    saved.day = (packed >> 8) & 0xff;
    saved.week = (RTCWeek)(packed & 0xff);
    ov00_021ECB94(&current, &time);
    delta = RTC_ConvertDateToDay(&current) - RTC_ConvertDateToDay(&saved);
    return delta >= 0 && delta < 3;
}

int ov70_0223C008(Ov70R8Work *w) {
    int selection = 3;
    Ov70InputRecord record;

    if (ov70_0223BFA8(w, 1)) {
        selection += 2;
    }
    if (ov70_0223BFA8(w, 0)) {
        selection += 2;
    }
    if (w->extra == 0) {
        ov70_02238130(&w->current, selection, w->mapRecord);
    } else {
        MI_CpuFill8(&record, 0, sizeof(record));
        record.species = w->current.species;
        record.a = w->current.a;
        record.b = w->current.b;
        record.c = w->current.c;
        record.d = w->current.d;
        record.selection = selection;
        record.extra = w->extra;
        ov70_022381A4(&record, w->mapRecord);
    }
    *(u16 *)&w->stored.species = *(u16 *)&w->current.species;
    *(u16 *)&w->stored.a = *(u16 *)&w->current.a;
    *(u16 *)&w->stored.c = *(u16 *)&w->current.c;
    w->storedExtra = w->extra;
    w->counter = 0;
    w->state = 0x11;
    w->changed = 0;
    return 3;
}

int ov70_0223C0C8(R14Work *w) {
    if (ov70_02237F38()) {
        int value = ov70_02237F58();
        U32(w, 0x1604) = 0;
        switch (value) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            U32(w, 0x128) = value;
            StopSE(0x5fe);
            ov70_02241184(w, value, 1);
            if (value == 0) {
                ov70_0223CC04(P(w, 4), w + 0x10d8, P(w, 0xba0), 0);
            } else {
                ov70_0223CC04(P(w, 4), w + 0x10d8, P(w, 0xba0), 1);
            }
            U32(w, 0x2c) = 0x12;
            break;
        case -14:
        case -2:
            U32(w, 0x2c) = 0x1b;
            break;
        case -13:
            sub_020399EC();
            break;
        case -15:
        case -12:
            U32(w, 0x2c) = 0x14;
            break;
        }
    } else {
        U32(w, 0x1604)
        ++;
        if (U32(w, 0x1604) == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}
