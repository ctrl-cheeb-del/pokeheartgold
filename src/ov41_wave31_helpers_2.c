#include "ov41_wave31_helpers_private.h"

void ov41_02249E40(void *d,int x){int i,n=U32(d,8)>>1;u16 *p=(u16 *)((u8 *)d+0xc);for(i=0;i<n;i++)p[i]+=x;}
