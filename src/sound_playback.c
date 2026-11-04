#include "sound_playback.h"

#include <nnsys/snd_internal.h>

#include "global.h"

#include "constants/species.h"

#include "heap.h"
#include "sound.h"
#include "sound_gb.h"
#include "sound_playback_internal.h"
#include "sound_radio.h"
#include "sound_system.h"
#include "sound_system_internal.h"
#include "sys_task_api.h"

// Starting and stopping sequences by kind: BGM, sound effects, Pokemon cries and fanfares (the BGM is paused
// meanwhile). Sound_StartSeq substitutes the GB-sounds version of a sequence when that option is on.

typedef struct CryStopTaskData {
    int frames;
    SysTask *task;
} CryStopTaskData;

// Cry-bank numbering extends beyond the ordinary species IDs.
#define CRY_BANK_SHAYMIN_SKY 494
#define CRY_BANK_MAX         495

static void Sound_OnBGMStarted(u16 seqNo, enum SoundHandleNo handleNo);
static BOOL PlayBGMOnBGMPlayer(u16 seqNo, int playerNo, enum SoundHandleNo handleNo);
static BOOL PlayBGMOnFieldPlayer(u16 seqNo, int playerNo, enum SoundHandleNo handleNo);
static void ClearPlayingBGM(void);
static BOOL PlaySEEx(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, int seqNo);
static void Sound_SetInitialVolumeWithVoiceChat(int species, int handleNo, int volume);
static void StartCryStopTask(int frames, int heapId);
static void CryStopTask(SysTask *task, void *arg);
static void DestroyCryStopTask(void);
static BOOL IsShayminSkyCry(u16 species, u8 form);
static void ClearQueuedCries(void);
static BOOL PlayChorusCryWithPitch(u16 species, int pitch, u8 form);
static void PlayReversedCry(u16 species, int unused, int volume, int pan, int heapId);
static void StopFanfare(int fadeFrames);
static void StartFanfareWaitTimer(u16 unused);
static BOOL Sound_StartSeq(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

// NitroSystem

BOOL PlayBGMDirect(u16 seqNo) {
    BOOL success;
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
    success = Sound_StartSeq(handleNo, -1, -1, -1, seqNo, 1);
    if (!success) {
        GF_SndOnStartSeqFailed(seqNo);
    }
    Sound_OnBGMStarted(seqNo, handleNo);
    return success;
}

BOOL PlayBGM(u16 seqNo) {
    int playerNo = GF_GetPlayerNoBySeq(seqNo);
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(playerNo);
    BOOL success;
    if (playerNo == PLAYER_BGM) {
        success = PlayBGMOnBGMPlayer(seqNo, playerNo, handleNo);
    } else if (playerNo == PLAYER_FIELD) {
        success = PlayBGMOnFieldPlayer(seqNo, playerNo, handleNo);
    } else {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    Sound_SetReloadFieldSeqFlag(0);
    if (!success) {
        GF_SndOnStartSeqFailed(seqNo);
    }
    Sound_OnBGMStarted(seqNo, handleNo);
    return success;
}

static void Sound_OnBGMStarted(u16 seqNo, enum SoundHandleNo handleNo) {
    Sound_SetCurrentBGM(seqNo);
    Sound_ApplyVoiceChatVolume(seqNo, handleNo);
    GF_SndSetState(1);
    if (handleNo == SND_HANDLE_FIELD) {
        GF_SndWorkSetGbSoundsVolume(128);
    }
}

static BOOL PlayBGMOnBGMPlayer(u16 seqNo, int playerNo, enum SoundHandleNo handleNo) {
    GF_Snd_LoadState(Sound_GetSavedHeapLevel(3));
    GF_Snd_LoadSeq(seqNo);
    return Sound_StartSeq(handleNo, -1, -1, -1, seqNo, 1);
}

static BOOL PlayBGMOnFieldPlayer(u16 seqNo, int playerNo, enum SoundHandleNo handleNo) {
    GF_SdatGetAttrPtr(SOUND_ATTR_RELOAD_FIELD_SEQ);
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(SOUND_ATTR_FIELD_SEQ);
    Sound_ReloadFieldSceneData(seqNo, GF_GetBankBySeqNo(GF_NNS_SndPlayerGetSeqNo(GF_GetSoundHandle(SND_HANDLE_FIELD))));
    SndRadio_StopSeq(0);
    return Sound_StartSeq(handleNo, -1, GF_GetBankBySeqNo(*fieldSeqNo), -1, seqNo, 1);
}

BOOL PlayBGMOnBGMPlayerInField(u16 seqNo) {
    BOOL success;
    u8 *scene = GF_SdatGetAttrPtr(SOUND_ATTR_PRIMARY_SCENE);
    if (*scene != 4) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    if (GF_GetPlayerNoBySeq(seqNo) != PLAYER_BGM) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    GF_Snd_LoadSeqEx(seqNo, 1);
    success = Sound_StartSeq(SND_HANDLE_BGM, -1, -1, -1, seqNo, 1);
    if (!success) {
        GF_SndOnStartSeqFailed(seqNo);
    }
    SndRadio_StopSeq(0);
    Sound_SetCurrentBGM(seqNo);
    GF_SndSetState(1);
    return success;
}

void StopBGM(u16 seqNo, int fadeFrames) {
    NNS_SndPlayerStopSeqBySeqNo(seqNo, fadeFrames);
    u16 gbSeqNo = GBSounds_GetGBSeqNoByDSSeqNo(seqNo);
    if (seqNo != gbSeqNo) {
        NNS_SndPlayerStopSeqBySeqNo(gbSeqNo, fadeFrames);
    }
    int playerNo = GF_GetPlayerNoBySeq(seqNo);
    if (playerNo != SOUND_PLAYER_NONE) {
        NNS_SndHandleReleaseSeq(GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(playerNo)));
    }
    ClearPlayingBGM();
}

static void ClearPlayingBGM(void) {
    SndRadio_StopSeq(0);
    Sound_SetCurrentBGM(SEQ_NONE);
    GF_SetCurrentPlayingBGM(SEQ_NONE);
    Sound_SetPlayingGBSeqNo(0);
    GF_SndSetState(0);
}

void GF_SndStartFadeInBGM(u32 volume, u32 frames, BOOL keepVolume) {
    int playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != SOUND_PLAYER_NONE) {
        enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(playerNo);
        if (keepVolume == FALSE) {
            GF_SndHandleMoveVolume(handleNo, 0, 0);
        }
        GF_SndHandleMoveVolume(handleNo, volume, frames);
        GF_SndSetFadeTimer(frames);
        GF_SndSetState(3);
    }
}

void GF_SndStartFadeOutBGM(u16 volume, u16 frames) {
    int playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != SOUND_PLAYER_NONE) {
        if (GF_SndGetFadeTimer() == 0) {
            GF_SndHandleMoveVolume(GF_GetSndHandleByPlayerNo(playerNo), volume, frames);
            GF_SndSetFadeTimer(frames);
        }
        GF_SndSetState(4);
    }
}

u32 GF_SndGetFadeTimer(void) {
    u16 *timer = GF_SdatGetAttrPtr(SOUND_ATTR_FADE_TIMER);
    return *timer;
}

u32 GF_SndCountPlayingSeqBySeqNo(u16 seqNo) {
    return GF_SndPlayerCountPlayingSeqByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
}

void Sound_Stop(void) {
    u8 *firstActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_14_ALLOCATED);
    u8 *secondActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_15_ALLOCATED);
    NNS_SndPlayerStopSeqAll(0);
    if (*firstActive == 1) {
        Sound_StopWaveOut(14);
    }
    if (*secondActive == 1) {
        Sound_StopWaveOut(15);
    }
    GF_SndSetState(0);
}

void StopBGMSEAndCry(void) {
    u8 *firstActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_14_ALLOCATED);
    u8 *secondActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_15_ALLOCATED);
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_BGM), 0);
    ClearPlayingBGM();
    for (int i = 0; i < 4; i++) {
        StopSEByHandle(i + SND_HANDLE_SE_1, 0);
    }
    StopCry(0);
    if (*firstActive == 1) {
        Sound_StopWaveOut(14);
    }
    if (*secondActive == 1) {
        Sound_StopWaveOut(15);
    }
}

BOOL PlaySE_SetPan(u16 seqNo, s32 pan) {
    BOOL success = PlaySE(seqNo);
    SetSeqTrackPan(seqNo, 0xFFFF, pan);
    return success;
}

BOOL PlaySE(u16 seqNo) {
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
    return PlaySEEx(handleNo, -1, -1, -1, seqNo);
}

BOOL PlaySEOnPlayer(u16 seqNo, int playerNo) {
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(playerNo);
    return PlaySEEx(handleNo, playerNo, -1, -1, seqNo);
}

BOOL PlaySEWithFieldBank(u16 seqNo) {
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(SOUND_ATTR_FIELD_SEQ);
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
    return PlaySEEx(handleNo, -1, GF_GetBankBySeqNo(*fieldSeqNo), -1, seqNo);
}

static BOOL PlaySEEx(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, int seqNo) {
    if (Sound_IsSelectSEMuted() == TRUE && (seqNo == SEQ_SE_DP_SELECT || seqNo == SEQ_SE_DP_DECIDE)) {
        return FALSE;
    }
    BOOL success = Sound_StartSeq(handleNo, playerNo, bankNo, playerPrio, seqNo, 0);
    Sound_ApplyVoiceChatVolume(seqNo, handleNo);
    if (!success) {
        GF_SndOnStartSeqFailed(seqNo);
    }
    return success;
}

BOOL PlaySE_SetVolume(u16 seqNo, u16 volume) {
    BOOL success = PlaySE(seqNo);
    if (success) {
        GF_SetVolumeBySeqNo(seqNo, volume);
    }
    return success;
}

BOOL PlaySE_SetPitch(u16 seqNo, int pitch) {
    BOOL success = PlaySE(seqNo);
    if (success) {
        GF_SndSetTrackPitchBySeqNo(seqNo, 0xFFFF, pitch);
    }
    return success;
}

void StopSE(u16 seqNo, int fadeFrames) {
    NNS_SndPlayerStopSeqBySeqNo(seqNo, fadeFrames);
}

void StopSEByHandle(int handleNo, int fadeFrames) {
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(handleNo), fadeFrames);
}

void StopAllSE(int unused) {
    for (int i = 0; i < 4; i++) {
        StopSEByHandle(i + SND_HANDLE_SE_1, 0);
    }
}

BOOL IsSEPlaying(u16 seqNo) {
    return GF_SndPlayerCountPlayingSeqByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
}

u32 GF_SndCountPlayingSeqOnPlayer(u32 playerNo) {
    return GF_SndPlayerCountPlayingSeqByPlayerNo(playerNo);
}

BOOL GF_IsAnySEPlaying(void) {
    for (int i = 0; i < 4; i++) {
        if (GF_SndPlayerCountPlayingSeqByPlayerNo(PLAYER_SE_1 + i) == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

void SetSeqTrackPan(u16 seqNo, u32 trackMask, int pan) {
    NNSSndHandle *handle = GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo)));
    NNS_SndPlayerSetTrackPan(handle, trackMask, pan);
}

void SetPlayerPan(int playerNo, int pan) {
    NNS_SndPlayerSetTrackPan(GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(playerNo)), 0xFFFF, pan);
}

void SetAllSEPan(int pan) {
    enum SoundHandleNo firstHandle = GF_GetSndHandleByPlayerNo(PLAYER_SE_1);
    for (int i = 0; i < 4; i++) {
        NNS_SndPlayerSetTrackPan(GF_GetSoundHandle(firstHandle + i), 0xFFFF, pan);
    }
}

BOOL PlayCry(u16 species, u8 form) {
    u8 *useChorus = GF_SdatGetAttrPtr(SOUND_ATTR_USE_CHORUS);
    SOUND_CHATOT **chatot = GF_SdatGetAttrPtr(SOUND_ATTR_MY_CHATOT);
    u8 *keepPlaying = GF_SdatGetAttrPtr(SOUND_ATTR_KEEP_PLAYING_CRIES);
    BOOL success;
    if (IsShayminSkyCry(species, form) == 1) {
        species = CRY_BANK_SHAYMIN_SKY;
    }
    if (species != CRY_BANK_SHAYMIN_SKY && (species > CRY_BANK_MAX || species == 0)) {
        species = SPECIES_BULBASAUR;
    }
    if (species == SPECIES_CHATOT && Chatot_PlayCry(*chatot, 0, 127, 0) == 1) {
        Chatot_SetForceDefaultCry(0);
        return TRUE;
    }
    if (*useChorus == 0) {
        if (*keepPlaying == 0) {
            StopCry(0);
        }
        success = Sound_StartSeq(SND_HANDLE_PV, -1, species, -1, 2, 0);
        Sound_ApplyVoiceChatVolume(species, SND_HANDLE_PV);
    } else {
        success = Sound_StartSeq(SND_HANDLE_CHORUS, -1, species, -1, 2, 0);
        Sound_ApplyVoiceChatVolume(species, SND_HANDLE_CHORUS);
    }
    Chatot_SetForceDefaultCry(0);
    return success;
}

BOOL PlayCryDelayed(u16 species, u8 delay, u8 form) {
    PlayCryDelayedEx(0, species, 0, 127, 11, delay, form);
    return TRUE;
}

void StopCry(int fadeFrames) {
    u8 *firstActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_14_ALLOCATED);
    u8 *secondActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_15_ALLOCATED);
    GF_SdatGetAttrPtr(SOUND_ATTR_REVERSED_CRY_STARTED);
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_PV), fadeFrames);
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_CHORUS), fadeFrames);
    if (*firstActive == 1) {
        Sound_StopWaveOutAndFreeBuffer(14);
        Sound_FreeWaveOutChannel(14);
    }
    if (*secondActive == 1) {
        Sound_StopWaveOutAndFreeBuffer(15);
        Sound_FreeWaveOutChannel(15);
    }
    Chatot_StopCry();
    ClearQueuedCries();
}

BOOL IsCryPlaying(void) {
    u8 *firstActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_14_ALLOCATED);
    u8 *secondActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_15_ALLOCATED);
    GF_SdatGetAttrPtr(SOUND_ATTR_REVERSED_CRY_STARTED);
    GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_DELAY_0);
    if (*firstActive == 1) {
        return Sound_IsWaveOutPlaying(14);
    }
    if (*secondActive == 1) {
        return Sound_IsWaveOutPlaying(15);
    }
    return GF_SndPlayerCountPlayingSeqByPlayerNo(PLAYER_PV);
}

BOOL PlayCryEx(u32 pattern, u16 species, int pan, int volume, int heapId, u8 form) {
    int wavePan;
    int chorusVolume;
    u8 *firstActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_14_ALLOCATED);
    u8 *secondActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_15_ALLOCATED);
    u8 *useChorus = GF_SdatGetAttrPtr(SOUND_ATTR_USE_CHORUS);
    u8 *chatotMode = GF_SdatGetAttrPtr(SOUND_ATTR_CHATOT_PLAYING);
    GF_SdatGetAttrPtr(SOUND_ATTR_MY_CHATOT);
    if (IsShayminSkyCry(species, form) == 1) {
        species = CRY_BANK_SHAYMIN_SKY;
    }
    if (species != CRY_BANK_SHAYMIN_SKY && (species > CRY_BANK_MAX || species == 0)) {
        species = SPECIES_BULBASAUR;
    }
    wavePan = pan / 2 + 64;
    chorusVolume = volume - 30;
    if (chorusVolume <= 0) {
        chorusVolume = 1;
    }
    *useChorus = 0;
    if (*firstActive == 1) {
        Sound_StopWaveOutAndFreeBuffer(14);
        Sound_FreeWaveOutChannel(14);
    }
    if (*secondActive == 1) {
        Sound_StopWaveOutAndFreeBuffer(15);
        Sound_FreeWaveOutChannel(15);
    }
    if (species == SPECIES_CHATOT) {
        switch (pattern) {
        case 0:
        case 1:
        case 2:
        case 5:
        case 11:
        case 12:
            PlayCry(SPECIES_CHATOT, form);
            if (*chatotMode == 0) {
                GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
                Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
            } else if (*firstActive == 1) {
                Sound_SetWaveOutPan(14, wavePan);
                Sound_SetWaveOutVolume(14, volume);
            } else {
                GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
                Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
            }
            return TRUE;
        default:
            Chatot_SetForceDefaultCry(1);
            break;
        }
    }
    switch (pattern) {
    case 0:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        break;
    case 1:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        StartCryStopTask(20, heapId);
        break;
    case 2:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, 64);
        PlayChorusCryWithPitch(species, 20, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_CHORUS, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_CHORUS, chorusVolume);
        break;
    case 3:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        StartCryStopTask(30, heapId);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, 192);
        PlayChorusCryWithPitch(species, 16, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_CHORUS, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_CHORUS, chorusVolume);
        break;
    case 4:
        Sound_AllocWaveOutChannel(14);
        Sound_PlayReversedWaveArc(species, volume, wavePan, 14, heapId);
        Sound_SetWaveOutPan(14, wavePan);
        StartCryStopTask(15, heapId);
        Sound_SetWaveOutSpeed(14, 34304);
        PlayReversedCry(species, -64, chorusVolume, wavePan, heapId);
        Sound_SetWaveOutSpeed(15, 34304);
        break;
    case 5:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, -224);
        break;
    case 6:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, 44);
        PlayChorusCryWithPitch(species, -64, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_CHORUS, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_CHORUS, chorusVolume);
        break;
    case 7:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        StartCryStopTask(11, heapId);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, -128);
        break;
    case 8:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        StartCryStopTask(60, heapId);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, 60);
        break;
    case 9:
        Sound_AllocWaveOutChannel(14);
        Sound_PlayReversedWaveArc(species, volume, wavePan, 14, heapId);
        Sound_SetWaveOutPan(14, wavePan);
        StartCryStopTask(13, heapId);
        Sound_SetWaveOutSpeed(14, 26624);
        break;
    case 10:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        StartCryStopTask(100, heapId);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, -44);
        break;
    case 11:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, -96);
        break;
    case 12:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_PV, 0xFFFF, pan);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, volume);
        StartCryStopTask(20, heapId);
        GF_SndHandleSetTrackPitch(SND_HANDLE_PV, 0xFFFF, -96);
        break;
    case 13:
        PlayCry(species, form);
        Sound_SetInitialVolumeWithVoiceChat(species, SND_HANDLE_PV, 127);
        PlayChorusCryWithPitch(species, 20, form);
        GF_SndHandleSetTrackPan(SND_HANDLE_CHORUS, 0xFFFF, pan);
        GF_SndHandleMoveVolume(SND_HANDLE_CHORUS, volume, 0);
        break;
    case 14:
        PlayCry(species, form);
        break;
    }
    return TRUE;
}

static void Sound_SetInitialVolumeWithVoiceChat(int species, int handleNo, int volume) {
    GF_SndHandleSetInitialVolume(handleNo, volume);
    Sound_ApplyVoiceChatVolume(species, (enum SoundHandleNo)handleNo);
}

static void StartCryStopTask(int frames, int heapId) {
    SysTask **task = GF_SdatGetAttrPtr(SOUND_ATTR_CRY_STOP_TASK);
    DestroyCryStopTask();
    CryStopTaskData *data = Heap_Alloc((enum HeapID)heapId, sizeof(CryStopTaskData));
    if (data == NULL) {
        GF_ASSERT(FALSE);
        return;
    }
    memset(data, 0, sizeof(CryStopTaskData));
    data->frames = frames;
    data->task = SysTask_CreateOnMainQueue(CryStopTask, data, 0);
    *task = data->task;
}

static void CryStopTask(SysTask *task, void *arg) {
    CryStopTaskData *data = arg;
    u8 *firstActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_14_ALLOCATED);
    u8 *secondActive = GF_SdatGetAttrPtr(SOUND_ATTR_WAVE_OUT_15_ALLOCATED);
    if (data->frames == 10) {
        GF_SndHandleMoveVolume(SND_HANDLE_PV, 0, data->frames);
        GF_SndHandleMoveVolume(SND_HANDLE_CHORUS, 0, data->frames);
    }
    data->frames--;
    if (!IsCryPlaying()) {
        data->frames = 0;
    }
    if (data->frames <= 0) {
        StopCry(0);
        if (*firstActive == 1) {
            Sound_StopWaveOutAndFreeBuffer(14);
            Sound_FreeWaveOutChannel(14);
        }
        if (*secondActive == 1) {
            Sound_StopWaveOutAndFreeBuffer(15);
            Sound_FreeWaveOutChannel(15);
        }
        DestroyCryStopTask();
    }
}

static void DestroyCryStopTask(void) {
    SysTask **task = GF_SdatGetAttrPtr(SOUND_ATTR_CRY_STOP_TASK);
    if (*task != NULL) {
        void *data = SysTask_GetData(*task);
        SysTask_Destroy(*task);
        Heap_Free(data);
    }
    *task = NULL;
}

void PlayCryDelayedEx(int pattern, u16 species, int pan, int volume, int heapId, u8 delay, u8 form) {
    int *queuedPattern;
    u16 *queuedSpecies;
    int *queuedPan;
    int *queuedVolume;
    int *queuedHeapId;
    u8 *queuedDelay;
    u8 *queueNo = GF_SdatGetAttrPtr(SOUND_ATTR_CRY_QUEUE);
    u8 *alternateQueue = GF_SdatGetAttrPtr(SOUND_ATTR_KEEP_PLAYING_CRIES);
    if (*queueNo == 0) {
        queuedPattern = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PATTERN_0);
        queuedSpecies = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_SPECIES_0);
        queuedPan = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PAN_0);
        queuedVolume = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_VOLUME_0);
        queuedHeapId = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_HEAP_ID_0);
        queuedDelay = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_DELAY_0);
    } else {
        queuedPattern = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PATTERN_1);
        queuedSpecies = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_SPECIES_1);
        queuedPan = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PAN_1);
        queuedVolume = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_VOLUME_1);
        queuedHeapId = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_HEAP_ID_1);
        queuedDelay = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_DELAY_1);
    }
    if (*alternateQueue == 1) {
        *queueNo ^= 1;
    }
    if (IsShayminSkyCry(species, form) == 1) {
        species = CRY_BANK_SHAYMIN_SKY;
    }
    if (species != 0) {
        if (delay == 0) {
            PlayCryEx(pattern, species, pan, volume, heapId, form);
            return;
        }
        *queuedPattern = pattern;
        *queuedSpecies = species;
        *queuedPan = pan;
        *queuedVolume = volume;
        *queuedHeapId = heapId;
        *queuedDelay = delay;
    }
}

static BOOL IsShayminSkyCry(u16 species, u8 form) {
    if (species == SPECIES_SHAYMIN && form == 1) {
        return TRUE;
    }
    if (species == CRY_BANK_SHAYMIN_SKY) {
        return TRUE;
    }
    return FALSE;
}

static void ClearQueuedCries(void) {
    int *pattern0 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PATTERN_0);
    u16 *species0 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_SPECIES_0);
    int *pan0 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PAN_0);
    int *volume0 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_VOLUME_0);
    int *heap0 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_HEAP_ID_0);
    u8 *delay0 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_DELAY_0);
    int *pattern1 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PATTERN_1);
    u16 *species1 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_SPECIES_1);
    int *pan1 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_PAN_1);
    int *volume1 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_VOLUME_1);
    int *heap1 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_HEAP_ID_1);
    u8 *delay1 = GF_SdatGetAttrPtr(SOUND_ATTR_QUEUED_CRY_DELAY_1);
    *pattern0 = 0;
    *species0 = 0;
    *pan0 = 0;
    *volume0 = 0;
    *heap0 = 0;
    *delay0 = 0;
    *pattern1 = 0;
    *species1 = 0;
    *pan1 = 0;
    *volume1 = 0;
    *heap1 = 0;
    *delay1 = 0;
}

static BOOL PlayChorusCryWithPitch(u16 species, int pitch, u8 form) {
    u8 *useChorus = GF_SdatGetAttrPtr(SOUND_ATTR_USE_CHORUS);
    *useChorus = 1;
    Chatot_SetForceDefaultCry(1);
    BOOL success = PlayCry(species, form);
    GF_SndHandleSetTrackPitch(SND_HANDLE_CHORUS, 0xFFFF, pitch);
    return success;
}

static void PlayReversedCry(u16 species, int unused, int volume, int pan, int heapId) {
    u8 *useChorus = GF_SdatGetAttrPtr(SOUND_ATTR_USE_CHORUS);
    *useChorus = 1;
    Sound_AllocWaveOutChannel(15);
    Sound_PlayReversedWaveArc(species, volume, pan, 15, heapId);
}

BOOL PlayFanfare(u16 seqNo) {
    GF_GetBankInfoBySeqNo(seqNo);
    StartFanfareWaitTimer(seqNo);
    u8 playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != SOUND_PLAYER_NONE) {
        Sound_SetPlayerPause(playerNo, TRUE);
    } else {
        SndRadio_PausePlayer(TRUE);
    }
    GF_Snd_SaveState(GF_SdatGetAttrPtr(SOUND_ATTR_SAVED_HEAP_LEVEL_6));
    GF_Snd_LoadSeqEx(seqNo, 3);
    BOOL success = Sound_StartSeq(SND_HANDLE_ME, -1, -1, -1, seqNo, 0);
    Sound_ApplyVoiceChatVolume(seqNo, SND_HANDLE_ME);
    return success;
}

BOOL IsFanfarePlayingOrWaiting(void) {
    u16 *waitTimer = GF_SdatGetAttrPtr(SOUND_ATTR_AFTER_FANFARE_WAIT_TIMER);
    if (GF_SndPlayerCountPlayingSeqByPlayerNo(PLAYER_ME) != 0) {
        return TRUE;
    }
    if (*waitTimer != 0) {
        (*waitTimer)--;
        return TRUE;
    }
    return FALSE;
}

static void StopFanfare(int fadeFrames) {
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_ME), fadeFrames);
    GF_Snd_LoadState(Sound_GetSavedHeapLevel(6));
}

BOOL IsFanfarePlaying(void) {
    GF_SdatGetAttrPtr(SOUND_ATTR_AFTER_FANFARE_WAIT_TIMER);
    if (IsFanfarePlayingOrWaiting() == 1) {
        return TRUE;
    }
    StopFanfare(0);
    u8 playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != SOUND_PLAYER_NONE) {
        Sound_SetPlayerPause(playerNo, FALSE);
    }
    SndRadio_PausePlayer(FALSE);
    return FALSE;
}

static void StartFanfareWaitTimer(u16 unused) {
    u16 *waitTimer = GF_SdatGetAttrPtr(SOUND_ATTR_AFTER_FANFARE_WAIT_TIMER);
    *waitTimer = 15;
}

static BOOL Sound_StartSeq(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds) {
    u16 playingSeqNo = seqNo;
    if (useGBSounds == 1 && SoundSys_GetGBSoundsState() == 1) {
        u16 gbSeqNo = GBSounds_GetGBSeqNoByDSSeqNo(seqNo);
        if (seqNo != gbSeqNo) {
            playingSeqNo = gbSeqNo;
            bankNo = 701;
            Sound_SetPlayingGBSeqNo(gbSeqNo);
            int seqPlayerNo = GF_GetPlayerNoBySeq(gbSeqNo);
            if (playerNo != -1) {
                seqPlayerNo = (u8)playerNo;
            }
            if (seqPlayerNo == PLAYER_BGM) {
                GF_Snd_LoadSeqEx(gbSeqNo, 1);
            }
        }
    }
    BOOL success = NNS_SndArcPlayerStartSeqEx(GF_GetSoundHandle(handleNo), playerNo, bankNo, playerPrio, playingSeqNo);
    GBSounds_SetAllocatableChannels();
    return success;
}
