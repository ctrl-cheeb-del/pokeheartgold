#include "overlay96_result_helpers_private.h"

void ov96_0220B6EC(u8 *p){if(((U32(p,0x40)<<22)>>24)==3)GF_AssertFail();ov96_0220C578(p,3);}

void ov96_0220B708(u8 *p,int flag){s32 i;if(!p)GF_AssertFail();for(i=0;i<9;i++,p+=4)if(PTR(p,0x10))ManagedSprite_SetAnimateFlag(PTR(p,0x10),flag);}
