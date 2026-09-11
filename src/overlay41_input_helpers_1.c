#include "overlay41_input_helpers_private.h"

void ov41_0224A3E4(void *a,void *b){int i;for(i=0;i<5;i++){ov41_02246388(b,i);ov41_0224639C(b,i);ObjCharTransfer_ResetTransferTasksByResID(i);}ObjPlttTransfer_FreeTaskByID(0);ObjPlttTransfer_FreeTaskByID(1);i=0;{u8 *p=a;do{ov41_0224A1A8(p);i++;p+=0x10;}while(i<4);}sub_02021B5C((u8 *)a+0x54);ov41_0224A1C0((u8 *)a+0x40);sub_020135AC(PTR(a,0x64));TouchHitboxController_Destroy(PTR(a,0x68));PTR(a,0x68)=0;}

void ov41_0224A448(void *w){int key=0xff;if(!PTR(w,0x68))GF_AssertFail();if(U16(w,0x84)){U16(w,0x84)--;ov41_0224A60C(U16(w,0x86),ov41_0224C094[U16(w,0x84)^1],w);return;}u32 keys=U32(gSystem,0x48);if(keys&3)key=4;else if(keys&0x40)key=1;else if(keys&0x80)key=0;else if(keys&0x20)key=2;else if(keys&0x10)key=3;if(key!=0xff){U16(w,0x86)=key;U16(w,0x84)=2;ov41_0224A60C(U16(w,0x86),0,w);}}
