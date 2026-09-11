#include "overlay41_ui_helpers_private.h"

int ov41_0224AD90(void *win,int narc,int file,int msgId,int x,int y,int speed){FillWindowPixelBuffer(win,0xf);int id=ov41_0224AE24(win,narc,file,msgId,x,y,0x1020f,speed);DrawFrameAndWindow2(win,0,1,1);return id;}

int ov41_0224ADD8(void *win,int narc,int file,int msgId,int x,int y,int speed,void **out){FillWindowPixelBuffer(win,0xf);int id=ov41_0224AE78(win,narc,file,msgId,x,y,0x1020f,speed,out);DrawFrameAndWindow2(win,0,1,1);return id;}

int ov41_0224AE24(void *win,int narc,int file,int msgId,int x,int y,int color,int speed){void *m=NewMsgDataFromNarc(0,narc,file,0xd);if(!m)GF_AssertFail();void *str=NewString_ReadMsgData(m,msgId);int id=AddTextPrinterParameterizedWithColor(win,1,str,x,y,speed,color,0);String_Delete(str);DestroyMsgData(m);return id;}

int ov41_0224AE78(void *win,int narc,int file,int msgId,int x,int y,int color,int speed,void **out){if(*out)GF_AssertFail();void *m=NewMsgDataFromNarc(0,narc,file,0xd);if(!m)GF_AssertFail();*out=NewString_ReadMsgData(m,msgId);int id=AddTextPrinterParameterizedWithColor(win,1,*out,x,y,speed,color,0);DestroyMsgData(m);return id;}
