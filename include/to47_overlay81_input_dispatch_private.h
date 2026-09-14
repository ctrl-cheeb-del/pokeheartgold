#ifndef TO47_OVERLAY81_INPUT_DISPATCH_PRIVATE_H
#define TO47_OVERLAY81_INPUT_DISPATCH_PRIVATE_H

#include "global.h"

#pragma require_prototypes off

#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef struct Ov81InputRecord {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Ov81InputRecord;

void ov81_02241238(int value, int unused, Ov81InputRecord *input, void *work);
void ov81_022412C4(void *work, int index);
void ov81_02241340(void *work, int value);
void ov81_02241364(void *work);
void ov81_02241398(void *work);

#endif
