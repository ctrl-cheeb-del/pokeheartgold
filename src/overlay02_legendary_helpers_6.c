#include "overlay_02_legendary_internal.h"

void ov02_02246714(void *task, u32 a, u32 b, u32 c, u16 d) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_02246744(field, a, b, c, d);
    TaskManager_Call(task, ov02_02246798, env);
}

void *ov02_02246744(void *field, u32 a, u32 b, u32 c, u16 d) {
    u8 *p = Heap_Alloc(4, 0xC);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0xC);
    *(void **)(p + 4) = field;
    *(u32 *)p = 4;
    *(void **)(p + 8) = ov02_0224650C(*(void **)(p + 4), 4);
    ov02_02246548(*(void **)(p + 8), (s16)a, (s16)b, c, d);
    return p;
}

int ov02_02246798(void *task) {
    u8 *p = TaskManager_GetEnvironment(task);
    if (!ov02_0224663C(*(void **)(p + 8))) {
        return 0;
    }
    ov02_0224662C(*(void **)(p + 8));
    ov02_02246534(*(void **)(p + 8));
    Heap_Free(p);
    return 1;
}

void OpenAlphHiddenRoom(void *task, u32 value) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_022467E8(field, (u8)value);
    TaskManager_Call(task, ov02_02246818, env);
}

void *ov02_022467E8(void *field, u32 value) {
    void *p = Heap_Alloc(4, 0x1C);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0x1C);
    *(void **)((u8 *)p + 4) = field;
    *((u8 *)p + 0x19) = value;
    *(u32 *)p = 4;
    return p;
}

int ov02_02246818(void *task) {
    u8 *p = TaskManager_GetEnvironment(task);
    switch (p[0x18]) {
    case 0:
        ov02_0224686C(p);
        PlaySE(0x5DC);
        p[0x18]++;
        break;
    case 1:
        if (ov02_022469A0()) {
            PlaySE(0x5DC);
            p[0x18]++;
            ov02_02246964(p);
            Heap_Free(p);
            return 1;
        }
        break;
    }
    return 0;
}

void ov02_0224686C(void *data) {
    u8 *p = data;
    void *narc;
    void *msg;
    void *string;
    u8 width;
    int x;
    narc = NARC_New(0xAE, *(u32 *)p);
    GfGfxLoader_GXLoadPalFromOpenNarc(narc, 0xF, 0, 0, 0x20, *(u32 *)p);
    GfGfxLoader_LoadCharDataFromOpenNarc(narc, 0x10, *(void **)((u8 *)*(void **)(p + 4) + 8), 1, 0, 0, 0, *(u32 *)p);
    GfGfxLoader_LoadScrnDataFromOpenNarc(narc, 0x11, *(void **)((u8 *)*(void **)(p + 4) + 8), 1, 0, 0, 0, *(u32 *)p);
    p[0x1A] = GetBgPriority(*(void **)((u8 *)*(void **)(p + 4) + 8), 1);
    SetBgPriority(1, 0);
    GfGfx_EngineATogglePlanes(2, 1);
    NARC_Delete(narc);
    AddWindow(*(void **)((u8 *)*(void **)(p + 4) + 8), p + 8, ov02_0225324C);
    FillWindowPixelBuffer(p + 8, 9);
    msg = NewMsgDataFromNarc(0, 0x1B, 0xC6, *(u32 *)p);
    string = NewString_ReadMsgData(msg, p[0x19]);
    width = FontID_String_GetWidth(3, string, 0);
    x = 0x70 - width;
    AddTextPrinterParameterizedWithColor(p + 8, 3, string, x / 2, 0, 0xFF, 0x000F0E09, NULL);
    ScheduleWindowCopyToVram(p + 8);
    String_Delete(string);
    DestroyMsgData(msg);
}

void ov02_02246964(void *data) {
    u8 *p = data;
    GfGfx_EngineATogglePlanes(2, 0);
    SetBgPriority(1, p[0x1A]);
    ClearWindowTilemapAndScheduleTransfer(p + 8);
    RemoveWindow(p + 8);
    BgClearTilemapBufferAndCommit(*(void **)((u8 *)*(void **)(p + 4) + 8), 1);
    BG_ClearCharDataRange(1, 0x1000, 0, *(void **)p);
}

int ov02_022469A0(void) {
    return (*(u32 *)(gSystem + 0x48) & 1) != 0;
}

void ov02_022469B4(void *task, u32 a, u32 b) {
    void *field = TaskManager_GetFieldSystem(task);
    void *env = ov02_022469D8(field, a, b);
    TaskManager_Call(task, ov02_02246A34, env);
}

void *ov02_022469D8(void *field, u32 a, u32 b) {
    u8 *p = Heap_Alloc(4, 0x1C);
    if (p == NULL) {
        GF_AssertFail();
        return NULL;
    }
    MI_CpuFill8(p, 0, 0x1C);
    *(void **)(p + 8) = field;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)p = 4;
    *(void **)(p + 0xC) = AllocMonZeroed(4);
    ZeroMonData(*(void **)(p + 0xC));
    CreateMon(*(void **)(p + 0xC), 0x95, 0x64, 0x20, 0, 0, 2, 0);
    return p;
}

int ov02_02246A34(void *task) {
    u8 *p = TaskManager_GetEnvironment(task);
    switch (*(u32 *)(p + 4)) {
    case 0:
        *(void **)(p + 0x18) = ov02_022494C4(*(void **)(p + 8), *(void **)(p + 0xC), *(void **)(p + 0x10), *(void **)(p + 0x14));
        (*(u32 *)(p + 4))++;
        break;
    case 1:
        if (ov02_0224953C(*(void **)(p + 0x18))) {
            ov02_02249548(*(void **)(p + 0x18));
            Heap_Free(*(void **)(p + 0xC));
            Heap_Free(p);
            return 1;
        }
        break;
    }
    return 0;
}
