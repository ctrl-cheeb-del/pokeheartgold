#include "global.h"

typedef struct Overlay31StateR11 {
    u8 data[0x300];
} Overlay31StateR11;

extern void *ov31_0225E95C(u8 *, void *);
extern void *ov31_0225E9CC(u8 *, void *);
extern void *NewString_ReadMsgData(void *, int);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void String_Delete(void *);
extern void FillWindowPixelBuffer(void *, int);
extern int Options_GetFrame(void *);
extern int Options_GetTextFrameDelay(void *);
extern void LoadUserFrameGfx2(void *, int, int, int, u8, int);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern int AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);

void ov31_0225EA08(Overlay31StateR11 *);
void ov31_0225EA9C(Overlay31StateR11 *);
void ov31_0225EB30(Overlay31StateR11 *);
void ov31_0225EBC4(Overlay31StateR11 *);
void ov31_0225EC58(Overlay31StateR11 *);

#define PTR(state, off) (*(void **)&(state)->data[(off)])

#define PRINT_MESSAGE_BODY(get_string)                                      \
    void *string = (get_string);                                            \
    int frame;                                                              \
    int delay;                                                              \
    StringExpandPlaceholders(PTR(state, 0x154), PTR(state, 0x188), string); \
    String_Delete(string);                                                  \
    FillWindowPixelBuffer(&state->data[0x44], 0xf);                         \
    frame = Options_GetFrame(PTR(state, 0x164));                            \
    LoadUserFrameGfx2(PTR(state, 4), 4, 0x1b5, 5, (u8)frame, 4);            \
    DrawFrameAndWindow2(&state->data[0x44], 1, 0x1b5, 5);                   \
    delay = Options_GetTextFrameDelay(PTR(state, 0x164));                   \
    *((u8 *)PTR(state, 0x14) + 0x280) = AddTextPrinterParameterized(        \
        &state->data[0x44], 1, PTR(state, 0x188), 0, 0, delay, NULL)

void ov31_0225EA08(Overlay31StateR11 *state) {
    PRINT_MESSAGE_BODY(ov31_0225E95C(PTR(state, 0x14), PTR(state, 0x158)));
}

void ov31_0225EA9C(Overlay31StateR11 *state) {
    PRINT_MESSAGE_BODY(ov31_0225E9CC(PTR(state, 0x14), PTR(state, 0x158)));
}

void ov31_0225EB30(Overlay31StateR11 *state) {
    PRINT_MESSAGE_BODY(NewString_ReadMsgData(PTR(state, 0x158), 0x10));
}

void ov31_0225EBC4(Overlay31StateR11 *state) {
    PRINT_MESSAGE_BODY(NewString_ReadMsgData(PTR(state, 0x158), 0x14));
}

void ov31_0225EC58(Overlay31StateR11 *state) {
    AddWindowParameterized(PTR(state, 4), &state->data[0xe4], 4, 0xc, 7, 0xb, 4, 0xc, 0xad);
    AddWindowParameterized(PTR(state, 4), &state->data[0xf4], 4, 0x10, 0xe, 2, 3, 0xc, 0xd9);
    AddWindowParameterized(PTR(state, 4), &state->data[0x104], 4, 0x14, 0xe, 2, 3, 0xc, 0xdf);
    AddWindowParameterized(PTR(state, 4), &state->data[0x114], 4, 0xe, 0x15, 7, 2, 0xc, 0xe5);
    AddWindowParameterized(PTR(state, 4), &state->data[0x124], 4, 1, 0xd, 8, 5, 0xb, 0xf3);
    AddWindowParameterized(PTR(state, 4), &state->data[0x134], 4, 0x17, 0xe, 8, 3, 0xc, 0x11b);
    AddWindowParameterized(PTR(state, 4), &state->data[0x144], 4, 0xc, 1, 0x11, 4, 0xc, 0x133);
    FillWindowPixelBuffer(&state->data[0xe4], 0);
    FillWindowPixelBuffer(&state->data[0xf4], 0);
    FillWindowPixelBuffer(&state->data[0x104], 0);
    FillWindowPixelBuffer(&state->data[0x114], 0);
    FillWindowPixelBuffer(&state->data[0x124], 0);
    FillWindowPixelBuffer(&state->data[0x134], 0);
    FillWindowPixelBuffer(&state->data[0x144], 0xf);
}
