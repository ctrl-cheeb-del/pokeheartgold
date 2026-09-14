#include "overlay18_pokedex_search_controls_private.h"

void ov18_021F7748(Ov18MenuState *state) {
    *(GridInputHandler **)&state->raw[0x1864] = GridInputHandler_Create(ov18_021FB9A8, ov18_021FBB0C, ov18_021FB658, state, TRUE, 0, (enum HeapID)0x25);
    ov18_021F11C0(state, 0, 1);
    ov18_021F77C0(state, 0);
}

int ov18_021F7790(Ov18MenuState *state) {
    MenuInputStateMgr_SetState(*(MenuInputStateMgr **)((u8 *)*(void **)&state->raw[0] + 0xc), (MenuInputState)0);
    if (gSystem.newKeys & 8) {
        return 0xf;
    }
    return GridInputHandler_HandleInput_AllowHold(*(GridInputHandler **)&state->raw[0x1864]);
}

void ov18_021F77C0(Ov18MenuState *state, int index) {
    u8 pos[2];
    const DpadMenuBox *box = GridInputHandler_GetDpadBox(*(GridInputHandler **)&state->raw[0x1864], index);
    DpadMenuBox_GetPosition(box, &pos[1], &pos[0]);
    ManagedSprite_SetPositionXY(*(ManagedSprite **)&state->raw[0x670], pos[1], pos[0]);
    ov18_021F118C(state, 0, ov18_021FBD28[index]);
}

void ov18_021F7800(Ov18MenuState *state, int index, int input) {
    int current;

    if (input == 0xf) {
        if (index == 0) {
            current = *(int *)&state->raw[0x189c];
            if (current >= 0 && current <= 2) {
                index = current;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0xf);
            } else if (current >= 10 && current <= 12) {
                index = current % 5;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0xf);
            }
        } else if (index == 10) {
            current = *(int *)&state->raw[0x189c];
            if (current >= 0 && current <= 2) {
                index = current + 10;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0xf);
            } else if (current >= 10 && current <= 12) {
                index = current;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0xf);
            }
        }
    } else if (input == 0x10) {
        if (index == 4) {
            current = *(int *)&state->raw[0x189c];
            if (current >= 3 && current <= 4) {
                index = current;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0x10);
            } else if (current >= 13 && current <= 14) {
                index = current % 5;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0x10);
            }
        } else if (index == 14) {
            current = *(int *)&state->raw[0x189c];
            if (current >= 3 && current <= 4) {
                index = current + 10;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0x10);
            } else if (current >= 13 && current <= 14) {
                index = current;
                GridInputHandler_SetNextLastUnk0FInputs(*(GridInputHandler **)&state->raw[0x1864], (u8)index, (u8)input, 0x10);
            }
        }
    }
    ov18_021F77C0(state, index);
    *(int *)&state->raw[0x189c] = input;
    PlaySE(0x8e8);
}
