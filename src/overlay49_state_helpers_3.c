#include "overlay49_state_helpers_private.h"
#pragma require_prototypes off

void ov49_02265858(void *p) {
    int i; u8 *cur=(u8 *)p+0x106dc; u8 *other=(u8 *)p+0x1081c;
    for(i=0;i<16;i++,p=(u8 *)p+0x14,cur+=0x14) {
        if(*(void **)((u8 *)p+0x106dc)!=0) { sub_020180F8(cur,other); *(void **)((u8 *)p+0x106dc)=0; }
    }
}

void ov49_02265890(void *p, Ov49Actor *a, void *object, u32 type) {
    if(type>=0x1b) GF_AssertFail();
    ov49_02265948(p,a); a->object=object; a->type=type; a->sub=(u8 *)ov49_02258E60(object,5)+0x28;
    ov49_0226A5A4[a->type](p,a); ov49_02265668(p,a,ov49_0226A610[a->type]);
}

void ov49_022658E4(void *p, Ov49Actor *a) {
    if(ov49_02265958(a)!=0) { if(a->type>=0x1b) GF_AssertFail(); if(ov49_0226A538[a->type](p,a)==1) ov49_02265948(p,a); }
}

u32 ov49_02265920(void *p, Ov49Actor *a) {
    if(ov49_02265958(a)==0) return 0; if(a->type>=0x1b) GF_AssertFail(); return ov49_02266AF0(p,a);
}

void ov49_02265948(void *unused, Ov49Actor *a) { memset(a,0,0xd10); }
