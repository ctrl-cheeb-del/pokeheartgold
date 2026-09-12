#ifndef OVERLAY70_GRAPHICS_LIFECYCLE_PRIVATE_H
#define OVERLAY70_GRAPHICS_LIFECYCLE_PRIVATE_H

#include "global.h"

typedef struct Ov70R8 {
    void *root;
    void *bgConfig;
    u8 pad08[0x2c - 8];
    s32 state;
    u8 pad30[4];
    u16 initialized;
    u8 pad36[0xf10 - 0x36];
    void *spriteF10;
    u8 padF14[0x11fc - 0xf14];
    s32 mode11FC;
} Ov70R8;

typedef struct Ov70GraphicsModes8 {
    u32 words[4];
} Ov70GraphicsModes8;

typedef struct Ov70BgTemplate8 {
    u32 words[7];
} Ov70BgTemplate8;

extern int (*const ov70_02246464[])(Ov70R8 *);
extern const Ov70GraphicsModes8 ov70_0224525C;
extern const Ov70BgTemplate8 ov70_022452F4;
extern const Ov70BgTemplate8 ov70_022452D8;
extern const Ov70BgTemplate8 ov70_02245310;
extern const Ov70BgTemplate8 ov70_022452A0;
extern const Ov70BgTemplate8 ov70_02245284;
extern const Ov70BgTemplate8 ov70_022452BC;
extern const Ov70BgTemplate8 ov70_0224532C;

void ov70_02239614(Ov70R8 *);
void ov70_02239134(void *);
void ov70_02239330(Ov70R8 *);
void ov70_022394B8(Ov70R8 *);
void ov70_02239414(Ov70R8 *);
void ov70_02245124(Ov70R8 *);
void ov70_02239B00(Ov70R8 *);
void Sound_SetSceneAndPlayBGM(int, int, int);
void ov70_02239304(Ov70R8 *);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
int PlayerProfile_GetTrainerGender(void *);
void ov70_02240EF4(Ov70R8 *, int);
int GXx_GetMasterBrightness_(volatile u16 *);
void ov70_02241358(Ov70R8 *);
void ov70_02238E44(Ov70R8 *);
void sub_0203A930(void);
void sub_0203A914(void);
void ov70_022394A8(Ov70R8 *);
void ov70_0223963C(Ov70R8 *);
void ov70_022395C4(Ov70R8 *);
void ov70_022392E0(void *);
void Sprite_SetDrawFlag(void *, int);
void ov70_02238E58(Ov70R8 *);
void SetBothScreensModesAndDisable(const void *);
void InitBgFromTemplate(void *, int, const void *, int);
void BgClearTilemapBufferAndCommit(void *, int);
void BG_ClearCharDataRange(int, int, int, int);
void GfGfx_EngineATogglePlanes(int, int);
void GfGfx_EngineBTogglePlanes(int, int);

int ov70_02238FF4(Ov70R8 *);
int ov70_022390DC(Ov70R8 *);
int ov70_022390FC(Ov70R8 *);
void ov70_02239134(void *);
void ov70_022391F0(void *, int, int);

#endif
