#ifndef OV96_R122_PRIVATE_H
#define OV96_R122_PRIVATE_H
#include "global.h"
#define U32AT(p,o) (*(u32 *)((u8 *)(p)+(o)))
#define S32AT(p,o) (*(s32 *)((u8 *)(p)+(o)))
#define U16AT(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define U8AT(p,o) (*(u8 *)((u8 *)(p)+(o)))
#define PAT(p,o) (*(void **)((u8 *)(p)+(o)))
typedef struct Ov96SpriteTemplate {
    u32 raw[13];
} Ov96SpriteTemplate;
#endif
