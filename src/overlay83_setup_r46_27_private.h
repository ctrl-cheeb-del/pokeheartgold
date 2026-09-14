#ifndef TO46_OV83_R27_PRIVATE_H
#define TO46_OV83_R27_PRIVATE_H
#include "global.h"

#include "palette.h"
#pragma require_prototypes off
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
void ov83_022444C0(void);
void ov83_022444E0(void *);
void ov83_0224465C(void *, int);
void ov83_022446D0(void);
void ov83_02244704(void *, int);
void ov83_0224474C(void);
void ov83_02244780(void *, int);
#endif
