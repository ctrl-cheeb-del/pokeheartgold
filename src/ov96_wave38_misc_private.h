#ifndef OV96_R109_H
#define OV96_R109_H
#include "global.h"
#include <nitro/fx/fx_vec.h>
typedef u8 R109;
#define P(w,o) (*(void **)((w)+(o)))
#define U32(w,o) (*(u32 *)((w)+(o)))
extern fx32 VEC_DotProduct(const VecFx32 *,const VecFx32 *);
extern void GF_AssertFail(void);
extern fx32 ov96_02213514(const VecFx32 *,const VecFx32 *);
extern const fx16 FX_SinCosTable_[];
extern void *SysTask_CreateOnMainQueue(void (*)(void *,void *),void *,u32);
extern void SysTask_Destroy(void *);
extern void ov96_02214278(void *,void *);
extern void ov96_02214044(R109 *,u32,u32);
extern u32 ov96_022143FC(s32,s32);
extern void ov96_021EABA8(void *,u32);
extern void *PokeathlonCourse_GetDataCopyArea(void *);extern void ov96_021E8A20(void *);extern void *PokeathlonCourse_GetHeapAllocPtr4(void *);extern u32 ov96_02214904(void *);extern void ov96_021E8318(void *,u32);extern void ov96_022136A4(void *,u32);
extern u32 ov96_021E5F24(void *);
extern void Heap_Free(void *);extern void MessageFormat_Delete(void *);extern void DestroyMsgData(void *);extern void RemoveWindow(void *);
BOOL ov96_0221341C(const VecFx32 *,fx32,const VecFx32 *,fx32);fx32 ov96_02213514(const VecFx32 *,const VecFx32 *);BOOL ov96_02213534(const VecFx32 *,const VecFx32 *,u32);void ov96_02213558(R109 *);void ov96_022141F8(R109 *);void ov96_02214234(R109 *);void ov96_02214258(R109 *,u32,u8,u8);u32 ov96_022143DC(const VecFx32 *);u32 ov96_022143FC(s32,s32);int ov96_0221454C(const void *,const void *);void ov96_02214490(R109 *);void ov96_02214618(void *);void ov96_02214690(R109 *);void ov96_022148E8(R109 *,u32,u32);
#endif
