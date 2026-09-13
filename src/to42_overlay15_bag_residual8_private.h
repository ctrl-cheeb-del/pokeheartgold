#ifndef TO42_OVERLAY15_BAG_RESIDUAL8_PRIVATE_H
#define TO42_OVERLAY15_BAG_RESIDUAL8_PRIVATE_H

#include "global.h"

#include "system.h"

#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))

extern const u8 ov15_02200584[];
extern const u8 ov15_02200585[];
extern const u8 ov15_02200586[];
extern const u8 ov15_02200587[];
extern const u8 ov15_02200528[];
extern const u8 ov15_02200529[];
extern const u8 ov15_0220052A[];
extern const u8 ov15_0220052B[];
extern const u8 ov15_02201468[];

int ov15_021FA074(void *);
int ov15_021FA098(void *);
void ov15_021FA0E4(void *, int);
int ov15_021FAC2C(void *, int);
void ov15_021F9F08(void *);
void ov15_021F9C78(void *, int);
void ov15_021FD574(void *, int, int, int);
void ov15_021FF364(void *, int, int, int);
void ov15_021FF6BC(void *, int, int, int);
void ov15_02200140(void *, void *, int, int);
void ov15_022001C4(void *, void *, int);
void ov15_02200030(void *, int);
void ov15_021FD404(void *, int, int);
void ov15_021FFECC(void *, int);
void ov15_02200294(void *);
void ov15_021FF560(void *);
void ov15_021FF7AC(void *);
void ov15_021FE868(void *);
void ov15_021FED3C(void *);
void ov15_021FED24(void *);
void ov15_021FD788(void *, int);
void ov15_021FFF24(void *);
int ov15_021FEF48(void *, int);
void ov15_021FB518(void *);
int ov15_021FB3F0(void *);
int ov15_021FB784(void *);
int BagApp_TryUseItemInPlace(void *, int);
void ov15_021FB830(void);
void ov15_021FBBB0(void);
void ov15_021FB060(void *);
void ov15_0220023C(void *, const u8 *);
void ov15_021FF758(void *, void *, u8);
void ov15_021FD7D0(void *, int, int, int, int);

int ov15_021FAD28(int);
int ov15_021FADE8(void *, int);
void ov15_021FAFFC(void *);
void ov15_021FB114(void *);
void ov15_021FAD80(void *, void *);
void ov15_021FB518(void *);
void ov15_021FB380(void *, const u8 *);
int ov15_021FB5AC(void *);
int ov15_021FB604(void *);
void ov15_021FB654(void *);
int ov15_021FB680(void *);
int ov15_021FB700(void *);

void PlaySE(u16);
void MoveItemSlotInList(void *, int, int, int, int);
void ManagedSprite_SetPositionXY(void *, s16, s16);
void ClearFrameAndWindow2(void *, int);
void ClearWindowTilemapAndScheduleTransfer(void *);
void ScheduleWindowCopyToVram(void *);
BOOL TextPrinterCheckActive(u8);
void sub_020880CC(int, int);
u32 GetItemAttr(u16, int, int);
void *GetItemFieldUseFunc(int, u16);
void GetItemUseErrorMessage(void *, void *, u16, int, int);
BOOL TryFormatRegisteredKeyItemUseMessage(void *, void *, u16, int);

#endif
