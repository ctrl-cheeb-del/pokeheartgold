#include "to47_overlay49_resource_cursor_private.h"

void ov49_0225CDEC(void *state, u32 a, u32 b, u32 heapId, u32 allocatorSize) {
    void *resource;
    void *narc;

    U8_AT(state, 0x127) = b;
    U8_AT(state, 0x126) = a;
    resource = ov49_0225D4FC(a, b, heapId);
    narc = NARC_New(0xCB, heapId);
    HeapExp_FndInitAllocator((u8 *)state + 0x494, allocatorSize, 4);
    ov49_0225D5FC((u8 *)state + 0x12C, narc, resource, allocatorSize, (u8 *)state + 0x494);
    ov49_0225DC2C((u8 *)state + 0x29C, narc, (u8 *)state + 0x494, resource, allocatorSize);
    ov49_0225D854((u8 *)state + 0x1C4, narc, (u8 *)state + 0x494, resource, allocatorSize);
    NARC_Delete(narc);
    ov49_0225D520(resource);
    ov49_0225D6F0(state, (u8 *)state + 0x12C);
    U32_AT(state, 0x128) = 1;
}

void ov49_0225CE88(void *state) {
    ov49_0225D76C(state, (u8 *)state + 0x12C);
    ov49_0225D6AC((u8 *)state + 0x12C, (u8 *)state + 0x494);
    ov49_0225DCBC((u8 *)state + 0x29C, (u8 *)state + 0x494);
    ov49_0225D9D0((u8 *)state + 0x1C4, (u8 *)state + 0x494);
    U32_AT(state, 0x128) = 0;
}

void ov49_0225CED0(void *state) {
    if (U32_AT(state, 0x1C0) == 1 && U32_AT(state, 0x104) == 0) {
        U32_AT(state, 0x104) = 1;
        sub_020181D4((u8 *)state + 4, (u8 *)state + 0x19C);
    }
}

void ov49_0225CEFC(void *state) {
    if (U32_AT(state, 0x1C0) == 1 && U32_AT(state, 0x104) == 1) {
        sub_020181E0((u8 *)state + 4, (u8 *)state + 0x19C);
        U32_AT(state, 0x104) = 0;
    }
}

void *ov49_0225CF28(void *state, s32 index, s32 selection, const void *value) {
    void *cursor;

    if (index > 2) {
        GF_AssertFail();
    }
    if (selection > 3) {
        GF_AssertFail();
    }
    cursor = ov49_0225D820(state);
    sub_020181B0((u8 *)cursor + 4, (u8 *)state + 0x1C4 + index * 0x10);
    sub_020182A0((u8 *)cursor + 4, 1);
    ov49_0225CFA8(cursor, value);
    {
        u32 zeroes[3] = { 0, 0, 0 };
        ov49_0225CFEC(cursor, zeroes);
    }
    U8_AT(cursor, 1) = selection;
    U8_AT(cursor, 2) = index;
    U8_AT(cursor, 0) = 1;
    U32_AT(cursor, 0x7C) = 1;
    U32_AT(cursor, 0x84) = 1;
    return cursor;
}
