#include "ov85_wave31_helpers_private.h"
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))

void ov85_021E7148(void *v){u8*p=v,*base=p+0xC9C,*win=base+0xC;int i;ClearWindowTilemapAndCopyToVram(win);RemoveWindow(win);ov85_021E7350(p);DestroyMsgData((void*)U32(base,4));MessageFormat_Delete((void*)U32(base,8));String_Delete((void*)U32(base,0x6C));i=0;do{String_Delete((void*)U32(p,0x98));i++;p+=4;}while(i<5);}

void ov85_021E7194(void *p,int msgNo){u8*base=(u8*)p+0xC9C,*win=base+0xC;FillWindowPixelBuffer(win,15);DrawFrameAndWindow2(win,1,10,14);FillWindowPixelBuffer(win,15);ReadMsgDataIntoString((void*)U32(base,4),msgNo,(void*)U32(base,0x6C));AddTextPrinterParameterized(win,1,(void*)U32(base,0x6C),0,0,0xFF,0);ScheduleWindowCopyToVram(win);}

void ov85_021E71EC(void *p,int msgNo,int player){u8*base=(u8*)p+0xC9C,*win=base+0xC;void*tmp;BufferPlayersName((void*)U32(base,8),1,sub_02034818(sub_0203769C()));BufferPlayersName((void*)U32(base,8),2,player);tmp=String_New(0x100,0x66);ReadMsgDataIntoString((void*)U32(base,4),msgNo,tmp);StringExpandPlaceholders((void*)U32(base,8),(void*)U32(base,0x6C),tmp);String_Delete(tmp);DrawFrameAndWindow2(win,1,10,14);FillWindowPixelBuffer(win,15);AddTextPrinterParameterized(win,1,(void*)U32(base,0x6C),0,0,0xFF,0);ScheduleWindowCopyToVram(win);}

void ov85_021E7274(void *p,int msgNo,int item){u8*base=(u8*)p+0xC9C,*win=base+0xC;void*tmp;BufferItemName((void*)U32(base,8),0,item);tmp=String_New(0x100,0x66);ReadMsgDataIntoString((void*)U32(base,4),msgNo,tmp);StringExpandPlaceholders((void*)U32(base,8),(void*)U32(base,0x6C),tmp);String_Delete(tmp);DrawFrameAndWindow2(win,1,10,14);FillWindowPixelBuffer(win,15);AddTextPrinterParameterized(win,1,(void*)U32(base,0x6C),0,0,0xFF,0);ScheduleWindowCopyToVram(win);}

void ov85_021E72E8(void *p){u8*w=(u8*)p+0xCA8;ClearFrameAndWindow2(w,1);FillWindowPixelBuffer(w,0);ScheduleWindowCopyToVram(w);}
