#include "opus10_overlay65_party_rows_private.h"

void ov65_0221D674(void *windows, int side, void *party, int index, void *work);
void ov65_0221D8C4(void *windows, int side, void *work);
void ov65_0221D930(void *work);
void ov65_0221DBF4(void *p);
void ov65_0221DC34(void *work);
void ov65_0221DCBC(void *state);
int ov65_0221DCFC(int idx, int dir, void *summaries);

void ov65_0221DD34(int idx, void *sprite, int form) {
    Ov65Vec3 pos;

    if (idx >= 0xd) {
        GF_AssertFail();
    }
    pos.x = ov65_0221FF4C[idx][0] << 12;
    pos.y = ov65_0221FF50[idx][0] << 12;
    if (idx == 0xc) {
        Sprite_SetMatrix(sprite, &pos);
        Sprite_SetAnimCtrlSeq(sprite, ov65_0221FD70[form][0]);
        return;
    }
    Sprite_SetMatrix(sprite, &pos);
    if (idx < 6) {
        Sprite_SetAnimCtrlSeq(sprite, ov65_0221FD68[form][0]);
    } else {
        Sprite_SetAnimCtrlSeq(sprite, ov65_0221FD6C[form][0]);
    }
}

int ov65_0221DDC0(void *input, void *state, void *sprite, void *summaries, int side) {
    int ret;
    int next;
    int dir;
    int prev;

    dir = *(int *)input;
    prev = dir - 1;
    ret = 0;
    if (side == 0) {
        if (dir != 0) {
            next = ov65_0221DCFC(*(int *)state, prev, summaries);
            ov65_0221DD34(next, sprite, side);
            if (*(int *)state != next) {
                PlaySE(0x5dc);
                *(int *)state = next;
                ret = 1;
            }
        }
        *(int *)input = 0;
    } else {
        ov65_0221DD34(*(int *)state, sprite, side);
    }
    return ret;
}
