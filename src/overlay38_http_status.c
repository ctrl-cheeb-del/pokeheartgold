#include "overlay38_http_private.h"

int ov38_0221BB44(u32 size) {
    return (size / 3 + (size % 3 != 0)) * 4;
}

void ov38_0221BB68(int value) {
    switch (value) {
    case -8:
        _02225040.error = 0;
        break;
    case -6:
        _02225040.error = 1;
        break;
    case -5:
        _02225040.error = 2;
        break;
    case -4:
        _02225040.error = 3;
        break;
    case -3:
        _02225040.error = 4;
        break;
    case -2:
        _02225040.error = 5;
        break;
    case -1:
        _02225040.error = 6;
        break;
    default:
        _02225040.error = 0;
        break;
    }
}
