#include "overlay41_input_helpers_private.h"

void ov41_0224A580(void *w){ov41_0224A8B0((u8 *)w+0x40,3);ov41_0224A8D4((u8 *)w+0x40,3);ov41_0224A1EC(w,2,3);}

void ov41_0224A5A4(void *w,void *a,void *b){void *base[1]={w};int i=0;u8 *p=w;do{ov41_0224A9BC(p,a,b);i++;p+=0x10;}while(i<4);ov41_0224A9F8((u8 *)base[0]+0x40,a,b);}

void ov41_0224A5D4(void *w,int i,void *a,void *b,void *c){if(!w)GF_AssertFail();if(i<4)ov41_0224A238((u8 *)w+i*0x10,a,b,c);else ov41_0224A238((u8 *)w+0x40,a,b,c);}
