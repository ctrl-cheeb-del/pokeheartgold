#ifndef OVERLAY41_R50_R19_PRIVATE_H
#define OVERLAY41_R50_R19_PRIVATE_H

#include "global.h"

#define PTR_AT(p, o)  (*(void **)((u8 *)(p) + (o)))
#define PTR_OFS(p, o) ((void *)((u8 *)(p) + (o)))

void ov41_0224BC04(void *work);
void ov41_0224BCA4(void *work);
void ov41_0224BCF0(void *work);
void ov41_0224BD8C(void *work);
void ov41_0224BDCC(void *work);
void ov41_0224BE34(void *work);
void ov41_0224BE5C(void *work);
void ov41_0224BE80(void *work);

#endif
