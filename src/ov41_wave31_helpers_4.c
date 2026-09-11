#include "ov41_wave31_helpers_private.h"

void ov41_0224A04C(int narc,int file,int target,int dest,int offset,int heap){u8 *e=Heap_Alloc(heap,0x14);memset(e,0,0x14);PTR(e,4)=GfGfxLoader_GetPlttData(narc,file,e,heap);U32(e,8)=target;U32(e,0xc)=dest;U32(e,0x10)=offset;SysTask_CreateOnVWaitQueue(ov41_0224A0D0,e,0x80);}

void ov41_0224A094(void *task,void *e){DC_FlushRange(PTR(PTR(e,4),0x14),U32(PTR(e,4),0x10));BG_LoadCharTilesData(PTR(e,0),U32(e,0xc),PTR(PTR(e,4),0x14),U32(PTR(e,4),0x10),U32(e,0x10));SysTask_Destroy(task);Heap_Free(PTR(e,8));Heap_Free(e);}

void ov41_0224A0D0(void *task,void *e){DC_FlushRange(PTR(PTR(e,0),0xc),U32(e,0x10));if(U32(e,8)==0)GX_LoadBGPltt(PTR(PTR(e,0),0xc),U32(e,0xc),U32(e,0x10));else if(U32(e,8)==4)GXS_LoadBGPltt(PTR(PTR(e,0),0xc),U32(e,0xc),U32(e,0x10));SysTask_Destroy(task);Heap_Free(PTR(e,4));Heap_Free(e);}

void ov41_0224A118(void *out,void *in){if(!out)GF_AssertFail();if(!in)GF_AssertFail();PTR(out,0)=Sprite_CreateAffine(PTR(in,0));if(!PTR(out,0))GF_AssertFail();U32(out,4)=U32(in,0xc);U32(out,8)=U32(in,8);if(PTR(in,4)){PTR(out,0xc)=PTR(in,4);return;}PTR(out,0xc)=ov41_0224A254;}

void ov41_0224A15C(void *out,void *in){u32 t[12];ov41_0224A118(out,in);t[0]=U32(in,0x14);t[1]=U32(in,0x10);t[2]=U32(PTR(in,0),0);t[3]=U32(in,0x18);t[4]=U32(out,0);t[5]=U32(in,0x24);t[6]=U32(in,0x1c);t[7]=U32(in,0x20);t[8]=0;t[9]=0;t[10]=U32(PTR(in,0),0x28);t[11]=U32(PTR(in,0),0x2c);PTR(out,0x10)=sub_020135D8(t);}
