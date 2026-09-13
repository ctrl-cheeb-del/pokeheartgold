#include "global.h"

typedef struct Ov111TextWorkR10 {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0C;
    void *string;
    void *unk14;
    void *unk18;
    u8 unk1C[0x10];
    int printerId;
    union {
        u32 raw;
        struct {
            u32 count : 16;
            u32 style : 3;
            u32 special : 1;
            u32 flagsHi : 12;
        } bits;
    } status;
} Ov111TextWorkR10;

extern BOOL TextPrinterCheckActive(u8);
extern void String_Delete(void *);
extern int ov111_021E6A74(void *, void *, void *, void *, void *, int, int, void *, void *);
extern void ov111_021E6B30(void *, void *, void *, void *, int, int, int, int, int, void *);
extern void FillWindowPixelBuffer(void *, int);
extern void sub_0200CE7C(void *, int, int, int, int, void *, int, int);
extern void PrintUIntOnWindow(void *, int, int, int, void *, int, int);
extern void ScheduleWindowCopyToVram(void *);

BOOL ov111_021E6888(Ov111TextWorkR10 *);
void ov111_021E68FC(Ov111TextWorkR10 *, int);
void ov111_021E6934(Ov111TextWorkR10 *, void *, int, int, u8);
void ov111_021E696C(Ov111TextWorkR10 *, void *, int, int, u8, int);
void ov111_021E69A0(Ov111TextWorkR10 *, void *, int, int, BOOL, int);

BOOL ov111_021E6888(Ov111TextWorkR10 *work) {
    if (work->printerId != -1) {
        if (!TextPrinterCheckActive((u8)work->printerId)) {
            work->status.bits.count = 0;
            String_Delete(work->string);
            work->string = NULL;
            work->printerId = -1;
        }
        return TRUE;
    }
    if (work->status.bits.count != 0) {
        if (work->status.bits.special == 1) {
            work->status.bits.count = 0;
            work->status.bits.special = 0;
        } else {
            work->status.bits.count--;
            return TRUE;
        }
    }
    return FALSE;
}

void ov111_021E68FC(Ov111TextWorkR10 *work, int arg) {
    work->printerId = ov111_021E6A74(work->unk00, work->unk1C, &work->string, work->unk08, work->unk0C, arg, (u8)((work->status.raw << 13) >> 29), work->unk18, work->unk14);
}

void ov111_021E6934(Ov111TextWorkR10 *work, void *arg1, int arg2, int arg3, u8 arg4) {
    ov111_021E6B30(work->unk00, arg1, work->unk08, work->unk0C, arg2, (u8)((work->status.raw << 13) >> 29), arg3, arg4, 0x10200, work->unk18);
}

void ov111_021E696C(Ov111TextWorkR10 *work, void *arg1, int arg2, int arg3, u8 arg4, int arg5) {
    ov111_021E6B30(work->unk00, arg1, work->unk08, work->unk0C, arg2, (u8)((work->status.raw << 13) >> 29), arg3, arg4, arg5, work->unk18);
}

void ov111_021E69A0(Ov111TextWorkR10 *work, void *window, int value, int digits, BOOL alternate, int arg5) {
    FillWindowPixelBuffer(window, 0);
    if (alternate) {
        sub_0200CE7C(work->unk04, arg5, value, digits, 1, window, 0, 0);
    } else {
        PrintUIntOnWindow(work->unk04, value, digits, 1, window, 0, 0);
    }
    ScheduleWindowCopyToVram(window);
}
