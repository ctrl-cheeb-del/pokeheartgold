#include "overlay70_selection_helpers_private.h"

int ov70_02243C8C(void *w){ov70_02241DB4(w,3);ListMenuItems_Delete(PTR(w,0x34));if(S16(w,0x3c)>8)GF_AssertFail();U32(w,0x4c)=ov70_02245F5C[S16(w,0x3c)].a==1?0x13:0x17;return -1;}

int ov70_02243CC8(void *w){ov70_02241DB4(w,3);if(PTR(w,0x18))Sprite_SetDrawFlag(PTR(w,0x18),1);ListMenuItems_Delete(PTR(w,0x34));return S16(w,0x42);}

int ov70_02243CEC(void *w){U32(w,0x48)=0;ov70_02242E58(w);Sprite_SetAnimCtrlSeq(PTR(w,0xc),0x31);u32 i=U32(w,0x48)*2;ov70_02238F9C(PTR(w,0xc),ov70_02245D66[i],ov70_02245D67[i]);U32(w,0x4c)=1;U32(w,0x50)=0x1d;return -1;}

int ov70_02243D28(void *w){int x=ov70_022426F4(w);switch(x){case -2:sub_020198FC(PTR(w,0x1c),0,4,0,4);Sprite_SetDrawFlag(PTR(w,0xc),0);U32(w,0x4c)=3;U32(w,0x50)=0x1e;S8(w,0x44)=-2;break;case -1:break;default:sub_020198FC(PTR(w,0x1c),0,4,0,4);Sprite_SetDrawFlag(PTR(w,0xc),0);U32(w,0x4c)=3;U32(w,0x50)=0x1e;S8(w,0x44)=x;break;}return -1;}

int ov70_02243D90(void *w){ov70_02241DB4(w,1);return S8(w,0x44);}

int ov70_02243DA0(void *w){U32(w,0x48)=0;ov70_02242EE4(w);Sprite_SetAnimCtrlSeq(PTR(w,0xc),0x31);u32 i=U32(w,0x48)*2;ov70_02238F9C(PTR(w,0xc),ov70_02245D80[i],ov70_02245D81[i]);U32(w,0x4c)=1;U32(w,0x50)=0x20;return -1;}
