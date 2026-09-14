#ifndef TO45_SOL_R6_OVERLAY_111_PRIVATE_H
#define TO45_SOL_R6_OVERLAY_111_PRIVATE_H

#include "global.h"

#include "system.h"

typedef struct OverlayManager OverlayManager;
typedef struct Ov111ArgsR6 {
    void *mons[2];
} Ov111ArgsR6;
typedef struct Ov111WorkR6 {
    u32 heapId;
    Ov111ArgsR6 *args;
    void *bgConfig;
    void *spriteSystem;
    void *spriteManager;
    void *sprite;
    void *yesNo;
    void *narc;
    void *animSystem;
    void *text;
    u8 pad28[4];
    int state;
    int substate;
} Ov111WorkR6;

typedef struct YesNoPromptTemplateR6 {
    void *bgConfig;
    int bgId;
    int tileStart;
    u32 plttSlot;
    u8 x;
    u8 y;
    u8 ignoreTouch : 4;
    u8 initialCursor : 4;
    u8 shape;
} YesNoPromptTemplateR6;

BOOL BugContestSwapMon_Init(OverlayManager *, int *);
BOOL BugContestSwapMon_Exit(OverlayManager *, int *);
BOOL BugContestSwapMon_Main(OverlayManager *, int *);
BOOL ov111_021E59E4(Ov111WorkR6 *);
BOOL ov111_021E5AA0(Ov111WorkR6 *);
void ov111_021E5BE4(Ov111WorkR6 *);
void ov111_021E5C54(Ov111WorkR6 *);

void *OverlayManager_GetData(OverlayManager *);
void ov111_021E5E34(OverlayManager *);
void ov111_021E5F04(OverlayManager *);
void BeginNormalPaletteFade(int, int, int, int, int, int, int);
BOOL IsPaletteFadeFinished(void);
void GF_AssertFail(void);
void *ov111_021E6A2C(void *);
BOOL ov111_021E6888(void *);
void ov111_021E68FC(void *, int);
void ov111_021E6738(void *, int, int, int, void *);
void *Mon_GetBoxMon(void *);
void BufferBoxMonSpeciesName(void *, int, void *);
BOOL System_GetTouchNew(void);
void PlaySE(int);
int YesNoPrompt_HandleInput(void *);
void YesNoPrompt_Reset(void *);
void ManagedSprite_SetDrawFlag(void *, int);
void ov111_021E6770(void *, int, void *, s16);
void ov111_021E5D08(void *, int);
void ov111_021E6784(void *);
BOOL ov111_021E67A4(void *);
void *ov111_021E6330(void *, void *, s16, s16, u8, u8);
void ManagedSprite_SetPaletteOverride(void *, int);
void YesNoPrompt_InitFromTemplate(void *, const YesNoPromptTemplateR6 *);

typedef BOOL (*Ov111StateFuncR6)(Ov111WorkR6 *);
extern const Ov111StateFuncR6 _021E6D40[];
#endif
