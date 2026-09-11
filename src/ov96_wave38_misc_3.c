#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

void ov96_022141F8(R109 *w){u8 i=0;do{R109 *x=w+0x7d4+i*16;x[0]=0;x[1]=i;x[2]=0;*(s8 *)(x+3)=-1;P(x,8)=w;P(x,4)=SysTask_CreateOnMainQueue(ov96_02214278,x,1);i++;}while(i<4);}

void ov96_02214234(R109 *w){u8 i=0;do{R109 *x=w+i*16;SysTask_Destroy(P(x,0x7d8));i++;}while(i<4);}
