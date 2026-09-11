#include "ov49_wave34_windows_private.h"

void ov49_0225C3C0(void *p){int i;u8 *w=(u8 *)p+4;for(i=0;i<5;i++,w+=0x10)FillWindowPixelBuffer(w,0);}

void ov49_0225C3DC(void *p,void *msg,int wi,int id,u8 x,u8 y,int speed){void *s=ov49_0225B388(msg,1,id);AddTextPrinterParameterizedWithColor((u8 *)p+4+wi*0x10,0,s,x,y,0xff,speed,0);}

void ov49_0225C414(void *p,void *msg,int wi,int id,u8 width,u8 y,int speed){void *s=ov49_0225B388(msg,1,id);int x=width-FontID_String_GetWidth(0,s,0);if(x<0)x=0;AddTextPrinterParameterizedWithColor((u8 *)p+4+wi*0x10,0,s,x,y,0xff,speed,0);}

void ov49_0225C460(void *p,int i){ScheduleWindowCopyToVram((u8 *)p+4+i*0x10);}

void ov49_0225C470(void *unused,void *a,void *b){ov49_0225B3C8(a,b,0);}

void ov49_0225C480(void *unused,void *p,void *q){int a=ov45_0222AA84(q);int b=ov45_0222AAA8(q);ov49_0225B408(p,a,0);ov49_0225B418(p,a,b,1);}

void ov49_0225C4B0(void *unused,void *p,u16 *q){int i;for(i=0;i<4;i++)ov49_0225B42C(p,i,q[i]);}
