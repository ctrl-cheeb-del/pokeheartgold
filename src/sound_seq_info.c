#include "sound.h"
#include "sound_02004A44.h"

void sub_02005448(int seqNo);
void sub_02005464(int seqNo, enum SoundHandleNo handleNo);
BOOL sub_020378CC(void);
u8 GF_GetPlayerNoBySeq(u16 seqNo);
int GF_NNS_SndPlayerGetSeqNo(NNSSndHandle *handle);
int NNS_SndPlayerGetSeqNo(NNSSndHandle *handle);
struct NNSSndArcBankInfo;
const struct NNSSndArcBankInfo *NNS_SndArcGetBankInfo(int bankNo);
const struct NNSSndArcBankInfo *GF_GetBankInfoBySeqNo(int seqNo);
int GF_GetBankBySeqNo(int seqNo);

void sub_02005448(int seqNo) {
    sub_02005464(seqNo, GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq((u16)seqNo)));
}
void sub_02005464(int seqNo, enum SoundHandleNo handleNo) {
    const NNSSndSeqParam *param = NNS_SndArcGetSeqParam(seqNo);
    int volume;
    if (handleNo == SND_HANDLE_PV || handleNo == SND_HANDLE_CHORUS) {
        volume = 127;
    } else {
        if (param == NULL) {
            return;
        }
        volume = param->volume;
    }
    if (sub_020378CC() == 1) {
        GF_SndHandleSetInitialVolume(handleNo, volume / 5);
    }
}
u16 GF_GetVolumeBySeqNo(int seqNo) {
    const NNSSndSeqParam *param = NNS_SndArcGetSeqParam(seqNo);
    if (param == NULL) {
        return 0;
    }
    return param->volume;
}
void GF_SetVolumeBySeqNo(u16 seqNo, u16 volume) {
    GF_SndHandleSetInitialVolume(GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo)), volume);
}
u32 GF_SndPlayerCountPlayingSeqByPlayerNo(u32 playerNo) {
    GF_ASSERT((s32)playerNo >= 0);
    return NNS_SndPlayerCountPlayingSeqByPlayerNo(playerNo);
}
u8 GF_GetPlayerNoBySeq(u16 seqNo) {
    const NNSSndSeqParam *param;
    if (seqNo == 0) {
        return 255;
    }
    param = NNS_SndArcGetSeqParam(seqNo);
    if (param == NULL) {
        return 255;
    }
    return param->playerNo;
}
int GF_NNS_SndPlayerGetSeqNo(NNSSndHandle *handle) {
    return NNS_SndPlayerGetSeqNo(handle);
}
const struct NNSSndArcBankInfo *GF_GetBankInfoBySeqNo(int seqNo) {
    return NNS_SndArcGetBankInfo(GF_GetBankBySeqNo(seqNo));
}
int GF_GetBankBySeqNo(int seqNo) {
    const NNSSndSeqParam *param = NNS_SndArcGetSeqParam(seqNo);
    if (param == NULL) {
        return 0;
    }
    return param->bankNo;
}
BOOL sub_02005518(void) {
    return GF_SndWorkMicCounterFull();
}
