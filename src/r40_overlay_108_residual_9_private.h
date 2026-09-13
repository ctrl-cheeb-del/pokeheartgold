#ifndef R40_OV108_R9_PRIVATE_H
#define R40_OV108_R9_PRIVATE_H
#include "global.h"

#include "list_menu_items.h"
#include "msgdata.h"
typedef struct R40Ov108Work9 {
    u32 heapId;
    u8 pad04[0x300];
    MsgData *msg;
    u8 pad308[0x1AC];
    ListMenuItem *listA;
    ListMenuItem *listB;
} R40Ov108Work9;
void ov108_021E7224(R40Ov108Work9 *);
#endif
