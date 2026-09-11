#include "ov85_wave31_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E7380(void *p,void*str,int i,u32 color){u8*w=(u8*)p+0xCB8+0x10*i;s32 x;DrawFrameAndWindow1(w,1,1,14);FillWindowPixelBuffer(w,15);x=FontID_String_GetCenterAlignmentX(0,str,0,0x40);AddTextPrinterParameterizedWithColor(w,0,str,x,0,0xFF,color,0);ScheduleWindowCopyToVram(w);}

void ov85_021E73D4(void *p,void *str,void *arg,int who){u32 color=0x10200;if(who==(int)sub_0203769C())color=0x30400;ov85_021E7380(p,str,(int)arg,color);}
