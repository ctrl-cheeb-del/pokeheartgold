#ifndef POKEHEARTGOLD_RENDER_WINDOW_SPRITE_SETUP_PRIVATE_H
#define POKEHEARTGOLD_RENDER_WINDOW_SPRITE_SETUP_PRIVATE_H

#include "field/field_sprite_manager.h"

#include "gf_gfx_planes.h"

typedef struct RenderWindowSpriteManager {
    FieldSpriteManager manager;
    u8 padding[0x164 - sizeof(FieldSpriteManager)];
    ManagedSprite *sprite;
} RenderWindowSpriteManager;

extern const SpriteResourceCountsListUnion _020F5C60;
extern const ManagedSpriteTemplate _020F5C78;

void sub_0200F600(FieldSpriteManager *manager, enum HeapID heapId);
void sub_0200F62C(FieldSpriteManager *manager);
void sub_0200F684(RenderWindowSpriteManager *manager, int x, int y);

#endif
