#include "ov49_wave30_direction_private.h"
typedef struct{u32 a;u8 state,timer,kind,flag;} R;

void ov49_0225F1A8(void*w){void*a=ov49_02259FEC(w);void*b=ov49_0225A010(w);int i=ov49_0225A02C(w);void*c=ov49_02259FE8(w);ov45_0222A5E8(c,1);GF_ASSERT(((u16*)a)[3]<4);ov49_0225EF98(b,i,ov49_02269BE0[((u16*)a)[3]],0);}

void ov49_0225F1F0(void*w){int i;int skip=ov49_0225A02C(w);void*ctx=ov49_0225A010(w);for(i=0;i<20;i++)if(skip!=i)ov49_0225EF98(ctx,i,ov49_02269B78,0);}

int ov49_0225F224(int d){int mask;switch(d){case 0:mask=0x40;break;case 1:mask=0x80;break;case 2:mask=0x20;break;case 3:mask=0x10;break;}return (gSystem.input&mask)?1:0;}
