#include "sound.h"
#include "sound_02004A44.h"

BOOL PlaySE(u16 seqNo);
BOOL sub_0200602C(u16 seqNo, int pan);
BOOL sub_0200606C(u16 seqNo, int playerNo);
BOOL sub_02006088(u16 seqNo);
BOOL sub_020060BC(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, int seqNo);
BOOL sub_02006118(u16 seqNo, u16 volume);
BOOL PlaySE_SetPitch(u16 seqNo, int pitch);
u8 GF_GetPlayerNoBySeq(u16 seqNo);
int GF_GetBankBySeqNo(int seqNo);
int sub_02005BFC(void);
void sub_02005464(int seqNo, enum SoundHandleNo handleNo);
void sub_020061B4(u16 seqNo, u32 trackMask, int pan);
void sub_0200592C(u16 seqNo, u32 trackMask, int pitch);
BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

void StopSE(u16 seqNo, int fadeFrames);
void sub_0200615C(int handleNo, int fadeFrames);
void sub_0200616C(int unused);
BOOL IsSEPlaying(u16 seqNo);
u32 sub_02006190(u32 playerNo);
BOOL GF_IsAnySEPlaying(void);
void NNS_SndPlayerStopSeqBySeqNo(int seqNo, int fadeFrames);
void NNS_SndPlayerStopSeq(NNSSndHandle *handle, int fadeFrames);

void sub_020061D0(int playerNo, int pan);
void sub_020061EC(int pan);
void NNS_SndPlayerSetTrackPan(NNSSndHandle *handle, u32 trackMask, int pan);

BOOL sub_0200602C(u16 seqNo, int pan) {
    BOOL success = PlaySE(seqNo);
    sub_020061B4(seqNo, 0xFFFF, pan);
    return success;
}

BOOL PlaySE(u16 seqNo) {
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
    return sub_020060BC(handleNo, -1, -1, -1, seqNo);
}

BOOL sub_0200606C(u16 seqNo, int playerNo) {
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(playerNo);
    return sub_020060BC(handleNo, playerNo, -1, -1, seqNo);
}

BOOL sub_02006088(u16 seqNo) {
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(32);
    enum SoundHandleNo handleNo = GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
    return sub_020060BC(handleNo, -1, GF_GetBankBySeqNo(*fieldSeqNo), -1, seqNo);
}

BOOL sub_020060BC(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, int seqNo) {
    if (sub_02005BFC() == 1 && (u32)seqNo - SEQ_SE_DP_SELECT <= 1) {
        return FALSE;
    }
    BOOL success = sub_02006C14(handleNo, playerNo, bankNo, playerPrio, seqNo, 0);
    sub_02005464(seqNo, handleNo);
    if (!success) {
        sub_02004920(seqNo);
    }
    return success;
}

BOOL sub_02006118(u16 seqNo, u16 volume) {
    BOOL success = PlaySE(seqNo);
    if (success) {
        GF_SetVolumeBySeqNo(seqNo, volume);
    }
    return success;
}

BOOL PlaySE_SetPitch(u16 seqNo, int pitch) {
    BOOL success = PlaySE(seqNo);
    if (success) {
        sub_0200592C(seqNo, 0xFFFF, pitch);
    }
    return success;
}

void StopSE(u16 seqNo, int fadeFrames) {
    NNS_SndPlayerStopSeqBySeqNo(seqNo, fadeFrames);
}

void sub_0200615C(int handleNo, int fadeFrames) {
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(handleNo), fadeFrames);
}

void sub_0200616C(int unused) {
    for (int i = 0; i < 4; i++) {
        sub_0200615C(i + SND_HANDLE_SE_1, 0);
    }
}

BOOL IsSEPlaying(u16 seqNo) {
    return GF_SndPlayerCountPlayingSeqByPlayerNo(GF_GetPlayerNoBySeq(seqNo));
}

u32 sub_02006190(u32 playerNo) {
    return GF_SndPlayerCountPlayingSeqByPlayerNo(playerNo);
}

BOOL GF_IsAnySEPlaying(void) {
    for (int i = 0; i < 4; i++) {
        if (GF_SndPlayerCountPlayingSeqByPlayerNo(i + 3) == 1) {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_020061B4(u16 seqNo, u32 trackMask, int pan) {
    NNSSndHandle *handle = GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo)));
    NNS_SndPlayerSetTrackPan(handle, trackMask, pan);
}

void sub_020061D0(int playerNo, int pan) {
    NNS_SndPlayerSetTrackPan(GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(playerNo)), 0xFFFF, pan);
}

void sub_020061EC(int pan) {
    enum SoundHandleNo firstHandle = GF_GetSndHandleByPlayerNo(3);
    for (int i = 0; i < 4; i++) {
        NNS_SndPlayerSetTrackPan(GF_GetSoundHandle(firstHandle + i), 0xFFFF, pan);
    }
}
