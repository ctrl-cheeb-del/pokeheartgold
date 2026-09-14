#include "global.h"

typedef u8 Ov70R14Work;

extern const u32 ov70_0224526C[];

void FillWindowPixelRect(void *window, u8 fillValue, u8 x, u8 y, u8 width, u8 height);
void CopyWindowToVram(void *window);
void ov70_02239C34(void *window, void *messages, u32 fontId, u32 messageId, u32 unused);
void ov70_02239B00(Ov70R14Work *work);

void ov70_02239B00(Ov70R14Work *work) {
    void *window = work + 0xF58;
    const u32 *messageIds = (const u32 *)((const u8 *)ov70_0224526C + (*(u16 *)(work + 0x36)) * 12);
    int i;

    for (i = 0; i < 3; i++) {
        FillWindowPixelRect(window, 15, 0, 0, 120, 8);
        FillWindowPixelRect(window, 14, 0, 8, 120, 2);
        FillWindowPixelRect(window, 13, 0, 10, 120, 6);
        ov70_02239C34(window, *(void **)(work + 0xBA0), 4, messageIds[i], 0);
        CopyWindowToVram(window);
        window = (u8 *)window + 0x10;
    }
}
