#include "global.h"
typedef struct Work Work;typedef struct Slot Slot;typedef u32(*GetFn)(void);typedef void*(*AllocFn)(u32,void*,u32);typedef void(*ExecFn)(u32,s32,void*,void*);typedef struct Ops{ExecFn exec;GetFn get;AllocFn alloc;}Ops;struct Slot{u32 active;u32 type;u8 data[0x28];s32 size;void*ptr;};struct Work{Slot slots[8];Ops*ops;void*ctx1;void*ctx2;void*task;};
extern void*Heap_Alloc(u32,u32);extern void Heap_Free(void*);extern void*SysTask_CreateOnVWaitQueue(void(*)(void*,void*),void*,u32);extern void SysTask_Destroy(void*);extern void GF_AssertFail(void);extern void ov96_021E8884(void*,Work*);
Work*ov96_021E883C(Ops*,void*,void*,u32);void ov96_021E8884(void*,Work*);void ov96_021E88FC(Work*);void ov96_021E8914(Work*,u32,void*,s32);void ov96_021E8988(Work*,u32,void*,s32);

Work*ov96_021E883C(Ops*ops,void*a,void*b,u32 heap){Work*w=Heap_Alloc(heap,0x1d0);memset(w,0,0x1d0);w->ops=ops;w->ctx1=a;w->ctx2=b;w->task=SysTask_CreateOnVWaitQueue((void(*)(void*,void*))ov96_021E8884,w,5000);return w;}

void ov96_021E8884(void *task, Work *w){int i;Slot*s;i=0;s=w->slots;for(;i<8;i++,s++){if(s->active==1){if(s->size<=0x26)w->ops[s->type].exec(0,s->size,s->data,w->ctx2);else w->ops[s->type].exec(0,s->size,s->ptr,w->ctx2);memset(s,0,sizeof(Slot));}}}

void ov96_021E88FC(Work*w){SysTask_Destroy(w->task);Heap_Free(w);}

void ov96_021E8914(Work*w,u32 type,void*data,s32 size){int i;Slot*s=NULL;for(i=0;i<8;i++){if(w->slots[i].active==0){s=&w->slots[i];break;}}if(s==NULL)GF_AssertFail();type-=22;if(w->ops[type].get!=NULL){u32 actual=w->ops[type].get();if(actual==size){}else GF_AssertFail();}if(size>0x26)GF_AssertFail();s->type=type;if(size>0)memcpy(s->data,data,size);s->size=size;s->active=1;}

void ov96_021E8988(Work*w,u32 type,void*data,s32 size){int i;Slot*s=NULL;u32 expected;for(i=0;i<8;i++){if(w->slots[i].active==0){s=&w->slots[i];break;}}if(s==NULL)GF_AssertFail();type-=22;expected=w->ops[type].get();if(expected!=0xffff&&expected!=size)GF_AssertFail();if(w->ops[type].alloc!=NULL){void*p=w->ops[type].alloc(0,w->ctx2,size);if(size>0)memcpy(p,data,size);s->ptr=p;}else s->ptr=data;s->type=type;s->size=size;s->active=1;}
