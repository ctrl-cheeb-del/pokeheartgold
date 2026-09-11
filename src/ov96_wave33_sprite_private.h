#ifndef R25_H
#define R25_H
#include "global.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
void GF_AssertFail(void);void ov96_0220D014(u8 *,int,u32);void ov96_0220D0F8(u8 *);
typedef struct R25Template { u16 x,y,z,arg5; u32 arg6; u32 rest[10]; } R25Template;
extern const R25Template ov96_0221CE84,ov96_0221CEB8;
void *SpriteSystem_NewSpriteWithYOffset(void *,void *,R25Template *,u32);void ManagedSprite_SetAnimateFlag(void *,int);
void *ov96_0220D13C(void *,void *,u16,u16,u16,u16);void *ov96_0220D1A0(void *,void *,u16,u16,u16,u16);
#endif
