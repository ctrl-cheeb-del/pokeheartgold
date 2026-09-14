#include "overlay83_r40_r2_private.h"
Sprite *ov83_0224714C(void *p, int charId, int plttId, int cellId, int sequence, int drawPriority, int priority, u8 screen) {
    SpriteResourcesHeader header;
    SpriteTemplate template;
    Sprite *sprite;

    CreateSpriteResourcesHeader(&header, charId, plttId, cellId, cellId, -1, -1, 0, priority, PTR_AT(p, 0x12C), PTR_AT(p, 0x130), PTR_AT(p, 0x134), PTR_AT(p, 0x138), NULL, NULL);
    template.spriteList = PTR_AT(p, 0);
    template.header = &header;
    template.position.x = 0;
    template.position.y = 0;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = drawPriority;
    if (screen == 0) {
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    } else {
        template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    }
    template.heapID = HEAP_ID_107;
    if (screen == 1) {
        template.position.y += 192 * FX32_ONE;
    }
    sprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimSpeed(sprite, FX32_ONE);
    Sprite_SetAnimCtrlSeq(sprite, sequence);
    return sprite;
}

void ov83_022471FC(void *p) {
    u8 i;

    for (i = 0; i < 14; i++) {
        u8 *q = (u8 *)p + i * 0x10;
        SpriteTransfer_DeleteCharTransferTask(PTR_AT(q, 0x13C));
    }
    for (i = 0; i < 11; i++) {
        u8 *q = (u8 *)p + i * 0x10;
        SpriteTransfer_DeletePlttTransferTask(PTR_AT(q, 0x140));
    }
    for (i = 0; i < 4; i++) {
        u8 *q = (u8 *)p + i * 4;
        Destroy2DGfxResObjMan(PTR_AT(q, 0x12C));
    }
    SpriteList_Delete(PTR_AT(p, 0));
    OamManager_Free();
    ObjCharTransfer_Destroy();
    ObjPlttTransfer_Destroy();
}
