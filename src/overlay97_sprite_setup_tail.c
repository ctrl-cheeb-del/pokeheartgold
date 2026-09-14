#include "pokeathlon/pokeathlon_box.h"

#include "heap.h"

extern Sprite *ov97_0221FAEC(PokeathlonBox_SubGraphics *sub, int resourceId, int drawPriority, int priority, int x, int y, int anim, BOOL draw);
extern void ov97_0221FB80(u32 *template, SpriteList *spriteList, SpriteResourcesHeader *header, int whichScreen, enum HeapID heapId);
extern void ov97_0221FBA0(PokeathlonBox_SubGraphics *sub);
extern const u8 ov97_0221FCF4[5];

void ov97_0221F9E0(PokeathlonBox_SubGraphics *sub) {
    u8 i;
    u8 j;
    int x;
    u8 *base;

    for (i = 0; i < 5; i++) {
        x = i * 32 + 104;
        base = (u8 *)sub + i * 4;
        *(Sprite **)(base + 0x1B4) = ov97_0221FAEC(sub, 1, 2, 0, x, 168, i, FALSE);
        *(Sprite **)(base + 0x1C8) = ov97_0221FAEC(sub, 1, 1, 0, x, 168, 5, FALSE);
    }

    for (i = 0; i < 5; i++) {
        x = ov97_0221FCF4[i] * 16 + 48;
        *(Sprite **)((u8 *)sub + i * 0x18 + 0x1DC) = ov97_0221FAEC(sub, 2, 1, 0, 96, x, 4, FALSE);
        base = (u8 *)sub + i * 0x18;
        for (j = 0; j < 5; j++) {
            *(Sprite **)(base + 0x1E0 + j * 4) = ov97_0221FAEC(sub, 2, 2, 0, j * 16 + 168, x, 3, FALSE);
        }
    }

    sub->unk254 = ov97_0221FAEC(sub, 3, 0, 0, 48, 72, 0, FALSE);
    sub->unk258 = Heap_Alloc(sub->heapID, 0xC80);
    ov97_0221FBA0(sub);
}

Sprite *ov97_0221FAEC(PokeathlonBox_SubGraphics *sub, int resourceId, int drawPriority, int priority, int x, int y, int anim, BOOL draw) {
    SpriteTemplate template;
    SpriteResourcesHeader header;
    Sprite *sprite;

    CreateSpriteResourcesHeader(&header, resourceId, resourceId, resourceId, resourceId, -1, -1, FALSE, priority, sub->mgrs[0], sub->mgrs[1], sub->mgrs[2], sub->mgrs[3], NULL, NULL);
    ov97_0221FB80((u32 *)&template, sub->spriteList, &header, NNS_G2D_VRAM_TYPE_2DSUB, sub->heapID);
    template.position.x = x << FX32_SHIFT;
    template.position.y = (y << FX32_SHIFT) + FX32_CONST(256);
    template.drawPriority = drawPriority;
    sprite = Sprite_CreateAffine(&template);
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, anim);
    Sprite_SetPriority(sprite, 1);
    Sprite_SetDrawFlag(sprite, draw);
    return sprite;
}
