#ifndef OVERLAY96_TO46_R36_SUFFIX_PRIVATE_H
#define OVERLAY96_TO46_R36_SUFFIX_PRIVATE_H
#include "global.h"

#include "filesystem_files_def.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96R38Source {
    u32 padding[5];
    u32 values[4][4];
} Ov96R38Source;
typedef struct Ov96EcaWork {
    u8 pad00[0x14];
    void *unk14;
} Ov96EcaWork;

typedef struct Ov96R38Result {
    u32 values[4][7];
} Ov96R38Result;

typedef struct Ov96R38SpriteTemplate {
    s16 x;
    s16 y;
    s16 z;
    u16 animation;
    int drawPriority;
    int palette;
    int vram;
    int resources[6];
    int bgPriority;
    int vramTransfer;
} Ov96R38SpriteTemplate;
void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, u32);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, u32);
void GfGfxLoader_GXLoadPal(int, int, int, int, int, u32);
void Sprite_DeleteAndFreeResources(void *);
void SpriteSystem_FreeResourcesAndManager(void *, void *);
void SpriteSystem_Free(void *);
void SpriteSystem_LoadCharResObj(void *, void *, NarcId, int, BOOL, int, int);
void SpriteSystem_LoadCellResObj(void *, void *, int, int, int, int);
void SpriteSystem_LoadAnimResObj(void *, void *, int, int, int, int);
void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const Ov96R38SpriteTemplate *, int);
void ManagedSprite_SetAnimateFlag(void *, int);
void ManagedSprite_SetPaletteOverride(void *, int);
void ManagedSprite_SetDrawFlag(void *, int);
void *Heap_Alloc(u32, u32);
void ov96_021EC3D8(void *, u32);
void ov96_021EC458(void *, u32);
void ov96_021EC51C(void *);
void ov96_021ECA18(void *);
Ov96R38Result *ov96_021ECBB8(u32, Ov96R38Source *);
Ov96EcaWork *PokeathlonCourse_GetHeapAllocPtr4(void *);
void *ov96_021EAA04(void *, u8);
void ov96_021EAB38(void *, int);
void ov96_021EC790(void *, u32);
void ov96_021ECA70(void *, u32);
void ov96_021EC68C(void *);
void ov96_021ECAC4(void *);
int PokeathlonCourse_GetParticipantCount(void *);
u32 *PokeathlonCourse_GetParticipantData(void *, int);
int ov96_021EEBC8(int);
void ov96_021EEA88(void *, int, u8, u32);
void ov96_021EEB74(void *, void *, u8, int);
int ov96_021E8424(u8);
int ov96_021EEDCC(int);
void GF_AssertFail(void);
void ov96_021ECB38(void **, void *, int, int, u32);
#endif
