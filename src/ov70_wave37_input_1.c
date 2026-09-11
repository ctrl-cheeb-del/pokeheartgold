#include "global.h"
typedef struct Pair{u32 a,b;}Pair;typedef struct Work{u8 pad0[0x34];Pair*items;u8 pad38[0x10];u32 cursor;u8 pad4c[0xe];s16 page;s32 count;}Work;
extern void PlaySE(u32);extern void ov70_02242574(Work*,int);extern void ov70_022427C4(Work*,int);
extern void Sprite_SetAnimActiveFlag(void*,int);extern void Sprite_SetAnimCtrlSeq(void*,int);extern void ov70_022434C0(Work*,int,int);extern int ov70_02242508(int,int);extern void ov70_02243F00(void*,void*,void*,int,int);
int ov70_0224251C(Work*,int);int ov70_02242860(Work*,int);

int ov70_0224251C(Work*w,int input){int idx;switch(input){case 4:return -2;case 5:ov70_02242574(w,-1);return -1;case 6:ov70_02242574(w,1);return -1;}idx=input+w->page*4;if(idx<w->count){PlaySE(0x5dc);return w->items[idx].b;}return -1;}

void ov70_02242574(Work*w,int dir){int last=ov70_02242508(w->count,4)-1,total;if(last==0)return;if(dir<0){PlaySE(0x5e0);Sprite_SetAnimActiveFlag(*(void**)((u8*)w+0x14),1);Sprite_SetAnimCtrlSeq(*(void**)((u8*)w+0x14),0x27);if(w->page!=0)w->page--;else w->page=last;}else{PlaySE(0x5e0);Sprite_SetAnimActiveFlag(*(void**)((u8*)w+0x10),1);Sprite_SetAnimCtrlSeq(*(void**)((u8*)w+0x10),0x26);if(w->page<last)w->page++;else w->page=0;}ov70_022434C0(w,w->page,w->count);total=ov70_02242508(w->count,4);ov70_02243F00(*(void**)((u8*)w+0x1c),*(void**)((u8*)w+0x38),(u8*)*(void**)((u8*)w+4)+0x40,w->page,total);}
