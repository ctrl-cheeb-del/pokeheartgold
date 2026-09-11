#ifndef SOL40_R30_PRIVATE_H
#define SOL40_R30_PRIVATE_H
#include "global.h"
#define U16(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
extern u8 gSystem[]; extern const u8 ov41_0224C094[]; int System_GetTouchHeld(void); void ov41_0224A60C(int,int,void *);
void GF_AssertFail(void); void ov41_02246388(void *,int); void ov41_0224639C(void *,int); void ObjCharTransfer_ResetTransferTasksByResID(int); void ObjPlttTransfer_FreeTaskByID(int); void ov41_0224A1A8(void *); void sub_02021B5C(void *); void ov41_0224A1C0(void *); void sub_020135AC(void *); void TouchHitboxController_Destroy(void *);
int ov41_0224A4EC(void *); void ov41_0224A448(void *); int TouchHitboxController_IsTriggered(void *); void ov41_0224A8B0(void *,int); void ov41_0224A8D4(void *,int); void ov41_0224A1EC(void *,int,int); void ov41_0224A9BC(void *,void *,void *); void ov41_0224A9F8(void *,void *,void *); void ov41_0224A238(void *,void *,void *,void *);
void ov41_02246360(void *,int); void ov41_02246374(void *,int); void ov41_0224A270(void *); void ov41_0224A258(void *); void ov41_0224A264(void *); void sub_020136B4(void *,int,int); void TextOBJ_SetPaletteNum(void *,int);
void ov41_0224A3E4(void *,void *); void ov41_0224A448(void *); int ov41_0224A4EC(void *); int ov41_0224A54C(void *); void ov41_0224A580(void *); void ov41_0224A5A4(void *,void *,void *); void ov41_0224A5D4(void *,int,void *,void *,void *); void ov41_0224A7E0(u8 *,int,int,int,int,int); void ov41_0224A888(void *); void ov41_0224A8B0(void *,int); void ov41_0224A8D4(void *,int);
#endif
