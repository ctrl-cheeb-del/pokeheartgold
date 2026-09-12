#ifndef POKEHEARTGOLD_OVERLAY108_AREA_PAGE_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY108_AREA_PAGE_PRIVATE_H

#include "global.h"

typedef struct Ov108AreaWindow {
    u8 raw[16];
} Ov108AreaWindow;

typedef struct Ov108AreaPageWork {
    u8 pad_000[0x304];
    void *msgData;
    void *format;
    void *string;
    u8 pad_310[0x340 - 0x310];
    void *bg;
    void *list;
    void *sub;
    void *spriteSystem;
    void *spriteMan;
    void *sprite0;
    void *sprite1;
    void *sprite2;
    void *sprite3;
    void *sprite4;
    void *sprite5;
    void *movingSprites[12];
    void *font;
    void *unk3A0;
    void *textObj;
    u8 pad_3A8[0x3B4 - 0x3A8];
    Ov108AreaWindow windows[15];
    u8 pad_4A4[0x184DE - 0x4A4];
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
} Ov108AreaPageWork;

extern const u32 ov108_021EA724[];
void ReadMsgDataIntoString(void *, int, void *);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
void CopyWindowToVram(void *);
void ManagedSprite_OffsetPositionXY(void *, s16, s16);
void ManagedSprite_SetPositionXY(void *, s16, s16);
void ManagedSprite_SetPriority(void *, int);
void Sprite_OffsetPositionXY(void *, s16, s16);
void ov108_021E84F8(void *, int, int);

void ov108_021E7C5C(Ov108AreaPageWork *);
u32 ov108_021E80F4(Ov108AreaPageWork *);
void ov108_021E81A8(Ov108AreaPageWork *);

#endif
