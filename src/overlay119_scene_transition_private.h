#include "global.h"

typedef struct Camera Camera;
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
    Interp interp0;
    u8 pad14[4];
    Interp interp18;
    u8 pad2c[4];
    Interp interp30;
    u8 pad44[4];
    Interp interp48;
    u8 spriteResources[0x13c];
    void *resource198;
    u8 pad19c[0x30];
    Sprite *sprite1cc;
    Camera *camera1d0;
    Interp cameraInterp;
} Ov119Work;

typedef struct {
    u32 state;
    u32 done;
    u32 unused08;
    Ov119Work *work;
    void *fieldSystem;
    u32 *completionFlag;
    u8 pad18[8];
    void *spriteManager;
} Ov119Task;

void *Heap_Alloc(u32 heapId, u32 size);
void *memset(void *dest, int value, u32 size);
void GfGfx_EngineATogglePlanes(u32 plane, BOOL enable);
void ov01_021EFCF8(s32, s32, s32, u32 *, s32);
void ov01_021EFEC8(Interp *, s32, s32, s32, s32);
BOOL ov01_021EFF28(Interp *);
void ov01_021F05C4(void *, s32, s32);
void ov01_021F05F4(void *);
void ov01_021F0614(void *, void *, void *, u32, s32, u32, u32, u32, u32);
void ov01_021F06EC(void *, void *);
Sprite *ov01_021F0718(void *, void *, s32, s32, s32, s32);
void ov01_021F074C(Triple *, s32, s32, s32);
void ov01_021EFE34(Interp *, s32, s32, s32);
BOOL ov01_021EFE44(Interp *);
void ov01_021EFCDC(Ov119Task *, void *);
void Sprite_SetDrawFlag(Sprite *, BOOL);
void Sprite_SetScaleAndAffineType(Sprite *, Triple *, u8);
void Sprite_SetMatrix(Sprite *, Triple *);
void Sprite_SetAffineScale(Sprite *, Triple *);
void Sprite_SetAffineZRotation(Sprite *, u32);
void Sprite_Delete(Sprite *);
void SpriteList_RenderAndAnimateSprites(SpriteList *);
void HBlankSystem_Stop(void *);
void HBlankSystem_Start(void *);
s32 Camera_GetDistance(Camera *);
void Camera_SetDistance(s32, Camera *);
void BeginNormalPaletteFade(s32, s32, s32, u16, s32, s32, s32);
BOOL IsPaletteFadeFinished(void);
void sub_0200FBF4(s32, u16);
void ov119_0225FF9C(void *, Ov119Task *);
