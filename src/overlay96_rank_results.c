#include "overlay96_rank_results_private.h"

void ov96_021EE290(Ov96RankEntry *values) {
    s32 i;
    u32 max = 0;
    s32 maxIndex;
    Ov96RankEntry *cursor;

    for (i = 0, cursor = values; i < 4; i++, cursor++) {
        if (cursor->uses == 0) {
            cursor->uses++;
            if (cursor->rank > max) {
                max = cursor->rank;
                maxIndex = i;
            }
        }
    }
    values[maxIndex].uses--;
    values[maxIndex].count++;
    MATH_QSort(values, 4, 4, ov96_021ECC58, NULL);
    values[0].count--;
}

static inline BOOL ov96_UpdateResult(void *course, BOOL second) {
    u32 all;
    u32 flag;
    u8 *previous;
    u8 *current;
    u8 *copy;
    u8 *work;
    u8 *entry;
    u8 participant;
    u8 state;
    s32 i;

    work = PokeathlonCourse_GetHeapAllocPtr4(course);
    copy = PokeathlonCourse_GetDataCopyArea(course);
    current = ov96_021E8A20(copy + 0x28);
    previous = ov96_021E8A20(copy + 0xf0);
    state = (u8)ov96_021E5F24(course);
    participant = work[0xb7];
    flag = 0;

    if (state == 0) {
        all = 1;
        if (second) {
            ((Ov96ResultB *)current)->participant = participant;
        } else {
            ((Ov96ResultA *)current)->participant = participant;
        }
        {
            u8 *dst = ov96_021E8A20(copy + 0x50);
            u8 *src = ov96_021E8A20(copy);
            u32 count = 0x24;

            do {
                *dst++ = *src++;
            } while (--count != 0);
        }
        for (i = 0; i < PokeathlonCourse_GetParticipantCount(course); i++) {
            entry = ov96_021E8A20(copy + 0x50 + i * 0x28);
            if (entry[0] < participant || entry[1] == 1) {
                flag = 1;
            }
            if (entry[2] == 0) {
                all = 0;
            }
        }
        if (second) {
            if (all != 0) {
                ((Ov96ResultB *)current)->all = 1;
            }
            ((Ov96ResultB *)current)->flag = flag;
        } else {
            if (all != 0) {
                ((Ov96ResultA *)current)->all = 1;
            }
            ((Ov96ResultA *)current)->flag = flag;
        }
    }
    entry = ov96_021E8A20(copy);
    entry[0] = participant;
    entry[1] = ov96_021EEA80(PTR(work, 0xc));
    entry[2] = U32(work, 0xb8);
    if (second) {
        if (((Ov96ResultB *)previous)->flag != 0 && participant >= ((Ov96ResultB *)previous)->participant) {
            return TRUE;
        }
    } else {
        if (((Ov96ResultA *)previous)->flag != 0 && participant >= ((Ov96ResultA *)previous)->participant) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov96_021EE324(void *course) {
    return ov96_UpdateResult(course, FALSE);
}

BOOL ov96_021EE440(void *course) {
    return ov96_UpdateResult(course, TRUE);
}
