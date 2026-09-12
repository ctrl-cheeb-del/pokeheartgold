#ifndef OVERLAY102_UI_LAYOUT_R20_PRIVATE_H
#define OVERLAY102_UI_LAYOUT_R20_PRIVATE_H

#include "global.h"

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
void *NewMsgDataFromNarc(u32 type, u32 narc, u32 fileId, u32 heapId);
void DestroyMsgData(void *msgData);
void *ListMenuCursorNew(u32 heapId);
void DestroyListMenuCursorObj(void *cursor);
void Sprite_Delete(void *sprite);
void YesNoPrompt_Destroy(void *prompt);
u32 ov102_021EA268(u8 *work);
u8 *ov102_021E8F68(u8 *args);
u32 ov102_021E8F6C(u8 *args);
u32 ov102_021E8F84(u8 *args);
void BgSetPosTextAndCommit(void *bgConfig, u32 layer, u32 op, s32 value);
void Main_SetHBlankIntrCB(void *callback, void *arg);
void RemoveWindow(void *window);

void ov102_021EA270(u8 *base, u8 *out, u32 index, u8 value);
void *ov102_021EA2B4(u8 *base, void *list, s32 x, s32 y, u32 anim, u32 kind);
void *ov102_021EA314(void *owner, void *args, void *fieldSystem);
void ov102_021EA380(u8 *work);
void ov102_021EA644(u8 *work);
void ov102_021EA71C(u8 *work, u8 direction);
void ov102_021EA874(u8 *work);
void ov102_021EA8C0(u8 *work);
void *Sprite_Create(void *template);
void Sprite_SetAnimActiveFlag(void *sprite, BOOL active);
void Sprite_SetAnimSpeed(void *sprite, fx32 speed);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *narc, s32 member, s32 location, s32 offset, u32 size, u32 heapId);
void *GfGfxLoader_GetPlttDataFromOpenNarc(void *narc, s32 member, void *out, u32 heapId);
void DC_FlushRange(const void *src, u32 size);
void ov102_021EA80C(u8 *work, void *narc);

#endif
