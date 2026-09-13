#ifndef OVERLAY_18_RESIDUAL_45_R40_PRIVATE_H
#define OVERLAY_18_RESIDUAL_45_R40_PRIVATE_H
#include "global.h"
typedef struct Ov18CharDataR45 {
    u8 pad00[0x14];
    void *raw;
} Ov18CharDataR45;
u32 FontID_String_GetWidth(u32 fontId, void *str, u32 spacing);
u8 AddTextPrinterParameterizedWithColor(void *window, u32 fontId, void *str, u32 x, u32 y, u32 speed, u32 color, void *callback);
void *NewString_ReadMsgData(void *msgData, s32 msgId);
void String_Delete(void *str);
u32 ov18_021E5900(u32 species);
u32 ov18_021E5904(u32 species);
void *GfGfxLoader_GetCharData(u32 narcId, s32 member, BOOL compressed, Ov18CharDataR45 **charData, u32 heapId);
void *Heap_AllocAtEnd(u32 heapId, u32 size);
void Heap_Free(void *ptr);
extern const u32 ov18_021FBE10[];
extern const u8 ov18_021FBDFC[];
void ov18_021F95FC(void *window, void *str, u32 x, u32 y, u32 fontId, u32 color, u32 align);
void ov18_021F9648(void *window, void *msgData, u32 msgId, u32 x, u32 y, u32 fontId, u32 color, u32 align);
u32 ov18_021F967C(u32 index);
u8 ov18_021F9688(u32 index);
void *ov18_021F9694(u32 species, u32 heapId);
#endif
