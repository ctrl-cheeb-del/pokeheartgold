#include "overlay41_accessors_private.h"











typedef struct { void *obj; s32 state; void *arg; void (*cb)(void *, void *); } Ov41Cb;

void ov41_02249CC4(void *p) { BgClearTilemapBufferAndCommit(*(void **)p, (u8)*(u32 *)((u8 *)p+0x1C)); memset(p,0,0x2C); }

void ov41_02249CE0(Ov41Record *dst, const Ov41Record *src) {
    dst->a=src->a; dst->b=src->b; dst->c=src->c;
    dst->d=0; dst->e=0; dst->f=src->d;
}
