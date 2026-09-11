#include "global.h"
extern void ov02_0224D700(void*);extern void ov02_0224D788(void*,void*);extern void Field3dObject_Draw(void*);extern void Field3dModel_Unload(void*);extern void Heap_Free(void*);
void ov02_0224D868(u8*);void ov02_0224D914(void*,void*,u8*);void ov02_0224D98C(void*,void*,u8*);

void ov02_0224D98C(void*a,void*b,u8*p){s32 i=0;p+=0x10;do{Field3dObject_Draw(p);i++;p+=0xcc;}while(i<16);}
