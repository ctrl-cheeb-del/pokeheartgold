#include "overlay70_selection_helpers_private.h"

int ov70_02243E74(void *w){ov70_02241DB4(w,2);ListMenuItems_Delete(PTR(w,0x34));return S8(w,0x45);}

void ov70_02243E8C(void *a,void *msg,void *win,int id,int arg,int arg2){void *s=NewString_ReadMsgData(msg,id);ov70_02242FC4(a,win,s,arg,arg2);String_Delete(s);}

void ov70_02243EB8(void *a,void *msg,void *win,int id){void *s=NewString_ReadMsgData(msg,id);AddTextPrinterParameterizedWithColor(win,4,s,0,0,0xff,0xf0e02,0);CopyWindowPixelsToVram_TextMode(win);sub_02019A60(a,0,win);String_Delete(s);}

void ov70_02243F00(void *a,void *msg,void *win,int n,int arg){PrintUIntOnWindow(msg,n+1,2,1,win,0,0);sub_0200CDAC(msg,0,win,0x10,0);PrintUIntOnWindow(msg,arg,2,0,win,0x18,0);CopyWindowPixelsToVram_TextMode(win);sub_02019A60(a,0,win);}

int ov70_02243F54(void *w,int id){u32 z;void *p=ov70_0223F658(0x3d,id,&z);int r=ov70_0224342C(PTR(w,0x30),PTR(w,0x20),z,p);Heap_Free(p);return r;}
