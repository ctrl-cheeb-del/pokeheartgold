#ifndef POKEHEARTGOLD_OVERLAY108_AREA_PAGE_NAME_INTERNAL_H
#define POKEHEARTGOLD_OVERLAY108_AREA_PAGE_NAME_INTERNAL_H

#include "global.h"

typedef struct SafariAreaCustomizer {
    u8 pad000[0x1C];
    u8 entries[0x304 - 0x1C];
    void *msgData;
    void *format;
    void *string;
    u8 pad310[0x340 - 0x310];
    void *bgConfig;
    void *listMenuSpawner;
    void *sub;
    void *spriteSystem;
    void *spriteMan;
    void *sprites[18];
    void *fontSystem;
    void *unk3A0;
    void *textObj;
    u8 pad3A8[0x3B4 - 0x3A8];
    u8 windows[15][0x10];
    u8 pad4A4[0x184DC - 0x4A4];
    u8 textSpeed;
    u8 frameStyle;
    u8 index;
    u8 selected;
    u8 otherPage;
    u8 frame;
    u8 flag0 : 1;
    u8 bit1 : 1;
    u8 flagB : 1;
    u8 mode : 5;
    u8 active;
    s16 x;
    s16 y;
} SafariAreaCustomizer;

void FillWindowPixelBuffer(void *window, u8 fillValue);
void ScheduleWindowCopyToVram(void *window);
void ReadMsgDataIntoString(void *msgData, u32 msgNo, void *dest);
u32 FontID_String_GetWidth(u32 fontId, void *string, u32 letterSpacing);
void AddTextPrinterParameterizedWithColor(void *window, u32 fontId, void *string, u32 x, u32 y, u32 speed, u32 color, u32 callback);
void FillBgTilemapRect(void *bgConfig, u8 bgId, u16 fillValue, u8 x, u8 y, u8 width, u8 height, u8 mode);
void ScheduleBgTilemapBufferTransfer(void *bgConfig, u8 bgId);
void ManagedSprite_SetPositionXY(void *sprite, s16 x, s16 y);
void ManagedSprite_SetPriority(void *sprite, int priority);
void ov108_021E78F4(SafariAreaCustomizer *s, u32 idx, u32 anim);
void ov108_021E77D4(SafariAreaCustomizer *s);
void ov108_021E79A8(SafariAreaCustomizer *s, u32 a, u32 b, u32 c);
void ov108_021E78C0(SafariAreaCustomizer *s, u32 idx, u32 anim, u32 on);
void ov108_021E84F8(void *sub, u8 idx, u8 value);
void ov108_021E7EB0(SafariAreaCustomizer *s);
void ov108_021E7F7C(SafariAreaCustomizer *s);

#endif
