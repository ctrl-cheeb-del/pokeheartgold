#ifndef POKEHEARTGOLD_OVERLAY40_PC_DISPLAY_R4_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY40_PC_DISPLAY_R4_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
void Sprite_DeleteAndFreeResources(void *);
void SysTask_Destroy(void *);
void SpriteManager_UnloadCharObjById(void *, int);
void ManagedSprite_SetDrawFlag(void *, int);
void TextOBJ_SetSpritesDrawFlag(void *, int);
void sub_02013FD0(void *, void *);

void ov40_0222C6C8(void *, int, int);
void ov40_0222C710(void *, int);
void ov40_0222CA8C(void *);
void ov40_0222CABC(void *);
void ov40_0222CBC0(void *);
void ov40_0222CED8(void *);
void ov40_0222CF94(void *);
void ov40_0222CFBC(void *, int);

#endif
