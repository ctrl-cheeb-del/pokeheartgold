#include "global.h"
typedef struct Work{u8 d[0xe00];}Work;
#define U32(w,o) (*(u32*)((w)->d+(o)))
extern void GF_AssertFail(void);extern const u16 ov96_0221AA20[];extern u32 PokeathlonCourse_GetHeapID(Work*);extern void *NARC_New(u32,u32);extern void NARC_ReadWholeMember(void*,u32,void*);extern void NARC_Delete(void*);extern u32 sub_02031B10(void);extern void *Heap_Alloc(u32,u32);extern void sub_0203410C(void*,void*,void*);extern void *ov96_021E883C(void*,void*,void*,u32);
extern u32 LCRandom(void);
extern void *Save_Pokeathlon_Get(void*);extern u32 PokeathlonCourse_GetField3D8_ForCurrentParticipant(Work*);extern void*PokeathlonSave_GetRecordsLink2(void*);extern void*PokeathlonSave_GetRecordsSolo2(void*);extern const u8 _0221A7D8[];
void ov96_021E8324(Work*,void*);void ov96_021E8340(u32,u32,u32*);BOOL ov96_021E839C(Work*);u16 ov96_021E8424(u8);u8 ov96_021E8448(Work*,u8);void ov96_021E860C(u32,u8,u32,u8*);void*ov96_021E86FC(Work*,u32);BOOL ov96_021E872C(s32,s32,s32,s32,s32,fx32*);void*ov96_021E8770(void*,void*,void*,u32,u32);
typedef struct Rec{u16 kind,pad;void*p;}Rec;

void*ov96_021E8770(void*a,void*b,void*c,u32 kind,u32 heap){Rec*r=Heap_Alloc(heap,8);r->kind=kind;r->pad=0;r->p=0;if(kind==1)sub_0203410C(a,b,c);else r->p=ov96_021E883C(a,b,c,heap);return r;}
