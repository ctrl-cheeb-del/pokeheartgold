#include "r40_overlay_29_residual_3_candidate_private.h"

void ov29_0225D9C8(Ov29StatePrivate *state, void *narc) {
    u32 header[9];
    u32 countOffset;
    u32 i;
    u8 *cursor;
    ov29_0225D880(&state->resourceManagers[4], state->resourceManagers, narc, 5, 4, 6, 7, 2, 0x399, 0x399, 0x399, 0x399);
    ov29_0225D910(&state->resourceManagers[4], state->resourceManagers, header, 1);
    ov29_0225D970(state, 0, header, &ov29_0225E21C);
    ov29_0225D970(state, 1, header, &ov29_0225E220);
    ov29_0225D970(state, 2, header, &ov29_0225E224);
    ov29_0225D970(state, 3, header, &ov29_0225E228);
    ov29_0225D970(state, 4, header, &ov29_0225E22C);
    ov29_0225D880(&state->resourceManagers[8], &state->resourceManagers[0], narc, 1, 0, 2, 3, 2, 0x39A, 0x39A, 0x39A, 0x39A);
    ov29_0225D910(&state->resourceManagers[8], state->resourceManagers, header, 1);
    ov29_0225D970(state, 5, header, &ov29_0225E230);
    ov29_0225D970(state, 6, header, &ov29_0225E234);
    ov29_0225D970(state, 7, header, &ov29_0225E238);
    ov29_0225D970(state, 8, header, &ov29_0225E23C);
    ov29_0225D970(state, 9, header, &ov29_0225E240);
    ov29_0225D970(state, 10, header, &ov29_0225E244);
    countOffset = 0x1FC;
    i = 0;
    cursor = (u8 *)state;
    while (i < 6) {
        if (i < *(u32 *)((u8 *)state + countOffset)) {
            Sprite_SetDrawFlag(*(SpritePrivate **)(cursor + 0x188), 1);
        } else {
            Sprite_SetDrawFlag(*(SpritePrivate **)(cursor + 0x188), 0);
        }
        i++;
        cursor += 4;
    }
}
