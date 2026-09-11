#include "overlay99_event_helpers_private.h"

void ov99_021E84EC(u8 *w,int i){void *x=ov99_021E94CC(*(void **)w,i,0,*(u32 *)(w+0xB0));ov98_0221EFE8((u8)i,ov99_021E945C(*(void **)w),x);}

int ov99_021E8518(u8 *w,int i,void *p){void *x=ov99_021E94CC(*(void **)w,i,0,0);if(*(u32 *)(w+0xB0)!=0)return 0;return ov98_0221EFE8((u8)i,p,x);}

BOOL ov99_021E8544(u8 *w,int x){if(ov99_021E94CC(*(void **)w,*(s8 *)(w+0xAC),x,*(u32 *)(w+0xB0))== (void *)0xFFFF)return TRUE;return FALSE;}
