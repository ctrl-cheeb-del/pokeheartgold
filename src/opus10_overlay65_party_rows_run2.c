#include "opus10_overlay65_party_rows_private.h"

void ov65_0221D674(void *windows, int side, void *party, int index, void *work);
void ov65_0221D8C4(void *windows, int side, void *work);
void ov65_0221D930(void *work);
void ov65_0221DC34(void *work);
void ov65_0221DCBC(void *state);
int ov65_0221DCFC(int idx, int dir, void *summaries);
void ov65_0221DD34(int idx, void *sprite, int form);
int ov65_0221DDC0(void *input, void *state, void *sprite, void *summaries, int side);

void ov65_0221DBF4(void *p) {
    int count;
    int dir;
    u32 keys;

    count = 0;
    dir = 0;
    keys = U32(gSystem, 0x4c);
    if (keys & 0x40) {
        dir = 1;
        count++;
    }
    if (keys & 0x80) {
        dir = 2;
        count++;
    }
    if (keys & 0x20) {
        dir = 3;
        count++;
    }
    if (keys & 0x10) {
        dir = 4;
        count++;
    }
    if (count != 0) {
        *(int *)p = dir;
    }
}
