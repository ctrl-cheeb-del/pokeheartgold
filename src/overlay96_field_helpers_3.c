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

void ov96_021EDF3C(void *fmt,s32 value,u32 digits,u32 field){BufferIntegerAsString(fmt,field,value,digits,0,1);}

u32 ov96_021EDF5C(s32 value){s32 i;for(i=0;i<12;i++){if(ov96_0221B058[i]>value)return i;}return i;}
