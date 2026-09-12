#ifndef POKEHEARTGOLD_OVERLAY102_EASY_CHAT_INPUT_R4_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY102_EASY_CHAT_INPUT_R4_PRIVATE_H

#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

extern u8 gSystem[];
extern int System_GetTouchHeld(void);
extern int System_GetTouchNew(void);
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern int TouchscreenHitbox_PointIsIn(const void *, int, int);
extern int ov102_021EC5A0(s16, s16);
extern u8 ov102_021EC5E0[];
extern u8 ov102_021EC600[];
extern int ov102_021E7A58(void *, void *);
extern int ov102_021E7C84(void *, void *);
extern int ov102_021E8178(void *, void *);
extern int ov102_021E9464(void *);
extern int ov102_021E947C(void *, int);
extern void ov102_021E8580(void *, void *);
extern void ov102_021E7A4C(void *, void *);
extern int ov102_021E7BD8(void *);
extern int ov102_021E7BE8(void *);
extern int ov102_021E7AB8(void *, int);
extern void ov102_021E940C(void *, int);
extern void ov102_021E8D50(void *, void *);
extern void ov102_021E8D94(void);
extern void ov102_021E8E84(void);
extern int ov102_021E7B18(void *);
extern int ov102_021EA238(void *);
extern int ov102_021E7F6C(void *);
extern void PlaySE(int);
extern void ov102_021E79A0(void *, void *);
extern void ov102_021E7968(void *, void *);
extern int ov102_021E7DBC(void *);
extern int ov102_021E85A8(void *, int, u16);
extern void ov102_021E874C(void *, void *);
extern void ov102_021E7AA4(void);
extern void ov102_021E87B4(void);
extern int ov102_021E85E8(void *);

int ov102_021E7BF8(void *work);
int ov102_021E7C84(void *work, void *state);
int ov102_021E7D0C(void *work, void *state);
int ov102_021E7D30(void *work, int choice);
int ov102_021E7EEC(void *unused, int x, int y);
int ov102_021E7F30(void *unused, int x, int y);
int ov102_021E80BC(void *work);
int ov102_021E8178(void *work, void *state);
int ov102_021E821C(void *work, void *state);
int ov102_021E8240(void *work, void *state);
void ov102_021E8294(void *work, void *state);
int ov102_021E839C(void *work);
int ov102_021E83E4(void *work);
int ov102_021E8458(void *work);
void ov102_021E848C(void *work, void *state);

#endif
