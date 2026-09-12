#ifndef POKEHEARTGOLD_OVERLAY96_RESIDUAL77_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY96_RESIDUAL77_PRIVATE_H
#include "global.h"

#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct GfxBanks40 {
    u32 words[10];
} GfxBanks40;
extern const GfxBanks40 ov96_0221C6F0;
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
void ov96_021E966C(void *, void *, int, u16, int, int, int, int, int, int, int);
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
void ov96_02200EEC(void *);
void ov96_021FFFE8(void *);
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
void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
void ov96_02200068(void *);
int ov96_021FD4D0(void *);
BOOL ov96_021FDB64(void *);
void GF_AssertFail(void);
void ov96_021EB0A4(void *, int, int, int *, int *);
BOOL ov96_021EB0CC(void *, int, int, int, int);

int ov96_021FCE10(void *);
void ov96_021FCEE0(void);
void ov96_021FD060(u8 *);
void ov96_021FD0E4(void *);
int ov96_021FD3EC(void *, u8 *);
int ov96_021FD46C(void *, u8 *);
BOOL ov96_021FDE08(u8 *, int, int, int);
int ov96_021FCD84(void *);

#endif
