#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void *PokeathlonCourse_GetParticipantUnk04(void *,int);
void *String_New(int,u32);
void CopyU16ArrayToString(void *,const u16 *);
void BufferString(void *,int,void *,int,int,int);
void String_Delete(void *);
void *PokeathlonCourse_GetPlayerProfileFromData(void *,int);
void *ov96_021EE97C(void *);
void BufferPlayersName(void *,int,void *);
void ov96_021EDF3C(void *,int,int,int);
void ov96_021ED524(void *,int,int,int);
void *PokeathlonCourse_GetDataCopyArea(void *);
void *ov96_021E8A20(void *);
void GF_AssertFail(void);
u32 MATH_CountPopulation(u32);
void ov96_021ED578(void *,int,int);
void ov96_021ED5AC(void *,int,int);
u32 ov96_021ED5E0(void *);
u32 ov96_021ED618(void *,int,int);
u32 ov96_021ED660(void *,int,int);
u32 ov96_021ED6A8(void *,int,int);
#endif
