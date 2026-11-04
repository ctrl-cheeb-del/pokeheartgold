#ifndef POKEHEARTGOLD_BATTLE_CURSOR_H
#define POKEHEARTGOLD_BATTLE_CURSOR_H

#include "battle/battle.h"

#include "sys_task_api.h"

typedef struct BattleCursor {
    void *sprites[5];
    SysTask *task;
} BattleCursor;

void BattleCursor_LoadResources(SpriteSystem *renderer, SpriteManager *gfxHandler, PaletteData *plttData, enum HeapID heapID, u32 character, u32 pal, u32 cell, u32 animation);
void BattleCursor_FreeResources(SpriteManager *gfxHandler, u32 character, u32 pal, u32 cell, u32 animation);
BattleCursor *BattleCursor_New(SpriteSystem *renderer, SpriteManager *gfxHandler, enum HeapID heapID, u32 character, u32 pal, u32 cell, u32 animation, u32 drawPriority, u32 bgPriority);
void BattleCursor_Delete(BattleCursor *cursor);
void BattleCursor_SetCornersWithOffset(BattleCursor *cursor, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, fx32 yOffset);
void BattleCursor_SetCorners(BattleCursor *cursor, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3);
void BattleCursor_SetRect(BattleCursor *cursor, int left, int right, int top, int bottom);
void BattleCursor_SetRectWithOffset(BattleCursor *cursor, int left, int right, int top, int bottom, fx32 yOffset);
void BattleCursor_ShowExtraSpriteWithOffset(BattleCursor *cursor, int x, int y, int anim, fx32 yOffset);
void BattleCursor_Disable(BattleCursor *cursor);
void BattleCursor_HideExtraSprite(BattleCursor *cursor);

#endif
