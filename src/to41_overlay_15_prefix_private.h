#ifndef OV15_PREFIX_PRIVATE_H
#define OV15_PREFIX_PRIVATE_H

#include "global.h"

void *Save_Bag_Get(void *);
void *Save_PlayerData_GetProfile(void *);
void *Save_PlayerData_GetOptionsAddr(void *);
void *Save_Roamers_Get(void *);
u8 *RoamerSave_GetRepelAddr(void *);
void RoamerSave_SetFlute(void *, u8);
void ReadMsgDataIntoString(void *, u32, void *);
u32 TMHMGetMove(u32);
void *String_New(u32, u32);
void String_Delete(void *);
s32 TouchscreenHitbox_FindRectAtTouchNew(const void *);
void ov15_021FAC48(void *);
s32 ov15_021FA650(void *);
void MenuInputStateMgr_SetState(void *, u32);
void ClearWindowTilemapAndScheduleTransfer(void *);
void ov15_021FED3C(void *);
void sub_020880CC(u32, u32);
void ov15_021FDF20(void *);
void Camera_Delete(void *);
void GF3dRender_DeleteSimpleManager(void);

extern const void *ov15_02201314[];

void BagApp_GetSaveStructPtrs(void *);
void *BagApp_GetSaveRoamers(void *);
void BagApp_GetRepelStepCountAddr(void *, u8);
void BagApp_SetFlute(void *, u8);
void ov15_021F9D8C(void *, void *, u32);
void ov15_021F9D9C(void *, void *, u32);
void ov15_021FA008(void *);
void ov15_021FA028(void *);
void ov15_021FA070(void);
void ov15_021FA0D8(void *);
s32 ov15_021FAC2C(void *, u32);
s32 ov15_021FAC40(void);
s32 ov15_021FB820(void *);
s32 ov15_021FBC6C(void *);
s32 ov15_021FBC8C(void *);
s32 ov15_021FBD28(s32, s32, s32);
s32 ov15_021FC3E0(void *);
s32 ov15_021FD3AC(void *);
BOOL ov15_021FD3F0(u32, u32);
void ov15_021FD774(void *, u32);
void ov15_021FDAD0(void *);
void ov15_021FDC6C(void *);
void ov15_021FDD54(void *);
void ov15_021FE504(void *);
void ov15_021FE868(void *);
void ov15_021FE8A4(void *);

typedef struct Ov15Banks {
    u32 words[10];
} Ov15Banks;
extern const Ov15Banks ov15_02200618;
void GfGfx_SetBanks(const Ov15Banks *);
void DoScheduledBgGpuUpdates(void *);
void GF_RunVramTransferTasks(void);
void SpriteSystem_TransferOam(void);
BOOL TextPrinterCheckActive(u8);
void ov15_021FF004(void *);
void ScheduleWindowCopyToVram(void *);
void ov15_021FEEA4(void *);
void ov15_02200428(void *);
void ov15_021FFF24(void *);
void ov15_021FF834(void *);
void ov15_021FD788(void *, u32);
void RemoveWindow(void *);
void ov15_021FE3E0(void *);
void ov15_021FE1D0(void *);
void *NewString_ReadMsgData(void *, u32);
void *BufferItemName(void *, u32, u16);
void *BufferItemNamePlural(void *, u32, u16);
BOOL SoundSys_GetGBSoundsState(void);
void SoundSys_ToggleGBSounds(void);

void ov15_021F9984(void);
void ov15_021F995C(void *);
u16 ov15_021F9D60(void *, u16, BOOL);
void ov15_021FA0E4(void *, s32);
s32 ov15_021FA074(void *);
BOOL ov15_021FA104(void *, s32);
s32 ov15_021FBFF8(void *);
s32 ov15_021FC140(void *);
s32 ov15_021FD0E8(void *);
s32 ov15_021FBF98(void *);
void ov15_021FE154(void *);
void ov15_021FE584(void *, u32, u32);
void ov15_021FE5A4(void *, u32, u32);
void BagApp_ToggleGBSounds(void *);
s32 ov15_021FC3EC(void *);
s32 ov15_021FD3C0(void *);
void ov15_021FE874(void *);

s32 ov15_021FA68C(void *, u8);
s32 ov15_021FA6C0(void *, s32, s32);
void ov15_021FE1D0(void *);

#endif
