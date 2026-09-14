#ifndef TO45_OV80_E948_PRIVATE_H
#define TO45_OV80_E948_PRIVATE_H

#include "global.h"

#include "message_format.h"
#include "msgdata.h"

#define U8_AT(p, n)  (*(u8 *)((u8 *)(p) + (n)))
#define U16_AT(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define S32_AT(p, n) (*(s32 *)((u8 *)(p) + (n)))
#define PTR_AT(p, n) (*(void **)((u8 *)(p) + (n)))

typedef struct Ov80MenuWorkPrefix {
    void *owner;
    u8 pad04[0x18];
    String *strings[28];
    MsgData *msgData;
    MessageFormat *messageFormat;
    u8 pad94[7];
    u8 count;
} Ov80MenuWorkPrefix;

u32 FontID_String_GetWidth(u32, String *, u32);
void ov80_0222EA74(void *, u32, u16, void *);
u32 ov80_0222EB14(void *);

#endif
