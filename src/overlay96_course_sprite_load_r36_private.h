#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_SPRITE_LOAD_R36_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_SPRITE_LOAD_R36_PRIVATE_H

#include "global.h"

#include "filesystem_files_def.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

BOOL SpriteSystem_LoadCharResObj(void *, void *, NarcId, int, BOOL, int, int);
BOOL SpriteSystem_LoadCellResObj(void *, void *, int, int, int, int);
BOOL SpriteSystem_LoadAnimResObj(void *, void *, int, int, int, int);
void ov96_021ECA18(void *);

#endif
