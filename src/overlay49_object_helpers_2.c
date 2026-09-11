#include "overlay49_object_helpers_private.h"
extern u32 ov49_0225E85C(u8*,u32,u32,u32);extern void ov49_0225ECD4(void*,u32);extern void ov49_0225EB54(void*,void*,u32);extern void ov49_0225EB84(void*);extern u32 ov49_0225D1C0(void*);extern void ov49_0225D214(void*,void*,u32,u32);extern void GF_AssertFail(void);extern u32 ov49_0225D3BC(void*,void*,u32);extern s32 ov49_0225D470(void*,u32);extern void ov49_0225EAE0(u8*,void*);extern void PlaySE(u32);
void ov49_0225E82C(u8*,u32,u32);u32 ov49_0225E85C(u8*,u32,u32,u32);void ov49_0225E894(u8*,u32);void ov49_0225EA10(void*,void*);void ov49_0225EA40(void*,void*);void ov49_0225EA70(u8*,void*);void ov49_0225EAB4(u8*,void*);void ov49_0225EAE0(u8*,void*);

void ov49_0225EA10(void*a,void*b){u32 v=ov49_0225D1C0(b);if(v!=11&&v!=12)GF_AssertFail();if(v-11<=1)ov49_0225D214(a,b,1,0);}

void ov49_0225EA40(void*a,void*b){u32 v=ov49_0225D1C0(b);if(v!=11&&v!=12)GF_AssertFail();if(v-11<=1)ov49_0225D214(a,b,0,2);}

void ov49_0225EA70(u8*p,void*b){u32 f=0;if(!ov49_0225D3BC(*(void**)(p+4),b,0))f=1;else if(ov49_0225D470(b,0)>0x2000)f=1;if(f==1){ov49_0225EAE0(p,b);PlaySE(0x5bc);}}

void ov49_0225EAB4(u8*p,void*b){u32 f=0;if(!ov49_0225D3BC(*(void**)(p+4),b,0))f=1;if(f==1){ov49_0225EAE0(p,b);PlaySE(0x5c0);}}

void ov49_0225EAE0(u8*p,void*b){s32 i;for(i=0;i<3;i++)ov49_0225D214(*(void**)(p+4),b,i,1);}
