#include "overlay96_field_helpers_private.h"
extern void GF_AssertFail(void);
extern u32 MATH_CountPopulation(u32);
extern void *PokeathlonCourse_GetDataCopyArea(void *);
extern void *PokeathlonCourse_GetFieldData(void *);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);
extern u32 PokeathlonCourse_GetHeapID(void *);
extern u32 PokeathlonCourse_GetMode(void *);
extern s32 PokeathlonCourse_GetParticipantCount(void *);
extern u32 PokeathlonCourse_GetParticipantUnk04(void *, u32);
extern u32 ov96_021E5F24(void *);
extern void *ov96_021E8A20(void *);
extern void ov96_021EE0AC(void *, void *);
extern void ov96_021EE144(void *, void *, u8);
extern void ov96_021EE1D8(void *, void *, u8);
extern u32 MTRandom(void);
extern void *NARC_New(u32, u32);
extern void NARC_Delete(void *);
extern void NARC_ReadWholeMember(void *, u32, void *);
extern u32 ov96_021E679C(u16,u16);
extern u32 ov96_021EDCEC(void *,u32,u32,u32);
extern void BufferIntegerAsString(void *,u32,s32,u32,u32,u32);
extern const s32 ov96_0221B058[];
extern void ov96_021ED5AC(void *,u8,u8); extern void ov96_021ECC38(void *,u8,u16); extern void ov96_021EC298(void *,u8); extern void ov96_021EAA04(void *,u8); extern void *ov96_021EAA20(void *); extern void *ov96_021E8BB0(void *); extern void sub_02006E3C(u8); extern u32 PlayCry(u16,u8);
typedef u32 (*Ov96R42Callback)(void *,u8,u8);
u32 ov96_021EDDA4(void *,Ov96R42Callback,u32);

u32 ov96_021ED754(void *); u32 ov96_021ED78C(void *); u32 ov96_021ED7C4(void *);
void ov96_021ED7FC(void *,u8 *); u32 ov96_021ED838(void *,u32); u32 ov96_021ED86C(void *,u32); u32 ov96_021ED8A4(void *,u32);
void ov96_021ED8DC(void *); u32 ov96_021ED954(void *,u32); u32 ov96_021ED9CC(void *); u32 ov96_021EDC38(u32,u32); u8 ov96_021EDCB4(void *); u32 ov96_021EDCEC(void *,u32,u32,u32); u32 ov96_021EDD64(u8 *); void ov96_021EDF3C(void *,s32,u32,u32); u32 ov96_021EDF5C(s32);

u32 ov96_021ED754(void *course) {
    void *copy = PokeathlonCourse_GetDataCopyArea(course);
    u8 *p = ov96_021E8A20((u8 *)copy + 0xf0);
    if (course == NULL) GF_AssertFail(); if (copy == NULL) GF_AssertFail(); if (p == NULL) GF_AssertFail();
    return MATH_CountPopulation((U32AT(p,4) << 5) >> 20);
}

u32 ov96_021ED78C(void *course) {
    void *copy = PokeathlonCourse_GetDataCopyArea(course);
    u8 *p = ov96_021E8A20((u8 *)copy + 0xf0);
    if (course == NULL) GF_AssertFail(); if (copy == NULL) GF_AssertFail(); if (p == NULL) GF_AssertFail();
    return MATH_CountPopulation((U32AT(p,8) << 4) >> 20);
}

u32 ov96_021ED7C4(void *course) {
    void *copy = PokeathlonCourse_GetDataCopyArea(course);
    u8 *p = ov96_021E8A20((u8 *)copy + 0xf0);
    if (course == NULL) GF_AssertFail(); if (copy == NULL) GF_AssertFail(); if (p == NULL) GF_AssertFail();
    return MATH_CountPopulation((U32AT(p,4) << 17) >> 20);
}

void ov96_021ED7FC(void *course, u8 *out) {
    void *copy = PokeathlonCourse_GetDataCopyArea(course); u8 *p = ov96_021E8A20((u8 *)copy + 0xf0); s32 i;
    if (course == NULL) GF_AssertFail(); if (copy == NULL) GF_AssertFail(); if (p == NULL) GF_AssertFail();
    for (i=0;i<4;i++) out[i]=p[0xd+i];
}

u32 ov96_021ED838(void *course, u32 i) {
    void *copy=PokeathlonCourse_GetDataCopyArea(course); u8 *p=ov96_021E8A20((u8 *)copy+0xf0);
    if(course==NULL)GF_AssertFail(); if(copy==NULL)GF_AssertFail(); if(p==NULL)GF_AssertFail(); return U32AT(p,i*8);
}

u32 ov96_021ED86C(void *course, u32 i) {
    void *copy=PokeathlonCourse_GetDataCopyArea(course); u8 *p=ov96_021E8A20((u8 *)copy+0xf0);
    if(course==NULL)GF_AssertFail(); if(copy==NULL)GF_AssertFail(); if(p==NULL)GF_AssertFail(); return ((Ov96R42Rec *)p)[i].low24;
}

u32 ov96_021ED8A4(void *course, u32 i) {
    void *copy=PokeathlonCourse_GetDataCopyArea(course); u8 *p=ov96_021E8A20((u8 *)copy+0xf0);
    if(course==NULL)GF_AssertFail(); if(copy==NULL)GF_AssertFail(); if(p==NULL)GF_AssertFail(); return ((Ov96R42Rec *)p)[i].high8;
}

void ov96_021ED8DC(void *course) {
    u8 *p=ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(course)+0x28); s32 i;
    if(PokeathlonCourse_GetMode(course)==0){for(i=0;i<4;i++,p+=8){if(i==ov96_021E5F24(course))ov96_021EE0AC(p,course);else ov96_021EE1D8(p,course,(u8)i);}}
    else {for(i=0;i<4;i++,p+=8){if(PokeathlonCourse_GetParticipantCount(course)>i)ov96_021EE144(p,course,(u8)i);else ov96_021EE1D8(p,course,(u8)i);}}
}

u32 ov96_021ED954(void *course, u32 idx) {
    u8 data[20]; void *narc; u8 *q; s32 result=75; s32 i;
    narc=NARC_New(0xa9,PokeathlonCourse_GetHeapID(course)); q=(u8 *)PokeathlonCourse_GetParticipantUnk04(course,idx);
    for(i=0;i<3;i++,q+=0x28){NARC_ReadWholeMember(narc,ov96_021E679C(*(u16 *)q,*(u16 *)(q+2)),data); result-=data[0]+1;result-=data[1]+1;result-=data[2]+1;result-=data[3]+1;result-=data[4]+1;}
    if(result>75)result=75; else if(result<0)result=0; NARC_Delete(narc); return result;
}
