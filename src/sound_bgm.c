#include "sound.h"
#include "sound_02004A44.h"
#include "sound_radio.h"

int GF_NNS_SndPlayerGetSeqNo(NNSSndHandle *handle);
int GF_GetBankBySeqNo(int seqNo);
u16 GBSounds_GetGBSeqNoByDSSeqNo(u16 seqNo);
void sub_020051A4(u16 seqNo, int bankNo);
BOOL sub_02005E44(u16 seqNo);
void StopBGM(u16 seqNo, int fadeFrames);
void sub_02005EEC(void);
void NNS_SndPlayerStopSeqBySeqNo(int seqNo, int fadeFrames);
int GF_GetPlayerNoBySeq(u16 seqNo);
int sub_02005328(int state);
void sub_02005464(int seqNo, enum SoundHandleNo handleNo);
void sub_020059E0(u16 seqNo);
BOOL sub_02005D10(u16 seqNo);
void sub_02005DA0(u16 seqNo, enum SoundHandleNo handleNo);
BOOL sub_02005DC4(u16 seqNo, int playerNo, enum SoundHandleNo handleNo);
BOOL sub_02005DF4(u16 seqNo, int playerNo, enum SoundHandleNo handleNo);
BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

void sub_02005990(u32 frames);
u32 sub_02005F94(u16 seqNo);
void NNS_SndPlayerStopSeqAll(int fadeFrames);
void NNS_SndPlayerStopSeq(NNSSndHandle *handle, int fadeFrames);
void sub_02005728(int handleNo);
void Sound_Stop(void);
void sub_02005FD8(void);
void sub_0200615C(int handleNo, int fadeFrames);
void sub_02006300(int fadeFrames);

BOOL sub_02005D10(u16 seqNo) {
    BOOL success;
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
    success = sub_02006C14(handleNo, -1, -1, -1, seqNo, 1);
    if (!success) {
        sub_02004920(seqNo);
    }
    sub_02005DA0(seqNo, handleNo);
    return success;
}

BOOL PlayBGM(u16 seqNo) {
    int playerNo = GF_GetPlayerNoBySeq(seqNo);
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(playerNo);
    BOOL success;
    if (playerNo == 7) {
        success = sub_02005DC4(seqNo, playerNo, handleNo);
    } else if (playerNo == 1) {
        success = sub_02005DF4(seqNo, playerNo, handleNo);
    } else {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    sub_020059E0(0);
    if (!success) {
        sub_02004920(seqNo);
    }
    sub_02005DA0(seqNo, handleNo);
    return success;
}

void sub_02005DA0(u16 seqNo, enum SoundHandleNo handleNo) {
    sub_02004A60(seqNo);
    sub_02005464(seqNo, handleNo);
    GF_SndSetState(1);
    if (handleNo == SND_HANDLE_FIELD) {
        GF_SndWorkSetGbSoundsVolume(128);
    }
}

BOOL sub_02005DC4(u16 seqNo, int playerNo, enum SoundHandleNo handleNo) {
    GF_Snd_LoadState(sub_02005328(3));
    GF_Snd_LoadSeq(seqNo);
    return sub_02006C14(handleNo, -1, -1, -1, seqNo, 1);
}

BOOL sub_02005DF4(u16 seqNo, int playerNo, enum SoundHandleNo handleNo) {
    GF_SdatGetAttrPtr(19);
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(32);
    sub_020051A4(seqNo, GF_GetBankBySeqNo(GF_NNS_SndPlayerGetSeqNo(GF_GetSoundHandle(SND_HANDLE_FIELD))));
    SndRadio_StopSeq(0);
    return sub_02006C14(handleNo, -1, GF_GetBankBySeqNo(*fieldSeqNo), -1, seqNo, 1);
}

BOOL sub_02005E44(u16 seqNo) {
    BOOL success;
    u8 *scene = GF_SdatGetAttrPtr(21);
    if (*scene != 4) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    if (GF_GetPlayerNoBySeq(seqNo) != 7) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    GF_Snd_LoadSeqEx(seqNo, 1);
    success = sub_02006C14(SND_HANDLE_BGM, -1, -1, -1, seqNo, 1);
    if (!success) {
        sub_02004920(seqNo);
    }
    SndRadio_StopSeq(0);
    sub_02004A60(seqNo);
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
    if (playerNo != 255) {
        NNS_SndHandleReleaseSeq(GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(playerNo)));
    }
    sub_02005EEC();
}

void sub_02005EEC(void) {
    SndRadio_StopSeq(0);
    sub_02004A60(0);
    GF_SetCurrentPlayingBGM(0);
    sub_02004AB8(0);
    GF_SndSetState(0);
}

void GF_SndStartFadeInBGM(u32 volume, u32 frames, u32 keepVolume) {
    int playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != 255) {
        enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(playerNo);
        if (keepVolume == 0) {
            GF_SndHandleMoveVolume(handleNo, 0, 0);
        }
        GF_SndHandleMoveVolume(handleNo, volume, frames);
        sub_02005990(frames);
        GF_SndSetState(3);
    }
}

void GF_SndStartFadeOutBGM(u16 volume, u16 frames) {
    int playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != 255) {
        if (GF_SndGetFadeTimer() == 0) {
            GF_SndHandleMoveVolume(GF_GetSndHandleByPlayerNo(playerNo), volume, frames);
            sub_02005990(frames);
        }
        GF_SndSetState(4);
    }
}

u32 GF_SndGetFadeTimer(void) {
    u16 *timer = GF_SdatGetAttrPtr(7);
    return *timer;
}

u32 sub_02005F94(u16 seqNo) {
    return GF_SndPlayerCountPlayingSeqByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
}

void Sound_Stop(void) {
    u8 *firstActive = GF_SdatGetAttrPtr(16);
    u8 *secondActive = GF_SdatGetAttrPtr(17);
    NNS_SndPlayerStopSeqAll(0);
    if (*firstActive == 1) {
        sub_02005728(14);
    }
    if (*secondActive == 1) {
        sub_02005728(15);
    }
    GF_SndSetState(0);
}

void sub_02005FD8(void) {
    u8 *firstActive = GF_SdatGetAttrPtr(16);
    u8 *secondActive = GF_SdatGetAttrPtr(17);
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_BGM), 0);
    sub_02005EEC();
    for (int i = 0; i < 4; i++) {
        sub_0200615C(i + SND_HANDLE_SE_1, 0);
    }
    sub_02006300(0);
    if (*firstActive == 1) {
        sub_02005728(14);
    }
    if (*secondActive == 1) {
        sub_02005728(15);
    }
}
