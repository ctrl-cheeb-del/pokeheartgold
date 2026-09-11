#include "overlay81_ui_helpers_private.h"

void ov81_02241CEC(void*w){int x,y;ov81_02241CA0(w,&x,&y);ov81_02242D94(*(void**)((u8*)w+0x390),x,y);}

int ov81_02241D0C(void*w){u32 i=0;u8*p=w;u32 v=*(u32*)((u8*)w+0x468);for(;i<3;i++,p+=2)if(v==*(u16*)(p+0x3c8))return i;return *((u8*)w+0x11);}

void ov81_02241D38(void*w){int x,y;u32 i=GridInputHandler_GetNextInput(*(void**)((u8*)w+0x464));if(i>=4)return;if(i==3){ov81_02242D88(*(void**)((u8*)w+0x390),0);return;}ov81_02242D88(*(void**)((u8*)w+0x390),1);ov81_02241C84(i,*(u32*)((u8*)w+0x47c),&x,&y);ov81_02242D94(*(void**)((u8*)w+0x390),x,y);}

void ov81_02241D94(void*w){u32 i=GridInputHandler_GetNextInput(*(void**)((u8*)w+0x464));if(i>=6)return;if(i>=4){ov81_02242D88(*(void**)((u8*)w+0x390),0);return;}ov81_02242D88(*(void**)((u8*)w+0x390),1);ov81_02241EDC(w,*(u16*)((u8*)w+0x3c8),i,0);}
