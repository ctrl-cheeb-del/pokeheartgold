#include "global.h"

typedef struct Slot {
    s16 count;
    u16 capacity;
    int *values;
} Slot;

typedef struct Work {
    u8 pad[0x11C];
    Slot slots[1];
} Work;

void ov45_0222FA40(Work *, int);
void ov45_0222FA74(Work *, int, int);
void ov45_0222FAF8(Work *, int, int);
int ov45_0222FB24(Work *, int, int);
int ov45_0222FB5C(Work *, int, int);

void ov45_0222FA40(Work *work, int which) {
    int i;
    work->slots[which].count = 0;
    for (i = 0; i < work->slots[which].capacity; i++) {
        work->slots[which].values[i] = -1;
    }
}

void ov45_0222FA74(Work *work, int value, int which) {
    int i;
    int freeSlot;
    if (ov45_0222FB24(work, value, which) == -1) {
        GF_ASSERT(work->slots[which].count < work->slots[which].capacity);
        if (work->slots[which].count < work->slots[which].capacity) {
            for (i = 0; i < work->slots[which].capacity; i++) {
                if (work->slots[which].values[i] == -1) {
                    freeSlot = i;
                    break;
                }
            }
            work->slots[which].values[freeSlot] = value;
            work->slots[which].count++;
        }
    }
}

void ov45_0222FAF8(Work *work, int value, int which) {
    int i = ov45_0222FB24(work, value, which);
    if (i != -1) {
        work->slots[which].values[i] = -1;
        work->slots[which].count--;
    }
}

int ov45_0222FB24(Work *work, int value, int which) {
    int i;
    for (i = 0; i < work->slots[which].capacity; i++) {
        if (work->slots[which].values[i] == value) {
            return i;
        }
    }
    return -1;
}

int ov45_0222FB5C(Work *work, int index, int which) {
    GF_ASSERT(index < work->slots[which].capacity);
    return work->slots[which].values[index];
}
