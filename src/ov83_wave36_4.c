#include "ov83_wave36_private.h"

int ov83_022448AC(void *p,int msg,int color){int r=ov83_022447E0(p,(u8 *)p+0xc0,msg,1,1,0xff,1,2,0xf,color);ScheduleWindowCopyToVram((u8 *)p+0xc0);return r;}
