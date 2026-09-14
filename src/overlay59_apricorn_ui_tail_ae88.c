#include "global.h"

extern const u32 ov59_0223C954[];

extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern void ClearWindowTilemapAndScheduleTransfer(void *);
extern void FillWindowPixelBuffer(void *, int);
extern BOOL IsPaletteFadeFinished(void);
extern void PlaySE(int);
extern void ReadMsgDataIntoString(void *, int, void *);
extern void ScheduleWindowCopyToVram(void *);
extern BOOL Sprite_IsAnimated(void *);
extern void Sprite_ResetAnimCtrlState(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void Sprite_SetDrawFlag(void *, BOOL);
extern int ov59_0223B358(void *);
extern int ov59_0223B3B0(void *, int *);
extern void ov59_0223BBB0(void *);
extern void ov59_0223BBD4(void *, int);
extern void ov59_0223C054(void *);
extern void ov59_0223C138(void *);

void ov59_0223AEB0(u8 *, int);
void ov59_0223AF7C(void *);
int ov59_0223AF9C(u8 *);

int ov59_0223AF9C(u8 *p) {
    switch (*(u16 *)(p + 0x42)) {
    case 0:
        if (Sprite_IsAnimated(*(void **)(p + 0x260))) {
            return FALSE;
        }
        ov59_0223AEB0(p, 3);
        ov59_0223BBB0(p);
        ov59_0223BBD4(p, 0);
        Sprite_SetDrawFlag(*(void **)(p + 0x268), TRUE);
        Sprite_SetAnimCtrlSeq(*(void **)(p + 0x268), 10);
        Sprite_ResetAnimCtrlState(*(void **)(p + 0x268));
        PlaySE(0x921);
        (*(u16 *)(p + 0x42))++;
        break;
    case 1:
        if (Sprite_IsAnimated(*(void **)(p + 0x268))) {
            return FALSE;
        }
        Sprite_SetAnimCtrlSeq(*(void **)(p + 0x268), 11);
        Sprite_ResetAnimCtrlState(*(void **)(p + 0x268));
        (*(u16 *)(p + 0x42))++;
        break;
    case 2:
        if (Sprite_IsAnimated(*(void **)(p + 0x268))) {
            return FALSE;
        }
        ov59_0223C054(p);
        (*(u16 *)(p + 0x42))++;
        break;
    case 3:
        if (p[0x4f] != 0) {
            return FALSE;
        }
        Sprite_SetDrawFlag(*(void **)(p + 0x268), FALSE);
        ov59_0223C138(p);
        (*(u16 *)(p + 0x42))++;
        break;
    case 4:
        if (p[0x4f] != 0) {
            return FALSE;
        }
        *(u16 *)(p + 0x42) = 6;
        break;
    case 5:
        if (IsPaletteFadeFinished()) {
            BeginNormalPaletteFade(0, 1, 1, 0x7fff, 6, 2, *(u32 *)p);
            (*(u16 *)(p + 0x42))++;
        }
        break;
    default:
        if (IsPaletteFadeFinished()) {
            *(u16 *)(p + 0x42) = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}
