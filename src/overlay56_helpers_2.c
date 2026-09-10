#include "overlay_56_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    u32 v[10];
} BanksConfig;
typedef struct {
    u32 v[4];
} ScreenModes;
typedef struct {
    u32 v[35];
} BgTemplates;
typedef struct {
    u8 padding[0x3ff8];
    volatile u32 irqCheck;
} DtcmLayout;
typedef struct {
    void *bgConfig;
    u32 zero;
    u32 tile;
    u32 palette;
    u8 x;
    u8 y;
    u8 touchMode : 4;
    u8 bgId : 4;
    u8 padding;
} PromptTemplate;
extern const BanksConfig ov56_021E6E58;
extern const u8 ov56_021E6E20[];
extern int (*const ov56_021E6DE4[])(void *);
extern const ScreenModes _021E6DD4;
extern const BgTemplates ov56_021E6E80;

void ov56_021E692C(void *data) {
    Heap_Free(PTR(data, 0x40));
    Heap_Free(PTR(data, 0x3c));
    PaletteData_FreeBuffers(PTR(data, 0x30), 2);
    PaletteData_FreeBuffers(PTR(data, 0x30), 0);
    PaletteData_Free(PTR(data, 0x30));
    PTR(data, 0x30) = 0;
    G2x_SetBlendAlpha_(0x04000050, 0, 0, 0x1f, 0);
}

void ov56_021E696C(void *data) {
    int i;
    u8 *window;
    AddWindowParameterized(PTR(data, 0x18), (u8 *)data + 0x4c, 1, 3, 3, 0x1a, 4, 1, 0x397);
    AddWindowParameterized(PTR(data, 0x18), (u8 *)data + 0x5c, 1, 3, 8, 0x1a, 4, 1, 0x32f);
    AddWindowParameterized(PTR(data, 0x18), (u8 *)data + 0x6c, 1, 3, 0xd, 0x1a, 4, 1, 0x2c7);
    AddWindowParameterized(PTR(data, 0x18), (u8 *)data + 0x7c, 1, 3, 0x14, 8, 2, 1, 0x2b7);
    AddWindowParameterized(PTR(data, 0x18), (u8 *)data + 0x8c, 1, 0x15, 0x14, 8, 2, 1, 0x2a7);
    AddWindowParameterized(PTR(data, 0x18), (u8 *)data + 0x9c, 0, 2, 0x13, 0x1b, 4, 5, 0x23b);
    i = 0;
    window = (u8 *)data + 0x4c;
    do {
        FillWindowPixelBuffer(window, 0);
        if (i < 5) {
            CopyWindowToVram(window);
        }
        i++;
        window += 0x10;
    } while (i < 6);
    PTR(data, 0xac) = YesNoPrompt_Create(U32(data, 0));
}

void ov56_021E6A7C(void *data) {
    int i;
    u8 *window = (u8 *)data;
    YesNoPrompt_Destroy(PTR(data, 0xac));
    i = 0;
    window += 0x4c;
    do {
        ClearWindowTilemapAndCopyToVram(window);
        RemoveWindow(window);
        i++;
        window += 0x10;
    } while (i < 6);
}

void ov56_021E6AA4(void *data) {
    int i;
    int offset;
    u8 *window;
    void *string;
    for (i = 0, offset = 0, window = (u8 *)data + 0x4c; i < 3; i++, offset += 8, window += 0x10) {
        if (MailMsg_IsInit((u8 *)PTR(data, 0x1c) + 0x1e + offset)) {
            string = MailMsg_GetExpandedString((u8 *)PTR(data, 0x1c) + 0x1e + offset, U32(data, 0));
            AddTextPrinterParameterizedWithColor(window, 1, string, 0, 0, 0, 0x10200, 0);
            String_Delete(string);
            CopyWindowToVram(window);
        }
    }
    if (U8(data, 0xc) == 1) {
        int x;
        PTR(data, 0x20) = NewMsgDataFromNarc(1, 0x1b, 0xe9, U32(data, 0));
        string = String_New(0x10, U32(data, 0));
        window = (u8 *)data;
        i = 0;
        window += 0x4c;
        do {
            String_SetEmpty(string);
            ReadMsgDataIntoString(PTR(data, 0x20), i, string);
            x = 0x40 - FontID_String_GetWidth(1, string, 0);
            AddTextPrinterParameterizedWithColor(window + (i + 3) * 0x10, 1, string, x / 2, 2, 0, 0x10200, 0);
            CopyWindowToVram(window + (i + 3) * 0x10);
            i++;
        } while (i < 2);
        String_Delete(string);
    } else {
        AddTextPrinterParameterizedWithColor((u8 *)data + 0x8c, 1, PTR(PTR(data, 0x1c), 0x14), 0, 1, 0, 0x10200, 0);
        CopyWindowToVram((u8 *)data + 0x8c);
    }
}
