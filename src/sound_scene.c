#include "sound.h"
#include "sound_02004A44.h"

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
