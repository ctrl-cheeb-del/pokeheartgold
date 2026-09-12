#ifndef OV96_R38_RESIDUAL36_PRIVATE_H
#define OV96_R38_RESIDUAL36_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96R38Work {
    u8 padding[0x18];
    void *spriteSystem;
    void *spriteManager;
    void *sprites[26];
} Ov96R38Work;

typedef struct Ov96R38Source {
    u32 padding[5];
    u32 values[4][4];
} Ov96R38Source;

typedef struct Ov96R38Result {
    u32 values[4][7];
} Ov96R38Result;

typedef struct Ov96R38Counts {
    int values[6];
} Ov96R38Counts;

typedef struct Ov96R38Oam {
    int values[8];
} Ov96R38Oam;

typedef struct Ov96R38Transfer {
    int values[5];
} Ov96R38Transfer;

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

extern const Ov96R38Counts ov96_0221AF88;
extern const Ov96R38Oam ov96_0221B010;
extern const Ov96R38Transfer ov96_0221AF74;

void *SpriteSystem_Alloc(u32);
void *SpriteManager_New(void *);
void SpriteSystem_Init(void *, const void *, const void *, int);
void SpriteSystem_InitSprites(void *, void *, int);
void SpriteSystem_InitManagerWithCapacities(void *, void *, const void *);
void *SpriteSystem_GetRenderer(void *);
void G2dRenderer_SetSubSurfaceCoords(void *, int, int);
void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const Ov96R38SpriteTemplate *, int);
void ManagedSprite_SetAnimateFlag(void *, int);

void Sprite_DeleteAndFreeResources(void *);
void SpriteSystem_FreeResourcesAndManager(void *, void *);
void SpriteSystem_Free(void *);
void SpriteSystem_LoadCharResObj(void *, void *, int, int, int, int, int);
void SpriteSystem_LoadCellResObj(void *, void *, int, int, int, int);
void SpriteSystem_LoadAnimResObj(void *, void *, int, int, int, int);
void *Heap_Alloc(u32, u32);
void MI_CpuFill8(void *, u8, u32);
void *PokeathlonCourse_GetHeapAllocPtr4(void *);
void *ov96_021EAA04(void *, u8);
void ov96_021EAB38(void *, int);
void ov96_021EC790(void *, u32);
int PokeathlonCourse_GetParticipantCount(void *);
u32 *PokeathlonCourse_GetParticipantData(void *, int);
int ov96_021EEBC8(int);
void ov96_021EEA88(void *, int, u8, u32);
void ov96_021EEB74(void *, void *, u8, int);
int ov96_021E8424(u8);
int ov96_021EEDCC(int);
void GF_AssertFail(void);
void ov96_021EC51C(void *);
void ov96_021EC490(void *);
void ov96_021EC550(void *);
void ov96_021ECA18(void *);
void ov96_021ECA70(void *, u32);
Ov96R38Result *ov96_021ECBB8(u32, Ov96R38Source *);
void ov96_021ECAC4(void *);
void ov96_021ECB38(void **, void *, int, int, u32);

#endif
