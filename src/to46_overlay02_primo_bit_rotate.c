#include "global.h"

void ov02_0224CA58(u8 *data, int size, u8 amount);

void ov02_0224CA58(u8 *data, int size, u8 amount) {
    u8 carry;
    int i;
    u8 *end;
    int last;
    u8 count = amount;
    count--;

    if (amount == 0) {
        return;
    }
    end = data + size;
    last = size - 1;
    do {
        carry = *(end - 1) & 1;
        i = last;
        while (i > 0) {
            data[i] >>= 1;
            data[i] |= (data[i - 1] & 1) << 7;
            i--;
        }
        data[i] >>= 1;
        data[i] |= carry << 7;
    } while (count-- != 0);
}
