#ifndef OVERLAY96_SPRITE_FACTORIES_R20_PRIVATE_H
#define OVERLAY96_SPRITE_FACTORIES_R20_PRIVATE_H

#include "global.h"

#include "sprite.h"

void *ov96_021E8A30(enum HeapID);
void ov96_021E8A44(void *, void *, void *);
void *ov96_021E9D08(void *, int);
void GF_AssertFail(void);

Sprite *ov96_021EA214(void *, SpriteList *, int, NNS_G2D_VRAM_TYPE, enum HeapID);
Sprite *ov96_021EA2C4(void *, SpriteList *, int, enum HeapID);
Sprite *ov96_021EA374(void *, SpriteList *, int, enum HeapID);
Sprite *ov96_021EA424(void *, SpriteList *, int, enum HeapID);
Sprite *ov96_021EA4D4(void *, SpriteList *, int, enum HeapID);
Sprite *ov96_021EA584(void *, SpriteList *, int, enum HeapID);
Sprite *ov96_021EA634(void *, SpriteList *, int, enum HeapID);
Sprite *ov96_021EA7A4(void *, SpriteList *, int, enum HeapID);
void *ov96_021EA854(enum HeapID, void *, void *, void *, void *);

#endif
