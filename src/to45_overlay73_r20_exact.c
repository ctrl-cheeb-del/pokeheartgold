#include "to45_overlay73_r20_private.h"

void ov73_021E8960(void *task, void *work) {
    if (U32(work, 4) != 0) {
        U8(work, 0x32B) ^= 1;
        if ((U8(work, 0x32B) & 1) == 0) {
            if (U32(work, 0x32C) <= 1) {
                GX_LoadBGPltt((u8 *)work + 0x88 + S16(work, 0x328) * 0x20, 0, 0x20);
            }
            if (U32(work, 0x32C) == 0 || U32(work, 0x32C) == 2) {
                GXS_LoadBGPltt((u8 *)work + 0x88 + S16(work, 0x328) * 0x20, 0, 0x20);
            }
            if (S8(work, 0x32A) == 0) {
                S16(work, 0x328)
                ++;
                if (S16(work, 0x328) >= 0x15) {
                    S16(work, 0x328) = 0x13;
                    S8(work, 0x32A) ^= 1;
                }
            } else {
                S16(work, 0x328)
                --;
                if (S16(work, 0x328) < 0) {
                    S16(work, 0x328) = 1;
                    S8(work, 0x32A) ^= 1;
                }
            }
        }
    }
}

void ov73_021E8A08(void *work) {
    AddWindowParameterized(PTR(work, 4), (u8 *)work + 0xE18, 0, 4, 4, 0x17, 0x10, 0xD, 0xA4);
    FillWindowPixelBuffer((u8 *)work + 0xE18, 0);
    AddWindowParameterized(PTR(work, 4), (u8 *)work + 0xDF8, 0, 0x1A, 0xE, 4, 2, 0xD, 0x94);
    FillWindowPixelBuffer((u8 *)work + 0xDF8, 0xF);
    AddWindowParameterized(PTR(work, 4), (u8 *)work + 0xDE8, 0, 0x1A, 0xE, 4, 2, 0xD, 0x9C);
    FillWindowPixelBuffer((u8 *)work + 0xDE8, 0xF);
    AddWindowParameterized(PTR(work, 4), (u8 *)work + 0xE08, 0, 4, 1, 0x18, 2, 0xD, 0x214);
    FillWindowPixelBuffer((u8 *)work + 0xE08, 0);
    ov73_021EA088((u8 *)work + 0xE08, PTR(work, 0xBE4), 0, 1, 1, 0xF0E00);
    AddWindowParameterized(PTR(work, 4), (u8 *)work + 0xDD8, 0, 2, 0x13, 0x1B, 4, 0xD, 0x28);
    FillWindowPixelBuffer((u8 *)work + 0xDD8, 0xF);
}

void ov73_021E8B20(void *work) {
    RemoveWindow((u8 *)work + 0xDD8);
    RemoveWindow((u8 *)work + 0xE08);
    RemoveWindow((u8 *)work + 0xDE8);
    RemoveWindow((u8 *)work + 0xDF8);
    RemoveWindow((u8 *)work + 0xE18);
}

void ov73_021E8B64(void *work) {
    PTR(work, 0xBE0) = String_New(0xB4, 0x96);
    PTR(work, 0xBE8) = String_New(4, 0x96);
    PTR(work, 0xBEC) = String_New(3, 0x96);
    PTR(work, 0xBE4) = NewString_ReadMsgData(PTR(work, 0xBD4), 0xA);
    PTR(work, 0xBF0) = String_New(0x100, 0x96);
}

void ov73_021E8BBC(void *work) {
    String_Delete(PTR(work, 0xBF0));
    String_Delete(PTR(work, 0xBE4));
    String_Delete(PTR(work, 0xBEC));
    String_Delete(PTR(work, 0xBE8));
    String_Delete(PTR(work, 0xBE0));
}
