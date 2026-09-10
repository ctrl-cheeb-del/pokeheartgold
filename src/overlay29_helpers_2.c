#include "overlay_29_helpers_internal.h"

void ov29_0225D7D4(Ov29StatePrivate *state) {
    u32 i = 0;
    u8 *window = (u8 *)state + 0x1a0;
    for (; i < 3; i++, window += 0x10) {
        RemoveWindow(window);
    }
}

void ov29_0225D7F0(Ov29StatePrivate *state, void *narc) {
    state->spriteList = G2dRenderer_Init(11, state->renderer, 8);
    G2dRenderer_SetSubSurfaceCoords(state->renderer, 0, 1 << 20);
    ov29_0225D840(state);
    ov29_0225D9C8(state, narc);
    ov29_0225DC84(state);
}

void ov29_0225D828(Ov29StatePrivate *state) {
    ov29_0225DB38(state);
    ov29_0225D864(state);
    SpriteList_Delete(state->spriteList);
}

void ov29_0225D840(Ov29StatePrivate *state) {
    u32 i;
    for (i = 0; i < 4; i++) {
        state->resourceManagers[i] = Create2DGfxResObjMan(2, i, 8);
    }
}

void ov29_0225D864(Ov29StatePrivate *state) {
    u32 i;
    for (i = 0; i < 4; i++) {
        Destroy2DGfxResObjMan(state->resourceManagers[i]);
    }
}

void ov29_0225D880(void **resources, GfxManagerPrivate **managers, void *narc, u32 charMember, u32 paletteMember, u32 cellMember, u32 animationMember, u32 paletteSlot, u32 charId, u32 paletteId, u32 cellId, u32 animationId) {
    resources[0] = AddCharResObjFromOpenNarc(managers[0], narc, charMember, 0, charId, 2, 8);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(resources[0]);
    sub_0200A740(resources[0]);
    resources[1] = AddPlttResObjFromOpenNarc(managers[1], narc, paletteMember, 0, paletteId, 2, paletteSlot, 8);
    SpriteTransfer_CreatePlttTransferTask(resources[1]);
    sub_0200A740(resources[1]);
    resources[2] = AddCellOrAnimResObjFromOpenNarc(managers[2], narc, cellMember, 0, cellId, 2, 8);
    resources[3] = AddCellOrAnimResObjFromOpenNarc(managers[3], narc, animationMember, 0, animationId, 3, 8);
}

void ov29_0225D910(void **resources, GfxManagerPrivate **managers, void *header, u32 priority) {
    s32 charId = GF2DGfxResObj_GetResID(resources[0]);
    s32 paletteId = GF2DGfxResObj_GetResID(resources[1]);
    s32 cellId = GF2DGfxResObj_GetResID(resources[2]);
    s32 animationId = GF2DGfxResObj_GetResID(resources[3]);
    CreateSpriteResourcesHeader(header, charId, paletteId, cellId, animationId, -1, -1, 0, priority, managers[0], managers[1], managers[2], managers[3], NULL, NULL);
}

void ov29_0225D970(Ov29StatePrivate *state, u32 index, const void *resourceHeader, const SpritePlacementPrivate *placement) {
    SpriteTemplatePrivate template;
    template.spriteList = state->spriteList;
    template.resourceHeader = resourceHeader;
    template.x = placement->x << 12;
    template.y = (placement->y << 12) + (1 << 20);
    template.z = 0;
    template.scaleX = 1 << 12;
    template.scaleY = 1 << 12;
    template.scaleZ = 1 << 12;
    template.rotation = 0;
    template.priority = placement->priority;
    template.vramType = 2;
    template.heapId = 8;
    state->sprites[index] = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(state->sprites[index], placement->animation);
}
