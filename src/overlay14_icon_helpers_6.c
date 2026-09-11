#include "overlay14_icon_helpers_private.h"
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define S8(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
typedef struct {u8 pad[0x2FC]; void **sprites[64];} SpriteCtx;
typedef struct {u8 pad[0x4094];u8 ids[64];} IdCtx;

typedef struct {void *sprite;u8 pad[3];u8 counter;u32 scale;} ScaleWork;

void ov14_021F3190(void *p,u32 i,int active){int id=U8((u8 *)p+i,0x4094);if(!active){ov14_021F2A60(p,id,0);ov14_021F2A74(p,id,0x14);return;}if(i<30)ov14_021F2A60(p,id,3);else ov14_021F2A60(p,id,1);ov14_021F2A74(p,id,0x74-2*i);}

void ov14_021F31E0(void *p,int i,u32 which){int id=U8((u8 *)p+i,0x4094);if(which<30)ov14_021F2A60(p,id,3);else ov14_021F2A60(p,id,1);ov14_021F2A74(p,id,0x14);}
