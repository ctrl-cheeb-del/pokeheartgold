#ifndef TO45_OVERLAY41_LIST_INIT_R37_PRIVATE_H
#define TO45_OVERLAY41_LIST_INIT_R37_PRIVATE_H

#include "global.h"

typedef struct Ov41ListNodeR37 {
    void *data;
    u32 type;
    struct Ov41ListNodeR37 *next;
} Ov41ListNodeR37;

typedef struct Ov41ListHolderR37 {
    Ov41ListNodeR37 *list;
    u32 unk_04;
    u32 unk_08;
} Ov41ListHolderR37;

typedef struct Ov41InitInputR37 {
    u8 padding[0x1C];
    u32 value_1C;
    u32 value_20;
    u32 value_24;
} Ov41InitInputR37;

void ov41_022489A8(Ov41ListHolderR37 *holders, const Ov41InitInputR37 *input);
void ov41_022489E4(Ov41ListNodeR37 *sentinel, u32 value);

#endif
