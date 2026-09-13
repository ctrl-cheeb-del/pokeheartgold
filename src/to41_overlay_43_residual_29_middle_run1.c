#include "to41_overlay_43_residual_29_middle_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct Ov43Entry {
    u8 pad_00[0xb];
    s8 playerIndex;
    u8 pad_0c[0xc];
    u8 playerIds[4];
} Ov43Entry;

#define GET_PLAYER_INDEX(entry) (((Ov43Entry *)(entry))->playerIds[((Ov43Entry *)(entry))->playerIndex])

void ov43_0222DFB0(void *windows, void *entry, void *display) {
    void *records = sub_0202C6F4(PTR(entry, 4));
    u32 i;
    u32 y;

    ov43_0222EC58(windows, 0, 0, entry, display, 0x13, 0, 0, 0x10200, PTR(display, 0x7c), PTR(display, 0x80), 0);
    i = 0;
    y = 0;
    do {
        u8 *player;
        ov43_0222EC58(windows, 0, 2, entry, display, 0x14 + i, 0, (u8)y, 0x10200, PTR(display, 0x7c), PTR(display, 0x80), 0);
        player = (u8 *)entry + S8(entry, 0xb);
        ov43_0222ABFC(display, sub_0202C090(records, player[0x18], i + 1));
        ov43_0222EC58(windows, 0, 2, entry, display, 0x16, 0, (u8)y, 0x10200, PTR(display, 0x7c), PTR(display, 0x80), 0);
        y += 0x18;
        i++;
    } while (i < 2);
    ov43_0222EC58(windows, 0, 1, entry, display, 0x17, 0, 0, 0x10200, PTR(display, 0x7c), PTR(display, 0x80), 0);
    {
        u8 *player = (u8 *)entry + S8(entry, 0xb);
        ov43_0222ABFC(display, sub_0202C090(records, player[0x18], 3));
    }
    ov43_0222EC58(windows, 0, 3, entry, display, 0x18, 0, 0, 0x10200, PTR(display, 0x7c), PTR(display, 0x80), 0);
    ov43_0222DEF8(windows, 0);
}
