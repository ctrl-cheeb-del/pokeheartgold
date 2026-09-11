#include "overlay96_list_helpers_private.h"

u32 ov96_0220CBC0(R97Item *p){p->v5.b.count++;if(p->v5.b.count>=26)ov96_0220CD84(p,0);return 0;}

u32 ov96_0220CBEC(R97Item *p){p->v5.b.count++;if(p->v5.b.count>=42)ov96_0220CD84(p,0);return 0;}

u32 ov96_0220CC18(R97Item *p){u32 n=p->v5.b.state;u32 x=p->w[1+n];if(((x<<6)>>24)>=8)ov96_0220CD84(p,0);return 0;}
