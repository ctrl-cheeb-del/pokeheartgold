#include "global.h"
typedef void BgConfig;
typedef void NARC;
typedef void Options;

typedef struct ObjCharTransferTemplate {
    int maxTasks;
    int sizeMain;
    int sizeSub;
    int heapID;
} ObjCharTransferTemplate;

typedef struct Ov37WorkR2 {
    BgConfig *bgConfig;
    u8 pad04[4];
    void *args;
    u8 pad0C[0x28 - 0x0C];
    void *string28;
    u8 pad2C[0x278 - 0x2C];
    struct {
        u8 data[0x10];
    } windows[8];
} Ov37WorkR2;

extern const ObjCharTransferTemplate ov37_021E7988;
extern void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
extern void LoadFontPal1(int, int, int);
extern u32 GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
extern u32 Options_GetFrame(void *);
extern void LoadUserFrameGfx2(void *, int, int, int, int, int);
extern void LoadUserFrameGfx1(void *, int, int, int, int, int);
extern void ObjCharTransfer_Init(void *);
extern void ObjPlttTransfer_Init(int, int);
extern void ObjCharTransfer_ClearBuffers(void);
extern void ObjPlttTransfer_Reset(void);
extern void AddWindowParameterized(void *, void *, u8, u8, u8, u8, u8, u8, u16);
extern void FillWindowPixelBuffer(void *, int);
extern u32 FontID_String_GetCenterAlignmentX(int, void *, int, int);
extern u8 AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void ov37_021E7478(void *, int, int, void *);

void ov37_021E5F98(Ov37WorkR2 *work, NARC *narc);
void ov37_021E6090(void);
void ov37_021E6418(Ov37WorkR2 *work);

void ov37_021E6418(Ov37WorkR2 *work) {
    int i;
    int x;
    int y;

    AddWindowParameterized(work->bgConfig, &work->windows[6], 0, 2, 1, 0x1B, 4, 0xD, 0x28);
    FillWindowPixelBuffer(&work->windows[6], 0xF);
    AddWindowParameterized(work->bgConfig, &work->windows[5], 1, 1, 2, 0x1E, 0xF, 0, 1);
    FillWindowPixelBuffer(&work->windows[5], 2);
    AddWindowParameterized(work->bgConfig, &work->windows[7], 1, 0x19, 0x15, 7, 2, 0xD, 0x1C3);
    FillWindowPixelBuffer(&work->windows[7], 0);
    AddTextPrinterParameterizedWithColor(&work->windows[7], 1, work->string28, FontID_String_GetCenterAlignmentX(1, work->string28, 0, 0x30) + 2, 0, 0, 0x70100, NULL);
    x = 1;
    y = 3;
    for (i = 0; i < 5; i++) {
        AddWindowParameterized(work->bgConfig, &work->windows[i], 4, 5, (u8)y, 0xA, 2, 0xD, (u16)x);
        FillWindowPixelBuffer(&work->windows[i], 0);
        x += 0x14;
        y += 4;
    }
    ov37_021E7478(&work->windows[0], 0, 0xE0D0F, work);
}
