#include "ov41_wave36_private.h"
#define U32(p,o) (*(u32*)((u8*)(p)+(o)))

void ov41_0224A60C(int which,int arg,void*v){u8*p=v;switch(which){case 0:ov41_0224A8B0(p);ov41_0224A918(p,0x680,0,arg);ov41_0224A1DC(p,arg);break;case 1:p+=0x10;ov41_0224A8B0(p);ov41_0224A918(p,0x680,0,arg);ov41_0224A1DC(p,arg);break;case 2:case 3:ov41_0224A1EC(p,which,arg);ov41_0224A1DC(p+which*0x10,arg);break;case 4:if(U32(p,0x60)==1){p+=0x40;ov41_0224A8B0(p);ov41_0224A8D4(p,arg);ov41_0224A918(p,0x5e2,0,arg);ov41_0224A1DC(p,arg);}break;default:GF_AssertFail();break;}}
