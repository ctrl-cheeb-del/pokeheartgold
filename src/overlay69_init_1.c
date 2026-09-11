#include "overlay69_init_internal.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov69_021E6A8C(u8 *work) {
    void *dest = String_New(0x400, U32(work, 0));
    void *src = String_New(0x400, U32(work, 0));
    AddWindow(PTR(work, 0xC010), work + 0xC054, ov69_021E764C);
    FillWindowPixelRect(work + 0xC054, 0xF, 0, 0, 0xD8, 0x30);
    DrawFrameAndWindow1(work + 0xC054, 0, 0x1D9, 7);
    BufferCountryName(PTR(work, 0xC080), 0, U32(work, 0xC324));
    BufferCityName(PTR(work, 0xC080), 1, U32(work, 0xC324), U32(work, 0xC328));
    ReadMsgDataIntoString(PTR(work, 0xC070), 0xE, src);
    StringExpandPlaceholders(PTR(work, 0xC080), dest, src);
    AddTextPrinterParameterized(work + 0xC054, 0, dest, 0, 0, 0, NULL);
    String_Delete(src);
    String_Delete(dest);
    CopyWindowToVram(work + 0xC054);
}

void ov69_021E6B5C(u8 *work, void *arg, int kind) {
    void *dest = String_New(0x40, U32(work, 0));
    void *src = String_New(0x40, U32(work, 0));
    AddWindow(PTR(work, 0xC010), work + 0xC054, ov69_021E764C);
    FillWindowPixelRect(work + 0xC054, 0xF, 0, 0, 0xD8, 0x30);
    DrawFrameAndWindow1(work + 0xC054, 0, 0x1D9, 7);
    ov69_021E7520(arg, kind, dest, src, U32(work, 0));
    if (kind != 0) {
        AddTextPrinterParameterized(work + 0xC054, 0, src, 0, 0x10, 0xFF, NULL);
    }
    AddTextPrinterParameterized(work + 0xC054, 0, dest, 0, 0, 0, NULL);
    String_Delete(src);
    String_Delete(dest);
    CopyWindowToVram(work + 0xC054);
}
