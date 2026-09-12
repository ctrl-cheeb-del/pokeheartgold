#include "overlay96_sprite_factories_r20_private.h"

Sprite *ov96_021EA214(void *resources, SpriteList *spriteList, int priority, NNS_G2D_VRAM_TYPE whichScreen, enum HeapID heapId) {
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
    CreateSpriteResourcesHeader(&header, 0x14, 0x17, 0x14, 0x14, -1, -1, 0, priority, res0, res1, res2, res3, NULL, NULL);
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
    template.drawPriority = 0;
    template.whichScreen = whichScreen;
    sprite = Sprite_CreateAffine(&template);
    if (sprite == NULL) {
        GF_AssertFail();
    }
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, 0);
    Sprite_SetDrawFlag(sprite, FALSE);
    return sprite;
}

Sprite *ov96_021EA2C4(void *resources, SpriteList *spriteList, int priority, enum HeapID heapId) {
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
    CreateSpriteResourcesHeader(&header, 0x19, 0x18, 0x19, 0x19, -1, -1, 0, priority, res0, res1, res2, res3, NULL, NULL);

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
    template.drawPriority = 0;
    template.whichScreen = NNS_G2D_VRAM_TYPE_2DSUB;
    sprite = Sprite_CreateAffine(&template);
    if (sprite == NULL) {
        GF_AssertFail();
    }
    Sprite_SetAnimActiveFlag(sprite, TRUE);
    Sprite_SetAnimCtrlSeq(sprite, 0);
    Sprite_SetDrawFlag(sprite, FALSE);
    return sprite;
}

#define DEFINE_SPRITE_FACTORY(name, resourceId, paletteId, screen, drawPrio)                                                                          \
    Sprite *name(void *resources, SpriteList *spriteList, int priority, enum HeapID heapId) {                                                         \
        SpriteResourcesHeader header;                                                                                                                 \
        SpriteTemplate template;                                                                                                                      \
        Sprite *sprite;                                                                                                                               \
        void *res0;                                                                                                                                   \
        void *res1;                                                                                                                                   \
        void *res2;                                                                                                                                   \
        void *res3;                                                                                                                                   \
        res0 = ov96_021E9D08(resources, 0);                                                                                                           \
        res1 = ov96_021E9D08(resources, 1);                                                                                                           \
        res2 = ov96_021E9D08(resources, 2);                                                                                                           \
        res3 = ov96_021E9D08(resources, 3);                                                                                                           \
        CreateSpriteResourcesHeader(&header, resourceId, paletteId, resourceId, resourceId, -1, -1, 0, priority, res0, res1, res2, res3, NULL, NULL); \
        template.spriteList = spriteList;                                                                                                             \
        template.header = &header;                                                                                                                    \
        template.heapID = heapId;                                                                                                                     \
        template.position.x = 0;                                                                                                                      \
        template.position.y = 0;                                                                                                                      \
        template.position.z = 0;                                                                                                                      \
        template.scale.x = FX32_ONE;                                                                                                                  \
        template.scale.y = FX32_ONE;                                                                                                                  \
        template.scale.z = FX32_ONE;                                                                                                                  \
        template.rotation = 0;                                                                                                                        \
        template.whichScreen = screen;                                                                                                                \
        template.drawPriority = drawPrio;                                                                                                             \
        sprite = Sprite_CreateAffine(&template);                                                                                                      \
        if (sprite == NULL) {                                                                                                                         \
            GF_AssertFail();                                                                                                                          \
        }                                                                                                                                             \
        Sprite_SetAnimActiveFlag(sprite, TRUE);                                                                                                       \
        Sprite_SetAnimCtrlSeq(sprite, 0);                                                                                                             \
        Sprite_SetDrawFlag(sprite, FALSE);                                                                                                            \
        return sprite;                                                                                                                                \
    }

DEFINE_SPRITE_FACTORY(ov96_021EA374, 0x1C, 0x17, NNS_G2D_VRAM_TYPE_2DMAIN, 0)
DEFINE_SPRITE_FACTORY(ov96_021EA424, 0x1A, 0x17, NNS_G2D_VRAM_TYPE_2DMAIN, 0)
DEFINE_SPRITE_FACTORY(ov96_021EA4D4, 0x1B, 0x17, NNS_G2D_VRAM_TYPE_2DMAIN, 0)
DEFINE_SPRITE_FACTORY(ov96_021EA584, 0x1D, 0x17, NNS_G2D_VRAM_TYPE_2DMAIN, 0)
DEFINE_SPRITE_FACTORY(ov96_021EA634, 0x1E, 0x18, NNS_G2D_VRAM_TYPE_2DSUB, 0)
