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

u32 ov96_021EDC38(u32 a,u32 b){switch(a){case 10:return 0;case 5:return (u8)(b?4:0);case 6:return (u8)(b?2:4);case 7:return (u8)(b?1:2);case 8:return (u8)(b?3:1);case 9:return (u8)(b?0:3);default:return a;}}

u8 ov96_021EDCB4(void *course){void *copy=PokeathlonCourse_GetDataCopyArea(course);u8*p=ov96_021E8A20((u8 *)copy+0xf0);if(course==NULL)GF_AssertFail();if(copy==NULL)GF_AssertFail();if(p==NULL)GF_AssertFail();return ((Ov96R42Bits *)(p + 4))->low3;}

u32 ov96_021EDCEC(void *course,u32 kind,u32 row,u32 col){Ov96FieldData *p=PokeathlonCourse_GetFieldData(course);if(row>=4)GF_AssertFail();if(col>=3)GF_AssertFail();switch(kind){case 0:return p->rec[row][col].f4;case 1:return p->rec[row][col].fc;case 2:return p->rec[row][col].f0;case 3:return p->rec[row][col].f14;default:GF_AssertFail();GF_AssertFail();return 0;}}

u32 ov96_021EDD64(u8*p){p[0xb3]++;if(p[0xb3]>=3){p[0xb3]=0;p[0xb2]++;}return p[0xb2]==4;}
