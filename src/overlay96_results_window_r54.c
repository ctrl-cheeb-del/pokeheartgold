#include "global.h"

#include "bg_window.h"
#include "font.h"
#include "message_format.h"
#include "msgdata.h"
#include "text.h"

typedef struct Ov96R54WindowWork {
    BgConfig *bgConfig;
    Window window;
    enum HeapID heapId;
} Ov96R54WindowWork;

typedef struct Ov96R54Participant {
    u8 padding[0x28];
    s32 field28;
    s16 field2C;
} Ov96R54Participant;

extern const WindowTemplate ov96_0221BC5C;
extern const u8 *ov96_021E60D8(void *, s32, s32);
extern void ov96_021EAED4(void *, s32, s32, s32, s32);
extern void ov96_021EB06C(void *, s32, s32, s32 *, s32 *);
void ov96_021F2E80(void *, Ov96R54Participant *, void *, s32, s32);
void ov96_021F2EC8(Ov96R54WindowWork *);
void ov96_021F2EFC(Ov96R54WindowWork *, s32);
BOOL ov96_021F2F7C(void *, s32, s32);

void ov96_021F2E80(void *a0, Ov96R54Participant *participant, void *a2, s32 value, s32 a4) {
    if (participant->field28 == value) {
        s32 quotient = value / 3;
        s32 remainder = value % 3;

        if (ov96_021E60D8(a0, quotient, remainder)[2] != 0) {
            ov96_021EAED4(a2, 0, participant->field2C, a4, 0);
        }
    }
}

void ov96_021F2EC8(Ov96R54WindowWork *work) {
    AddWindow(work->bgConfig, &work->window, &ov96_0221BC5C);
    BG_FillCharDataRange(work->bgConfig, GF_BG_LYR_MAIN_3, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, GF_PAL_SLOT_15_OFFSET, work->heapId);
}

void ov96_021F2EFC(Ov96R54WindowWork *work, s32 value) {
    MsgData *msgData;
    MessageFormat *format;
    String *string;

    FillWindowPixelBuffer(&work->window, 0);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 0x135, work->heapId);
    format = MessageFormat_New(work->heapId);
    BufferIntegerAsString(format, 0, value, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(format, msgData, 0x9E, work->heapId);
    AddTextPrinterParameterizedWithColor(&work->window, 4, string, 0, 0, 0xFF, 0xF0E00, NULL);
    String_Delete(string);
    MessageFormat_Delete(format);
    DestroyMsgData(msgData);
    CopyWindowToVram(&work->window);
}

BOOL ov96_021F2F7C(void *object, s32 x, s32 y) {
    s32 outX;
    s32 outY;

    ov96_021EB06C(object, x / FX32_ONE, y / FX32_ONE, &outX, &outY);
    if (outX < 0x10 || outX >= 0xF0 || outY < 0x10 || outY >= 0xB0) {
        return TRUE;
    }
    return FALSE;
}
