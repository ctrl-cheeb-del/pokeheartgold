#ifndef OV48_PRIVATE_H
#define OV48_PRIVATE_H

#include "global.h"

#include "camera.h"
#include "gf_3d_vramman.h"
#include "msgdata.h"
#include "render_window.h"
#include "sprite.h"
#include "yes_no_prompt.h"

/* Raw byte-offset accessors: this module has no tracked struct layout, and the
   brief prefers raw offsets over an invented struct (a wrong struct size looks
   exactly like a register-allocation defect). */
#define U8AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S16AT(p, n) (*(s16 *)((u8 *)(p) + (n)))
#define U32AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define S32AT(p, n) (*(s32 *)((u8 *)(p) + (n)))
#define PTRAT(p, n) (*(void **)((u8 *)(p) + (n)))
#define ADD(p, n)   ((void *)((u8 *)(p) + (n)))

/* 12-byte aggregate copied wholesale by ov48_022598AC / CC / DC. */
/* The module's 12-byte aggregate is the tracked VecFx32 (proved at the
   Sprite_SetMatrix(Sprite *, VecFx32 *) call site in ov48_0225B010). */

/* No tracked prototype exists for this one. */
extern void sub_02018068(void *);
extern void OamManager_ApplyAndResetBuffers(void);
extern void GF_RunVramTransferTasks(void);
extern void SysTask_Destroy(void *);
extern void DestroyMsgData(MsgData *);
extern void String_Delete(String *);

/* Intra-module callees this candidate references but does not define. */
void ov48_02258BF4(void *, void *);
void ov48_0225A158(void *, void *, void *);
void ov48_0225A95C(void *, void *);
void ov48_0225A43C(void *, void *, u32);
void ov48_0225AEDC(void *);
void ov48_0225AFB4(void *, void *);

/* --- tier-2 callees (tracked headers win where they declare these) --- */
extern void Thunk_G3X_Reset(void);
extern void RequestSwap3DBuffers(u32, u32);
extern void GF_DestroyVramTransferManager(void);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void OamManager_Free(void);
extern void sub_020182A8(void *, u32, u32, u32);
extern void sub_020182C4(void *, u32, u32, u32);
extern void sub_02018288(void *, void *);
extern void PlaySE(u16);
extern u32 TextPrinterCheckActive(u8);
extern void RemoveTextPrinter(u8);
extern void Heap_Free(void *);
extern void GF_CreateNewVramTransferTask(u32, u32, void *, u32);
extern u32 ov45_0222D724(void *, u8);

void ov48_022599A0(void *, void *);
void ov48_02259874(void *);
void ov48_022594D0(void *);
void ov48_02259650(void *);
void ov48_02259724(void *);
void ov48_02259788(void *);
void ov48_0225B010(void *, u32);
void ov48_0225AEC4(void *, fx32 *);
void ov48_0225AEA8(void *, void *);
u32 ov48_02259BBC(void *);
u16 ov48_02259B68(void *, u32);
void ov48_02259B3C(void *, void *, u32);
s32 ov48_02259B10(void *, u16, u16);

extern void sub_02018030(void *, void *, u32, u32);
extern void sub_020181B0(void *, void *);
extern s32 GF_DegreeToSinCosIdxNoWrap(s32);
extern fx32 FX_Sqrt(fx32);
u32 ov48_022591D8(void *);
u32 ov48_0225932C(void *, u32, void *);
u32 ov48_0225A30C(void *, VecFx32 *, u32);
u32 ov48_0225AE60(void *, void *);
u16 ov48_02259B84(void *, u32);
u16 ov48_02259BA0(void *, u32);
void ov48_0225A2EC(void *);

#endif
