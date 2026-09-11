#include "global.h"
typedef struct Work{u8 d[0xe00];}Work;
#define U32(w,o) (*(u32*)((w)->d+(o)))
#define U8(w,o) ((w)->d[(o)])
extern void ov96_021E8028(Work*,u32);extern void *Save_Pokeathlon_Get(void*);extern void PokeathlonSave_SetUnkDC_AtIndex(void*,u32,u16);extern void *PokeathlonSave_GetUnkDC(void*);extern u32 ov96_021E5F24(Work*);extern void *PokeathlonSave_GetRecordsSolo2(void*);extern BOOL ov96_021E7D30(int,int,u32);extern const u16 ov96_0221A894[];extern const u8 _0221A7D8[];
extern const u8 ov96_0221A95C[][4];extern const u8 ov96_0221A934[][4];extern u32 LCRandom(void);extern void GF_AssertFail(void);extern void ov96_021EAEC8(void*,s32*,s32*);extern void Sprite_SetDrawFlag(void*,u32);extern void Sprite_SetMatrix(void*,VecFx32*);extern BOOL ov96_021EB120(void*);
void ov96_021E7FA8(Work*);void ov96_021E8028(Work*,u32);BOOL ov96_021E8060(u8*);BOOL ov96_021E8084(Work*);BOOL ov96_021E80C4(Work*);void ov96_021E811C(u8*,u32,u8*);void ov96_021E81D8(void*,u8*);

void ov96_021E7FA8(Work*w){switch(U8((Work*)U32(w,0x1f8),0xc)){case 0:ov96_021E8028(w,1);break;case 1:ov96_021E8028(w,2);break;case 2:ov96_021E8028(w,4);break;case 3:ov96_021E8028(w,8);break;case 4:ov96_021E8028(w,0x10);break;case 5:ov96_021E8028(w,0x11);break;case 6:ov96_021E8028(w,0x14);break;case 7:ov96_021E8028(w,6);break;case 8:ov96_021E8028(w,0xa);break;case 9:ov96_021E8028(w,9);break;}}

void ov96_021E8028(Work*w,u32 kind){void*save=Save_Pokeathlon_Get(**(void***)(w->d+0x1f8));u8 i=0;do{PokeathlonSave_SetUnkDC_AtIndex(save,kind,*(u16*)(w->d+0x204+i*0x28));i++;}while(i<3);}

BOOL ov96_021E8060(u8*p){u8 i=0;do{if(*(u16*)(p+6+i*0x2c)==0)return FALSE;i++;}while(i<5);return TRUE;}

BOOL ov96_021E8084(Work*w){void*save=Save_Pokeathlon_Get(**(void***)(w->d+0x1f8));u8 i=0;do{u32 index=*(u16*)(w->d+0x204+i*0x28)-1;u8*data=PokeathlonSave_GetUnkDC(save);if(data[index]==0x1f)return TRUE;i++;}while(i<3);return FALSE;}

BOOL ov96_021E80C4(Work*w){u8 i;u8*records=PokeathlonSave_GetRecordsSolo2(Save_Pokeathlon_Get(**(void***)(w->d+0x1f8)));i=0;do{u16 value=*(u16*)(records+i*0x2c);if(value==0xffff)return FALSE;if(!ov96_021E7D30(ov96_0221A894[i],value,_0221A7D8[i]))return FALSE;i++;}while(i<10);return TRUE;}

void ov96_021E811C(u8*cfg,u32 count,u8*out){u8 kind;BOOL valid=FALSE;out[0]=10;kind=cfg[0xc];if(*(u32*)(cfg+4)==1){switch(kind){case 5:case 6:case 7:case 8:case 9:case 10:valid=TRUE;break;default:GF_AssertFail();break;}}else{switch(kind){case 0:case 1:case 2:case 3:case 4:valid=TRUE;break;default:GF_AssertFail();break;}}if(valid){u8 i;if(kind==10){u8 row=(u8)((s32)LCRandom()%10);for(i=0;i<count;i++)out[i]=ov96_0221A95C[row][i];}else{for(i=0;i<count;i++)out[i]=ov96_0221A934[kind][i];}}}

void ov96_021E81D8(void*unused,u8*obj){s32 y,x;VecFx32 v;ov96_021EAEC8(*(void**)(obj+4),&y,&x);Sprite_SetDrawFlag(*(void**)(obj+8),1);v.z=0;v.x=y<<12;v.y=x<<12;Sprite_SetMatrix(*(void**)(obj+8),&v);if(ov96_021EB120(*(void**)(obj+4)))Sprite_SetDrawFlag(*(void**)(obj+8),1);else Sprite_SetDrawFlag(*(void**)(obj+8),0);}
