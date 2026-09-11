#include "overlay56_sprite_setup_internal.h"

void ov56_021E6BB4(Ov56WorkResidual *work) {
    ManagedSpriteTemplate template;
    OamManagerParam oam;
    OamCharTransferParam transfer;
    SpriteResourceCountsListUnion counts;
    int i;
    int recordOffset;
    int xOffset;
    u8 *spriteSlot;

    sub_0203A964();
    if (work->mode == 1) {
        return;
    }

    GF_CreateVramTransferManager(0x20, work->heapId);
    work->spriteSystem = SpriteSystem_Alloc(work->heapId);
    work->spriteManager = SpriteManager_New(work->spriteSystem);
    oam = ov56_021E6E38;
    transfer = ov56_021E6DF4;
    counts = ov56_021E6E08;
    SpriteSystem_Init(work->spriteSystem, &oam, &transfer, 0x20);
    SpriteSystem_InitSprites(work->spriteSystem, work->spriteManager, 3);
    SpriteSystem_InitManagerWithCapacities(work->spriteSystem, work->spriteManager, &counts);
    thunk_ClearMainOAM(work->heapId);

    SpriteSystem_LoadPlttResObj(work->spriteSystem, work->spriteManager, NARC_poketool_icongra_poke_icon, sub_02074490(), FALSE, 3, 1, 0);
    SpriteSystem_LoadCellResObj(work->spriteSystem, work->spriteManager, NARC_poketool_icongra_poke_icon, sub_02074494(), FALSE, 0);
    SpriteSystem_LoadAnimResObj(work->spriteSystem, work->spriteManager, NARC_poketool_icongra_poke_icon, sub_020744A0(), FALSE, 0);

    i = 0;
    recordOffset = i;
    xOffset = i;
    spriteSlot = (u8 *)work;
    for (; i < 3; i++, recordOffset += 2, spriteSlot += 4, xOffset += 0x28) {
        if (((volatile Ov56Record *)(work->records + recordOffset))->resource.raw == 0xFFFF) {
            return;
        }
        SpriteSystem_LoadCharResObjWithHardwareMappingType(work->spriteSystem,
            work->spriteManager,
            NARC_poketool_icongra_poke_icon,
            ((volatile Ov56Record *)(work->records + recordOffset))->resource.id,
            FALSE,
            1,
            i);
        MI_CpuFill8(&template, 0, sizeof(template));
        template.x = 0x80 - xOffset;
        template.y = 0xA0;
        template.z = 0;
        template.animation = 0;
        template.bgPriority = 2;
        template.pal = ((volatile Ov56Record *)(work->records + recordOffset))->resource.palette;
        template.vramTransfer = 0;
        template.vram = NNS_G2D_VRAM_TYPE_2DMAIN;
        template.resIdList[0] = i;
        template.resIdList[1] = 0;
        template.resIdList[2] = 0;
        template.resIdList[3] = 0;
        template.resIdList[4] = -1;
        template.resIdList[5] = -1;
        *(ManagedSprite **)(spriteSlot + 0xB8) = SpriteSystem_NewSprite(work->spriteSystem, work->spriteManager, &template);
        if (((volatile Ov56Record *)(work->records + recordOffset))->resource.id == 7) {
            ManagedSprite_SetDrawFlag(*(ManagedSprite **)(spriteSlot + 0xB8), FALSE);
        }
    }
}
