#ifndef POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_R86_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_COURSE_SCENE_R86_PRIVATE_H
#include "global.h"

typedef struct GfxBanks40 {
    u32 words[10];
} GfxBanks40;
extern const GfxBanks40 ov96_0221CB9C;
extern u8 gSystem[];
void *PokeathlonCourse_GetGraphicsSystem(void *);
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void *PokeathlonCourse_GetDataCopyArea(void *);
u16 PokeathlonCourse_GetField5F0_AtIndex(void *, u8);
void PokeathlonCourse_SetField5E0_AtIndex(void *, u8, u16);
void PokeathlonCourse_ResetField3A4(void *);
void PokeathlonCourse_FreePtr4HeapAlloc(void *);
void PokeathlonCourse_SetStateField07(void *, int);
BOOL ov96_021E5F24(void *);
BOOL ov96_021E637C(void *);
BOOL ov96_021E667C(void *);
void ov96_021E9510(void *);
void ov96_021E952C(void *);
void ov96_021E9570(void *, int);
void ov96_021E95F8(void *, void *, int, u16, int, int, int);
void ov96_021E93B4(void *, int);
void ov96_0221A56C(void *, int);
void sub_0203A914(void);
void Main_SetVBlankIntrCB(void *, void *);
void Main_SetHBlankIntrCB(void *, void *);
void FreeBgTilemapBuffer(void *, int);
void RemoveWindow(void *);
void Heap_Free(void *);
void ov96_021EB21C(void *);
void ov96_021EA894(void *);
void ov96_021E9C0C(void *);
void OamManager_Free(void);
void ObjCharTransfer_Destroy(void);
void ObjPlttTransfer_Destroy(void);
void ov96_02208B2C(void *);
void ov96_02207D64(void *);
void FontID_Release(int);
void GfGfx_SwapDisplay(void);
void Heap_Destroy(int);
void GfGfx_SetBanks(const GfxBanks40 *);
void ov96_021EB2BC(void *, int, int, int, int);
void ov96_021EB2F4(void *, int, int, int, int, int);
void ov96_021EB334(void *, int, int, int);
void ov96_021EB36C(void *, int, int, int);
void BeginNormalPaletteFade(int, int, int, int, int, int, void *);
BOOL IsPaletteFadeFinished(void);
void *ov96_021E8A20(void *);
void ScheduleSetBgPosText(void *, int, int, int);
void ov96_02206380(void *, int, void *, void *);
void ov96_02206A24(void *, int, int);
void ov96_02206AC0(void *, int, int);
void ov96_02206B80(void *, void *, int, int);
void ov96_02207BE4(void *);
void ov96_02208740(void *, u16);
void ov96_021E6454(void *, u16);
void GF_AssertFail(void);
void ov96_021EB0A4(void *, int, int, int *, int *);
BOOL ov96_021EB0CC(void *, int, int, int, int);

int ov96_02204DF8(void *);
int ov96_02204E58(void *);
void ov96_02204F20(void);
void ov96_022050B4(void *);
int ov96_0220549C(void *, u8 *);
int ov96_02205520(void *, u8 *);
void ov96_02205D30(void *);
BOOL ov96_02205DD4(u8 *, int, int, int);
void ov96_022055AC(void *);
BOOL ov96_02205C94(void *);

#endif
