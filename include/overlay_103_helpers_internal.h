#ifndef OV103_PRIVATE_H
#define OV103_PRIVATE_H

#include "global.h"

/* Raw byte-offset accessors: PROVENANCE-safe, no invented struct sizes. */
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define S8AT(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

/* main work struct = 0x2c bytes (OverlayManager_CreateAndGetData(a,0x2c,0x9c)) */
#define W_OPTIONS 0x00
#define W_MAILBOX 0x04
#define W_ARGS    0x08
#define W_SUB     0x0c
#define W_OVLMGR  0x10
#define W_CHILD   0x14
#define W_BRANCH  0x18
#define W_PAGE    0x1c
#define W_COL     0x1e
#define W_SLOT    0x1f
#define W_RET20   0x20
#define W_RET21   0x21
#define W_ITEM    0x22
#define W_OK      0x24
#define W_STATE   0x28

/* sub struct at W_SUB = 0x2f0 bytes (Heap_Alloc(0x9d, 0x2f0)) */
#define S_BGCFG     0x000
#define S_WINSET    0x004
#define S_MSGDATA   0x228
#define S_MSGFMT    0x22c
#define S_STRING    0x230
#define S_FLAG235   0x235
#define S_YESNO     0x238
#define S_YNBRANCH  0x23c
#define S_LISTMENU  0x244
#define S_LISTITEMS 0x248
#define S_SPRSYS    0x250
#define S_SPRMAN    0x254
#define S_SPRITES   0x258
#define S_GRID      0x278
#define S_MAIL      0x27c
#define S_SLOTMAP   0x2cc
#define S_COUNT     0x2e0
#define S_MAXPAGE   0x2e2
#define S_ANIM      0x2e4
#define S_NEXT      0x2ec

#endif
