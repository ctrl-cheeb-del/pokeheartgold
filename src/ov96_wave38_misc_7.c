#include "ov96_wave38_misc_private.h"
typedef struct Pair109 {u16 a,b;} Pair109;

void ov96_02214618(void *course){void *data=PokeathlonCourse_GetDataCopyArea(course);ov96_021E8A20((u8 *)data+0xf0);void *p=PokeathlonCourse_GetHeapAllocPtr4(course);u32 v=ov96_02214904(P((R109 *)p,0x750));ov96_021E8318(course,v);ov96_022136A4(p,v);}
