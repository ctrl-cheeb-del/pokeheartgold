#ifndef PRIVATE_OVERLAY_80_0223A00C_H
#define PRIVATE_OVERLAY_80_0223A00C_H
#include "global.h"
typedef struct MotionR21 {
    s32 value;
    s32 start;
    s32 delta;
    s32 step;
    s32 duration;
} MotionR21;
typedef struct Vec3R21 {
    s32 x, y, z;
} Vec3R21;
typedef struct SpriteDescriptorR21 {
    u32 words[13];
} SpriteDescriptorR21;
void SysTask_Destroy(void *);
void NARC_Delete(void *);
void Heap_FreeExplicit(int, void *);
void DestroySysTaskAndEnvironment(void *);
void *CreateSysTaskAndEnvironment(void (*)(void *, void *), u32, u32, int);
void *SysTask_GetData(void *);
void *NARC_New(int, int);
void *BgGetCharPtr(int);
void ScheduleSetBgPosText(void *, int, int, int);
void ov80_0223A938(void *, const u8 *);
void *SysTask_CreateOnVWaitQueue(void (*)(void *, void *), void *, int);
void FontOAM_Delete(void *);
void sub_02021B5C(void *);
int FontID_String_GetWidth(void *, int, int);
void Sprite_DeleteAndFreeResources(void *);
void PaletteData_LoadPalette(void *, const void *, int, int, int);
void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, int);
void MI_CpuFill8(void *, u8, u32);
int ov80_0223A174(void *, int, const u8 *);
extern const u8 ov80_0223DB98[];
extern const SpriteDescriptorR21 ov80_0223DB64;
void *SpriteSystem_NewSprite(void *, void *, const void *);
void Sprite_SetAffineOverwriteMode(void *, int);
void Sprite_SetAnimCtrlSeq(void *, int);
void ManagedSprite_SetPositionXYWithSubscreenOffset(void *, s16, s16, s32);
void ManagedSprite_SetDrawFlag(void *, int);
void ov80_0223A0C0(void *, void *);
void ov80_0223A748(void *);
void ov80_0223A75C(int, void *, int *, int *);
void ov80_0223A81C(void *);
void ov80_0223A8C4(MotionR21 *, s32, s32, s32);
int ov80_0223A8D4(MotionR21 *);
void ov80_0223A91C(Vec3R21 *, s32, s32, s32);
void ov80_0223AA4C(void *, void *);
void ov80_0223AAD0(void *, void *);
void ov80_0223AB34(void *, void *);
void ov80_0223A0EC(void *, void *);
void ov80_0223A144(void *, void *);
void ov80_0223AA80(void *, int);
int ov80_0223AB94(void *, void *, void *);
void ov80_0223A78C(void *, void *, s32, s32, int);
void ov80_0223A00C(int, void *, void *, void *, void *, void *, s16, s16);
#endif
