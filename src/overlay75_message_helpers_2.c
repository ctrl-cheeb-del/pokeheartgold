#include "overlay75_message_helpers_internal.h"

s32 ov75_0224964C(void *win, u32 font, s32 x, u32 align, u32 unused, void *str) {
    switch (align) {
    case 1: {
        s32 width = FontID_String_GetWidth((u32)str, (void *)font, 0);
        x = (((u8 *)win)[7] * 8 - width) / 2;
        break;
    }
    case 2: {
        s32 width = FontID_String_GetWidth((u32)str, (void *)font, 0);
        x = ((u8 *)win)[7] * 8 - width;
        break;
    }
    }
    return x;
}
