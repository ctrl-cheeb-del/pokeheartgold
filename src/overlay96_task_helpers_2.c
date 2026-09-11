#include "overlay96_task_helpers_private.h"
#include "unk_02020B8C.h"
extern void SysTask_Destroy(void*); extern void *SysTask_CreateOnMainQueue(void (*)(void*,void*),void*,u32);
extern const s32 ov96_0221DB70[]; extern const s32 ov96_0221DB5C[];
extern void *Heap_Alloc(u32,u32); extern void MI_CpuFill8(void*,u8,u32);
s32 ov96_021F2814(const VecFx32*,const VecFx32*); u32 ov96_021F2A84(u8*,u32); void ov96_021F2AA4(u8*); void ov96_021F2D68(void*,void*); void ov96_021F2E2C(u8*,u32); void ov96_021F2E4C(void*,void*); s32 ov96_021F2FBC(const u16*,const u16*); void *ov96_021F30A4(u32);

void ov96_021F2AA4(u8*p){if(p[0x44]){p[0x45]--;if(p[0x45]==0){p[0x45]=0;p[0x44]=0;*(u16*)(p+0x8e)=*(u16*)(p+0x8c);}}else{*(u16*)(p+0x8e)+=2;if(*(u16*)(p+0x8e)>*(u16*)(p+0x8c))*(u16*)(p+0x8e)=*(u16*)(p+0x8c);if(*(u16*)(p+0x8e)==*(u16*)(p+0x8c)){p[0x45]=0;p[0x44]=0;}}}
