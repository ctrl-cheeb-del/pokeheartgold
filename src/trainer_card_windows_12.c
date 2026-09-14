#include "trainer_card_windows_12_private.h"

void ov51_021E6E60(TrainerCardMainState *state) {
    const WindowTemplate *templates = ov51_021E7F48;
    TrainerCardMainState *work = state;
    u8 i = 0;
    Window *windows = (Window *)&work->data[4];
    do {
        AddWindow(*(BgConfig **)work, &windows[i], &templates[i]);
        i++;
    } while (i < 14);
    BG_FillCharDataRange(*(BgConfig **)work, (GFBgLayer)7, 0, 1, 0);
    BG_FillCharDataRange(*(BgConfig **)work, (GFBgLayer)4, 0, 1, 0);
    LoadUserFrameGfx2(*(BgConfig **)work, (GFBgLayer)4, 0x3e1, 13, work->data[0x343d], (enum HeapID)25);
    LoadFontPal0((enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0x1c0, (enum HeapID)25);
    *(YesNoPrompt **)&work->data[0x33c0] = YesNoPrompt_Create((enum HeapID)25);
    ScheduleBgTilemapBufferTransfer(*(BgConfig **)work, 7);
    ScheduleBgTilemapBufferTransfer(*(BgConfig **)work, 4);
}

void ov51_021E6EF0(TrainerCardMainState *state) {
    u8 *base = (u8 *)state;
    u16 i;
    YesNoPrompt_Destroy(*(YesNoPrompt **)&state->data[0x33c0]);
    i = 0;
    base += 4;
    for (; i < 14; i = (u16)(i + 1)) {
        RemoveWindow((Window *)(base + i * 0x10));
    }
}
