#ifndef TO45_OV102_RESIDUAL_36_PRIVATE_H
#define TO45_OV102_RESIDUAL_36_PRIVATE_H

#include "global.h"

void *Heap_Alloc(u32 heapId, u32 size);
void Heap_Free(void *ptr);
void *String_New(u32 size, u32 heapId);
void String_Delete(void *str);
void AddWindowParameterized(void *bgConfig, void *window, int bgId, int x, int y, int width, int height, int palette, int baseTile);
void RemoveWindow(void *window);
void Sprite_Delete(void *sprite);
void Sprite_SetAnimCtrlSeq(void *sprite, int seq);
void Sprite_SetDrawFlag(void *sprite, int flag);
void BG_ClearCharDataRange(int bgId, u32 size, int offset, int heapId);
void FillBgTilemapRect(void *bgConfig, int bgId, int fill, int x, int y, int width, int height, int mode);
void FillWindowPixelBuffer(void *window, int fill);
void PutWindowTilemap(void *window);
void CopyWindowPixelsToVram_TextMode(void *window);
void BgCommitTilemapBufferToVram(void *bgConfig, int bgId);
void ToggleBgLayer(int bgId, int enable);
void G2x_SetBlendAlpha_(u32 reg, int plane1, int plane2, int eva, int evb);

void *ov102_021EA268(void *work);
void *ov102_021E8F68(void *args);
void ov102_021EA270(void *work, void *out, int index, int value);
void *ov102_021EA2B4(void *work, void *resource, int x, int y, int anim, int kind);
u32 ov102_021E8FD8(void *args);
void ov102_021EC11C(void *state);
void ov102_021EC13C(void *state, u32 index, void *entry);
int ov102_021EC37C(void *state, int plane1, int plane2, int start, int target, int frames);

void *ov102_021EBC34(void *work, void *args, void *fieldSystem);
void ov102_021EBCBC(void *state);
void ov102_021EBD00(void *state);
void ov102_021EBD68(void *state);
void ov102_021EBDEC(void *state);
int ov102_021EBE3C(void *state);

#endif
