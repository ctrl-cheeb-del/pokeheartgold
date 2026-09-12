#ifndef OV40_PC_BOX_GRID_PRIVATE_H
#define OV40_PC_BOX_GRID_PRIVATE_H

#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define S32(p, off)  (*(s32 *)((u8 *)(p) + (off)))

void ClearWindowTilemapAndCopyToVram(void *window);
void RemoveWindow(void *window);
void InitWindow(void *window);
int WindowIsInUse(const void *window);
void AddWindowParameterized(void *bgConfig, void *window, u8 bgId, u8 x, u8 y, u8 width, u8 height, u8 paletteNum, u16 baseTile);
void FillWindowPixelBuffer(void *window, u8 fillValue);
void ScheduleWindowCopyToVram(void *window);
void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *str, int x, int y, int speed, u32 color, void *callback);
void *NewString_ReadMsgData(void *msgData, u32 strno);
void DestroyMsgData(void *msgData);
void *NewMsgDataFromNarc(u32 type, u32 narcId, u32 fileId, u32 heapId);
void ReadMsgDataIntoString(void *msgData, u32 msgId, void *dst);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
void String_SetEmpty(void *str);
BOOL FontID_String_AllCharsValid(u32 fontId, void *str0, void *str1);
void Heap_Free(void *ptr);
void GF_AssertFail(void);
void PlaySE(u32 seq);
void GfGfx_EngineATogglePlanes(int planes, int enable);
void GF_RunVramTransferTasks(void);
void PaletteData_PushTransparentBuffers(void *paletteData);
void DoScheduledBgGpuUpdates(void *bgConfig);
BOOL System_GetTouchNew(void);
BOOL System_GetTouchNewCoords(u32 *x, u32 *y);
void TouchHitboxController_IsTriggered(void *controller);
BOOL TouchscreenHitbox_TouchHeldIsIn(const void *hitbox);
BOOL TouchscreenHitbox_TouchNewIsIn(const void *hitbox);
void Sprite_DeleteAndFreeResources(void *sprite);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_GetPositionXY(void *sprite, s16 *x, s16 *y);
void ManagedSprite_SetPositonFxXY(void *sprite, s32 x, s32 y);
void TextOBJ_SetSpritesDrawFlag(void *obj, BOOL draw);
void sub_020136B4(void *p, s32 a, s32 b);
void SpriteSystem_LoadCharResObjFromOpenNarc(void *system, void *manager, void *narc, u32 member, u32 compressed, u32 vramType, u32 resourceId);
void SpriteSystem_LoadCellResObjFromOpenNarc(void *system, void *manager, void *narc, u32 member, u32 compressed, u32 resourceId);
void SpriteSystem_LoadAnimResObjFromOpenNarc(void *system, void *manager, void *narc, u32 member, u32 compressed, u32 resourceId);
void Thunk_G3X_Reset(void);
void RequestSwap3DBuffers(int a, int b);
u64 sub_0203088C(void *summary, int field, int index);
void sub_020878B8(void *p, s16 x, s16 y);
BOOL sub_020879E0(void *p, int flag);
void ov41_0224B554(void *p);
void ov41_0224B5C8(void *p);

void ov40_0222BF80(void *p, int value);
void ov40_0222C474(void *p);
void ov40_0222D294(void *p, s16 *x, s16 *y);
void ov40_0222D6D0(void *p);
void ov40_0222D7DC(void *p);
void ov40_0222DE40(void *p);
void ov40_0222DED0(void *p, int value);
void ov40_0222DFB0(void *p);
void ov40_02230944(void *p);
void *ov40_0223D540(void *p);

extern const u8 ov40_02245100[];
extern const u8 ov40_02245104[];
extern const u8 ov40_022451C8[];
extern const u8 ov40_022451CC[];
extern const s16 _02245CC0[];

void *ov40_022309DC(void *p);
void ov40_02230E08(void *str, u32 heapId);
int ov40_0223142C(void *p);
int ov40_0223169C(void *p);
int ov40_02231700(void);
void ov40_02232FEC(void *p, u32 msgId);
void ov40_02235868(void *p, u32 msgId);
void ov40_022359B4(void *p, int a);
BOOL ov40_02235DAC(void *scene, u32 sel);
void ov40_02235E34(void *scene, u32 sel);
int ov40_022306C0(void *window, void *str);

/* module-local prototypes */
void ov40_02230CDC(void *p);
void ov40_02230D20(void *p);
BOOL ov40_02230D94(void *p, u64 val);
void ov40_02230DCC(void *p, void *str);
void ov40_02230E08(void *str, u32 heapId);
void ov40_02230E34(void *p);
void ov40_02230EB4(void *p);
int ov40_022313F0(void *p);
int ov40_0223169C(void *p);
int ov40_02231700(void);
int ov40_0223172C(void *p);
int ov40_02231868(void *p);
int ov40_0223189C(void *p);
int ov40_02232598(void *p);
void ov40_022327BC(void *p);
void ov40_02232F50(void *p);
void ov40_02232F88(void *p);
void ov40_02232FCC(void *p);
void ov40_02232FEC(void *p, u32 msgId);
void ov40_022330B8(void *p);
void ov40_022330E0(void *p, int a);
void ov40_0223311C(void *p, u32 vram);
void ov40_0223320C(void *p);
void ov40_022334F8(u16 *buf, int start, int count);
void ov40_02233C3C(void *p);
int ov40_02233EE8(void *p);
int ov40_02234470(void *p);
int ov40_02234A14(void *p);
void ov40_0223584C(void *p);
void ov40_02235868(void *p, u32 msgId);
void ov40_022358C0(void *p);
void ov40_02235900(void *p);
void ov40_02235994(void);
void ov40_022359B4(void *p, int a);
void ov40_02235B10(void *p);
void ov40_02235FA0(void *p);
void ov40_02235FD0(u32 sel, int flag, void *scene);
void ov40_0223610C(void *p);
void ov40_02236130(void *p);

#endif
