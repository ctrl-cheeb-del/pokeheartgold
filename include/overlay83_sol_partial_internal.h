#ifndef OVERLAY_83_SOL_PRIVATE_H
#define OVERLAY_83_SOL_PRIVATE_H

#include "global.h"

typedef struct Ov83SpriteWrap {
    s16 x;
    s16 y;
    void *sprite;
} Ov83SpriteWrap;

typedef struct Ov83PromptWrap {
    void *prompt;
    u32 active;
    void *bgConfig;
} Ov83PromptWrap;

/* Generated integration prototypes. */
u32 ov83_02247768(u32 unused, u32 value);
void ov83_02247A20(void);
u32 ov83_0224037C(void *p);
u32 ov83_022403B8(void *p);
void ov83_02240DA8(u8 *p, u32 *out, u32 value);
u32 ov83_02244A88(void *p);
u32 ov83_02244A90(void *p);
u32 ov83_02244CCC(void *p);
void ov83_02244CD4(u8 *p, u32 *out, u32 value);
void ov83_022477E4(u32 *p);
void ov83_02247A18(void *p);
void ov83_02247CC4(void *p);
void ov83_02247CE8(void *p);
void ov83_022402F4(u8 *p);
void ov83_02240C60(u8 *p, int field, void *mon);
void ov83_02241504(u8 *p);
u32 ov83_02242AB4(u8 *p, u32 a, u32 b);
u32 ov83_02242AE0(void *p, int value);
void ov83_02244AB0(u8 *p, int field, void *mon);
void ov83_02244C4C(u8 *p);
int ov83_02245068(int value);
void ov83_02245248(u8 *p);
void ov83_022459A0(void);
u32 ov83_022469D8(u8 *p, u32 a, u32 b);
void ov83_0224755C(Ov83SpriteWrap *p, int draw);
void ov83_02247600(Ov83SpriteWrap *p, int value);
int ov83_02247624(Ov83SpriteWrap *p);
void ov83_02247858(Ov83PromptWrap *p);
void *ov83_02247CB8(void);
void ov83_022414CC(u8 *p, u16 value);
void ov83_0224152C(void *a, void *b);
void ov83_02245210(u8 *p, u16 value);
u8 ov83_0224776C(u8 subtrahend, u8 value);
void ov83_02247988(u16 *a, u16 *b);
void ov83_02240334(u8 *p);
void ov83_02240514(u8 *p);
void ov83_02241354(void *window);
void ov83_0224175C(u8 *p);
void ov83_02242894(u32 value, u16 *x, u16 *y);
void ov83_02242F18(u8 *p, u16 value);
void ov83_02244A74(u8 *p);
void ov83_02244C88(u8 *p);
void ov83_02245094(void *window);
void ov83_02245824(u8 *p);
void ov83_022475EC(Ov83SpriteWrap *p, int species);
void ov83_022477B0(int value, int seq);
void ov83_02247844(Ov83PromptWrap *p);
void ov83_02240C48(u8 *p, int field, int value, int digits, int mode);
void ov83_02241B18(u8 *p);
void ov83_02244A98(u8 *p, int field, int value, int digits, int mode);
void ov83_02245270(u8 *p, int value);
void ov83_02245300(u8 *p, int value);
void ov83_022475D4(Ov83SpriteWrap *p, int seq);
void ov83_0224760C(Ov83SpriteWrap *p, int value);
void ov83_02247B04(void *p);
void ov83_02247B1C(void *p, int a, int b);
void ov83_02247B34(void *p, int a, int b);
void ov83_02247B4C(void *p, int a, int b);
void ov83_02247B64(void *p, int a, int b);
void ov83_02241510(int value, int unused, u16 *src, u8 *p);
void ov83_02244ABC(u8 *p, int field);
void ov83_02245254(int value, int unused, u16 *src, u8 *p);
void ov83_022453C0(u8 *p);
void ov83_0224691C(void *p, int value);
BOOL ov83_02247CF0(void);
void ov83_02240C6C(u8 *p, int field);
void ov83_02242AC0(u8 *p, int unused1, int unused2, int seq);
void ov83_02245074(u8 *p);
void ov83_02245CE8(u8 *p, u32 *a, u32 *b);
int ov83_0224753C(Ov83SpriteWrap *p);
void ov83_022477C4(u32 value, int field);
void ov83_022477EC(int index, int value, u32 *word);
void ov83_022478B4(Ov83PromptWrap *p);
void ov83_02245220(int value, int unused, u16 *src, u8 *p);
void ov83_02245C80(u8 *p);
void ov83_0224791C(void *windows, u32 set);
int ov83_022411B0(int value, u32 choice);
int ov83_022411DC(int value, u32 choice);
void ov83_02241730(u8 *p);
void ov83_0224773C(Ov83SpriteWrap **sprites, u32 count, int mode);
void ov83_02240F7C(u8 *p, u16 *a, u16 *b, u16 *c, u16 *d);
void ov83_02244DF4(u8 *p, u16 *a, u16 *b, u16 *c, u16 *d);
void ov83_02244C58(u8 *p);
void ov83_02244C9C(u8 *p);
void ov83_02245390(u8 *p);
void ov83_02240080(u8 *p, void *window);
void ov83_02240170(u8 *p, void *window);
void ov83_022412A0(u8 *p);
void ov83_0224517C(u8 *p, u16 value, u16 selected);
void ov83_02245CA8(u8 *p, u8 index);
int ov83_0223F010(u8 *p);
int ov83_02243DE8(u8 *p);
void ov83_0223E10C(u8 *p);
void ov83_022433B8(u8 *p);
void ov83_0224780C(u32 *flags);
int ov83_0223DFBC(void *manager);
void ov83_0223F1C8(void);
void ov83_02243F9C(void);
void ov83_0224143C(u8 *p, u16 value, u16 selected);
void ov83_02245104(u8 *p, u16 value);
#endif
