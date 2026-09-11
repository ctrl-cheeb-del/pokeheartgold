#include "ov41_wave31_helpers_private.h"

void ov41_02249F0C(void *task,void *e){U32(e,0x38)--;if((s32)U32(e,0x38)>=0){ScheduleSetBgPosText(PTR(PTR(e,0),0),U32(PTR(e,0),0x1c),2,U32(e,0x3c));ScheduleSetBgPosText(PTR(PTR(e,0),0),U32(PTR(e,0),0x1c),5,U32(e,0x40));}else{ScheduleSetBgPosText(PTR(PTR(e,0),0),U32(PTR(e,0),0x1c),0,U32(e,0x44));ScheduleSetBgPosText(PTR(PTR(e,0),0),U32(PTR(e,0),0x1c),3,U32(e,0x48));ov41_02249C7C(PTR(e,0),(u8 *)e+4);if(PTR(e,0x34))U32(PTR(e,0x34),0)=1;DestroySysTaskAndEnvironment(task);}}
