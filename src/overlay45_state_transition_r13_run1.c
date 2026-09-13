#include "overlay45_state_transition_r13_private.h"

void ov45_0222ADA8(void *state, int value) {
    ov45_0222C5B4((u8 *)state + 0x20C, value);
}

void ov45_0222ADB8(void *state, int value, int other) {
    ov45_0222C408((u8 *)state + 0x20C, value, other);
}

void ov45_0222ADC8(void *state, int value) {
    ov45_0222C480((u8 *)state + 0x20C, value);
}

void ov45_0222ADD8(void *state, int value) {
    ov45_0222C514((u8 *)state + 0x20C, value);
}

void ov45_0222ADE8(void *state, int value) {
    ov45_0222C54C((u8 *)state + 0x20C, value);
}

void ov45_0222ADF8(void *state, int value) {
    ov45_0222C580((u8 *)state + 0x20C, value);
}

void ov45_0222AE08(u32 value, u32 *quotient, u32 *remainder) {
    *quotient = value / 3;
    *remainder = value % 3;
}

void ov45_0222AE24(void *state, int value, int other) {
    ov45_0222C5E8((u8 *)state + 0x20C, value, other);
}

void ov45_0222AE34(void *state, int value) {
    ov45_0222C658((u8 *)state + 0x20C, value);
}

void ov45_0222AE44(void) {
    u32 output;

    ov45_0222EEF0(6, &output, 4);
}

void ov45_0222AE54(void) {
    u32 output;

    ov45_0222EEF0(7, &output, 4);
}

void ov45_0222AE64(void *state) {
    ov45_0222BD4C((u8 *)state + 0x1C0);
}
