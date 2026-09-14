#ifndef TO47_OVERLAY83_SPRITE_SETUP_PRIVATE_H
#define TO47_OVERLAY83_SPRITE_SETUP_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define U8(p, offset) (*(u8 *)((u8 *)(p) + (offset)))
#define PTR(p, offset) (*(void **)((u8 *)(p) + (offset)))

void *NARC_New(int narcId, int heapId);
void FontID_Alloc(int fontId, int heapId);
void *NewMsgDataFromNarc(int type, int narcId, int fileId, int heapId);
void *MessageFormat_New(int heapId);
void *String_New(int maxLength, int heapId);
void LoadFontPal0(int, int, int);
void LoadFontPal1(int, int, int);
void *MessagePrinter_New(int, int, int, int);
void ov83_022478D4(void *, void *, int);
void ov83_02240F7C(void *, s16 *, s16 *, s16 *, s16 *);
void *ov83_02247454(void *, int, int, int, int, s16, s16, int, int);
void *ov83_022474C4(void *, int, int, int, int, s16, s16, int, int);
void ov83_0224755C(void *, int);
int ov80_02237B24(u8, int);
int ov80_02237D8C(u8);
void *Party_GetMonByIndex(void *, int);
u32 GetMonData(void *, int, void *);
int CalculateHpBarColor(u16, u16, int);
int ov83_022411B0(void *, int);
int ov83_022411DC(void *, int);
void ov83_022475EC(void *, void *);
void ov83_02242894(int, s16 *, s16 *);
void ov83_02240E70(void *, int *, int *, int);
void ov83_02241E18(void *);
void ov83_02241FF0(void *);
void ov83_022421E0(void *, int);
void ov83_02247668(void *, void *, u16, void *);
void *ov83_02247A24(void *, int, u8);
void *ov83_02247CB8(void *, void *);
void ov83_02247844(void *);
int sub_02037474(void);
void G2dRenderer_SetObjCharTransferReservedRegion(int, int);
void G2dRenderer_SetPlttTransferReservedRegion(int);
void sub_0203A880(void);
void G2x_SetBlendAlpha_(u32, int, int, int, int);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void ov83_0223F690(void *);
void ov83_0223F70C(void *);
void ov83_0223F7A0(void *);

#endif
