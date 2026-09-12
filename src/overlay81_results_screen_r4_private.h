#ifndef POKEHEARTGOLD_OVERLAY81_RESULTS_SCREEN_R4_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY81_RESULTS_SCREEN_R4_PRIVATE_H

#include "global.h"

#define OV81_R4_PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define OV81_R4_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef struct Ov81R4Banks {
    u32 words[10];
} Ov81R4Banks;

extern int ov81_02240FA4(void *, int, void *);
extern int ov81_0224086C(void *, int);
extern void sub_02037BEC(void);
extern void sub_02037AC0(int);
extern int sub_02037B38(int);
extern void BeginNormalPaletteFade(int, int, int, int, int, int, int);
extern BOOL IsPaletteFadeFinished(void);
extern void PokepicManager_HandleLoadImgAndOrPltt(void *);
extern void PaletteData_PushTransparentBuffers(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern void GF_RunVramTransferTasks(void);
extern void OamManager_ApplyAndResetBuffers(void);
extern void GfGfx_SetBanks(const Ov81R4Banks *);
extern const Ov81R4Banks ov81_0224356C;
extern void ov81_02240230(void *);
extern void *PaletteData_Init(int);
extern void PaletteData_AllocBuffers(void *, int, int, int);
extern void ov81_02240770(void);
extern void ov81_02240728(void *, int);
extern void ov81_02240698(void *, int);
extern void ov81_022406E0(void *, int);
extern void BgSetPosTextAndCommit(void *, int, int, int);
extern void GfGfx_EngineATogglePlanes(int, int);
extern void ov81_022407A8(void *, int);
extern void Delete2dMenu(void *, int);
extern void ov81_022413E0(void *);
extern void ov81_02242FC8(void *);
extern void ov80_0222A7CC(void *, int);
extern void *Party_GetMonByIndex(void *, int);
extern void *Mon_GetBoxMon(void *);
extern void ov81_022408B8(void *, int, void *);
extern int Options_GetFrame(void *);
extern void ov81_02243028(void *, int);
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern int Options_GetTextFrameDelay(void *);
extern int ov81_0224080C(void *, void *, int, int, int, int, int, int, int, int);
extern void ScheduleWindowCopyToVram(void *);
extern int TextPrinterCheckActive(int);

int ov81_02240008(void *work);
int ov81_02240048(void *work);
int ov81_02240088(void *work);
int ov81_022400D0(void *work);
void ov81_022401C8(void *work);
void ov81_02240210(void);
void ov81_022403C0(void *work);

#endif // POKEHEARTGOLD_OVERLAY81_RESULTS_SCREEN_R4_PRIVATE_H
