#include "overlay_103_helpers_internal.h"

/* ---- data: ALL 25 rodata symbols are preserved as assembly (extern) ---- */
extern const u32 ov103_021EEC30[];
extern const u16 _021EEB34[];
extern u32 (*const ov103_021EECA8[])(void *);
extern u32 (*const ov103_021EEC68[][2])(void *);
extern const u32 ov103_021EEC58[];
extern const u8 ov103_021EED58[];
extern const u8 ov103_021EEFB4[];

struct Ov103YesNoTemplate {
    void *bgConfig;
    u32 unk4;
    u32 msgId;
    u32 unkC;
    u8 x;
    u8 y;
    u8 palA : 4;
    u8 palB : 4;
    u8 unk13;
};

extern void YesNoPrompt_InitFromTemplate(void *, const struct Ov103YesNoTemplate *);
void ov103_021ECEA4(void *);

struct Ov103Anim {
    u8 kind : 1;
    u8 index : 7;
    u8 palA : 4;
    u8 palB : 4;
    u8 state;
    u8 timer;
    s8 x;
    s8 y;
    u8 w;
    u8 h;
};

extern void sub_02019B1C(void *, u32, s8 *, s8 *);
extern void sub_02019B44(void *, u32, u16 *, u16 *);
u32 ov103_021EDA98(void *, u32, u32);
u32 ov103_021EDB18(void *, u32, u32);

struct Ov103Branch {
    u32 (*enter)(void *);
    u32 (*leave)(void *);
    u32 next;
};
extern const struct Ov103Branch ov103_021EEC78[];

/* ---- callees not written here (prototypes only) ---- */
extern void *OverlayManager_CreateAndGetData(void *, u32, u32);
extern void *OverlayManager_GetArgs(void *);
extern void *OverlayManager_GetData(void *);
extern void OverlayManager_FreeData(void *);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void *Save_Mailbox_Get(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern void SpriteSystem_TransferOam(void);
extern void GfGfx_SetBanks(const void *);
extern void FreeBgTilemapBuffer(void *, u32);
extern u32 Options_GetFrame(void *);
extern void LoadUserFrameGfx2(void *, u32, u32, u32, u32, u32);
extern void LoadFontPal1(u32, u32, u32);
extern void LoadFontPal0(u32, u32, u32);
extern void *sub_0201956C(void *, u32, u32, u32);
extern void sub_020195C0(void *);
extern void sub_020195F4(void *, u32, u32, u32, u32);
extern void sub_02019688(void *, u32, u32, u32, u32);
extern void *sub_02019B08(void *, u32);
extern void sub_020196E8(void *, u32, s8, s8);
extern void sub_0201980C(void *, u32);
extern void sub_020197F4(void *, u32);
extern void *NewMsgDataFromNarc(u32, u32, u32, u32);
extern void *MessageFormat_New(u32);
extern void *String_New(u32, u32);
extern void TextFlags_SetCanTouchSpeedUpPrint(u32);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void *YesNoPrompt_Create(u32);
extern void YesNoPrompt_Destroy(void *);
extern u32 YesNoPrompt_HandleInput(void *);
extern void YesNoPrompt_Reset(void *);
extern void *TouchscreenListMenuSpawner_Create(u32, u32);
extern void TouchscreenListMenuSpawner_Destroy(void *);
extern void *ListMenuItems_New(u32, u32);
extern void ListMenuItems_Delete(void *);
extern void ListMenuItems_AppendFromMsgData(void *, void *, u32, u32);
extern void TouchscreenListMenu_Destroy(void *);
extern u32 TouchscreenListMenu_HandleInput(void *);
extern void *Mailbox_AllocAndFetchMailI(void *, u32, u32, u32);
extern u32 Mail_TypeIsValid(void *);
extern u32 Mail_GetType(void *);
extern u32 MailToItemId(u32);
extern u32 ItemToMailId(u32);
extern void Mailbox_DeleteSlotI(void *, u32, u32);
extern void *SaveArray_Party_Get(void *);
extern u32 Party_GetCount(void *);
extern void *Party_GetMonByIndex(void *, u32);
extern void *Save_Bag_Get(void *);
extern u32 Bag_AddItem(void *, u32, u32, u32);
extern u32 Bag_TakeItem(void *, u32, u32, u32);
extern void Main_SetVBlankIntrCB(void *, void *);
extern void HBlankInterruptDisable(void);
extern void GfGfx_EngineASetPlanes(u32);
extern void GfGfx_EngineBSetPlanes(u32);
extern void GfGfx_EngineATogglePlanes(u32, u32);
extern void GfGfx_EngineBTogglePlanes(u32, u32);
extern void sub_020210BC(void);
extern void sub_02021148(u32);
extern void sub_02021238(void);
extern u32 IsPaletteFadeFinished(void);
extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern u32 TextPrinterCheckActive(u32);
extern u32 System_GetTouchNew(void);
extern void PlaySE(u32);
extern void SpriteSystem_DrawSprites(void *);
extern void sub_02019934(void *);
extern u32 GridInputHandler_HandleInput_NoHold(void *);
extern u32 GridInputHandler_GetNextInput(void *);
extern void GridInputHandler_Free(void *);
extern void *GridInputHandler_GetDpadBox(void *, u32);
extern void ManagedSprite_TickFrame(void *);
extern void SpriteSystem_FreeResourcesAndManager(void *, void *);
extern void SpriteSystem_Free(void *);
/* G2x_SetBlendAlpha_ comes from tracked headers */
extern void *OverlayManager_New(const void *, void *, u32);
extern u32 OverlayManager_Run(void *);
extern void OverlayManager_Delete(void *);
extern void *sub_02090E68(void *, u32, u32, u32);
extern u32 sub_02090F6C(void *);
extern void sub_02090F70(void *, void *);
extern void sub_02090F90(void *);
extern void sub_02091004(void *, u32, void *, u32);
extern const void *gOverlayTemplate_PartyMenu;
extern u8 gSystem[];
extern void FillWindowPixelBuffer(void *, u32);
extern u8 AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, void *);
extern void *SpriteSystem_NewSprite(void *, void *, const void *);
extern void *SpriteSystem_NewSpriteWithYOffset(void *, void *, const void *, u32);
extern u32 FontID_String_GetWidth(u32, void *, u32);
extern void *NewString_ReadMsgData(void *, u32);
extern void *Mail_GetAuthorNamePtr(void *);
extern u32 Mail_GetAuthorGender(void *);
extern void CopyU16ArrayToString(void *, void *);
extern void BufferString(void *, u32, void *, u32, u32, u32);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void *Mail_GetUnk20Array(void *, u32);
extern u32 MailMsg_IsInit(void *);
extern void *MailMsg_GetExpandedString(void *, u32);
extern void *GridInputHandler_Create(const void *, const void *, const void *, void *, u32, u32, u32);
void ov103_021EE3E4(void *, void *, u32, u32, u32, u32, u32);
void ov103_021EE430(void *, void *, u32, u32, u32, u32, u32, u32, u32);
u32 ov103_021EDD14(void *);
void ov103_021EE784(void *, u32);
extern u32 Options_GetTextFrameDelay(void *);
extern const u8 ov103_021EEEC4[];
extern const u8 ov103_021EEFBC[];
extern const u8 ov103_021EEFD8[];
extern void GfGfxLoader_LoadCharDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_LoadScrnDataFromOpenNarc(void *, u32, void *, u32, u32, u32, u32, u32);
extern void GfGfxLoader_GXLoadPalFromOpenNarc(void *, u32, u32, u32, u32, u32);
void ov103_021ED0C0(void *);
void ov103_021ED00C(void *);
void ov103_021ED23C(void *);
extern const u8 ov103_021EF008[];
extern const u8 ov103_021EEFC8[];
extern void Sprite_DeleteAndFreeResources(void *);
extern void ManagedSprite_SetAnimationFrame(void *, u32);
extern void ManagedSprite_SetAnim(void *, u32);
extern void ManagedSprite_SetDrawFlag(void *, u32);
extern void ManagedSprite_SetPositionXY(void *, u32, u32);
extern void ManagedSprite_SetOamMode(void *, u32);
extern void *NARC_New(u32, u32);
extern void NARC_Delete(void *);
extern void FontID_Alloc(u32, u32);
extern void FontID_Release(u32);
extern void AddWindow(void *, void *, const void *);
extern void RemoveWindow(void *);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void ScheduleWindowCopyToVram(void *);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void DrawFrameAndWindow2(void *, u32, u32, u32);
extern void ClearFrameAndWindow2(void *, u32);
#define WIN(sub, i) ((void *)((u8 *)(sub) + 0x48 + (i) * 0x10))
extern void *Heap_Create(u32, u32, u32);
extern void Heap_Destroy(u32);
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void MI_CpuFill8(void *, u8, u32);
extern void BgClearTilemapBufferAndCommit(void *, u32);
extern s32 TouchscreenHitbox_FindRectAtTouchNew(const void *);
#define NEWKEYS U32AT(gSystem, 0x48)

/* ---- forward decls, source order ---- */
u32 ov103_021EC940(void *a0);
u32 ov103_021EC988(void *a0, void *a1);
u32 ov103_021EC9A4(void *a0);
void ov103_021EC9B4(void *a0);
void ov103_021EC9D8(void);
void ov103_021ECBBC(void *a0);
void ov103_021ECD18(void *a0);
void ov103_021ECE0C(void *a0);
void ov103_021ECE18(void *a0);
void ov103_021ECE54(void *a0);
void ov103_021ECE80(void *a0);
void ov103_021ECE94(void *a0);
void ov103_021ECF48(void *a0);
void ov103_021ECFFC(void *a0);
void ov103_021ED0A0(void *a0);
void ov103_021ED124(void *a0);
u32 ov103_021ED2B8(void *a0);
BOOL ov103_021ED2D4(void *a0, u32 *a1);
u32 ov103_021ED314(void *a0);
u32 ov103_021ED3E8(void *a0);
u32 ov103_021ED460(void *a0);
u32 ov103_021ED47C(void *a0);
u32 ov103_021ED4D4(void *a0);
u32 ov103_021ED53C(void *a0);
u32 ov103_021ED550(void *a0);
u32 ov103_021ED568(void *a0);
u32 ov103_021ED5A8(void *a0);
u32 ov103_021ED750(void *a0);
u32 ov103_021ED760(void *a0);
u32 ov103_021ED7A4(void *a0);
u32 ov103_021ED7D8(void *a0);
u32 ov103_021ED8D0(void *a0);
u32 ov103_021ED8F8(void *a0);
u32 ov103_021ED930(void *a0);
u32 ov103_021ED93C(void *a0);
u32 ov103_021ED954(void *a0);
u32 ov103_021ED960(void *a0);
u32 ov103_021ED97C(void *a0);
u32 ov103_021ED99C(void *a0);
u32 ov103_021ED9AC(void *a0);
u32 ov103_021ED9D8(void *a0);
u32 ov103_021EDA14(void *a0, u32 a1);
u32 ov103_021EDA40(void *a0, u32 a1);
u32 ov103_021EDA70(void *a0, u32 a1, u32 a2);
u32 ov103_021EDA84(void *a0, u32 a1);
void ov103_021EDB60(void *a0, u32 a1);
void ov103_021EDBB0(void *a0);
void ov103_021EDBC8(void *a0);
void ov103_021EDC00(void *a0);
void ov103_021EDC58(void *a0);
void ov103_021EDC68(void *a0, u32 a1, u32 a2, u32 a3);
u32 ov103_021EDCC8(void *a0);
u32 ov103_021EDCE0(void *a0);
u32 ov103_021EDD48(void *a0);
u32 ov103_021EDD54(void *a0);
u32 ov103_021EDD98(void *a0);
u32 ov103_021EDDE4(void *a0);
u32 ov103_021EDE5C(void *a0);
u32 ov103_021EDE7C(void *a0);
void ov103_021EDEA8(void *a0);
void ov103_021EDF50(void *a0);
void ov103_021EDF68(void *a0);
void ov103_021EE028(void *a0);
void ov103_021EEAA0(void *a0);
void ov103_021EEAB0(void);
void ov103_021EEAB4(void);
void ov103_021EEAB8(void *a0, u32 a1);
void ov103_021EEAC0(void *a0, u32 a1);
void ov103_021EEAC8(void *a0, u32 a1);
u32 ov103_021EEB04(void);

/* callees written elsewhere in the module (assembly for now) */
extern void ov103_021EC9E8(void *);
extern void ov103_021ECC1C(void *);
extern void ov103_021ECD68(void *);

void ov103_021ECEEC(void *);
extern void ov103_021ECF68(void *);

extern u32 ov103_021ED144(void *);

extern void ov103_021EDBC8_unused(void *);
extern void ov103_021EDF88(void *);
extern void ov103_021EE028_x(void *);
void *ov103_021EE048(void *, const void *);
s32 ov103_021EEA24(void *);
extern void ov103_021EE078(void *, u32);
extern void ov103_021EE094(void *);
extern void ov103_021EE0AC(void *, u32, u32);
extern void ov103_021EE0CC(void *, u32, u32);
extern void ov103_021EE0F8(void *, u32, u32, u32);
extern void ov103_021EE110(void *, u32, u32);
extern void ov103_021EE13C(void *);
extern void ov103_021EE150(void *);
extern void ov103_021EE160(void *);
extern void ov103_021EE210(void *);
extern void ov103_021EE2E0(void *);
extern void ov103_021EE374(void *);
extern void ov103_021EE390(void *);
extern void ov103_021EE3C0(void *);
extern void ov103_021EE468(void *, u32, u32, u32);
extern void ov103_021EE550(void *);
extern void ov103_021EE60C(void *);
extern void ov103_021EE628(void *);
extern void ov103_021EE644(void *);
void ov103_021EE824(void *);
void ov103_021EE7DC(void *);
extern void ov103_021EE860(void *);
extern void ov103_021EE888(void *);
extern void ov103_021EE8A8(void *, u32);
void ov103_021EE9C8(void *, u32, u32);
void ov103_021EEA48(void *);
u32 ov103_021ECEEC_dummy(void);
extern void ov103_021EE930(void *);

/* ================= functions, source order ================= */

u32 ov103_021EDB18(void *a0, u32 a1, u32 a2) {
    struct Ov103Anim *p = (struct Ov103Anim *)((u8 *)PAT(a0, W_SUB) + S_ANIM);
    p->kind = 0;
    p->index = (u8)a1;
    p->palA = 1;
    p->palB = 0;
    p->state = 0;
    p->timer = 0;
    U32AT(a0, W_STATE) = a2;
    return 5;
}

void ov103_021EDB60(void *sub, u32 a1) {
    if (a1 == 1) {
        ov103_021EE110(sub, 0, 1);
        ov103_021EE110(sub, 1, 1);
        G2x_SetBlendAlpha_(0x04000050, 4, 8, 4, 0xc);
    } else {
        ov103_021EE110(sub, 0, 0);
        ov103_021EE110(sub, 1, 0);
        *(u16 *)0x04000050 = 0;
    }
}

void ov103_021EDBB0(void *a0) {
    ov103_021ED23C(a0);
    ov103_021EE930(a0);
    ov103_021EE210(a0);
}

void ov103_021EDBC8(void *a0) {
    ov103_021EE0CC(PAT(a0, W_SUB), 4, 0);
    ov103_021EE0CC(PAT(a0, W_SUB), 5, 0);
    ov103_021EE0CC(PAT(a0, W_SUB), 6, 0);
    BgClearTilemapBufferAndCommit(PAT(PAT(a0, W_SUB), S_BGCFG), 4);
    BgClearTilemapBufferAndCommit(PAT(PAT(a0, W_SUB), S_BGCFG), 5);
}

void ov103_021EDC00(void *a0) {
    void *bag = Save_Bag_Get(PAT(PAT(a0, W_ARGS), 0));
    U16AT(a0, W_ITEM) = MailToItemId(Mail_GetType(PAT((u8 *)PAT(a0, W_SUB) + U8AT(a0, W_SLOT) * 4, S_MAIL)));
    if (Bag_AddItem(bag, U16AT(a0, W_ITEM), 1, 0x9d) == 1) {
        U8AT(a0, W_RET21) &= ~0x80;
    } else {
        U8AT(a0, W_RET21) |= 0x80;
    }
}

void ov103_021EDC58(void *a0) {
    Mailbox_DeleteSlotI(PAT(a0, W_MAILBOX), 0, U8AT(a0, W_SLOT));
}

void ov103_021EDC68(void *a0, u32 a1, u32 a2, u32 a3) {
    void *c = Heap_Alloc(0x9c, 0x44);
    MI_CpuFill8(c, 0, 0x44);
    PAT(c, 0x00) = SaveArray_Party_Get(PAT(PAT(a0, W_ARGS), 0));
    PAT(c, 0x04) = Save_Bag_Get(PAT(PAT(a0, W_ARGS), 0));
    PAT(c, 0x0c) = PAT(a0, W_OPTIONS);
    PAT(c, 0x08) = PAT(a0, W_MAILBOX);
    U8AT(c, 0x25) = 0;
    U8AT(c, 0x24) = a1;
    U16AT(c, 0x28) = a2;
    PAT(c, 0x1c) = PAT(PAT(a0, W_ARGS), 4);
    PAT(c, 0x20) = PAT(PAT(a0, W_ARGS), 8);
    U8AT(c, 0x26) = a3;
    PAT(a0, W_CHILD) = c;
}

u32 ov103_021EDCC8(void *a0) {
    PAT(a0, W_OVLMGR) = OverlayManager_New(&gOverlayTemplate_PartyMenu, PAT(a0, W_CHILD), 0x9c);
    return 0;
}

u32 ov103_021EDCE0(void *a0) {
    u32 idx = U8AT(PAT(a0, W_CHILD), 0x26);
    if (idx <= 5) {
        sub_02091004(PAT(a0, W_MAILBOX), U8AT(a0, W_SLOT), Party_GetMonByIndex(SaveArray_Party_Get(PAT(PAT(a0, W_ARGS), 0)), idx), 0x9c);
    }
    Heap_Free(PAT(a0, W_CHILD));
    return 8;
}

u32 ov103_021EDD14(void *a0) {
    void *c = PAT(a0, W_CHILD);
    U8AT(a0, W_RET21) = (U8AT(a0, W_RET21) & ~0x7f) | (U8AT(c, 0x26) & 0x7f);
    U8AT(a0, W_RET20) = U8AT(c, 0x27);
    Heap_Free(PAT(a0, W_CHILD));
    return 0;
}

u32 ov103_021EDD48(void *a0) {
    Heap_Free(PAT(a0, W_CHILD));
    return 8;
}
