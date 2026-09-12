#include "overlay70_pokegear_radio_ui_private.h"

int ov70_022403FC(Ov70Work *work) {
    ov70_02238E50(work, 1, 0);
    work->state2c = 0x24;
    return 3;
}

int ov70_02240410(Ov70Work *work) {
    ov70_02238008(work->unk13c);
    work->state2c = 0x1b;
    work->timer1604 = 0;
    return 3;
}

int ov70_02240430(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        work->timer1604 = 0;
        switch (result + 15) {
        case 15:
            if (ov70_02240D54(work)) {
                work->state2c = 0x16;
                work->value36 = 0;
                return 3;
            }
            work->value36 = 1;
            break;
        case 12:
            work->value36 = 0;
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            work->value3c = result;
            work->state2c = 0x26;
            return 3;
        case 2:
            sub_020399EC();
            return 3;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
            break;
        }
        ov70_022404D4(work);
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}

void ov70_022404D4(Ov70Work *work) {
    switch (work->unk1c) {
    case 1:
        ov70_02238E50(work, 1, 0);
        work->state2c = 0x24;
        break;
    case 2:
        ov70_02238E50(work, 2, 3);
        work->state2c = 0x24;
        break;
    }
}

void ov70_02240500(Ov70Work *work, void *mon) {
    GameStats_AddScore(work->unk00->unk28, 0x18);
    GameStats_Inc(work->unk00->unk28, 0x19);
    if (gGameLanguage != GetMonData(mon, 0xc, NULL)) {
        Pokewalker_UnlockCourse(Save_Pokewalker_Get(work->unk00->unk20), 0x14);
    }
}

int ov70_02240540(Ov70Work *work) {
    ov70_02240A7C(work, work->unk13c, sub_0202DBA0(work->unk00->unk00), work->unk25d);
    ov70_02240CE4(work->unk00->unk18, work->unk13c);
    ov70_02240500(work, work->unk13c);
    sub_0202DB5C(work->unk00->unk00, 0);
    work->state2c = 0x1e;
    ov70_02240D44(work, 0x13, 0xb);
    return 3;
}

int ov70_02240598(Ov70Work *work) {
    ov70_022380A8(work);
    work->state2c = 0x14;
    work->timer1604 = 0;
    return 3;
}

int ov70_022405B4(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58();
        work->timer1604 = 0;
        switch (result + 15) {
        case 15:
            work->state2c = 0x21;
            break;
        case 12:
            sub_02039AD8(3);
            break;
        case 3:
        case 11:
            work->value3c = result;
        case 0:
        case 1:
        case 13:
            sub_02039AD8(4);
            break;
        case 2:
            sub_020399EC();
            break;
        }
    } else {
        work->timer1604++;
        if (work->timer1604 == 0xe10) {
            sub_020399EC();
        }
    }
    return 3;
}
