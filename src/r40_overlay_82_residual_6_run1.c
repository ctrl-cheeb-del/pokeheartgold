#include "r40_overlay_82_residual_6_private.h"

void ov82_0223EE6C(Ov82Work *work, u32 bgLayer) {
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 0x81, work->bgConfig, (GFBgLayer)bgLayer, 0, 0, TRUE, (enum HeapID)0x69);
    GfGfxLoader_LoadScrnDataFromOpenNarc(work->narc, 0x82, work->bgConfig, (GFBgLayer)bgLayer, 0, 0, TRUE, (enum HeapID)0x69);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 0xBE, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x20, (enum HeapID)0x69);
}

void ov82_0223EECC(Ov82Work *work, u32 bgLayer) {
    BG_ClearCharDataRange((u8)bgLayer, 0x20, 0, (enum HeapID)0x69);
    GfGfxLoader_LoadCharDataFromOpenNarc(work->narc, 0x85, work->bgConfig, (GFBgLayer)bgLayer, 1, 0, TRUE, (enum HeapID)0x69);
    GfGfxLoader_GXLoadPalFromOpenNarc(work->narc, 0xC0, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0x20, 0x20, (enum HeapID)0x69);
}

u8 ov82_0223EF1C(Ov82Work *work, Window *window, u32 messageNo, u32 x, u32 y, u32 speed, u8 foreground, u8 shadow, u8 background, u8 font) {
    FillWindowPixelBuffer(window, background);
    ReadMsgDataIntoString(work->msgData, messageNo, work->rawString);
    StringExpandPlaceholders(work->messageFormat, work->expandedString, work->rawString);
    return AddTextPrinterParameterizedWithColor(window, (FontID)font, work->expandedString, x, y, speed, MAKE_TEXT_COLOR(foreground, shadow, background), NULL);
}
