#include "field_state_dispatch_1_private.h"

void sub_02038EB8(void) {
 int n; sub_0203786C(1); n=ov00_021E5E54(0);
 if(n>=10 && n<20) sub_020381C0(sub_02038EB4,0);
 else if(n<0) sub_020381C0(sub_02038E90,0);
 else if(n==23) sub_020381C0(sub_02038E94,0);
 else if(n==24) { if(_021D4150[0x53]) sub_020381C0(sub_02038E90,0); else sub_020381C0(sub_02038EB0,0); }
 else if(n==21) { if(_021D4150[0x53]) sub_020381C0(sub_02038E90,0); else sub_020381C0(sub_02038EB0,0); }
 if(_021D4150[0x53] && sub_02037454()!=_021D4150[0x4b]) sub_020381C0(sub_02038E90,0);
}

void sub_02038F74(int a,int b,int c) {
 u8 *p=_021D4150; if(p!=0) { if((u32)(a-25)>1)a=-a; *(int *)(p+0x34)=a; *(int *)(_021D4150+0x38)=b; *(int *)(_021D4150+0x3c)=c; }
}

void sub_02038F9C(void) {
 int n=ov00_021E5E54(0);
 if(n>=10 && n<20){sub_020381C0(sub_02038EB4,0);return;} if(n<0){sub_020381C0(sub_02038E90,0);return;} if(n==20){sub_020381C0(sub_02038EB8,0);return;} if(n==21){sub_020381C0(sub_02038EB0,0);return;} if(n==22){sub_020381C0(sub_02038EB4,0);return;} if(n==24)sub_020381C0(sub_02038EB0,0);
}

void sub_0203900C(void) {
 int n=ov00_021E5E54(1); int x,r;
 if(n<0){sub_020381C0(sub_02038E90,0);return;}
 x=sub_02033FC4(_021D4150[0x4e]); r=ov00_021E6D7C(*(s8 *)(_021D4150+0x51),x+1,0);
 switch(r){case 0:sub_0203622C();sub_020381C0(sub_02038F9C,0);return;case -3:sub_020381C0(sub_02038E90,0);break;case -2:case -1:default:break;}
}
