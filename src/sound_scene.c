#include "sound.h"
#include "sound_02004A44.h"

void sub_02005B20(void);
void Sound_ClearBGMPauseFlags(void);
void sub_02005318(void);

extern int _021D05E8[4];
int GF_NNS_SndPlayerGetSeqNo(NNSSndHandle *handle);
u16 GBSounds_GetDSSeqNoByGBSeqNo(u16 seqNo);
int GF_GetBankBySeqNo(int seqNo);
void sub_020059E0(u16 seqNo);
void sub_02005FD8(void);
void Sound_Stop(void);
int sub_02005328(int state);
void sub_02005150(u16 seqNo, u16 previousSeqNo);
void sub_020051A4(u16 seqNo, int bankNo);

BOOL sub_02004EB4(u16 seqNo);
void sub_02005060(int scene);
void sub_02005AF8(int mode);
void sub_0200508C(u16 seqNo, int mode);
void sub_02005228(u16 seqNo, int mode);
void sub_02005260(u16 seqNo, int mode);
void sub_02005280(u16 seqNo, int mode);
void sub_020052A4(u16 seqNo, int mode);
void sub_020052C8(int scene);
void sub_020052E4(int scene, u16 seqNo, int mode);

BOOL sub_02004B24(int scene) {
    BOOL success;
    switch (scene) {
    case 1:
    case 9:
    case 10:
    case 17:
    case 20:
    case 23:
        success = GF_Snd_LoadGroup(GROUP_SE_FIELD);
        break;
    case 19:
        success = GF_Snd_LoadGroup(GROUP_SE_FIELD);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_BALLOON02, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_BALLOON03_2, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_BALLOON05, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_BALLOON01, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_BALLOON07, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_ALERT4, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_DP_FW104, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_NOMI02, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_DP_023, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_POINT1, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_POINT2, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_POINT3, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_BALLOON05_2, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_DP_HAMARU, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_DP_CON_016, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_KIRAKIRA, 1);
        GF_Snd_LoadSeqEx(SEQ_SE_PL_FCALL, 1);
        break;
    case 14:
        success = GF_Snd_LoadGroup(GROUP_SE_NUTMIXER);
        break;
    case 2:
    case 13:
        success = GF_Snd_LoadGroup(GROUP_SE_BATTLE);
        break;
    case 21:
        GF_Snd_LoadBank(BANK_SE_HIROBA);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_HIROBA);
        break;
    case 3:
        success = GF_Snd_LoadGroup(GROUP_SE_TRADE);
        break;
    case 4:
    case 22:
        success = GF_Snd_LoadGroup(GROUP_SE_FIELD);
        break;
    case 5:
        success = GF_Snd_LoadGroup(GROUP_SE_BATTLE);
        break;
    case 11:
        success = GF_Snd_LoadGroup(GROUP_SE_FIELD);
        break;
    case 6:
        success = GF_Snd_LoadGroup(GROUP_SE_CONTEST);
        break;
    case 8:
        success = GF_Snd_LoadGroup(GROUP_SE_FIELD);
        break;
    case 12:
        success = GF_Snd_LoadGroup(GROUP_SE_NUTMIXER);
        break;
    case 16:
        GF_Snd_LoadGroup(GROUP_SE_FIELD);
        success = GF_Snd_LoadGroup(GROUP_SE_DIG);
        break;
    case 15:
        success = GF_Snd_LoadGroup(GROUP_SE_FIELD);
        break;
    case 24:
        GF_Snd_LoadBank(BANK_SE_THLON);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_THLON);
        break;
    case 25:
        GF_Snd_LoadBank(BANK_SE_THLON_OPED);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_THLON_OPED);
        break;
    case 51:
        success = GF_Snd_LoadGroup(GROUP_SE_BAG);
        break;
    case 64:
        success = GF_Snd_LoadGroup(GROUP_SE_SLOT);
        break;
    case 52:
    case 67:
        success = GF_Snd_LoadGroup(GROUP_SE_NAMEIN);
        break;
    case 7:
    case 53:
        success = GF_Snd_LoadGroup(GROUP_SE_IMAGE);
        break;
    case 54:
        success = GF_Snd_LoadGroup(GROUP_SE_ZUKAN);
        break;
    case 55:
    case 65:
        GF_Snd_LoadBank(BANK_SE_TOWNMAP);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_TOWNMAP);
        break;
    case 56:
        success = GF_Snd_LoadGroup(GROUP_SE_TRCARD);
        break;
    case 57:
        success = GF_Snd_LoadGroup(GROUP_SE_POKELIST);
        break;
    case 58:
        success = GF_Snd_LoadGroup(GROUP_SE_DIG);
        break;
    case 59:
        success = GF_Snd_LoadGroup(GROUP_SE_CUSTOM);
        break;
    case 60:
        success = GF_Snd_LoadGroup(GROUP_SE_BAG);
        break;
    case 61:
        success = GF_Snd_LoadGroup(GROUP_SE_NAMEIN);
        break;
    case 62:
        success = GF_Snd_LoadGroup(GROUP_SE_CUSTOM);
        break;
    case 63:
        success = GF_Snd_LoadGroup(GROUP_SE_CLIMAX);
        break;
    case 66:
        GF_Snd_LoadBank(BANK_SE_SCRATCH);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_SCRATCH);
        break;
    case 69:
        GF_Snd_LoadBank(BANK_SE_PLANTER);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_PLANTER);
        break;
    case 68:
        GF_Snd_LoadBank(BANK_SE_LINEAR);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_LINEAR);
        break;
    case 70:
        GF_Snd_LoadBank(BANK_SE_COIN);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_COIN);
        break;
    case 71:
        GF_Snd_LoadBank(BANK_SE_DENDO);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_DENDO);
        break;
    case 72:
        GF_Snd_LoadBank(BANK_SE_JUICE);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_JUICE);
        break;
    case 73:
        GF_Snd_LoadBank(BANK_SE_PHC);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_PHC);
        break;
    case 74:
        GF_Snd_LoadBank(BANK_SE_SEKIBAN);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_SEKIBAN);
        break;
    case 75:
        GF_Snd_LoadBank(BANK_SE_EVENT);
        success = GF_Snd_LoadWaveArc(WAVE_ARC_SE_EVENT);
        break;
    default:
        GF_ASSERT(FALSE);
        success = FALSE;
        break;
    }
    return success;
}

BOOL sub_02004EB4(u16 seqNo) {
    return Sound_SetSceneAndPlayBGM(4, seqNo, 1);
}

BOOL Sound_SetSceneAndPlayBGM(u8 scene, u16 seqNo, int mode) {
    u8 *primary = GF_SdatGetAttrPtr(21);
    u8 *secondary = GF_SdatGetAttrPtr(22);
    u16 *fanfareWait = GF_SdatGetAttrPtr(14);
    if (scene < 51) {
        if (*primary == scene) {
            return FALSE;
        }
    } else {
        if (*secondary == scene) {
            return FALSE;
        }
    }
    Sound_SetScene(scene);
    switch (scene) {
    case 4:
        sub_02005AF8(0);
        sub_0200508C(seqNo, mode);
        *fanfareWait = 0;
        break;
    case 5:
        sub_02005228(seqNo, mode);
        break;
    case 11:
        sub_02005260(seqNo, mode);
        break;
    case 6:
        sub_02005280(seqNo, mode);
        break;
    case 7:
        sub_020052A4(seqNo, mode);
        break;
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 69:
    case 70:
    case 71:
    case 72:
    case 74:
        sub_020052C8(scene);
        break;
    case 68:
        sub_020052C8(scene);
        PlayBGM(seqNo);
        break;
    case 1:
        sub_02005AF8(1);
        sub_020052E4(scene, seqNo, mode);
        break;
    case 14:
        sub_02005AF8(2);
        sub_020052E4(scene, seqNo, mode);
        break;
    case 2:
        sub_02005AF8(0);
        sub_020052E4(scene, seqNo, mode);
        break;
    case 3:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 25:
    case 73:
        sub_020052E4(scene, seqNo, mode);
        break;
    case 22:
        sub_020052E4(scene, seqNo, mode);
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

void sub_02005060(int scene) {
    GF_Snd_LoadState(*(int *)GF_SdatGetAttrPtr(24));
    GF_Snd_SaveState(GF_SdatGetAttrPtr(25));
    sub_02004B24(scene);
    GF_Snd_SaveState(GF_SdatGetAttrPtr(26));
}

void sub_0200508C(u16 seqNo, int mode) {
    int playingSeqNo;
    u8 *reload = GF_SdatGetAttrPtr(12);
    GF_SdatGetAttrPtr(24);
    GF_SdatGetAttrPtr(32);
    playingSeqNo = GF_NNS_SndPlayerGetSeqNo(GF_GetSoundHandle(0));
    u16 currentSeqNo = playingSeqNo;
    if (playingSeqNo > SEQ_GS_P_START) {
        currentSeqNo = GBSounds_GetDSSeqNoByGBSeqNo(currentSeqNo);
    }
    if (*reload != 0 || currentSeqNo != seqNo || sub_02004AAC() == SEQ_GS_BICYCLE) {
        sub_020059E0(1);
        if (_021D05E8[3] == 0 || _021D05E8[1] == 0) {
            sub_02005FD8();
            _021D05E8[1] = 1;
        }
        if (currentSeqNo != seqNo) {
            sub_020053A8(1, 0);
            Sound_Stop();
        }
        if (*reload == 1) {
            GF_Snd_LoadState(sub_02005328(2));
            sub_02004B24(4);
            GF_Snd_SaveState(GF_SdatGetAttrPtr(26));
            if (currentSeqNo != seqNo) {
                sub_020053A8(1, 0);
            }
            sub_02005150(seqNo, (u16)playingSeqNo);
        } else {
            PlayBGM(seqNo);
        }
    }
}

void sub_02005150(u16 seqNo, u16 previousSeqNo) {
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(32);
    if (GF_GetBankBySeqNo(*fieldSeqNo) == BANK_BASIC) {
        GF_Snd_LoadSeqEx(seqNo, 4);
        GF_ASSERT(FALSE);
    } else {
        GF_Snd_LoadSeqEx(*fieldSeqNo, 6);
    }
    GF_Snd_SaveState(GF_SdatGetAttrPtr(27));
    sub_020053A8(1, 0);
    GF_SndStartFadeInBGM(127, 40, 0);
    sub_020059E0(0);
}

void sub_020051A4(u16 seqNo, int bankNo) {
    u8 *reload = GF_SdatGetAttrPtr(19);
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(32);
    if (*reload == 1 || bankNo == 0) {
        GF_Snd_LoadState(sub_02005328(1));
        sub_02004AFC(0);
        GF_Snd_LoadSeqEx(*fieldSeqNo, 2);
        GF_Snd_SaveState(GF_SdatGetAttrPtr(25));
        sub_02004B24(4);
        GF_Snd_SaveState(GF_SdatGetAttrPtr(26));
        if (GF_GetBankBySeqNo(*fieldSeqNo) == BANK_BASIC) {
            GF_Snd_LoadSeqEx(seqNo, 4);
            GF_ASSERT(FALSE);
        } else {
            GF_Snd_LoadSeqEx(*fieldSeqNo, 4);
        }
        GF_Snd_SaveState(GF_SdatGetAttrPtr(27));
    }
}

void sub_02005228(u16 seqNo, int mode) {
    GF_SdatGetAttrPtr(24);
    sub_02005B20();
    GF_Snd_LoadState(sub_02005328(2));
    sub_02004B24(5);
    GF_Snd_SaveState(GF_SdatGetAttrPtr(26));
    sub_020059E0(1);
    PlayBGM(seqNo);
}
void sub_02005260(u16 seqNo, int mode) {
    GF_SdatGetAttrPtr(24);
    Sound_Stop();
    Sound_ClearBGMPauseFlags();
    sub_02005060(4);
    PlayBGM(seqNo);
}
void sub_02005280(u16 seqNo, int mode) {
    GF_SdatGetAttrPtr(24);
    Sound_Stop();
    sub_02005060(6);
    sub_020059E0(1);
    PlayBGM(seqNo);
}
void sub_020052A4(u16 seqNo, int mode) {
    GF_SdatGetAttrPtr(24);
    Sound_Stop();
    sub_02005060(7);
    sub_020059E0(1);
    PlayBGM(seqNo);
}
void sub_020052C8(int scene) {
    sub_02005318();
    sub_02004B24(scene);
    GF_Snd_SaveState(GF_SdatGetAttrPtr(28));
}
void sub_020052E4(int scene, u16 seqNo, int mode) {
    GF_SdatGetAttrPtr(24);
    Sound_Stop();
    sub_02005060(scene);
    PlayBGM(seqNo);
}
void BGM_SaveStateAndPlayNew(u16 seqNo) {
    GetSoundDataPointer();
    sub_02005B20();
    PlayBGM(seqNo);
}
void sub_02005318(void) {
    GF_Snd_LoadState(sub_02005328(4));
}
