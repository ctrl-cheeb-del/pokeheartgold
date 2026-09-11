#include "overlay96_task_helpers_private.h"
#include "unk_02020B8C.h"
extern void SysTask_Destroy(void*); extern void *SysTask_CreateOnMainQueue(void (*)(void*,void*),void*,u32);
extern const s32 ov96_0221DB70[]; extern const s32 ov96_0221DB5C[];
extern void *Heap_Alloc(u32,u32); extern void MI_CpuFill8(void*,u8,u32);
s32 ov96_021F2814(const VecFx32*,const VecFx32*); u32 ov96_021F2A84(u8*,u32); void ov96_021F2AA4(u8*); void ov96_021F2D68(void*,void*); void ov96_021F2E2C(u8*,u32); void ov96_021F2E4C(void*,void*); s32 ov96_021F2FBC(const u16*,const u16*); void *ov96_021F30A4(u32);

void *ov96_021F30A4(u32 heap){void*p=Heap_Alloc(heap,0x84);MI_CpuFill8(p,0,0x84);return p;}
