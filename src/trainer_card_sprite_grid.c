#include "trainer_card_main_22_private.h"

void ov51_021E7AF4(TrainerCardMainState22 *work, const u8 *drawFlags, int mode) {
    SpriteResourcesHeader header;
    SpriteTemplate template;
    int yOffset;
    int i;
    TrainerCardMainState22 *cursor;
    const TrainerCardSpritePosition22 *position;

    CreateSpriteResourcesHeader(&header, 0, 0, 0, 0, -1, -1, 0, 1, work->resourceManagers[0][0], work->resourceManagers[0][1], work->resourceManagers[0][2], work->resourceManagers[0][3], NULL, NULL);
    template.spriteList = work->spriteList;
    template.header = &header;
    template.position.x = 0;
    template.position.y = 0;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = 2;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    template.heapID = HEAP_ID_25;
    if (mode == 0) {
        yOffset = 40;
    } else {
        yOffset = 0;
    }
    cursor = work;
    position = ov51_021E801C;
    for (i = 0; i < 16; i++, position++, cursor = (TrainerCardMainState22 *)((u8 *)cursor + 4)) {
        template.position.x = position->x << FX32_SHIFT;
        template.position.y = (yOffset + position->y) << FX32_SHIFT;
        cursor->sprites[0] = Sprite_CreateAffine(&template);
        Sprite_SetAnimActiveFlag(cursor->sprites[0], TRUE);
        Sprite_SetAnimCtrlSeq(cursor->sprites[0], i);
        if (drawFlags[i] == 0 || (mode == 0 && i > 7)) {
            Sprite_SetDrawFlag(cursor->sprites[0], FALSE);
        }
    }
}
