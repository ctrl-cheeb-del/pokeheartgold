#ifndef PRIVATE_UNK_020163E0_H
#define PRIVATE_UNK_020163E0_H

#include "global.h"

typedef struct PaletteFadeTask PaletteFadeTask;
typedef void (*PaletteApplyFunc)(PaletteFadeTask *, const u16 *);

struct PaletteFadeTask {
    void *task;
    PaletteApplyFunc apply;
    void *paletteData;
    u16 source[16];
    u16 current[16];
    u8 buffer;
    u8 palette;
    u8 state;
    u8 timer;
};

void DestroySysTaskAndEnvironment(void *task);
void BG_LoadPlttData(u32 location, const void *source, u32 size, u32 offset);
void PaletteData_LoadPalette(void *paletteData, const void *source, u32 buffer, u32 offset, u32 size);
void *CreateSysTaskAndEnvironment(void (*callback)(void *, void *), u32 size, u32 priority);
void *SysTask_GetData(void *task);
void *PaletteData_GetUnfadedBuf(void *paletteData, u32 buffer);
void *GetMainBgPlttAddr(void);
void *GetSubBgPlttAddr(void);

PaletteFadeTask *sub_020163E0(void *paletteData, u32 buffer, u32 palette);
void sub_0201649C(PaletteFadeTask *state, u32 command);
void sub_020164C4(PaletteFadeTask *state);
void sub_020164D0(void *task, void *data);
BOOL sub_02016548(PaletteFadeTask *state);
void sub_020165A4(PaletteFadeTask *state, const u16 *source);
void sub_020165BC(PaletteFadeTask *state, const u16 *source);
void sub_020165D4(PaletteFadeTask *state, const u16 *source);
void sub_020165F0(PaletteFadeTask *state, const u16 *source);

#endif
