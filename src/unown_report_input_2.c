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

void ov113_021E6238(State*s,void*v,u32 bg){u8*b=v;CopyToBgTilemapRect((void*)U32(s,0x40),(u8)bg,0,0,0x20,0x18,*(void**)(b+8),0,0,b[0xc],b[0xd]);ScheduleBgTilemapBufferTransfer((void*)U32(s,0x40),(u8)bg);}
