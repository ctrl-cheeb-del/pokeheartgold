#include "to47_overlay49_sprite_lifecycle_r40_private.h"

typedef struct Ov49ResourceRowsR40 {
    u8 pad[0x3BC];
    void *rows[][3];
} Ov49ResourceRowsR40;

void *ov49_0225D098(void *state, u32 index, u32 x, u32 y) {
    register void *base = state;
    void *cursor;
    s32 i;
    Ov49PositionR40 position;

    cursor = ov49_0225DBF8(base);
    sub_020181B0((u8 *)cursor + 4, (u8 *)base + 0x29C + index * 0x10);
    for (i = 0; i < 3; i++) {
        void *resource = ((Ov49ResourceRowsR40 *)base)->rows[index][i];
        if (resource != NULL) {
            sub_020180E8((u8 *)cursor + 0x7C + i * 0x14,
                (u8 *)base + 0x29C + (index << 4),
                resource,
                (u8 *)base + 0x494);
        }
    }
    sub_020182A0((u8 *)cursor + 4, 1);
    position.x = x << 4;
    position.y = y << 4;
    ov49_0225D1C4(cursor, position);
    U16_AT(cursor, 0) = 1;
    U16_AT(cursor, 2) = index;
    U8_AT(cursor, 0xCC) = 0x14;
    U32_AT(cursor, 0xDC) = 0x1000;
    U8_AT(cursor, 0xE0) = 0;
    U8_AT(cursor, 0xE1) = 0x1F;
    U8_AT(cursor, 0xE2) = 0x1F;
    return cursor;
}

void ov49_0225D160(void *state, void *cursor) {
    s32 i;

    sub_020182A0((u8 *)cursor + 4, 0);
    for (i = 0; i < 3; i++) {
        u32 index = U16_AT(cursor, 2);
        void *resource = ((Ov49ResourceRowsR40 *)state)->rows[index][i];
        if (resource != NULL) {
            sub_020180E8((u8 *)cursor + 0x7C + i * 0x14,
                (u8 *)state + 0x29C + index * 0x10,
                resource,
                (u8 *)state + 0x494);
        }
    }
    U16_AT(cursor, 0) = 0;
}
