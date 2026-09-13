#ifndef OV41_RESIDUAL_45_PRIVATE_H
#define OV41_RESIDUAL_45_PRIVATE_H

#include "global.h"

/* Placeholder work struct: word-indexed. Codegen-identical to a named-field
   struct for the word-sized accesses this module makes. */
typedef struct Ov41Work {
    u32 f[512];
} Ov41Work;

#define W(w, off)   ((w)->f[(off) / 4])
#define AT(w, off)  ((void *)((u8 *)(w) + (off)))
#define S16(w, off) (*(s16 *)((u8 *)(w) + (off)))
#define U8F(w, off) (*(u8 *)((u8 *)(w) + (off)))

extern u8 gSystem[];

void PlaySE(u32 seq);
u32 MTRandom(void);

void ov41_022463FC(void);
void ov41_02248020(void *a, void *b);
BOOL ov41_022480A4(void *a, void *b, void *c);
void ov41_02248158(void *a);
int ov41_022481D8(void *a, int x, int y);
void ov41_0224825C(void *a, void *b, int c);
void ov41_022482A8(void *a);
void ov41_022482B8(void *work, int *outX, int *outY);
int ov41_022484E8(int mode, int value, void *object);
int ov41_0224883C(void *a, int x, int y);
int ov41_0224895C(void *a, void *b);
void ov41_0224946C(void *self, int *a, int *b, int *c, int *d);
void ov41_02249480(void *w, int a, int x, int y, void *p, int q);
void ov41_022495A4(void *self, int x, int y);
void ov41_02249A90(void *object, int a);
void ov41_02249AF4(void *object, int x, int y);
void ov41_02249B44(void *object, int *a, int *b);
void ov41_02249B94(void *object, int *a, int *b);
void ov41_02249BAC(void *object, int *a, int *b, int *c, int *d);
void ov41_0224AC08(void *a, int b, int c, int d);

#endif // OV41_RESIDUAL_45_PRIVATE_H
