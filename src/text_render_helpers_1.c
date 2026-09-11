#include "text_render_helpers_private.h"

void sub_02010F34(int mode,u32 a,int x) {
 if(mode==0){sub_02013424(a,0);return;}sub_02013424(a,1);sub_02013440(a,0x3f,0,0,x);sub_02013488(a,0,0,0,0,0,x);sub_02013468(a,0x20,0,x);
}

void sub_02010F84(u32 a0,u32 a1,u32 a2,u32 a3,int a4,int a5,int a6,int a7,int a8,int a9) {
 if(a9==0){sub_02013220(a1,0,a3,a4);sub_020132A8(a2,0,a4);sub_02013364(a5,a6,a7,a8,a3,a4);return;}
 sub_02013440(a0,a1,0,a3,a4);sub_02013468(a0,a2,0,a4);sub_02013488(a0,a5,a6,a7,a8,a3,a4);
}

void sub_02010FEC(u32 a,int b,int c,int mode) {
 volatile u8 x[4];x[1]=sub_020132E8(b,c);x[3]=x[1];x[0]=sub_0201333C(c);x[2]=x[0];
 if(mode==0){sub_02013220((u32)(x[2] << 27) >> 27,0,b,c);sub_020132A8((u32)(x[3] << 27) >> 27,0,c);return;}
 sub_02013440(a,(u32)(x[2] << 27) >> 27,0,b,c);sub_02013468(a,(u32)(x[3] << 27) >> 27,0,c);
}
