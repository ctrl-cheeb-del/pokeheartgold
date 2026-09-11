#include "global.h"
#include "sprite.h"
#include "gf_gfx_planes.h"
void ov52_021E888C(void *);

extern u32 FontID_String_GetWidth(u32,void*,u32);extern u8 AddTextPrinterParameterizedWithColor(void*,int,void*,u32,u32,u32,u32,void*);
u32 ov52_021E8994(void *window, void *string, u32 y, int font, u32 color);

u32 ov52_021E8994(void *window, void *string, u32 y, int font, u32 color){int width=FontID_String_GetWidth(2,string,0);int x=((((u8*)window)[7]<<3)-width)/2;AddTextPrinterParameterizedWithColor(window,font,string,x,y,0xff,color,NULL);return *(u32*)((u8*)window+0xc);}
