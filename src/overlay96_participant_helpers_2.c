#include "overlay96_participant_helpers_private.h"

void *ov96_021FC028(u32 heap) {
 int i; u8 *p; u8 *base=Heap_Alloc(heap,0xC24); MI_CpuFill8(base,0,0xC24); p=base; i=0;
 do { *(void **)p=ov96_021FBE20(4,(void *)heap); i++; p+=8; } while(i<3);
 return base;
}

void ov96_021FC05C(u8 *p) { u8 *base; int i; u8 *it; base=p; i=0; it=base; do { ov96_021FBE3C(*(void **)it); i++; it+=8; } while(i<3); Heap_Free(base); }

void ov96_021FC07C(u8 **p, void *arg) { int i=0,j; do { j=0; do { void **x=ov96_021FBE44(*p,j); void *a=ov96_021EB4F4(arg,0x65,2); void *b=ov96_021EB4F4(arg,0x67,6); ov96_021FBE4C(x,a,b); j++; } while(j<4); p=(u8 **)((u8 *)p+8); i++; } while(i<3); }
