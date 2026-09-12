#ifndef OVERLAY14_BOX_MOVE_ACTIONS_R38_PRIVATE_H
#define OVERLAY14_BOX_MOVE_ACTIONS_R38_PRIVATE_H

#include "overlay_14_sol_partial_internal.h"

extern void PlaySE(u32);
extern u32 PCStorage_CountMonsAndEggsInBox(void *, u32);
extern u32 PCStorage_CountEmptySpotsInBox(void *);
extern u32 Party_GetCount(void *);
extern void *Party_GetMonByIndex(void *, u32);
extern u32 GetMonData(void *, u32, void *);
extern u32 ItemIdIsMail(u32);
extern u32 GridInputHandler_GetNextInput(void *);
extern void GridInputHandler_SetNextInput(void *, u32);
extern u32 GetBoxMonData(void *, u32, void *);

extern u32 ov14_021E6070(void *, u32, u32, u32);
extern void *ov14_021E60C0(void *, u32, u32);
extern u32 ov14_021E6480(void *, u32);
extern u32 ov14_021E6AA0(void *, u32, u32);
extern u32 ov14_021E7588(void *);
extern void ov14_021E8234(void *);
extern void ov14_021E8294(void *);
extern void ov14_021E8314(void *);
extern void ov14_021E8434(void *);
extern void ov14_021E83F4(void *);
extern void ov14_021E84A4(void *);
extern u32 ov14_021E8544(void *);
extern void ov14_021E85D0(void *);
extern u32 ov14_021E85E4(void *);
extern u32 ov14_021E8648(void *);
extern void ov14_021E8620(void *);
extern void ov14_021E8634(void *);
extern void ov14_021E8824(void *);
extern void ov14_021E884C(void *);
extern void ov14_021E88BC(void *);
extern void ov14_021E88F8(void *);

extern void ov14_021E9450(void *);
extern void ov14_021E99A0(void *);
extern void ov14_021EA254(void *);
extern void ov14_021EA378(void *);
extern void ov14_021EA408(void *);
extern void ov14_021EA4C8(void *);
extern void ov14_021EA778(void *);
extern void ov14_021EAA04(void *);
extern void ov14_021EAB54(void *);
extern void ov14_021EAC24(void *);
extern void ov14_021EACD4(void *);

extern void ov14_021F08BC(void *);
extern void ov14_021F29E4(void *, u32, u32);
extern u32 ov14_021F2A44(void *, u32);
extern void ov14_021F2F88(u32, s16 *, s16 *, u32);
extern void ov14_021F3190(void *, u32, u32);
extern void ov14_021F3844(void *, u32);
extern void ov14_021F396C(void *, u32, u32);
extern void ov14_021F39A0(void *, u32, u32);
extern void ov14_021F39D0(void *);
extern void ov14_021F48B4(void *);
extern void ov14_021F57B8(void *);
extern void ov14_021F5FBC(void *, u32);
extern void ov14_021F6408(void *, u32);
extern void ov14_021F6928(void *, u32, u32);

u32 ov14_021F1540(void *);
u32 ov14_021F1580(void *, u32);
u32 ov14_021F15C8(void *, u32);
u32 ov14_021F1808(void *, u32);
u32 ov14_021F18B0(void *, u32);
u32 ov14_021F19F0(void *, u32);
u32 ov14_021F1B4C(void *, u32);
u32 ov14_021F1C04(void *);
u32 ov14_021F1C4C(void *, u32);
u32 ov14_021F1CDC(void *, u32);
u32 ov14_021F1D6C(void *, u32);

#endif
