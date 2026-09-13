#ifndef SOL_R40_UNK_02033FC4_PRIVATE_H
#define SOL_R40_UNK_02033FC4_PRIVATE_H

#include "global.h"

#include "assert.h"

typedef struct LookupTable02033FC4 {
    u8 values[41];
} LookupTable02033FC4;

extern const LookupTable02033FC4 _020F692C;
extern const LookupTable02033FC4 _020F6955;

int sub_02033FC4(u16 index);
int sub_02033FF0(u16 index);

#endif
