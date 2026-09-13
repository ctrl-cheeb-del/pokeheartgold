#ifndef SOL_R40_NIGHT_OVERLAY72_RESIDUAL6_PRIVATE_H
#define SOL_R40_NIGHT_OVERLAY72_RESIDUAL6_PRIVATE_H
#include "global.h"

#include "bg_window.h"
void ov72_02238124(void);
void ov72_02238164(void);
void ov72_02238194(void *);
void ov72_02238408(void *);
void ov72_022380FC(void *);
void Main_SetVBlankIntrCB(void (*)(void *), void *);
void SpriteTransfer_DeleteCharTransferTask(void *);
void SpriteTransfer_DeletePlttTransferTask(void *);
void Destroy2DGfxResObjMan(void *);
void SpriteList_Delete(void *);
void OamManager_Free(void);
void ObjCharTransfer_Destroy(void);
void ObjPlttTransfer_Destroy(void);
BOOL ov72_022387C4(void);
void sub_0203A930(void);
extern int (*ov72_0223B660[])(void *);
void SysTask_Destroy(void *);
void ov72_02239098(void *);
void ov72_02238FFC(void *);
void ov72_02238AEC(void *);
void ov72_022387D8(void *);
void ov72_02238800(void *);
int ov72_0223894C(void *);
int ov72_0223897C(void *);
extern const BgTemplate ov72_0223B42C, ov72_0223B410, ov72_0223B448, ov72_0223B3D8, ov72_0223B3F4;
void ov72_022389C8(void *);
void ov72_02239040(void *);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
void ov72_02238BEC(void *);
void ov72_02238EE4(void *);
void *sub_0202D488(void *, int);
BOOL ov00_021EC5B4(void);
void sub_02039418(void *);
void ov72_0223A350(void *, void *, int, int, int);
void ov72_02238680(void *, int, int);
void ov72_0223A420(void *);
void Sys_ClearSleepDisableFlag(int);
int ov72_0223886C(void *);
#endif
