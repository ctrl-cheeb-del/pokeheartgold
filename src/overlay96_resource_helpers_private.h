#ifndef R21_OV96_PRIVATE_H
#define R21_OV96_PRIVATE_H
#include "global.h"
#define U8P(p,o) ((u8 *)(p)+(o))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
void *Sprite_CreateAffine(void *);
void Sprite_SetAnimActiveFlag(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_SetDrawFlag(void *, int);
void Sprite_SetDrawPriority(void *, int);
void Sprite_SetPaletteOverride(void *, int);
void TextOBJ_SetSpritesDrawFlag(void *, int);
void TextOBJ_Destroy(void *);
void sub_02021B5C(void *);
void sub_02013938(void *);
void RemoveWindow(void *);
void sub_020135AC(void *);
void Heap_Free(void *);
void GF_AssertFail(void);
void ov96_021F8C88(s32,s32,void *);
void ov96_021F91E8(u8 *,s32);
void ov96_021F91CC(u8 *);
void *ov96_021EB5B8(void *);
typedef struct R21SpriteTemplate R21SpriteTemplate;
void ov96_021F8A98(R21SpriteTemplate *, u8 *, void *, u32);
void *ov96_021F8ACC(void *, s32, s32);
void ov96_021F8C2C(u8 *);
void ov96_021F8C54(BOOL, BOOL, u8 *);
void ov96_021F8DD4(u8 *);
void ov96_021F8E94(u8 *);
void ov96_021F8F0C(u8 *);
void ov96_021F910C(u8 *, void *, u32);
void ov96_021F8F44(u8 *, s32);
void ov96_021F8C04(u8 *, void *, u8 *);
void ov96_021F8BC0(u8 *, s32, u8 *);
void ov96_021F8DF4(void *, void *, void *, s32, s32, s32, void *, void *);
void *PokeathlonCourse_GetPlayerProfileFromData(void *, s32);
void *PlayerProfile_GetPlayerName_NewString(void *, u32);
void String_Delete(void *);
void ov96_021F8D98(u8 *, u8 *, s32);
void InitWindow(void *);
void AddTextWindowTopLeftCorner(void *, void *, u8, s32, s32, s32);
void *sub_02013910(void *, void *);
void *sub_02013948(void *, s32);
void ov96_021F8A50(u8 *);
void CreateSpriteResourcesHeader(void *, s32, s32, s32, s32, s32, s32, s32, s32, void *, void *, void *, void *, s32, s32);
void *ov96_021F8EB0(u32, void *, void *);
void *Heap_Alloc(u32, u32);
void MI_CpuFill8(void *, u8, u32);
void *FontSystem_NewInit(s32, u32);
void ov96_021EB29C(void *, s32, s32);
void ov96_021EB2BC(void *, s32, s32, s32, s32);
void ov96_021EB2F4(void *, s32, s32, s32, s32, s32);
void ov96_021EB334(void *, s32, s32, s32);
void ov96_021EB36C(void *, s32, s32, s32);
#endif
