#include "sound.h"
#include "sound_02004A44.h"

BOOL GF_NowStartMusicId(u16 seqNo, u16 fadeOutFrames, int delay, u8 reload, int unused);
BOOL sub_02005A10(int scene, u16 seqNo, u16 fadeOutFrames, int delay, u8 reload, int unused);
BOOL GF_FadeStartMusicId(u16 seqNo, u16 fadeOutFrames, int delay, int fadeInFrames, u8 reload, int unused);
BOOL sub_02005A74(int scene, u16 seqNo, u16 fadeOutFrames, int delay, int fadeInFrames, u8 reload, int unused);
void sub_02005AB0(int scene, u16 seqNo, u16 fadeOutFrames, int delay, u8 reload, int unused);
struct NNSSndArcBankInfo;
const struct NNSSndArcBankInfo *GF_GetBankInfoBySeqNo(int seqNo);
void sub_020059A0(u32 frames);
void sub_020059E0(u16 state);
void GF_SndSetAllocatableChannelForBGMPlayer(u32 channels);
void NNS_SndPlayerSetAllocatableChannel(int playerNo, u32 channels);
void sub_02005AF8(int mode);
void sub_02005910(int frames);
BOOL sub_020058F4(void);
void sub_02005B20(void);
int GF_NNS_SndPlayerGetSeqNo(NNSSndHandle *handle);
void sub_02005FD8(void);
void Sound_Stop(void);

BOOL GF_NowStartMusicId(u16 seqNo, u16 fadeOutFrames, int delay, u8 reload, int unused) {
    return sub_02005A10(4, seqNo, fadeOutFrames, delay, reload, unused);
}
BOOL sub_02005A10(int scene, u16 seqNo, u16 fadeOutFrames, int delay, u8 reload, int unused) {
    u8 *secondary = GF_SdatGetAttrPtr(22);
    sub_02005AB0(scene, seqNo, fadeOutFrames, delay, reload, unused);
    *secondary = 0;
    GF_SndSetState(5);
    return TRUE;
}
BOOL GF_FadeStartMusicId(u16 seqNo, u16 fadeOutFrames, int delay, int fadeInFrames, u8 reload, int unused) {
    return sub_02005A74(4, seqNo, fadeOutFrames, delay, fadeInFrames, reload, unused);
}
BOOL sub_02005A74(int scene, u16 seqNo, u16 fadeOutFrames, int delay, int fadeInFrames, u8 reload, int unused) {
    int *fadeIn = GF_SdatGetAttrPtr(9);
    sub_02005AB0(scene, seqNo, fadeOutFrames, delay, reload, unused);
    *fadeIn = fadeInFrames;
    GF_SndSetState(6);
    return TRUE;
}
void sub_02005AB0(int scene, u16 seqNo, u16 fadeOutFrames, int delay, u8 reload, int unused) {
    const struct NNSSndArcBankInfo **bank = GF_SdatGetAttrPtr(2);
    GF_SndStartFadeOutBGM(0, fadeOutFrames);
    sub_02004A60(0);
    GF_SetCurrentPlayingBGM(seqNo);
    sub_020059A0(delay);
    *bank = GF_GetBankInfoBySeqNo(seqNo);
    sub_020059E0(reload);
}
void GF_SndSetAllocatableChannelForBGMPlayer(u32 channels) {
    NNS_SndPlayerSetAllocatableChannel(7, channels);
}
void sub_02005AF8(int mode) {
    if (mode == 0) {
        GF_SndSetAllocatableChannelForBGMPlayer(0xA7FE);
        sub_02005910(0);
    } else {
        GF_SndSetAllocatableChannelForBGMPlayer(0x3FFF);
    }
    sub_020058F4();
}
void sub_02005B20(void) {
    if (GF_SndGetFadeTimer() == 0 && GF_NNS_SndPlayerGetSeqNo(GF_GetSoundHandle(0)) != -1) {
        sub_02005FD8();
        sub_020053A8(1, 1);
    } else {
        Sound_Stop();
    }
}
