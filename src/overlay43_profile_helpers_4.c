#include "overlay43_profile_helpers_private.h"

void ov43_0222AB20(void*w,void*a,int b,int heap){void*src=sub_0202C6F4(a);void*p=PlayerProfile_New(heap);Save_Profile_PlayerName_Set(p,sub_0202C254(src,b));BufferPlayersName(*(void**)((u8*)w+0x50),0,p);Heap_Free(p);}

void ov43_0222AB5C(void*w,void*a,int b,int heap){void*p=PlayerProfile_New(heap);void*src=sub_0202C6F4(a);Save_Profile_PlayerName_Set(p,sub_0202C298(src,b));BufferPlayersName(*(void**)((u8*)w+0x50),0,p);Heap_Free(p);}
