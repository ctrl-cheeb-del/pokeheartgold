#include "global.h"
typedef struct Work {u8 d[0xe00];} Work;
#define U32(w,o) (*(u32*)((w)->d+(o)))
#define U8(w,o) ((w)->d[(o)])
typedef void (*EndFn)(Work*,u32);typedef struct Ops4{void*f0;EndFn end;}Ops4;typedef struct OpsC{void*f0,*f4,*f8;EndFn end;}OpsC;
extern BOOL ov96_021E5F24(Work*);extern void PokeathlonCourse_SetStateField07(Work*,u32);extern void PokeathlonCourse_SetStateField07_IfDifferent(Work*,u32,u32);extern BOOL ov96_021E87EC(u32,void*,void*,void*);extern void *ov96_021E99F8(void);extern void *ov96_021E99FC(void);extern void *ov96_021E9A04(void);extern void *PokeathlonCourse_GetParticipantData(Work*,u32);extern void *PokeathlonCourse_GetSystem(Work*);extern void PokeathlonCourse_ResetDataCopyArea(Work*);extern void PokeathlonCourse_InitStateInfo(const void*,void*);extern BOOL PokeathlonCourse_RunSubStateLoop(Work*);extern void *PokeathlonCourse_GetDataCopyArea(Work*);extern void ov96_021E87B0(void*,u32);extern void PokeathlonCourse_SetStateTransitionType(Work*,u32);extern void Sound_SetScene(u32);extern void Sound_SetSceneAndPlayBGM(u32,u32,u32);extern void GF_AssertFail(void);extern const u8 ov96_0221A808[];extern const u8 ov96_0221DA50[];extern const u8 ov96_0221A8E4[];extern const u8 ov96_0221DA6C[];
void ov96_021E67AC(Work*);u32 ov96_021E695C(Work*);u32 ov96_021E6990(Work*);u32 ov96_021E69C4(Work*);u32 ov96_021E6A54(Work*);u32 ov96_021E6A94(Work*);u32 ov96_021E6BC0(Work*);u32 ov96_021E6BEC(Work*);u32 ov96_021E6C20(Work*);u32 ov96_021E6CB8(Work*);
u32 ov96_021E67C4(Work*);u32 ov96_021E6DE8(Work*);
extern void ov96_021E811C(void*,u32,void*);extern void *ov96_021E99F4(void);extern BOOL ov96_021E87B4(u32,void*,void*,void*);
extern BOOL OverlayManager_Run(void*);extern void OverlayManager_Delete(void*);
u32 ov96_021E6814(Work*);

u32 ov96_021E6DE8(Work*w){if(U32(w,0x3b0)!=0){if(!ov96_021E5F24(w)){if(ov96_021E87EC(0x1c,(void*)U32(w,0x3a4),(void*)U32(w,0x3ac),(void*)U32(w,0x288)))PokeathlonCourse_SetStateField07(w,0x26);}else PokeathlonCourse_SetStateField07(w,0x26);}else PokeathlonCourse_SetStateField07(w,0x12);return 0;}
