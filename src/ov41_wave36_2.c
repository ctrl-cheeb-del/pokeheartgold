#include "ov41_wave36_private.h"
#define U32(p,o) (*(u32*)((u8*)(p)+(o)))

void ov41_0224A7E0(u8*p,int i,int a,int b,int c,int d){i*=4;p[i]=b;p+=i;p[2]=a;p[1]=b+d;p[3]=a+c;}

void ov41_0224A7F8(void*v){u8*p=v;int i=0;int a=0x6b,b=0x6a,c=0x69;do{ov41_022462E4(p,(void*)U32(p,0x180),a,0,1,i);ov41_02246328(p,(void*)U32(p,0x180),b,0,i);ov41_02246344(p,(void*)U32(p,0x180),c,0,i);a+=3;b+=3;c+=3;i++;}while(i<5);ov41_02246304(p,(void*)U32(p,0x180),0x68,0,1,3,0);ov41_02246304(p,(void*)U32(p,0x180),0x78,0,1,2,1);}
