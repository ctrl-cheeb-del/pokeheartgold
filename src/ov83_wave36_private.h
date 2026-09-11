#ifndef SOL40_R34_PRIVATE_H
#define SOL40_R34_PRIVATE_H
#include "global.h"
#pragma require_prototypes off
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define U16(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define PTR(p,o) (*(void **)((u8 *)(p)+(o)))
void *GfGfxLoader_GetPlttData(int,int,void *,int);
void Heap_Free(void *);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *,int,void *,int,int,int,int,int);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *,int,void *,int,int,int,int,int);
void GfGfxLoader_GXLoadPalFromOpenNarc(void *,int,int,int,int,int);
void ov83_02246E08(void *,void *,u8);
typedef struct { u32 v[10]; } SolBanks;
extern SolBanks ov83_02248150;
void GfGfx_SetBanks(void *);
int ov83_022447E0(void *,void *,int,int,int,int,int,int,int,int);
void ScheduleWindowCopyToVram(void *);
#endif
