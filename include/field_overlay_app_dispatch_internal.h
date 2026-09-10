#ifndef PRIVATE_OV01_021F6830_H
#define PRIVATE_OV01_021F6830_H

// global.h -> <nitro/code16.h> -> "#pragma thumb on". This is how this project
// selects Thumb: in the source, not via a compiler flag (there is no -thumb
// anywhere in the real build). It also supplies u8/u16/u32/BOOL/TRUE/FALSE/NULL
// and, via <nitro.h>, FS_EXTERN_OVERLAY / FS_OVERLAY_ID.
#include "global.h"

#include "poke_overlay.h"        // HandleLoadOverlay, UnloadOverlayByID
#include "screen_fade.h"         // BeginNormalPaletteFade, IsPaletteFadeFinished
#include "sys_task.h"            // SysTask, SysTaskFunc, SysTask_GetData
#include "systask_environment.h" // Create/DestroySysTaskAndEnvironment

FS_EXTERN_OVERLAY(OVY_27);
FS_EXTERN_OVERLAY(touch_save_app);
FS_EXTERN_OVERLAY(OVY_31);
FS_EXTERN_OVERLAY(OVY_28);
FS_EXTERN_OVERLAY(OVY_29);
FS_EXTERN_OVERLAY(OVY_32);
FS_EXTERN_OVERLAY(OVY_33);
FS_EXTERN_OVERLAY(OVY_34);

// ---------------------------------------------------------------------------
// Private types. None of these have a tracked definition that matches what the
// assembly requires, so per the brief they stay local rather than editing a
// shared header. `FieldSys` is deliberately NOT named `FieldSystem`: it is a
// padded stand-in for the real tracked type, and the offsets it pins down
// (+0xD0..+0xDC) are offered as a proposal in report.md.
// ---------------------------------------------------------------------------

typedef struct FieldSysUnk04 {
    u8 pad00[0x14];
    void *unk14;
} FieldSysUnk04;

typedef struct FieldSys {
    u8 pad00[0x04];
    FieldSysUnk04 *unk04;
    void *unk08;
    u8 pad0C[0x1C - 0x0C];
    u32 unk1C;
    u8 pad20[0xD0 - 0x20];
    void *unkD0;
    void *unkD4;
    SysTask *unkD8;
    void *unkDC;
} FieldSys;

typedef struct AppTaskData {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    void *unk04;
    FieldSys *unk08;
    void *unk0C;
} AppTaskData;

typedef struct AppSubData {
    u32 unk00;
    void *unk04;
    u8 pad08[0x0C - 0x08];
    void *unk0C;
} AppSubData;

typedef struct FieldTaskCtx {
    u8 pad00[0x30];
    FieldSys *fieldSystem;
    u8 pad34[0x90 - 0x34];
    u32 unk90[2];
    u16 state;
} FieldTaskCtx;

typedef void *(*AppInitFunc)(void *, void *, FieldSys *, void *);
typedef void (*AppMainFunc)(void *, void *);
typedef BOOL (*AppDoneFunc)(void *);

typedef struct AppEntry {
    AppInitFunc init;
    AppMainFunc main;
    AppDoneFunc done;
    u32 ovlId;
} AppEntry;

// ---------------------------------------------------------------------------
// Cross-overlay externs with no tracked header.
// ---------------------------------------------------------------------------

extern void ov35_02259D80(void *, int, int);
extern void ov27_0225C41C(void *, void *, void *);
extern void ov27_0225A2CC(void *);
extern void ov27_0225A2EC(void *, int);
extern void *ov34_0225D7A8(FieldSys *);
extern void ov34_0225D87C(void *);

extern void *ov27_02259F80(void *, void *, FieldSys *, void *);
extern void ov27_0225A19C(void *, void *);
extern BOOL ov27_0225A2C8(void *);
extern void *ov30_0225D520(void *, void *, FieldSys *, void *);
extern void ov30_0225D64C(void *, void *);
extern BOOL ov30_0225D6FC(void *);
extern void *ov31_0225D520(void *, void *, FieldSys *, void *);
extern void ov31_0225D710(void *, void *);
extern BOOL ov31_0225D758(void *);
extern void *ov27_0225C250(void *, void *, FieldSys *, void *);
extern void ov27_0225C398(void *, void *);
extern BOOL ov27_0225C418(void *);
extern void *ov28_0225D520(void *, void *, FieldSys *, void *);
extern void ov28_0225D5EC(void *, void *);
extern BOOL ov28_0225D624(void *);
extern void *ov29_0225D520(void *, void *, FieldSys *, void *);
extern void ov29_0225D5EC(void *, void *);
extern BOOL ov29_0225D61C(void *);
extern void *ov32_0225D520(void *, void *, FieldSys *, void *);
extern void ov32_0225D5CC(void *, void *);
extern BOOL ov32_0225D608(void *);
extern void *ov33_0225D520(void *, void *, FieldSys *, void *);
extern void ov33_0225D5A8(void *, void *);
extern BOOL ov33_0225D5CC(void *);

#endif
