#ifndef POKEHEARTGOLD_UNK_02005D10_H
#define POKEHEARTGOLD_UNK_02005D10_H

#include "global.h"

#include "constants/sndseq.h"

BOOL PlaySE(u16 sndseq);
void StopBGM(u16 sndseq, int a1);
BOOL sub_02006088(u16 sndseq);
void sub_0200615C(int, int);
BOOL IsCryFinished(void);
void sub_02006300(int);
BOOL PlaySE_SetPitch(u16 seqNo, int pitch);
BOOL IsSEPlaying(u16 sndseq);
void sub_0200616C(int a0);
u32 sub_02005F94(u16 a0);
void StopBGM(u16 a0, int a1);
BOOL sub_02005E44(u16 a0);
void StopSE(u16 sndseq, int a1);
void PlayFanfare(u16 a0);
BOOL IsFanfarePlaying(void);
BOOL GF_IsAnySEPlaying(void);
void Sound_Stop(void);
void Sound_SetMasterVolume(int volume);
BOOL sub_020062E0(u16 species, u8 delay, u8 form);
BOOL sub_0200602C(u16 seqNo, s32 pan);

#endif // POKEHEARTGOLD_UNK_02005D10_H
