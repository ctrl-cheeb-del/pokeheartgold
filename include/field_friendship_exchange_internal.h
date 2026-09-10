#ifndef POKEHEARTGOLD_FIELD_FRIENDSHIP_EXCHANGE_OV01_021F6CFC_H
#define POKEHEARTGOLD_FIELD_FRIENDSHIP_EXCHANGE_OV01_021F6CFC_H

// global.h -> <nitro/code16.h> -> "#pragma thumb on". Thumb comes from the
// SOURCE in this project, not from a -thumb flag (there is no -thumb anywhere
// in the real build). global.h also supplies u8/u16/u32/BOOL/TRUE/FALSE/NULL.
#include "global.h"

#include "field_system.h"  // FieldSystem: bgConfig +0x08, saveData +0x0c, taskman +0x10
#include "gf_gfx_planes.h" // GF_BG_LYR_MAIN_3
#include "heap.h"          // enum HeapID
#include "render_window.h" // LoadUserFrameGfx1 / LoadUserFrameGfx2 (u8 palette/frame matter)
#include "unk_0202C034.h"  // UnkStruct_021D2230, sub_0202C6F4, sub_0202C254

// ---------------------------------------------------------------------------
// The task context. 0x9c bytes (MI_CpuFill8(ctx, 0, 0x9c) in ov01_021F722C and
// Heap_AllocAtEnd(HEAP_ID_FIELD2, 0x9c) in ov01_021F729C both pin the size).
//
// include/field_overlay_app_dispatch_internal.h already carries a PARTIAL
// FieldTaskCtx for the sibling module (fieldSystem +0x30, unk90[2], state u16
// +0x98) and every offset it names agrees with this one. It is a shared header
// so it is not edited here; see report.md for the merge proposal.
// ---------------------------------------------------------------------------
typedef struct FieldFriendCtx {
    u8 pad00[0x08];
    String *msg;              // +0x08 ReadMsgDataIntoString dest
    String *expanded;         // +0x0c StringExpandPlaceholders dest
    u8 window[0x20];          // +0x10 Window
    FieldSystem *fieldSystem; // +0x30
    SaveData *saveData;       // +0x34
    MessageFormat *msgFmt;    // +0x38
    MsgData *msgData;         // +0x3c
    u32 printerId;            // +0x40
    u32 state;                // +0x44
    u32 unk48[16];            // +0x48
    u32 unk88;                // +0x88
    u32 unk8c;                // +0x8c
    u32 unk90;                // +0x90
    s32 unk94;                // +0x94
    u16 unk98;                // +0x98
    u16 unk9a;                // +0x9a
} FieldFriendCtx;

// ---------------------------------------------------------------------------
// Callees with no tracked header, or whose tracked prototype disagrees with the
// call site. Both disagreements are flagged as proposals in report.md:
//   * unk_02037C94.h says `void sub_0203A1C4(...)` but ov01_021F6CFC tests r0.
//   * field_application_tasks_internal.h says `void DialogBox_PrintMessage(...)`
//     but ov01_021F71C4 stores r0 into ctx->printerId.
// Params are declared with the widths the call sites require (u8 printer id,
// u8 frame/palette) so codegen is not perturbed.
// ---------------------------------------------------------------------------
extern void *sub_0202C23C(void *, int);
extern BOOL sub_0203A1C4(SaveData *saveData, void *a1, int heapId);
extern void sub_0203A280(SaveData *saveData, u32 a1, int a2, int a3, int a4);
extern BOOL sub_0202C2DC(UnkStruct_021D2230 *data, int index);
extern void sub_0202C338(UnkStruct_021D2230 *data, int index);
extern void sub_020311AC(void *frontier, int row);
extern void *Save_Frontier_GetStatic(SaveData *saveData);
extern int sub_02037454(void);
extern int sub_02034818(int);
extern void *Save_Bag_Get(SaveData *saveData);
extern BOOL Bag_HasItem(void *bag, u16 itemId, u16 quantity, int heapId);
extern u8 TextPrinterCheckActive(u8 printerId);
extern void DialogBox_AddWindowToLayer3(void *bgConfig, void *window, int bgId);
extern void DialogBox_LoadFrame(void *window, void *options);
extern u32 DialogBox_PrintMessage(void *window, void *message, void *options, int canSpeedUp);
extern void *TaskManager_GetEnvironment(TaskManager *taskman);
extern FieldSystem *TaskManager_GetFieldSystem(TaskManager *taskman);
extern void TaskManager_Call(TaskManager *taskman, BOOL (*func)(TaskManager *), void *env);
extern void Heap_Free(void *);
extern void sub_0203E30C(void);

// Same-overlay neighbours (defined in src/field_overlay_app_dispatch.c, which
// types these as its own FieldTaskCtx *; pointer-compatible at the ABI).
extern BOOL ov01_021F6CA0(FieldFriendCtx *ctx);
extern BOOL ov01_021F6C28(FieldFriendCtx *ctx);
extern void ov01_021F6A9C(FieldSystem *fieldSystem, int a1, void *a2);

#endif // POKEHEARTGOLD_FIELD_FRIENDSHIP_EXCHANGE_OV01_021F6CFC_H
