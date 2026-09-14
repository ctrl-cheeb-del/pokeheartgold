#include "touch_sampling_internal.h"

TouchState _021D2198;

int sub_020214B0(int mode, int latest, u32 threshold)
{
    u32 i;
    for (i = 0; i < STATE.count; i++) {
        s16 index = latest - STATE.count + i + 1;
        if (index < 0) {
            index += 9;
        }
        STATE.buffer[STATE.write] = STATE.samples[index];
        STATE.write++;
        if (STATE.write >= STATE.capacity) {
            if (mode == 4) {
                STATE.write %= STATE.capacity;
            } else {
                return -1;
            }
        }
    }
    return STATE.write;
}
