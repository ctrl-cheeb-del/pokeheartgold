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

void ov37_021E5F98(Ov37WorkR2 *work, NARC *narc) {
    BgConfig *bgConfig = work->bgConfig;

    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0, 0, 0, 0x40, 0x27);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 1, 4, 0, 0x40, 0x27);
    LoadFontPal1(0, 0x1A0, 0x27);
    LoadFontPal1(4, 0x1A0, 0x27);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 2, bgConfig, 2, 0, 0x2000, TRUE, 0x27);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 4, bgConfig, 2, 0, 0x600, TRUE, 0x27);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 3, bgConfig, 5, 0, 0x2000, TRUE, 0x27);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 5, bgConfig, 5, 0, 0x600, TRUE, 0x27);
    LoadUserFrameGfx2(bgConfig, 0, 1, 0xA, (u8)Options_GetFrame(*(Options **)((u8 *)work->args + 4)), 0x27);
    LoadUserFrameGfx1(bgConfig, 0, 0x1F, 0xB, 0, 0x27);
}

void ov37_021E6090(void) {
    ObjCharTransferTemplate template = ov37_021E7988;

    ObjCharTransfer_Init(&template);
    ObjPlttTransfer_Init(0x14, 0x27);
    ObjCharTransfer_ClearBuffers();
    ObjPlttTransfer_Reset();
}
