#include "global.h"

typedef struct BankConfig59 {
    u32 word[10];
} BankConfig59;
typedef struct ListDesc59 {
    u16 count;
    u16 pad;
    const u8 *messages;
} ListDesc59;
typedef struct YesNoTemplate59 {
    void *bgConfig;
    u32 zero;
    u32 baseTile;
    u32 palette;
    u8 x;
    u8 y;
    u8 initialTouch : 4;
    u8 screen : 4;
    u8 padding;
} YesNoTemplate59;

extern const BankConfig59 ov59_0223C770;
extern const ListDesc59 ov59_0223C668[];
extern int TouchscreenListMenu_HandleInput(void *);
extern BOOL TouchscreenListMenu_WasLastInputTouch(void *);
extern void TouchscreenListMenu_Destroy(void *);
extern int YesNoPrompt_HandleInput(void *);
extern BOOL YesNoPrompt_IsInTouchMode(void *);
extern void YesNoPrompt_Reset(void *);
extern void SpriteSystem_TransferOam(void *);
extern void NNS_GfdDoVramTransfer(void);
extern void DoScheduledBgGpuUpdates(void *);
extern void GfGfx_SetBanks(const BankConfig59 *);
extern void FreeBgTilemapBuffer(void *, int);
extern void Heap_Free(void *);
extern void NARC_Delete(void *);
extern void G2x_SetBlendAlpha_(u32, int, int, int, int);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void DestroyMsgData(void *);
extern void FontID_Release(int);
extern void FontID_Alloc(int, int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *MessageFormat_New_Custom(int, int, int);
extern void *String_New(int, int);
extern void *NewString_ReadMsgData(void *, int);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern void YesNoPrompt_Destroy(void *);
extern void *ListMenuItems_New(int, int);
extern void ListMenuItems_AppendFromMsgData(void *, void *, u8, int);
extern void YesNoPrompt_InitFromTemplate(void *, const YesNoTemplate59 *);
extern void Sprite_SetOamMode(void *, int);
extern void Sprite_SetDrawPriority(void *, int);
extern void ov59_0223891C(u8 *, int);
extern void ov59_022387D0(u8 *, int);

int ov59_02238F24(u8 *state);
void ov59_02238F58(u8 *state);
int ov59_02238FB4(u8 *state);
void ov59_02238FF4(u8 *state, int mode);
void ov59_022393D4(u8 *state);
void ov59_02239408(void);
void ov59_022395B8(u8 *state);
void ov59_022396E4(u8 *state);
void ov59_02239704(u8 *state);
void ov59_0223978C(u8 *state);
void ov59_022398A0(u8 *state);
void ov59_022398CC(u8 *state);

void ov59_022393D4(u8 *state) {
    if (*(void **)(state + 0x24C) != NULL) {
        SpriteSystem_TransferOam(*(void **)(state + 0x24C));
    }
    NNS_GfdDoVramTransfer();
    DoScheduledBgGpuUpdates(*(void **)(state + 0x54));
    {
        vu32 *base = (vu32 *)0x027E0000;
        base[0x3FF8 / 4] |= 1;
    }
}

void ov59_02239408(void) {
    BankConfig59 config = ov59_0223C770;
    GfGfx_SetBanks(&config);
}
