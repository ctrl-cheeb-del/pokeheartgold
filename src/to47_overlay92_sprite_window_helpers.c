#include "to47_overlay92_sprite_window_helpers_private.h"

void ov92_0225DF58(void *work, int slot, int which) {
    Ov92SpriteWork *state = work;
    Ov92AnimPair pairs = ov92_02263BCC;
    u16 sprite = state->slot[slot];

    ManagedSprite_SetAnim(state->first[sprite], pairs.value[which][0]);
    ManagedSprite_SetAnim(state->second[sprite], pairs.value[which][1]);
}

int ov92_0225DFA4(void *work, int slot) {
    Ov92SpriteWork *state = work;
    Ov92AnimPair table = ov92_02263B8C;
    u16 sprite = state->slot[slot];
    int first = ManagedSprite_GetActiveAnim(state->first[sprite]);
    int second = ManagedSprite_GetActiveAnim(state->second[sprite]);
    int i;

    for (i = 0; i < 4; i++) {
        if (first == table.value[i][0] && second == table.value[i][1]) {
            return i;
        }
    }
    GF_AssertFail();
    return 0;
}

void ov92_0225E008(void *work) {
    int i = 0;
    if (S32(work, 4) > 0) {
        u8 *sprite = work;
        do {
            if (i != S32(work, 0)) {
                ManagedSprite_TickTwoFrames(PTR(sprite, 0x1C));
                ManagedSprite_TickTwoFrames(PTR(sprite, 0x28));
                ManagedSprite_TickTwoFrames(PTR(sprite, 0x34));
                sprite += 4;
            }
            i++;
        } while (i < S32(work, 4));
    }
}

void ov92_0225E03C(void *work) {
    int i = 0;
    if (S32(work, 4) > 0) {
        u8 *sprite = work;
        do {
            if (i != S32(work, 0)) {
                Sprite_DeleteAndFreeResources(PTR(sprite, 0x1C));
                Sprite_DeleteAndFreeResources(PTR(sprite, 0x28));
                Sprite_DeleteAndFreeResources(PTR(sprite, 0x34));
                sprite += 4;
            }
            i++;
        } while (i < S32(work, 4));
    }
}

void ov92_0225E070(void *work) {
    Ov92Work *state = work;
    void *msgData;
    void *string;

    InitWindow(state->window);
    AddWindowParameterized(PTR(PTR(work, 0x14), 0x10), state->window, 7, 2, 0x13, 0x1C, 4, 0xE, 0x130);
    FillWindowPixelBuffer(state->window, 0xFF);
    msgData = NewMsgDataFromNarc(0, 0x1B, 0xEB, 0x71);
    string = NewString_ReadMsgData(msgData, 0);
    AddTextPrinterParameterized(state->window, 0, string, 0, 0, 0, 0);
    String_Delete(string);
    DestroyMsgData(msgData);
    DrawFrameAndWindow1(state->window, 0, 0xB4, 0xD);
    CopyWindowToVram(state->window);
}
