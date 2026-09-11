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

u32 ov86_021E6484(Work*w,u32 which){u32 stat;u32 result;if(which==0)stat=0x66;else stat=0x68;u8 mode=w->data[6];if(mode==3){void*p=Save_Frontier_GetStatic(PTR(w,0x224));result=FrontierSave_GetStat(p,stat,sub_0205C268(stat));}else{void*p=sub_02030AE8(PTR(w,0x224));result=sub_02030AD4(p,10,(u8)(mode+which*4),0);}return (u8)result==1?0x1e:0x1d;}
