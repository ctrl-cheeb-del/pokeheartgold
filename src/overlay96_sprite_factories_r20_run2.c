#include "overlay96_sprite_factories_r20_private.h"

typedef struct Ov96EA854Work {
    u32 unk00;
    void *unk04;
    void *unk08;
    u32 unk0C;
    void *unk10;
    void *unk14;
    void *unk18;
    u8 unk1C[0x330];
} Ov96EA854Work;

Sprite *ov96_021EA7A4(void *resources, SpriteList *spriteList, int priority, enum HeapID heapId) {
    SpriteResourcesHeader header;
    SpriteTemplate template;
    Sprite *sprite;
    void *res0;
    void *res1;
    void *res2;
    void *res3;

    res0 = ov96_021E9D08(resources, 0);
    res1 = ov96_021E9D08(resources, 1);
    res2 = ov96_021E9D08(resources, 2);
    res3 = ov96_021E9D08(resources, 3);
    CreateSpriteResourcesHeader(&header, 0x20, 0x17, 0x20, 0x20, -1, -1, 0, priority, res0, res1, res2, res3, NULL, NULL);
    template.spriteList = spriteList;
    template.header = &header;
    template.heapID = heapId;
    template.position.x = 0;
    template.position.y = 0;
    template.position.z = 0;
    template.scale.x = FX32_ONE;
    template.scale.y = FX32_ONE;
    template.scale.z = FX32_ONE;
    template.rotation = 0;
    template.drawPriority = 2;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DMAIN;
    sprite = Sprite_CreateAffine(&template);
    if (sprite == NULL) {
        GF_AssertFail();
    }
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, 0);
    Sprite_SetDrawFlag(sprite, FALSE);
    return sprite;
}

void *ov96_021EA854(enum HeapID arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    Ov96EA854Work *work = Heap_Alloc(arg0, sizeof(Ov96EA854Work));
    MI_CpuFill8(work, 0, sizeof(Ov96EA854Work));
    work->unk00 = arg0;
    work->unk04 = arg1;
    work->unk18 = arg3;
    work->unk10 = arg4;
    work->unk08 = arg2;
    work->unk14 = ov96_021E8A30(arg0);
    ov96_021E8A44(work->unk14, arg1, arg4);
    return work;
}
