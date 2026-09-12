#ifndef OVERLAY05_PARTY_STATUS_UI_PRIVATE_H
#define OVERLAY05_PARTY_STATUS_UI_PRIVATE_H
#include "global.h"

#include "filesystem.h"
#include "sprite_system.h"
typedef struct Ov05R10 {
    u8 raw[0xC00];
} Ov05R10;
typedef struct Ov05R10Layout {
    u8 pad[0xB48];
    void *text[9];
    u8 x[4];
    u8 y[4];
} Ov05R10Layout;
void ov05_0221D318(Ov05R10 *);
void ov05_0221D414(Ov05R10 *, void *, int, int);
int Party_GetCount(void *);
void *Party_GetMonByIndex(void *, int);
u32 GetMonData(void *, int, void *);
int Pokemon_GetStatusIconId(void *);
void ov05_0221D4D0(Ov05R10 *);
void ov05_0221D530(Ov05R10 *, int, void *);
void ov05_0221D5DC(Ov05R10 *);
void ov05_0221D664(Ov05R10 *, int, int, int);
void ov05_0221D690(Ov05R10 *);
void ov05_0221D890(Ov05R10 *);
void ov05_0221D904(Ov05R10 *);
void *FontSystem_NewInit(int, int);
void FontOAM_Delete(void *);
void sub_020135AC(void *);
void sub_020136B4(void *, int, int);
int ov05_0221CCF4(void);
void TextOBJ_SetSpritesDrawFlag(void *, int);
#endif
