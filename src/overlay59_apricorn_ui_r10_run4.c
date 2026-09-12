#include "global.h"

extern u8 gSystem[];
extern const u32 ov59_0223C99C[];
extern const u32 ov59_0223C95C[];
typedef struct BankConfig10 {
    u32 words[10];
} BankConfig10;
extern const BankConfig10 ov59_0223CA68;
extern const u32 ov59_0223CA40[];
extern const u32 ov59_0223CA20[];
extern const u32 ov59_0223C988[];
extern const u32 ov59_0223C968[];

extern void *SaveArray_Party_Get(void *);
extern int Party_GetCount(void *);
extern void *Party_GetMonByIndex(void *, int);
extern int GetMonData(void *, int, void *);
extern void ov59_0223BA64(void *, void *, void *, u8);
extern void ov59_0223BADC(void *);
extern int ov59_0223B3B0(u8 *, int *);
extern int ov59_0223B358(u8 *);
extern void ov59_0223BAE8(void *);
extern void PlaySE(int);
extern void ov59_0223AEB0(void *, int);
extern void ov59_0223BC88(void *, int);
extern int TouchscreenHitbox_FindHitboxAtTouchNew(const void *);
extern int ov59_0223B2B4(u8 *, int);
extern void ov59_0223BBB0(void *);
extern void ov59_0223BBD4(void *, int);
extern int TextPrinterCheckActive(u8);
extern void SpriteSystem_TransferOam(void *);
extern void ov59_0223C374(void *);
extern void GF_RunVramTransferTasks(void);
extern void DoScheduledBgGpuUpdates(void *);
extern void GfGfx_SetBanks(const void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Free(void *);
extern void NARC_Delete(void *);
extern void G2x_SetBlendAlpha_(u32, int, int, int, int);
extern void FontID_Alloc(int, int);
extern void FontID_Release(int);
extern void TextFlags_SetCanABSpeedUpPrint(BOOL);
extern void TextFlags_SetCanTouchSpeedUpPrint(BOOL);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *MessageFormat_New_Custom(int, int, int);
extern void *String_New(int, int);
extern void *NewString_ReadMsgData(void *, int);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void YesNoPrompt_Destroy(void *);
extern void FillWindowPixelBuffer(void *, int);
extern void *YesNoPrompt_Create(int);
extern void *AddWindow(void *, void *, const void *);
extern void *AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
extern void *GF_CreateVramTransferManager(int, int);
extern void *SpriteSystem_Alloc(int);
extern void SpriteSystem_Init(void *, const void *, const void *, int);
extern void thunk_ClearMainOAM(int);
extern void thunk_ClearSubOAM(int);
extern void *SpriteManager_New(void *);
extern void SpriteSystem_InitSprites(void *, void *, int);
extern void sub_0200D2A4(void *, void *, const void *, int, int);
extern void SpriteSystem_DestroySpriteManager(void *, void *);
extern void SpriteSystem_Free(void *);
extern void GF_DestroyVramTransferManager(void);
extern void *NARC_New(int, int);
extern void GfGfxLoader_GXLoadPalFromOpenNarc(void *, int, int, int, int, int);
extern void GfGfxLoader_LoadCharDataFromOpenNarc(void *, int, void *, int, int, int, BOOL, int);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, BOOL, int);
extern void LoadUserFrameGfx2(void *, int, int, int, int, int);
extern void LoadFontPal1(int, int, int);
extern void ReadMsgDataIntoString(void *, int, void *);
extern int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void ScheduleWindowCopyToVram(void *);

void ov59_0223AE20(u8 *);
void ov59_0223AE88(u8 *);
void ov59_0223AF7C(void *);
int ov59_0223B11C(u8 *);
void ov59_0223B3DC(u8 *);
void ov59_0223B414(void);
void ov59_0223B554(u8 *);
void ov59_0223B66C(u8 *);
void ov59_0223B68C(u8 *);
void ov59_0223B6FC(u8 *);
void ov59_0223B7D8(u8 *);
void ov59_0223B804(u8 *);
void ov59_0223B878(u8 *);
void ov59_0223B590(u8 *);
void ov59_0223B740(u8 *);
void ov59_0223AD84(u8 *);

void ov59_0223AD84(u8 *p);
void ov59_0223AE20(u8 *p);
void ov59_0223AE88(u8 *p);
void ov59_0223AF7C(void *p);
int ov59_0223B11C(u8 *p);
int ov59_0223B2B4(u8 *p, int input);
int ov59_0223B358(u8 *p);
int ov59_0223B3B0(u8 *p, int *touched);
void ov59_0223B3DC(u8 *p);
void ov59_0223B414(void);
void ov59_0223B7D8(u8 *p);
void ov59_0223B740(u8 *p);
void ov59_0223B804(u8 *p);
void ov59_0223B878(u8 *p);

void ov59_0223B554(u8 *p) {
    FreeBgTilemapBuffer(*(void **)(p + 0x54), 3);
    FreeBgTilemapBuffer(*(void **)(p + 0x54), 2);
    FreeBgTilemapBuffer(*(void **)(p + 0x54), 1);
    FreeBgTilemapBuffer(*(void **)(p + 0x54), 7);
    Heap_Free(*(void **)(p + 0x54));
    *(vu16 *)0x04000304 |= 0x8000;
}

void ov59_0223B590(u8 *p) {
    void *narc = NARC_New(0xf4, *(u32 *)p);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 5, 0, 0, 0, *(u32 *)p);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 7, *(void **)(p + 0x54), 3, 0, 0, TRUE, *(u32 *)p);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 9, *(void **)(p + 0x54), 3, 0, 0, TRUE, *(u32 *)p);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 4, 4, 0, 0, *(u32 *)p);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 6, *(void **)(p + 0x54), 7, 0, 0, TRUE, *(u32 *)p);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 8, *(void **)(p + 0x54), 7, 0, 0, TRUE, *(u32 *)p);
    *(void **)(p + 0x2e8) = narc;
    LoadUserFrameGfx2(*(void **)(p + 0x54), 1, 1, 0xd, p[0x4c], *(u32 *)p);
    LoadFontPal1(0, 0x180, *(u32 *)p);
    G2x_SetBlendAlpha_(0x04000050, 1, 0xe, 6, 0x1a);
}

void ov59_0223B66C(u8 *p) {
    NARC_Delete(*(void **)(p + 0x2e8));
    G2x_SetBlendAlpha_(0x04000050, 0, 0, 0x1f, 0);
}

void ov59_0223B68C(u8 *p) {
    int i;
    u8 *slot;
    FontID_Alloc(4, *(u32 *)p);
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetCanTouchSpeedUpPrint(TRUE);
    *(void **)(p + 0x5c) = NewMsgDataFromNarc(0, 0x1b, 0x16, *(u32 *)p);
    *(void **)(p + 0x60) = MessageFormat_New_Custom(0x10, 0x10, *(u32 *)p);
    *(void **)(p + 0x64) = String_New(0x100, *(u32 *)p);
    *(void **)(p + 0x68) = String_New(0x100, *(u32 *)p);
    *(void **)(p + 0x6c) = NewString_ReadMsgData(*(void **)(p + 0x5c), 4);
    i = 0;
    slot = p;
    do {
        *(void **)(slot + 0x70) = NewString_ReadMsgData(*(void **)(p + 0x5c), i + 10);
        i++;
        slot += 4;
    } while (i < 2);
}

void ov59_0223B6FC(u8 *p) {
    String_Delete(*(void **)(p + 0x74));
    String_Delete(*(void **)(p + 0x70));
    String_Delete(*(void **)(p + 0x6c));
    String_Delete(*(void **)(p + 0x68));
    String_Delete(*(void **)(p + 0x64));
    MessageFormat_Delete(*(void **)(p + 0x60));
    DestroyMsgData(*(void **)(p + 0x5c));
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    FontID_Release(4);
}
