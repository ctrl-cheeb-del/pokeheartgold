#ifndef OVERLAY_98_PRIVATE_H
#define OVERLAY_98_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "gf_gfx_planes.h"
#include "message_format.h"
#include "msgdata.h"
#include "palette.h"
#include "pm_string.h"
#include "sprite_system.h"
#include "system.h"
#include "text.h"
#include "touchscreen.h"

typedef struct Ov98SpriteContext {
    enum HeapID heapId;
    SpriteSystem *spriteSystem;
    SpriteManager *spriteManager;
    PaletteData *paletteData;
    NARC *narc;
    s8 paletteOffset;
} Ov98SpriteContext;

typedef struct Ov98TextContext {
    enum HeapID heapId;
    Window *windows;
    MsgData *msgData;
    MsgData *msgDataFixed;
    MessageFormat *msgFormat;
    String *string;
    u32 windowCount;
} Ov98TextContext;

extern const s32 ov98_0221F220[10];
extern const u16 ov98_0221F1F8[][2];
extern const u32 ov98_0221F1E4[5];
extern const GraphicsBanks ov98_0221F248;
extern const TouchscreenHitbox ov98_0221F1E0;
extern const OamManagerParam ov98_0221F1C0;
extern const OamCharTransferParam ov98_0221F1AC;

void *ov98_0221E5C0(Ov98SpriteContext *);
void *ov98_0221E5D0(Ov98SpriteContext *);
Ov98SpriteContext *ov98_0221E5E0(enum HeapID, SpriteResourceCountsListUnion *, int);
void ov98_0221E684(Ov98SpriteContext *, ManagedSprite **, u32);
void ov98_0221E784(SpriteSystem *, SpriteManager *, const int *, int);
void ov98_0221E6CC(Ov98SpriteContext *);
ManagedSprite *ov98_0221E6E0(Ov98SpriteContext *, const ManagedSpriteTemplate *);
void ov98_0221E9FC(ManagedSprite *, void *, u32);
void *ov98_0221EAA8(Ov98SpriteContext *, int, NNSG2dCharacterData **);
void ov98_0221EE84(Ov98TextContext *, u32);
void ov98_0221EEDC(Ov98TextContext *, u32);
void ov98_0221EEEC(Ov98TextContext *, u32, u8);
void *ov98_0221EEFC(Ov98TextContext *);
void ov98_0221EF14(Ov98TextContext *, u32);
u32 ov98_0221EF64(u32);
u8 ov98_0221EF80(s32);
u16 ov98_0221EFA4(u32, u32);
BOOL ov98_0221EFB4(u32, u32, u16);
BOOL ov98_0221EFE8(u32, u32, u16);
u16 ov98_0221F01C(const void *, u32);
u32 ov98_0221F024(const u8 *);
u8 ov98_0221F058(const u16 (*)[22]);
u32 ov98_0221F120(u32, u32);
u8 ov98_0221F150(s32);
void ov98_0221F174(void);
void ov98_0221EB84(Ov98TextContext *, int);
BOOL ov98_0221EF24(void);
void ov98_0221EBD8(Ov98TextContext *, u32, u32, u32);
void ov98_0221EBEC(Ov98TextContext *, u32, u32, u32, u8, u32);
void ov98_0221EC08(Ov98TextContext *, u32, u32, u32, u8);
void ov98_0221EC24(Ov98TextContext *, u32, u32, u32);
void ov98_0221EC3C(Ov98TextContext *, u32, u32, u32, u32, u8, u32, u32);
void ov98_0221ED3C(Ov98TextContext *, u32, u32);
void ov98_0221ED48(Ov98TextContext *, u32, u32, u32, u32);
void ov98_0221EDA4(Ov98TextContext *, s32, u32, u32);
void ov98_0221EE28(Ov98TextContext *, u32, u32);
void ov98_0221EE9C(Ov98TextContext *, u32, String *, u32, u8);
void ov98_0221EDC4(Ov98TextContext *, u32, u32, u32, PlayerProfile *);
void ov98_0221ECD0(Ov98TextContext *, u32, u32, s32, u32, u32);
void ov98_0221F090(void);
void ov98_0221F0EC(void);

extern void sub_0200FBF4(int, int);

extern u32 MATH_CountPopulation(u32);

#endif
