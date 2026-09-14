#include "global.h"

extern void *ListMenu_ProcessInput(void *);
extern void ov49_0225B070(void *);
extern void PlaySE(int);
extern void DestroyListMenu(void *);
extern void sub_0200E5D4(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void RemoveWindow(void *);
extern void Sprite_SetDrawFlag(void *, int);
extern void GF_AssertFail(void);
extern void ov49_0225B058(void);
extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void DrawFrameAndWindow1(void *, int, int, int);
extern void *ListMenuInit(void *, void *, int, int);
extern void ScheduleWindowCopyToVram(void *);

typedef struct ListTemplate {
    u32 raw[4];
    u16 field10;
    u16 field12;
    u32 rest[3];
} ListTemplate;

typedef struct MenuState {
    u8 template_[0x20];
    u8 window[0x10];
    void *menu;
    void *entries;
    volatile u16 count;
    u16 field3A;
    u32 field3C;
    u8 pad40[0x10];
    void *sprites[2];
} MenuState;

BOOL ov49_0225AF08(MenuState *state, u32 value);
void ov49_0225AF30(MenuState *state, const ListTemplate *template_, void *context, void *list, u16 arg4, int arg5, u8 arg6, u8 arg7, u8 arg8);
s32 ov49_0225AFD8(MenuState *state);
void ov49_0225B014(MenuState *state, int unused1, int unused2);

BOOL ov49_0225AF08(MenuState *state, u32 value)
{
    int i;
    u8 *entry;
    i = 0;
    if (i < state->count) {
        entry = state->entries;
        do {
            if (value == *(u32 *)(entry + 4)) {
                return TRUE;
            }
            i++;
            entry += 8;
        } while (i < state->count);
    }
    return FALSE;
}

void ov49_0225AF30(MenuState *state, const ListTemplate *template_, void *context, void *list, u16 arg4, int arg5, u8 arg6, u8 arg7, u8 arg8)
{
    if (state->menu != NULL) {
        GF_AssertFail();
    }
    if (template_->field12 * 2 >= 0x12) {
        GF_AssertFail();
    }
    *(ListTemplate *)state = *template_;
    *(void **)((u8 *)state + 0xc) = state->window;
    state->field3A = template_->field10;
    *(void **)((u8 *)state + 4) = ov49_0225B058;
    AddWindowParameterized(*(void **)context, state->window, 1, (u8)arg6, (u8)arg7, (u8)arg8, (u8)(template_->field12 * 2), 5, 0xca);
    FillWindowPixelBuffer(state->window, 0xf);
    DrawFrameAndWindow1(state->window, 1, 0x55, 3);
    state->menu = ListMenuInit(state, list, arg4, (u8)arg5);
    ScheduleWindowCopyToVram(state->window);
}

s32 ov49_0225AFD8(MenuState *state)
{
    s32 result;
    if (state->menu == NULL) {
        return -2;
    }
    result = (s32)ListMenu_ProcessInput(state->menu);
    switch (result) {
    case -2:
    case -1:
        ov49_0225B070(state);
        break;
    default:
        PlaySE(0x5dc);
        break;
    }
    return result;
}

void ov49_0225B014(MenuState *state, int unused1, int unused2)
{
    int i;
    if (state->menu != NULL) {
        DestroyListMenu(state->menu);
        state->menu = NULL;
        sub_0200E5D4(state->window, 1);
        ClearWindowTilemapAndScheduleTransfer(state->window);
        RemoveWindow(state->window);
        state->field3C = 0;
        for (i = 0; i < 2; i++) {
            Sprite_SetDrawFlag(state->sprites[i], FALSE);
        }
    }
}
