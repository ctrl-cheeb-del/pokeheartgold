#include "overlay49_message_internal.h"
#pragma require_prototypes off

typedef struct Ov49MsgWork {
    MessageFormat *fmt;
    void *messages[4];
    String *raw;
    String *expanded;
} Ov49MsgWork;
String *ov49_0225B388(Ov49MsgWork *, u32, u32);
void ov49_0225B3A8(Ov49MsgWork *, u32, u32, u32, u32);

void ov49_0225B214(Window *win, void **bg) {
    AddWindowParameterized(*bg, win, 1, 4, 4, 0x17, 0x10, 5, 0x5e);
    FillWindowPixelBuffer(win, 0xf);
}

void ov49_0225B244(Window *win) {
    RemoveWindow(win);
}

void ov49_0225B24C(Window *win, String *str) {
    AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xff, 0x1020f, 0);
    DrawFrameAndWindow1(win, 1, 0x55, 3);
    ScheduleWindowCopyToVram(win);
}

void ov49_0225B284(Window *win, Ov49MsgWork *msg) {
    u32 *pair = sub_020392D8(win);
    u32 value = ov45_0222D7CC(pair[0], pair[1]);
    ov49_0225B3A8(msg, pair[0], 5, 0, 2);
    ov49_0225B24C(win, ov49_0225B388(msg, 2, value));
}

void ov49_0225B2C0(Window *win, Ov49MsgWork *msg, u32 a) {
    u32 value = ov45_0222E7FC(a);
    ov49_0225B3A8(msg, value, 5, 0, 2);
    ov49_0225B24C(win, ov49_0225B388(msg, 2, 0x20));
}

void ov49_0225B2F0(Window *win, Ov49MsgWork *msg) {
    ov49_0225B24C(win, ov49_0225B388(msg, 2, 0xe));
}

void ov49_0225B308(Ov49MsgWork *msg, u32 heap) {
    int i;
    msg->fmt = MessageFormat_New_Custom(8, 0x40, heap);
    for (i = 0; i < 4; i++) {
        msg->messages[i] = NewMsgDataFromNarc(1, 0x1b, ov49_02269714[i], heap);
    }
    msg->raw = String_New(0x1e0, heap);
    msg->expanded = String_New(0x1e0, heap);
}

void ov49_0225B35C(Ov49MsgWork *msg) {
    int i;
    MessageFormat_Delete(msg->fmt);
    for (i = 0; i < 4; i++) {
        DestroyMsgData(msg->messages[i]);
    }
    String_Delete(msg->raw);
    String_Delete(msg->expanded);
}

String *ov49_0225B388(Ov49MsgWork *msg, u32 which, u32 id) {
    ReadMsgDataIntoString(msg->messages[which], id, msg->expanded);
    StringExpandPlaceholders(msg->fmt, msg->raw, msg->expanded);
    return msg->raw;
}

void ov49_0225B3A8(Ov49MsgWork *msg, u32 index, u32 value, u32 mode, u32 digits) {
    BufferIntegerAsString(msg->fmt, mode, index, value, digits, 1);
}

void ov49_0225B3C8(Ov49MsgWork *msg, void *profile, u32 index) {
    BufferPlayersName(msg->fmt, index, profile);
}

void ov49_0225B3D8(Ov49MsgWork *msg, u32 value, u32 index) {
    BufferWiFiPlazaActivityName(msg->fmt, index, value);
}

void ov49_0225B3E8(Ov49MsgWork *msg, u32 value, u32 index) {
    BufferWiFiPlazaEventName(msg->fmt, index, value);
}

void ov49_0225B3F8(Ov49MsgWork *msg, u32 value, u32 index) {
    BufferWiFiPlazaInstrumentName(msg->fmt, index, value);
}

void ov49_0225B408(Ov49MsgWork *msg, u32 value, u32 index) {
    BufferCountryName(msg->fmt, index, value);
}

void ov49_0225B418(Ov49MsgWork *msg, u32 a, u32 b, u32 index) {
    BufferCityName(msg->fmt, index, a, b);
}

void ov49_0225B42C(Ov49MsgWork *msg, u32 a, u32 b) {
    BufferECWord(msg->fmt, a, b);
}

void ov49_0225B438(Ov49MsgWork *msg) {
    MessageFormat_ResetBuffers(msg->fmt);
}
