#include "overlay41_input_helpers_private.h"

void ov41_0224A888(void *w){int i;for(i=0;i<5;i++)ov41_02246360(w,i);ov41_02246374(w,0);ov41_02246374(w,1);}

void ov41_0224A8B0(void *w,int i){if(i==0)ov41_0224A270(w);else if(i==2)ov41_0224A258(w);else if(i==1||i==3)ov41_0224A264(w);}

void ov41_0224A8D4(void *w,int i){if(i==0){sub_020136B4(PTR(w,0x10),0,0xf);TextOBJ_SetPaletteNum(PTR(w,0x10),4);}else{if(i==1)sub_020136B4(PTR(w,0x10),0,0x13);if(i==3){sub_020136B4(PTR(w,0x10),0,0x13);TextOBJ_SetPaletteNum(PTR(w,0x10),3);}}}
