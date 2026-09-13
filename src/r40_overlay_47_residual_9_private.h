#ifndef SOL_R40_NIGHT_OV47_R9_PRIVATE_H
#define SOL_R40_NIGHT_OV47_R9_PRIVATE_H
#include "global.h"
typedef struct {
    u32 values[3];
    u64 total;
} State47;
u32 ov45_0222F544(int);
void ov47_02259D74(State47 *);
#endif
