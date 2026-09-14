#include "global.h"

#include "font.h"
#include "heap.h"
#include "menu_input_state.h"
#include "msgdata.h"
#include "overlay_manager.h"
#include "pm_string.h"
#include "render_text.h"
#include "screen_fade.h"
#include "sound_02004A44.h"
#include "sprite.h"
#include "system.h"

typedef struct TrainerCardMainInitState {
    u8 data[0x3444];
} TrainerCardMainInitState;

typedef struct TrainerCardMessages {
    u8 padding[0x33c4];
    MsgData *msgData;
    String *string4;
    String *string5;
    String *string32;
    String *string10;
    String *group3[3];
    String *group2[2];
    String *group14[14];
} TrainerCardMessages;

extern void ov51_021E6C00(void);
extern void ov51_021E6038(TrainerCardMainInitState *state);
extern void ov51_021E7CA4(void *sprites);
extern void ov51_021E6EF0(TrainerCardMainInitState *state);
extern void ov51_021E6644(void *bgConfig);
extern void sub_02021238(void);
extern int ov51_021E6B44(TrainerCardMainInitState *work);
extern void ov51_021E7D44(void *sprites, int sprite, int sequence, int draw);
extern void ov51_021E6DA8(TrainerCardMainInitState *work, int update);
extern int ov51_021E6888(TrainerCardMainInitState *work);
extern int ov51_021E67A4(TrainerCardMainInitState *work);

int TrainerCardMainApp_Main(OverlayManager *manager, int *state);
int TrainerCardMainApp_Exit(OverlayManager *manager, int *state);
void ov51_021E5F64(TrainerCardMainInitState *work);
void ov51_021E6038(TrainerCardMainInitState *work);

int TrainerCardMainApp_Main(OverlayManager *manager, int *state) {
    TrainerCardMainInitState *work = OverlayManager_GetData(manager);

    switch (*state) {
    case 0:
        if (IsPaletteFadeFinished()) {
            *state = 1;
        }
        break;
    case 1: {
        int input = ov51_021E6B44(work);
        if (input == 3) {
            work->data[0x3436] = 0;
            *state = 3;
        } else if (input == 4) {
            ov51_021E7D44(&work->data[0x311c], 1, 3, 1);
            work->data[0x3436] = 0;
            *state = 4;
        } else if (input == 5) {
            ov51_021E7D44(&work->data[0x311c], 0, 1, 1);
            BeginNormalPaletteFade((enum FadeMode)1, (enum FadeType)4, (enum FadeType)4, 0, 6, 1, HEAP_ID_25);
            *state = 2;
        }
        ov51_021E6DA8(work, ((u32)((u8 *)*(void **)&work->data[0xe8])[4] << 30) >> 31);
        break;
    }
    case 2:
        if (IsPaletteFadeFinished()) {
            return TRUE;
        }
        break;
    case 3:
        if (ov51_021E6888(work)) {
            *state = 1;
        }
        break;
    case 4: {
        switch (ov51_021E67A4(work)) {
        case 1:
            *state = 1;
            break;
        case 2:
            *state = 5;
            break;
        }
        break;
    }
    case 5:
        BeginNormalPaletteFade((enum FadeMode)1, (enum FadeType)4, (enum FadeType)4, 0, 6, 1, HEAP_ID_25);
        *(u32 *)((u8 *)*(void **)&work->data[0xe4] + 0x674) = 1;
        *state = 2;
        break;
    }

    work->data[0x343f]++;
    if (work->data[0x343f] >= 0x80) {
        work->data[0x343f] = 0;
    }
    SpriteList_RenderAndAnimateSprites(*(SpriteList **)&work->data[0x311c]);
    return FALSE;
}

int TrainerCardMainApp_Exit(OverlayManager *manager, int *state) {
    TrainerCardMainInitState *work = OverlayManager_GetData(manager);

    ov51_021E6C00();
    ov51_021E6038(work);
    ov51_021E7CA4(&work->data[0x311c]);
    Heap_Free(*(void **)&work->data[0x30ec]);
    Heap_Free(*(void **)&work->data[0x33b8]);
    Heap_Free(*(void **)&work->data[0x33b0]);
    ov51_021E6EF0(work);
    ov51_021E6644(*(void **)&work->data[0]);
    sub_02021238();
    TextFlags_SetCanTouchSpeedUpPrint(FALSE);
    TextFlags_SetCanABSpeedUpPrint(FALSE);
    MenuInputStateMgr_SetState(*(MenuInputStateMgr **)((u8 *)*(void **)&work->data[0xe4] + 0x66c), *(MenuInputState *)&work->data[0x310c]);
    OverlayManager_FreeData(manager);
    Main_SetVBlankIntrCB(NULL, NULL);
    Heap_Destroy(HEAP_ID_25);
    GF_SndHandleSetPlayerVolume(1, 0x7f);
    return TRUE;
}

void ov51_021E5F64(TrainerCardMainInitState *work) {
    TrainerCardMessages *messages = (TrainerCardMessages *)work;
    int i;

    FontID_Alloc(4, HEAP_ID_25);
    messages->msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, (NarcId)0x1b, 0x2d7, HEAP_ID_25);
    messages->string4 = String_New(4, HEAP_ID_25);
    messages->string32 = String_New(0x20, HEAP_ID_25);
    messages->string10 = String_New(10, HEAP_ID_25);
    messages->string5 = String_New(5, HEAP_ID_25);
    ReadMsgDataIntoString(messages->msgData, 11, messages->string5);
    for (i = 0; i < 3; i++) {
        messages->group3[i] = NewString_ReadMsgData(messages->msgData, i + 14);
    }
    for (i = 0; i < 2; i++) {
        messages->group2[i] = NewString_ReadMsgData(messages->msgData, i + 17);
    }
    for (i = 0; i < 14; i++) {
        messages->group14[i] = NewString_ReadMsgData(messages->msgData, i);
    }
}

void ov51_021E6038(TrainerCardMainInitState *work) {
    int i;
    u32 offset;
    u8 *walker;

    offset = 0x33ec;
    i = 0;
    walker = (u8 *)work;
    for (; i < 14; i++, walker += 4) {
        String_Delete(*(String **)(walker + offset));
    }
    String_Delete(*(String **)&work->data[0x33e8]);
    String_Delete(*(String **)&work->data[0x33e4]);
    String_Delete(*(String **)&work->data[0x33e0]);
    String_Delete(*(String **)&work->data[0x33dc]);
    String_Delete(*(String **)&work->data[0x33d8]);
    String_Delete(*(String **)&work->data[0x33cc]);
    String_Delete(*(String **)&work->data[0x33d4]);
    String_Delete(*(String **)&work->data[0x33d0]);
    String_Delete(*(String **)&work->data[0x33c8]);
    DestroyMsgData(*(MsgData **)&work->data[0x33c4]);
    FontID_Release(4);
}
