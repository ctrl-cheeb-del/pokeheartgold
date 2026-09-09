#ifndef POKEHEARTGOLD_SOUND_02004A44_H
#define POKEHEARTGOLD_SOUND_02004A44_H

#include <nitro.h>
#include <nnsys.h>

typedef struct UnkStruct_02004A44_0 {
    NNSSndWaveOutHandle *unk00;
    NNSSndWaveFormat unk04;
    void *unk08;
    u32 unk0c;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    s32 unk1c;
    u32 unk20;
    s32 unk24;
} UnkStruct_02004A44_0;

void sub_02004B10(void);
void GF_SndHandleMoveVolume(int, int, int);

void Sound_SetMasterVolume(int a0);
void sub_02005D00(void);
void GF_MicPauseOnLidClose(void);
void GF_MicResumeOnLidOpen(void);
BOOL SoundSys_GetGBSoundsState(void);
void SoundSys_ToggleGBSounds(void);
BOOL sub_02005738(int a0);
s8 *sub_020059D8(void);
void sub_02005600(int);
void sub_020058B8(int);
void sub_02005680(int);
NNSSndWaveOutHandle *sub_020055AC(int);
BOOL sub_020056E8(UnkStruct_02004A44_0 *wavParam, int);
void sub_02005774(int, int);
BOOL GF_MIC_StartAutoSampling(MICAutoParam *param);
void GF_MIC_StopAutoSampling(void);
BOOL PlayCryEx(u32 pattern, u16 species, int pan, int volume, int heapId, u8 form);
void sub_02004B24(int);
void BGM_SaveStateAndPlayNew(int a0);
u16 GF_GetCurrentPlayingBGM(); // Cannot put `void` in it since it's sometimes called with an argument (required for matching), sometimes not.
void sub_020053A8(u8 a0, u8 a1);
void GF_SND_BGM_DisableSet(u8 a0);
BOOL GF_SND_BGM_DisableCheck(void);
void sub_02004A60(u16 seqNo);
void GF_SetCurrentPlayingBGM(u16 seqNo);
u16 sub_02004AAC(void);
void sub_02004AB8(u16 seqNo);
void Sound_SetFieldBGM(u16 seqNo);
void sub_02004AFC(u8 scene);
BOOL sub_02005518(void);
void Sound_SetSceneAndPlayBGM(u8 scene, u16 seqNo, int unused);
void GF_SetVolumeBySeqNo(u16 a0, u16 a1);
void GF_SndHandleSetPlayerVolume(u32 a0, u32 a1);
void GF_SndHandleSetInitialVolume(s32 a0, s32 a1);
u16 GF_GetVolumeBySeqNo();

void sub_02005448(void);
void Sound_SetScene(int a0);
void sub_02005BEC(BOOL);

#endif // POKEHEARTGOLD_SOUND_02004A44_H
