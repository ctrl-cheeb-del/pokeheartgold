#ifndef TO45_OV39_R16_PRIVATE_H
#define TO45_OV39_R16_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "gf_gfx_planes.h"

typedef struct OverlayManager OverlayManager;

typedef struct Ov39R16App {
    void *args;
    BgConfig *bgConfig;
    int state;
    u8 pad0C[0x20 - 0x0C];
    void *messageFormat;
    void *msgData24;
    void *msgData28;
    void *msgData2C;
    u8 pad30[4];
    void *string34;
    void *string38;
    void *string3C;
    u8 pad40[0x90 - 0x40];
    u32 textFrameDelay;
    u32 substate;
    u32 timer;
    u32 unk9C;
    u8 padA0[8];
    void *sysTask;
    void *unkAC;
} Ov39R16App;

extern BOOL (*ov39_0222AA20[])(Ov39R16App *);
void *OverlayManager_GetData(OverlayManager *manager);
BOOL IsPaletteFadeFinished(void);
void SysTask_Destroy(void *task);
void DestroyMsgData(void *msgData);
void MessageFormat_Delete(void *messageFormat);
void String_Delete(void *string);
void ov39_02228948(Ov39R16App *app);
void Heap_Free(void *ptr);
void ov39_022285A8(void *bgConfig);
void Main_SetVBlankIntrCB(void (*callback)(void *), void *arg);
void HBlankInterruptDisable(void);
void GF_DestroyVramTransferManager(void);
void sub_02021238(void);
void TextFlags_SetCanABSpeedUpPrint(BOOL enable);
void TextFlags_SetAutoScrollParam(int param);
void TextFlags_SetCanTouchSpeedUpPrint(BOOL enable);
void sub_0203A914(void);
void OverlayManager_FreeData(OverlayManager *manager);
void GfGfx_SwapDisplay(void);
void GF_RunVramTransferTasks(void);
void OamManager_ApplyAndResetBuffers(void);

typedef struct Ov39R16Templates {
    BgTemplate templates[2];
} Ov39R16Templates;

extern const GraphicsBanks ov39_0222A8E4;
extern const GraphicsModes ov39_0222A8D4;
extern const Ov39R16Templates ov39_0222A90C;
extern const Ov39R16Templates ov39_0222A944;

BOOL ov39_02228308(OverlayManager *manager, int *state);
BOOL ov39_02228370(OverlayManager *manager);
void ov39_02228418(Ov39R16App *app);
void ov39_02228440(void *bgConfig);

#endif
