#ifndef UNK_02088894_PRIVATE_H
#define UNK_02088894_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "filesystem.h"
#include "message_format.h"
#include "message_printer.h"
#include "msgdata.h"
#include "pm_string.h"
#include "unk_0201956C.h"

typedef struct SummaryInputData {
    u8 pad00[8];
    const u16 *presetName;
} SummaryInputData;

typedef struct SummaryTextWork {
    BgConfig *bgConfig;
    u8 pad004[0x228];
    SummaryInputData *input;
    String *string230;
    String *string234;
    String *string238;
    u8 pad23C[0x560];
    MessagePrinter *printer;
    MsgData *msgData300;
    MsgData *msgData424;
    MessageFormat *msgFormat;
    String *string7AC;
    String *string7B0;
    MsgData *msgData750;
    u8 pad7B8[0x18];
    UnkStruct_0201956C *cellManager;
} SummaryTextWork;

void sub_02088894(SummaryTextWork *);
void sub_0208895C(SummaryTextWork *);
void sub_020889D0(SummaryTextWork *, NARC *);

#endif
