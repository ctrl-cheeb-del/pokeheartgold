#include "overlay41_ui_helpers_private.h"

void ov41_0224B21C(void *w,void *r){if(PTR(w,0x24))SysTask_Destroy(PTR(w,0x24));if(PTR(w,0x28))SysTask_Destroy(PTR(w,0x28));ov41_0224B084(w,r);ov41_0224AD84(PTR(w,0x18));memset(w,0,0x94);}

void ov41_0224B250(void *w){ov41_0224B310(w);ov41_0224B270(w);ov41_0224B298(w);ov41_0224B450((u8 *)w+0x30);}

void ov41_0224B270(void *w){s32 n=U32(PTR(w,0x2c),0);if(U32(w,0x1c)!=n){U32(w,0x1c)=n;if(n<=10){ov41_0224B374(w,(u8 *)w+0x30);PlaySE(0x682);}}}
