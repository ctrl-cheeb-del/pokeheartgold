#ifndef OV82_RESIDUAL6_R40_PRIVATE_H
#define OV82_RESIDUAL6_R40_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "message_format.h"
#include "msgdata.h"
#include "pm_string.h"
#include "text.h"

typedef struct Ov82Work {
    u8 pad000[0x20];
    MsgData *msgData;
    MessageFormat *messageFormat;
    String *expandedString;
    String *rawString;
    u8 pad030[0x48 - 0x30];
    BgConfig *bgConfig;
    u8 pad04C[0x220 - 0x4C];
    NARC *narc;
} Ov82Work;

void ov82_0223EE6C(Ov82Work *work, u32 bgLayer);
void ov82_0223EECC(Ov82Work *work, u32 bgLayer);
u8 ov82_0223EF1C(Ov82Work *work, Window *window, u32 messageNo, u32 x, u32 y, u32 speed, u8 foreground, u8 shadow, u8 background, u8 font);

#endif
