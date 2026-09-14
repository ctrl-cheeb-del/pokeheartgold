#include "global.h"

extern u32 MTRandom(void);
extern u32 ov96_021EDCEC(void *course, u8 kind, u8 row, u8 column);

u32 ov96_021ED9CC(void *course);

u32 ov96_021ED9CC(void *course) {
    s32 outer;
    s32 row;
    {
        s32 found;
        s32 start;

        found = 0;
        start = MTRandom() & 3;
        for (outer = 0; outer < 4; outer++) {
            for (row = 0; row < 4; row++) {
                s32 column;

                for (column = 0; column < 3; column++) {
                    if (ov96_021EDCEC(course, start, row, column)) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
            start = (start + 1) % 4;
        }
        if (!found) {
            start = 4;
        }
        return start;
    }
}
