#include "sound.h"
#include "sound_02004A44.h"
#include "sound_radio.h"

BOOL PlayFanfare(u16 seqNo);
BOOL sub_02006B84(void);
void sub_02006BB0(int fadeFrames);
BOOL IsFanfarePlaying(void);
void sub_02006C04(u16 unused);
void GF_GetBankInfoBySeqNo(u16 seqNo);
u8 GF_GetPlayerNoBySeq(u16 seqNo);
void sub_02005464(int seqNo, enum SoundHandleNo handleNo);
void NNS_SndPlayerStopSeq(NNSSndHandle *handle, int fadeFrames);
int sub_02005328(int state);
BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

BOOL PlayFanfare(u16 seqNo) {
    GF_GetBankInfoBySeqNo(seqNo);
    sub_02006C04(seqNo);
    u8 playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != 255) {
        sub_020053A8(playerNo, TRUE);
    } else {
        SndRadio_PausePlayer(TRUE);
    }
    GF_Snd_SaveState(GF_SdatGetAttrPtr(29));
    GF_Snd_LoadSeqEx(seqNo, 3);
    BOOL success = sub_02006C14(SND_HANDLE_ME, -1, -1, -1, seqNo, 0);
    sub_02005464(seqNo, SND_HANDLE_ME);
    return success;
}

BOOL sub_02006B84(void) {
    u16 *waitTimer = GF_SdatGetAttrPtr(14);
    if (GF_SndPlayerCountPlayingSeqByPlayerNo(2) != 0) {
        return TRUE;
    }
    if (*waitTimer != 0) {
        (*waitTimer)--;
        return TRUE;
    }
    return FALSE;
}

void sub_02006BB0(int fadeFrames) {
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_ME), fadeFrames);
    GF_Snd_LoadState(sub_02005328(6));
}

BOOL IsFanfarePlaying(void) {
    GF_SdatGetAttrPtr(14);
    if (sub_02006B84() == 1) {
        return TRUE;
    }
    sub_02006BB0(0);
    u8 playerNo = GF_GetPlayerNoBySeq(GF_GetCurrentPlayingBGM());
    if (playerNo != 255) {
        sub_020053A8(playerNo, FALSE);
    }
    SndRadio_PausePlayer(FALSE);
    return FALSE;
}

void sub_02006C04(u16 unused) {
    u16 *waitTimer = GF_SdatGetAttrPtr(14);
    *waitTimer = 15;
}
