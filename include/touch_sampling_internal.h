#ifndef POKEHEARTGOLD_TOUCH_SAMPLING_INTERNAL_H
#define POKEHEARTGOLD_TOUCH_SAMPLING_INTERNAL_H
#include "global.h"

#include "system.h"
#include "unk_020210A0.h"
typedef struct TouchState {
    TPData *buffer;
    u32 capacity, count;
    TPData samples[9];
    u32 write;
    u16 mode, paused;
} TouchState;
typedef struct TouchOutput {
    u16 count;
    TPData samples[8];
} TouchOutput;
void TP_RequestAutoSamplingStartAsync(u16, u16, TPData *, u16);
void TP_RequestAutoSamplingStopAsync(void);
void TP_WaitBusy(u32);
u32 TP_CheckBusy(u32);
u16 TP_GetLatestIndexInAuto(void);
extern TouchState _021D2198;
#define STATE _021D2198
#define FLAGS (*(struct TouchFlags *)((u8 *)&STATE + 0x40))
struct TouchFlags {
    u8 pad[24];
    u16 mode, paused;
};
void GF_TouchpadInit(void);
void sub_020210BC(void);
BOOL sub_020210D8(TPData *data, u32 capacity, u32 frequency);
BOOL sub_02021148(int frequency);
void sub_020211AC(u16 mode, u8 autoRead, TPData *data, u32 capacity, u32 write, u32 count);
void sub_020211E0(TPData *data, int count);
int GF_TouchpadStopAutoSampling(void);
BOOL sub_02021238(void);
int sub_02021280(TouchOutput *out, int mode, u32 threshold);
void sub_020212EC(TPData *data, u32 count);
void GF_TouchpadResumeOnLidOpen(void);
void GF_TouchpadPauseOnLidClose(void);
int GF_TouchpadStartAutoSampling(u32 frequency);
int sub_020213C8(int mode, int latest, u32 threshold);
int sub_020213F8(int mode, int latest, u32 threshold);
int sub_020214B0(int mode, int latest, u32 threshold);
void sub_02021528(TouchOutput *out);
void sub_02021540(TouchOutput *out, int latest);

#endif
