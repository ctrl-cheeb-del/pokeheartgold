#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
void *Sprite_GetImageProxy(void *);
u32 Boxmon_GetIconNaix(void *);void *GfGfxLoader_GetCharDataFromOpenNarc(void *,u32,int,void **,u32);u32 Boxmon_GetIconPalette(void *);void Heap_Free(void *);void ManagedSprite_SetPaletteOverride(void *,int);void ManagedSprite_SetDrawFlag(void *,int);
void ov14_021F2C1C(void *,int,void *,u32);void ov14_021F2C50(void *,int,void *,u32);void *ov14_021F2DC4(void *,void *,void **);void ov14_021F2E78(void *,void *,int,int);void ov14_021F2EA0(void *,void *,int);int ov14_021E6070(void *,int,int,int);
void *ov14_021E60C0(void *,int,int);
void ov14_021F2ED0(void *,int,int,int);void ov14_021F2F20(void *);
void ov14_021F2A60(void *,int,int);void ov14_021F2A74(void *,int,int);void ov14_021F3190(void *,u32,int);void ov14_021F31E0(void *,int,u32);
void ManagedSprite_SetAffineOverwriteMode(void *,int);void ManagedSprite_SetAffineScale(void *,u32,u32);void ManagedSprite_SetAffineTranslation(void *,int,int);u32 _fsub(u32,u32);u32 _fadd(u32,u32);
void ov14_021F3354(void *);int ov14_021F3380(void *);int ov14_021F33B0(void *);
u32 Party_GetCount(void *);
void *Party_GetMonByIndex(void *,u32);
void *Mon_GetBoxMon(void *);
extern s16 ov14_021F80BC[];
void ov14_021F2F3C(void *);
void ov14_021F2F88(u32,s16 *,s16 *,int);
void ov14_021F2A18(void *,int,int);
void ov14_021F3190(void *,u32,int);
void ov14_021F31E0(void *,int,u32);
void ov14_021F2A18(void *,int,int);
void ov14_021F2A60(void *,int,int);
void ov14_021F2A74(void *,int,int);
void ov14_021F2E8C(void *,void *,void *,int,int,int);
void *NewString_ReadMsgData(void *,int);
void ov14_021F2FC4(void *,void *,void *,int,int);
void String_Delete(void *);
void ov14_021F41DB4(void *,int);
void ListMenuItems_Delete(void *);
int ov14_021F2D90(void *);
int ov14_021F2E74(void *);
#endif
