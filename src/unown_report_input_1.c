#include "global.h"
#include "system.h"
typedef struct State { u8 d[0x300]; } State;
#define U32(s,o) (*(u32*)((s)->d+(o)))
#define U8(s,o) ((s)->d[(o)])
extern void PlaySE(u32);
extern void ov113_021E5E64(State*,u32);
extern void Sprite_SetAnimCtrlSeq(void*,u32);
extern int TouchscreenHitbox_FindHitboxAtTouchNew(const void*);
extern const u8 ov113_021E6B82[];
extern u32 ov113_021E5ED0(State*,u32);
extern void CopyToBgTilemapRect(void*,u8,u32,u32,u32,u32,void*,u32,u32,u32,u32);
extern void ScheduleBgTilemapBufferTransfer(void*,u8);
u32 ov113_021E5ED0(State*,u32);u32 ov113_021E5F48(State*);u32 ov113_021E5F94(State*,u32*);void ov113_021E6238(State*,void*,u32);

u32 ov113_021E5ED0(State*s,u32 dir){switch(dir){case 0:PlaySE(0x5dd);ov113_021E5E64(s,1);return 1;case 1:if(U8(s,0x1a)==0)return 2;U8(s,0x1a)--;Sprite_SetAnimCtrlSeq((void*)U32(s,0xbc),3);PlaySE(0x5dc);return 3;case 2:if(U8(s,0x1a)>=U8(s,0x1b)-1)return 2;U8(s,0x1a)++;Sprite_SetAnimCtrlSeq((void*)U32(s,0xc0),6);PlaySE(0x5dc);return 3;default:return 2;}}

u32 ov113_021E5F48(State*s){if(gSystem.newKeys&0xcf3)U32(s,0x14)=0;if(gSystem.newKeys&2)return ov113_021E5ED0(s,0);if(gSystem.newKeys&0x40)return ov113_021E5ED0(s,1);if(gSystem.newKeys&0x80)return ov113_021E5ED0(s,2);return 2;}

u32 ov113_021E5F94(State*s,u32*hit){int n=TouchscreenHitbox_FindHitboxAtTouchNew(ov113_021E6B82);if(n==-1)return 2;*hit=1;U32(s,0x14)=1;return ov113_021E5ED0(s,n);}
