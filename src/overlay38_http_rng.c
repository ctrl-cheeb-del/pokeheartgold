#include "overlay38_http_private.h"

void ov38_0221BA00(u32 value) {
    _02226020 = value | (value << 16);
}

u8 ov38_0221BA10(void) {
    _02226020 = (_02226020 * 0x45 + 0x1111) & 0x7FFFFFFF;
    return (s32)_02226020 >> 16;
}
