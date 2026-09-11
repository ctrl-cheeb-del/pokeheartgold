#include "trainer_ai_state_helpers_private.h"

void ov10_0221EC44(void*ctx,void*s){ov10_0221EF24(s,1);if(ov10_0221EE60(ctx,s)!=1)*((u8*)s+0x364)|=1;}

void ov10_0221EC6C(void*x,void*s){int op,value;ov10_0221EF24(s,1);op=ov10_0221EEF0(s);value=ov10_0221EEF0(s);switch(op){case 0:if(*((u8*)s+0x2d74+*((u8*)s+0x3cf)*0xc0)>*((u8*)s+0x2d74+*((u8*)s+0x3d0)*0xc0))ov10_0221EF24(s,value);break;case 1:if(*((u8*)s+0x2d74+*((u8*)s+0x3cf)*0xc0)<*((u8*)s+0x2d74+*((u8*)s+0x3d0)*0xc0))ov10_0221EF24(s,value);break;case 2:if(*((u8*)s+0x2d74+*((u8*)s+0x3cf)*0xc0)==*((u8*)s+0x2d74+*((u8*)s+0x3d0)*0xc0))ov10_0221EF24(s,value);break;}}

void ov10_0221ED10(void*x,void*s){int v,b;ov10_0221EF24(s,1);v=ov10_0221EEF0(s);b=*((u8*)s+0x3d0);if(((AiBits*)((u8*)s+0x2dc8+b*0xc0))->flag)ov10_0221EF24(s,v);}

void ov10_0221ED48(void*x,void*s){int v,b;ov10_0221EF24(s,1);v=ov10_0221EEF0(s);b=*((u8*)s+0x3d0);if(((AiBits*)((u8*)s+0x2dc8+b*0xc0))->flag==0)ov10_0221EF24(s,v);}

void ov10_0221ED80(void*x,void*s){int v;ov10_0221EF24(s,1);v=ov10_0221EEF0(s);if((s32)(*((u8*)s+0x3cf)&1)==(s32)(*((u8*)s+0x3d0)&1))ov10_0221EF24(s,v);}

void ov10_0221EDB4(void*x,void*s){int a,b,target;ov10_0221EF24(s,1);a=ov10_0221EEF0(s);b=ov10_0221EEF0(s);target=ov10_0221EF34(s,(u8)a);if(*(u32*)((u8*)s+target*0xc0+0x2dc8)>>31)ov10_0221EF24(s,b);}

void ov10_0221EDF8(void*x,void*s){int v,b;ov10_0221EF24(s,1);v=ov10_0221EEF0(s);b=ov10_0221EF34(s,(u8)v);*(u32*)((u8*)s+0x35c)=GetBattlerAbility(s,b);}

void ov10_0221EE28(void*x,void*s,int value){u8 i=*((u8*)s+0x3cc);*((u8*)s+0x3cc)=i+1;*(u32*)((u8*)s+0x3ac+i*4)=*(u32*)((u8*)s+0x2138);ov10_0221EF24(s,value);if(*((u8*)s+0x3cc)>8)GF_AssertFail();}

int ov10_0221EE60(void*x,void*s){u8 n=*((u8*)s+0x3cc);if(n!=0){*((u8*)s+0x3cc)=n-1;n=*(volatile u8*)((u8*)s+0x3cc);*(u32*)((u8*)s+0x2138)=*(u32*)((u8*)s+0x3ac+n*4);return 1;}return 0;}
