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
void sub_02005464(u16 seqNo, enum SoundHandleNo handleNo);
void sub_020059E0(u16 seqNo);
BOOL sub_02005D10(u16 seqNo);
void sub_02005DA0(u16 seqNo, enum SoundHandleNo handleNo);
BOOL sub_02005DC4(u16 seqNo, int playerNo, enum SoundHandleNo handleNo);
BOOL sub_02005DF4(u16 seqNo, int playerNo, enum SoundHandleNo handleNo);
BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

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
