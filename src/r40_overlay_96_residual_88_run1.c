#include "r40_overlay_96_residual_88_private.h"

extern void ov96_021EABA8(void *, int);
extern Ov96AnimRecordR40 *ov96_021EB594(void *);
extern void ov96_021EB630(void *, int);
extern int ov96_02207BD8(int);
extern const u8 ov96_0221CAC0[];
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, int);
extern void AddWindow(void *, void *, const void *);
extern void BG_FillCharDataRange(void *, int, int, int, int);
extern void BufferIntegerAsString(void *, int, int, int, int, int);
extern void CopyWindowToVram(void *);
extern void DestroyMsgData(void *);
extern void FillWindowPixelBuffer(void *, int);
extern void LoadFontPal0(int, int, int);
extern void MessageFormat_Delete(void *);
extern void *MessageFormat_New(int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, int, int);
extern void String_Delete(void *);

void ov96_0220764C(u8 *);
void ov96_022076C0(u8 *, int);
void ov96_022076E4(u8 *);
void ov96_02207718(u8 *, int);
void ov96_02207740(u8 *);
void ov96_02207774(u8 *, u16);

void ov96_0220764C(u8 *work) {
    int i;
    u8 *p;

    i = 0;
    p = work;
    for (; i < 10; i++, p += 0x10) {
        int value;
        ov96_021EB630(R40_PTR(p, 0x474), 3);
        value = ov96_02207BD8(ov96_021EB594(R40_PTR(p, 0x470))->value / FX32_ONE);
        ov96_021EB630(R40_PTR(p, 0x470), value + 7);
    }

    i = 0;
    p = work;
    for (; i < 20; i++, p += 0xC) {
        int value = ov96_02207BD8(ov96_021EB594(R40_PTR(p, 0x380))->value / FX32_ONE);
        ov96_021EB630(R40_PTR(p, 0x380), value + 1);
    }
}

void ov96_022076C0(u8 *work, int value) {
    int converted = ov96_02207BD8(value);

    ov96_021EB630(R40_PTR(work, 4), converted + 9);
    ov96_021EB630(R40_PTR(work, 8), converted + 8);
}

void ov96_022076E4(u8 *work) {
    int i;
    u8 *p = work;

    for (i = 0; i < 4; i++, p += 4) {
        int value = ov96_02207BD8(ov96_021EB594(R40_PTR(p, 0x35C))->value / FX32_ONE);
        ov96_021EB630(R40_PTR(p, 0x35C), value + 2);
    }
}

void ov96_02207718(u8 *work, int value) {
    int i;
    int converted = ov96_02207BD8(value);

    ov96_021EB630(R40_PTR(work, 0x48), converted + 3);
    for (i = 0; i < 3; i++, work += 4) {
        ov96_021EABA8(R40_PTR(work, 0), converted + 4);
    }
}

void ov96_02207740(u8 *work) {
    AddWindow(*(void **)work, work + 4, ov96_0221CAC0);
    BG_FillCharDataRange(*(void **)work, 3, 0, 1, 0);
    LoadFontPal0(0, 0x1E0, *(int *)(work + 0x14));
}

void ov96_02207774(u8 *work, u16 value) {
    void *msgData;
    void *format;
    void *string;

    FillWindowPixelBuffer(work + 4, 0);
    msgData = NewMsgDataFromNarc(1, 0x1B, 0x135, *(int *)(work + 0x14));
    format = MessageFormat_New(*(int *)(work + 0x14));
    BufferIntegerAsString(format, 0, value, 3, 0, 1);
    string = ReadMsgData_ExpandPlaceholders(format, msgData, 0x9D, *(int *)(work + 0x14));
    AddTextPrinterParameterizedWithColor(work + 4, 4, string, 0, 0, 0xFF, 0xF0E00, 0);
    String_Delete(string);
    MessageFormat_Delete(format);
    DestroyMsgData(msgData);
    CopyWindowToVram(work + 4);
}
