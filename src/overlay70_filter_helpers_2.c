#include "overlay70_filter_helpers_private.h"

void ov70_0223E738(MonKey*a,void*x,Filter*f,void*r){int i;for(i=0;i<30;i++,a++,r=(u8*)r+0x20c){if(a->species!=0&&ov70_0223E5FC(a,f)==0)*(u32*)((u8*)r+4)+=3;}}
