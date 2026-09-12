#include "overlay89_lookup_r14c_internal.h"

typedef struct Ov89Entry {
    u16 unk0;
    u16 value;
    u8 pad[8];
} Ov89Entry;

typedef struct Ov89Lookup {
    void *ptr;
    u32 value;
} Ov89Lookup;

u16 ov89_0225C830(u32 column, u32 value) {
    const u8 *row = (const u8 *)ov89_0225CE70 + (value % 9) * 4;
    return *(const u16 *)(row + column * 2);
}

u32 ov89_0225C84C(const Ov89Entry *entries, int current) {
    u32 ret = 0xff;
    int result = TouchscreenHitbox_FindRectAtTouchNew(ov89_0225CE50);
    if (result < 6) {
        if (current != result && entries[result].value != 0 && entries[result].value <= 0x1ed) {
            ret = result;
        }
    } else {
        if (result == 6) {
            ret = 0xfe;
        } else {
            return ret;
        }
    }
    return ret;
}

u32 ov89_0225C88C(u32 value, int a, int b) {
    if (value == 0x1e7 && a > 0) {
        return 0;
    }
    if (value == 0x1ed && b == 0) {
        return 0;
    }
    return ov89_0225CE94[value * 4];
}

u32 ov89_0225C8BC(u32 value, int arg) {
    if (value == 0x1e7 && arg > 0) {
        return 2;
    }
    return ov89_0225CE95[value * 4];
}

int ov89_0225C8DC(void *arg) {
    return ov45_0222EE50(ov89_0225D64C, 3, arg);
}

BOOL ov89_0225C8F0(u32 value, const Ov89Lookup *lookup) {
    int result;
    if (lookup->value == value) {
        return FALSE;
    }
    if (lookup->ptr == NULL) {
        return FALSE;
    }
    result = ov45_0222EC7C(value, lookup->ptr);
    if (result != -1) {
        return TRUE;
    }
    return FALSE;
}
