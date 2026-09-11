#ifndef OV85_R34_PRIVATE_H
#define OV85_R34_PRIVATE_H

#include "global.h"

#include "constants/game_stats.h"

#include "bg_window.h"
#include "game_stats.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "list_menu_2d.h"
#include "math_util.h"
#include "message_format.h"
#include "msgdata.h"
#include "obj_char_transfer.h"
#include "obj_pltt_transfer.h"
#include "pokemon.h"
#include "sys_task_api.h"
#include "text.h"
#include "trainer_memo.h"
#include "unk_0205B3DC.h"

extern void GF_AssertFail(void);
extern s32 _s32_div_f(s32 num, s32 den);
extern int Party_GetCount(void *party);
extern void *Party_GetMonByIndex(void *party, int idx);

typedef struct ArcPair {
    u16 unk_00;
    u16 unk_02;
} ArcPair;

typedef struct ArcPair2 {
    u32 unk_00;
    u32 unk_04;
} ArcPair2;

typedef struct ArcGfxRes {
    u8 pad_00[0x0C];
    void *unk_0C;
    u8 pad_10[0x04];
    void *unk_14;
} ArcGfxRes;

typedef struct ArcGfxHolder {
    u8 pad_00[0x04];
    ArcGfxRes *unk_04;
} ArcGfxHolder;

typedef struct ArcSub1C {
    u32 unk_00;
    s32 unk_04;
    s32 unk_08;
    u8 pad_0C[0x04];
    ArcGfxRes *unk_10;
} ArcSub1C;

typedef struct ArcFadeTask {
    void *unk_00;
    s32 unk_04;
    s32 unk_08;
} ArcFadeTask;

typedef struct ArcEntry {
    u32 unk_00;
    u8 pad_04[0x08];
    void *unk_0C;
} ArcEntry;

typedef struct ArcMsg {
    u8 pad_00[0x0C];
    s32 unk_0C;
} ArcMsg;

typedef struct ArcSubD0 {
    u8 pad_00[0x40];
    u16 unk_40;
    u16 unk_42;
    u8 pad_44[0x02];
    s16 unk_46;
    u16 unk_48;
    u16 unk_4A;
} ArcSubD0;

typedef struct ArcSubCC {
    u8 pad_00[0x04];
    s32 unk_04;
    s32 unk_08;
} ArcSubCC;

typedef struct ArcCounter {
    u8 pad_00[0x08];
    s32 unk_08;
} ArcCounter;

typedef struct ArcWork {
    u8 pad_000[0x24];
    void *unk_024;
    u32 unk_028;
    u32 unk_02C;
    u32 unk_030;
    u32 unk_034;
    u32 unk_038;
    u32 unk_03C;
    u32 unk_040;
    u32 unk_044;
    u8 pad_048[0x10];
    u16 unk_058;
    u16 unk_05A;
    u16 unk_05C;
    u16 unk_05E;
    u16 unk_060;
    u8 pad_062[0x0E];
    ArcPair unk_070[5];
    u8 pad_084[0x28];
    u8 unk_0AC[0x20];
    void *unk_0CC;
    void *unk_0D0;
    u8 unk_0D4[0x10];
    u8 pad_0E4[0xB68];
    ArcEntry unk_C4C[5];
    u8 pad_C9C[0x128];
    SysTask *unk_DC4;
} ArcWork;

typedef union ArcTid {
    u64 raw;
    struct {
        u32 id;
        u32 valid;
    } f;
} ArcTid;

typedef struct ArcQuad {
    ArcTid cur;
    ArcTid prev;
} ArcQuad;

typedef struct ArcScene {
    u8 pad_000[0x08];
    u32 unk_008;
    void *unk_00C;
    void *unk_010;
    void *unk_014;
    u8 pad_018[0x04];
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    void *unk_028;
    void *unk_02C;
    void *unk_030;
    void *unk_034;
    void *unk_038;
    String *unk_03C[5];
    u8 pad_050[0x04];
    String *unk_054;
    String *unk_058;
    u32 unk_05C;
    void *unk_060;
    u8 pad_064[0x128];
    void *unk_18C[4];
    u8 pad_19C[0x20];
    void *unk_1BC;
    void *unk_1C0;
    u8 pad_1C4[0x78];
    void *unk_23C[5];
    u8 pad_250[0x58];
    Window unk_2A8;
    u8 pad_2B8[0x40];
    Window unk_2F8;
    Window unk_308;
    Window unk_318;
    u8 pad_328[0x08];
    void *unk_330;
    void *unk_334;
    void *unk_338;
    void *unk_33C;
    void *unk_340;
    void *unk_344;
    void *unk_348;
    void *unk_34C;
    void *unk_350;
    u32 unk_354;
    u32 unk_358;
    u8 pad_35C[0x04];
    s32 unk_360;
    u8 pad_364[0x10];
    ArcPair2 unk_374[5];
    u32 unk_39C[5];
    u8 unk_3B0[0x04];
    u16 unk_3B4;
    u16 pad_3B6;
    void *unk_3B8;
    u8 pad_3BC[0x9C4];
    NARC *unk_D80;
    u8 pad_D84[0x1FC];
    u8 unk_F80[0x3AC4];
    u32 unk_4A44;
    u32 unk_4A48;
    u32 pad_4A4C;
    u8 unk_4A50;
    s8 unk_4A51;
    u8 unk_4A52;
    u8 unk_4A53;
    s32 unk_4A54;
    u32 unk_4A58;
    s16 unk_4A5C;
    u8 pad_4A5E[0x02];
    ArcQuad unk_4A60[5];
} ArcScene;

typedef struct ArcSaveHolder {
    u8 pad_00[0x28];
    void *unk_28;
} ArcSaveHolder;

typedef struct ArcSubC {
    u8 pad_00[0x08];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u8 pad_14[0x08];
    void *unk_1C;
} ArcSubC;

typedef struct ArcSub10 {
    u8 pad_00[0x20];
    u32 unk_20;
    u32 unk_24;
    u8 pad_28[0x04];
    u32 unk_2C;
    u32 unk_30;
    u8 pad_34[0x04];
    u16 unk_38;
} ArcSub10;

extern void ClearFrameAndWindow2(void *window, int a1);
extern u8 TextPrinterCheckActive(u8 printerId);
extern BOOL sub_02034818(int a0);
extern void sub_02037AC0(int a0);
extern BOOL sub_0203769C(void);
extern u32 sub_02037454(void);
extern void GF_RunVramTransferTasks(void);
extern void OamManager_ApplyAndResetBuffers(void);
extern void DoScheduledBgGpuUpdates(BgConfig *bgConfig);

extern BOOL sub_02096D4C(void *, int, void *, int);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern int sub_02037B38(u32 a0);
extern void sub_020398D4(int a0, int a1);
extern void sub_0205A904(int a0);
extern void sub_02039EAC(void *p);
extern const u8 ov85_021EA8D8[];
extern const ObjCharTransferTemplate ov85_021EA904;
extern void ov85_021E83C0(SysTask *task, void *data);
extern u32 NARC_GetMemberSize(NARC *narc, u32 member);
extern u32 FontID_String_GetWidth(u32 fontId, String *str, u32 letterSpacing);
extern void *sub_02097018(void *p, int idx);

extern const GraphicsBanks ov85_021EA9B8;
extern void *const ov85_021EA4F0[];
extern const u16 ov85_021EA8E0[];
extern void ov85_021E6EA8(void *p, s32 a1);

extern BOOL sub_02039EB4(void *a0, int a1, void *a2);
extern void sub_02038C1C(int a0);
extern void StopSE(u32 seId, u32 fadeout);

extern void DrawFrameAndWindow2(Window *window, int a1, int a2, int a3);

extern void PlaySE(u32 seId);

extern void *OverlayManager_GetData(void *man);
extern void OverlayManager_FreeData(void *man);
extern void Main_SetVBlankIntrCB(void (*cb)(void *), void *arg);
extern void SpriteTransfer_DeleteCharTransferTask(void *p);
extern void SpriteTransfer_DeletePlttTransferTask(void *p);
extern void OamManager_Free(void);

extern const u8 ov85_021EA8EA[];
extern const u8 ov85_021EA8EB[];

#endif // OV85_R34_PRIVATE_H
