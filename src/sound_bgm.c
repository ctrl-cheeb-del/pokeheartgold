#include "sound.h"
#include "sound_02004A44.h"

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
