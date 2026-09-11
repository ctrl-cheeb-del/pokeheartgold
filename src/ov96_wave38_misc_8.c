#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

void ov96_02214690(R109 *w){Heap_Free(P(w,0x40));MessageFormat_Delete(P(w,0x38));DestroyMsgData(P(w,0x34));RemoveWindow(w+0x14);RemoveWindow(w+0x24);Heap_Free(w);}
