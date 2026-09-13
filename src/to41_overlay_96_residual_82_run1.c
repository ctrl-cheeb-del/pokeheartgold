#include "to41_overlay_96_residual_82_private.h"

void ov96_02203310(Ov96CourseUiWork *work) {
    int i;

    AddWindow(work->bgConfig, &work->mainWindow, &ov96_0221C7B0);
    BG_FillCharDataRange(work->bgConfig, (GFBgLayer)3, 0, 1, 0);
    FillWindowPixelBuffer(&work->mainWindow, 0);
    for (i = 0; i < 3; i++) {
        AddWindow(work->bgConfig, &work->windows[i], &ov96_0221C7EC[i]);
        FillWindowPixelBuffer(&work->windows[i], 0);
    }
    BG_FillCharDataRange(work->bgConfig, (GFBgLayer)0, 0, 1, 0);
    LoadFontPal0(0, 0x1E0, work->heapId);
}

void ov96_0220337C(Ov96CourseUiWork *work, u16 value) {
    MsgData *msgData;
    MessageFormat *format;
    String *string;

    FillWindowPixelBuffer(&work->mainWindow, 0);
    msgData = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, NARC_msgdata_msg, 0x135, work->heapId);
    format = MessageFormat_New(work->heapId);
    BufferIntegerAsString(format, 0, value, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    string = ReadMsgData_ExpandPlaceholders(format, msgData, 0xA4, work->heapId);
    AddTextPrinterParameterizedWithColor(&work->mainWindow, 4, string, 0, 0, 0xFF, 0x000F0E00, NULL);
    String_Delete(string);
    MessageFormat_Delete(format);
    DestroyMsgData(msgData);
    CopyWindowToVram(&work->mainWindow);
}

void ov96_022033FC(PokeathlonCourseData *course) {
    Ov96CourseEntryWork *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    int i;

    for (i = 0; i < 12; i++) {
        if (work->entries[i].unk18 != 0) {
            work->entries[i].unk18 = work->entries[i].unk18 - 1;
        }
        if (work->entries[i].unk16 < 120) {
            work->entries[i].unk16 = work->entries[i].unk16 + 1;
        }
        if (work->entries[i].unk18 != 0) {
            work->entries[i].unk19 = 1;
        } else if (work->entries[i].unk16 <= 100) {
            work->entries[i].unk19 = 2;
        } else {
            work->entries[i].unk19 = 0;
        }
    }
}
