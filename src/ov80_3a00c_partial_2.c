#include "ov80_3a00c_partial_internal.h"

void ov80_0223A144(void *task, void *data) {
    u8 *p = data;
    if (ov80_0223A174(data, 0x65, ov80_0223DB98 + p[0x2C] * 12) == 1) {
        ov80_0223A0C0(data, task);
    }
}
