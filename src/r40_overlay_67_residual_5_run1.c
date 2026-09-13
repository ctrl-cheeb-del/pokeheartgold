#include "r40_overlay_67_residual_5_private.h"

extern u32 FontID_String_GetWidth(int fontId, void *string, int letterSpacing);
extern void AddTextPrinterParameterizedWithColor(void *window, int fontId, void *string, int x, int y, int speed, u32 color, void *callback);
extern void *NewString_ReadMsgData(void *msgData, int messageId);
extern void StringExpandPlaceholders(void *messageFormat, void *destination, void *source);
extern void String_Delete(void *string);

void ov67_021E6118(void *window, void *string, u32 x, int y, int fontId, u32 color, int alignment) {
    if (alignment == 1) {
        x -= FontID_String_GetWidth(fontId, string, 0);
    } else if (alignment == 2) {
        x -= FontID_String_GetWidth(fontId, string, 0) >> 1;
    }
    AddTextPrinterParameterizedWithColor(window, fontId, string, x, y, 0xFF, color, NULL);
}

void ov67_021E6164(u8 *state, int windowIndex, int messageId, u32 x, int y, int fontId, u32 color, int alignment) {
    void *string = NewString_ReadMsgData(*(void **)(state + 0x28), messageId);

    ov67_021E6118(state + 0x6C + windowIndex * 0x10, string, x, y, fontId, color, alignment);
    String_Delete(string);
}

void ov67_021E61A0(u8 *state, int windowIndex, int messageId, u32 x, int y, int fontId, u32 color, int alignment) {
    void *string = NewString_ReadMsgData(*(void **)(state + 0x28), messageId);

    StringExpandPlaceholders(*(void **)(state + 0x2C), *(void **)(state + 0x30), string);
    ov67_021E6118(state + 0x6C + windowIndex * 0x10, *(void **)(state + 0x30), x, y, fontId, color, alignment);
    String_Delete(string);
}
