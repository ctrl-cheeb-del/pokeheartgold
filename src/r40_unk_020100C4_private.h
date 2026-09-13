#ifndef POKEHEARTGOLD_COMPLEX_BUFFER_CLEAR_R40_H
#define POKEHEARTGOLD_COMPLEX_BUFFER_CLEAR_R40_H
#include "global.h"
typedef struct ComplexBufferR40 {
    u8 head[0x14];
    u8 block14[0x30];
    u8 block44[0x30];
    u8 small74[0x18];
    u8 tail8C[0xC0];
} ComplexBufferR40;
#endif
