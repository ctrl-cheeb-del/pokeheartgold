#include "overlay81_dispatch_helpers_private.h"

int ov81_02240FA4(void*w,int kind,void*p){int code;if(!ov80_02237254(*((u8*)w+9)))return 0;switch(kind){case 7:code=0x1d;ov81_02241008(w,kind);break;case 8:code=0x1e;ov81_0224102C(w,kind,p);break;case 10:code=0x20;ov81_02241218(w,kind,p);break;}if(sub_02037030(code,(u8*)w+0x3e0,0x3c)==1)return 1;return 0;}

void ov81_02241008(void*w,int n){Save_PlayerData_GetProfile(*(void**)((u8*)w+0x1bc));*(u16*)((u8*)w+0x3e0)=n;}
