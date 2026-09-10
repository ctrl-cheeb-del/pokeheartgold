#include "global.h"

typedef struct {
    u8 raw[0x400];
} Ov34State;
extern u8 gSystem[];
extern void *NewString_ReadMsgData(void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void String_Delete(void *);
extern int ov01_021F6B10(void *);
extern void ov34_0225E58C(Ov34State *);
extern void ov34_0225E4F8(Ov34State *);
extern void ov34_0225DE04(Ov34State *);
extern void ov34_0225E164(Ov34State *);
extern void ov34_0225DD04(Ov34State *);
extern void ov34_0225E630(Ov34State *);
extern void RemoveWindow(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern int Sprite_GetAnimationFrame(void *);
extern int Sprite_GetAnimationNumber(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern int Sprite_GetAnimActiveFlag(void *);
extern void Sprite_SetAnimActiveFlag(void *, int);
extern void Sprite_SetAnimationFrame(void *, int);
extern void *MessageFormat_New(int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *GfGfxLoader_GetScrnData(int, int, int, void **, int);
extern void FontID_SetAccessLazy(int);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void Destroy2DGfxResObjMan(void *);
extern void SpriteList_Delete(void *);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void Heap_Free(void *);
extern void DestroySysTaskAndEnvironment(void *);
extern void GF_AssertFail(void);
extern void Sprite_SetMatrix(void *, const VecFx32 *);
extern void *CreateSysTaskAndEnvironment(void (*)(void *, void *), int, int, int);
extern void *SysTask_GetData(void *);
extern void *Save_PlayerData_GetProfile(void *);
extern void ov34_0225D5A0(void *, Ov34State *);
extern void ov34_0225D924(void *);
extern void SetKeyRepeatTimers(int, int);
extern void ov34_0225DA50(Ov34State *);
extern void ov34_0225DB20(Ov34State *);
extern void FontID_SetAccessDirect(int, int);
extern void ov34_0225D650(void *, void *, void *);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern int FieldSystem_TaskIsRunning(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern void ov01_021F6A9C(void *, int, int);
extern void PlaySE(int);
extern void ov34_0225E348(Ov34State *, u32, u32, u32);

void ov34_0225D520(Ov34State *);
void ov34_0225D558(Ov34State *);
void ov34_0225D5A0(void *, Ov34State *);
void ov34_0225D77C(void *, void *);
void ov34_0225D5F8(Ov34State *);
void *ov34_0225D7A8(void *);
void ov34_0225D87C(Ov34State *);
void ov34_0225DDB8(void *, int);
void ov34_0225D900(void *);
int ov34_0225DC00(int, int);
int ov34_0225DC0C(int, int);
void ov34_0225E560(Ov34State *);
void ov34_0225E56C(Ov34State *);
void ov34_0225E58C(Ov34State *);
int ov34_0225E5D4(Ov34State *);
void ov34_0225E5DC(Ov34State *, void *);
void *ov34_0225E5E4(Ov34State *);
void ov34_0225E5EC(Ov34State *, int);
void ov34_0225E630(Ov34State *);
void ov34_0225E0E4(Ov34State *);
void ov34_0225E4A8(Ov34State *, u32, u32, u32);

void ov34_0225D77C(void *windows, void *extra) {
    int i;
    u8 *p = windows;
    RemoveWindow(extra);
    for (i = 0; i < 3; i++, p += 0x38) {
        RemoveWindow(p + 0x10);
        RemoveWindow(p);
        RemoveWindow(p + 0x20);
    }
}

void *ov34_0225D7A8(void *fieldSystem) {
    void *task = CreateSysTaskAndEnvironment((void (*)(void *, void *))ov34_0225D5A0, 0x2A8, 4, 4);
    Ov34State *p = SysTask_GetData(task);
    *(void **)((u8 *)p + 0xC) = fieldSystem;
    *(void **)((u8 *)p + 0x14) = *(void **)((u8 *)fieldSystem + 8);
    *(void **)((u8 *)p + 4) = *(void **)((u8 *)fieldSystem + 0x84);
    *(void **)((u8 *)p + 8) = *(void **)((u8 *)fieldSystem + 0x80);
    *(void **)((u8 *)p + 0x10) = Save_PlayerData_GetProfile(*(void **)((u8 *)fieldSystem + 0xC));
    *(u32 *)p = 2;
    *(void **)((u8 *)p + 0x2A4) = task;
    *(void **)((u8 *)p + 0x270) = *(void **)((u8 *)*(void **)((u8 *)fieldSystem + 0x84) + 0x4DC);
    ov34_0225D924(*(void **)((u8 *)p + 0x14));
    ov34_0225D5F8(p);
    SetKeyRepeatTimers(4, 8);
    ov34_0225E56C(p);
    ov34_0225E5DC(p, (void *)1);
    ov34_0225DA50(p);
    ov34_0225DB20(p);
    FontID_SetAccessDirect(1, 4);
    ov34_0225D650(*(void **)((u8 *)p + 0x14), (u8 *)p + 0x1C8, (u8 *)p + 0x274);
    ov34_0225D520(p);
    GfGfx_EngineBTogglePlanes(0x10, 1);
    GfGfx_EngineBTogglePlanes(1, 1);
    GfGfx_EngineBTogglePlanes(2, 1);
    GfGfx_EngineBTogglePlanes(4, 1);
    GfGfx_EngineBTogglePlanes(8, 1);
    ov34_0225E560(p);
    return p;
}

void ov34_0225D87C(Ov34State *p) {
    int i, off;
    u8 *cursor;
    void *bg;
    if ((u32)(*(u32 *)p - 2) > 2) {
        goto bad;
    }
    bg = *(void **)((u8 *)p + 0x14);
    *(u32 *)p = 5;
    FontID_SetAccessLazy(1);
    SpriteTransfer_DeleteCharTransferTask(*(void **)((u8 *)p + 0x164));
    SpriteTransfer_DeletePlttTransferTask(*(void **)((u8 *)p + 0x168));
    off = 0x154;
    i = 0;
    cursor = (u8 *)p;
    do {
        Destroy2DGfxResObjMan(*(void **)(cursor + off));
        i++;
        cursor += 4;
    } while (i < 4);
    SpriteList_Delete(*(void **)((u8 *)p + 0x28));
    DestroyMsgData(*(void **)((u8 *)p + 0x1C));
    MessageFormat_Delete(*(void **)((u8 *)p + 0x18));
    ov34_0225D77C((u8 *)p + 0x1C8, (u8 *)p + 0x274);
    ov34_0225D900(bg);
    Heap_Free(*(void **)((u8 *)p + 0x20));
    DestroySysTaskAndEnvironment(*(void **)((u8 *)p + 0x2A4));
    return;
bad:
    GF_AssertFail();
}

void ov34_0225D900(void *bg) {
    FreeBgTilemapBuffer(bg, 4);
    FreeBgTilemapBuffer(bg, 5);
    FreeBgTilemapBuffer(bg, 6);
    FreeBgTilemapBuffer(bg, 7);
}
