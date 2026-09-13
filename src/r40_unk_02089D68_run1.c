#include "r40_unk_02089D68_private.h"

void sub_02089D68(SummaryState89 *state, int selection) {
    if ((s8)state->data[0x7B8] == selection) {
        return;
    }
    sub_0208C4E0(state);
    state->data[0x7B8] = selection;
    sub_0208B448(state);
    sub_0208B5A8(state);
    sub_0208B89C(state);
    sub_0208B9C8(state);
    sub_0208C2A0(state);
    sub_0208BCD4(state);
    sub_0208C42C(state);
    FillBgTilemapRect(state->bgConfig, 1, 0, 0, 3, 0x12, 0x14, 0);
    BgCommitTilemapBufferToVram(state->bgConfig, 1);
    FillBgTilemapRect(state->bgConfig, 4, 0, 0, 3, 0x12, 0x14, 0);
    BgCommitTilemapBufferToVram(state->bgConfig, 4);
    sub_0208CBD4(state);
    sub_02089F98(state);
    if (*((u8 *)(*(void **)((u8 *)state + 0x22C)) + 0x12) == 2) {
        sub_0208A950(state);
    }
}

void sub_02089E14(SummaryState89 *state, int selection) {
    PlaySE(0x5E1);
    sub_02089D68(state, (u8)selection);
}

void sub_02089E30(SummaryState89 *state, int direction) {
    s8 current = (s8)state->data[0x7B8];
    if (((*(u32 *)((u8 *)state + 0x280) << 3) >> 31) != 0) {
        return;
    }
    u8 available = *((u8 *)(*(void **)((u8 *)state + 0x22C)) + 0x15);
    do {
        current += direction;
        if (current < 0) {
            current = 2;
        } else if (current > 2) {
            current = 0;
        }
    } while ((available & (1 << current)) == 0);
    if (current != (s8)state->data[0x7B8]) {
        sub_02089E14(state, current);
    }
}
