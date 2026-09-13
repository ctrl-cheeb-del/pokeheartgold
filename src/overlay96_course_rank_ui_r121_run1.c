#include "overlay96_course_rank_ui_r121_private.h"

void ov96_022193F8(void *course, u32 number) {
    Ov96RankUiWork *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    void *formatter = OV96_RANK_PTR(work, 0x10);
    void *messages = OV96_RANK_PTR(work, 0x14);
    void *string;

    FillWindowPixelBuffer(work->data + 0x20, 0);
    BufferIntegerAsString(formatter, 0, number, 3, 0, 1);
    string = ReadMsgData_ExpandPlaceholders(formatter, messages, 0xA3, OV96_RANK_PTR(work, 0));
    AddTextPrinterParameterizedWithColor(work->data + 0x20, 4, string, 0, 0, 0xFF, 0x000F0E00, 0);
    String_Delete(string);
    CopyWindowToVram(work->data + 0x20);
}

void ov96_02219460(Ov96RankUiWork *work, void *arg0, u32 flag) {
    Ov96RankUiFlags *arg = (Ov96RankUiFlags *)arg0;
    void *position = OV96_RANK_PTR(work, 4);
    Ov96RankUiWork *base = work;
    s32 height = ((s32 *)position)[2] >> 12;
    u8 *dst = base->data + 0x5F;
    int low;
    u32 status;

    if (height < 30) {
        low = 1;
    } else {
        low = 0;
    }
    if (ov96_0221862C(base)) {
        if (low) {
            status = 1;
        } else {
            status = 0;
        }
    } else {
        status = 3;
    }
    if (flag == 0) {
        *dst = status;
        return;
    }
    if (arg->bit14) {
        if (status <= 1) {
            *dst = 2;
            return;
        }
        if (status == 3) {
            *dst = 4;
            return;
        }
        GF_AssertFail();
        return;
    }
    if (!arg->bit15) {
        *dst = status;
    }
}
