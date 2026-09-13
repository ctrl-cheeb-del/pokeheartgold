#include "r40_overlay_72_residual_25_private.h"

extern int TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);
extern const u8 ov72_0223B774[];
extern const u8 ov72_0223B7B8[];
extern const u8 ov72_0223B48C[][4];
extern const u8 ov72_0223B464[];
extern const u8 ov72_0223B466[];
extern const u8 ov72_0223B468[];
extern const u8 ov72_0223B46A[];

int ov72_0223A738(u8 *work) {
    if (work[0x130D] == 100) {
        return TouchscreenHitbox_FindRectAtTouchNew(ov72_0223B774);
    }
    return TouchscreenHitbox_FindRectAtTouchNew(ov72_0223B7B8);
}

u8 ov72_0223A760(u32 current, u32 direction, u16 *position) {
    u8 next = ov72_0223B48C[current][direction];

    if (next == 13) {
        next = ov72_0223B464[position[0]];
    } else if (next == 14) {
        next = ov72_0223B466[position[0]];
    } else if (next == 15) {
        next = ov72_0223B468[position[1]];
    } else if (next == 16) {
        next = ov72_0223B46A[position[1]];
    } else if (next == 10) {
        if (current == 5 || current == 0) {
            position[0] = 0;
        } else if (current == 1 || current == 6) {
            position[0] = 1;
        }
    } else if (next == 12) {
        if (current == 3 || current == 8) {
            position[1] = 0;
        } else if (current == 4 || current == 9) {
            position[1] = 1;
        }
    }
    return next;
}

int ov72_0223A7F4(u8 *work, int override) {
    int digits[3];
    int selected[3];
    int placeValue = 100;
    int digitCount = 3;
    int outputCount;
    int started;
    int i;
    int sum;

    for (i = 0; i < 3; i++) {
        digits[i] = (s8)work[8 + i];
    }
    if (override != -1) {
        digits[*(s16 *)(work + 4)] = override;
    }
    outputCount = 0;
    started = FALSE;
    for (i = 0; i < 3; i++) {
        if (((s8)work[8 + i] == 0 && started == FALSE) || digits[i] < 0) {
            placeValue /= 10;
            digitCount--;
        } else {
            started = TRUE;
            selected[outputCount++] = digits[i];
        }
    }
    sum = 0;
    for (i = 0; i < digitCount; i++) {
        sum += selected[i] * placeValue;
        placeValue /= 10;
    }
    if (sum > work[1]) {
        return -1;
    }
    return sum;
}

BOOL ov72_0223A8A0(u8 *work) {
    if (work[1] != 100) {
        if ((s8)work[9] >= 0 && (s8)work[10] >= 0) {
            return TRUE;
        }
    } else {
        if ((s8)work[8] >= 0 && (s8)work[9] >= 0 && (s8)work[10] >= 0) {
            return TRUE;
        }
    }
    return FALSE;
}
