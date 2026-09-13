#include "ov96_r109_r3_private.h"

void ov96_0221359C(void *a, s32 *values, void *c, void *d, u8 *out) {
    u8 *indices = ov96_021E60D8(a, c, d);
    *(u16 *)(out + 0x6c) = values[indices[4]];
    *(u16 *)(out + 0x6e) = *(s32 *)((u8 *)values + indices[4] * 4 + 0x14);
    out[0x70] = *(s32 *)((u8 *)values + indices[3] * 4 + 0x28);
    out[0x71] = *(s32 *)((u8 *)values + indices[3] * 4 + 0x28);
    *(s32 *)(out + 0x64) = _s32_div_f(*(s32 *)((u8 *)values + indices[1] * 4 + 0x3c) << 12, 10);
    *(s32 *)(out + 0x68) = _s32_div_f(*(s32 *)((u8 *)values + indices[1] * 4 + 0x50) << 12, 10);
    out[0x72] = *(s32 *)((u8 *)values + indices[0] * 4 + 0x64);
    out[0x73] = indices[4];
    out[0x75] = indices[0];
    out[0x74] = indices[3];
}

void ov96_0221362C(u8 *work) {
    u32 i;
    AddWindow(*(void **)(work + 4), (Window *)(work + 8), &ov96_0221D1F8);
    for (i = 0; (s32)i < 4; i++) {
        AddWindow(*(void **)(work + 4), (Window *)(work + 0x18 + i * sizeof(Window)), &ov96_0221D360[i]);
    }
    BG_FillCharDataRange(*(BgConfig **)(work + 4), GF_BG_LYR_MAIN_3, 0, 1, 0);
    BG_FillCharDataRange(*(BgConfig **)(work + 4), GF_BG_LYR_MAIN_0, 0, 1, 0);
    LoadFontPal0(GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0x1e0, (enum HeapID) * (u32 *)(work + 0x58));
    GfGfxLoader_GXLoadPal((NarcId)0xec, 0x13, GF_PAL_LOCATION_MAIN_BG, (enum GFPalSlotOffset)0x1c0, 0x20, (enum HeapID) * (u32 *)(work + 0x58));
}

void ov96_022136A4(u8 *work, u32 value) {
    MsgData *msg;
    MessageFormat *fmt;
    String *string;
    FillWindowPixelBuffer((Window *)(work + 8), 0);
    msg = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, (NarcId)0x1b, 0x135, (enum HeapID) * (u32 *)(work + 0x58));
    fmt = MessageFormat_New((enum HeapID) * (u32 *)(work + 0x58));
    BufferIntegerAsString(fmt, 0, value, 3, PRINTING_MODE_LEFT_ALIGN, 1);
    string = ReadMsgData_ExpandPlaceholders(fmt, msg, 0xa5, (enum HeapID) * (u32 *)(work + 0x58));
    AddTextPrinterParameterizedWithColor((Window *)(work + 8), 4, string, 0, 0, 0xff, 0xf0e00, NULL);
    String_Delete(string);
    MessageFormat_Delete(fmt);
    DestroyMsgData(msg);
    CopyWindowToVram((Window *)(work + 8));
}
