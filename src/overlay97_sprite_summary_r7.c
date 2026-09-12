#include "global.h"

typedef struct Ov97BgTemplate {
    u32 words[7];
} Ov97BgTemplate;

typedef struct Ov97Work {
    u32 heapId;
    void *bgConfig;
    u8 windows[6][0x10];
    u16 course;
    u16 flag;
    void *msgData;
    void *msgFormat;
    void *string;
    u8 spriteWork[0x400];
} Ov97Work;

typedef struct Ov97SpriteWork {
    u32 heapId;
    void *spriteList;
    u8 pad08[0x118];
    void *resourceManagers[6];
    u8 pad138[0x78];
    void *spritesA[5];
    u8 pad1c4[0x14];
    void *spritesB[5][6];
    void *mainSprites[5];
    u8 pad264[0x10];
    void *specialSprite;
    void *alloc;
} Ov97SpriteWork;

extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void String_Delete(void *);
extern void RemoveWindow(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void Destroy2DGfxResObjMan(void *);
extern void SpriteList_Delete(void *);
extern void Heap_Free(void *);
extern void Sprite_Delete(void *);
extern void ov97_0221F0E0(Ov97SpriteWork *);
extern void GfGfxLoader_GXLoadPal(int, int, int, int, int, int);
extern void GfGfxLoader_LoadCharData(int, int, void *, int, int, int, int, int);
extern void GfGfxLoader_LoadScrnData(int, int, void *, int, int, int, int, int);
extern void BgCommitTilemapBufferToVram(void *, int);
extern void LoadFontPal0(int, int, int);
extern void BufferPokeathlonCourseName(void *, int, int);
extern void *ReadMsgData_ExpandPlaceholders(void *, void *, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void CopyWindowToVram(void *);
extern void *NewString_ReadMsgData(void *, int);
extern void CopyU16ArrayToString(void *, const u16 *);
extern void *GetSpeciesName(int, int);
extern void BufferString(void *, int, void *, int, int, int);
extern void ov97_0221FBDC(void *);
extern void ov97_0221FC54(void *);
extern void Sprite_SetDrawFlag(void *, int);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void GF_AssertFail(void);
extern const u8 ov97_0221FCFC[5];
extern const Ov97BgTemplate ov97_0221FD20;
extern const Ov97BgTemplate ov97_0221FD3C;
extern const Ov97BgTemplate ov97_0221FD04;
extern const Ov97BgTemplate ov97_0221FD58;
extern void InitBgFromTemplate(void *, int, const Ov97BgTemplate *, int);
extern void BgClearTilemapBufferAndCommit(void *, int);

void ov97_0221F020(Ov97Work *work);
void ov97_0221F14C(void *bgConfig, int heapId);
void ov97_0221F1D8(void *bgConfig);
void ov97_0221F294(Ov97Work *work);
void ov97_0221F428(Ov97Work *work, const u8 *record);
void ov97_0221F56C(Ov97Work *work, const u8 *record);
void ov97_0221F5F8(void *spriteWork, const u8 *record);

void ov97_0221F020(Ov97Work *work) {
    u8 i;
    Ov97SpriteWork *spriteWork;

    DestroyMsgData(work->msgData);
    MessageFormat_Delete(work->msgFormat);
    String_Delete(work->string);
    RemoveWindow(work->windows[0]);
    RemoveWindow(work->windows[1]);
    RemoveWindow(work->windows[2]);
    RemoveWindow(work->windows[3]);
    RemoveWindow(work->windows[4]);
    RemoveWindow(work->windows[5]);
    FreeBgTilemapBuffer(work->bgConfig, 4);
    FreeBgTilemapBuffer(work->bgConfig, 5);
    FreeBgTilemapBuffer(work->bgConfig, 6);
    FreeBgTilemapBuffer(work->bgConfig, 7);
    spriteWork = (Ov97SpriteWork *)work->spriteWork;
    ov97_0221F0E0(spriteWork);
    for (i = 0; i < 3; i++) {
        u8 *entry = (u8 *)spriteWork + i * 0x18;
        SpriteTransfer_DeleteCharTransferTask(*(void **)(entry + 0x148));
        SpriteTransfer_DeletePlttTransferTask(*(void **)(entry + 0x14c));
    }
    for (i = 0; i < 6; i++) {
        Destroy2DGfxResObjMan(*(void **)((u8 *)spriteWork + 0x130 + i * 4));
    }
    SpriteList_Delete(spriteWork->spriteList);
    Heap_Free(work);
}

void ov97_0221F0E0(Ov97SpriteWork *work) {
    int i;
    int j;
    u8 *walkA;
    u8 *outerWalk;
    u8 *innerWalk;

    i = 0;
    walkA = (u8 *)work;
    do {
        Sprite_Delete(*(void **)(walkA + 0x1b4));
        i++;
        walkA += 4;
    } while (i < 5);
    outerWalk = (u8 *)work;
    for (i = 0; i < 5; i++) {
        Sprite_Delete(*(void **)(outerWalk + 0x1dc));
        j = 0;
        innerWalk = outerWalk;
        do {
            Sprite_Delete(*(void **)(innerWalk + 0x1e0));
            j++;
            innerWalk += 4;
        } while (j < 5);
        outerWalk += 0x18;
    }
    Sprite_Delete(*(void **)((u8 *)work + 0x254));
    Heap_Free(*(void **)((u8 *)work + 0x258));
}

void ov97_0221F14C(void *bgConfig, int heapId) {
    ov97_0221F1D8(bgConfig);
    GfGfxLoader_GXLoadPal(0xf3, 0, 4, 0, 0, heapId);
    GfGfxLoader_LoadCharData(0xf3, 1, bgConfig, 7, 0, 0, 1, heapId);
    GfGfxLoader_LoadScrnData(0xf3, 2, bgConfig, 7, 0, 0x600, 1, heapId);
    BgCommitTilemapBufferToVram(bgConfig, 7);
    GfGfxLoader_LoadScrnData(0xf3, 3, bgConfig, 6, 0, 0x600, 1, heapId);
    BgCommitTilemapBufferToVram(bgConfig, 6);
    LoadFontPal0(4, 0x1e0, heapId);
}

void ov97_0221F1D8(void *bgConfig) {
    Ov97BgTemplate bg4 = ov97_0221FD20;
    InitBgFromTemplate(bgConfig, 4, &bg4, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 4);

    Ov97BgTemplate bg5 = ov97_0221FD3C;
    InitBgFromTemplate(bgConfig, 5, &bg5, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 5);

    Ov97BgTemplate bg6 = ov97_0221FD04;
    InitBgFromTemplate(bgConfig, 6, &bg6, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 6);

    Ov97BgTemplate bg7 = ov97_0221FD58;
    InitBgFromTemplate(bgConfig, 7, &bg7, 0);
    BgClearTilemapBufferAndCommit(bgConfig, 7);
}

void ov97_0221F294(Ov97Work *work) {
    void *string;

    BufferPokeathlonCourseName(work->msgFormat, 0, (u8)work->course);
    string = ReadMsgData_ExpandPlaceholders(work->msgFormat, work->msgData, 0, work->heapId);
    FillWindowPixelBuffer(work->windows[0], 0);
    AddTextPrinterParameterizedWithColor(work->windows[0], 0, string, 0, 0, 0xff, 0x10200, NULL);
    CopyWindowToVram(work->windows[0]);
    String_Delete(string);

    FillWindowPixelBuffer(work->windows[1], 0);
    if (work->flag != 0) {
        string = NewString_ReadMsgData(work->msgData, 1);
        AddTextPrinterParameterizedWithColor(work->windows[1], 0, string, 0, 0, 0xff, 0x10200, NULL);
        String_Delete(string);
    }
    CopyWindowToVram(work->windows[1]);

    FillWindowPixelBuffer(work->windows[4], 0);
    string = NewString_ReadMsgData(work->msgData, 8);
    AddTextPrinterParameterizedWithColor(work->windows[4], 0, string, 0, 0, 0xff, 0x10200, NULL);
    String_Delete(string);
    string = NewString_ReadMsgData(work->msgData, 4);
    AddTextPrinterParameterizedWithColor(work->windows[4], 0, string, 0, 0x10, 0xff, 0x10200, NULL);
    String_Delete(string);
    string = NewString_ReadMsgData(work->msgData, 6);
    AddTextPrinterParameterizedWithColor(work->windows[4], 0, string, 0, 0x20, 0xff, 0x10200, NULL);
    String_Delete(string);
    string = NewString_ReadMsgData(work->msgData, 5);
    AddTextPrinterParameterizedWithColor(work->windows[4], 0, string, 0, 0x30, 0xff, 0x10200, NULL);
    String_Delete(string);
    string = NewString_ReadMsgData(work->msgData, 7);
    AddTextPrinterParameterizedWithColor(work->windows[4], 0, string, 0, 0x40, 0xff, 0x10200, NULL);
    String_Delete(string);
    CopyWindowToVram(work->windows[4]);
}

void ov97_0221F428(Ov97Work *work, const u8 *record) {
    void *string;

    CopyU16ArrayToString(work->string, (const u16 *)(record + 0xa));
    FillWindowPixelBuffer(work->windows[2], 0);
    AddTextPrinterParameterizedWithColor(work->windows[2], 0, work->string, 0, 0, 0xff, 0x10200, NULL);
    CopyWindowToVram(work->windows[2]);
    if (record[8] == 0) {
        string = NewString_ReadMsgData(work->msgData, 2);
        FillWindowPixelBuffer(work->windows[3], 0);
        AddTextPrinterParameterizedWithColor(work->windows[3], 0, string, 4, 0, 0xff, 0x70800, NULL);
        CopyWindowToVram(work->windows[3]);
        String_Delete(string);
    } else if (record[8] == 1) {
        string = NewString_ReadMsgData(work->msgData, 3);
        FillWindowPixelBuffer(work->windows[3], 0);
        AddTextPrinterParameterizedWithColor(work->windows[3], 0, string, 4, 0, 0xff, 0x30400, NULL);
        CopyWindowToVram(work->windows[3]);
        String_Delete(string);
    } else {
        FillWindowPixelBuffer(work->windows[3], 0);
        CopyWindowToVram(work->windows[3]);
    }

    string = GetSpeciesName(*(const u16 *)(record + 4), work->heapId);
    BufferString(work->msgFormat, 0, string, 2, 1, 2);
    String_Delete(string);
    string = ReadMsgData_ExpandPlaceholders(work->msgFormat, work->msgData, 9, work->heapId);
    FillWindowPixelBuffer(work->windows[5], 0);
    AddTextPrinterParameterizedWithColor(work->windows[5], 0, string, 0, 0, 0xff, 0x10200, NULL);
    CopyWindowToVram(work->windows[5]);
    String_Delete(string);
}

void ov97_0221F56C(Ov97Work *work, const u8 *record) {
    u8 order[5];
    u8 i;
    u8 *walker;
    Ov97Work *base = work;
    u8 *spriteWork = base->spriteWork;

    ov97_0221FBDC(spriteWork);
    ov97_0221FC54(base->spriteWork);
    Sprite_SetDrawFlag(*(void **)((u8 *)base + 0x2cc), 1);
    ov97_0221F5F8(base->spriteWork, record);
    order[0] = ov97_0221FCFC[0];
    order[1] = ov97_0221FCFC[1];
    order[2] = ov97_0221FCFC[2];
    order[3] = ov97_0221FCFC[3];
    order[4] = ov97_0221FCFC[4];
    walker = order;
    i = 0;
    do {
        if (record[0x20 + walker[i]] != 0) {
            Sprite_SetDrawFlag(*(void **)(spriteWork + 0x1b4 + walker[i] * 4), 1);
        } else {
            Sprite_SetDrawFlag(*(void **)(spriteWork + 0x1b4 + walker[i] * 4), 0);
        }
        i++;
    } while (i < 5);
}
