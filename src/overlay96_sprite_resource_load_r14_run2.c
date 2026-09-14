#include "overlay96_sprite_resource_load_r14_private.h"

void ov96_021E8EE4(u8 *gfx, int priority, int transfer, NNS_G2D_VRAM_TYPE whichScreen, u8 resourceId, u8 index) {
    SpriteResourcesHeader header;
    SpriteTemplate template;
    Sprite *sprite;
    int offset;

    CreateSpriteResourcesHeader(&header, resourceId, resourceId, resourceId, resourceId, -1, -1, transfer, priority, PTR_AT(gfx, 0x144), PTR_AT(gfx, 0x148), PTR_AT(gfx, 0x14C), PTR_AT(gfx, 0x150), NULL, NULL);
    if (whichScreen == NNS_G2D_VRAM_TYPE_2DBOTH) {
        whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    }
    template.spriteList = PTR_AT(gfx, 0x18);
    template.header = &header;
    template.heapID = (enum HeapID)U32_AT(gfx, 0);
    template.position.x = 0;
    template.position.y = 0;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.whichScreen = whichScreen;
    template.drawPriority = 0;
    offset = index * 0x2C;
    sprite = Sprite_CreateAffine(&template);
    PTR_AT((u8 *)PTR_AT(gfx, 0x154) + offset, 0x10) = sprite;
    if (PTR_AT((u8 *)PTR_AT(gfx, 0x154) + offset, 0x10) == NULL) {
        GF_AssertFail();
    }
    Sprite_SetAnimActiveFlag(PTR_AT((u8 *)PTR_AT(gfx, 0x154) + offset, 0x10), TRUE);
    Sprite_SetAnimCtrlSeq(PTR_AT((u8 *)PTR_AT(gfx, 0x154) + offset, 0x10), 0);
    Sprite_SetDrawFlag(PTR_AT((u8 *)PTR_AT(gfx, 0x154) + offset, 0x10), FALSE);
}

void ov96_021E8FB4(void *task, u8 *work) {
    do {
        if (ov96_021E8FE0(work)) {
            U32_AT(PTR_AT(work, 0xC), 0xC) = 1;
            Heap_Free(work);
            SysTask_Destroy(task);
            return;
        }
    } while (PTR_AT(work, 0x10) != NULL);
}
