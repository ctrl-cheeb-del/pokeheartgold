#include "to46_overlay15_gap11_private.h"

void ov15_021FF97C(BagWorkRaw *work, u16 item, BOOL draw) {
    u16 move;
    u16 type;
    u16 category;
    NarcId narc;

    ManagedSprite_SetDrawFlag(*(ManagedSprite **)&work->raw[0x26C], draw);
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)&work->raw[0x270], draw);
    if (draw != FALSE) {
        move = TMHMGetMove(item);
        type = GetMoveAttr(move, MOVEATTR_TYPE);
        category = GetMoveAttr(move, MOVEATTR_CLASS);
        narc = sub_020776B4();
        SpriteSystem_ReplaceCharResObj(*(SpriteSystem **)&work->raw[0x248], *(SpriteManager **)&work->raw[0x24C], narc, sub_02077678(type), TRUE, 0xC103);
        ManagedSprite_SetPaletteOverride(*(ManagedSprite **)&work->raw[0x26C], sub_0207769C(type) + 4);
        narc = sub_02077830();
        SpriteSystem_ReplaceCharResObj(*(SpriteSystem **)&work->raw[0x248], *(SpriteManager **)&work->raw[0x24C], narc, sub_02077800(category), TRUE, 0xC104);
        ManagedSprite_SetPaletteOverride(*(ManagedSprite **)&work->raw[0x270], sub_02077818(category) + 4);
    }
}

void ov15_021FFA40(BagWorkRaw *work) {
    SpriteResourceCountsListUnion counts = ov15_022009BC;
    *(SpriteSystem **)&work->raw[0x248] = SpriteSystem_Alloc(HEAP_ID_6);
    *(SpriteManager **)&work->raw[0x24C] = SpriteManager_New(*(SpriteSystem **)&work->raw[0x248]);
    OamManagerParam oam = ov15_022009F4;
    OamCharTransferParam transfer = ov15_022009A8;
    SpriteSystem_Init(*(SpriteSystem **)&work->raw[0x248], &oam, &transfer, 0x20);
    SpriteSystem_InitSprites(*(SpriteSystem **)&work->raw[0x248], *(SpriteManager **)&work->raw[0x24C], 0x27);
    SpriteSystem_InitManagerWithCapacities(*(SpriteSystem **)&work->raw[0x248], *(SpriteManager **)&work->raw[0x24C], &counts);
}
