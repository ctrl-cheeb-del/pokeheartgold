#include "overlay106_cinematic_internal.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
typedef struct {
    u32 v[4];
} Modes;
typedef struct {
    u32 v[10];
} Banks;
typedef struct {
    u32 v[3];
} Vec3;
typedef struct {
    u32 v[11];
} Setup44;
extern const Modes ov106_021E6D7C;
extern const Banks ov106_021E6DB0;
extern const Banks ov106_021E6FE8;
extern int (*const sScriptCinematicSubs_HoOh[])(void *);
extern int (*const sScriptCinematicSubs_Lugia[])(void *);
extern int (*const sScriptCinematicSubs_Arceus[])(void *);
extern const Setup44 ov106_021E6DD8;
extern const u8 ov106_021E6EFC[];
extern const u8 ov106_021E6EC4[];
extern const u8 ov106_021E6EE4[];
extern const u8 ov106_021E6E9C[];
extern const u8 ov106_021E6E2C[];
extern const u8 ov106_021E6E04[];
extern const u8 ov106_021E6E74[];
extern const u8 ov106_021E6E50[];

void ov106_021E5900(void *data) {
    Main_SetVBlankIntrCB(0, 0);
    HBlankInterruptDisable();
    GfGfx_EngineASetPlanes(0);
    GfGfx_EngineBSetPlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000304 |= 0x8000;
    ov106_021E5D38();
    ov106_021E5D48();
    ov106_021E5D70(data);
}

void ov106_021E594C(void *p) {
    ov106_021E5DFC(p);
}

void ov106_021E5954(void *d, int a, int b, int next) {
    BeginNormalPaletteFade(0, 1, 1, 0, a, b, 0x99);
    U32(d, 0x410) = next;
}

void ov106_021E597C(void *d, int a, int b, int next) {
    BeginNormalPaletteFade(0, 0, 0, 0, a, b, 0x99);
    U32(d, 0x410) = next;
}

void ov106_021E59A4(void *d, int a, int b, int next) {
    BeginNormalPaletteFade(0, 1, 1, 0x7fff, a, b, 0x99);
    U32(d, 0x410) = next;
}

void ov106_021E59D0(void *d, int a, int b, int next) {
    BeginNormalPaletteFade(0, 0, 0, 0x7fff, a, b, 0x99);
    U32(d, 0x410) = next;
}

void ov106_021E59FC(void *data, void *cfg) {
    Vec3 v = *(Vec3 *)((u8 *)cfg + 0x14);
    *(Vec3 *)((u8 *)data + 0x400) = v;
    Camera_Init_FromTargetDistanceAndAngle((u8 *)data + 0x400, U32(cfg, 0), (u8 *)cfg + 4, U16(cfg, 0xe), U8(cfg, 0xc), 1, PTR(data, 0x18));
    Camera_SetPerspectiveClippingPlane(U32(cfg, 0x20), U32(cfg, 0x24), PTR(data, 0x18));
    Camera_SetStaticPtr(PTR(data, 0x18));
}
