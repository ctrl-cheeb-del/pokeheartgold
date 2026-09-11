#ifndef OVERLAY_69_SCRATCH_PRIVATE_H
#define OVERLAY_69_SCRATCH_PRIVATE_H
#include "global.h"

#include "overlay_69.h"
#include "system.h"
extern void GfGfx_DisableEngineAPlanes(void);
extern void GfGfx_DisableEngineBPlanes(void);
extern void *OverlayManager_GetArgs(OverlayManager *);
extern void *memset(void *, int, u32);
extern void *Save_WiFiHistory_Get(void *);
extern int WifiHistory_GetPlayerCountry(void *);
extern int WiFiHistory_GetPlayerRegion(void *);
extern int WiFiHistory_GetNonJapaneseFlag(void *);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void ov69_021E60F8(void *);
extern void ov69_021E6118(void);
extern void ov69_021E6138(void *);
extern void GF3dRender_InitSimpleManager(int);
extern void *BgConfig_Alloc(int);
extern void GfGfx_BothDispOn(void);
extern void ResetAllTextPrinters(void);
extern void *MessageFormat_New_Custom(int, int, int);
extern void *Camera_New(int);
extern void GfGfx_SwapDisplay(void);
extern void SetKeyRepeatTimers(int, int);
extern void TextFlags_SetCanABSpeedUpPrint(int);
extern void TextFlags_SetAutoScrollParam(int);
extern void TextFlags_SetCanTouchSpeedUpPrint(int);
#endif
