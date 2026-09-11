#include "overlay14_icon_helpers_private.h"
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define S8(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
typedef struct {u8 pad[0x2FC]; void **sprites[64];} SpriteCtx;
typedef struct {u8 pad[0x4094];u8 ids[64];} IdCtx;

typedef struct {void *sprite;u8 pad[3];u8 counter;u32 scale;} ScaleWork;

void ov14_021F2C1C(void *p,int i,void *src,u32 size){u32 loc=NNS_G2dGetImageLocation(Sprite_GetImageProxy(*((SpriteCtx *)p)->sprites[i]),NNS_G2D_VRAM_TYPE_2DMAIN);DC_FlushRange(src,size);GX_LoadOBJ(src,loc,size);}

void ov14_021F2C50(void *p,int i,void *src,u32 size){u32 loc=NNS_G2dGetImageLocation(Sprite_GetImageProxy(*((SpriteCtx *)p)->sprites[i]),NNS_G2D_VRAM_TYPE_2DSUB);DC_FlushRange(src,size);GXS_LoadOBJ(src,loc,size);}
