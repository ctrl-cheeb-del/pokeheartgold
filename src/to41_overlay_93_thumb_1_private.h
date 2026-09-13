#ifndef OV93_THUMB1_PRIVATE_H
#define OV93_THUMB1_PRIVATE_H

#include "global.h"

/* Raw byte-offset accessors: no invented struct sizes. */
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

/* Event record posted to the queue at +0x176c. Definition carried over
   verbatim from the sibling object overlay_93_thumb_2 (Opus round 5). */
typedef struct Ov93Evt {
    u32 kind;
    union {
        struct {
            u32 a, b, c, d;
        } blob;
        struct {
            u8 b4, b5, b6, b7;
        } b;
        struct {
            u16 h4;
            u8 b6, b7, b8;
        } h;
    } u;
} Ov93Evt; /* sizeof == 0x14 */

/* Two adjacent words at 0x2fd4.  Spelled as struct members (not as a
   pointer-cast macro) so MWCC materialises the displacement per access
   instead of CSE-hoisting the folded address across a call. */
typedef struct Ov93Pend {
    u8 _pad[0x2fd4];
    u32 kind;
    u32 arg;
} Ov93Pend;

/* Big system struct.  Spelling these as struct members (rather than as a
   cast-and-add macro) stops MWCC from CSE-hoisting the folded address —
   the reference materialises the displacement per access. */
typedef struct Ov93Sys {
    u8 _pad0[0x2edc];
    Ov93Evt cur;     /* 0x2edc */
    Ov93Evt pending; /* 0x2ef0 */
    u32 ctr[8];      /* 0x2f04 */
    u32 head;        /* 0x2f24 */
    u32 tail;        /* 0x2f28 */
    u8 _pad1[0x2fc4 - 0x2f2c];
    s32 delay; /* 0x2fc4 */
} Ov93Sys;

typedef struct Ov93Render {
    u8 _pad[0x1454];
    u8 showBg;
    u8 hideBg;
} Ov93Render;

typedef struct Ov93Players {
    u8 _pad[0x2c];
    u8 ids[4];
    u8 count;
} Ov93Players;

typedef struct Ov93Ranks {
    Ov93Players *players;
    u32 selected;
    u32 _unused;
    u32 score[4];
} Ov93Ranks;

#endif
