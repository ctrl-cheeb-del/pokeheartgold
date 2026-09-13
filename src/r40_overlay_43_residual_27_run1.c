#include "r40_overlay_43_residual_27_private.h"

void ov43_0222DC7C(void *unused, void *state) {
    void *screen = PTR(state, 0x20c);
    CopyToBgTilemapRect(PTR(state, 0), 2, 0, 0x14, 0x20, 4, (u8 *)screen + 0xc, 0, 0x1c, ((u32)U16(screen, 0) << 21) >> 24, ((u32)U16(screen, 2) << 21) >> 24);
    ScheduleBgTilemapBufferTransfer(PTR(state, 0), 2);
}

int ov43_0222DCC4(void *state, int direction) {
    void *data = sub_0202C6F4(PTR(state, 4));
    int current = *(s8 *)((u8 *)state + 0xb);
    u32 i;
    if (direction == 0) {
        for (i = 0; i < U32(state, 0x10) - 1; i++) {
            current--;
            if (current < 0) {
                current += U32(state, 0x10);
            }
            if (sub_0202C090(data, *((u8 *)state + 0x18 + current), 8) != 2) {
                *((u8 *)state + 0xb) = current;
                return 1;
            }
        }
    } else {
        for (i = 0; i < U32(state, 0x10) - 1; i++) {
            current = (current + 1) % U32(state, 0x10);
            if (sub_0202C090(data, *((u8 *)state + 0x18 + current), 8) != 2) {
                *((u8 *)state + 0xb) = current;
                return 1;
            }
        }
    }
    return 0;
}

void ov43_0222DD40(void **output, void *context, int heapId) {
    u16 members[4];
    u16 *member;
    int i;
    members[0] = _0222ED5C[23];
    members[1] = _0222ED5C[24];
    member = members;
    i = 0;
    members[2] = _0222ED5C[25];
    members[3] = _0222ED5C[26];
    for (; i < 4; i++) {
        output[0] = GfGfxLoader_GetScrnDataFromOpenNarc(PTR(context, 0x58), *member, 1, &output[1], heapId);
        output += 2;
        member++;
    }
}
