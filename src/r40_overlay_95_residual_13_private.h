#ifndef OVERLAY_95_RESIDUAL_13_PRIVATE_H
#define OVERLAY_95_RESIDUAL_13_PRIVATE_H

#include "global.h"

#include "sprite_system.h"

typedef struct Ov95StateR13 {
    u32 heapId;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    u8 pad0C[4];
    ManagedSprite *sprite;
    void *messageFormat;
    u8 pad18[4];
    u8 windows[0x20];
} Ov95StateR13;

extern const ManagedSpriteTemplate ov95_021E782C;
void GF_AssertFail(void);
void RemoveWindow(void *window);
void *NewMsgDataFromNarc(u32 type, u32 narc, u32 file, u32 heap);
void *ReadMsgData_ExpandPlaceholders(void *format, void *msgData, u32 msgId, u32 heap);
void FillWindowPixelBuffer(void *window, u32 fill);
u8 AddTextPrinterParameterizedWithColor(void *window, u32 font, void *string, u32 x, u32 y, u32 speed, u32 color, void *callback);
void CopyWindowToVram(void *window);
void DestroyMsgData(void *msgData);
void String_Delete(void *string);
void ManagedSprite_SetAnimateFlag(ManagedSprite *sprite, BOOL flag);
void ManagedSprite_SetDrawFlag(ManagedSprite *sprite, BOOL flag);

void ov95_021E7308(Ov95StateR13 *state);
void ov95_021E7328(Ov95StateR13 *state, void *window, u32 msgId);
void ov95_021E7388(Ov95StateR13 *state, int resource0, int resource1, int resource2, int resource3);

#endif
