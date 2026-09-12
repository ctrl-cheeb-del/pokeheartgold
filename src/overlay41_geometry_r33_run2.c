#include "overlay41_geometry_r33_private.h"

void ov41_02248400(void *object, int *outX, int *outY) {
    int a;
    int b;
    int c;
    int d;
    int e;
    int g;
    int f;
    int h;
    int x1;
    int x2;
    int y1;
    int y2;

    ov41_02249B94(object, &a, &b);
    ov41_02249B44(object, &c, &d);
    ov41_02249BAC(object, &e, &f, &g, &h);
    x1 = 0x8A - (c + e);
    x2 = c + a - f - 0xF6;
    y1 = 0x12 - (d + g);
    y2 = d + b - h - 0x8F;
    if (x1 > 0) {
        *outX = x1;
    } else if (x2 > 0) {
        *outX = -x2;
    } else {
        *outX = 0;
    }
    if (y1 > 0) {
        *outY = y1;
    } else if (y2 > 0) {
        *outY = -y2;
    } else {
        *outY = 0;
    }
}

void ov41_02248488(void *work, void *input) {
    U32_AT(work, 0x44) = U32_AT(input, 0x00);
    U32_AT(work, 0x48) = U32_AT(input, 0x04);
    U32_AT(work, 0x4C) = U32_AT(input, 0x08);
    U32_AT(work, 0x50) = U32_AT(input, 0x0C);
    U32_AT(work, 0x54) = U32_AT(input, 0x10);
    U32_AT(work, 0x58) = U32_AT(input, 0x14);
    U32_AT(work, 0x08) = U32_AT(input, 0x18);
    U32_AT(work, 0x04) = U32_AT(input, 0x28);
    ov41_0224888C(work, 0);
    ov41_022489A8(work, input);
}

void ov41_022484C0(void *work) {
    int i;
    u8 *entry;

    ov41_022486F8(work);
    entry = work;
    i = 0;
    entry += 0xC;
    while (i < 4) {
        ov41_02248A6C(entry);
        i++;
        entry += 0xC;
    }
    memset(work, 0, 0x8C);
}

int ov41_022484E8(int mode, int value, void *object) {
    switch (mode) {
    case 0:
        if (value <= 5) {
            return 0;
        }
        if (value <= 11) {
            return 1;
        }
        if (value <= 17) {
            return 2;
        }
        if (value <= 21) {
            return 3;
        }
        if (value <= 28) {
            return 4;
        }
        if (value <= 33) {
            return 5;
        }
        if (value <= 38) {
            return 6;
        }
        if (value <= 42) {
            return 7;
        }
        if (value <= 49) {
            return 8;
        }
        if (value <= 55) {
            return 9;
        }
        if (value <= 60) {
            return 10;
        }
        if (value <= 71) {
            return 11;
        }
        if (value <= 91) {
            return 12;
        }
        if (value <= 99) {
            return 13;
        }
        break;
    case 1:
        return ov41_02248EF4(object) / 9;
    case 2:
        mode = ov41_02248EF4(object) / 9;
        break;
    }
    return mode;
}

void ov41_02248584(int mode, int unused, int *outX, int *outY, int x, int y, void *object) {
    switch (mode) {
    case 0:
        *outX = 10;
        *outY = 18;
        *outX += MTRandom() % (108 - x);
        *outY += MTRandom() % (125 - y);
        break;
    case 1:
    case 2:
        ov41_02248B48(ov41_02248EF4(object), outX, outY);
        break;
    }
}
