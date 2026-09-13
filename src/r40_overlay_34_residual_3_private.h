#ifndef OVERLAY34_DISPLAY_R40_PRIVATE_H
#define OVERLAY34_DISPLAY_R40_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "sprite.h"
#include "sprite_transfer.h"
typedef struct Ov34State {
    u8 raw[0x400];
} Ov34State;
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
extern const BgTemplate ov34_0225E714;
extern const BgTemplate ov34_0225E6F8;
extern const BgTemplate ov34_0225E6C0;
extern const BgTemplate ov34_0225E6DC;
void ov34_0225D900(void *);
void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
void FieldMessage_LoadTextPalettes(int, int);
extern const s32 ov34_0225E6A0[];
void ov34_0225D924(void *);
void ov34_0225DB20(Ov34State *);
void ov34_0225DA50(Ov34State *);
#endif
