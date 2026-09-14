#include "global.h"

typedef struct Sprite Sprite;
typedef struct SpriteList SpriteList;

typedef struct {
    s32 value;
    s32 start;
    s32 delta;
    s32 frame;
    s32 duration;
} Interp;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Triple;

typedef struct {
    Interp fade;
    Interp scale;
    u8 pad28[4];
    u8 spriteResources[0x13c];
    void *resource168;
    u8 pad16c[0x30];
    Sprite *sprite19c;
} Ov114WorkA;

typedef struct {
    u8 spriteResources[0x13c];
    void *resource13c;
    u8 pad140[0x30];
    Sprite *sprites170[4];
    Interp horiz;
    u8 pad194[4];
    Interp vert;
    u8 pad1ac[4];
} Ov114WorkB;

typedef struct {
    u32 state;
    u32 done;
    u32 unused08;
    void *work;
    void *fieldSystem;
    u32 *completionFlag;
    u8 pad18[8];
    void *spriteManager;
} Ov114Task;

void *Heap_Alloc(u32, u32);
void *memset(void *, int, u32);
void GfGfx_EngineATogglePlanes(u32, BOOL);
void ov01_021EFCF8(s32, s32, s32, u32 *, s32);
void ov01_021EFE34(Interp *, s32, s32, s32);
BOOL ov01_021EFE44(Interp *);
void ov01_021EFEC8(Interp *, s32, s32, s32, s32);
BOOL ov01_021EFF28(Interp *);
void ov01_021F05C4(void *, s32, s32);
void ov01_021F05F4(void *);
void ov01_021F0614(void *, void *, void *, u32, s32, u32, u32, u32, u32);
void ov01_021F06EC(void *, void *);
Sprite *ov01_021F0718(void *, void *, s32, s32, s32, s32);
void ov01_021F074C(Triple *, s32, s32, s32);
void ov01_021EFCDC(Ov114Task *, void *);
void Sprite_SetDrawFlag(Sprite *, BOOL);
void Sprite_SetAffineOverwriteMode(Sprite *, int);
void Sprite_SetOamMode(Sprite *, int);
void Sprite_SetAffineScale(Sprite *, Triple *);
void Sprite_SetMatrix(Sprite *, Triple *);
void Sprite_Delete(Sprite *);
void SpriteList_RenderAndAnimateSprites(SpriteList *);
void HBlankSystem_Stop(void *);
void HBlankSystem_Start(void *);
void BeginNormalPaletteFade(s32, s32, s32, u16, s32, s32, s32);
BOOL IsPaletteFadeFinished(void);
void sub_0200FBF4(s32, u16);
void ov114_0225F020(void *, Ov114Task *);
void ov114_0225F280(void *, Ov114Task *);
