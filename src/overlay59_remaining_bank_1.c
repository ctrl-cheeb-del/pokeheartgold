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

int ov59_02238F24(u8 *state) {
    int result = TouchscreenListMenu_HandleInput(*(void **)(state + 0x298));
    if (result == -1) {
        return -1;
    }
    *(u32 *)(state + 0x40) = TouchscreenListMenu_WasLastInputTouch(*(void **)(state + 0x298));
    TouchscreenListMenu_Destroy(*(void **)(state + 0x298));
    return result;
}

void ov59_02238F58(u8 *state) {
    YesNoTemplate59 template;
    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = *(void **)(state + 0x54);
    template.zero = 0;
    template.baseTile = 0x6A;
    template.palette = 0xE;
    template.x = 0x19;
    template.y = 5;
    template.initialTouch = *(u32 *)(state + 0x40);
    template.screen = 1;
    YesNoPrompt_InitFromTemplate(*(void **)(state + 0x248), &template);
}

int ov59_02238FB4(u8 *state) {
    int result = YesNoPrompt_HandleInput(*(void **)(state + 0x248));
    int answer;
    switch (result) {
    case 1:
        answer = 1;
        break;
    case 2:
        answer = 0;
        break;
    default:
        return -1;
    }
    *(u32 *)(state + 0x40) = YesNoPrompt_IsInTouchMode(*(void **)(state + 0x248));
    YesNoPrompt_Reset(*(void **)(state + 0x248));
    return answer;
}

void ov59_02238FF4(u8 *state, int mode) {
    int i;
    u8 *cursor;
    if (mode == 1 || mode == 2) {
        for (i = 0, cursor = state; i < 7; i++, cursor += 4) {
            if (i == state[0x4D] && mode == 2) {
                Sprite_SetOamMode(*(void **)(cursor + 0x25C), 0);
            } else {
                Sprite_SetOamMode(*(void **)(cursor + 0x25C), 1);
            }
        }
        ov59_0223891C(state, 0);
        ov59_022387D0(state, 2);
        if (state[0x4D] < 7) {
            Sprite_SetDrawPriority(*(void **)(state + 0x254 + (state[0x4D] + 2) * 4), 2);
        }
    } else {
        u8 *cursor2;
        int j;
        j = 0;
        cursor2 = state;
        for (; j < 7; j++, cursor2 += 4) {
            Sprite_SetOamMode(*(void **)(cursor2 + 0x25C), 0);
        }
        ov59_0223891C(state, 1);
        ov59_022387D0(state, 0);
        if (state[0x4D] < 7) {
            Sprite_SetDrawPriority(*(void **)(state + 0x254 + (state[0x4D] + 2) * 4), 3);
        }
    }
}
