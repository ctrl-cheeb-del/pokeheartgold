#include "global.h"

#include "constants/sndseq.h"

#include "system.h"
#include "trainer_card_main_decomp_private.h"

typedef struct Banks40 {
    u32 words[10];
} Banks40;
typedef struct ObjTransfer16 {
    u32 words[4];
} ObjTransfer16;

extern const Banks40 ov51_021E7EA8;
extern const ObjTransfer16 ov51_021E7FCC;
extern void GfGfx_SetBanks(const void *);
extern void *GfGfxLoader_GetPlttData(int, int, void **, int);
extern void Heap_Free(void *);
extern void FillBgTilemapRect(void *, int, int, int, int, int, int, int);
extern void YesNoPrompt_Destroy(void *);
extern void RemoveWindow(void *);
extern void CopyWindowToVram(void *);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern int FontID_String_GetWidth(int, void *, int);
extern int AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);
extern void FillWindowPixelRect(void *, int, int, int, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void ScheduleWindowCopyToVram(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void Sprite_ResetAnimCtrlState(void *);
extern void Sprite_SetDrawFlag(void *, int);
extern void ObjCharTransfer_Init(const void *);
extern void ObjPlttTransfer_Init(int, int);
extern void ObjCharTransfer_ClearBuffers(void);
extern void ObjPlttTransfer_Reset(void);
extern void thunk_ClearMainOAM(int);
extern void thunk_ClearSubOAM(int);
extern void ov51_021E6AAC(TrainerCardMainState *, int *);
extern int ov51_021E6A54(TrainerCardMainState *);
extern void PlaySE(int);
extern void ov51_021E757C(void *, void *, void *);
extern int YesNoPrompt_HandleInput(void *);
extern int YesNoPrompt_IsInTouchMode(void *);
extern void YesNoPrompt_Reset(void *);
extern void ClearFrameAndWindow2(void *, int);
extern void *ScheduleBgTilemapBufferTransfer(void *, int);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern void String16_FormatInteger(void *, int, int, int, int);
extern void BgSetPosTextAndCommit(void *, int, int, int);
extern void DoScheduledBgGpuUpdates(void *);
extern void GF_RunVramTransferTasks(void);
extern void OamManager_ApplyAndResetBuffers(void);

void ov51_021E60D4(void);
void ov51_021E6200(int palette);
void ov51_021E6CCC(TrainerCardMainState *state);
void ov51_021E6EF0(TrainerCardMainState *state);
void ov51_021E71D0(TrainerCardMainState *state, void *windows);
void ov51_021E74D4(void *windows, u8 first, u8 last);
void ov51_021E7540(void *window, int right, int gap, int y, void *string);
void ov51_021E7664(void *window, int present, void *string);
void ov51_021E76A4(TrainerCardMainState *state);
void ov51_021E78D0(TrainerCardMainState *state, int clear);
void ov51_021E7D44(TrainerCardMainState *state, int sprite, int sequence, int draw);
void ov51_021E7D68(void);
void ov51_021E7DA4(u8 *pairs);
void ov51_021E6B44(TrainerCardMainState *state);
void ov51_021E6E10(TrainerCardMainState *state, int mode);
int ov51_021E6A54(TrainerCardMainState *state);
void ov51_021E6DA8(TrainerCardMainState *state, int update);
int ov51_021E786C(TrainerCardMainState *state, int keepFrame);
void ov51_021E77A0(TrainerCardMainState *state, int message);
void ov51_021E74F4(void *window, int right, int gap, int y, void *string, int value, u8 digits, int mode);
void ov51_021E69EC(TrainerCardMainState *state);
void ov51_021E6B88(TrainerCardMainState *state);
void ov51_021E6C00(void);
void ov51_021E6CF0(u8 *src, u8 *dst);

void ov51_021E69EC(TrainerCardMainState *state) {
    MtxFx22 matrix;
    matrix._00 = FX_Inv(*(fx32 *)&state->data[0x30fc]);
    matrix._01 = 0;
    matrix._10 = 0;
    matrix._11 = FX_Inv(*(fx32 *)&state->data[0x3100]);
    OS_WaitVBlankIntr();
    G2x_SetBGyAffine_(0x04001020, &matrix, 0x80, 0x60, 0, 0);
    G2x_SetBGyAffine_(0x04001030, &matrix, 0x80, 0x60, 0, 0);
    state->data[0x343a] &= ~4;
}

int ov51_021E6A54(TrainerCardMainState *state) {
    if (gSystem.newKeys & 1) {
        if (*(void **)&state->data[0x30f4] != NULL && (((u32)state->data[0x343a] << 30) >> 31) == 0) {
            PlaySE(SEQ_SE_DP_SELECT);
            return 4;
        }
    } else if (gSystem.newKeys & 2) {
        PlaySE(SEQ_SE_GS_GEARCANCEL);
        return 5;
    }
    if (gSystem.newKeys & 0x30) {
        return 3;
    }
    return 0;
}
