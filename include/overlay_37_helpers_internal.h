#ifndef OVERLAY_37_PRIVATE_H
#define OVERLAY_37_PRIVATE_H

#include "global.h"

typedef struct Ov37Window {
    u8 dummy[0x10];
} Ov37Window;

typedef struct Ov37SpriteHolder {
    u8 unk_00[0x20];
    void *unk_20;
} Ov37SpriteHolder;

typedef struct Ov37Pair {
    u32 cur;
    u32 prev;
} Ov37Pair;

typedef struct Ov37Work {
    void *bgConfig; /* 0x0000 */
    u8 unk_0004[0x000C - 0x0004];
    void *msgFormat; /* 0x000C */
    u8 unk_0010[0x0014 - 0x0010];
    void *strbuf[5]; /* 0x0014 */
    void *unk_0028;  /* 0x0028 */
    void *unk_002C;  /* 0x002C */
    u32 printerId;   /* 0x0030 */
    u8 unk_0034[0x01D8 - 0x0034];
    void *sprites[5]; /* 0x01D8 */
    u8 unk_01EC[0x0248 - 0x01EC];
    Ov37SpriteHolder holder; /* 0x0248 */
    u8 unk_026C[0x0278 - 0x026C];
    Ov37Window windows[5]; /* 0x0278 */
    Ov37Window winB2;      /* 0x02C8 */
    Ov37Window winB6;      /* 0x02D8 */
    Ov37Window winBA;      /* 0x02E8 */
    u8 unk_02F8[0x0304 - 0x02F8];
    u32 prevState; /* 0x0304 */
    u32 state;     /* 0x0308 */
    u8 unk_030C[0x0310 - 0x030C];
    u32 counter; /* 0x0310 */
    u8 unk_0314[0x0320 - 0x0314];
    u32 unk_0320; /* 0x0320 */
    u8 unk_0324[0x0334 - 0x0324];
    Ov37Pair pair[5]; /* 0x0334 */
    u8 unk_035C[0x4380 - 0x035C];
    u8 flags; /* 0x4380 */
    u8 unk_4381;
    u8 unk_4382[0x43B4 - 0x4382]; /* 0x4382 */
    u8 unk_43B4[0x43C8 - 0x43B4]; /* 0x43B4 */
    void *unk_43C8;               /* 0x43C8 */
    u8 unk_43CC[0x93B0 - 0x43CC];
    u32 unk_93B0; /* 0x93B0 */
    u8 unk_93B4[0x93BA - 0x93B4];
    u16 unk_93BA; /* 0x93BA */
    u8 unk_93BC;  /* 0x93BC */
    u8 unk_93BD[0x93F0 - 0x93BD];
    void *yesNoPrompt; /* 0x93F0 */
    u8 unk_93F4[0x93F8 - 0x93F4];
    u32 yesNoActive; /* 0x93F8 */
    u8 unk_93FC[0x9404 - 0x93FC];
    u32 unk_9404; /* 0x9404 */
    u8 unk_9408[0x940C - 0x9408];
} Ov37Work;

typedef struct Ov37YesNoTemplate {
    void *bgConfig;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
} Ov37YesNoTemplate;

typedef struct Ov37StateEntry {
    u32 unk_00;
    u32 unk_04;
} Ov37StateEntry;

/* module-local rodata blobs, left in the assembly */
extern const Ov37StateEntry ov37_021E7D20[];
extern const u8 _021E7968[];

/* external game functions */
void GF_RunVramTransferTasks(void);
void OamManager_ApplyAndResetBuffers(void);
void DoScheduledBgGpuUpdates(void *bgConfig);
void Heap_Free(void *ptr);
void String_Delete(void *str);
void YesNoPrompt_Destroy(void *prompt);
void YesNoPrompt_Reset(void *prompt);
u32 YesNoPrompt_InitFromTemplate(void *prompt, const Ov37YesNoTemplate *tmpl);
void FreeBgTilemapBuffer(void *bgConfig, u32 layer);
void RemoveWindow(Ov37Window *window);
void ClearFrameAndWindow2(Ov37Window *window, u32 arg1);
u32 TextPrinterCheckActive(u8 printerId);
void RemoveTextPrinter(u8 printerId);
void Sprite_SetAnimCtrlSeq(void *sprite, u32 seq);
void Sprite_SetDrawFlag(void *sprite, u32 flag);
u32 sub_02034818(u32 index);
u32 sub_0203769C(void);
u32 sub_02037454(void);
void sub_02038C1C(u32 arg0);
u32 sub_02037B38(u32 arg0);
void sub_02037AC0(u32 arg0);
void BufferPlayersName(void *msgFormat, u32 idx, u32 arg2);
void PlaySE(u32 seq);
void BeginNormalPaletteFade(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heapId);
void GF_AssertFail(void);
s32 GF_SinDeg(u16 deg);
void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
u32 TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);

/* module functions */
void ov37_021E5CC8(void *bgConfig);
void ov37_021E5F20(Ov37Work *work);
void ov37_021E5F5C(void *bgConfig);
void ov37_021E6540(Ov37Work *work);
void ov37_021E6818(void **sprites, u32 sel);
void ov37_021E6848(Ov37SpriteHolder *holder, u32 arg1);
void ov37_021E68AC(Ov37Work *work);
u32 ov37_021E68D0(Ov37Work *work, u32 arg1);
u32 ov37_021E6928(Ov37Work *work, u32 arg1);
u32 ov37_021E694C(Ov37Work *work, u32 arg1);
u32 ov37_021E6980(Ov37Work *work, u32 arg1);
u32 ov37_021E6BFC(Ov37Work *work, u32 arg1);
u32 ov37_021E6B40(Ov37Work *work, u32 arg1);
u32 ov37_021E6C38(Ov37Work *work, u32 arg1);
u32 ov37_021E6C58(Ov37Work *work, u32 arg1);
u32 ov37_021E6C84(Ov37Work *work, u32 arg1);
u32 ov37_021E6CC0(Ov37Work *work, u32 arg1);
u32 ov37_021E6DD0(Ov37Work *work, u32 arg1);
u32 ov37_021E6E04(Ov37Work *work, u32 arg1);
u32 ov37_021E6E2C(Ov37Work *work, u32 arg1);
u32 ov37_021E6E6C(u32 arg0, u32 arg1);
u32 ov37_021E6E70(Ov37Work *work, u32 arg1);
u32 ov37_021E6E90(Ov37Work *work, u32 arg1);
u32 ov37_021E6EB4(Ov37Work *work, u32 arg1);
u32 ov37_021E6F14(Ov37Work *work, u32 arg1);
u32 ov37_021E741C(u16 *arg0);
u32 ov37_021E745C(void);
void ov37_021E755C(Ov37Work *work);
u32 ov37_021E65EC(Ov37Work *work);
void ov37_021E72E8(Ov37Window *window, const u8 *a1, const u8 *a2, u32 a3);
void ov37_021E73B4(Ov37Work *work);
u32 ov37_021E75C4(void);
u32 ov37_021E75E0(void);
u32 ov37_021E75E8(Ov37Work *work);
void ov37_021E762C(Ov37Work *work, u32 arg1, u32 arg2);
u32 ov37_021E76A0(u32 printerId);
void ov37_021E76C0(Ov37Work *work);
void ov37_021E76D0(Ov37Work *work, u32 arg1);
void ov37_021E7844(Ov37Work *work, u32 state);
void ov37_021E784C(Ov37Work *work, u32 arg1);
u32 ov37_021E7880(Ov37Work *work, const Ov37YesNoTemplate *tmpl);
void ov37_021E78A4(Ov37Work *work);
u32 ov37_021E78C4(void);
u32 ov37_021E6860(Ov37Work *work, u32 arg1);

#endif
