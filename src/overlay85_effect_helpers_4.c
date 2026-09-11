#include "overlay85_effect_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E7B8C(void *task,void *p){int r;do{r=ov85_021EA51C[U32(p,0)](p);}while(r==1);if(r==2){U32((void*)U32(p,0x10),8)=1;Heap_Free(p);SysTask_Destroy(task);}}

int ov85_021E7BC0(void *p){void *obj=(void*)U32(p,0x10);U32(obj,0x38)=0x1000;U32(obj,0x3C)=0x1000;U32(obj,0x40)=0x1000;U32(obj,0x54)=0xC0000;ov85_021E776C((void*)U32(p,0x14),obj);U32(p,0xC)=0x8000;U32(p,0)=1;return 0;}

int ov85_021E7BEC(void *p){void *obj=(void*)U32(p,0x10);U32(obj,0x54)-=U32(p,0xC);if(U32(p,8)==0 && (s32)U32(obj,0x54)<=0x68000){U32(p,8)=1;PlaySE(0x64F);}if((s32)U32(obj,0x54)<=0x20000){U32(obj,0x54)=0x20000;U32(p,0)=2;}return 0;}
