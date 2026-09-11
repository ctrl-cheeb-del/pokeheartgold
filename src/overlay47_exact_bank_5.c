#include "global.h"
typedef struct {
    u8 raw[0x220];
} State;
extern void ov47_02258A8C(State *);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void *NARC_New(int, int);
extern void GF_CreateVramTransferManager(int, int);
extern const u8 ov47_02259EC0[];
extern void GfGfx_SetBanks(const void *);
extern void ov47_02258AA0(State *, void *, int);
extern void ov47_02258BB4(State *, int);
extern void NARC_Delete(void *);
extern void GF_DestroyVramTransferManager(void);
extern void ov47_02258B8C(State *);
extern void ov47_02258C44(State *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern void OamManager_ApplyAndResetBuffers(void);
extern void GF_RunVramTransferTasks(void);
extern const u32 ov47_02259E68[];
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Free(void *);
extern void SpriteList_Delete(void *);
extern void Destroy2DGfxResObjMan(void *);
extern void ObjCharTransfer_Destroy(void);
extern void ObjPlttTransfer_Destroy(void);
extern void OamManager_Free(void);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void String_Delete(void *);
extern void GF_AssertFail(void);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void *ov47_02258CEC(State *, int, int);
extern void Sprite_SetDrawFlag(void *, int);
extern const VecFx32 ov47_02259E78[];
extern void Sprite_SetMatrix(void *, const VecFx32 *);
extern void Sprite_SetAnimActiveFlag(void *, int);
extern int TextPrinterCheckActive(u8);
extern void RemoveTextPrinter(u8);
extern void ov47_022593A0(State *);
extern void RemoveWindow(void *);
extern void ov47_02259448(State *, int);
extern void *WaitingIcon_New(void *, int);
extern void sub_0200F450(void *);
extern void ClearFrameAndWindow2(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern int Handle2dMenuInput_DeleteOnFinish(void *);
extern void Clear2dMenuWindowAndDelete(void *);
extern void ov47_02259D24(State *);
extern void *ov47_02258D18(State *, int);
extern void *ov47_02258D44(State *, int, int);
extern u32 ov45_0222F544(int);
extern const u8 _02259E38[];
extern void *Std_CreateYesNoMenu(void *, const void *, int, int, int);
extern void ov47_02258DD0(void *, void *, void *, void *);
extern void ov47_02258F48(void *, void *, void *, void *, void *, void *);
extern void ov47_02259488(void *, void *, void *, void *, void *);
extern void ov47_02259578(void *, void *, void *, void *, void *, void *);

void ov47_02258A14(State *);
void ov47_02258A1C(State *, void *, int);
void ov47_02258A60(State *);
void ov47_02258A80(State *);
void ov47_02258A8C(State *);
void ov47_02258B8C(State *);
void ov47_02258C44(State *);
void ov47_02258CC0(State *);
void *ov47_02258CEC(State *, int, int);
void *ov47_02258D18(State *, int);
void *ov47_02258D44(State *, int, int);
void ov47_02258DC8(void);
void ov47_022591F8(State *);
void ov47_0225921C(State *);
void ov47_02259278(State *, int);
void ov47_02259384(State *);
void ov47_022593A0(State *);
int ov47_022593B4(State *);
void ov47_022593CC(State *);
int ov47_02259430(State *);
void ov47_02259448(State *, int);
void ov47_02259480(void);
void ov47_02259968(State *);
void ov47_02259D24(State *);
void *ov47_02259D40(State *, int);
void *ov47_02259D58(State *, int, int);
void ov47_02259D74(State *);
void ov47_02259404(State *, void *, int);
void ov47_02258DA8(void *, void *, void *, void *, void *);
void ov47_02258DB4(void *, void *, void *, void *, void *, void *);
void ov47_0225945C(void *, void *, void *, void *, void *);
void ov47_0225946C(void *, void *, void *, void *, void *, void *);

/* exploratory trampoline */
/* exploratory trampoline */

void ov47_02258D78(State *, int, int);
void ov47_0225912C(State *, void *, State *);
extern void *PlayerProfile_New(int);
extern void *ov45_0222A5C0(void *);
extern void ov45_0222A844(void *, void *, int);
extern void BufferPlayersName(void *, int, void *);

extern void Sprite_Delete(void *);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void DestroySingle2DGfxResObj(void *, void *);

extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void *String_New(u32, int);
extern int Options_GetTextFrameDelay(void *);
void ov47_02259228(State *, State *, void *, int);

extern void String_Copy(void *, void *);
extern u8 AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern void ScheduleWindowCopyToVram(void *);
void ov47_022592B4(State *, void *);
void ov47_02259318(State *, void *);

extern int FontID_String_GetWidth(int, void *, int);
void ov47_0225999C(void *, State *, int, u32);

u64 ov47_02259DA4(State *, int, u32);

extern void SetWindowPaletteNum(void *, u8);
void ov47_02259B30(State *, State *, void *, int);

extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, int, void *, int, int, int, int, int);
extern void CopyWindowToVram(void *);
void ov47_02259C3C(State *, State *, State *, int);

extern void *ov45_0222A578(void *, int);
extern void *ov45_0222AA54(void *);
extern void ov45_0222AB0C(void *, void *);
extern int ov45_0222F6B0(int, void *);
typedef struct {
    u32 a;
    u32 category;
} Ov47Temp;
void ov47_02259DCC(State *, void *);

void ov47_022591F8(State *p) {
    Sprite_SetDrawFlag(*(void **)((u8 *)p + 0x14), 1);
    Sprite_SetMatrix(*(void **)((u8 *)p + 0x14), &ov47_02259E78[*(u32 *)((u8 *)p + 0x10)]);
}

void ov47_0225921C(State *p) {
    Sprite_SetAnimActiveFlag(*(void **)((u8 *)p + 0x14), 1);
}

void ov47_02259228(State *p, State *ctx, void *save, int heap) {
    AddWindowParameterized(*(void **)ctx, (void *)((u8 *)p + 8), 1, 2, 0x13, 0x1b, 4, 4, 0x28);
    FillWindowPixelBuffer((void *)((u8 *)p + 8), 0xf);
    *(void **)((u8 *)p + 0x18) = String_New(0x100, heap);
    *(u32 *)((u8 *)p + 4) = Options_GetTextFrameDelay(Save_PlayerData_GetOptionsAddr(save));
}

void ov47_02259278(State *p, int v) {
    if (TextPrinterCheckActive(*(u32 *)p)) {
        RemoveTextPrinter(*(u32 *)p);
    }
    ov47_022593A0(p);
    String_Delete(*(void **)((u8 *)p + 0x18));
    RemoveWindow((u8 *)p + 8);
    ov47_02259448(p, v);
}

void ov47_022592B4(State *p, void *str) {
    if (TextPrinterCheckActive(*(u32 *)p)) {
        RemoveTextPrinter(*(u32 *)p);
    }
    FillWindowPixelBuffer((u8 *)p + 8, 0xf);
    String_Copy(*(void **)((u8 *)p + 0x18), str);
    *(u32 *)p = AddTextPrinterParameterizedWithColor((u8 *)p + 8, 1, *(void **)((u8 *)p + 0x18), 0, 0, *(u32 *)((u8 *)p + 4), 0x1020f, NULL);
    DrawFrameAndWindow2((u8 *)p + 8, 1, 1, 5);
}

void ov47_02259318(State *p, void *str) {
    if (TextPrinterCheckActive(*(u32 *)p)) {
        RemoveTextPrinter(*(u32 *)p);
    }
    FillWindowPixelBuffer((u8 *)p + 8, 0xf);
    String_Copy(*(void **)((u8 *)p + 0x18), str);
    AddTextPrinterParameterizedWithColor((u8 *)p + 8, 1, *(void **)((u8 *)p + 0x18), 0, 0, 0xff, 0x1020f, NULL);
    DrawFrameAndWindow2((u8 *)p + 8, 1, 1, 5);
    ScheduleWindowCopyToVram((u8 *)p + 8);
}

void ov47_02259384(State *p) {
    if (*(void **)((u8 *)p + 0x1C)) {
        GF_AssertFail();
    }
    *(void **)((u8 *)p + 0x1C) = WaitingIcon_New((u8 *)p + 8, 1);
}

void ov47_022593A0(State *p) {
    if (*(void **)((u8 *)p + 0x1C)) {
        sub_0200F450(*(void **)((u8 *)p + 0x1C));
        *(void **)((u8 *)p + 0x1C) = NULL;
    }
}

int ov47_022593B4(State *p) {
    return !TextPrinterCheckActive(*(u32 *)p);
}

void ov47_022593CC(State *p) {
    if (TextPrinterCheckActive(*(u32 *)p)) {
        RemoveTextPrinter(*(u32 *)p);
    }
    ov47_022593A0(p);
    ClearFrameAndWindow2((u8 *)p + 8, 1);
    ClearWindowTilemapAndScheduleTransfer((u8 *)p + 8);
}

void ov47_02259404(State *p, void *ctx, int heap) {
    if (*(void **)((u8 *)p + 0x20)) {
        GF_AssertFail();
    }
    *(void **)((u8 *)p + 0x20) = Std_CreateYesNoMenu(*(void **)ctx, _02259E38, 0x1F, 6, heap);
}

int ov47_02259430(State *p) {
    int r = Handle2dMenuInput_DeleteOnFinish(*(void **)((u8 *)p + 0x20));
    if (r != -1) {
        *(void **)((u8 *)p + 0x20) = NULL;
    }
    return r;
}

void ov47_02259448(State *p, int x) {
    if (*(void **)((u8 *)p + 0x20)) {
        Clear2dMenuWindowAndDelete(*(void **)((u8 *)p + 0x20));
        *(void **)((u8 *)p + 0x20) = NULL;
    }
}

void ov47_0225945C(void *a, void *b, void *c, void *d, void *e) {
    ov47_02259488(a, b, c, d, e);
}

void ov47_0225946C(void *a, void *b, void *c, void *d, void *e, void *f) {
    ov47_02259578(a, b, c, d, e, f);
}
