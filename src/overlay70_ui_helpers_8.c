#include "overlay70_ui_helpers_private.h"

void ov70_0223F7A4(u8 *dst, u8 *src) {
    ov70_0223F6E4(dst, src);
    *(u16 *)(dst + 0xEC) = *(u16 *)(src + 0xB80);
    *(u16 *)(dst + 0xEE) = *(u16 *)(src + 0xB82);
    *(u16 *)(dst + 0xF0) = *(u16 *)(src + 0xB84);
    *(u16 *)(dst + 0xF2) = *(u16 *)(src + 0xB86);
    *(u16 *)(dst + 0xF4) = *(u16 *)(src + 0xB88);
}
