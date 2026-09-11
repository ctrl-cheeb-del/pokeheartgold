#include "overlay14_icon_helpers_private.h"
#define U8(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define S8(p,o) (*(s8 *)((u8 *)(p)+(o)))
#define U32(p,o) (*(u32 *)((u8 *)(p)+(o)))
typedef struct {u8 pad[0x2FC]; void **sprites[64];} SpriteCtx;
typedef struct {u8 pad[0x4094];u8 ids[64];} IdCtx;

typedef struct {void *sprite;u8 pad[3];u8 counter;u32 scale;} ScaleWork;

void ov14_021F3354(void *v){ScaleWork *p=v;p->scale=0x3F800000;p->counter=0;ManagedSprite_SetAffineOverwriteMode(p->sprite,1);ManagedSprite_SetAffineScale(p->sprite,p->scale,p->scale);ManagedSprite_SetAffineTranslation(p->sprite,0,8);}

int ov14_021F3380(void *v){ScaleWork*p=v;p->counter++;p->scale=_fsub(p->scale,0x3CCCCCCD);if(p->counter==40)return 0;ManagedSprite_SetAffineScale(p->sprite,p->scale,p->scale);return 1;}

int ov14_021F33B0(void *v){ScaleWork*p=v;p->counter-=2;p->scale=_fadd(p->scale,0x3CCCCCCD);p->scale=_fadd(p->scale,0x3CCCCCCD);if(p->counter==0)return 0;ManagedSprite_SetAffineScale(p->sprite,p->scale,p->scale);return 1;}
