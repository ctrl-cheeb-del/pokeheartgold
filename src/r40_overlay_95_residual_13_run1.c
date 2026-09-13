#include "r40_overlay_95_residual_13_private.h"

void ov95_021E7308(Ov95StateR13 *state) {
    int i;
    u8 *window;

    GF_ASSERT(state != NULL);
    i = 0;
    window = state->windows;
    for (; i < 2; i++) {
        RemoveWindow(window);
        window += 0x10;
    }
}

void ov95_021E7328(Ov95StateR13 *state, void *window, u32 msgId) {
    void *msgData = NewMsgDataFromNarc(0, 0x1B, 0xBB, state->heapId);
    void *string = ReadMsgData_ExpandPlaceholders(state->messageFormat, msgData, msgId, state->heapId);

    FillWindowPixelBuffer(window, 0);
    AddTextPrinterParameterizedWithColor(window, 4, string, 0, 0, 0, 0x10200, NULL);
    CopyWindowToVram(window);
    DestroyMsgData(msgData);
    String_Delete(string);
}

void ov95_021E7388(Ov95StateR13 *state, int resource0, int resource1, int resource2, int resource3) {
    ManagedSpriteTemplate template = ov95_021E782C;
    ManagedSprite *sprite;
    SpriteSystem *spriteSystem = state->spriteSystem;
    SpriteManager *spriteManager = state->spriteManager;

    GF_ASSERT(state != NULL);
    GF_ASSERT(spriteSystem != NULL);
    GF_ASSERT(spriteManager != NULL);
    template.x = 0x80;
    template.y = 0x48;
    template.animation = 1;
    template.resIdList[0] = resource0;
    template.resIdList[1] = resource1;
    template.resIdList[2] = resource2;
    template.resIdList[3] = resource3;
    sprite = SpriteSystem_NewSprite(spriteSystem, spriteManager, &template);
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
    ManagedSprite_SetDrawFlag(sprite, FALSE);
    state->sprite = sprite;
}
