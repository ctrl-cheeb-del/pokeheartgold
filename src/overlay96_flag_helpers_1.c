#include "overlay96_flag_helpers_private.h"
#define WORD(p,n) (*(u32 *)((u8 *)(p)+(n)))

void ov96_021ED524(void *p,int who,int slot,int field) { void *heap=PokeathlonCourse_GetHeapAllocPtr4(p); u8 *participant=PokeathlonCourse_GetParticipantUnk04(p,who); void *str=String_New(11,*(u32 *)heap); CopyU16ArrayToString(str,(u16 *)(participant+0x28*slot+0x12)); BufferString(ov96_021EE97C(*(void **)((u8 *)heap+0xC)),field,str,2,1,0); String_Delete(str); }

void ov96_021ED578(void *p,int idx,int arg) { void *fmt=ov96_021EE97C(*(void **)((u8 *)PokeathlonCourse_GetHeapAllocPtr4(p)+0xC)); void *profile=PokeathlonCourse_GetPlayerProfileFromData(p,idx); BufferPlayersName(fmt,0,profile); ov96_021EDF3C(fmt,arg,3,1); }

void ov96_021ED5AC(void *p,int idx,int arg) { void *fmt=ov96_021EE97C(*(void **)((u8 *)PokeathlonCourse_GetHeapAllocPtr4(p)+0xC)); void *profile=PokeathlonCourse_GetPlayerProfileFromData(p,idx); BufferPlayersName(fmt,0,profile); ov96_021ED524(p,idx,arg,1); }

u32 ov96_021ED5E0(void *p) { void *copy=PokeathlonCourse_GetDataCopyArea(p); void *q=ov96_021E8A20((u8 *)copy+0xF0); if(!p)GF_AssertFail();if(!copy)GF_AssertFail();if(!q)GF_AssertFail();return MATH_CountPopulation((WORD(q,4)<<5)>>20); }

u32 ov96_021ED618(void *p,int a,int b) { int idx=b+a*3;void *copy=PokeathlonCourse_GetDataCopyArea(p);void *q=ov96_021E8A20((u8 *)copy+0xF0);if(!p)GF_AssertFail();if(!copy)GF_AssertFail();if(!q)GF_AssertFail();if(idx>=12)GF_AssertFail();return ((WORD(q,4)<<5)>>20) & (1<<idx); }

u32 ov96_021ED660(void *p,int a,int b) { int idx=b+a*3;void *copy=PokeathlonCourse_GetDataCopyArea(p);void *q=ov96_021E8A20((u8 *)copy+0xF0);if(!p)GF_AssertFail();if(!copy)GF_AssertFail();if(!q)GF_AssertFail();if(idx>=12)GF_AssertFail();return ((WORD(q,8)<<4)>>20) & (1<<idx); }

u32 ov96_021ED6A8(void *p,int a,int b) { int idx=b+a*3;void *copy=PokeathlonCourse_GetDataCopyArea(p);void *q=ov96_021E8A20((u8 *)copy+0xF0);if(!p)GF_AssertFail();if(!copy)GF_AssertFail();if(!q)GF_AssertFail();return ((WORD(q,4)<<17)>>20) & (1<<idx); }
