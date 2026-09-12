#include "global.h"

#include "font.h"
#include "heap.h"
#include "message_format.h"
#include "message_printer.h"
#include "pm_string.h"

typedef struct BagWorkTmLabel {
    u8 pad000[0x2EC];
    MessagePrinter *numberPrinter;
    MessageFormat *messageFormat;
    u8 pad2F4[0x5EC - 0x2F4];
    String *tmLabelTemplate;
} BagWorkTmLabel;

void ov15_021FE8C4(BagWorkTmLabel *, u16, u32, u32);

void ov15_021FE8C4(BagWorkTmLabel *work, u16 labelId, u32 unused2, u32 unused3) {
    String *formatted = String_New(10, HEAP_ID_6);
    BufferIntegerAsString(((MessageFormat **)work)[0xBD], 0, labelId, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    StringExpandPlaceholders(((MessageFormat **)work)[0xBD], formatted, work->tmLabelTemplate);
    FontID_String_GetWidth(0, formatted, 0);
    String_Delete(formatted);
}
