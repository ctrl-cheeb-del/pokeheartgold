#include "overlay83_ui_r39_38_private.h"

void ov83_02245D08(u8 *work, void *window, void *msgData, int msgNo, int x, int y, int color, int a, int b) {
    void *string = NewString_ReadMsgData(msgData, msgNo);

    StringExpandPlaceholders(PTR_AT(work, 0x24), PTR_AT(work, 0x28), string);
    ov83_02247998(window, PTR_AT(work, 0x28), x, y, color, a, b);
    String_Delete(string);
}

void ov83_02245D48(u8 *work) {
    void *mon;
    BOOL lock;
    u16 i;
    u16 ppUps;
    u8 *moveSlot;
    u8 *byteSlot;

    mon = Party_GetMonByIndex(PTR_AT(work, 0x55C), ov83_02247768(work[0x14], work[0xD]));
    lock = AcquireMonLock(mon);
    PTR_AT(work, 0x5BC) = mon;
    PTR_AT(work, 0x5C0) = Mon_GetBoxMon(mon);
    U16_AT(work, 0x5C4) = GetMonData(mon, 5, NULL);
    U8_AT(work, 0x5C7) = GetMonData(mon, 0xA1, NULL);
    U8_AT(work, 0x5C8) = GetMonData(mon, 0xA, NULL);
    U8_AT(work, 0x5C9) = GetMonNature(mon);
    U16_AT(work, 0x5CA) = GetMonData(mon, 6, NULL);
    U16_AT(work, 0x5D0) = GetMonData(mon, 0xA3, NULL);
    U16_AT(work, 0x5D2) = GetMonData(mon, 0xA4, NULL);
    U16_AT(work, 0x5D4) = GetMonData(mon, 0xA5, NULL);
    U16_AT(work, 0x5D6) = GetMonData(mon, 0xA8, NULL);
    U16_AT(work, 0x5D8) = GetMonData(mon, 0xA6, NULL);
    U16_AT(work, 0x5DA) = GetMonData(mon, 0xA9, NULL);
    U16_AT(work, 0x5DC) = GetMonData(mon, 0xA7, NULL);
    U8_AT(work, 0x5DE) = GetMonData(mon, 0x70, NULL);
    U32_AT(work, 0x5CC) = GetMonData(mon, 0, NULL);

    if (GetMonData(mon, 0xB0, NULL) == 1) {
        ((Ov83R39Flags *)(work + 0x5C6))->flag = 0;
    } else {
        ((Ov83R39Flags *)(work + 0x5C6))->flag = 1;
    }
    ((Ov83R39Flags *)(work + 0x5C6))->gender = GetMonGender(mon);

    for (i = 0; i < 4; i++) {
        moveSlot = work + i * 2;
        U16_AT(moveSlot, 0x5E0) = GetMonData(mon, i + 0x36, NULL);
        byteSlot = work + i;
        U8_AT(byteSlot, 0x5E8) = GetMonData(mon, i + 0x3A, NULL);
        ppUps = GetMonData(mon, i + 0x3E, NULL);
        U8_AT(byteSlot, 0x5EC) = GetMoveMaxPP(U16_AT(moveSlot, 0x5E0), ppUps);
    }
    ReleaseMonLock(mon, lock);
}

void ov83_02245F24(u8 *work) {
    FillWindowPixelBuffer(work + 0x130, 0);
    FillWindowPixelBuffer(work + 0x150, 0);
    FillWindowPixelBuffer(work + 0x170, 0);
    FillWindowPixelBuffer(work + 0x190, 0);
    FillWindowPixelBuffer(work + 0x1B0, 0);
    FillWindowPixelBuffer(work + 0x1D0, 0);
    FillWindowPixelBuffer(work + 0x1F0, 0);
    FillWindowPixelBuffer(work + 0x210, 0);
    FillWindowPixelBuffer(work + 0x230, 0);
    FillWindowPixelBuffer(work + 0x250, 0);
    ov83_022479E4(work + 0x130, PTR_AT(work, 0x20), 0x42, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x150, PTR_AT(work, 0x20), 0x34, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x170, PTR_AT(work, 0x20), 0x32, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x190, PTR_AT(work, 0x20), 0x30, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x1B0, PTR_AT(work, 0x20), 0x43, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x1D0, PTR_AT(work, 0x20), 0x36, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x1F0, PTR_AT(work, 0x20), 0x3A, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x210, PTR_AT(work, 0x20), 0x38, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x230, PTR_AT(work, 0x20), 0x3C, 0, 0, 0, 0x10200, 0);
    ov83_022479E4(work + 0x250, PTR_AT(work, 0x20), 0x3E, 0, 0, 0, 0x10200, 0);
    CopyWindowPixelsToVram_TextMode(work + 0x130);
    CopyWindowPixelsToVram_TextMode(work + 0x150);
    CopyWindowPixelsToVram_TextMode(work + 0x170);
    CopyWindowPixelsToVram_TextMode(work + 0x190);
    CopyWindowPixelsToVram_TextMode(work + 0x1B0);
    CopyWindowPixelsToVram_TextMode(work + 0x1D0);
    CopyWindowPixelsToVram_TextMode(work + 0x1F0);
    CopyWindowPixelsToVram_TextMode(work + 0x210);
    CopyWindowPixelsToVram_TextMode(work + 0x230);
    CopyWindowPixelsToVram_TextMode(work + 0x250);
}
