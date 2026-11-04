#ifndef POKEHEARTGOLD_SOUND_PLAYBACK_H
#define POKEHEARTGOLD_SOUND_PLAYBACK_H

#include "global.h"

#include "constants/sndseq.h"

BOOL PlaySE(u16 sndseq);
void StopBGM(u16 sndseq, int fadeFrames);
BOOL PlaySEWithFieldBank(u16 sndseq);
void StopSEByHandle(int, int);
BOOL IsCryPlaying(void);
void StopCry(int);
BOOL PlaySE_SetPitch(u16 seqNo, int pitch);
BOOL IsSEPlaying(u16 sndseq);
void StopAllSE(int unused);
u32 GF_SndCountPlayingSeqBySeqNo(u16 seqNo);
void StopBGM(u16 a0, int fadeFrames);
BOOL PlayBGMOnBGMPlayerInField(u16 seqNo);
void StopSE(u16 sndseq, int fadeFrames);
BOOL PlayFanfare(u16 seqNo);
BOOL IsFanfarePlaying(void);
BOOL GF_IsAnySEPlaying(void);
void Sound_Stop(void);
void Sound_SetMasterVolume(int volume);
BOOL PlayCryDelayed(u16 species, u8 delay, u8 form);
BOOL PlaySE_SetPan(u16 seqNo, s32 pan);

#endif // POKEHEARTGOLD_SOUND_PLAYBACK_H
