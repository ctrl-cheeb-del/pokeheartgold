#include "global.h"
#include "font.h"
#include "msgdata.h"
#include "message_format.h"
#include "pm_string.h"
typedef struct Work {u8 data[0x230];} Work;
#define PTR(w,o) (*(void **)((w)->data+(o)))
extern u8 AddTextPrinterParameterizedWithColor(Window*,u32,String*,u32,u32,u32,u32,void*);
extern void ov86_021E5FD8(Window*,String*,u32,u32,u32,u32,u32);extern u32 ov86_021E6484(Work*,u32);
void ov86_021E5FD8(Window*,String*,u32,u32,u32,u32,u32);void ov86_021E6024(Work*,u32,u32,u32,u32,u32,u32,u32);void ov86_021E6064(Work*,u32,u32,u32,u32,u32,u32,u32);void ov86_021E60B8(Work*);u32 ov86_021E6484(Work*,u32);
extern void ov86_021E6114(Work*);extern void ov86_021E62F4(Work*);extern void ov86_021E64E0(Work*);extern void ov86_021E66D0(Work*);extern void ov86_021E690C(Work*);extern void ov86_021E6A88(Work*);extern void ov86_021E6BA8(Work*);
extern void *Save_Frontier_GetStatic(void*);extern u32 sub_0205C268(u32);extern u32 FrontierSave_GetStat(void*,u32,u32);extern void *sub_02030AE8(void*);extern u32 sub_02030AD4(void*,u32,u32,u32);

void ov86_021E5FD8(Window*w,String*s,u32 x,u32 y,u32 font,u32 color,u32 align){if(align==1)x-=FontID_String_GetWidth(font,s,0);else if(align==2)x-=FontID_String_GetWidth(font,s,0)/2;AddTextPrinterParameterizedWithColor(w,font,s,x,y,255,color,NULL);}

void ov86_021E6024(Work*w,u32 wi,u32 msg,u32 x,u32 y,u32 font,u32 color,u32 align){String*s=NewString_ReadMsgData((MsgData*)PTR(w,0x210),msg);ov86_021E5FD8((Window*)(w->data+0x10+wi*16),s,x,y,font,color,align);String_Delete(s);}

void ov86_021E6064(Work*w,u32 wi,u32 msg,u32 x,u32 y,u32 font,u32 color,u32 align){String*s=NewString_ReadMsgData((MsgData*)PTR(w,0x210),msg);StringExpandPlaceholders((MessageFormat*)PTR(w,0x214),(String*)PTR(w,0x218),s);ov86_021E5FD8((Window*)(w->data+0x10+wi*16),PTR(w,0x218),x,y,font,color,align);String_Delete(s);}

void ov86_021E60B8(Work*w){switch(w->data[7]){case 2:case 3:ov86_021E6114(w);ov86_021E62F4(w);break;case 5:ov86_021E64E0(w);break;case 4:ov86_021E66D0(w);break;case 6:ov86_021E690C(w);break;case 1:if(w->data[6]<=1)ov86_021E6A88(w);else ov86_021E6BA8(w);break;default:ov86_021E690C(w);break;}}
