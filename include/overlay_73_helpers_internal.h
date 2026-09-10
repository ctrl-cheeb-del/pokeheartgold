#ifndef OVERLAY_73_PRIVATE_H
#define OVERLAY_73_PRIVATE_H
#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
extern int ov73_021E746C(void *);
extern int sub_0203A880(void *);
extern void *Save_GetPlayerMixingRankingEntry(void *, u32);
extern u32 ov00_021EC9D4(void *);
extern void *Save_FriendGroup_Get(void *);
extern void *Save_FashionData_Get(void *);
extern void *sub_0202B994(void *);
extern void ClearFrameAndWindow2(void *, u32);
extern void ov00_021ECD04(void *);
extern void Heap_Free(void *);
extern void ov73_021E67A8(void *);
extern int YesNoPrompt_HandleInput(void *);
extern void YesNoPrompt_Destroy(void *);
extern void Save_PrepareForAsyncWrite(void *, u32);
extern void ov73_021E79F4(void *, void *, void *, void *);
extern void *sub_02034818(u32);
extern void *OverlayManager_GetArgs(void *);
extern void ov72_02237CB0(void *);
extern void ov00_021EC8D8(void *);
extern void sub_0200F450(void *);
extern void sub_0202BF80(u8, void *, void *, void *);
extern void ov73_021E756C(void *, u32, u32);
extern void sub_02037AC0(u32);
extern void ov73_021E8128(void);
extern void ov73_021E8168(void);
extern void ov73_021E8198(void *);
extern void ov73_021E82D4(void *);
extern void ov73_021E8100(void *);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void Sprite_SetDrawFlag(void *, u32);
extern void *Heap_AllocAtEnd(u32, u32);
extern void sub_02069528(void *, u32, void *);
extern void *WaitingIcon_New(void *, u32);
extern u32 Save_WriteFileAsync(void *);
extern u32 TextPrinterCheckActive(u8);
extern void FreeBgTilemapBuffer(void *, u32);
extern void ov73_021E6508(void *);
extern u32 sub_0203769C(void);
extern void sub_0200E5D4(void *, u32);
extern u8 gSystem[];
extern void ov73_021E9FF8(void *, void *, u32, u32, u32);
extern void ov73_021E9F34(void *, void *, u32, u32, u32);
extern void ov72_02237BD0(void *, void *, void *);
extern void sub_0203946C(void);
extern void BufferIntegerAsString(void *, u32, u32, u32, u32, u32);
extern void ov73_021EA3D0(void *, void *);
extern void ov72_02237B80(void *);
extern void *Save_Rankings_Get(void *);
extern void Save_UpdateRankingsFromMixing(void *, void *, u8, void *, void *);
extern void *sub_020270C4(void *);
extern void ov73_021E7E24(void *, void *, void *, void *, void *);
extern void sub_0203189C(void *, void *);
extern void ov72_02237CF4(void *, void *);
extern void ReadMsgDataIntoString(void *, u32, void *);
extern void ov73_021E63BC(void *, void *, u32);
extern void Sprite_SetAnimCtrlSeq(void *, u32);
extern void GameStats_AddScore(void *, u32);
extern void sub_02039EAC(void *);
extern void ov00_021EC3F0(void *, u32, u32, u32);
extern void ov00_021EC454(u32);
extern void ov00_021EC4A4(void);
extern u32 PlayerProfile_GetVersion(void *);
extern void *ov73_021E8390(void *, u32, u32);
extern void DrawFrameAndWindow1(void *, u32, u32, u32);
extern void ov73_021EA0F0(void *, void *, u32, u32);
extern void CopyWindowToVram(void *);
extern u32 System_GetTouchHeld(void);
extern void String_Delete(void *);
extern void RemoveWindow(void *);
extern void GF_RunVramTransferTasks(void);
extern void OamManager_ApplyAndResetBuffers(void);
extern void DoScheduledBgGpuUpdates(void *);
extern NNSFndHeapHandle _021EA940[];
#endif
