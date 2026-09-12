#include "overlay43_touch_menu_r15_private.h"

int ov43_0222C228(u8 *work, u32 *touchMode, void *ctx) {
    int result;

    if (!ov43_0222C5D8(work)) {
        return 6;
    }
    result = TouchscreenListMenu_HandleInput(PTR_AT(work, 0xec));
    if (result == 3) {
        goto selected;
    }
    if (result == -2) {
        goto selected;
    }
    if (result == -1) {
        return 6;
    }
    goto continued;
selected:
    ov43_0222AD00(ctx, 1);
    result = 2;
continued:
    ov43_0222C600(work);
    *touchMode = TouchscreenListMenu_WasLastInputTouch(PTR_AT(work, 0xec));
    TouchscreenListMenu_Destroy(PTR_AT(work, 0xec));
    if (result == 2) {
        ov43_0222AD00(ctx, 1);
        ov43_0222C890(work + 8, ctx, S16_AT(work, 4), 0);
    }
    SetBlendBrightness(0, 0x3d, 1);
    return result;
}

int ov43_0222C2B0(u8 *work, u8 *entry, void *ctx, void *arg3) {
    int index;
    u8 *indices;
    void *records;
    u64 key;
    int next;

    records = sub_0202C6F4(PTR_AT(entry, 4));
    index = ov43_0222C620(work);
    indices = entry + 0x18;
    key = DWC_GetFriendKey(sub_0202C23C(records, indices[index]));
    next = key != 0 ? 0x3c : 0x42;
    PlaySE(0x5dd);
    ov43_0222AAA4(ctx, (u32)key, (u32)(key >> 32));
    ov43_0222AB20(ctx, PTR_AT(entry, 4), indices[index], arg3);
    ov43_0222C550(work, ctx, next, arg3);
    return 1;
}

void ov43_0222C32C(u8 *work, u8 *entry, void *ctx, void *arg3) {
    typedef struct Entry {
        u8 pad00[0x18];
        u8 indices[1];
    } Entry;
    int index = ov43_0222C620(work);

    ov43_0222AB20(ctx, PTR_AT(entry, 4), ((Entry *)entry)->indices[index], arg3);
    ov43_0222C550(work, ctx, 0x39, arg3);
}
