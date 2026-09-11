#ifndef TO30_OVERLAY_92_PRIVATE_H
#define TO30_OVERLAY_92_PRIVATE_H

#include "global.h"

#define U8AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

typedef struct Ov92Vec4 {
    u32 v[4];
} Ov92Vec4;

typedef struct Ov92FEE4 {
    u8 pad0[0x21a4];
    u32 flag;
    u8 pad1[0x2af4 - 0x21a8];
    u32 index;
    u32 previous;
    u8 pad2[2];
    s16 timer;
} Ov92FEE4;

typedef struct Ov92E100 {
    u8 pad[0x1fe0];
    u8 window;
} Ov92E100;



/* Generated integration prototypes. */
void ov92_0225C558(void *a, void *b, void *c, void *d);
void ov92_0225C564(int idx, void *unused, const u32 *src, void *p);
void ov92_0225C578(int idx, void *unused, const u32 *src, void *p);
void ov92_0225C584(void);
int ov92_0225C588(void);
int ov92_0225C58C(void);
int ov92_0225C590(void);
int ov92_0225C594(void);
int ov92_0225C598(void);
const void *ov92_0225C59C(void);
int ov92_0225C5A4(void);
void ov92_0225D344(void *p);
int ov92_0225D868(int mask);
void ov92_0225D88C(void *unused, int enabled, u32 value, u32 *dst);
void ov92_0225D894(void *p);
int ov92_0225D8C4(void *p);
void ov92_0225D8D4(void *p);
void ov92_0225D8DC(void *p);
void ov92_0225D970(void *p, void *a, void *b);
void ov92_0225D9A8(void *p, int a, int b);
void ov92_0225DA2C(void *p);
void ov92_0225DDD8(void *p, u16 a, u16 b, u32 c, u32 d, u32 e);
void ov92_0225DEF0(void *p);
void ov92_0225DF0C(void *p, int flag);
void ov92_0225DF28(void *p);
void ov92_0225DF40(void *p);
void ov92_0225E100(void *p);
int ov92_0225E188(const void *window, const void *str);
void ov92_0225E918(void *p);
void ov92_0225E9A8(void *p);
void ov92_0225EB68(void *p);
int ov92_0225EB70(void *p);
void ov92_0225ED60(void *p);
int ov92_0225ED68(void *p);
void ov92_0225ED80(void *p);
void ov92_0225FEB4(void *p);
void ov92_0225FEE4(void *p);
int ov92_0226077C(void *p, u32 value);
void ov92_02260860(void *p, s32 start, s32 end, s32 arg);
void ov92_022610E8(void *p, void *arg);
void ov92_02261E80(void *p);
void ov92_022630E8(void *p);
void ov92_022630F8(Ov92Vec4 *dst, const Ov92Vec4 *src);
float ov92_02263218(const float *p);
void ov92_022632B4(float *dst, const float *src, float divisor);
void ov92_02263824(const void *src, MtxFx43 *dst);
#endif
