#include "overlay70_filter_helpers_private.h"

int ov70_0223E59C(void*m){int lock=AcquireBoxMonLock(m);int v=GetBoxMonData(m,6,0);ReleaseBoxMonLock(m,lock);return v==0x70;}

int ov70_0223E5C8(void){void*m=ov70_0223E49C();if(m==0)return 0;if(GetBoxMonData(m,0xac,0)==0)return 0;if(GetBoxMonData(m,0xad,0)!=0)return 2;return 1;}

int ov70_0223E5FC(void*aa,Filter*b){MonKey*a=aa;if(a->species!=b->species)return 0;if(b->form!=3&&b->form!=a->form)return 0;if(a->level==0)return 0;if(b->level!=0&&b->level>a->level)return 0;if(b->max!=0&&b->max<a->level)return 0;return 1;}

int ov70_0223E658(void*m,Filter*f){MonKey a;a.species=GetBoxMonData(m,5,0);a.form=GetBoxMonData(m,0x6f,0)+1;a.level=CalcBoxMonLevel(m);return ov70_0223E5FC(&a,f);}
