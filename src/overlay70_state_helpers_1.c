#include "overlay70_state_helpers_1_private.h"

int ov70_02240640(Ov70Work *work) {
    work->value36 = 1;
    ov70_02238E50(work, 9, 7);
    work->state2c = 0x24;
    return 3;
}

int ov70_02240658(Ov70Work *work) {
    work->value36 = 0;
    ov70_02238E50(work, 9, 8);
    work->state2c = 0x24;
    return 3;
}

int ov70_02240670(Ov70Work *work) {
    ov70_02238E50(work, 9, 9);
    work->state2c = 0x24;
    return 3;
}

int ov70_02240684(Ov70Work *work) {
    work->value36 = 0;
    ov70_02238E50(work, 9, 10);
    work->state2c = 0x1e;
    return 3;
}

int ov70_0224069C(Ov70Work *work) {
    ov70_022380EC(work);
    work->state2c = 0x17;
    work->timer1604 = 0;
    return 3;
}

int ov70_022406B8(Ov70Work *work) {
    if (ov70_02237F38()) {
        int result = ov70_02237F58() + 15;
        work->timer1604 = 0;
        switch (result) {
        case 15:
            ov70_022404D4(work);
            break;
        case 12:
            ov70_022404D4(work);
        case 11:
            ov70_022404D4(work);
        case 10:
            sub_02039AD8(3);
            break;
        case 0:
        case 1:
        case 3:
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

int ov70_02240748(Ov70Work *work) {
    ov70_02244FA4(work, work->ptrBA0, 0x93, 1, 0xf0f);
    ov70_02238D84(work, 0x25, 0x24);
    ov70_02238E50(work, 1, 0);
    ov70_02238F80(work);
    ov70_02241234(work);
    return 3;
}

void ov70_0224078C(Ov70Work *work) {
    int value = 0x9a;
    switch (work->value3c + 15) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        value = 0x1a;
        break;
    case 14:
        value = 0x97;
        break;
    case 1:
    case 13:
        value = 0x9c;
        break;
    }
    ov70_02244FA4(work, work->ptrBA0, value, 1, 0xf0f);
}

int ov70_022407E4(Ov70Work *work) {
    ov70_0224078C(work);
    ov70_02238D84(work, 0x25, 0x24);
    ov70_02238E50(work, 0, 0);
    ov70_02238F80(work);
    return 3;
}

int ov70_0224080C(Ov70Work *work) {
    ov70_0224078C(work);
    ov70_02238D84(work, 0x25, 0x24);
    ov70_02238E50(work, 1, 0);
    ov70_02238F80(work);
    ov70_02241234(work);
    return 3;
}
