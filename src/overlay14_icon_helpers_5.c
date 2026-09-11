#include "overlay14_icon_helpers_private.h"
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define S8(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
typedef struct {u8 pad[0x2FC]; void **sprites[64];} SpriteCtx;
typedef struct {u8 pad[0x4094];u8 ids[64];} IdCtx;

typedef struct {void *sprite;u8 pad[3];u8 counter;u32 scale;} ScaleWork;

void ov14_021F2F88(u32 i,s16 *x,s16 *y,int mode){if(i<30){*x=(i%6+1)*24;*y=(i/6)*24+48;}else{i-=30;*x=ov14_021F80BC[2*i];*y=ov14_021F80BC[2*i+1]-144;if(mode==2)*x+=152;}}
