#ifndef OV102_PRIVATE_H
#define OV102_PRIVATE_H

#include "global.h"

/* No tracked struct layout exists for the OVY_102 EasyChat application work
 * objects, so accessors are expressed against the raw object base with explicit
 * byte offsets, exactly as the original walks them. */

/* --- external callees (prototypes only; mwcc emits the ordinary bl/relocation) --- */
void Heap_Free(void *ptr);
void String_Delete(void *str);
void ObjCharTransfer_Destroy(void);
void *SysTask_CreateOnVBlankQueue(void *func, void *work, u32 prio);
void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
void Sprite_SetDrawFlag(void *sprite, int flag);
void *TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);
u8 sub_02090D74(void *args);
u32 sub_02090D78(void *args);
u32 MailMsg_GetMsgBank(void *msg);
void *MailMsg_GetRawString(void *msg);

/* --- in-module callees written elsewhere in the overlay --- */
u8 ov102_021E7A0C(u8 *p);
u32 ov102_021E87A8(u8 *p);
u16 ov102_021E87AC(u8 *p);
u16 ov102_021E87B0(u8 *p);
int ov102_021E878C(u8 *p);
u8 ov102_021E8F64(u8 *p);
void ov102_021E94A4(void *p);
void ov102_021EB088(u8 *p, int a);
u32 ov102_021EC2EC(u8 *p);
void ov102_021EC450(u8 *p);
u32 ov102_021EC3AC(u8 *p);
u32 ov102_021EAFEC(u8 *p);
u32 ov102_021EADF0(u8 *p);
void ov102_021EAB10(u8 *p, u8 *dst, u32 idx);
void ov102_021EB130(u8 *p);
void ov102_021EB29C(u8 *p);
void DestroyMsgData(void *msgData);
void ov102_021EB3B4(u8 *p, int a);
void ov102_021EB2EC(u8 *p, int a, int b);
void Sprite_Delete(void *sprite);

/* --- rodata owned by this module --- */
extern const u8 ov102_021EC610[];
extern const u8 ov102_021EC620[];

/* --- batch 2 callees --- */
void GF_AssertFail(void);
void ToggleBgLayer(u32 layer, u32 on);
void BgSetPosTextAndCommit(void *bgConfig, u32 layer, u32 op, u32 val);
u16 MailMsg_GetFieldI(void *msg, u32 idx);
u32 sub_02090DC0(void *a, void *b, void *c);
void ov102_021EB98C(u8 *p, int a);
void ov102_021EBEF4(u8 *p, int a);
void ov102_021EB530(u8 *p, u16 a);
void ov102_021EB9C0(u8 *p, u16 a);
void ov102_021EBF38(u8 *p, int a);
void ov102_021EAE40(u8 *p, int a);
void ov102_021EB170(u8 *p, u8 a);
int ov102_021E9028(u8 *p);
void ov102_021EC410(u8 *p, int a, int b, int c, int d);
void ov102_021EC37C(u8 *p, int a, int b, int c, int d, int e);
void ov102_021EC294(u8 *p, int a, int b);
void ov102_021EC290(void);

/* function-pointer dispatch tables in this module's .rodata */
extern void (*const ov102_021EC5E8[])(u8 *p);
extern void (*const _021EC5D8[])(u8 *p);

/* --- batch 3 callees --- */
extern const u8 ov102_021EC820[];
void CopyU16ArrayToStringN(void *dst, const void *src, u32 n);
BOOL ov102_021E7A58(u8 *p);
u32 ov102_021E7C84(u8 *p, u8 *q);
u32 ov102_021E8178(u8 *p, u8 *q);
u32 ov102_021E8294(u8 *p, u8 *q);
u32 ov102_021E848C(u8 *p, u8 *q);
u32 ov102_021E8820(u8 *p, u8 *q);
u32 ov102_021E8A34(u8 *p, u8 *q);
void sub_02091C38(void *a, u16 b);
void sub_02091C74(void *a, u16 b);
void sub_02091C40(void *a, u16 b, void *c, void *d);
void sub_02091C84(void *a, u16 b, void *c, void *d);
void *SysTask_GetData(void *task);
void ov102_021EC298(u8 *p, void *a, int b, int c, int d, int e);
void FillWindowPixelRect(void *w, u32 c, u16 x, u16 y, u32 dx, u32 dy);
void Sprite_SetPositionXY(void *sprite, s16 x, s16 y);
void *String_cstr(void *str);
void ov102_021EAA3C(u8 *p);
void ov102_021EAFF0(u8 *p, u16 a);

/* --- batch 4 callees --- */
u32 MailMsg_GetMsgNo(void *msg);
void MailMsg_SetMsgBankAndNum(void *msg, u16 bank, u8 num);
void OverlayManager_FreeData(void *ovy);
void *OverlayManager_GetData(void *ovy);
void sub_02090E5C(void *a, u32 b);
void TouchHitboxController_Destroy(void *p);
void ov102_021E9144(void *p);
void sub_020918C0(void *p);
void Heap_Destroy(u32 heapId);
void *Heap_Alloc(u32 heapId, u32 size);
void *SysTask_CreateOnMainQueue(void *func, void *work, u32 prio);
void ov102_021EB5B8(void *task, void *work);
void DoScheduledBgGpuUpdates(void *bgConfig);
void SpriteList_RenderAndAnimateSprites(void *list);
void OamManager_ApplyAndResetBuffers(void);

/* --- batch 5 callees --- */
void ov102_021E940C(void *p, u32 mode);
BOOL ov102_021E9464(u8 *p);
void ov102_021EAFAC(u8 *p);
void ov102_021EAF5C(u8 *p, int flag);
void *NewMsgDataFromNarc(u32 type, u32 narc, u32 fileId, u32 heapId);

#endif /* OV102_PRIVATE_H */
