#include "overlay70_selection_helpers_private.h"

int ov70_02244154(void *w){Far29 *f=(Far29 *)w;if(f->task){SysTask_Destroy(f->task);f->task=0;f->value=0;}ov70_022446A8(w);ov70_02244644(w);ov70_02244290(PTR(w,4));f->value=0;ov70_02238E58(w);if(PTR(w,0x14)==0)return 5;return 1;}
