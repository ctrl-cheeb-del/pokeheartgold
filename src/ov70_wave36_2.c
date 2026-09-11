#include "ov70_wave36_private.h"

void ov70_02239B84(R14Work *w,u32 id,u32 speed){ReadMsgDataIntoString(P(w,0xba0),id,P(w,0xbbc));FillWindowPixelBuffer(w+0xf18,15);DrawFrameAndWindow2(w+0xf18,0,1,14);U32(w,0xbf0)=AddTextPrinterParameterized(w+0xf18,1,P(w,0xbbc),0,0,speed,NULL);}

void ov70_02239BDC(R14Work *w,u32 id,u32 speed){ReadMsgDataIntoString(P(w,0xba0),id,P(w,0xbbc));FillWindowPixelBuffer(w+0x1158,15);DrawFrameAndWindow2(w+0x1158,0,1,14);U32(w,0xbf0)=AddTextPrinterParameterized(w+0x1158,1,P(w,0xbbc),0,0,speed,NULL);}

void ov70_02239C34(void *win,void *msg,u32 font,u32 id){void *s=NewString_ReadMsgData(msg,id);AddTextPrinterParameterizedWithColor(win,font,s,0,0,0,0x000a0900,NULL);String_Delete(s);}
