#ifndef OVERLAY41_GEOMETRY_R33_PRIVATE_H
#define OVERLAY41_GEOMETRY_R33_PRIVATE_H

#include "global.h"

#define U32_AT(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

extern void ov41_022486F8(void *work);
extern void ov41_02248A6C(void *entry);
extern void ov41_0224888C(void *work, int value);
extern void ov41_022489A8(void *work, void *input);
extern int ov41_02248EF4(void *object);
extern void ov41_02248B48(int value, int *outX, int *outY);
extern void ov41_02249A50(void *object, void *value);
extern void ov41_02248B20(void *work, void *object, int mode, int index);
extern void ov41_02249B44(void *object, int *a, int *b);
extern void ov41_02249B94(void *object, int *a, int *b);
extern void ov41_02249BAC(void *object, int *a, int *b, int *c, int *d);
extern void *memset(void *dest, int value, u32 size);
extern u32 MTRandom(void);

void ov41_022482B8(void *work, int *outX, int *outY);
void ov41_02248400(void *object, int *outX, int *outY);
void ov41_02248488(void *work, void *input);
void ov41_022484C0(void *work);
int ov41_022484E8(int mode, int value, void *object);
void ov41_02248584(int mode, int unused, int *outX, int *outY, int x, int y, void *object);
void ov41_022486C4(void *work, int mode, int index, void *object);

#endif
