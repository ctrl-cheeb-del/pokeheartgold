#ifndef POKEHEARTGOLD_TO45_OVERLAY45_ENTRY_RENDER_PRIVATE_H
#define POKEHEARTGOLD_TO45_OVERLAY45_ENTRY_RENDER_PRIVATE_H

#include "global.h"

typedef struct Overlay45RenderEntry {
    u8 state : 4;
    u8 type : 2;
    u8 top : 2;
    u8 active : 1;
    u8 handler : 7;
    u8 timer;
    u8 step;
    void *ctx;
    void *sprite;
    u8 render[0x78];
    u8 mode;
    u8 lastAnim;
    u16 frame;
    u32 baseOffset;
    u32 lightFlags;
} Overlay45RenderEntry;

extern u32 ov42_02228188(void *, u32);
extern u32 ov45_022309C4(u32, u32);
extern u32 ov45_022309D0(u32, u16, u32);
extern void sub_02023EE0(void *, u32);
extern void sub_02023F40(void *, s32);
extern void sub_02023F04(void *, s32);
extern BOOL ov45_02230AA4(Overlay45RenderEntry *);
extern BOOL ov45_02230E78(void *);
extern void sub_02023EA4(void *, BOOL);
extern void sub_020182A0(void *, BOOL);
extern void *sub_02023FDC(void *);
extern void NNS_G3dMdlSetMdlLightEnableFlagAll(void *, u32);
extern const u8 ov45_02254C34[4];
extern void (*ov45_02254F1C[3])(Overlay45RenderEntry *);

void ov45_02230E28(Overlay45RenderEntry *entry);
void ov45_02230B64(Overlay45RenderEntry *entry);
void ov45_02230B8C(Overlay45RenderEntry *entry);
void ov45_02230BFC(Overlay45RenderEntry *entry);
void ov45_02230C40(Overlay45RenderEntry *entry);
void ov45_02230CB0(Overlay45RenderEntry *entry);
void ov45_02230D20(Overlay45RenderEntry *entry);
void ov45_02230D5C(Overlay45RenderEntry *entry);
BOOL ov45_02230DC4(u32 value);
void ov45_02230DF4(Overlay45RenderEntry *entry);
void ov45_02230E64(void *sprite, Overlay45RenderEntry *entry);

#endif
